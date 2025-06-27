typedef int (*VM_Call_t)(vm_t *vm, int callnum, ...);
static const VM_Call_t VM_Call = (VM_Call_t)0x809AFBC;

typedef char* (*va_t)(const char *format, ...);
extern va_t va;

typedef void (*G_Error_t)(const char *fmt, ...);

typedef void (*Cbuf_ExecuteText_t)(cbufExec_t exec_when, const char* text);
static const Cbuf_ExecuteText_t Cbuf_ExecuteText = (Cbuf_ExecuteText_t)0x805FCC0;

typedef void* (*Z_MallocInternal_t)(int size);
static const Z_MallocInternal_t Z_MallocInternal = (Z_MallocInternal_t)0x806BBCC;

typedef void (*Hunk_ClearTempMemoryInternal_t)(void);
static const Hunk_ClearTempMemoryInternal_t Hunk_ClearTempMemoryInternal = (Hunk_ClearTempMemoryInternal_t)0x806C84B;

typedef qboolean (*Netchan_Process_t)(netchan_t *chan, msg_t *msg);
static const Netchan_Process_t Netchan_Process = (Netchan_Process_t)0x8083890;

typedef qboolean (*Sys_IsLANAddress_t)(netadr_t adr);
static const Sys_IsLANAddress_t Sys_IsLANAddress = (Sys_IsLANAddress_t)0x80D4EBC;

typedef char* (*SL_ConvertToString_t)(unsigned int index);
static const SL_ConvertToString_t SL_ConvertToString = (SL_ConvertToString_t)0x80A3460;

typedef short (*BigShort_t)(short l);
static const BigShort_t BigShort = (BigShort_t)0x80859B2;

typedef char* (*UI_GetMapRotationToken_t)(void);
static const UI_GetMapRotationToken_t UI_GetMapRotationToken = (UI_GetMapRotationToken_t)0x8087A6A;

typedef void (*ClientCommand_t)(int clientNum);
extern ClientCommand_t ClientCommand;

typedef qboolean (*StuckInClient_t)(gentity_s *self);
extern StuckInClient_t StuckInClient;

typedef int (*Jump_Check_t)();

//// BG
typedef int (*BG_GetNumWeapons_t)(void);
extern BG_GetNumWeapons_t BG_GetNumWeapons;

typedef weaponinfo_t* (*BG_GetInfoForWeapon_t)(unsigned int weaponIndex);
extern BG_GetInfoForWeapon_t BG_GetInfoForWeapon;

typedef int (*BG_GetWeaponIndexForName_t)(const char *name);
extern BG_GetWeaponIndexForName_t BG_GetWeaponIndexForName;

typedef int (*BG_AnimationIndexForString_t)(char *src);
extern BG_AnimationIndexForString_t BG_AnimationIndexForString;

typedef int (*BG_AnimScriptEvent_t)(playerState_t *ps, scriptAnimEventTypes_t event, int isContinue, int force);
extern BG_AnimScriptEvent_t BG_AnimScriptEvent;

typedef void (*BG_AddPredictableEventToPlayerstate_t)(int newEvent, int eventParm, playerState_t *ps);
extern BG_AddPredictableEventToPlayerstate_t BG_AddPredictableEventToPlayerstate;
////

//// Cmd
typedef char* (*Cmd_Argv_t)(int arg);
static const Cmd_Argv_t Cmd_Argv = (Cmd_Argv_t)0x80600F4;

typedef int (*Cmd_Argc_t)();
static const Cmd_Argc_t Cmd_Argc = (Cmd_Argc_t)0x80600EA;

typedef void (*Cmd_AddCommand_t)(const char *cmd_name, xcommand_t function);
static const Cmd_AddCommand_t Cmd_AddCommand = (Cmd_AddCommand_t)0x806043E;

typedef void (*Cmd_ArgvBuffer_t)(int arg, char *buffer, int bufferLength);
static const Cmd_ArgvBuffer_t Cmd_ArgvBuffer = (Cmd_ArgvBuffer_t)0x806014B;

typedef void (*Cmd_TokenizeString_t)(const char *text_in);
static const Cmd_TokenizeString_t Cmd_TokenizeString = (Cmd_TokenizeString_t)0x8060423;

typedef void (*Cmd_ExecuteString_t)(const char *cmd);
static const Cmd_ExecuteString_t Cmd_ExecuteString = (Cmd_ExecuteString_t)0x80605B5;
////

//// Com
typedef void (*Com_Printf_t)(const char *format, ...);
static const Com_Printf_t Com_Printf = (Com_Printf_t)0x806FC10;

typedef void (*Com_DPrintf_t)(const char *format, ...);
static const Com_DPrintf_t Com_DPrintf = (Com_DPrintf_t)0x806FC5F;

typedef int (*Com_sprintf_t)(char *dest, int size, const char *format, ...);
static const Com_sprintf_t Com_sprintf = (Com_sprintf_t)0x80861A6; //tbd

typedef void (*Com_PrintMessage_t)(int channel, const char *message);
static const Com_PrintMessage_t Com_PrintMessage = (Com_PrintMessage_t)0x806F827;

typedef void (*Com_Error_t)(errorParm_t code, const char *format, ...);
static const Com_Error_t Com_Error = (Com_Error_t)0x806FEF4;

typedef char* (*Com_Parse_t)(const char **data_p);
static const Com_Parse_t Com_Parse = (Com_Parse_t)0x8085323; 

typedef void (*Com_SkipRestOfLine_t)(const char **data);

typedef char* (*Com_ParseRestOfLine_t)(const char **data);

typedef int (*Com_ParseInt_t)(const char **data);

typedef int (*Com_Milliseconds_t)(void);
static const Com_Milliseconds_t Com_Milliseconds = (Com_Milliseconds_t)0x070BE8;

typedef void (*Com_BeginRedirect_t)(char *buffer, int buffersize, void (*flush)(char *));
static const Com_BeginRedirect_t Com_BeginRedirect = (Com_BeginRedirect_t)0x806F7B0;

typedef unsigned int (*Com_AddToString_t)(const char* string, char* buffer, unsigned int current, unsigned int length, byte escapeSpaces);
static const Com_AddToString_t Com_AddToString = (Com_AddToString_t)0x8072745;

typedef void (*Com_EndRedirect_t)(void);
static const Com_EndRedirect_t Com_EndRedirect = (Com_EndRedirect_t)0x806F7E9;
////

//// Cvar
typedef cvar_t* (*Cvar_Set_t)(const char *var_name, const char *value);
static const Cvar_Set_t Cvar_Set = (Cvar_Set_t)0x8073100;

typedef cvar_t* (*Cvar_Get_t)(const char *var_name, const char *var_value, unsigned short flags);
static const Cvar_Get_t Cvar_Get = (Cvar_Get_t)0x8072A7C;

typedef cvar_t* (*Cvar_FindVar_t)(const char *var_name);
static const Cvar_FindVar_t Cvar_FindVar = (Cvar_FindVar_t)0x8072916;

typedef char* (*Cvar_VariableString_t)(const char *cvarName);
static const Cvar_VariableString_t Cvar_VariableString = (Cvar_VariableString_t)0x807347C;

typedef float (*Cvar_VariableValue_t)(const char *var_name);
static const Cvar_VariableValue_t Cvar_VariableValue = (Cvar_VariableValue_t)0x807341C;

typedef char* (*Cvar_InfoString_t)(int bit);
static const Cvar_InfoString_t Cvar_InfoString = (Cvar_InfoString_t)0x80741CB;
////

//// FS
typedef void (*FS_ConvertPath_t)(char *s);
static const FS_ConvertPath_t FS_ConvertPath = (FS_ConvertPath_t)0x806418A;

typedef int (*FS_Read_t)(void *buffer, int len, fileHandle_t f);
static const FS_Read_t FS_Read = (FS_Read_t)0x8062960;

typedef long (*FS_SV_FOpenFileRead_t)(const char *filename, fileHandle_t *fp);
static const FS_SV_FOpenFileRead_t FS_SV_FOpenFileRead = (FS_SV_FOpenFileRead_t)0x8074596;

typedef int (*FS_iwPak_t)(char *pak, const char *base); //FS_idPak
static const FS_iwPak_t FS_iwPak = (FS_iwPak_t)0x80754EA;

typedef int (*FS_ReadFile_t)(const char* qpath, void** buffer);
static const FS_ReadFile_t FS_ReadFile = (FS_ReadFile_t)0x8062FBD; 

typedef void (*FS_FreeFile_t)(void* buffer);
static const FS_FreeFile_t FS_FreeFile = (FS_FreeFile_t)0x8063314;

typedef int (*FS_FOpenFileByMode_t)(const char *qpath, fileHandle_t *f, fsMode_t mode);
static const FS_FOpenFileByMode_t FS_FOpenFileByMode = (FS_FOpenFileByMode_t)0x8065E76; //tbd

typedef void (*FS_Write_t)(fileHandle_t h, const char *fmt, ...);
static const FS_Write_t FS_Write = (FS_Write_t)0x8062A90;

typedef void (*FS_FCloseFile_t)(fileHandle_t f);
static const FS_FCloseFile_t FS_FCloseFile = (FS_FCloseFile_t)0x80612A2;//tbd

typedef void (*FS_WriteFile_t)(const char* filename, const void* buffer, int size);
static const FS_WriteFile_t FS_WriteFile = (FS_WriteFile_t)0x806334C;//tbd
////

//// G
typedef void (*G_Say_t)(gentity_s *ent, gentity_s *target, int mode, const char *chatText);
extern G_Say_t G_Say;

typedef void (*G_RegisterCvars_t)(void);
extern G_RegisterCvars_t G_RegisterCvars;

typedef void (*G_AddEvent_t)(gentity_t *ent, int event, int eventParm);

typedef void (*G_AddPredictableEvent_t)(gentity_t *ent, int event, int eventParm);

typedef int (*G_LocalizedStringIndex_t)(const char *string);
extern G_LocalizedStringIndex_t G_LocalizedStringIndex;
////

//// Get
typedef unsigned int (*GetVariableName_t)(unsigned int a1);
static const GetVariableName_t GetVariableName = (GetVariableName_t)0x80A6AAC;

typedef unsigned int (*GetNextVariable_t)(unsigned int a1);
static const GetNextVariable_t GetNextVariable = (GetNextVariable_t)0x80A6A38;
////

//// Huff
typedef void (*Huff_Decompress_t)(msg_t *mbuf, int offset);
static const Huff_Decompress_t Huff_Decompress = (Huff_Decompress_t)0x8076C31;

typedef void (*Huff_offsetReceive_t)(node_t *node, int *ch, byte *fin, int *offset);
static const Huff_offsetReceive_t Huff_offsetReceive = (Huff_offsetReceive_t)0x8076A9B;
////

//// I
typedef int (*I_strncmp_t)(const char *s1, const char *s2, int n); //Q_strncmp
static const I_strncmp_t I_strncmp = (I_strncmp_t)0x8085F03; 

//// Info
typedef void (*Info_SetValueForKey_t)(char *s, const char *key, const char *value);
static const Info_SetValueForKey_t Info_SetValueForKey = (Info_SetValueForKey_t)0x8086855;

typedef char* (*Info_ValueForKey_t)(const char *s, const char *key);
static const Info_ValueForKey_t Info_ValueForKey = (Info_ValueForKey_t)0x8086397; 
////

//// MSG
typedef int (*MSG_ReadBits_t)(msg_t *msg, int numBits);
static const MSG_ReadBits_t MSG_ReadBits = (MSG_ReadBits_t)0x807FB40;

typedef int (*MSG_ReadBitsCompress_t)(const byte* input, byte* outputBuf, int readsize);
static const MSG_ReadBitsCompress_t MSG_ReadBitsCompress = (MSG_ReadBitsCompress_t)0x807FC6F;

typedef void (*MSG_Init_t)(msg_t *buf, byte *data, int length);
static const MSG_Init_t MSG_Init = (MSG_Init_t)0x807F928;

typedef void (*MSG_WriteByte_t)(msg_t *msg, int c);
static const MSG_WriteByte_t MSG_WriteByte = (MSG_WriteByte_t)0x807FCD8;

typedef void (*MSG_WriteShort_t)(msg_t *msg, int c);
static const MSG_WriteShort_t MSG_WriteShort = (MSG_WriteShort_t)0x807FD65;

typedef void (*MSG_WriteLong_t)(msg_t *msg, int c);
static const MSG_WriteLong_t MSG_WriteLong = (MSG_WriteLong_t)0x807FDB5;

typedef void (*MSG_WriteString_t)(msg_t *msg, const char *s);
static const MSG_WriteString_t MSG_WriteString = (MSG_WriteString_t)0x807FE03;

typedef void (*MSG_WriteData_t)(msg_t *msg, const void *data, int length);
static const MSG_WriteData_t MSG_WriteData = (MSG_WriteData_t)0x807FD10;

typedef char* (*MSG_ReadString_t)(msg_t *msg);
static const MSG_ReadString_t MSG_ReadString = (MSG_ReadString_t)0x808013B;

typedef void (*MSG_BeginReading_t)(msg_t *buf);
static const MSG_BeginReading_t MSG_BeginReading = (MSG_BeginReading_t)0x807F96B;

typedef int (*MSG_ReadLong_t)(msg_t *msg);
static const MSG_ReadLong_t MSG_ReadLong = (MSG_ReadLong_t)0x80800E8;

typedef char* (*MSG_ReadStringLine_t)(msg_t *msg);
static const MSG_ReadStringLine_t MSG_ReadStringLine = (MSG_ReadStringLine_t)0x8080212;

typedef int (*MSG_WriteBitsCompress_t)(const byte *datasrc, byte *buffdest, int bytecount);
static const MSG_WriteBitsCompress_t MSG_WriteBitsCompress = (MSG_WriteBitsCompress_t)0x807FC1B; 

typedef int (*MSG_ReadShort_t)(msg_t *msg);
static const MSG_ReadShort_t MSG_ReadShort = (MSG_ReadShort_t)0x8080093;

typedef int (*MSG_ReadByte_t)(msg_t *msg);
static const MSG_ReadByte_t MSG_ReadByte = (MSG_ReadByte_t)0x8080053;

typedef void (*MSG_WriteBigString_t)(msg_t *msg, const char *s);
static const MSG_WriteBigString_t MSG_WriteBigString = (MSG_WriteBigString_t)0x807FEDB;

typedef void (*MSG_WriteDeltaEntity_t)(msg_t *msg, entityState_t *from, entityState_t *to, qboolean force);
static const MSG_WriteDeltaEntity_t MSG_WriteDeltaEntity = (MSG_WriteDeltaEntity_t)0x808149A; 

typedef void (*MSG_WriteDeltaField_t)(msg_t *msg, const byte *from, const byte *to, const netField_t *field);
static const MSG_WriteDeltaField_t MSG_WriteDeltaField = (MSG_WriteDeltaField_t)0x808102D;

typedef void (*MSG_WriteDeltaHudElems_t)(msg_t *msg, hudelem_t *from, hudelem_t *to, int count);
static const MSG_WriteDeltaHudElems_t MSG_WriteDeltaHudElems = (MSG_WriteDeltaHudElems_t)0x8081AFF;

typedef char * (*MSG_ReadCommandString_t)(msg_t *msg);
static const MSG_ReadCommandString_t MSG_ReadCommandString = (MSG_ReadCommandString_t)0x808013B;

typedef void (*MSG_WriteReliableCommandToBuffer_t)(const char *source, char *destination, int length);
static const MSG_WriteReliableCommandToBuffer_t MSG_WriteReliableCommandToBuffer = (MSG_WriteReliableCommandToBuffer_t)0x8080550;
////

//// NET
typedef const char* (*NET_AdrToString_t)(netadr_t a);
static const NET_AdrToString_t NET_AdrToString = (NET_AdrToString_t)0x8083E10;

typedef void (*NET_OutOfBandPrint_t)(netsrc_t net_socket, netadr_t adr, const char *format, ...);
static const NET_OutOfBandPrint_t NET_OutOfBandPrint = (NET_OutOfBandPrint_t)0x808428E; 

typedef qboolean (*NET_StringToAdr_t)(const char *s, netadr_t *a);
static const NET_StringToAdr_t NET_StringToAdr = (NET_StringToAdr_t)0x80844E0;

typedef qboolean (*NET_CompareBaseAdr_t)(netadr_t a, netadr_t b);
static const NET_CompareBaseAdr_t NET_CompareBaseAdr = (NET_CompareBaseAdr_t)0x8083DE3;

typedef qboolean (*NET_CompareAdr_t)(netadr_t a, netadr_t b);
static const NET_CompareAdr_t NET_CompareAdr = (NET_CompareAdr_t)0x808400F;
////

//// PM
typedef int (*PM_GetEffectiveStance_t)(playerState_t *ps);

typedef void (*PM_ClipVelocity_t)(const float *in, const float *normal, float *out, float overbounce);

typedef void (*PM_NoclipMove_t)();
////

//// Q
typedef char* (*Q_strlwr_t)(char *s1);
extern Q_strlwr_t Q_strlwr;

typedef char* (*Q_strupr_t)(char *s1);
extern Q_strupr_t Q_strupr;

typedef void (*Q_strcat_t)(char *dest, int size, const char *src);

typedef void (*Q_strncpyz_t)(char *dest, const char *src, int destsize);

typedef void (*Q_CleanStr_t)(char *string);

typedef int (*Q_stricmp_t)(const char *s1, const char *s2);
static const Q_stricmp_t Q_stricmp = (Q_stricmp_t)0x8085F72; //tbd
////

//// Scr
typedef xfunction_t (*Scr_GetFunction_t)(const char** v_functionName, qboolean *v_developer);
extern Scr_GetFunction_t Scr_GetFunction;

typedef xmethod_t (*Scr_GetMethod_t)(const char** v_methodName, qboolean *v_developer);
extern Scr_GetMethod_t Scr_GetMethod;

typedef void (*Scr_Error_t)(const char *string);
extern Scr_Error_t Scr_Error;

typedef short (*Scr_ExecThread_t)(int callbackHook, unsigned int numArgs);
extern Scr_ExecThread_t Scr_ExecThread;

typedef short (*Scr_ExecEntThread_t)(gentity_t* ent, int callbackHook, unsigned int numArgs);
extern Scr_ExecEntThread_t Scr_ExecEntThread;

typedef unsigned short (*Scr_ExecEntThreadNum_t)(int entnum, unsigned int classnum, int handle, unsigned int paramcount);
extern Scr_ExecEntThreadNum_t Scr_ExecEntThreadNum;

typedef short (*Scr_FreeThread_t)(short thread_id);
extern Scr_FreeThread_t Scr_FreeThread;

typedef int (*Scr_GetFunctionHandle_t)(const char* scriptName, const char* labelName);

typedef int (*Scr_GetNumParam_t)(void);
extern Scr_GetNumParam_t Scr_GetNumParam;

typedef int (*Scr_IsSystemActive_t)();
extern Scr_IsSystemActive_t Scr_IsSystemActive;

typedef int (*Scr_GetInt_t)(unsigned int param);
extern Scr_GetInt_t Scr_GetInt;

typedef const char* (*Scr_GetString_t)(unsigned int param);
extern Scr_GetString_t Scr_GetString;

typedef int (*Scr_GetType_t)(unsigned int param);
extern Scr_GetType_t Scr_GetType;

typedef gentity_t* (*Scr_GetEntity_t)(unsigned int index);
extern Scr_GetEntity_t Scr_GetEntity;

typedef void (*Scr_AddBool_t)(qboolean value);
extern Scr_AddBool_t Scr_AddBool;

typedef void (*Scr_AddInt_t)(int value);
extern Scr_AddInt_t Scr_AddInt;

typedef void (*Scr_AddFloat_t)(float value);
extern Scr_AddFloat_t Scr_AddFloat;

typedef void (*Scr_AddString_t)(const char *string);
extern Scr_AddString_t Scr_AddString;

typedef void (*Scr_AddUndefined_t)(void);
extern Scr_AddUndefined_t Scr_AddUndefined;

typedef void (*Scr_AddVector_t)(vec3_t vec);
extern Scr_AddVector_t Scr_AddVector;

typedef void (*Scr_MakeArray_t)(void);
extern Scr_MakeArray_t Scr_MakeArray;

typedef void (*Scr_AddArray_t)(void);
extern Scr_AddArray_t Scr_AddArray;

typedef void (*Scr_AddObject_t)(unsigned int object);
extern Scr_AddObject_t Scr_AddObject;

typedef unsigned int (*Scr_LoadScript_t)(const char *filename);

typedef void (*Scr_ObjectError_t)(const char *error);
extern Scr_ObjectError_t Scr_ObjectError;

typedef unsigned short (*Scr_GetConstString_t)(unsigned int param);
extern Scr_GetConstString_t Scr_GetConstString;

typedef void (*Scr_ParamError_t)(int paramNum, const char *error);
extern Scr_ParamError_t Scr_ParamError;

typedef int (*Scr_GetPointerType_t)(unsigned int param);
extern Scr_GetPointerType_t Scr_GetPointerType;
////

//// SV
typedef void (*SV_ClientEnterWorld_t)(client_t *cl, usercmd_t *cmd);
static const SV_ClientEnterWorld_t SV_ClientEnterWorld = (SV_ClientEnterWorld_t)0x808B12A; //tbd

typedef void (*SV_SendClientGameState_t)(client_t *cl);
static const SV_SendClientGameState_t SV_SendClientGameState = (SV_SendClientGameState_t)0x808AE44; //tbd

typedef qboolean (*SV_ClientCommand_t)(client_t *cl, msg_t *msg);
static const SV_ClientCommand_t SV_ClientCommand = (SV_ClientCommand_t)0x808C858; //tbd

typedef void (*SV_SendClientSnapshot_t)(client_t *cl);
static const SV_SendClientSnapshot_t SV_SendClientSnapshot = (SV_SendClientSnapshot_t)0x8097C2F; //tbd

typedef void (*SV_UserMove_t)(client_t *cl, msg_t *msg, qboolean delta);
static const SV_UserMove_t SV_UserMove = (SV_UserMove_t)0x808CADE;//tbd

typedef void (*SV_SpawnServer_t)(char *server);
static const SV_SpawnServer_t SV_SpawnServer = (SV_SpawnServer_t)0x8090D0F;

typedef void (*SV_InitArchivedSnapshot_t)(void);
static const SV_InitArchivedSnapshot_t SV_InitArchivedSnapshot = (SV_InitArchivedSnapshot_t)0x8090BB1;

typedef void (*SV_RestartGameProgs_t)(int savepersist);
static const SV_RestartGameProgs_t SV_RestartGameProgs = (SV_RestartGameProgs_t)0x808FE4B;//tbd

typedef void (*SV_RunFrame_t)(void);
static const SV_RunFrame_t SV_RunFrame = (SV_RunFrame_t)0x8094069;

typedef void (*SV_AddServerCommand_t)(client_t *client, svscmd_type type, const char *cmd);
static const SV_AddServerCommand_t SV_AddServerCommand = (SV_AddServerCommand_t)0x8091E1B;

typedef void (*SV_SendServerCommand_t)(client_t *cl, int type, const char *fmt, ...);
static const SV_SendServerCommand_t SV_SendServerCommand = (SV_SendServerCommand_t)0x80920DE;

typedef void (*SV_DropClient_t)(client_t *drop, const char *reason);
static const SV_DropClient_t SV_DropClient = (SV_DropClient_t)0x808AC11;

typedef void (*SVC_RemoteCommand_t)(netadr_t from, msg_t *msg);
static const SVC_RemoteCommand_t SVC_RemoteCommand = (SVC_RemoteCommand_t)0x80930D0;

typedef void (*SV_GetChallenge_t)(netadr_t from);
static const SV_GetChallenge_t SV_GetChallenge = (SV_GetChallenge_t)0x80889D0;

typedef void (*SV_DirectConnect_t)(netadr_t from);
static const SV_DirectConnect_t SV_DirectConnect = (SV_DirectConnect_t)0x8089E7E;

typedef void (*SV_SetConfigstring_t)(int index, const char *val);
static const SV_SetConfigstring_t SV_SetConfigstring = (SV_SetConfigstring_t)0x808FF60;

typedef playerState_t* (*SV_GameClientNum_t)(int num);
static const SV_GameClientNum_t SV_GameClientNum = (SV_GameClientNum_t)0x808D331;

typedef void (*SV_AuthorizeIpPacket_t)(netadr_t from);
static const SV_AuthorizeIpPacket_t SV_AuthorizeIpPacket = (SV_AuthorizeIpPacket_t)0x80893C1;

typedef client_t* (*SV_GetPlayerByNum_t)(void);
static const SV_GetPlayerByNum_t SV_GetPlayerByNum = (SV_GetPlayerByNum_t)0x8087417;

typedef void (*SV_MapRestart_f_t)(void);
static const SV_MapRestart_f_t SV_MapRestart_f = (SV_MapRestart_f_t)0x808773A;

typedef void (*SV_ExecuteClientCommand_t)(client_t *cl, char *s, qboolean clientOK);
static const SV_ExecuteClientCommand_t SV_ExecuteClientCommand = (SV_ExecuteClientCommand_t)0x808C7A9;

typedef void (*SV_Netchan_AddOOBProfilePacket_t)(int iLength);
static const SV_Netchan_AddOOBProfilePacket_t SV_Netchan_AddOOBProfilePacket = (SV_Netchan_AddOOBProfilePacket_t)0x8094928;

typedef void (*SV_UpdateUserinfo_f_t)(client_t *cl);
static const SV_UpdateUserinfo_f_t SV_UpdateUserinfo_f = (SV_UpdateUserinfo_f_t)0x808C743;

typedef void (*SV_Disconnect_f_t)(client_t *cl);
static const SV_Disconnect_f_t SV_Disconnect_f = (SV_Disconnect_f_t)0x808C13E;

typedef void (*SV_VerifyPaks_f_t)(client_t *cl);
static const SV_VerifyPaks_f_t SV_VerifyPaks_f = (SV_VerifyPaks_f_t)0x808C159;

typedef void (*SV_ResetPureClient_f_t)(client_t *cl);
static const SV_ResetPureClient_f_t SV_ResetPureClient_f = (SV_ResetPureClient_f_t)0x808C4EB;

typedef void (*SV_BeginDownload_f_t)(client_t *cl);
static const SV_BeginDownload_f_t SV_BeginDownload_f = (SV_BeginDownload_f_t)0x808B456;

typedef void (*SV_NextDownload_f_t)(client_t *cl);
static const SV_NextDownload_f_t SV_NextDownload_f = (SV_NextDownload_f_t)0x808B352;

typedef void (*SV_StopDownload_f_t)(client_t *cl);
static const SV_StopDownload_f_t SV_StopDownload_f = (SV_StopDownload_f_t)0x808B298;

typedef void (*SV_DoneDownload_f_t)(client_t *cl);
static const SV_DoneDownload_f_t SV_DoneDownload_f = (SV_DoneDownload_f_t)0x808B2E8;

typedef void (*SV_RetransmitDownload_f_t)(client_t *cl);
static const SV_RetransmitDownload_f_t SV_RetransmitDownload_f = (SV_RetransmitDownload_f_t)0x808B313;

typedef gentity_t* (*SV_ClientThink_t)(client_t *cl, usercmd_t *cmd);
static const SV_ClientThink_t SV_ClientThink = (SV_ClientThink_t)0x808CA58;

typedef void (*SV_Netchan_TransmitNextFragment_t)(netchan_t *chan);
static const SV_Netchan_TransmitNextFragment_t SV_Netchan_TransmitNextFragment = (SV_Netchan_TransmitNextFragment_t)0x80948D0;

typedef qboolean (*SV_Netchan_Transmit_t)(client_t *client, byte *data, int length);
static const SV_Netchan_Transmit_t SV_Netchan_Transmit = (SV_Netchan_Transmit_t)0x80948E3;

typedef void (*SV_Netchan_Decode_t)(client_t *client, byte *data, int remaining);
static const SV_Netchan_Decode_t SV_Netchan_Decode = (SV_Netchan_Decode_t)0x8094822;

typedef void (*SV_ConnectionlessPacket_t)(netadr_t from, msg_t *msg);
static const SV_ConnectionlessPacket_t SV_ConnectionlessPacket = (SV_ConnectionlessPacket_t)0x809336A;

typedef void (*SV_ExecuteClientMessage_t)(client_t *cl, msg_t *msg);
static const SV_ExecuteClientMessage_t SV_ExecuteClientMessage = (SV_ExecuteClientMessage_t)0x808CDD0;

typedef void (*SV_UserinfoChanged_t)(client_t *client);
static const SV_UserinfoChanged_t SV_UserinfoChanged = (SV_UserinfoChanged_t)0x808C4FD;

typedef void (*SV_UpdateServerCommandsToClient_t)(client_t *client, msg_t *msg);
static const SV_UpdateServerCommandsToClient_t SV_UpdateServerCommandsToClient = (SV_UpdateServerCommandsToClient_t)0x80959D0;//tbd

typedef void (*SV_SendMessageToClient_t)(msg_t *msg, client_t *cl);
static const SV_SendMessageToClient_t SV_SendMessageToClient = (SV_SendMessageToClient_t)0x8097A2F;

typedef void (*SV_DelayDropClient_t)(client_t *client, const char *dropmsg);
static const SV_DelayDropClient_t SV_DelayDropClient = (SV_DelayDropClient_t)0x808ADFB;

typedef int (*SV_CanReplaceServerCommand_t)(client_t *client, const char *cmd);
static const SV_CanReplaceServerCommand_t SV_CanReplaceServerCommand = (SV_CanReplaceServerCommand_t)0x8091BEC;//tbd

typedef void (*SV_FlushRedirect_t)(char *outputbuf);
static const SV_FlushRedirect_t SV_FlushRedirect = (SV_FlushRedirect_t)0x8092FE8;
////

//// SVC
typedef void (*SVC_Info_t)(netadr_t from);
static const SVC_Info_t SVC_Info = (SVC_Info_t)0x8092A74;

typedef void (*SVC_Status_t)(netadr_t from);
static const SVC_Status_t SVC_Status = (SVC_Status_t)0x809246E;
////

//// trap
typedef void (*trap_Argv_t)(int arg, char *buffer, int bufferLength);

typedef void (*trap_SendServerCommand_t)(int clientnum, svscmd_type type, const char *text);
extern trap_SendServerCommand_t trap_SendServerCommand;

typedef const char* (*trap_GetConfigstringConst_t)(int index);
extern trap_GetConfigstringConst_t trap_GetConfigstringConst;

typedef void (*trap_GetConfigstring_t)(int index, char *buffer, int bufferSize);
extern trap_GetConfigstring_t trap_GetConfigstring;

typedef void (*trap_GetUserinfo_t)(int num, char *buffer, int bufferSize);

typedef void (*trap_SetConfigstring_t)(int index, const char *val);
extern trap_SetConfigstring_t trap_SetConfigstring;

typedef int (*trap_GetArchivedPlayerState_t)(int clientNum, int *pArchiveTime, playerState_t *ps);
////

typedef float (*Jump_Set_t)(float height);
extern Jump_Set_t Jump_Set;