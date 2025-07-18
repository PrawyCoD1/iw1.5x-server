/*
Linux inline asm notes

- __attribute__ ((naked)):  no prologue/epilogue
- extern "C":               no name mangling
- asm volatile:             no optimizaion/reordering

- pushal:   save general-purpose registers
- popal:    restore general-purpose registers

Can add a suffix to an instruction to indicate the size/type of the operand:
- b: byte
- w: word
- l: long

asm volatile (
    // Instructions
    : // Output operands
    : // Input operands (m = memory, r = register)
    : // Clobber list
);
*/

#include "shared.h"

// Cvars
extern cvar_t *jump_slowdownEnable;
extern cvar_t *jump_height;
// Resume addresses
extern uintptr_t resume_addr_PM_WalkMove;
extern uintptr_t resume_addr_PM_SlideMove;

// Game lib objects
extern pmove_t **pm;

#define JUMP_LAND_SLOWDOWN_TIME 1800

////


void hook_Jump_Check()
{
    float height = jump_height->value;
    Jump_Set(height);
}

__attribute__ ((naked)) void hook_PM_WalkMove_Naked()
{
    asm volatile (
        "pushal\n"
        "call Jump_ApplySlowdown\n"
        "popal\n"
        "jmp *%0\n"
        :
        : "r"(resume_addr_PM_WalkMove)
        : "memory"
    );
}

extern "C" void Jump_ApplySlowdown()
{
    playerState_t *ps = ((pmove_t*)*((int*)pm))->ps;

    if(ps->pm_flags & PMF_JUMPING)
    {
        float scale = 1.0;


        if(ps->pm_time <= JUMP_LAND_SLOWDOWN_TIME)
        {
            if(!ps->pm_time)
            {
                if ((float)(ps->fJumpOriginZ + 18.0) <= ps->origin[2])
                {
                    ps->pm_time = 1200;
                    scale = 0.5;
                }
                else
                {
                    ps->pm_time = JUMP_LAND_SLOWDOWN_TIME;
                    scale = 0.64999998;
                }
            }
        }
        else
        {
            // Clear jump state
            ps->pm_flags &= ~PMF_JUMPING;
            ps->fJumpOriginZ = 0.0;
            scale = 0.64999998;
        }

        if(jump_slowdownEnable->integer)
            VectorScale(ps->velocity, scale, ps->velocity);
    }
}

__attribute__ ((naked)) void hook_PM_SlideMove_Naked()
{
    asm volatile (
        "pushal\n"

        "movl -0xA0(%%ebp), %%eax\n"
        "pushl %%eax\n"

        "movl -0xA4(%%ebp), %%eax\n"
        "pushl %%eax\n"

        "movl -0xA8(%%ebp), %%eax\n"
        "pushl %%eax\n"

        "call hook_PM_SlideMove\n"
        "addl $12, %%esp\n"

        "popal\n"
        "jmp *%0\n"
        :
        : "r"(resume_addr_PM_SlideMove)
        : "%eax", "memory"
    );
}

extern "C" void hook_PM_SlideMove(float primal_velocity_0, float primal_velocity_1, float primal_velocity_2)
{
    if(jump_slowdownEnable->integer) // Not to disable wallrun after jump
    {
        playerState_t *ps = ((pmove_t*)*((int*)pm))->ps;
        if (ps->pm_time)
        {
            ps->velocity[0] = primal_velocity_0;
            ps->velocity[1] = primal_velocity_1;
            ps->velocity[2] = primal_velocity_2;
        }
    }
}

double custom_Jump_GetLandFactor()
{
    if(!jump_slowdownEnable->integer)
        return 1.0;

    playerState_t *ps = ((pmove_t*)*((int*)pm))->ps;
    if (ps->pm_time < 1700)
        return (double)ps->pm_time * 1.5 * 0.00058823527 + 1.0;
    return 2.5;
}

double custom_PM_GetReducedFriction()
{
    if(!jump_slowdownEnable->integer)
        return 1.0;

    playerState_t *ps = ((pmove_t*)*((int*)pm))->ps;
    if (ps->pm_time < 1700)
        return (double)ps->pm_time * 1.5 * 0.00058823527 + 1.0;
    return 2.5;
}