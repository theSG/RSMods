#include "WwiseHijack.hpp"

// Yeah don't touch this file if you don't have to...


/// <summary>
/// Audio Engine Hijacks
/// </summary>

namespace WwiseVariables {
	uintptr_t func_Wwise_Root_IsRestoreSinkRequested = 0x1f5bfd3;
	uintptr_t func_Wwise_Root_IsUsingDummySink = 0x1f5bfc3;
	// IAkStreamMgr
	uintptr_t func_Wwise_IAkStreamMgr_m_pStreamMgr = 0x134f500;
	// MemoryMgr
	uintptr_t func_Wwise_Memory_CheckPoolId = 0x1f32828;
	uintptr_t func_Wwise_Memory_CreatePool = 0x1f32519;
	uintptr_t func_Wwise_Memory_DestroyPool = 0x1f326d4;
	uintptr_t func_Wwise_Memory_Falign = 0x1f329ee;
	uintptr_t func_Wwise_Memory_GetBlock = 0x1f32aee;
	uintptr_t func_Wwise_Memory_GetBlockSize = 0x1f327e8;
	uintptr_t func_Wwise_Memory_GetMaxPools = 0x1f32818;
	uintptr_t func_Wwise_Memory_GetNumPools = 0x1f32808;
	uintptr_t func_Wwise_Memory_GetPoolAttributes = 0x1f327c4;
	uintptr_t func_Wwise_Memory_GetPoolMemoryUsed = 0x1f32aae;
	uintptr_t func_Wwise_Memory_GetPoolName = 0x2006a57;
	uintptr_t func_Wwise_Memory_GetPoolStats = 0x1f32a3e;
	uintptr_t func_Wwise_Memory_IsInitialized = 0x1f32784;
	uintptr_t func_Wwise_Memory_Malign = 0x1f3298a;
	uintptr_t func_Wwise_Memory_Malloc = 0x1f3290a;
	uintptr_t func_Wwise_Memory_ReleaseBlock = 0x1f32b3e;
	uintptr_t func_Wwise_Memory_SetMonitoring = 0x167e4f8;
	uintptr_t func_Wwise_Memory_SetPoolName = 0x1f32794;
	uintptr_t func_Wwise_Memory_Term = 0x1f32b8e;
	// Monitor
	uintptr_t func_Wwise_Monitor_PostCode = 0x1f587ba;
	// Motion Engine
	uintptr_t func_Wwise_Motion_AddPlayerMotionDevice = 0x1f58638;
	uintptr_t func_Wwise_Motion_RegisterMotionDevice = 0x1f58712;
	uintptr_t func_Wwise_Motion_RemovePlayerMotionDevice = 0x1f586ad;
	uintptr_t func_Wwise_Motion_SetPlayerListener = 0x1f58722;
	uintptr_t func_Wwise_Motion_SetPlayerVolume = 0x1f5876e;
	// Music Engine
	uintptr_t func_Wwise_Music_GetDefaultInitSettings = 0x1f340ef;
	uintptr_t func_Wwise_Music_GetPlayingSegmentInfo = 0x1f3413f;
	uintptr_t func_Wwise_Music_Init = 0x1f34f8c;
	uintptr_t func_Wwise_Music_Term = 0x1f34e38;
	// Sound Engine
	uintptr_t func_Wwise_Sound_AddBehaviorExtension = 0x1f5a741;
	uintptr_t func_Wwise_Sound_CancelBankCallbackCookie = 0x1f57f0c;
	uintptr_t func_Wwise_Sound_CancelEventCallback = 0x1f5760d;
	uintptr_t func_Wwise_Sound_CancelEventCallbackCookie = 0x1f575ed;
	uintptr_t func_Wwise_Sound_ClearBanks = 0x1f58ecc;
	uintptr_t func_Wwise_Sound_ClearPreparedEvents = 0x1f58064;
	uintptr_t func_Wwise_Sound_CloneActorMixerEffect = 0x1f5bd9d;
	uintptr_t func_Wwise_Sound_CloneBusEffect = 0x1f5bd79;
	uintptr_t func_Wwise_Sound_DynamicDialogue_ResolveDialogueEvent_UniqueID = 0x1f5b68e;
	uintptr_t func_Wwise_Sound_DynamicDialogue_ResolveDialogueEvent_Char = 0x1f5b77a;
	uintptr_t func_Wwise_Sound_DynamicSequence_Break = 0x1f5baba;
	uintptr_t func_Wwise_Sound_DynamicSequence_Close = 0x1f5bb4c;
	uintptr_t func_Wwise_Sound_DynamicSequence_LockPlaylist = 0x1f5bbde;
	uintptr_t func_Wwise_Sound_DynamicSequence_Open = 0x1f57661;
	uintptr_t func_Wwise_Sound_DynamicSequence_Pause = 0x1f5b8ac;
	uintptr_t func_Wwise_Sound_DynamicSequence_Play = 0x1f5b816;
	uintptr_t func_Wwise_Sound_DynamicSequence_Resume = 0x1f5b93e;
	uintptr_t func_Wwise_Sound_DynamicSequence_Stop = 0x1f5b9d4;
	uintptr_t func_Wwise_Sound_DynamicSequence_UnlockPlaylist = 0x1f5bc1e;
	uintptr_t func_Wwise_Sound_ExecuteActionOnEvent_UniqueID = 0x1f5b302;
	uintptr_t func_Wwise_Sound_ExecuteActionOnEvent_Char = 0x1f5b3ca;
	uintptr_t func_Wwise_Sound_g_PlayingID = 0x134e790;
	uintptr_t func_Wwise_Sound_GetDefaultInitSettings = 0x1f5683d;
	uintptr_t func_Wwise_Sound_GetDefaultPlatformInitSettings = 0x1f5689d;
	uintptr_t func_Wwise_Sound_GetIDFromString = 0x1f58956;
	uintptr_t func_Wwise_Sound_GetPanningRule = 0x1f568fd;
	uintptr_t func_Wwise_Sound_GetSourcePlayPosition = 0x1f57631;
	uintptr_t func_Wwise_Sound_GetSpeakerConfiguration = 0x1f5690d;
	uintptr_t func_Wwise_Sound_Init = 0x1f5bdbd;
	uintptr_t func_Wwise_Sound_IsInitialized = 0x01f56829;
	uintptr_t func_Wwise_Sound_LoadBank_BankID_MemPoolID = 0x1f57a8f;
	uintptr_t func_Wwise_Sound_LoadBank_Void_UInt32_BankID = 0x1f57b81;
	uintptr_t func_Wwise_Sound_LoadBank_BankID_Callback = 0x1f57c55;
	uintptr_t func_Wwise_Sound_LoadBank_Void_UInt32_Callback = 0x1f57cd0;
	uintptr_t func_Wwise_Sound_LoadBank_Char_MemPoolID = 0x1f5916c;
	uintptr_t func_Wwise_Sound_LoadBank_Char_Callback = 0x1f592c1;
	uintptr_t func_Wwise_Sound_LoadBankUnique = 0x1f5933c;
	uintptr_t func_Wwise_Sound_PlaySourcePlugin = 0x1f574d5;
	uintptr_t func_Wwise_Sound_PostEvent_Char = 0x1f5b260;
	uintptr_t func_Wwise_Sound_PostEvent_UniqueID = 0x1f5bf11;
	uintptr_t func_Wwise_Sound_PostTrigger_TriggerID = 0x1f56e60;
	uintptr_t func_Wwise_Sound_PostTrigger_Char = 0x1f58c2b;
	uintptr_t func_Wwise_Sound_PrepareBank_BankID_Callback = 0x1f57f2c;
	uintptr_t func_Wwise_Sound_PrepareBank_BankID_BankContent = 0x1f59588;
	uintptr_t func_Wwise_Sound_PrepareBank_Char_Callback = 0x1f596d4;
	uintptr_t func_Wwise_Sound_PrepareBank_Char_BankContent = 0x1f5a651;
	uintptr_t func_Wwise_Sound_PrepareEvent_EventID_UInt32 = 0x1f57fa1;
	uintptr_t func_Wwise_Sound_PrepareEvent_EventID_UInt32_Callback_Void = 0x1f58034;
	uintptr_t func_Wwise_Sound_PrepareEvent_Char_UInt32 = 0x1f59915;
	uintptr_t func_Wwise_Sound_PrepareEvent_Char_UInt32_Callback_Void = 0x1f59c73;
	uintptr_t func_Wwise_Sound_PrepareGameSyncs_UInt32_UInt32_UInt32_Callback_Void = 0x1f58125;
	uintptr_t func_Wwise_Sound_PrepareGameSyncs_UInt32_UInt32_UInt32 = 0x1f58155;
	uintptr_t func_Wwise_Sound_PrepareGameSyncs_Char_Char_UInt32_Callback_Void = 0x1f59f4d;
	uintptr_t func_Wwise_Sound_PrepareGameSyncs_Char_Char_UInt32 = 0x1f5a1c0;
	uintptr_t func_Wwise_Sound_Query_GetActiveGameObjects = 0x1f55e5f;
	uintptr_t func_Wwise_Sound_Query_GetActiveListeners = 0x1f56168;
	uintptr_t func_Wwise_Sound_Query_GetCustomPropertyValue_Int32 = 0x1f55f95;
	uintptr_t func_Wwise_Sound_Query_GetCustomPropertyValue_Real32 = 0x1f56025;
	uintptr_t func_Wwise_Sound_Query_GetEventIDFromPlayingID = 0x1f55f25;
	uintptr_t func_Wwise_Sound_Query_GetGameObjectAuxSendValues = 0x1f56493;
	uintptr_t func_Wwise_Sound_Query_GetGameObjectDryLevelValue = 0x1f5658f;
	uintptr_t func_Wwise_Sound_Query_GetGameObjectFromPlayingID = 0x1f55f45;
	uintptr_t func_Wwise_Sound_Query_GetIsGameObjectActive = 0x1f55e8f;
	uintptr_t func_Wwise_Sound_Query_GetListenerPosition = 0x1f55c7f;
	uintptr_t func_Wwise_Sound_Query_GetListenerSpatialization = 0x1f55cdf;
	uintptr_t func_Wwise_Sound_Query_GetMaxRadius_RadiusList = 0x1f55ebf;
	uintptr_t func_Wwise_Sound_Query_GetMaxRadius_GameObject = 0x1f55eef;
	uintptr_t func_Wwise_Sound_Query_GetObjectObstructionAndOcclusion = 0x1f56622;
	uintptr_t func_Wwise_Sound_Query_GetPlayingIDsFromGameObject = 0x1f55f65;
	uintptr_t func_Wwise_Sound_Query_GetPosition = 0x1f560b5;
	uintptr_t func_Wwise_Sound_Query_GetPositioningInfo = 0x1f55dff;
	uintptr_t func_Wwise_Sound_Query_GetRTPCValue_RTPCID = 0x1f561fb;
	uintptr_t func_Wwise_Sound_Query_GetRTPCValue_Char = 0x1f5634a;
	uintptr_t func_Wwise_Sound_Query_GetState_StateGroupID = 0x1f55d1f;
	uintptr_t func_Wwise_Sound_Query_GetState_Char = 0x1f55daf;
	uintptr_t func_Wwise_Sound_Query_GetSwitch_SwitchGroupID = 0x1f5638a;
	uintptr_t func_Wwise_Sound_Query_GetSwitch_Char = 0x1f56463;
	uintptr_t func_Wwise_Sound_Query_QueryAudioObjectIDs_UniqueID = 0x1f566e5;
	uintptr_t func_Wwise_Sound_Query_QueryAudioObjectIDs_Char = 0x1f56799;
	uintptr_t func_Wwise_Sound_RegisterBusVolumeCallback = 0x1f57018;
	uintptr_t func_Wwise_Sound_RegisterCodec = 0x1f5693d;
	uintptr_t func_Wwise_Sound_RegisterGameObj = 0x1f57728;
	uintptr_t func_Wwise_Sound_RegisterGlobalCallback = 0x1f5a814;
	uintptr_t func_Wwise_Sound_RegisterPlugin = 0x1f5692d;
	uintptr_t func_Wwise_Sound_RemoveBehavioralExtension = 0x1f5a7b1;
	uintptr_t func_Wwise_Sound_RenderAudio = 0x1f5691d;
	uintptr_t func_Wwise_Sound_ResetRTPCValue_RTPCID = 0x1f56f0e;
	uintptr_t func_Wwise_Sound_ResetRTPCValue_Char = 0x1f58e2c;
	uintptr_t func_Wwise_Sound_SeekOnEvent_UniqueID_Int32 = 0x1f5b3fa;
	uintptr_t func_Wwise_Sound_SeekOnEvent_Char_Int32 = 0x1f5b4af;
	uintptr_t func_Wwise_Sound_SeekOnEvent_UniqueID_Float = 0x1f5b4df;
	uintptr_t func_Wwise_Sound_SeekOnEvent_Char_Float = 0x1f5b5f9;
	uintptr_t func_Wwise_Sound_SetActiveListeners = 0x1f56b76;
	uintptr_t func_Wwise_Sound_SetActorMixerEffect = 0x1f5825a;
	uintptr_t func_Wwise_Sound_SetAttenuationScalingFactor = 0x1f56aba;
	uintptr_t func_Wwise_Sound_SetBankLoadIOSettings = 0x1f5785a;
	uintptr_t func_Wwise_Sound_SetBusEffect_UniqueID = 0x1f581f4;
	uintptr_t func_Wwise_Sound_SetBusEffect_Char = 0x1f5a3b1;
	uintptr_t func_Wwise_Sound_SetEffectParam = 0x1f582bc;
	uintptr_t func_Wwise_Sound_SetGameObjectAuxSendValues = 0x1f56fa9;
	uintptr_t func_Wwise_Sound_SetGameObjectOutputBusVolume = 0x1f5704c;
	uintptr_t func_Wwise_Sound_SetListenerPipeline = 0x1f56d24;
	uintptr_t func_Wwise_Sound_SetListenerPosition = 0x1f56bc2;
	uintptr_t func_Wwise_Sound_SetListenerScalingFactor = 0x1f56b1a;
	uintptr_t func_Wwise_Sound_SetListenerSpatialization = 0x1f56c90;
	uintptr_t func_Wwise_Sound_SetMaxNumVoicesLimit = 0x1f58e8c;
	uintptr_t func_Wwise_Sound_SetMultiplePositions = 0x1f569c8;
	uintptr_t func_Wwise_Sound_SetObjectObstructionAndOcclusion = 0x1f57098;
	uintptr_t func_Wwise_Sound_SetPanningRule = 0x1f5744c;
	uintptr_t func_Wwise_Sound_SetPosition = 0x1f58a31;
	uintptr_t func_Wwise_Sound_SetPositionInternal = 0x1f5694d;
	uintptr_t func_Wwise_Sound_SetRTPCValue_RTPCID = 0x1f56d73;
	uintptr_t func_Wwise_Sound_SetRTPCValue_Char = 0x1f58a91;
	uintptr_t func_Wwise_Sound_SetState_StateGroupID = 0x1f58c8b;
	uintptr_t func_Wwise_Sound_SetState_Char = 0x1f58d69;
	uintptr_t func_Wwise_Sound_SetSwitch_SwitchGroupID = 0x1f56e11;
	uintptr_t func_Wwise_Sound_SetSwitch_Char = 0x1f58b50;
	uintptr_t func_Wwise_Sound_SetVolumeThreshold = 0x1f58e6c;
	uintptr_t func_Wwise_Sound_StartOutputCapture = 0x1f583a4;
	uintptr_t func_Wwise_Sound_StopAll = 0x1f58590;
	uintptr_t func_Wwise_Sound_StopOutputCapture = 0x1f58463;
	uintptr_t func_Wwise_Sound_StopPlayingID = 0x1f585d9;
	uintptr_t func_Wwise_Sound_StopSourcePlugin = 0x1f5756c;
	uintptr_t func_Wwise_Sound_Term = 0x1f5acc6;
	uintptr_t func_Wwise_Sound_UnloadBank_BankID_MemPoolID = 0x1f57d6b;
	uintptr_t func_Wwise_Sound_UnloadBank_BankID_Callback = 0x1f57e91;
	uintptr_t func_Wwise_Sound_UnloadBank_Char_MemPoolID = 0x1f593e7;
	uintptr_t func_Wwise_Sound_UnloadBank_Char_Callback = 0x1f59482;
	uintptr_t func_Wwise_Sound_UnloadBankUnique = 0x1f594fd;
	uintptr_t func_Wwise_Sound_UnregisterAllGameObj = 0x1f577dd;
	uintptr_t func_Wwise_Sound_UnregisterGameObj = 0x1f57784;
	uintptr_t func_Wwise_Sound_UnregisterGlobalCallback = 0x1f5a844;
	// StreamMgr
	uintptr_t func_Wwise_Stream_AddLanguageChangeObserver = 0x1fbc23a;
	uintptr_t func_Wwise_Stream_Create = 0x1fbbf66;
	uintptr_t func_Wwise_Stream_CreateDevice = 0x1fbc3dc;
	uintptr_t func_Wwise_Stream_DestroyDevice = 0x1fbbfe6;
	uintptr_t func_Wwise_Stream_FlushAllCaches = 0x1fbc076;
	uintptr_t func_Wwise_Stream_GetCurrentLanguage = 0x1fbb4c3;
	uintptr_t func_Wwise_Stream_GetDefaultDeviceSettings = 0x1fbb433;
	uintptr_t func_Wwise_Stream_GetDefaultSettings = 0x1fbb423;
	uintptr_t func_Wwise_Stream_GetFileLocationResolver = 0x1fbb493;
	uintptr_t func_Wwise_Stream_GetPoolID = 0x1fbb4b3;
	uintptr_t func_Wwise_Stream_RemoveLanguageChangeObserver = 0x1fbc056;
	uintptr_t func_Wwise_Stream_SetCurrentLanguage = 0x1fbc036;
	uintptr_t func_Wwise_Stream_SetFileLocationResolver = 0x1fbb4a3;

	// Rocksmith Function Hijack
	uintptr_t func_Rocksmith_RegisterAllPlugins = 0x01ca0780;
	uintptr_t func_Rocksmith_SetAudioInputCallbacks = 0x01f10d67;

	// End Wwise Hijack

	// Template: type Variable = (type)MemoryAddress;
	// Example: tSetRTPCValue_Char Wwise_Sound_SetRTPCValue_Char = (tSetRTPCValue_Char)func_Wwise_Sound_SetRTPCValue_Char;

	//// Root Functions
	//tIsRestoreSinkRequested Wwise_Root_IsRestoreSinkRequested = (tIsRestoreSinkRequested)func_Wwise_Root_IsRestoreSinkRequested;
	//tIsUsingDummySink Wwise_Root_IsUsingDummySink = (tIsUsingDummySink)func_Wwise_Root_IsUsingDummySink;

	//// MemoryMgr
	//tMemory_CheckPoolId Wwise_Memory_CheckPoolId = (tMemory_CheckPoolId)func_Wwise_Memory_CheckPoolId;
	//tMemory_CreatePool Wwise_Memory_CreatePool = (tMemory_CreatePool)func_Wwise_Memory_CreatePool;
	//tMemory_DestroyPool Wwise_Memory_DestroyPool = (tMemory_DestroyPool)func_Wwise_Memory_DestroyPool;
	//tMemory_Falign Wwise_Memory_Falign = (tMemory_Falign)func_Wwise_Memory_Falign;
	//tMemory_GetBlock Wwise_Memory_GetBlock = (tMemory_GetBlock)func_Wwise_Memory_GetBlock;
	//tMemory_GetBlockSize Wwise_Memory_GetBlockSize = (tMemory_GetBlockSize)func_Wwise_Memory_GetBlockSize;
	//tMemory_GetMaxPools Wwise_Memory_GetMaxPools = (tMemory_GetMaxPools)func_Wwise_Memory_GetMaxPools;
	//tMemory_GetNumPools Wwise_Memory_GetNumPools = (tMemory_GetNumPools)func_Wwise_Memory_GetNumPools;
	//tMemory_GetPoolAttributes Wwise_Memory_GetPoolAttributes = (tMemory_GetPoolAttributes)func_Wwise_Memory_GetPoolAttributes;
	//tMemory_GetPoolMemoryUsed Wwise_Memory_GetPoolMemoryUsed = (tMemory_GetPoolMemoryUsed)func_Wwise_Memory_GetPoolMemoryUsed;
	//tMemory_GetPoolName Wwise_Memory_GetPoolName = (tMemory_GetPoolName)func_Wwise_Memory_GetPoolName;
	//tMemory_GetPoolStats Wwise_Memory_GetPoolStats = (tMemory_GetPoolStats)func_Wwise_Memory_GetPoolStats;
	//tMemory_IsInitialized Wwise_Memory_IsInitialized = (tMemory_IsInitialized)func_Wwise_Memory_IsInitialized;
	//tMemory_Malign Wwise_Memory_Malign = (tMemory_Malign)func_Wwise_Memory_Malign;
	//tMemory_Malloc Wwise_Memory_Malloc = (tMemory_Malloc)func_Wwise_Memory_Malloc;
	//tMemory_ReleaseBlock Wwise_Memory_ReleaseBlock = (tMemory_ReleaseBlock)func_Wwise_Memory_ReleaseBlock;
	//tMemory_SetMonitoring Wwise_Memory_SetMonitoring = (tMemory_SetMonitoring)func_Wwise_Memory_SetMonitoring;
	//tMemory_SetPoolName Wwise_Memory_SetPoolName = (tMemory_SetPoolName)func_Wwise_Memory_SetPoolName;
	//tMemory_Term Wwise_Memory_Term = (tMemory_Term)func_Wwise_Memory_Term;

	//// Monitor
	//tMonitor_PostCode Wwise_Monitor_PostCode = (tMonitor_PostCode)func_Wwise_Monitor_PostCode;

	//// Motion Engine
	//tMotion_AddPlayerMotionDevice Wwise_Motion_AddPlayerMotionDevice = (tMotion_AddPlayerMotionDevice)func_Wwise_Motion_AddPlayerMotionDevice;
	//tMotion_RegisterMotionDevice Wwise_Motion_RegisterMotionDevice = (tMotion_RegisterMotionDevice)func_Wwise_Motion_RegisterMotionDevice;
	//tMotion_RemovePlayerMotionDevice Wwise_Motion_RemovePlayerMotionDevice = (tMotion_RemovePlayerMotionDevice)func_Wwise_Motion_RemovePlayerMotionDevice;
	//tMotion_SetPlayerListener Wwise_Motion_SetPlayerListener = (tMotion_SetPlayerListener)func_Wwise_Motion_SetPlayerListener;
	//tMotion_SetPlayerVolume Wwise_Motion_SetPlayerVolume = (tMotion_SetPlayerVolume)func_Wwise_Motion_SetPlayerVolume;

	//// Music Engine
	//tMusic_GetDefaultInitSettings Wwise_Music_GetDefaultInitSettings = (tMusic_GetDefaultInitSettings)func_Wwise_Music_GetDefaultInitSettings;
	//tMusic_GetPlayingSegmentInfo Wwise_Music_GetPlayingSegmentInfo = (tMusic_GetPlayingSegmentInfo)func_Wwise_Music_GetPlayingSegmentInfo;
	//tMusic_Init Wwise_Music_Init = (tMusic_Init)func_Wwise_Music_Init;
	//tMusic_Term Wwise_Music_Term = (tMusic_Term)func_Wwise_Music_Term;

	//// Sound Engine
	//tCancelBankCallbackCookie Wwise_Sound_CancelBankCallbackCookie = (tCancelBankCallbackCookie)func_Wwise_Sound_CancelBankCallbackCookie;
	//tCancelEventCallback Wwise_Sound_CancelEventCallback = (tCancelEventCallback)func_Wwise_Sound_CancelEventCallback;
	//tCancelEventCallbackCookie Wwise_Sound_CancelEventCallbackCookie = (tCancelEventCallbackCookie)func_Wwise_Sound_CancelEventCallbackCookie;
	//tClearBanks Wwise_Sound_ClearBanks = (tClearBanks)func_Wwise_Sound_ClearBanks;
	//tClearPreparedEvents Wwise_Sound_ClearPreparedEvents = (tClearPreparedEvents)func_Wwise_Sound_ClearPreparedEvents;
	//tDynamicDialogue_ResolveDialogueEvent_UniqueID Wwise_Sound_DynamicDialogue_ResolveDialogueEvent_UniqueID = (tDynamicDialogue_ResolveDialogueEvent_UniqueID)func_Wwise_Sound_DynamicDialogue_ResolveDialogueEvent_UniqueID;
	//tDynamicDialogue_ResolveDialogueEvent_Char Wwise_Sound_DynamicDialogue_ResolveDialogueEvent_Char = (tDynamicDialogue_ResolveDialogueEvent_Char)func_Wwise_Sound_DynamicDialogue_ResolveDialogueEvent_Char;
	//tDynamicSequence_Break Wwise_Sound_DynamicSequence_Break = (tDynamicSequence_Break)func_Wwise_Sound_DynamicSequence_Break;
	//tDynamicSequence_Close Wwise_Sound_DynamicSequence_Close = (tDynamicSequence_Close)func_Wwise_Sound_DynamicSequence_Close;
	//tDynamicSequence_LockPlaylist Wwise_Sound_DynamicSequence_LockPlaylist = (tDynamicSequence_LockPlaylist)func_Wwise_Sound_DynamicSequence_LockPlaylist;
	//tDynamicSequence_Open Wwise_Sound_DynamicSequence_Open = (tDynamicSequence_Open)func_Wwise_Sound_DynamicSequence_Open;
	//tDynamicSequence_Pause Wwise_Sound_DynamicSequence_Pause = (tDynamicSequence_Pause)func_Wwise_Sound_DynamicSequence_Pause;
	//tDynamicSequence_Play Wwise_Sound_DynamicSequence_Play = (tDynamicSequence_Play)func_Wwise_Sound_DynamicSequence_Play;
	//tDynamicSequence_Resume Wwise_Sound_DynamicSequence_Resume = (tDynamicSequence_Resume)func_Wwise_Sound_DynamicSequence_Resume;
	//tDynamicSequence_Stop Wwise_Sound_DynamicSequence_Stop = (tDynamicSequence_Stop)func_Wwise_Sound_DynamicSequence_Stop;
	//tDynamicSequence_UnlockPlaylist Wwise_Sound_DynamicSequence_UnlockPlaylist = (tDynamicSequence_UnlockPlaylist)func_Wwise_Sound_DynamicSequence_UnlockPlaylist;
	//tExecuteActionOnEvent_UniqueID Wwise_Sound_ExecuteActionOnEvent_UniqueID = (tExecuteActionOnEvent_UniqueID)func_Wwise_Sound_ExecuteActionOnEvent_UniqueID;
	//tExecuteActionOnEvent_Char Wwise_Sound_ExecuteActionOnEvent_Char = (tExecuteActionOnEvent_Char)func_Wwise_Sound_ExecuteActionOnEvent_Char;
	//tGetDefaultInitSettings Wwise_Sound_GetDefaultInitSettings = (tGetDefaultInitSettings)func_Wwise_Sound_GetDefaultInitSettings;
	//tGetDefaultPlatformInitSettings Wwise_Sound_GetDefaultPlatformInitSettings = (tGetDefaultPlatformInitSettings)func_Wwise_Sound_GetDefaultPlatformInitSettings;
	//tGetIDFromString Wwise_Sound_GetIDFromString = (tGetIDFromString)func_Wwise_Sound_GetIDFromString;
	//tGetPanningRule Wwise_Sound_GetPanningRule = (tGetPanningRule)func_Wwise_Sound_GetPanningRule;
	//tGetSourcePlayPosition Wwise_Sound_GetSourcePlayPosition = (tGetSourcePlayPosition)func_Wwise_Sound_GetSourcePlayPosition;
	//tGetSpeakerConfiguration Wwise_Sound_GetSpeakerConfiguration = (tGetSpeakerConfiguration)func_Wwise_Sound_GetSpeakerConfiguration;
	//tInit Wwise_Sound_Init = (tInit)func_Wwise_Sound_Init;
	//tIsInitialized Wwise_Sound_IsInitialized = (tIsInitialized)func_Wwise_Sound_IsInitialized;
	//tLoadBank_BankID_MemPoolID Wwise_Sound_LoadBank_BankID_MemPoolID = (tLoadBank_BankID_MemPoolID)func_Wwise_Sound_LoadBank_BankID_MemPoolID;
	//tLoadBank_Void_UInt32_BankID Wwise_Sound_LoadBank_Void_UInt32_BankID = (tLoadBank_Void_UInt32_BankID)func_Wwise_Sound_LoadBank_Void_UInt32_BankID;
	//tLoadBank_BankID_Callback Wwise_Sound_LoadBank_BankID_Callback = (tLoadBank_BankID_Callback)func_Wwise_Sound_LoadBank_BankID_Callback;
	//tLoadBank_Void_UInt32_Callback Wwise_Sound_LoadBank_Void_UInt32_Callback = (tLoadBank_Void_UInt32_Callback)func_Wwise_Sound_LoadBank_Void_UInt32_Callback;
	//tLoadBank_Char_MemPoolID Wwise_Sound_LoadBank_Char_MemPoolID = (tLoadBank_Char_MemPoolID)func_Wwise_Sound_LoadBank_Char_MemPoolID;
	//tLoadBank_Char_Callback Wwise_Sound_LoadBank_Char_Callback = (tLoadBank_Char_Callback)func_Wwise_Sound_LoadBank_Char_Callback;
	tPostEvent_Char Wwise_Sound_PostEvent_Char = (tPostEvent_Char)func_Wwise_Sound_PostEvent_Char;
	//tPostEvent_UniqueID Wwise_Sound_PostEvent_UniqueID = (tPostEvent_UniqueID)func_Wwise_Sound_PostEvent_UniqueID;
	//tPostTrigger_TriggerID Wwise_Sound_PostTrigger_TriggerID = (tPostTrigger_TriggerID)func_Wwise_Sound_PostTrigger_TriggerID;
	//tPostTrigger_Char Wwise_Sound_PostTrigger_Char = (tPostTrigger_Char)func_Wwise_Sound_PostTrigger_Char;
	//tPrepareBank_BankID_Callback Wwise_Sound_PrepareBank_BankID_Callback = (tPrepareBank_BankID_Callback)func_Wwise_Sound_PrepareBank_BankID_Callback;
	//tPrepareBank_BankID_BankContent Wwise_Sound_PrepareBank_BankID_BankContent = (tPrepareBank_BankID_BankContent)func_Wwise_Sound_PrepareBank_BankID_BankContent;
	//tPrepareBank_Char_Callback Wwise_Sound_PrepareBank_Char_Callback = (tPrepareBank_Char_Callback)func_Wwise_Sound_PrepareBank_Char_Callback;
	//tPrepareBank_Char_BankContent Wwise_Sound_PrepareBank_Char_BankContent = (tPrepareBank_Char_BankContent)func_Wwise_Sound_PrepareBank_Char_BankContent;
	//tPrepareEvent_EventID_UInt32 Wwise_Sound_PrepareEvent_EventID_UInt32 = (tPrepareEvent_EventID_UInt32)func_Wwise_Sound_PrepareEvent_EventID_UInt32;
	//tPrepareEvent_EventID_UInt32_Callback_Void Wwise_Sound_PrepareEvent_EventID_UInt32_Callback_Void = (tPrepareEvent_EventID_UInt32_Callback_Void)func_Wwise_Sound_PrepareEvent_EventID_UInt32_Callback_Void;
	//tPrepareEvent_Char_UInt32 Wwise_Sound_PrepareEvent_Char_UInt32 = (tPrepareEvent_Char_UInt32)func_Wwise_Sound_PrepareEvent_Char_UInt32;
	//tPrepareEvent_Char_UInt32_Callback_Void Wwise_Sound_PrepareEvent_Char_UInt32_Callback_Void = (tPrepareEvent_Char_UInt32_Callback_Void)func_Wwise_Sound_PrepareEvent_Char_UInt32_Callback_Void;
	//tPrepareGameSyncs_UInt32_UInt32_UInt32_Callback_Void Wwise_Sound_PrepareGameSyncs_UInt32_UInt32_UInt32_Callback_Void = (tPrepareGameSyncs_UInt32_UInt32_UInt32_Callback_Void)func_Wwise_Sound_PrepareGameSyncs_UInt32_UInt32_UInt32_Callback_Void;
	//tPrepareGameSyncs_UInt32_UInt32_UInt32 Wwise_Sound_PrepareGameSyncs_UInt32_UInt32_UInt32 = (tPrepareGameSyncs_UInt32_UInt32_UInt32)func_Wwise_Sound_PrepareGameSyncs_UInt32_UInt32_UInt32;
	//tPrepareGameSyncs_Char_Char_UInt32_Callback_Void Wwise_Sound_PrepareGameSyncs_Char_Char_UInt32_Callback_Void = (tPrepareGameSyncs_Char_Char_UInt32_Callback_Void)func_Wwise_Sound_PrepareGameSyncs_Char_Char_UInt32_Callback_Void;
	//tPrepareGameSyncs_Char_Char_UInt32 Wwise_Sound_PrepareGameSyncs_Char_Char_UInt32 = (tPrepareGameSyncs_Char_Char_UInt32)func_Wwise_Sound_PrepareGameSyncs_Char_Char_UInt32;
	//tQuery_GetActiveGameObjects Wwise_Sound_Query_GetActiveGameObjects = (tQuery_GetActiveGameObjects)func_Wwise_Sound_Query_GetActiveGameObjects;
	//tQuery_GetActiveListeners Wwise_Sound_Query_GetActiveListeners = (tQuery_GetActiveListeners)func_Wwise_Sound_Query_GetActiveListeners;
	//tQuery_GetCustomPropertyValue_Int32 Wwise_Sound_Query_GetCustomPropertyValue_Int32 = (tQuery_GetCustomPropertyValue_Int32)func_Wwise_Sound_Query_GetCustomPropertyValue_Int32;
	//tQuery_GetCustomPropertyValue_Real32 Wwise_Sound_Query_GetCustomPropertyValue_Real32 = (tQuery_GetCustomPropertyValue_Real32)func_Wwise_Sound_Query_GetCustomPropertyValue_Real32;
	//tQuery_GetEventIDFromPlayingID Wwise_Sound_Query_GetEventIDFromPlayingID = (tQuery_GetEventIDFromPlayingID)func_Wwise_Sound_Query_GetEventIDFromPlayingID;
	//tQuery_GetGameObjectAuxSendValues Wwise_Sound_Query_GetGameObjectAuxSendValues = (tQuery_GetGameObjectAuxSendValues)func_Wwise_Sound_Query_GetGameObjectAuxSendValues;
	//tQuery_GetGameObjectDryLevelValue Wwise_Sound_Query_GetGameObjectDryLevelValue = (tQuery_GetGameObjectDryLevelValue)func_Wwise_Sound_Query_GetGameObjectDryLevelValue;
	//tQuery_GetGameObjectFromPlayingID Wwise_Sound_Query_GetGameObjectFromPlayingID = (tQuery_GetGameObjectFromPlayingID)func_Wwise_Sound_Query_GetGameObjectFromPlayingID;
	//tQuery_GetIsGameObjectActive Wwise_Sound_Query_GetIsGameObjectActive = (tQuery_GetIsGameObjectActive)func_Wwise_Sound_Query_GetIsGameObjectActive;
	//tQuery_GetListenerPosition Wwise_Sound_Query_GetListenerPosition = (tQuery_GetListenerPosition)func_Wwise_Sound_Query_GetListenerPosition;
	//tQuery_GetMaxRadius_RadiusList Wwise_Sound_Query_GetMaxRadius_RadiusList = (tQuery_GetMaxRadius_RadiusList)func_Wwise_Sound_Query_GetMaxRadius_RadiusList;
	//tQuery_GetMaxRadius_GameObject Wwise_Sound_Query_GetMaxRadius_GameObject = (tQuery_GetMaxRadius_GameObject)func_Wwise_Sound_Query_GetMaxRadius_GameObject;
	//tQuery_GetObjectObstructionAndOcclusion Wwise_Sound_Query_GetObjectObstructionAndOcclusion = (tQuery_GetObjectObstructionAndOcclusion)func_Wwise_Sound_Query_GetObjectObstructionAndOcclusion;
	//tQuery_GetPlayingIDsFromGameObject Wwise_Sound_Query_GetPlayingIDsFromGameObject = (tQuery_GetPlayingIDsFromGameObject)func_Wwise_Sound_Query_GetPlayingIDsFromGameObject;
	//tQuery_GetPosition Wwise_Sound_Query_GetPosition = (tQuery_GetPosition)func_Wwise_Sound_Query_GetPosition;
	//tQuery_GetPositioningInfo Wwise_Sound_Query_GetPositioningInfo = (tQuery_GetPositioningInfo)func_Wwise_Sound_Query_GetPositioningInfo;
	tQuery_GetRTPCValue_Char Wwise_Sound_Query_GetRTPCValue_Char = (tQuery_GetRTPCValue_Char)func_Wwise_Sound_Query_GetRTPCValue_Char;
	//tQuery_GetRTPCValue_RTPCID Wwise_Sound_Query_GetRTPCValue_RTPCID = (tQuery_GetRTPCValue_RTPCID)func_Wwise_Sound_Query_GetRTPCValue_RTPCID;
	//tQuery_GetState_StateGroupID Wwise_Sound_Query_GetState_StateGroupID = (tQuery_GetState_StateGroupID)func_Wwise_Sound_Query_GetState_StateGroupID;
	//tQuery_GetState_Char Wwise_Sound_Query_GetState_Char = (tQuery_GetState_Char)func_Wwise_Sound_Query_GetState_Char;
	//tQuery_GetSwitch_SwitchGroupID Wwise_Sound_Query_GetSwitch_SwitchGroupID = (tQuery_GetSwitch_SwitchGroupID)func_Wwise_Sound_Query_GetSwitch_SwitchGroupID;
	//tQuery_GetSwitch_Char Wwise_Sound_Query_GetSwitch_Char = (tQuery_GetSwitch_Char)func_Wwise_Sound_Query_GetSwitch_Char;
	//tQuery_QueryAudioObjectIDs_UniqueID Wwise_Sound_Query_QueryAudioObjectIDs_UniqueID = (tQuery_QueryAudioObjectIDs_UniqueID)func_Wwise_Sound_Query_QueryAudioObjectIDs_UniqueID;
	tQuery_QueryAudioObjectIDs_Char Wwise_Sound_Query_QueryAudioObjectIDs_Char = (tQuery_QueryAudioObjectIDs_Char)func_Wwise_Sound_Query_QueryAudioObjectIDs_Char;
	//tRegisterCodec Wwise_Sound_RegisterCodec = (tRegisterCodec)func_Wwise_Sound_RegisterCodec;
	//tRegisterGlobalCallback Wwise_Sound_RegisterGlobalCallback = (tRegisterGlobalCallback)func_Wwise_Sound_RegisterGlobalCallback;
	//tRegisterPlugin Wwise_Sound_RegisterPlugin = (tRegisterPlugin)func_Wwise_Sound_RegisterPlugin;
	//tRenderAudio Wwise_Sound_RenderAudio = (tRenderAudio)func_Wwise_Sound_RenderAudio;
	//tSetActiveListeners Wwise_Sound_SetActiveListeners = (tSetActiveListeners)func_Wwise_Sound_SetActiveListeners;
	tSetActorMixerEffect Wwise_Sound_SetActorMixerEffect = (tSetActorMixerEffect)func_Wwise_Sound_SetActorMixerEffect;
	//tSetAttenuationScalingFactor Wwise_Sound_SetAttenuationScalingFactor = (tSetAttenuationScalingFactor)func_Wwise_Sound_SetAttenuationScalingFactor;
	//tSetBankLoadIOSettings Wwise_Sound_SetBankLoadIOSettings = (tSetBankLoadIOSettings)func_Wwise_Sound_SetBankLoadIOSettings;
	//tSetBusEffect_UniqueID Wwise_Sound_SetBusEffect_UniqueID = (tSetBusEffect_UniqueID)func_Wwise_Sound_SetBusEffect_UniqueID;
	//tSetBusEffect_Char Wwise_Sound_SetBusEffect_Char = (tSetBusEffect_Char)func_Wwise_Sound_SetBusEffect_Char;
	//tSetGameObjectAuxSendValues Wwise_Sound_SetGameObjectAuxSendValues = (tSetGameObjectAuxSendValues)func_Wwise_Sound_SetGameObjectAuxSendValues;
	//tSetGameObjectOutputBusVolume Wwise_Sound_SetGameObjectOutputBusVolume = (tSetGameObjectOutputBusVolume)func_Wwise_Sound_SetGameObjectOutputBusVolume;
	//tSetListenerPipeline Wwise_Sound_SetListenerPipeline = (tSetListenerPipeline)func_Wwise_Sound_SetListenerPipeline;
	//tSetListenerPosition Wwise_Sound_SetListenerPosition = (tSetListenerPosition)func_Wwise_Sound_SetListenerPosition;
	//tSetListenerScalingFactor Wwise_Sound_SetListenerScalingFactor = (tSetListenerScalingFactor)func_Wwise_Sound_SetListenerScalingFactor;
	//tSetListenerSpatialization Wwise_Sound_SetListenerSpatialization = (tSetListenerSpatialization)func_Wwise_Sound_SetListenerSpatialization;
	//tSetMaxNumVoicesLimit Wwise_Sound_SetMaxNumVoicesLimit = (tSetMaxNumVoicesLimit)func_Wwise_Sound_SetMaxNumVoicesLimit;
	//tSetMultiplePositions Wwise_Sound_SetMultiplePositions = (tSetMultiplePositions)func_Wwise_Sound_SetMultiplePositions;
	//tSetObjectObstructionAndOcclusion Wwise_Sound_SetObjectObstructionAndOcclusion = (tSetObjectObstructionAndOcclusion)func_Wwise_Sound_SetObjectObstructionAndOcclusion;
	//tSetPanningRule Wwise_Sound_SetPanningRule = (tSetPanningRule)func_Wwise_Sound_SetPanningRule;
	//tSetPosition Wwise_Sound_SetPosition = (tSetPosition)func_Wwise_Sound_SetPosition;
	//tSetRTPCValue_RTPCID Wwise_Sound_SetRTPCValue_RTPCID = (tSetRTPCValue_RTPCID)func_Wwise_Sound_SetRTPCValue_RTPCID;
	tSetRTPCValue_Char Wwise_Sound_SetRTPCValue_Char = (tSetRTPCValue_Char)func_Wwise_Sound_SetRTPCValue_Char;
	//tSetState_StateGroupID Wwise_Sound_SetState_StateGroupID = (tSetState_StateGroupID)func_Wwise_Sound_SetState_StateGroupID;
	//tSetState_Char Wwise_Sound_SetState_Char = (tSetState_Char)func_Wwise_Sound_SetState_Char;
	//tSetSwitch_SwitchGroupID Wwise_Sound_SetSwitch_SwitchGroupID = (tSetSwitch_SwitchGroupID)func_Wwise_Sound_SetSwitch_SwitchGroupID;
	//tSetSwitch_Char Wwise_Sound_SetSwitch_Char = (tSetSwitch_Char)func_Wwise_Sound_SetSwitch_Char;
	//tSetVolumeThreshold Wwise_Sound_SetVolumeThreshold = (tSetVolumeThreshold)func_Wwise_Sound_SetVolumeThreshold;
	//tStartOutputCapture Wwise_Sound_StartOutputCapture = (tStartOutputCapture)func_Wwise_Sound_StartOutputCapture;
	//tStopAll Wwise_Sound_StopAll = (tStopAll)func_Wwise_Sound_StopAll;
	//tStopOutputCapture Wwise_Sound_StopOutputCapture = (tStopOutputCapture)func_Wwise_Sound_StopOutputCapture;
	//tStopPlayingID Wwise_Sound_StopPlayingID = (tStopPlayingID)func_Wwise_Sound_StopPlayingID;
	//tTerm Wwise_Sound_Term = (tTerm)func_Wwise_Sound_Term;
	//tUnloadBank_BankID_MemPoolID Wwise_Sound_UnloadBank_BankID_MemPoolID = (tUnloadBank_BankID_MemPoolID)func_Wwise_Sound_UnloadBank_BankID_MemPoolID;
	//tUnloadBank_BankID_Callback Wwise_Sound_UnloadBank_BankID_Callback = (tUnloadBank_BankID_Callback)func_Wwise_Sound_UnloadBank_BankID_Callback;
	//tUnloadBank_Char_MemPoolID Wwise_Sound_UnloadBank_Char_MemPoolID = (tUnloadBank_Char_MemPoolID)func_Wwise_Sound_UnloadBank_Char_MemPoolID;
	//tUnloadBank_Char_Callback Wwise_Sound_UnloadBank_Char_Callback = (tUnloadBank_Char_Callback)func_Wwise_Sound_UnloadBank_Char_Callback;
	//tUnregisterAllGameObj Wwise_Sound_UnregisterAllGameObj = (tUnregisterAllGameObj)func_Wwise_Sound_UnregisterAllGameObj;
	//tUnregisterGameObj Wwise_Sound_UnregisterGameObj = (tUnregisterGameObj)func_Wwise_Sound_UnregisterGameObj;
	//tUnregisterGlobalCallback Wwise_Sound_UnregisterGlobalCallback = (tUnregisterGlobalCallback)func_Wwise_Sound_UnregisterGlobalCallback;

	////Custom Wwise_Sound Functions

	//tCloneActorMixerEffect Wwise_Sound_CloneActorMixerEffect = (tCloneActorMixerEffect)func_Wwise_Sound_CloneActorMixerEffect;
	//tCloneBusEffect Wwise_Sound_CloneBusEffect = (tCloneBusEffect)func_Wwise_Sound_CloneBusEffect;
	//tLoadBankUnique Wwise_Sound_LoadBankUnique = (tLoadBankUnique)func_Wwise_Sound_LoadBankUnique;
	//tPlaySourcePlugin Wwise_Sound_PlaySourcePlugin = (tPlaySourcePlugin)func_Wwise_Sound_PlaySourcePlugin;
	//tRegisterGameObj Wwise_Sound_RegisterGameObj = (tRegisterGameObj)func_Wwise_Sound_RegisterGameObj;
	//tResetRTPCValue_RTPCID Wwise_Sound_ResetRTPCValue_RTPCID = (tResetRTPCValue_RTPCID)func_Wwise_Sound_ResetRTPCValue_RTPCID;
	//tResetRTPCValue_Char Wwise_Sound_ResetRTPCValue_Char = (tResetRTPCValue_Char)func_Wwise_Sound_ResetRTPCValue_Char;
	//tSeekOnEvent_UniqueID_Int32 Wwise_Sound_SeekOnEvent_UniqueID_Int32 = (tSeekOnEvent_UniqueID_Int32)func_Wwise_Sound_SeekOnEvent_UniqueID_Int32;
	//tSeekOnEvent_UniqueID_Float Wwise_Sound_SeekOnEvent_UniqueID_Float = (tSeekOnEvent_UniqueID_Float)func_Wwise_Sound_SeekOnEvent_UniqueID_Float;
	tSeekOnEvent_Char_Int32 Wwise_Sound_SeekOnEvent_Char_Int32 = (tSeekOnEvent_Char_Int32)func_Wwise_Sound_SeekOnEvent_Char_Int32;
	//tSeekOnEvent_Char_Float Wwise_Sound_SeekOnEvent_Char_Float = (tSeekOnEvent_Char_Float)func_Wwise_Sound_SeekOnEvent_Char_Float;
	//tSetEffectParam Wwise_Sound_SetEffectParam = (tSetEffectParam)func_Wwise_Sound_SetEffectParam;
	//tSetPositionInternal Wwise_Sound_SetPositionInternal = (tSetPositionInternal)func_Wwise_Sound_SetPositionInternal;
	//tStopSourcePlugin Wwise_Sound_StopSourcePlugin = (tStopSourcePlugin)func_Wwise_Sound_StopSourcePlugin;
	//tUnloadBankUnique Wwise_Sound_UnloadBankUnique = (tUnloadBankUnique)func_Wwise_Sound_UnloadBankUnique;

	//// Rocksmith Function Hijack

	//tRegisterAllPlugins Rocksmith_RegisterAllPlugins = (tRegisterAllPlugins)func_Rocksmith_RegisterAllPlugins;
	//tSetAudioInputCallbacks Rocksmith_SetAudioInputCallbacks = (tSetAudioInputCallbacks)func_Rocksmith_SetAudioInputCallbacks;

}
/* 
	// Plugin Registration

	std::cout << "AudioKinetic Plugins" << std::endl;

	std::cout << "Source Plugins" << std::endl;

	std::cout << WwiseVariables::Wwise_Sound_RegisterPlugin((AkPluginType)2, 0, 100, (AkCreatePluginCallback*)0x01f55909, (AkCreateParamCallback*)0x01f5552d) << std::endl; // Sine https://www.audiokinetic.com/library/2015.1.9_5624/?source=SDK&id=_ak_sine_source_factory_8h_ab36cdff56a4114c8dc7bd778f3c458a6.html#ab36cdff56a4114c8dc7bd778f3c458a6
	std::cout << WwiseVariables::Wwise_Sound_RegisterPlugin((AkPluginType)2, 0, 101, (AkCreatePluginCallback*)0x01f552ed, (AkCreateParamCallback*)0x01f552cd) << std::endl; // Silence https://www.audiokinetic.com/library/2015.1.9_5624/?source=SDK&id=_ak_silence_source_factory_8h_abe4e09287a6a4625ee1f318cbe284cbe.html#abe4e09287a6a4625ee1f318cbe284cbe
	std::cout << WwiseVariables::Wwise_Sound_RegisterPlugin((AkPluginType)2, 0, 102, (AkCreatePluginCallback*)0x01fc44d7, (AkCreateParamCallback*)0x01fc3941) << std::endl; // Tone https://www.audiokinetic.com/library/2015.1.9_5624/?source=SDK&id=_ak_tone_source_factory_8h_a556f52a9a328dee0693c7898220b987d.html#a556f52a9a328dee0693c7898220b987d
	std::cout << WwiseVariables::Wwise_Sound_RegisterPlugin((AkPluginType)2, 0, 200, *(AkCreatePluginCallback*)0x01f11435, *(AkCreateParamCallback*)0x01f11535) << std::endl; // Audio Input https://www.audiokinetic.com/library/2015.1.9_5624/?source=SDK&id=_ak_audio_input_source_factory_8h_a525cc107623ec9df67be8be92a2bd5db.html#a525cc107623ec9df67be8be92a2bd5db

	std::cout << "Effect Plugins" << std::endl;

	std::cout << WwiseVariables::Wwise_Sound_RegisterPlugin((AkPluginType)3, 0, 105, (AkCreatePluginCallback*)0x01f49cd6, (AkCreateParamCallback*)0x01f48f37) << std::endl; // Parametric EQ https://www.audiokinetic.com/library/2015.1.9_5624/?source=SDK&id=_ak_parametric_e_q_f_x_factory_8h_ab3c24f987d4eea8d2054252da4a2b4e4.html#ab3c24f987d4eea8d2054252da4a2b4e4
	std::cout << WwiseVariables::Wwise_Sound_RegisterPlugin((AkPluginType)3, 0, 106, (AkCreatePluginCallback*)0x01f184fa, (AkCreateParamCallback*)0x01f182f6) << std::endl; // Delay https://www.audiokinetic.com/library/2015.1.9_5624/?source=SDK&id=_ak_delay_f_x_factory_8h_a945fa489838c6c5ff34ba144fd8ee5a7.html#a945fa489838c6c5ff34ba144fd8ee5a7
	std::cout << WwiseVariables::Wwise_Sound_RegisterPlugin((AkPluginType)3, 0, 108, (AkCreatePluginCallback*)0x01f125a4, (AkCreateParamCallback*)0x01f117e5) << std::endl; // Compressor https://www.audiokinetic.com/library/2015.1.9_5624/?source=SDK&id=_ak_compressor_f_x_factory_8h_a8a1aefc973bf36d4c3645a54b4296787.html#a8a1aefc973bf36d4c3645a54b4296787
	std::cout << WwiseVariables::Wwise_Sound_RegisterPlugin((AkPluginType)3, 0, 109, (AkCreatePluginCallback*)0x01f19c61, (AkCreateParamCallback*)0x01f18e6a) << std::endl; // Expander https://www.audiokinetic.com/library/2015.1.9_5624/?source=SDK&id=_ak_expander_f_x_factory_8h_af1ab755771ef101eb2d197870b6b5559.html#af1ab755771ef101eb2d197870b6b5559
	std::cout << WwiseVariables::Wwise_Sound_RegisterPlugin((AkPluginType)3, 0, 110, (AkCreatePluginCallback*)0x01f4bb16, (AkCreateParamCallback*)0x01f4a006) << std::endl; // Peak Limiter https://www.audiokinetic.com/library/2015.1.9_5624/?source=SDK&id=_ak_peak_limiter_f_x_factory_8h_a2fff1d80430c06021f9a9f8c33a82374.html#a2fff1d80430c06021f9a9f8c33a82374
	std::cout << WwiseVariables::Wwise_Sound_RegisterPlugin((AkPluginType)3, 0, 115, (AkCreatePluginCallback*)0x01f32348, (AkCreateParamCallback*)0x01f2727d) << std::endl; // Matrix Reverb https://www.audiokinetic.com/library/2015.1.9_5624/?source=SDK&id=_ak_matrix_reverb_f_x_factory_8h_aa42114eb41275a4a54e11b3481728a85.html#aa42114eb41275a4a54e11b3481728a85
	std::cout << WwiseVariables::Wwise_Sound_RegisterPlugin((AkPluginType)3, 0, 118, (AkCreatePluginCallback*)0x01f516ef, (AkCreateParamCallback*)0x01f4d8ff) << std::endl; // Roomverb https://www.audiokinetic.com/library/2015.1.9_5624/?source=SDK&id=_ak_room_verb_f_x_factory_8h_a1bdaea8632abbc2caa1c475b39e4f845.html#a1bdaea8632abbc2caa1c475b39e4f845
	std::cout << WwiseVariables::Wwise_Sound_RegisterPlugin((AkPluginType)3, 0, 125, (AkCreatePluginCallback*)0x01f1ad5e, (AkCreateParamCallback*)0x01f1a11d) << std::endl; // Flanger https://www.audiokinetic.com/library/2015.1.9_5624/?source=SDK&id=_ak_flanger_f_x_factory_8h_a90cda97c241c27d9a060aa7f184a905e.html#a90cda97c241c27d9a060aa7f184a905e
	std::cout << WwiseVariables::Wwise_Sound_RegisterPlugin((AkPluginType)3, 0, 126, (AkCreatePluginCallback*)0x01f1d8fe, (AkCreateParamCallback*)0x01f1d154) << std::endl; // Guitar Distortion https://www.audiokinetic.com/library/2015.1.9_5624/?source=SDK&id=_ak_guitar_distortion_f_x_factory_8h_ac982da86fbbeb5675e781f5290e94545.html#ac982da86fbbeb5675e781f5290e94545
	std::cout << WwiseVariables::Wwise_Sound_RegisterPlugin((AkPluginType)3, 0, 127, (AkCreatePluginCallback*)0x01f13d1f, (AkCreateParamCallback*)0x01f12ad8) << std::endl; // Convolution Reverb https://www.audiokinetic.com/library/2015.1.9_5624/?source=SDK&id=_ak_convolution_reverb_f_x_factory_8h_acbefb0c6db1e3837e8d7816602eaf2d8.html#acbefb0c6db1e3837e8d7816602eaf2d8 
	std::cout << WwiseVariables::Wwise_Sound_RegisterPlugin((AkPluginType)3, 0, 129, (AkCreatePluginCallback*)0x01f33e23, (AkCreateParamCallback*)0x01f334fd) << std::endl; // Meter https://www.audiokinetic.com/library/2015.1.9_5624/?source=SDK&id=_ak_meter_f_x_factory_8h_a7ed0c7ff5c97a9b0b757f1d0b6ddaa7a.html#a7ed0c7ff5c97a9b0b757f1d0b6ddaa7a
	std::cout << WwiseVariables::Wwise_Sound_RegisterPlugin((AkPluginType)3, 0, 130, (AkCreatePluginCallback*)0x01fc35b1, (AkCreateParamCallback*)0x01fc2ce3) << std::endl; // Time Stretch https://www.audiokinetic.com/library/2015.1.9_5624/?source=SDK&id=_ak_time_stretch_f_x_factory_8h_a50a41e0d1788223367ae2c50bca929dc.html#a50a41e0d1788223367ae2c50bca929dc
	std::cout << WwiseVariables::Wwise_Sound_RegisterPlugin((AkPluginType)3, 0, 131, (AkCreatePluginCallback*)0x01fc6bc4, (AkCreateParamCallback*)0x01fc66c2) << std::endl; // Tremolo https://www.audiokinetic.com/library/2015.1.9_5624/?source=SDK&id=_ak_tremolo_f_x_factory_8h_a25a1a5e47e5aa0071cac9f2ce8b0ffc4.html#a25a1a5e47e5aa0071cac9f2ce8b0ffc4
	std::cout << WwiseVariables::Wwise_Sound_RegisterPlugin((AkPluginType)3, 0, 132, (AkCreatePluginCallback*)0x01f4c583, (AkCreateParamCallback*)0x01f4bef8) << std::endl; // Recorder https://www.audiokinetic.com/library/2015.1.9_5624/?source=SDK&id=_ak_recorder_f_x_factory_8h_abf3480b8d1398f8fe4ed546159790807.html
	std::cout << WwiseVariables::Wwise_Sound_RegisterPlugin((AkPluginType)3, 0, 135, (AkCreatePluginCallback*)0x01fba060, (AkCreateParamCallback*)0x01fb9a21) << std::endl; // Stereo Delay https://www.audiokinetic.com/library/2015.1.9_5624/?source=SDK&id=_ak_stereo_delay_f_x_factory_8h_ac6d5f65f9f7986c072de8d170c19ba9a.html#ac6d5f65f9f7986c072de8d170c19ba9a
	std::cout << WwiseVariables::Wwise_Sound_RegisterPlugin((AkPluginType)3, 0, 136, (AkCreatePluginCallback*)0x01f20d74, (AkCreateParamCallback*)0x01f2052c) << std::endl; // Pitch Shifter https://www.audiokinetic.com/library/2015.1.9_5624/?source=SDK&id=_ak_pitch_shifter_f_x_factory_8h_af59100e964c89255422d5d7d1f32b220.html#af59100e964c89255422d5d7d1f32b220
	std::cout << WwiseVariables::Wwise_Sound_RegisterPlugin((AkPluginType)3, 0, 138, (AkCreatePluginCallback*)0x01f232f2, (AkCreateParamCallback*)0x01f22929) << std::endl; // Harmonizer https://www.audiokinetic.com/library/2015.1.9_5624/?source=SDK&id=_ak_harmonizer_f_x_factory_8h_a659f62ff7931a0745deb532a4967092a.html#a659f62ff7931a0745deb532a4967092a

	std::cout << WwiseVariables::Wwise_Sound_RegisterPlugin((AkPluginType)3, 255, 110, (AkCreatePluginCallback*)0x01febc77, (AkCreateParamCallback*)0x01feae79) << std::endl; // Custom Plugin? Non-registered Audio Kinetic Comapany ID

	std::cout << "iZotope Plugins (Tones)" << std::endl;

	std::cout << WwiseVariables::Wwise_Sound_RegisterPlugin((AkPluginType)3, 259, 4, (AkCreatePluginCallback*)0x01fcfa19, (AkCreateParamCallback*)0x01fcf5d1) << std::endl; // iZotope Trash Delay https://www.audiokinetic.com/library/2015.1.9_5624/?source=SDK&id=i_z_trash_delay_f_x_factory_8h_a03ced9816a8acacc6b67d2e6406e0e67.html#a03ced9816a8acacc6b67d2e6406e0e67
	std::cout << WwiseVariables::Wwise_Sound_RegisterPlugin((AkPluginType)3, 259, 5, (AkCreatePluginCallback*)0x01fd6921, (AkCreateParamCallback*)0x01fd6501) << std::endl; // iZotope Trash Dynamics https://www.audiokinetic.com/library/2015.1.9_5624/?source=SDK&id=i_z_trash_dynamics_f_x_factory_8h_a3d9e8fffaf23fee2a3afaa43753f9bf7.html#a3d9e8fffaf23fee2a3afaa43753f9bf7
	std::cout << WwiseVariables::Wwise_Sound_RegisterPlugin((AkPluginType)3, 259, 6, (AkCreatePluginCallback*)0x01fd95b0, (AkCreateParamCallback*)0x01fd8e0c) << std::endl; // iZotope Trash Filters https://www.audiokinetic.com/library/2015.1.9_5624/?source=SDK&id=i_z_trash_filters_f_x_factory_8h_a97114961181f3b4dace0ea4c9e73f041.html#a97114961181f3b4dace0ea4c9e73f041
	std::cout << WwiseVariables::Wwise_Sound_RegisterPlugin((AkPluginType)3, 259, 9, (AkCreatePluginCallback*)0x01fe22ba, (AkCreateParamCallback*)0x01fe1a11) << std::endl; // iZotope Trash Multiband Distortion https://www.audiokinetic.com/library/2015.1.9_5624/?source=SDK&id=i_z_trash_multiband_distortion_f_x_factory_8h_a270360b0053eddb74cafb461763ff2cb.html#a270360b0053eddb74cafb461763ff2cb
	
	*/

#ifdef _WWISE_LOGS
namespace WwiseLogging {

	void __stdcall log_PostEvent_Name(char* eventName, int gameObject) {
		std::cout << "(Wwise) PostEvent: " << eventName << " on game object 0x" << std::hex << gameObject << std::endl;
	}

	void __declspec(naked) hook_log_PostEvent() {
		__asm {
			push ESI	// Save current state of ESI to the stack.
			push EAX	// Save current state of EAX to the stack.
			push ESP	// Save current state of ESP to the stack.

			push[EBP + 0xC]			// Wwise Object
			push[EBP + 0x8]			// Wwise Event name.
			call log_PostEvent_Name	// Log the event name

			pop ESP	// Get old ESP
			pop EAX	// Get old EAX
			pop ESI // Get old ESI

			mov ESI, EAX  // Assembly we removed to place this hook
			add ESP, 0x20 // Assembly we removed to place this hook
			jmp Offsets::ptr_Wwise_Log_PostEventHookJmpBck  // Jump back to the original code.
		}
	}

	void Setup_log_PostEvent() {
		MemUtil::PlaceHook((void*)Offsets::ptr_Wwise_Log_PostEventHook, hook_log_PostEvent, 5);
	}


	void __stdcall log_SetRTPCValue(char* rtpcName, float rtpcValue, int gameObject) {
		if (!strcmp(rtpcName, "Player_Success") ||
			!strcmp(rtpcName, "Portal_Size") ||
			!strcmp(rtpcName, "LoftAmb_CamPosition") ||
			!strcmp(rtpcName, "AmbRadio_OnOff_Return") ||
			!strcmp(rtpcName, "Average_Song_Difficulty") ||
			!strcmp(rtpcName, "Lowest_Phrase_Difficulty_Level") ||
			!strcmp(rtpcName, "PortalClose_TailLP_Return") ||
			!strcmp(rtpcName, "PortalClose_TailRamping_Return") ||
			!strcmp(rtpcName, "P1_Instrument_Volume") ||
			!strcmp(rtpcName, "GateTime") ||
			!strcmp(rtpcName, "P1_Streak_Hit_Count") ||
			!strcmp(rtpcName, "P1_Streak_Miss") ||
			!strcmp(rtpcName, "P1_Streak_Note_Count") ||
			!strcmp(rtpcName, "P1_Streak_Chord_Count") ||
			!strcmp(rtpcName, "P1_Streak_Phrase_Count") ||
			!strcmp(rtpcName, "P2_Instrument_Volume") ||
			!strcmp(rtpcName, "MusicRamping")
			)
			return; // To prevent spamming of the log. If you need to look at these, remove the if-statement.

		std::cout << "(Wwise) SetRTPCValue: " << rtpcName << " to " << rtpcValue << " on game object 0x" << std::hex << gameObject << std::endl;
	}

	void __declspec(naked) hook_log_SetRTPCValue() {
		__asm {
			push ESP // Save current state of ESP to the stack.
			push EAX // Save current state of EAX to the stack.

			push [EBP+0x10] // RTPC Object
			push [EBP+0xC]	// RTPC Value
			push [EBP+0x8]	// RTPC Name
			call log_SetRTPCValue

			pop EAX // Get old EAX
			pop ESP // Get old ESP

			add ESP, 0x4 // Assembly we removed to place this hook
			test EAX,EAX // Assembly we removed to place this hook
			jmp Offsets::ptr_Wwise_Log_SetRTPCValueHookJmpBck // Jump back to the original code.
		}
	}

	void Setup_log_SetRTPCValue() {
		MemUtil::PlaceHook((void*)Offsets::ptr_Wwise_Log_SetRTPCValueHook, hook_log_SetRTPCValue, 5);
	}
}
#endif