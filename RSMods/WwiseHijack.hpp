#pragma once
#include <cmath>
#include <map>
#include <vector>
#include <iostream>
#include <list>

#include "windows.h"

#include "Offsets.hpp"

/*
 Get documentation here: https://www.audiokinetic.com/library/2015.1.9_5624/?source=SDK&id=namespace_a_k_1_1_sound_engine.html

 Note: Rocksmith is made with Wwise 2013, not Wwise 2015. This is the earliest version with good documentation.
 This means that some functions are in that documentation that aren't in the 2013 version, and vise-versa.
 To tell what functions we have access to, go to the functions part of this document as I layed everything out

 Documentation by: Audiokinetic (makers of Wwise)
 Types add by: LovroM8
 Functions added by: Ffio
*/

/*------------------Dependancies---------------------------------*/

typedef unsigned char		AkUInt8;			///< Unsigned 8-bit integer
typedef unsigned short		AkUInt16;			///< Unsigned 16-bit integer
typedef unsigned long		AkUInt32;			///< Unsigned 32-bit integer
typedef char			AkInt8;					///< Signed 8-bit integer
typedef short			AkInt16;				///< Signed 16-bit integer
typedef long   			AkInt32;				///< Signed 32-bit integer
typedef int 		AkInt;					///< Signed integer
typedef int AkIntPtr;						///< Integer type for pointers
typedef  unsigned int AkUIntPtr;			///< Integer (unsigned) type for pointers
typedef float			AkReal32;				///< 32-bit floating point
typedef double          AkReal64;				///< 64-bit floating point

typedef AkUInt32		AkUniqueID;			 		///< Unique 32-bit ID
typedef AkUInt32		AkStateID;			 		///< State ID
typedef AkUInt32		AkStateGroupID;		 		///< State group ID
typedef AkUInt32		AkPlayingID;		 		///< Playing ID
typedef	AkInt32			AkTimeMs;			 		///< Time in ms
typedef AkReal32		AkPitchValue;		 		///< Pitch value
typedef AkReal32		AkVolumeValue;		 		///< Volume value( also apply to LFE )
typedef AkUIntPtr		AkGameObjectID;		 		///< Game object ID
typedef AkReal32		AkLPFType;			 		///< Low-pass filter type
typedef AkInt32			AkMemPoolId;		 		///< Memory pool ID
typedef AkUInt32		AkPluginID;			 		///< Source or effect plug-in ID
typedef AkUInt32		AkCodecID;			 		///< Codec plug-in ID
typedef AkUInt32		AkEnvID;			 		///< Environmental ID
typedef AkInt16			AkPluginParamID;	 		///< Source or effect plug-in parameter ID
typedef AkInt8			AkPriority;			 		///< Priority
typedef AkUInt16        AkDataCompID;		 		///< Data compression format ID
typedef AkUInt16        AkDataTypeID;		 		///< Data sample type ID
typedef AkUInt8			AkDataInterleaveID;	 		///< Data interleaved state ID
typedef AkUInt32        AkSwitchGroupID;	 		///< Switch group ID
typedef AkUInt32        AkSwitchStateID;	 		///< Switch ID
typedef AkUInt32        AkRtpcID;			 		///< Real time parameter control ID
typedef AkReal32        AkRtpcValue;		 		///< Real time parameter control value
typedef AkUInt32        AkBankID;			 		///< Run time bank ID
typedef AkUInt32        AkFileID;			 		///< Integer-type file identifier
typedef AkUInt32        AkDeviceID;			 		///< I/O device ID
typedef AkUInt32		AkTriggerID;		 		///< Trigger ID
typedef AkUInt32		AkArgumentValueID;			///< Argument value ID
typedef AkUInt32		AkChannelMask;				///< Channel mask (similar to WAVE_FORMAT_EXTENSIBLE). Bit values are defined in AkCommonDefs.h.

static const AkGameObjectID	AK_INVALID_GAME_OBJECT = (AkGameObjectID)-1;	///< Invalid game object (may also mean all game objects)
static const AkUniqueID AK_INVALID_UNIQUE_ID = (AkUniqueID)0;
static const AkUniqueID AK_ID_Default_Time_Stretch = 0xB3745FC2;

enum AKRESULT
{
	AK_NotImplemented = 0,	///< This feature is not implemented.
	AK_Success = 1,	///< The operation was successful.
	AK_Fail = 2,	///< The operation failed.
	AK_PartialSuccess = 3,	///< The operation succeeded partially.
	AK_NotCompatible = 4,	///< Incompatible formats
	AK_AlreadyConnected = 5,	///< The stream is already connected to another node.
	AK_NameNotSet = 6,	///< Trying to open a file when its name was not set
	AK_InvalidFile = 7,	///< An unexpected value causes the file to be invalid.
	AK_CorruptedFile = 8,	///< The file is missing some exprected data.
	AK_MaxReached = 9,	///< The maximum was reached.
	AK_InputsInUsed = 10,	///< Inputs are currently used.
	AK_OutputsInUsed = 11,	///< Outputs are currently used.
	AK_InvalidName = 12,	///< The name is invalid.
	AK_NameAlreadyInUse = 13,	///< The name is already in use.
	AK_InvalidID = 14,	///< The ID is invalid.
	AK_IDNotFound = 15,	///< The ID was not found.
	AK_InvalidInstanceID = 16,	///< The InstanceID is invalid.
	AK_NoMoreData = 17,	///< No more data is available from the source.
	AK_NoSourceAvailable = 18,	///< There is no child (source) associated with the node.
	AK_StateGroupAlreadyExists = 19,	///< The StateGroup already exists.
	AK_InvalidStateGroup = 20,	///< The StateGroup is not a valid channel.
	AK_ChildAlreadyHasAParent = 21,	///< The child already has a parent.
	AK_InvalidLanguage = 22,	///< The language is invalid (applies to the Low-Level I/O).
	AK_CannotAddItseflAsAChild = 23,	///< It is not possible to add itself as its own child.
	AK_TransitionNotFound = 24,	///< The transition is not in the list.
	AK_TransitionNotStartable = 25,	///< Start allowed in the Running and Done states.
	AK_TransitionNotRemovable = 26,	///< Must not be in the Computing state.
	AK_UsersListFull = 27,	///< No one can be added any more, could be AK_MaxReached.
	AK_UserAlreadyInList = 28,	///< This user is already there.
	AK_UserNotInList = 29,	///< This user is not there.
	AK_NoTransitionPoint = 30,	///< Not in use.
	AK_InvalidParameter = 31,	///< Something is not within bounds.
	AK_ParameterAdjusted = 32,	///< Something was not within bounds and was relocated to the nearest OK value.
	AK_IsA3DSound = 33,	///< The sound has 3D parameters.
	AK_NotA3DSound = 34,	///< The sound does not have 3D parameters.
	AK_ElementAlreadyInList = 35,	///< The item could not be added because it was already in the list.
	AK_PathNotFound = 36,	///< This path is not known.
	AK_PathNoVertices = 37,	///< Stuff in vertices before trying to start it
	AK_PathNotRunning = 38,	///< Only a running path can be paused.
	AK_PathNotPaused = 39,	///< Only a paused path can be resumed.
	AK_PathNodeAlreadyInList = 40,	///< This path is already there.
	AK_PathNodeNotInList = 41,	///< This path is not there.
	AK_VoiceNotFound = 42,	///< Unknown in our voices list
	AK_DataNeeded = 43,	///< The consumer needs more.
	AK_NoDataNeeded = 44,	///< The consumer does not need more.
	AK_DataReady = 45,	///< The provider has available data.
	AK_NoDataReady = 46,	///< The provider does not have available data.
	AK_NoMoreSlotAvailable = 47,	///< Not enough space to load bank.
	AK_SlotNotFound = 48,	///< Bank error.
	AK_ProcessingOnly = 49,	///< No need to fetch new data.
	AK_MemoryLeak = 50,	///< Debug mode only.
	AK_CorruptedBlockList = 51,	///< The memory manager's block list has been corrupted.
	AK_InsufficientMemory = 52,	///< Memory error.
	AK_Cancelled = 53,	///< The requested action was cancelled (not an error).
	AK_UnknownBankID = 54,	///< Trying to load a bank using an ID which is not defined.
	AK_IsProcessing = 55,   ///< Asynchronous pipeline component is processing.
	AK_BankReadError = 56,	///< Error while reading a bank.
	AK_InvalidSwitchType = 57,	///< Invalid switch type (used with the switch container)
	AK_VoiceDone = 58,	///< Internal use only.
	AK_UnknownEnvironment = 59,	///< This environment is not defined.
	AK_EnvironmentInUse = 60,	///< This environment is used by an object.
	AK_UnknownObject = 61,	///< This object is not defined.
	AK_NoConversionNeeded = 62,	///< Audio data already in target format, no conversion to perform.
	AK_FormatNotReady = 63,   ///< Source format not known yet.
	AK_WrongBankVersion = 64,	///< The bank version is not compatible with the current bank reader.
	AK_DataReadyNoProcess = 65,	///< The provider has some data but does not process it (virtual voices).
	AK_FileNotFound = 66,   ///< File not found.
	AK_DeviceNotReady = 67,   ///< IO device not ready (may be because the tray is open)
	AK_CouldNotCreateSecBuffer = 68,   ///< The direct sound secondary buffer creation failed.
	AK_BankAlreadyLoaded = 69,	///< The bank load failed because the bank is already loaded.
	AK_RenderedFX = 71,	///< The effect on the node is rendered.
	AK_ProcessNeeded = 72,	///< A routine needs to be executed on some CPU.
	AK_ProcessDone = 73,	///< The executed routine has finished its execution.
	AK_MemManagerNotInitialized = 74,	///< The memory manager should have been initialized at this point.
	AK_StreamMgrNotInitialized = 75,	///< The stream manager should have been initialized at this point.
	AK_SSEInstructionsNotSupported = 76,///< The machine does not support SSE instructions (required on PC).
	AK_Busy = 77,	///< The system is busy and could not process the request.
	AK_UnsupportedChannelConfig = 78,	///< Channel configuration is not supported in the current execution context.
	AK_PluginMediaNotAvailable = 79,	///< Plugin media is not available for effect.
};


/// Curve interpolation types
enum AkCurveInterpolation
{
	//DONT GO BEYOND 15! (see below for details)
	//Curves from 0 to LastFadeCurve NEED TO BE A MIRROR IMAGE AROUND LINEAR (eg. Log3 is the inverse of Exp3)
	AkCurveInterpolation_Log3 = 0, ///< Log3
	AkCurveInterpolation_Sine = 1, ///< Sine
	AkCurveInterpolation_Log1 = 2, ///< Log1
	AkCurveInterpolation_InvSCurve = 3, ///< Inversed S Curve
	AkCurveInterpolation_Linear = 4, ///< Linear (Default)
	AkCurveInterpolation_SCurve = 5, ///< S Curve
	AkCurveInterpolation_Exp1 = 6, ///< Exp1
	AkCurveInterpolation_SineRecip = 7, ///< Reciprocal of sine curve
	AkCurveInterpolation_Exp3 = 8, ///< Exp3
	AkCurveInterpolation_LastFadeCurve = 8, ///< Update this value to reflect last curve available for fades
	AkCurveInterpolation_Constant = 9  ///< Constant ( not valid for fading values )
//DONT GO BEYOND 15! The value is stored on 5 bits,
//but we can use only 4 bits for the actual values, keeping
//the 5th bit at 0 to void problems when the value is
//expanded to 32 bits.
};

enum RTPCValue_type
{
	RTPCValue_Default,      ///< The value is the Default RTPC.
	RTPCValue_Global,       ///< The value is the Global RTPC.
	RTPCValue_GameObject,   ///< The value is the game object specific RTPC.
	RTPCValue_PlayingID,    ///< The value is the playing ID specific RTPC.
	RTPCValue_Unavailable   ///< The value is not available for the RTPC specified.
};

enum AkCallbackType
{
	AK_EndOfEvent = 0x0001,
	AK_EndOfDynamicSequenceItem = 0x0002,
	AK_Marker = 0x0004,
	AK_Duration = 0x0008,

	AK_SpeakerVolumeMatrix = 0x0010,

	AK_Starvation = 0x0020,

	AK_MusicPlaylistSelect = 0x0040,
	AK_MusicPlayStarted = 0x0080,

	AK_MusicSyncBeat = 0x0100,
	AK_MusicSyncBar = 0x0200,
	AK_MusicSyncEntry = 0x0400,
	AK_MusicSyncExit = 0x0800,
	AK_MusicSyncGrid = 0x1000,
	AK_MusicSyncUserCue = 0x2000,
	AK_MusicSyncPoint = 0x4000,
	AK_MusicSyncAll = 0x7f00,

	AK_MidiEvent = 0x10000,

	AK_CallbackBits = 0xfffff,

	// Not callback types, but need to be part of same bitfield for AK::SoundEngine::PostEvent().
	AK_EnableGetSourcePlayPosition = 0x100000,
	AK_EnableGetMusicPlayPosition = 0x200000,
	AK_EnableGetSourceStreamBuffering = 0x400000
};
struct AkCallbackInfo
{
	void* pCookie;
	AkGameObjectID  gameObjID;
};

enum DynamicSequenceType
{
	DynamicSequenceType_SampleAccurate,
	DynamicSequenceType_NormalTransition
};
//
typedef void(*AkCallbackFunc)(AkCallbackType in_eType, AkCallbackInfo* in_pCallbackInfo);

enum AkActionOnEventType
{
	AkActionOnEventType_Stop = 0,
	AkActionOnEventType_Pause = 1,
	AkActionOnEventType_Resume = 2,
	AkActionOnEventType_Break = 3,
	AkActionOnEventType_ReleaseEnvelope = 4
};

//struct AkCommSettings
//{
//	AkCommSettings()
//	{
//		szAppNetworkName[0] = 0;
//	}
//	AkUInt32    uPoolSize;
//	struct Ports
//	{
//		Ports()
//			: uDiscoveryBroadcast(24024)
//			, uCommand(0)
//			, uNotification(0)
//		{
//		}
//		AkUInt16 uDiscoveryBroadcast;
//		AkUInt16 uCommand;
//		AkUInt16 uNotification;
//	};
//	Ports ports;
//	bool bInitSystemLib;
//	char szAppNetworkName[64];
//};
//
//
//typedef void(*AkBankCallbackFunc)(AkUInt32 in_bankID, const void* in_pInMemoryBankPtr, AKRESULT in_eLoadResult, AkMemPoolId in_memPoolId, void* in_pCookie);
//
typedef wchar_t AkOSChar;
//
struct AkExternalSourceInfo
{
	AkUInt32 iExternalSrcCookie;
	AkCodecID idCodec;
	AkOSChar* szFile;
	void* pInMemory;
	AkUInt32 uiMemorySize;
	AkFileID idFile;

	AkExternalSourceInfo()
		: iExternalSrcCookie(0)
		, idCodec(0)
		, szFile(0)
		, pInMemory(0)
		, uiMemorySize(0)
		, idFile(0) {}

	AkExternalSourceInfo(
		void* in_pInMemory,
		AkUInt32 in_uiMemorySize,
		AkUInt32 in_iExternalSrcCookie,
		AkCodecID in_idCodec
	)
		: iExternalSrcCookie(in_iExternalSrcCookie)
		, idCodec(in_idCodec)
		, szFile(0)
		, pInMemory(in_pInMemory)
		, uiMemorySize(in_uiMemorySize)
		, idFile(0) {}

	AkExternalSourceInfo(
		AkOSChar* in_pszFileName,
		AkUInt32 in_iExternalSrcCookie,
		AkCodecID in_idCodec
	)
		: iExternalSrcCookie(in_iExternalSrcCookie)
		, idCodec(in_idCodec)
		, szFile(in_pszFileName)
		, pInMemory(0)
		, uiMemorySize(0)
		, idFile(0) {}

	AkExternalSourceInfo(
		AkFileID in_idFile,
		AkUInt32 in_iExternalSrcCookie,
		AkCodecID in_idCodec
	)
		: iExternalSrcCookie(in_iExternalSrcCookie)
		, idCodec(in_idCodec)
		, szFile(0)
		, pInMemory(0)
		, uiMemorySize(0)
		, idFile(in_idFile) {}
};
//
//enum PreparationType
//{
//	Preparation_Load,
//	Preparation_Unload
//};
//
//enum AkBankContent
//{
//	AkBankContent_StructureOnly,
//	AkBankContent_All
//};
//
//enum AkGroupType // should stay set as Switch = 0 and State = 1
//{
//	AkGroupType_Switch = 0,
//	AkGroupType_State = 1
//};
//
//typedef AkUInt32 AkAuxBusID;
//
//struct AkAuxSendValue
//{
//	AkAuxBusID auxBusID;
//	AkReal32 fControlValue;
//};
//
//struct AkVector
//{
//	AkReal32 X;
//	AkReal32 Y;
//	AkReal32 Z;
//};
//
//struct AkListenerPosition
//{
//	AkVector OrientationFront;
//	AkVector OrientationTop;
//	AkVector Position;
//};
//
//struct AkSoundPosition
//{
//	AkVector        Position;
//	AkVector        Orientation;
//};
//
//enum AkPannerType
//{
//	Ak2D = 0,
//	Ak3D = 1
//};
//
//enum AkPositionSourceType
//{
//	AkUserDef = 0,
//	AkGameDef = 1
//};
//
//struct AkPositioningInfo
//{
//	AkReal32            fCenterPct;
//	AkPannerType        pannerType;
//	AkPositionSourceType posSourceType;
//	bool                bUpdateEachFrame;
//	bool                bUseSpatialization;
//	bool                bUseAttenuation;
//
//	bool                bUseConeAttenuation;
//	AkReal32            fInnerAngle;
//	AkReal32            fOuterAngle;
//	AkReal32            fConeMaxAttenuation;
//	AkLPFType           LPFCone;
//	AkLPFType           HPFCone;
//
//	AkReal32            fMaxDistance;
//	AkReal32            fVolDryAtMaxDist;
//	AkReal32            fVolAuxGameDefAtMaxDist;
//	AkReal32            fVolAuxUserDefAtMaxDist;
//	AkLPFType           LPFValueAtMaxDist;
//	AkLPFType           HPFValueAtMaxDist;
//};
//
struct AkObjectInfo
{
	AkUniqueID  objID;
	AkUniqueID  parentID;
	AkInt32     iDepth;
};
//class IAkSoftwareCodec;
//
//typedef IAkSoftwareCodec* (AkCreateFileSourceCallback)(void* in_pCtx);
//typedef IAkSoftwareCodec* (AkCreateBankSourceCallback)(void* in_pCtx);
//typedef void(AkGlobalCallbackFunc)(bool in_bLastCall);
//
//enum AkPluginType
//{
//	AkPluginTypeNone = 0,
//	AkPluginTypeCodec = 1,
//	AkPluginTypeSource = 2,
//	AkPluginTypeEffect = 3,
//	AkPluginTypeMotionDevice = 4,
//	AkPluginTypeMotionSource = 5,
//	AkPluginTypeMixer = 6,
//	AkPluginTypeSink = 7,
//	AkPluginTypeMask = 0xf
//};
//
//struct AkPluginInfo
//{
//	AkPluginType eType;
//	bool bIsInPlace;
//	bool bIsAsynchronous;
//};
//
//class IAkPluginMemAlloc
//{
//protected:
//	virtual ~IAkPluginMemAlloc() {}
//
//public:
//	virtual void* Malloc(
//		size_t in_uSize
//	) = 0;
//
//	virtual void Free(
//		void* in_pMemAddress
//	) = 0;
//};
//
//class IAkPlugin
//{
//protected:
//	virtual ~IAkPlugin() {}
//
//public:
//	virtual AKRESULT Term(
//		IAkPluginMemAlloc* in_pAllocator
//	) = 0;
//
//	virtual AKRESULT Reset() = 0;
//
//	virtual AKRESULT GetPluginInfo(
//		AkPluginInfo& out_rPluginInfo
//	) = 0;
//
//	virtual bool SupportMediaRelocation() const {
//		return false;
//	}
//
//
//	virtual AKRESULT RelocateMedia(
//		AkUInt8* /*in_pNewMedia*/,
//		AkUInt8* /*in_pOldMedia*/
//	)
//	{
//		return AK_NotImplemented;
//	}
//
//};
//
//class IAkRTPCSubscriber
//{
//protected:
//	virtual ~IAkRTPCSubscriber() {}
//
//public:
//	virtual AKRESULT SetParam(
//		AkPluginParamID in_paramID,
//		const void* in_pParam,
//		AkUInt32        in_uParamSize
//	) = 0;
//};
//
//class IAkPluginParam : public IAkRTPCSubscriber
//{
//protected:
//	virtual ~IAkPluginParam() {}
//
//public:
//	virtual IAkPluginParam* Clone(
//		IAkPluginMemAlloc* in_pAllocator
//	) = 0;
//
//	virtual AKRESULT Init(
//		IAkPluginMemAlloc* in_pAllocator,
//		const void* in_pParamsBlock,
//		AkUInt32            in_uBlockSize
//	) = 0;
//
//	virtual AKRESULT Term(
//		IAkPluginMemAlloc* in_pAllocator
//	) = 0;
//
//	virtual AKRESULT SetParamsBlock(
//		const void* in_pParamsBlock,
//		AkUInt32 in_uBlockSize
//	) = 0;
//
//	virtual AKRESULT SetParam(
//		AkPluginParamID in_paramID,
//		const void* in_pValue,
//		AkUInt32 in_uParamSize
//	) = 0;
//	static const AkPluginParamID ALL_PLUGIN_DATA_ID = 0x7FFF;
//};
//
//typedef IAkPlugin* (AkCreatePluginCallback)(IAkPluginMemAlloc* in_pAllocator);
//typedef IAkPluginParam* (AkCreateParamCallback)(IAkPluginMemAlloc* in_pAllocator);
//
//enum MultiPositionType
//{
//	MultiPositionType_SingleSource,
//	MultiPositionType_MultiSources,
//	MultiPositionType_MultiDirections
//};
//
//struct PoolMemInfo
//{
//	// Current state
//	AkUInt32 uReserved;
//	AkUInt32 uUsed;
//};
//
//struct PoolStats
//{
//	// Current state
//	AkUInt32 uReserved;
//	AkUInt32 uUsed;
//	AkUInt32 uMaxFreeBlock;
//
//	// Statistics
//	AkUInt32 uAllocs;
//	AkUInt32 uFrees;
//	AkUInt32 uPeakUsed;
//};
//
//enum ErrorLevel
//{
//	ErrorLevel_Message = (1 << 0), // used as bitfield
//	ErrorLevel_Error = (1 << 1),
//
//	ErrorLevel_All = ErrorLevel_Message | ErrorLevel_Error
//};
//
//enum ErrorCode
//{
//	ErrorCode_NoError = 0, // 0-based index into AK::Monitor::s_aszErrorCodes table 
//	ErrorCode_FileNotFound,
//	ErrorCode_CannotOpenFile,
//	ErrorCode_CannotStartStreamNoMemory,
//	ErrorCode_IODevice,
//	ErrorCode_IncompatibleIOSettings,
//
//	ErrorCode_PluginUnsupportedChannelConfiguration,
//	ErrorCode_PluginMediaUnavailable,
//	ErrorCode_PluginInitialisationFailed,
//	ErrorCode_PluginProcessingFailed,
//	ErrorCode_PluginExecutionInvalid,
//	ErrorCode_PluginAllocationFailed,
//
//	ErrorCode_VorbisRequireSeekTable,
//	ErrorCode_VorbisRequireSeekTableVirtual,
//
//	ErrorCode_VorbisDecodeError,
//	ErrorCode_AACDecodeError,
//
//	ErrorCode_xWMACreateDecoderFailed,
//
//	ErrorCode_ATRAC9CreateDecoderFailed,
//	ErrorCode_ATRAC9CreateDecoderFailedChShortage,
//	ErrorCode_ATRAC9DecodeFailed,
//	ErrorCode_ATRAC9ClearContextFailed,
//	ErrorCode_ATRAC9LoopSectionTooSmall,
//
//	ErrorCode_InvalidAudioFileHeader,
//	ErrorCode_AudioFileHeaderTooLarge,
//	ErrorCode_FileTooSmall,
//
//	ErrorCode_TransitionNotAccurateChannel,
//	ErrorCode_TransitionNotAccurateStarvation,
//	ErrorCode_NothingToPlay,
//	ErrorCode_PlayFailed,
//
//	ErrorCode_StingerCouldNotBeScheduled,
//	ErrorCode_TooLongSegmentLookAhead,
//	ErrorCode_CannotScheduleMusicSwitch,
//	ErrorCode_TooManySimultaneousMusicSegments,
//	ErrorCode_PlaylistStoppedForEditing,
//	ErrorCode_MusicClipsRescheduledAfterTrackEdit,
//
//	ErrorCode_CannotPlaySource_Create,
//	ErrorCode_CannotPlaySource_VirtualOff,
//	ErrorCode_CannotPlaySource_TimeSkip,
//	ErrorCode_CannotPlaySource_InconsistentState,
//	ErrorCode_MediaNotLoaded,
//	ErrorCode_VoiceStarving,
//	ErrorCode_StreamingSourceStarving,
//	ErrorCode_XMADecoderSourceStarving,
//	ErrorCode_XMADecodingError,
//	ErrorCode_InvalidXMAData,
//
//	ErrorCode_PluginNotRegistered,
//	ErrorCode_CodecNotRegistered,
//
//	ErrorCode_EventIDNotFound,
//
//	ErrorCode_InvalidGroupID,
//	ErrorCode_SelectedChildNotAvailable,
//	ErrorCode_SelectedNodeNotAvailable,
//	ErrorCode_SelectedMediaNotAvailable,
//	ErrorCode_NoValidSwitch,
//
//	ErrorCode_SelectedNodeNotAvailablePlay,
//
//	ErrorCode_FeedbackVoiceStarving,
//
//	ErrorCode_BankLoadFailed,
//	ErrorCode_BankUnloadFailed,
//	ErrorCode_ErrorWhileLoadingBank,
//	ErrorCode_InsufficientSpaceToLoadBank,
//
//	ErrorCode_LowerEngineCommandListFull,
//
//	ErrorCode_SeekNoMarker,
//	ErrorCode_CannotSeekContinuous,
//	ErrorCode_SeekAfterEof,
//
//	ErrorCode_UnknownGameObjectEvent,
//	ErrorCode_UnknownGameObject,
//
//	ErrorCode_ExternalSourceNotResolved,
//	ErrorCode_FileFormatMismatch,
//
//	ErrorCode_CommandQueueFull,
//	ErrorCode_CommandTooLarge,
//
//	ErrorCode_ExecuteActionOnEvent,
//	ErrorCode_StopAll,
//	ErrorCode_StopPlayingID,
//
//	ErrorCode_XMACreateDecoderLimitReached,
//	ErrorCode_XMAStreamBufferTooSmall,
//
//	ErrorCode_ModulatorScopeError_Inst,
//	ErrorCode_ModulatorScopeError_Obj,
//
//	Num_ErrorCodes // THIS STAYS AT END OF ENUM
//};
//
//struct AkMusicSettings
//{
//	AkReal32 fStreamingLookAheadRatio;
//};
//
//struct AkSegmentInfo
//{
//	AkTimeMs iCurrentPosition;
//	AkTimeMs iPreEntryDuration;
//	AkTimeMs iActiveDuration;
//	AkTimeMs iPostExitDuration;
//	AkTimeMs iRemainingLookAheadTime;
//};
//
//typedef void(*AkLanguageChangeHandler)(const AkOSChar* const in_pLanguageName, void* in_pCookie);
//
//struct AkStreamMgrSettings
//{
//	AkUInt32 uMemorySize;
//};
//
//enum AkMemPoolAttributes
//{
//	AkNoAlloc = 0,
//	AkMalloc = 1,
//	AkAllocMask = AkNoAlloc | AkMalloc,
//
//	AkFixedSizeBlocksMode = 1 << 3,
//	AkBlockMgmtMask = AkFixedSizeBlocksMode
//};
//
//#define AKSOUNDENGINE_API
//#define AkForceInline   __forceinline
//#define AK_SIMD_ALIGNMENT   16                  ///< Platform-specific alignment requirement for SIMD data
//#define AK_ALIGN_SIMD(__Declaration__) __declspec(align(AK_SIMD_ALIGNMENT)) __Declaration__ ///< Platform-specific alignment requirement for SIMD data
//#define AK_ALIGN_DMA                            ///< Platform-specific data alignment for DMA transfers
//#define AK_ALIGN_FASTDMA                        ///< Platform-specific data alignment for faster DMA transfers
//#define AK_ALIGN_SIZE_FOR_DMA(__Size__) (__Size__) ///< Used to align sizes to next 16 byte boundary on platfroms that require it
//
//extern AKSOUNDENGINE_API AkMemPoolId g_DefaultPoolId;
//extern AKSOUNDENGINE_API AkMemPoolId g_LEngineDefaultPoolId;
//
//#define _AKARRAY_H
//
//#define AK_DEFINE_ARRAY_POOL( _name_, _poolID_ )    \
//struct _name_                                       \
//{                                                   \
//	static AkMemPoolId Get()                        \
//    {                                               \
//		return _poolID_;                            \
//	}                                               \
//};
//
//AK_DEFINE_ARRAY_POOL(_ArrayPoolDefault, g_DefaultPoolId)
//AK_DEFINE_ARRAY_POOL(_ArrayPoolLEngineDefault, g_LEngineDefaultPoolId)
//
//template <class U_POOL>
//struct AkArrayAllocatorNoAlign
//{
//	AkForceInline void TransferMem(void*& io_pDest, AkArrayAllocatorNoAlign<U_POOL> in_srcAlloc, void* in_pSrc)
//	{
//		io_pDest = in_pSrc;
//	}
//};
//
//template <class U_POOL>
//struct AkArrayAllocatorAlignedSimd
//{
//	AkForceInline void* Alloc(size_t in_uSize)
//	{
//		return AK::MemoryMgr::Malign(U_POOL::Get(), in_uSize, AK_SIMD_ALIGNMENT);
//	}
//
//	AkForceInline void Free(void* in_pAddress)
//	{
//		AK::MemoryMgr::Falign(U_POOL::Get(), in_pAddress);
//	}
//
//	AkForceInline void TransferMem(void*& io_pDest, AkArrayAllocatorAlignedSimd<U_POOL> in_srcAlloc, void* in_pSrc)
//	{
//		io_pDest = in_pSrc;
//	}
//
//};
//
//template <class T>
//struct AkAssignmentMovePolicy
//{
//	// By default the assignment operator is invoked to move elements of an array from slot to slot.  If desired,
//	//	a custom 'Move' operation can be passed into TMovePolicy to transfer ownership of resources from in_Src to in_Dest.
//	static AkForceInline void Move(T& in_Dest, T& in_Src)
//	{
//		in_Dest = in_Src;
//	}
//};
//
//// Can be used as TMovePolicy to create arrays of arrays.
//template <class T>
//struct AkTransferMovePolicy
//{
//	static AkForceInline void Move(T& in_Dest, T& in_Src)
//	{
//		in_Dest.Transfer(in_Src); //transfer ownership of resources.
//	}
//};
//
//// Common allocators:
//typedef AkArrayAllocatorNoAlign<_ArrayPoolDefault> ArrayPoolDefault;
//typedef AkArrayAllocatorNoAlign<_ArrayPoolLEngineDefault> ArrayPoolLEngineDefault;
//typedef AkArrayAllocatorAlignedSimd<_ArrayPoolLEngineDefault> ArrayPoolLEngineDefaultAlignedSimd;
//
//struct AkPlacementNewKey
//{
//	AkForceInline AkPlacementNewKey() {}
//};
//
//#define AkPlacementNew(_memory) ::new( _memory, AkPlacementNewKey() )
//
//AkForceInline void* operator new(size_t /*size*/, void* memory, const AkPlacementNewKey& /*key*/) throw()
//{
//	return memory;
//}
//
//#define AKASSERT(Condition) ((void)0)
//
///// Specific implementation of array
//template <class T, class ARG_T, class TAlloc = ArrayPoolDefault, unsigned long TGrowBy = 1, class TMovePolicy = AkAssignmentMovePolicy<T> > class AkArray : public TAlloc
//{
//public:
//	/// Constructor
//	AkArray()
//		: m_pItems(0)
//		, m_uLength(0)
//		, m_ulReserved(0)
//	{
//	}
//
//	/// Destructor
//	~AkArray()
//	{
//		AKASSERT(m_pItems == 0);
//		AKASSERT(m_uLength == 0);
//		AKASSERT(m_ulReserved == 0);
//	}
//
//	/// Iterator
//	struct Iterator
//	{
//		T* pItem;	///< Pointer to the item in the array.
//
//		/// ++ operator
//		Iterator& operator++()
//		{
//			AKASSERT(pItem);
//			++pItem;
//			return *this;
//		}
//
//		/// -- operator
//		Iterator& operator--()
//		{
//			AKASSERT(pItem);
//			--pItem;
//			return *this;
//		}
//
//		/// * operator
//		T& operator*()
//		{
//			AKASSERT(pItem);
//			return *pItem;
//		}
//
//		/// == operator
//		bool operator ==(const Iterator& in_rOp) const
//		{
//			return (pItem == in_rOp.pItem);
//		}
//
//		/// != operator
//		bool operator !=(const Iterator& in_rOp) const
//		{
//			return (pItem != in_rOp.pItem);
//		}
//	};
//
//	/// Returns the iterator to the first item of the array, will be End() if the array is empty.
//	Iterator Begin() const
//	{
//		Iterator returnedIt;
//		returnedIt.pItem = m_pItems;
//		return returnedIt;
//	}
//
//	/// Returns the iterator to the end of the array
//	Iterator End() const
//	{
//		Iterator returnedIt;
//		returnedIt.pItem = m_pItems + m_uLength;
//		return returnedIt;
//	}
//
//	/// Returns the iterator th the specified item, will be End() if the item is not found
//	Iterator FindEx(ARG_T in_Item) const
//	{
//		Iterator it = Begin();
//
//		for (Iterator itEnd = End(); it != itEnd; ++it)
//		{
//			if (*it == in_Item)
//				break;
//		}
//
//		return it;
//	}
//
//	/// Returns the iterator th the specified item, will be End() if the item is not found
//	/// The array must be in ascending sorted order.
//	Iterator BinarySearch(ARG_T in_Item) const
//	{
//		Iterator itResult = End();
//		if (m_pItems)
//		{
//			T* pTop = m_pItems, * pBottom = m_pItems + m_uLength;
//
//			while (pTop <= pBottom)
//			{
//				T* pThis = (pBottom - pTop) / 2 + pTop;
//				if (in_Item < *pThis)
//					pBottom = pThis - 1;
//				else if (in_Item > * pThis)
//					pTop = pThis + 1;
//				else
//				{
//					itResult.pItem = pThis;
//					break;
//				}
//			}
//		}
//
//		return itResult;
//	}
//
//	/// Erase the specified iterator from the array
//	Iterator Erase(Iterator& in_rIter)
//	{
//		AKASSERT(m_pItems != 0);
//
//		// Move items by 1
//
//		T* pItemLast = m_pItems + m_uLength - 1;
//
//		for (T* pItem = in_rIter.pItem; pItem < pItemLast; pItem++)
//			TMovePolicy::Move(pItem[0], pItem[1]);
//
//		// Destroy the last item
//
//		pItemLast->~T();
//
//		m_uLength--;
//
//		return in_rIter;
//	}
//
//	/// Erase the item at the specified index
//	void Erase(unsigned int in_uIndex)
//	{
//		AKASSERT(m_pItems != 0);
//
//		// Move items by 1
//
//		T* pItemLast = m_pItems + m_uLength - 1;
//
//		for (T* pItem = m_pItems + in_uIndex; pItem < pItemLast; pItem++)
//			TMovePolicy::Move(pItem[0], pItem[1]);
//
//		// Destroy the last item
//
//		pItemLast->~T();
//
//		m_uLength--;
//	}
//
//	/// Erase the specified iterator in the array. but it dos not guarantee the ordering in the array.
//	/// This version should be used only when the order in the array is not an issue.
//	Iterator EraseSwap(Iterator& in_rIter)
//	{
//		AKASSERT(m_pItems != 0);
//
//		if (Length() > 1)
//		{
//			// Swap last item with this one.
//			TMovePolicy::Move(*in_rIter.pItem, Last());
//		}
//
//		// Destroy.
//		AKASSERT(Length() > 0);
//		Last().~T();
//
//		m_uLength--;
//
//		return in_rIter;
//	}
//
//	/// Pre-Allocate a number of spaces in the array
//	AKRESULT Reserve(AkUInt32 in_ulReserve)
//	{
//		AKASSERT(m_pItems == 0 && m_uLength == 0);
//		AKASSERT(in_ulReserve || TGrowBy);
//
//		if (in_ulReserve)
//		{
//			m_pItems = (T*)TAlloc::Alloc(sizeof(T) * in_ulReserve);
//			if (m_pItems == 0)
//				return AK_InsufficientMemory;
//
//			m_ulReserved = in_ulReserve;
//		}
//
//		return AK_Success;
//	}
//
//	AkUInt32 Reserved() const { return m_ulReserved; }
//
//	/// Term the array. Must be called before destroying the object.
//	void Term()
//	{
//		if (m_pItems)
//		{
//			RemoveAll();
//			TAlloc::Free(m_pItems);
//			m_pItems = 0;
//			m_ulReserved = 0;
//		}
//	}
//
//	/// Returns the numbers of items in the array.
//	AkForceInline AkUInt32 Length() const
//	{
//		return m_uLength;
//	}
//
//	/// Returns true if the number items in the array is 0, false otherwise.
//	AkForceInline bool IsEmpty() const
//	{
//		return m_uLength == 0;
//	}
//
//	/// Returns a pointer to the specified item in the list if it exists, 0 if not found.
//	T* Exists(ARG_T in_Item) const
//	{
//		Iterator it = FindEx(in_Item);
//		return (it != End()) ? it.pItem : 0;
//	}
//
//	/// Add an item in the array, without filling it.
//	/// Returns a pointer to the location to be filled.
//	T* AddLast()
//	{
//		size_t cItems = Length();
//
//		if ((cItems >= m_ulReserved) && TGrowBy > 0)
//		{
//			if (!GrowArray())
//				return 0;
//		}
//
//		// have we got space for a new one ?
//		if (cItems < m_ulReserved)
//		{
//			T* pEnd = m_pItems + m_uLength++;
//			AkPlacementNew(pEnd) T;
//			return pEnd;
//		}
//
//		return 0;
//	}
//
//	/// Add an item in the array, and fills it with the provided item.
//	T* AddLast(ARG_T in_rItem)
//	{
//		T* pItem = AddLast();
//		if (pItem)
//			*pItem = in_rItem;
//		return pItem;
//	}
//
//	/// Returns a reference to the last item in the array.
//	T& Last()
//	{
//		AKASSERT(m_uLength);
//
//		return *(m_pItems + m_uLength - 1);
//	}
//
//	/// Removes the last item from the array.
//	void RemoveLast()
//	{
//		AKASSERT(m_uLength);
//		(m_pItems + m_uLength - 1)->~T();
//		m_uLength--;
//	}
//
//	/// Removes the specified item if found in the array.
//	AKRESULT Remove(ARG_T in_rItem)
//	{
//		Iterator it = FindEx(in_rItem);
//		if (it != End())
//		{
//			Erase(it);
//			return AK_Success;
//		}
//
//		return AK_Fail;
//	}
//
//	/// Fast remove of the specified item in the array.
//	/// This method do not guarantee keeping ordering of the array.
//	AKRESULT RemoveSwap(ARG_T in_rItem)
//	{
//		Iterator it = FindEx(in_rItem);
//		if (it != End())
//		{
//			EraseSwap(it);
//			return AK_Success;
//		}
//
//		return AK_Fail;
//	}
//
//	/// Removes all items in the array
//	void RemoveAll()
//	{
//		for (Iterator it = Begin(), itEnd = End(); it != itEnd; ++it)
//			(*it).~T();
//		m_uLength = 0;
//	}
//
//	/// Operator [], return a reference to the specified index.
//	AkForceInline T& operator[](unsigned int uiIndex) const
//	{
//		AKASSERT(m_pItems);
//		AKASSERT(uiIndex < Length());
//		return m_pItems[uiIndex];
//	}
//
//	/// Insert an item at the specified position without filling it.
//	/// Returns the pointer to the item to be filled.
//	T* Insert(unsigned int in_uIndex)
//	{
//		AKASSERT(in_uIndex <= Length());
//
//		size_t cItems = Length();
//
//		if ((cItems >= m_ulReserved) && TGrowBy > 0)
//		{
//			if (!GrowArray())
//				return 0;
//		}
//
//		// have we got space for a new one ?
//		if (cItems < m_ulReserved)
//		{
//			T* pItemLast = m_pItems + m_uLength++;
//			AkPlacementNew(pItemLast) T;
//
//			// Move items by 1
//
//			for (T* pItem = pItemLast; pItem > (m_pItems + in_uIndex); --pItem)
//				TMovePolicy::Move(pItem[0], pItem[-1]);
//
//			// Reinitialize item at index
//
//			(m_pItems + in_uIndex)->~T();
//			AkPlacementNew(m_pItems + in_uIndex) T;
//
//			return m_pItems + in_uIndex;
//		}
//
//		return 0;
//	}
//
//	/// Resize the array.
//	bool GrowArray(AkUInt32 in_uGrowBy = TGrowBy)
//	{
//		AKASSERT(in_uGrowBy);
//		return true;
//	}
//
//	/// Resize the array to the specified size.
//	bool Resize(AkUInt32 in_uiSize)
//	{
//		AkUInt32 cItems = Length();
//		if (in_uiSize < cItems)
//		{
//			//Destroy superfluous elements
//			for (AkUInt32 i = in_uiSize - 1; i < cItems; i++)
//			{
//				m_pItems[i].~T();
//			}
//			m_uLength = in_uiSize;
//			return true;
//		}
//
//		if (in_uiSize > m_ulReserved)
//		{
//			if (!GrowArray(in_uiSize - cItems))
//				return false;
//		}
//
//		//Create the missing items.
//		for (size_t i = cItems; i < in_uiSize; i++)
//		{
//			AkPlacementNew(m_pItems + i) T;
//		}
//
//		m_uLength = in_uiSize;
//		return true;
//	}
//
//	void Transfer(AkArray<T, ARG_T, TAlloc, TGrowBy, TMovePolicy>& in_rSource)
//	{
//		Term();
//
//		TAlloc::TransferMem((void*&)m_pItems, in_rSource, (void*)in_rSource.m_pItems);
//		m_uLength = in_rSource.m_uLength;
//		m_ulReserved = in_rSource.m_ulReserved;
//
//		in_rSource.m_pItems = NULL;
//		in_rSource.m_uLength = 0;
//		in_rSource.m_ulReserved = 0;
//	}
//
//	AKRESULT Copy(const AkArray<T, ARG_T, TAlloc, TGrowBy, TMovePolicy>& in_rSource)
//	{
//		Term();
//
//		if (Resize(in_rSource.Length()))
//		{
//			for (AkUInt32 i = 0; i < in_rSource.Length(); ++i)
//				m_pItems[i] = in_rSource.m_pItems[i];
//			return AK_Success;
//		}
//		return AK_Fail;
//	}
//
//protected:
//
//	T* m_pItems;		///< pointer to the beginning of the array.
//	AkUInt32    m_uLength;		///< number of items in the array.
//	AkUInt32	m_ulReserved;	///< how many we can have at most (currently allocated).
//};
//
//struct GameObjDst
//{
//	GameObjDst()
//		: m_gameObjID(AK_INVALID_GAME_OBJECT)
//		, m_dst(-1.0f)
//	{}
//
//	GameObjDst(AkGameObjectID in_gameObjID, AkReal32 in_dst)
//		: m_gameObjID(in_gameObjID)
//		, m_dst(in_dst)
//	{}
//
//	AkGameObjectID  m_gameObjID;
//	AkReal32 m_dst;
//};
//
//typedef AkArray<GameObjDst, const GameObjDst&, ArrayPoolDefault, 32> AkRadiusList;
//
//#define AKASSERT(Condition) ((void)0)
//
//class AkExternalSourceArray;
//
//class PlaylistItem
//{
//public:
//	PlaylistItem();
//	PlaylistItem(const PlaylistItem& in_rCopy);
//	~PlaylistItem();
//
//	PlaylistItem& operator=(const PlaylistItem& in_rCopy);
//	bool operator==(const PlaylistItem& in_rCopy)
//	{
//		AKASSERT(pExternalSrcs == NULL);
//		return audioNodeID == in_rCopy.audioNodeID && msDelay == in_rCopy.msDelay && pCustomInfo == in_rCopy.pCustomInfo;
//	};
//
//
//	AKRESULT SetExternalSources(AkUInt32 in_nExternalSrc, AkExternalSourceInfo* in_pExternalSrc);
//
//	AkExternalSourceArray* GetExternalSources() { return pExternalSrcs; }
//
//	AkUniqueID audioNodeID;
//	AkTimeMs   msDelay;
//	void* pCustomInfo;
//
//private:
//	AkExternalSourceArray* pExternalSrcs;
//};
//
//class Playlist
//	: public AkArray < PlaylistItem, const PlaylistItem&, ArrayPoolDefault, 4>
//{
//public:
//	AkForceInline AKRESULT Enqueue(
//		AkUniqueID in_audioNodeID,
//		AkTimeMs in_msDelay = 0,
//		void* in_pCustomInfo = NULL,
//		AkUInt32 in_cExternals = 0,
//		AkExternalSourceInfo* in_pExternalSources = NULL
//	)
//	{
//		PlaylistItem* pItem = AddLast();
//		if (!pItem)
//			return AK_Fail;
//
//		pItem->audioNodeID = in_audioNodeID;
//		pItem->msDelay = in_msDelay;
//		pItem->pCustomInfo = in_pCustomInfo;
//		return pItem->SetExternalSources(in_cExternals, in_pExternalSources);
//	}
//};
//struct IXAudio2;
//
//enum AkSoundQuality
//{
//	AkSoundQuality_High,
//	AkSoundQuality_Low,
//};
//
//struct AkThreadProperties
//{
//	int                 nPriority;
//	AkUInt32            dwAffinityMask;
//	AkUInt32            uStackSize;
//};
//
//struct AkPlatformInitSettings
//{
//	// Direct sound.
//	HWND                hWnd;
//
//	// Threading model.
//	AkThreadProperties  threadLEngine;
//	AkThreadProperties  threadBankManager;
//	AkThreadProperties  threadMonitor;
//
//	// Memory.
//	AkUInt32            uLEngineDefaultPoolSize;
//	AkReal32            fLEngineDefaultPoolRatioThreshold;
//
//	// Voices.
//	AkUInt16            uNumRefillsInVoice;
//	AkSoundQuality      eAudioQuality;
//
//	bool                bGlobalFocus;
//
//	IXAudio2* pXAudio2;
//
//	AkUInt32            idAudioDevice;
//};
//
//enum AkPanningRule
//{
//	AkPanningRule_Speakers = 0,
//	AkPanningRule_Headphones = 1
//};
//
//enum AkAudioOutputType
//{
//	AkOutput_Dummy = 1 << 3,
//	AkOutput_MergeToMain = 1 << 4,
//	AkOutput_Main = 1 << 5,
//	AkOutput_Secondary = 1 << 6,
//	AkOutput_NumOutputs = 1 << 7,
//};
//
//typedef void(*AkAssertHook)(const char* in_pszExpression, const char* in_pszFileName, int in_lineNumber);
//
//typedef AKRESULT(*AkAudioSourceChangeCallbackFunc)(bool in_bOtherAudioPlaying, void* in_pCookie);
//
//enum AkChannelConfigType
//{
//	AK_ChannelConfigType_Anonymous = 0x0,  // Channel mask == 0 and channels are anonymous.
//	AK_ChannelConfigType_Standard = 0x1,  // Channels must be identified with standard defines in AkSpeakerConfigs.   
//	AK_ChannelConfigType_Ambisonic = 0x2   // Ambisonic. Channel mask == 0 and channels follow standard ambisonic order.
//};
//
//#define AK_SPEAKER_FRONT_LEFT				0x1		///< Front left speaker bit mask
//#define AK_SPEAKER_FRONT_RIGHT				0x2		///< Front right speaker bit mask
//#define AK_SPEAKER_FRONT_CENTER				0x4		///< Front center speaker bit mask
//#define AK_SPEAKER_SETUP_MONO			AK_SPEAKER_FRONT_CENTER		///< 1.0 setup channel mask
//#define AK_SPEAKER_SETUP_STEREO			(AK_SPEAKER_FRONT_LEFT		| AK_SPEAKER_FRONT_RIGHT)	///< 2.0 setup channel mask
//
//struct AkChannelConfig
//{
//	// Channel config: 
//	// - uChannelMask is a bit field, whose channel identifiers depend on AkChannelConfigType (up to 20). Channel bits are defined in AkSpeakerConfig.h.
//	// - eConfigType is a code that completes the identification of channels by uChannelMask.
//	// - uNumChannels is the number of channels, identified (deduced from channel mask) or anonymous (set directly). 
//	AkUInt32	uNumChannels : 8;	///< Number of channels.
//	AkUInt32	eConfigType : 4;	///< Channel config type (AkChannelConfigType).
//	AkUInt32	uChannelMask : 20;///< Channel mask (configuration). 
//
//	/// Constructor. Clears / sets the channel config in "invalid" state (IsValid() returns false).
//	AkForceInline AkChannelConfig()
//		: uNumChannels(0)
//		, eConfigType(0)
//		, uChannelMask(0)
//	{
//	}
//
//	/// Constructor. Sets number of channels, and config type according to whether channel mask is defined or not. If defined, it must be consistent with the number of channels.
//	AkForceInline AkChannelConfig(AkUInt32 in_uNumChannels, AkUInt32 in_uChannelMask)
//	{
//		// Input arguments should be consistent.
//		SetStandardOrAnonymous(in_uNumChannels, in_uChannelMask);
//	}
//
//	/// Operator != with a 32-bit word.
//	AkForceInline bool operator!=(AkUInt32 in_uBitField)
//	{
//		return (*((AkUInt32*)this) != in_uBitField);
//	}
//
//	/// Clear the channel config. Becomes "invalid" (IsValid() returns false).
//	AkForceInline void Clear()
//	{
//		uNumChannels = 0;
//		eConfigType = 0;
//		uChannelMask = 0;
//	}
//
//	static inline AkUInt8 ChannelMaskToNumChannels(AkChannelMask in_uChannelMask)
//	{
//		AkUInt8 num = 0;
//		while (in_uChannelMask) { ++num; in_uChannelMask &= in_uChannelMask - 1; } // iterate max once per channel.
//		return num;
//	}
//
//	/// Set channel config as a standard configuration specified with given channel mask.
//	AkForceInline void SetStandard(AkUInt32 in_uChannelMask)
//	{
//		uNumChannels = ChannelMaskToNumChannels(in_uChannelMask);
//		eConfigType = AK_ChannelConfigType_Standard;
//		uChannelMask = in_uChannelMask;
//	}
//
//	/// Set channel config as either a standard or an anonymous configuration, specified with both a given channel mask (0 if anonymous) and a number of channels (which must match the channel mask if standard).
//	AkForceInline void SetStandardOrAnonymous(AkUInt32 in_uNumChannels, AkUInt32 in_uChannelMask)
//	{
//		AKASSERT(in_uChannelMask == 0 || in_uNumChannels == AK::ChannelMaskToNumChannels(in_uChannelMask));
//		uNumChannels = in_uNumChannels;
//		eConfigType = (in_uChannelMask) ? AK_ChannelConfigType_Standard : AK_ChannelConfigType_Anonymous;
//		uChannelMask = in_uChannelMask;
//	}
//
//	/// Set channel config as an anonymous configuration specified with given number of channels.
//	AkForceInline void SetAnonymous(AkUInt32 in_uNumChannels)
//	{
//		uNumChannels = in_uNumChannels;
//		eConfigType = AK_ChannelConfigType_Anonymous;
//		uChannelMask = 0;
//	}
//
//	/// Set channel config as an ambisonic configuration specified with given number of channels.
//	AkForceInline void SetAmbisonic(AkUInt32 in_uNumChannels)
//	{
//		uNumChannels = in_uNumChannels;
//		eConfigType = AK_ChannelConfigType_Ambisonic;
//		uChannelMask = 0;
//	}
//
//	/// Returns true if valid, false otherwise (as when it is constructed, or invalidated using Clear()).
//	AkForceInline bool IsValid() const
//	{
//		return uNumChannels != 0;
//	}
//
//	/// Serialize channel config into a 32-bit word.
//	AkForceInline AkUInt32 Serialize() const
//	{
//		return uNumChannels | (eConfigType << 8) | (uChannelMask << 12);
//	}
//
//	/// Deserialize channel config from a 32-bit word.
//	AkForceInline void Deserialize(AkUInt32 in_uChannelConfig)
//	{
//		uNumChannels = in_uChannelConfig & 0x000000ff;
//		eConfigType = (in_uChannelConfig >> 8) & 0x0000000f;
//		uChannelMask = (in_uChannelConfig >> 12) & 0x000fffff;
//	}
//
//	/// Returns a new config based on 'this' with no LFE.
//	AkForceInline AkChannelConfig RemoveLFE() const
//	{
//		AkChannelConfig newConfig = *this;
//		return newConfig;
//	}
//
//	/// Returns a new config based on 'this' with no Front Center channel.
//	AkForceInline AkChannelConfig RemoveCenter() const
//	{
//		AkChannelConfig newConfig = *this;
//		return newConfig;
//	}
//
//	/// Operator ==
//	AkForceInline bool operator==(const AkChannelConfig& in_other) const
//	{
//		return uNumChannels == in_other.uNumChannels
//			&& eConfigType == in_other.eConfigType
//			&& uChannelMask == in_other.uChannelMask;
//	}
//
//	/// Operator !=
//	AkForceInline bool operator!=(const AkChannelConfig& in_other) const
//	{
//		return uNumChannels != in_other.uNumChannels
//			|| eConfigType != in_other.eConfigType
//			|| uChannelMask != in_other.uChannelMask;
//	}
//
//	/// Checks if the channel configuration is supported by the source pipeline.
//	/// \return The interleaved type
//	AkForceInline bool IsChannelConfigSupported() const
//	{
//		if (eConfigType == AK_ChannelConfigType_Standard)
//		{
//			switch (uChannelMask)
//			{
//			case AK_SPEAKER_SETUP_MONO:
//			case AK_SPEAKER_SETUP_STEREO:
//				return true;
//			}
//		}
//		return false;
//	}
//
//	/// Query if LFE channel is present.
//	/// \return True when LFE channel is present
//	AkForceInline bool HasLFE() const
//	{
//		return false;
//	}
//
//	/// Query if center channel is present.
//	/// Note that mono configurations have one channel which is arbitrary set to AK_SPEAKER_FRONT_CENTER,
//	/// so HasCenter() returns true for mono signals.
//	/// \return True when center channel is present and configuration has more than 2 channels.
//	AkForceInline bool HasCenter() const
//	{
//		return false;
//	}
//};
//
//
//struct AkOutputSettings
//{
//	AkPanningRule   ePanningRule;
//
//	AkChannelConfig channelConfig;
//
//	AkCreatePluginCallback pfSinkPluginFactory;
//};
//
//enum AkAudioAPI
//{
//	AkAPI_XAudio2 = 1 << 0,
//	AkAPI_DirectSound = 1 << 1,
//	AkAPI_Wasapi = 1 << 2,
//	AkAPI_Default = AkAPI_Wasapi | AkAPI_XAudio2 | AkAPI_DirectSound,
//	AkAPI_Dummy = 1 << 3,
//};
//
//struct AkInitSettings
//{
//	AkAssertHook        pfnAssertHook;
//
//	AkUInt32            uMaxNumPaths;
//	AkUInt32            uMaxNumTransitions;
//	AkUInt32            uDefaultPoolSize;
//	AkReal32            fDefaultPoolRatioThreshold;
//	AkUInt32            uCommandQueueSize;
//	AkMemPoolId         uPrepareEventMemoryPoolID;
//	bool                bEnableGameSyncPreparation;
//	AkUInt32            uContinuousPlaybackLookAhead;
//
//	AkUInt32            uNumSamplesPerFrame;
//
//	AkUInt32            uMonitorPoolSize;
//	AkUInt32            uMonitorQueuePoolSize;
//
//	AkAudioAPI          eMainOutputType;
//	AkOutputSettings    settingsMainOutput;
//	AkUInt32            uMaxHardwareTimeoutMs;
//
//	bool                bUseSoundBankMgrThread;
//	bool                bUseLEngineThread;
//
//	AkAudioSourceChangeCallbackFunc sourceChangeCallback;
//	void* sourceChangeCallbackCookie;
//};
//
//typedef AkArray<AkGameObjectID, AkGameObjectID, ArrayPoolDefault, 32> AkGameObjectsList;
//
//typedef AkReal32* VectorPtr;
//
//typedef AkReal32 AkSampleType;	///< Audio sample data type (32 bit floating point)
//
//#define AK_SPEAKER_LOW_FREQUENCY 0x8
///// Audio buffer structure including the address of an audio buffer, the number of valid frames inside, 
///// and the maximum number of frames the audio buffer can hold.
///// \sa
///// - \ref fx_audiobuffer_struct
//class AkAudioBuffer
//{
//public:
//
//	/// Constructor.
//	AkAudioBuffer()
//	{
//		Clear();
//	}
//
//	/// Clear data pointer.
//	AkForceInline void ClearData()
//	{
//		pData = NULL;
//	}
//
//	/// Clear members.
//	AkForceInline void Clear()
//	{
//		ClearData();
//		uValidFrames = 0;
//		uMaxFrames = 0;
//		eState = AK_DataNeeded;
//	}
//
//	/// \name Channel queries.
//	//@{
//	/// Get the number of channels.
//	AkForceInline AkUInt32 NumChannels() const
//	{
//		return channelConfig.uNumChannels;
//	}
//
//	/// Returns true if there is an LFE channel present.
//	AkForceInline bool HasLFE() const
//	{
//		return channelConfig.HasLFE();
//	}
//
//	AkForceInline AkChannelConfig GetChannelConfig() const { return channelConfig; }
//
//	//@}
//
//	/// \name Interleaved interface
//	//@{
//	/// Get address of data: to be used with interleaved buffers only.
//	/// \remarks Only source plugins can output interleaved data. This is determined at 
//	/// initial handshaking.
//	/// \sa 
//	/// - \ref fx_audiobuffer_struct
//	AkForceInline void* GetInterleavedData()
//	{
//		return pData;
//	}
//
//	/// Attach interleaved data. Allocation is performed outside.
//	inline void AttachInterleavedData(void* in_pData, AkUInt16 in_uMaxFrames, AkUInt16 in_uValidFrames, AkChannelConfig in_channelConfig)
//	{
//		pData = in_pData;
//		uMaxFrames = in_uMaxFrames;
//		uValidFrames = in_uValidFrames;
//		channelConfig = in_channelConfig;
//	}
//	//@}
//
//	/// \name Deinterleaved interface
//	//@{
//
//	/// Check if buffer has samples attached to it.
//	AkForceInline bool HasData() const
//	{
//		return (NULL != pData);
//	}
//
//	/// Convert a channel, identified by a single channel bit, to a buffer index used in GetChannel() below, for a given channel config.
//	/// Standard indexing follows channel bit order (see AkSpeakerConfig.h). Pipeline/buffer indexing is the same but the LFE is moved to the end.
//	static inline AkUInt32 StandardToPipelineIndex(
//		AkChannelConfig
//		, AkUInt32		in_uChannelIdx			///< Channel index in standard ordering to be converted to pipeline ordering.
//	)
//	{
//		return in_uChannelIdx;
//	}
//
//	/// Get the buffer of the ith channel. 
//	/// Access to channel data is most optimal through this method. Use whenever the
//	/// speaker configuration is known, or when an operation must be made independently
//	/// for each channel.
//	/// \remarks When using a standard configuration, use ChannelMaskToBufferIndex() to convert channel bits to buffer indices.
//	/// \return Address of the buffer of the ith channel.
//	/// \sa
//	/// - \ref fx_audiobuffer_struct
//	/// - \ref fx_audiobuffer_struct_channels
//	inline AkSampleType* GetChannel(
//		AkUInt32 in_uIndex		///< Channel index [0,NumChannels()-1]
//	)
//	{
//		AKASSERT(in_uIndex < NumChannels());
//		return (AkSampleType*)((AkUInt8*)(pData)+(in_uIndex * sizeof(AkSampleType) * MaxFrames()));
//	}
//
//	/// Get the buffer of the LFE.
//	/// \return Address of the buffer of the LFE. Null if there is no LFE channel.
//	/// \sa
//	/// - \ref fx_audiobuffer_struct_channels
//	inline AkSampleType* GetLFE()
//	{
//		if (channelConfig.uChannelMask & AK_SPEAKER_LOW_FREQUENCY)
//			return GetChannel(NumChannels() - 1);
//
//		return (AkSampleType*)0;
//	}
//
//	/// Attach deinterleaved data where channels are contiguous in memory. Allocation is performed outside.
//	AkForceInline void AttachContiguousDeinterleavedData(void* in_pData, AkUInt16 in_uMaxFrames, AkUInt16 in_uValidFrames, AkChannelConfig in_channelConfig)
//	{
//		AttachInterleavedData(in_pData, in_uMaxFrames, in_uValidFrames, in_channelConfig);
//	}
//	/// Detach deinterleaved data where channels are contiguous in memory. The address of the buffer is returned and fields are cleared.
//	AkForceInline void* DetachContiguousDeinterleavedData()
//	{
//		uMaxFrames = 0;
//		uValidFrames = 0;
//		channelConfig.Clear();
//		void* pDataOld = pData;
//		pData = NULL;
//		return pDataOld;
//	}
//
//	//@}
//
//	void RelocateMedia(AkUInt8* in_pNewMedia, AkUInt8* in_pOldMedia)
//	{
//		AkUIntPtr uMemoryOffset = (AkUIntPtr)in_pNewMedia - (AkUIntPtr)in_pOldMedia;
//		pData = (void*)(((AkUIntPtr)pData) + uMemoryOffset);
//	}
//
//protected:
//
//	void* pData;				///< Start of the audio buffer.
//
//	AkChannelConfig	channelConfig;		///< Channel config.
//public:
//	AKRESULT		eState;				///< Execution status	
//protected:
//	AkUInt16		uMaxFrames;			///< Number of sample frames the buffer can hold. Access through AkAudioBuffer::MaxFrames().
//
//public:
//	/// Access to the number of sample frames the buffer can hold.
//	/// \return Number of sample frames the buffer can hold.
//	AkForceInline AkUInt16 MaxFrames() const { return uMaxFrames; }
//
//	AkUInt16		uValidFrames;		///< Number of valid sample frames in the audio buffer
//} AK_ALIGN_DMA;
//
//struct AkAudioFormat
//{
//	AkUInt32	uSampleRate;		///< Number of samples per second
//
//	AkChannelConfig channelConfig;	///< Channel configuration.
//
//	AkUInt32	uBitsPerSample : 6; ///< Number of bits per sample.
//	AkUInt32	uBlockAlign : 10;///< Number of bytes per sample frame. (For example a 5.1 PCM 16bit should have a uBlockAlign equal to 6(5.1 channels)*2(16 bits per sample) = 12.
//	AkUInt32	uTypeID : 2; ///< Data type ID (AkDataTypeID). 
//	AkUInt32	uInterleaveID : 1; ///< Interleave ID (AkDataInterleaveID). 
//
//	/// Get the number of channels.
//	/// \return The number of channels
//	AkForceInline AkUInt32 GetNumChannels() const
//	{
//		return channelConfig.uNumChannels;
//	}
//
//	/// Query if LFE channel is present.
//	/// \return True when LFE channel is present
//	AkForceInline bool HasLFE() const
//	{
//		return channelConfig.HasLFE();
//	}
//
//	/// Query if center channel is present.
//	/// Note that mono configurations have one channel which is arbitrary set to AK_SPEAKER_FRONT_CENTER,
//	/// so HasCenter() returns true for mono signals.
//	/// \return True when center channel is present and configuration has more than 2 channels.
//	AkForceInline bool HasCenter() const
//	{
//		return channelConfig.HasCenter();
//	}
//
//	/// Get the number of bits per sample.
//	/// \return The number of bits per sample
//	AkForceInline AkUInt32 GetBitsPerSample()	const
//	{
//		return uBitsPerSample;
//	}
//
//	/// Get the block alignment.
//	/// \return The block alignment
//	AkForceInline AkUInt32 GetBlockAlign() const
//	{
//		return uBlockAlign;
//	}
//
//	/// Get the data sample format (Float or Integer).
//	/// \return The data sample format
//	AkForceInline AkUInt32 GetTypeID() const
//	{
//		return uTypeID;
//	}
//
//	/// Get the interleaved type.
//	/// \return The interleaved type
//	AkForceInline AkUInt32 GetInterleaveID() const
//	{
//		return uInterleaveID;
//	}
//
//	/// Set all parameters of the audio format structure.
//	/// Channels are specified by channel mask (standard configs).
//	void SetAll(
//		AkUInt32    in_uSampleRate,		///< Number of samples per second
//		AkChannelConfig in_channelConfig,	///< Channel configuration
//		AkUInt32    in_uBitsPerSample,	///< Number of bits per sample
//		AkUInt32    in_uBlockAlign,		///< Block alignment
//		AkUInt32    in_uTypeID,			///< Data sample format (Float or Integer)
//		AkUInt32    in_uInterleaveID	///< Interleaved type
//	)
//	{
//		uSampleRate = in_uSampleRate;
//		channelConfig = in_channelConfig;
//		uBitsPerSample = in_uBitsPerSample;
//		uBlockAlign = in_uBlockAlign;
//		uTypeID = in_uTypeID;
//		uInterleaveID = in_uInterleaveID;
//	}
//
//	/// Checks if the channel configuration is supported by the source pipeline.
//	/// \return The interleaved type
//	AkForceInline bool IsChannelConfigSupported() const
//	{
//		return channelConfig.IsChannelConfigSupported();
//	}
//
//	AkForceInline bool operator==(const AkAudioFormat& in_other) const
//	{
//		return uSampleRate == in_other.uSampleRate
//			&& channelConfig == in_other.channelConfig
//			&& uBitsPerSample == in_other.uBitsPerSample
//			&& uBlockAlign == in_other.uBlockAlign
//			&& uTypeID == in_other.uTypeID
//			&& uInterleaveID == in_other.uInterleaveID;
//	}
//
//	AkForceInline bool operator!=(const AkAudioFormat& in_other) const
//	{
//		return uSampleRate != in_other.uSampleRate
//			|| channelConfig != in_other.channelConfig
//			|| uBitsPerSample != in_other.uBitsPerSample
//			|| uBlockAlign != in_other.uBlockAlign
//			|| uTypeID != in_other.uTypeID
//			|| uInterleaveID != in_other.uInterleaveID;
//	}
//};
//
//typedef void* (AkAudioInputPluginExecuteCallbackFunc)(AkPlayingID in_playingID, AkAudioBuffer* io_pBufferOut);
//typedef AkReal32 (AkAudioInputPluginGetGainCallbackFunc)(AkPlayingID in_playingID);
//typedef void (AkAudioInputPluginGetFormatCallbackFunc)(AkPlayingID in_playingID, AkAudioFormat* io_AudioFormat);

/* Typedef Functions */

	// IAKStreamMgr
	// Only has a single pointer, and is protected https://www.audiokinetic.com/library/2015.1.9_5624/?source=SDK&id=class_a_k_1_1_i_ak_stream_mgr_a85c6043c1a45f13b7df2f05729248b1f.html
	// End IAKStreamMgr

//typedef bool(__cdecl* tIsRestoreSinkRequested)(void);
//typedef bool(__cdecl* tIsUsingDummySink)(void);
//// MemoryMgr
//typedef AKRESULT(__cdecl* tMemory_CheckPoolId)(AkMemPoolId in_poolId);
//typedef AKRESULT(__cdecl* tMemory_CreatePool)(void* in_pMemAddress, AkUInt32 in_uMemSize, AkUInt32 in_uBlockSize, AkUInt32 in_eAttributes, AkUInt32 in_uBlockAlign);
//typedef AKRESULT(__cdecl* tMemory_DestroyPool)(AkMemPoolId in_poolId);
//typedef AKRESULT(__cdecl* tMemory_Falign)(AkMemPoolId in_poolId, void* in_pMemAddress);
//typedef void* (__cdecl* tMemory_GetBlock)(AkMemPoolId in_poolId);
//typedef AkUInt32(__cdecl* tMemory_GetBlockSize)(AkMemPoolId in_poolId);
//typedef AkInt32(__cdecl* tMemory_GetMaxPools)(void);
//typedef AkInt32(__cdecl* tMemory_GetNumPools)(void);
//typedef AkMemPoolAttributes(__cdecl* tMemory_GetPoolAttributes)(AkMemPoolId in_poolId);
//typedef void(__cdecl* tMemory_GetPoolMemoryUsed)(AkMemPoolId in_poolId, PoolMemInfo* out_memInfo);
//typedef AkOSChar* (__cdecl* tMemory_GetPoolName)(AkMemPoolId in_poolId);
//typedef AKRESULT(__cdecl* tMemory_GetPoolStats)(AkMemPoolId in_poolId, PoolStats* out_stats);
//typedef bool(__cdecl* tMemory_IsInitialized)(void);
//typedef void* (__cdecl* tMemory_Malign)(AkMemPoolId in_poolId, size_t in_uSize, AkUInt32 in_uAlignment);
//typedef void* (__cdecl* tMemory_Malloc)(AkMemPoolId in_poolId, size_t in_uSize);
//typedef AKRESULT(__cdecl* tMemory_ReleaseBlock)(AkMemPoolId in_poolId, void* in_pMemAddress);
//typedef AKRESULT(__cdecl* tMemory_SetMonitoring)(AkMemPoolId in_poolId, bool in_bDoMonitor);
//typedef AKRESULT(__cdecl* tMemory_SetPoolName)(AkMemPoolId in_poolId, const char* in_pszPoolName);
//typedef void(__cdecl* tMemory_Term)(void);
//// End MemoryMgr
//// Monitor
//typedef AKRESULT(__cdecl* tMonitor_PostCode)(ErrorCode in_eError, ErrorLevel in_eErrorLevel);
//// End Monitor
//// Motion Engine
//typedef AKRESULT(__cdecl* tMotion_AddPlayerMotionDevice)(AkUInt8 in_iPlayerID, AkUInt32 in_iCompanyID, AkUInt32 in_iDeviceID, void* in_pDevice);
//typedef void(__cdecl* tMotion_RegisterMotionDevice)(AkUInt32 in_ulCompanyID, AkUInt32 in_ulPluginID, AkCreatePluginCallback in_pCreateFunc);
//typedef void(__cdecl* tMotion_RemovePlayerMotionDevice)(AkUInt8 in_iPlayerID, AkUInt32 in_iCompanyID, AkUInt32 in_iDeviceID);
//typedef void(__cdecl* tMotion_SetPlayerListener)(AkUInt8 in_iPlayerID, AkUInt8 in_iListener);
//typedef void(__cdecl* tMotion_SetPlayerVolume)(AkUInt8 in_iPlayerID, AkReal32 in_fVolume);
//// End Motion Engine
//// Music Engine
//typedef void(__cdecl* tMusic_GetDefaultInitSettings)(AkMusicSettings* out_settings);
//typedef AKRESULT(__cdecl* tMusic_GetPlayingSegmentInfo)(AkPlayingID in_playingID, AkSegmentInfo* out_segmentInfo, bool in_bExtrapolate);
//typedef AKRESULT(__cdecl* tMusic_Init)(AkMusicSettings* in_pSettings);
//typedef void(__cdecl* tMusic_Term)(void);
//// End Music Engine
//// Sound Engine
//typedef void(__cdecl* tCancelBankCallbackCookie)(void* in_pCookie);
//typedef void(__cdecl* tCancelEventCallback)(AkPlayingID in_playingID);
//typedef void(__cdecl* tCancelEventCallbackCookie)(void* in_pCookie);
//typedef AKRESULT(__cdecl* tClearBanks)(void);
//typedef AKRESULT(__cdecl* tClearPreparedEvents)(void);
//// Dynamic Dialogue
//typedef AkUniqueID(__cdecl* tDynamicDialogue_ResolveDialogueEvent_UniqueID)(AkUniqueID in_eventID, AkArgumentValueID* in_aArgumentValues, AkUInt32 in_uNumArguments, AkPlayingID in_idSequence);
//typedef AkUniqueID(__cdecl* tDynamicDialogue_ResolveDialogueEvent_Char)(const char* in_pszEventName, const char** in_aArgumentValueNames, AkUInt32 in_uNumArguments, AkPlayingID in_idSequence);
//// End Dynamic Dialogue
//// Dynamic Sequence
//typedef AKRESULT(__cdecl* tDynamicSequence_Break)(AkPlayingID in_playingID);
//typedef AKRESULT(__cdecl* tDynamicSequence_Close)(AkPlayingID in_playingID);
//typedef Playlist* (__cdecl* tDynamicSequence_LockPlaylist)(AkPlayingID in_playingID);
//typedef AkPlayingID(__cdecl* tDynamicSequence_Open)(AkGameObjectID in_gameObjectID, AkUInt32 in_uFlags, AkCallbackFunc in_pfnCallback, void* in_pCookie, DynamicSequenceType in_eDynamicSequenceType);
//typedef AKRESULT(__cdecl* tDynamicSequence_Pause)(AkPlayingID in_playingID, AkTimeMs in_uTransitionDuration, AkCurveInterpolation in_eFadeCurve);
//typedef AKRESULT(__cdecl* tDynamicSequence_Play)(AkPlayingID in_playingID, AkTimeMs in_uTransitionDuration, AkCurveInterpolation in_eFadeCurve);
//typedef AKRESULT(__cdecl* tDynamicSequence_Resume)(AkPlayingID in_playingID, AkTimeMs in_uTransitionDuration, AkCurveInterpolation in_eFadeCurve);
//typedef AKRESULT(__cdecl* tDynamicSequence_Stop)(AkPlayingID in_playingID, AkTimeMs in_uTransitionDuration, AkCurveInterpolation in_eFadeCurve);
//typedef AKRESULT(__cdecl* tDynamicSequence_UnlockPlaylist)(AkPlayingID in_playingID);
//// End Dynamic Sequence
//typedef AKRESULT(__cdecl* tExecuteActionOnEvent_UniqueID)(AkUniqueID in_eventID, AkActionOnEventType in_ActionType, AkGameObjectID in_gameObjectID, AkTimeMs in_uTransitionDuration, AkCurveInterpolation in_eFadeCurve, AkPlayingID in_PlayingID);
//typedef AKRESULT(__cdecl* tExecuteActionOnEvent_Char)(const char* in_pszEventName, AkActionOnEventType in_ActionType, AkGameObjectID in_gameObjectID, AkTimeMs in_uTransitionDuration, AkCurveInterpolation in_eFadeCurve, AkPlayingID in_PlayingID);
//typedef void(__cdecl* tGetDefaultInitSettings)(AkInitSettings* out_settings);
//typedef void(__cdecl* tGetDefaultPlatformInitSettings)(AkPlatformInitSettings* out_platformSettings);
//typedef AkUInt32(__cdecl* tGetIDFromString)(const char* in_pszString);
//typedef AKRESULT(__cdecl* tGetPanningRule)(AkPanningRule* out_ePanningRule, AkAudioOutputType in_eSinkType, AkUInt32 in_iOutputID);
//typedef AKRESULT(__cdecl* tGetSourcePlayPosition)(AkPlayingID in_PlayingID, AkTimeMs* out_puPosition, bool in_bExtrapolate);
//typedef AkUInt32(__cdecl* tGetSpeakerConfiguration)(void);
//typedef AKRESULT(__cdecl* tInit)(AkInitSettings* in_pSettings, AkPlatformInitSettings* in_pPlatformSettings);
//typedef bool(__cdecl* tIsInitialized)(void);
//typedef AKRESULT(__cdecl* tLoadBank_BankID_MemPoolID)(AkBankID in_bankID, AkMemPoolId in_memPoolId);
//typedef AKRESULT(__cdecl* tLoadBank_Void_UInt32_BankID)(const void* in_plnMemoryBankPtr, AkUInt32 in_ulnMemoryBankSize, AkBankID* out_bankID);
//typedef AKRESULT(__cdecl* tLoadBank_BankID_Callback)(AkBankID in_BankID, AkBankCallbackFunc in_pfnBankCallback, void* in_pCookie, AkMemPoolId in_memPoolId);
//typedef AKRESULT(__cdecl* tLoadBank_Void_UInt32_Callback)(const void* in_plnMemoryBankPtr, AkUInt32 in_ulnMemoryBankSize, AkBankCallbackFunc in_pfnBankCallback, void* in_pCookie, AkBankID* out_bankID);
//typedef AKRESULT(__cdecl* tLoadBank_Char_MemPoolID)(const char* in_pszString, AkMemPoolId in_memPoolId, AkBankID* out_bankID);
//typedef AKRESULT(__cdecl* tLoadBank_Char_Callback)(const char* in_pszString, AkBankCallbackFunc in_pfnBankCallback, void* in_pCookie, AkMemPoolId in_memPoolId, AkBankID* out_bankId);
typedef AkPlayingID(__cdecl* tPostEvent_Char)(const char* in_pszEventName, AkGameObjectID in_gameObjectID, AkUInt32 in_uFlags, AkCallbackFunc in_pfnCallback, void* in_pCookie, AkUInt32 in_cExternals, AkExternalSourceInfo* in_pExternalSources, AkPlayingID in_PlayingID);
//typedef AkPlayingID(__cdecl* tPostEvent_UniqueID)(AkUniqueID in_eventID, AkGameObjectID in_gameObjectID, AkUInt32 in_uFlags, AkCallbackFunc in_pfnCallback, void* in_pCookie, AkUInt32 in_cExternals, AkExternalSourceInfo* in_pExternalSources, AkPlayingID in_PlayingID);
//typedef AKRESULT(__cdecl* tPostTrigger_TriggerID)(AkTriggerID in_triggerID, AkGameObjectID in_gameObjectID);
//typedef AKRESULT(__cdecl* tPostTrigger_Char)(char* in_szTriggerName, AkGameObjectID in_gameObjectID);
//typedef AKRESULT(__cdecl* tPrepareBank_BankID_Callback)(PreparationType in_PreparationType, AkBankID in_bankID, AkBankCallbackFunc in_pfnBankCallback, void* in_pCookie, AkBankContent in_uFlags);
//typedef AKRESULT(__cdecl* tPrepareBank_BankID_BankContent)(PreparationType in_PreparationType, AkBankID in_bankID, AkBankContent in_uFlags);
//typedef AKRESULT(__cdecl* tPrepareBank_Char_Callback)(PreparationType in_PreparationType, const char* in_pszString, AkBankCallbackFunc in_pfnBankCallback, void* in_pCookie, AkBankContent in_uFlags);
//typedef AKRESULT(__cdecl* tPrepareBank_Char_BankContent)(PreparationType in_PreparationType, const char* in_pszString, AkBankContent in_uFlags);
//typedef AKRESULT(__cdecl* tPrepareEvent_EventID_UInt32)(PreparationType in_PreparationType, AkUniqueID* in_pEventID, AkUInt32 in_uNumEvent);
//typedef AKRESULT(__cdecl* tPrepareEvent_EventID_UInt32_Callback_Void)(PreparationType in_PreparationType, AkUniqueID* in_pEventID, AkUInt32 in_uNumEvent, AkBankCallbackFunc in_pfnBankCallback, void* in_pCookie);
//typedef AKRESULT(__cdecl* tPrepareEvent_Char_UInt32)(PreparationType in_PreparationType, const char** in_ppszString, AkUInt32 in_uNumEvent);
//typedef AKRESULT(__cdecl* tPrepareEvent_Char_UInt32_Callback_Void)(PreparationType in_PreparationType, const char** in_ppszString, AkUInt32 in_uNumEvent, AkBankCallbackFunc in_pfnBankCallback, void* in_pCookie);
//typedef AKRESULT(__cdecl* tPrepareGameSyncs_UInt32_UInt32_UInt32_Callback_Void)(PreparationType in_PreparationType, AkGroupType in_eGameSyncType, AkUInt32 in_GroupID, AkUInt32* in_paGameSyncID, AkUInt32 in_uNumGameSyncs, AkBankCallbackFunc in_pfnBankCallback, void* in_pCookie);
//typedef AKRESULT(__cdecl* tPrepareGameSyncs_UInt32_UInt32_UInt32)(PreparationType in_PreparationType, AkGroupType in_eGameSyncType, AkUInt32 in_GroupID, AkUInt32* in_paGameSyncID, AkUInt32 in_uNumGameSyncs);
//typedef AKRESULT(__cdecl* tPrepareGameSyncs_Char_Char_UInt32_Callback_Void)(PreparationType in_PreparationType, AkGroupType in_eGameSyncType, const char* in_pszGroupName, const char** in_ppszGameSyncName, AkUInt32 in_uNumGameSyncs, AkBankCallbackFunc in_pfnBankCallback, void* in_pCookie);
//typedef AKRESULT(__cdecl* tPrepareGameSyncs_Char_Char_UInt32)(PreparationType in_PreparationType, AkGroupType in_eGameSyncType, const char* in_pszGroupName, const char** in_ppszGameSyncName, AkUInt32 in_uNumGameSyncs);
//// Query
//typedef AKRESULT(__cdecl* tQuery_GetActiveGameObjects)(AkGameObjectsList* io_GameObjectList);
//typedef AKRESULT(__cdecl* tQuery_GetActiveListeners)(AkGameObjectID in_GameObjectID, AkUInt32* out_ruListenerMask);
//typedef AKRESULT(__cdecl* tQuery_GetCustomPropertyValue_Int32)(AkUniqueID in_ObjectID, AkUInt32 in_uPropID, AkInt32* out_iValue);
//typedef AKRESULT(__cdecl* tQuery_GetCustomPropertyValue_Real32)(AkUniqueID in_ObjectID, AkUInt32 in_uPropID, AkReal32* out_fValue);
//typedef AkUniqueID(__cdecl* tQuery_GetEventIDFromPlayingID)(AkPlayingID in_playingID);
//typedef AKRESULT(__cdecl* tQuery_GetGameObjectAuxSendValues)(AkGameObjectID in_gameObjectID, AkAuxSendValue* out_paAuxSendValues, AkUInt32* io_ruNumSendValues);
//typedef AKRESULT(__cdecl* tQuery_GetGameObjectDryLevelValue)(AkGameObjectID in_gameObjectID, AkReal32* out_rfControlValue);
//typedef AkGameObjectID(__cdecl* tQuery_GetGameObjectFromPlayingID)(AkPlayingID in_playingID);
//typedef bool(__cdecl* tQuery_GetIsGameObjectActive)(AkGameObjectID in_GameObjId);
//typedef AKRESULT(__cdecl* tQuery_GetListenerPosition)(AkUInt32 in_uIndex, AkListenerPosition* out_rPosition);
//typedef AKRESULT(__cdecl* tQuery_GetMaxRadius_RadiusList)(AkRadiusList* io_RadiusList);
//typedef AKRESULT(__cdecl* tQuery_GetMaxRadius_GameObject)(AkGameObjectID in_GameObjId);
//typedef AKRESULT(__cdecl* tQuery_GetObjectObstructionAndOcclusion)(AkGameObjectID in_ObjectID, AkUInt32 in_uListener, AkReal32* out_rfObstructionLevel, AkReal32* out_rfOcclusionLevel);
//typedef AKRESULT(__cdecl* tQuery_GetPlayingIDsFromGameObject)(AkGameObjectID in_GameObjId, AkUInt32* io_ruNumIds, AkPlayingID* out_aPlayingIDs);
//typedef AKRESULT(__cdecl* tQuery_GetPosition)(AkGameObjectID in_GameObjectID, AkSoundPosition* out_rPosition);
//typedef AKRESULT(__cdecl* tQuery_GetPositioningInfo)(AkUniqueID in_ObjectID, AkPositioningInfo* out_rPositioningInfo);
typedef AKRESULT(__cdecl* tQuery_GetRTPCValue_Char)(const char* in_pszRtpcName, AkGameObjectID in_gameObjectID, AkRtpcValue* out_rValue, RTPCValue_type* io_rValueType);
//typedef AKRESULT(__cdecl* tQuery_GetRTPCValue_RTPCID)(AkRtpcID in_rtpcID, AkGameObjectID in_gameObjectID, AkRtpcValue* out_rValue, RTPCValue_type* io_rValueType);
//typedef AKRESULT(__cdecl* tQuery_GetState_StateGroupID)(AkStateGroupID in_stateGroup, AkStateID* out_rState);
//typedef AKRESULT(__cdecl* tQuery_GetState_Char)(const char* in_pstrStateGroupName, AkStateID* out_rState);
//typedef AKRESULT(__cdecl* tQuery_GetSwitch_SwitchGroupID)(AkSwitchGroupID in_switchGroup, AkGameObjectID in_gameObjectID, AkSwitchStateID* out_rSwitchState);
//typedef AKRESULT(__cdecl* tQuery_GetSwitch_Char)(const char* in_pstrSwitchGroupName, AkGameObjectID in_GameObj, AkSwitchStateID* out_rSwitchState);
//typedef AKRESULT(__cdecl* tQuery_QueryAudioObjectIDs_UniqueID)(AkUniqueID in_eventID, AkUInt32* io_ruNumItems, AkObjectInfo* out_aObjectInfos);
typedef AKRESULT(__cdecl* tQuery_QueryAudioObjectIDs_Char)(const char* in_pszEventName, AkUInt32* io_ruNumItems, AkObjectInfo* out_aObjectInfos);
//// End Query
//typedef AKRESULT(__cdecl* tRegisterCodec)(AkUInt32 in_ulCompanyID, AkUInt32 in_ulCodecID, AkCreateFileSourceCallback in_pFileCreateFunc, AkCreateBankSourceCallback in_pBankCreateFunc);
//typedef AKRESULT(__cdecl* tRegisterGlobalCallback)(AkGlobalCallbackFunc in_pCallback);
//typedef AKRESULT(__cdecl* tRegisterPlugin)(AkPluginType in_eType, AkUInt32 in_ulCompanyID, AkUInt32 in_ulPluginID, AkCreatePluginCallback in_pCreateFunc, AkCreateParamCallback in_pCreateParamFunc);
//typedef AKRESULT(__cdecl* tRenderAudio)(void);
//typedef AKRESULT(__cdecl* tSetActiveListeners)(AkGameObjectID in_gameObjectID, AkUInt32 in_uiListenerMask);
typedef AKRESULT(__cdecl* tSetActorMixerEffect)(AkUniqueID in_audioNodeID, AkUInt32 in_uFXIndex, AkUniqueID in_shareSetID);
//typedef AKRESULT(__cdecl* tSetAttenuationScalingFactor)(AkGameObjectID in_GameObjectID, AkReal32 in_fAttenuationScalingFactor);
//typedef AKRESULT(__cdecl* tSetBankLoadIOSettings)(AkReal32 in_fThroughput, AkPriority in_priority);
//typedef AKRESULT(__cdecl* tSetBusEffect_UniqueID)(AkUniqueID in_audioNodeID, AkUInt32 in_uFXIndex, AkUniqueID in_shareSetID);
//typedef AKRESULT(__cdecl* tSetBusEffect_Char)(const char* in_pszBusName, AkUInt32 in_uFXIndex, AkUniqueID in_shareSetID);
//typedef AKRESULT(__cdecl* tSetGameObjectAuxSendValues)(AkGameObjectID in_gameObjectID, AkAuxSendValue* in_aAuxSendValues, AkUInt32 in_uNumSendValues);
//typedef AKRESULT(__cdecl* tSetGameObjectOutputBusVolume)(AkGameObjectID in_gameObjectID, AkReal32 in_fControlValue);
//typedef AKRESULT(__cdecl* tSetListenerPipeline)(AkUInt32 in_uIndex, bool in_bAudio, bool in_bMotion);
//typedef AKRESULT(__cdecl* tSetListenerPosition)(const AkListenerPosition* in_rPosition, AkUInt32 in_uiIndex);
//typedef AKRESULT(__cdecl* tSetListenerScalingFactor)(AkUInt32 in_uiIndex, AkReal32 in_fAttenuationScalingFactor);
//typedef AKRESULT(__cdecl* tSetListenerSpatialization)(AkUInt32 in_uIndex, bool in_bSpatialized, AkChannelConfig in_channelConfig, VectorPtr in_pVolumeOffsets);
//typedef AKRESULT(__cdecl* tSetMaxNumVoicesLimit)(AkUInt16 in_maxNumberVoices);
//typedef AKRESULT(__cdecl* tSetMultiplePositions)(AkGameObjectID in_GameObjectID, const AkSoundPosition* in_pPositions, AkUInt16 in_NumPositions, MultiPositionType in_eMultiPositionType);
//typedef AKRESULT(__cdecl* tSetObjectObstructionAndOcclusion)(AkGameObjectID in_ObjectID, AkUInt32 in_uListener, AkReal32 in_fObstructionLevel, AkReal32 in_fOcclusionLevel);
//typedef AKRESULT(__cdecl* tSetPanningRule)(AkPanningRule in_ePanningRule, AkAudioOutputType in_eSinkType, AkUInt32 in_iOutputID);
//typedef AKRESULT(__cdecl* tSetPosition)(AkGameObjectID in_GameObjectID, const AkSoundPosition* in_Position);
//typedef AKRESULT(__cdecl* tSetRTPCValue_RTPCID)(AkRtpcID in_rtpcID, AkRtpcValue in_value, AkGameObjectID in_gameObjectID, AkTimeMs in_uValueChangeDuration, AkCurveInterpolation in_eFadeCruve, bool in_bBypassInternalValueInterpolation);
typedef AKRESULT(__cdecl* tSetRTPCValue_Char) (const char* in_pszRtpcName, AkRtpcValue in_value, AkGameObjectID in_gameObjectID, AkTimeMs in_uValueChangeDuration, AkCurveInterpolation in_eFadeCurve);
//typedef AKRESULT(__cdecl* tSetState_StateGroupID)(AkStateGroupID in_stateGroup, AkStateID in_state);
//typedef AKRESULT(__cdecl* tSetState_Char)(const char* in_pszStateGroup, const char* in_pszState);
//typedef AKRESULT(__cdecl* tSetSwitch_SwitchGroupID)(AkSwitchGroupID in_switchGroup, AkSwitchStateID in_switchState, AkGameObjectID in_gameObjectID);
//typedef AKRESULT(__cdecl* tSetSwitch_Char)(const char* in_pszSwitchGroup, const char* in_pszSwitchState, AkGameObjectID in_gameObjectID);
//typedef AKRESULT(__cdecl* tSetVolumeThreshold)(AkReal32 in_fVolumeThresholdDB);
//typedef AKRESULT(__cdecl* tStartOutputCapture)(const AkOSChar* in_CaptureFileName);
//typedef void(__cdecl* tStopAll)(AkGameObjectID in_gameObjectID);
//typedef AKRESULT(__cdecl* tStopOutputCapture)(void);
//typedef AKRESULT(__cdecl* tStopPlayingID)(AkPlayingID in_playingID, AkTimeMs in_uTransitionDuration, AkCurveInterpolation in_eFadeCurve);
//typedef AKRESULT(__cdecl* tTerm)(void);
//typedef AKRESULT(__cdecl* tUnloadBank_BankID_MemPoolID)(AkBankID in_bankID, const void* in_pInMemoryBankPtr, AkMemPoolId* out_pMemPoolId);
//typedef AKRESULT(__cdecl* tUnloadBank_BankID_Callback)(AkBankID in_bankID, const void* in_pInMemoryBankPtr, AkBankCallbackFunc in_pfnBankCallback, void* in_pCookie);
//typedef AKRESULT(__cdecl* tUnloadBank_Char_MemPoolID)(const char* in_pszString, const void* in_pInMemoryBankPtr, AkMemPoolId* out_pMemPoolId);
//typedef AKRESULT(__cdecl* tUnloadBank_Char_Callback)(const char* in_pszString, const void* in_pInMemoryBankPtr, AkBankCallbackFunc in_pfnBankCallback, void* in_pCookie);
//typedef AKRESULT(__cdecl* tUnregisterAllGameObj)(void);
//typedef AKRESULT(__cdecl* tUnregisterGameObj)(AkGameObjectID in_gameObjectID);
//typedef AKRESULT(__cdecl* tUnregisterGlobalCallback)(AkGlobalCallbackFunc in_pCallback);
//// End Sound Engine
//// StreamMgr
//// This Section has way too many dependancies for us to really use it.
//// End StreamMgr
//// End WWise Documentation
//
//// Rocksmith Custom Wwise Functions | These will use vague types since that's all I can get out of Ghidra
//// AddBehavioralExtension (Custom | Can't be added because a param requires a function)
//typedef AkUInt32(__cdecl* tCloneActorMixerEffect)(AkUInt32 param_1, AkUInt32 param_2, AkUInt32 param_3);
//typedef AkUInt32(__cdecl* tCloneBusEffect)(AkUInt32 param_1, AkUInt32 param_2, AkUInt32 param_3);
//typedef AKRESULT(__cdecl* tLoadBankUnique)(const char* in_pszString, AkBankCallbackFunc in_pfnBankCallback, void* in_pCookie, AkMemPoolId in_memPoolId, AkBankID* out_bankId);
//typedef AkUInt32(__cdecl* tPlaySourcePlugin)(AkUInt32 param_1, AkUInt32 param_2, AkUInt32 param_3);
//// RegisterBusVolumeCallback (Custom | Can't be added because a param requires a function)
//typedef AKRESULT(__cdecl* tRegisterGameObj)(AkGameObjectID in_gameObjectID);
//typedef AKRESULT(__cdecl* tResetRTPCValue_RTPCID)(AkRtpcID in_rtpcID, UINT param_2, long param_3, AkCurveInterpolation in_curveInterpolation);
//typedef AKRESULT(__cdecl* tResetRTPCValue_Char)(const char* in_pszRtpcName, UINT param_2, long param_3, AkCurveInterpolation in_curveInterpolation);
//typedef AKRESULT(__cdecl* tSeekOnEvent_UniqueID_Int32)(AkUniqueID in_eventID, AkGameObjectID in_gameObjectID, AkTimeMs in_iPosition, bool in_bSeekToNearestMarker);
typedef AKRESULT(__cdecl* tSeekOnEvent_Char_Int32)(const char* in_pszEventName, AkGameObjectID in_gameObjectID, AkTimeMs in_iPosition, bool in_bSeekToNearestMarker);
//typedef AKRESULT(__cdecl* tSeekOnEvent_UniqueID_Float)(AkUniqueID in_eventID, AkGameObjectID in_gameObjectID, AkReal32 in_iPosition, bool in_bSeekToNearestMarker);
//typedef AKRESULT(__cdecl* tSeekOnEvent_Char_Float)(const char* in_pszEventName, AkGameObjectID in_gameObjectID, AkReal32 in_iPosition, bool in_bSeekToNearestMarker);
//typedef AKRESULT(__cdecl* tSetEffectParam)(AkUInt32 param_1, short param_2, void* in_pCookie);
//typedef AKRESULT(__cdecl* tSetPositionInternal)(AkGameObjectID in_GameObjectID, AkSoundPosition* in_soundPosition);
//typedef AKRESULT(__cdecl* tStopSourcePlugin)(AkUInt32 param_1, AkUInt32 param_2, AkUInt32 param_3);
//typedef AKRESULT(__cdecl* tUnloadBankUnique)(const char* in_pszString, AkBankCallbackFunc in_pfnBankCallback, void* in_pCookie);
//// End Rocksmith Custom Wwise Functions
//
//// Rocksmith Function Hijack
//
//typedef void(__stdcall* tRegisterAllPlugins)(void);
//typedef void(__cdecl* tSetAudioInputCallbacks)(AkAudioInputPluginExecuteCallbackFunc* execute, AkAudioInputPluginGetFormatCallbackFunc* format, AkAudioInputPluginGetGainCallbackFunc* gain, int* normallyReturnsOne);

//// End Rocksmith Function Hijack

/* Types To Variables (External Use) */

namespace WwiseVariables {
	/* Offsets For Functions */

	// Wwise Hijack
	extern uintptr_t func_Wwise_Root_IsRestoreSinkRequested;
	extern uintptr_t func_Wwise_Root_IsUsingDummySink;
	// IAkStreamMgr;
	extern uintptr_t func_Wwise_IAkStreamMgr_m_pStreamMgr;
	// MemoryMgr;
	extern uintptr_t func_Wwise_Memory_CheckPoolId;
	extern uintptr_t func_Wwise_Memory_CreatePool;
	extern uintptr_t func_Wwise_Memory_DestroyPool;
	extern uintptr_t func_Wwise_Memory_Falign;
	extern uintptr_t func_Wwise_Memory_GetBlock;
	extern uintptr_t func_Wwise_Memory_GetBlockSize;
	extern uintptr_t func_Wwise_Memory_GetMaxPools;
	extern uintptr_t func_Wwise_Memory_GetNumPools;
	extern uintptr_t func_Wwise_Memory_GetPoolAttributes;
	extern uintptr_t func_Wwise_Memory_GetPoolMemoryUsed;
	extern uintptr_t func_Wwise_Memory_GetPoolName;
	extern uintptr_t func_Wwise_Memory_GetPoolStats;
	extern uintptr_t func_Wwise_Memory_IsInitialized;
	extern uintptr_t func_Wwise_Memory_Malign;
	extern uintptr_t func_Wwise_Memory_Malloc;
	extern uintptr_t func_Wwise_Memory_ReleaseBlock;
	extern uintptr_t func_Wwise_Memory_SetMonitoring;
	extern uintptr_t func_Wwise_Memory_SetPoolName;
	extern uintptr_t func_Wwise_Memory_Term;
	// Monitor
	extern uintptr_t func_Wwise_Monitor_PostCode;
	// Motion Engine;
	extern uintptr_t func_Wwise_Motion_AddPlayerMotionDevice;
	extern uintptr_t func_Wwise_Motion_RegisterMotionDevice;
	extern uintptr_t func_Wwise_Motion_RemovePlayerMotionDevice;
	extern uintptr_t func_Wwise_Motion_SetPlayerListener;
	extern uintptr_t func_Wwise_Motion_SetPlayerVolume;
	// Music Engine;
	extern uintptr_t func_Wwise_Music_GetDefaultInitSettings;
	extern uintptr_t func_Wwise_Music_GetPlayingSegmentInfo;
	extern uintptr_t func_Wwise_Music_Init;
	extern uintptr_t func_Wwise_Music_Term;
	// Sound Engine;
	extern uintptr_t func_Wwise_Sound_AddBehaviorExtension;
	extern uintptr_t func_Wwise_Sound_CancelBankCallbackCookie;
	extern uintptr_t func_Wwise_Sound_CancelEventCallback;
	extern uintptr_t func_Wwise_Sound_CancelEventCallbackCookie;
	extern uintptr_t func_Wwise_Sound_ClearBanks;
	extern uintptr_t func_Wwise_Sound_ClearPreparedEvents;
	extern uintptr_t func_Wwise_Sound_CloneActorMixerEffect;
	extern uintptr_t func_Wwise_Sound_CloneBusEffect;
	extern uintptr_t func_Wwise_Sound_DynamicDialogue_ResolveDialogueEvent_UniqueID;
	extern uintptr_t func_Wwise_Sound_DynamicDialogue_ResolveDialogueEvent_Char;
	extern uintptr_t func_Wwise_Sound_DynamicSequence_Break;
	extern uintptr_t func_Wwise_Sound_DynamicSequence_Close;
	extern uintptr_t func_Wwise_Sound_DynamicSequence_LockPlaylist;
	extern uintptr_t func_Wwise_Sound_DynamicSequence_Open;
	extern uintptr_t func_Wwise_Sound_DynamicSequence_Pause;
	extern uintptr_t func_Wwise_Sound_DynamicSequence_Play;
	extern uintptr_t func_Wwise_Sound_DynamicSequence_Resume;
	extern uintptr_t func_Wwise_Sound_DynamicSequence_Stop;
	extern uintptr_t func_Wwise_Sound_DynamicSequence_UnlockPlaylist;
	extern uintptr_t func_Wwise_Sound_ExecuteActionOnEvent_UniqueID;
	extern uintptr_t func_Wwise_Sound_ExecuteActionOnEvent_Char;
	extern uintptr_t func_Wwise_Sound_g_PlayingID;
	extern uintptr_t func_Wwise_Sound_GetDefaultInitSettings;
	extern uintptr_t func_Wwise_Sound_GetDefaultPlatformInitSettings;
	extern uintptr_t func_Wwise_Sound_GetIDFromString;
	extern uintptr_t func_Wwise_Sound_GetPanningRule;
	extern uintptr_t func_Wwise_Sound_GetSourcePlayPosition;
	extern uintptr_t func_Wwise_Sound_GetSpeakerConfiguration;
	extern uintptr_t func_Wwise_Sound_Init;
	extern uintptr_t func_Wwise_Sound_IsInitialized;
	extern uintptr_t func_Wwise_Sound_LoadBank_BankID_MemPoolID;
	extern uintptr_t func_Wwise_Sound_LoadBank_Void_UInt32_BankID;
	extern uintptr_t func_Wwise_Sound_LoadBank_BankID_Callback;
	extern uintptr_t func_Wwise_Sound_LoadBank_Void_UInt32_Callback;
	extern uintptr_t func_Wwise_Sound_LoadBank_Char_MemPoolID;
	extern uintptr_t func_Wwise_Sound_LoadBank_Char_Callback;
	extern uintptr_t func_Wwise_Sound_LoadBankUnique;
	extern uintptr_t func_Wwise_Sound_PlaySourcePlugin;
	extern uintptr_t func_Wwise_Sound_PostEvent_Char;
	extern uintptr_t func_Wwise_Sound_PostEvent_UniqueID;
	extern uintptr_t func_Wwise_Sound_PostTrigger_TriggerID;
	extern uintptr_t func_Wwise_Sound_PostTrigger_Char;
	extern uintptr_t func_Wwise_Sound_PrepareBank_BankID_Callback;
	extern uintptr_t func_Wwise_Sound_PrepareBank_BankID_BankContent;
	extern uintptr_t func_Wwise_Sound_PrepareBank_Char_Callback;
	extern uintptr_t func_Wwise_Sound_PrepareBank_Char_BankContent;
	extern uintptr_t func_Wwise_Sound_PrepareEvent_EventID_UInt32;
	extern uintptr_t func_Wwise_Sound_PrepareEvent_EventID_UInt32_Callback_Void;
	extern uintptr_t func_Wwise_Sound_PrepareEvent_Char_UInt32;
	extern uintptr_t func_Wwise_Sound_PrepareEvent_Char_UInt32_Callback_Void;
	extern uintptr_t func_Wwise_Sound_PrepareGameSyncs_UInt32_UInt32_UInt32_Callback_Void;
	extern uintptr_t func_Wwise_Sound_PrepareGameSyncs_UInt32_UInt32_UInt32;
	extern uintptr_t func_Wwise_Sound_PrepareGameSyncs_Char_Char_UInt32_Callback_Void;
	extern uintptr_t func_Wwise_Sound_PrepareGameSyncs_Char_Char_UInt32;
	extern uintptr_t func_Wwise_Sound_Query_GetActiveGameObjects;
	extern uintptr_t func_Wwise_Sound_Query_GetActiveListeners;
	extern uintptr_t func_Wwise_Sound_Query_GetCustomPropertyValue_Int32;
	extern uintptr_t func_Wwise_Sound_Query_GetCustomPropertyValue_Real32;
	extern uintptr_t func_Wwise_Sound_Query_GetEventIDFromPlayingID;
	extern uintptr_t func_Wwise_Sound_Query_GetGameObjectAuxSendValues;
	extern uintptr_t func_Wwise_Sound_Query_GetGameObjectDryLevelValue;
	extern uintptr_t func_Wwise_Sound_Query_GetGameObjectFromPlayingID;
	extern uintptr_t func_Wwise_Sound_Query_GetIsGameObjectActive;
	extern uintptr_t func_Wwise_Sound_Query_GetListenerPosition;
	extern uintptr_t func_Wwise_Sound_Query_GetListenerSpatialization;
	extern uintptr_t func_Wwise_Sound_Query_GetMaxRadius_RadiusList;
	extern uintptr_t func_Wwise_Sound_Query_GetMaxRadius_GameObject;
	extern uintptr_t func_Wwise_Sound_Query_GetObjectObstructionAndOcclusion;
	extern uintptr_t func_Wwise_Sound_Query_GetPlayingIDsFromGameObject;
	extern uintptr_t func_Wwise_Sound_Query_GetPosition;
	extern uintptr_t func_Wwise_Sound_Query_GetPositioningInfo;
	extern uintptr_t func_Wwise_Sound_Query_GetRTPCValue_RTPCID;
	extern uintptr_t func_Wwise_Sound_Query_GetRTPCValue_Char;
	extern uintptr_t func_Wwise_Sound_Query_GetState_StateGroupID;
	extern uintptr_t func_Wwise_Sound_Query_GetState_Char;
	extern uintptr_t func_Wwise_Sound_Query_GetSwitch_SwitchGroupID;
	extern uintptr_t func_Wwise_Sound_Query_GetSwitch_Char;
	extern uintptr_t func_Wwise_Sound_Query_QueryAudioObjectIDs_UniqueID;
	extern uintptr_t func_Wwise_Sound_Query_QueryAudioObjectIDs_Char;
	extern uintptr_t func_Wwise_Sound_RegisterBusVolumeCallback;
	extern uintptr_t func_Wwise_Sound_RegisterCodec;
	extern uintptr_t func_Wwise_Sound_RegisterGameObj;
	extern uintptr_t func_Wwise_Sound_RegisterGlobalCallback;
	extern uintptr_t func_Wwise_Sound_RegisterPlugin;
	extern uintptr_t func_Wwise_Sound_RemoveBehavioralExtension;
	extern uintptr_t func_Wwise_Sound_RenderAudio;
	extern uintptr_t func_Wwise_Sound_ResetRTPCValue_RTPCID;
	extern uintptr_t func_Wwise_Sound_ResetRTPCValue_Char;
	extern uintptr_t func_Wwise_Sound_SeekOnEvent_UniqueID_Int32;
	extern uintptr_t func_Wwise_Sound_SeekOnEvent_Char_Int32;
	extern uintptr_t func_Wwise_Sound_SeekOnEvent_UniqueID_Float;
	extern uintptr_t func_Wwise_Sound_SeekOnEvent_Char_Float;
	extern uintptr_t func_Wwise_Sound_SetActiveListeners;
	extern uintptr_t func_Wwise_Sound_SetActorMixerEffect;
	extern uintptr_t func_Wwise_Sound_SetAttenuationScalingFactor;
	extern uintptr_t func_Wwise_Sound_SetBankLoadIOSettings;
	extern uintptr_t func_Wwise_Sound_SetBusEffect_UniqueID;
	extern uintptr_t func_Wwise_Sound_SetBusEffect_Char;
	extern uintptr_t func_Wwise_Sound_SetEffectParam;
	extern uintptr_t func_Wwise_Sound_SetGameObjectAuxSendValues;
	extern uintptr_t func_Wwise_Sound_SetGameObjectOutputBusVolume;
	extern uintptr_t func_Wwise_Sound_SetListenerPipeline;
	extern uintptr_t func_Wwise_Sound_SetListenerPosition;
	extern uintptr_t func_Wwise_Sound_SetListenerScalingFactor;
	extern uintptr_t func_Wwise_Sound_SetListenerSpatialization;
	extern uintptr_t func_Wwise_Sound_SetMaxNumVoicesLimit;
	extern uintptr_t func_Wwise_Sound_SetMultiplePositions;
	extern uintptr_t func_Wwise_Sound_SetObjectObstructionAndOcclusion;
	extern uintptr_t func_Wwise_Sound_SetPanningRule;
	extern uintptr_t func_Wwise_Sound_SetPosition;
	extern uintptr_t func_Wwise_Sound_SetPositionInternal;
	extern uintptr_t func_Wwise_Sound_SetRTPCValue_RTPCID;
	extern uintptr_t func_Wwise_Sound_SetRTPCValue_Char;
	extern uintptr_t func_Wwise_Sound_SetState_StateGroupID;
	extern uintptr_t func_Wwise_Sound_SetState_Char;
	extern uintptr_t func_Wwise_Sound_SetSwitch_SwitchGroupID;
	extern uintptr_t func_Wwise_Sound_SetSwitch_Char;
	extern uintptr_t func_Wwise_Sound_SetVolumeThreshold;
	extern uintptr_t func_Wwise_Sound_StartOutputCapture;
	extern uintptr_t func_Wwise_Sound_StopAll;
	extern uintptr_t func_Wwise_Sound_StopOutputCapture;
	extern uintptr_t func_Wwise_Sound_StopPlayingID;
	extern uintptr_t func_Wwise_Sound_StopSourcePlugin;
	extern uintptr_t func_Wwise_Sound_Term;
	extern uintptr_t func_Wwise_Sound_UnloadBank_BankID_MemPoolID;
	extern uintptr_t func_Wwise_Sound_UnloadBank_BankID_Callback;
	extern uintptr_t func_Wwise_Sound_UnloadBank_Char_MemPoolID;
	extern uintptr_t func_Wwise_Sound_UnloadBank_Char_Callback;
	extern uintptr_t func_Wwise_Sound_UnloadBankUnique;
	extern uintptr_t func_Wwise_Sound_UnregisterAllGameObj;
	extern uintptr_t func_Wwise_Sound_UnregisterGameObj;
	extern uintptr_t func_Wwise_Sound_UnregisterGlobalCallback;
	// StreamMgr;
	extern uintptr_t func_Wwise_Stream_AddLanguageChangeObserver;
	extern uintptr_t func_Wwise_Stream_Create;
	extern uintptr_t func_Wwise_Stream_CreateDevice;
	extern uintptr_t func_Wwise_Stream_DestroyDevice;
	extern uintptr_t func_Wwise_Stream_FlushAllCaches;
	extern uintptr_t func_Wwise_Stream_GetCurrentLanguage;
	extern uintptr_t func_Wwise_Stream_GetDefaultDeviceSettings;
	extern uintptr_t func_Wwise_Stream_GetDefaultSettings;
	extern uintptr_t func_Wwise_Stream_GetFileLocationResolver;
	extern uintptr_t func_Wwise_Stream_GetPoolID;
	extern uintptr_t func_Wwise_Stream_RemoveLanguageChangeObserver;
	extern uintptr_t func_Wwise_Stream_SetCurrentLanguage;
	extern uintptr_t func_Wwise_Stream_SetFileLocationResolver;

	// Rocksmith Function Hijack
	extern uintptr_t func_Rocksmith_RegisterAllPlugins;
	extern uintptr_t func_Rocksmith_SetAudioInputCallbacks;
	// End Wwise Hijack;

	//// Root Functions;
	//extern tIsRestoreSinkRequested Wwise_Root_IsRestoreSinkRequested;
	//extern 	tIsUsingDummySink Wwise_Root_IsUsingDummySink;

	//// MemoryMgr;
	//extern 	tMemory_CheckPoolId Wwise_Memory_CheckPoolId;
	//extern 	tMemory_CreatePool Wwise_Memory_CreatePool;
	//extern 	tMemory_DestroyPool Wwise_Memory_DestroyPool;
	//extern 	tMemory_Falign Wwise_Memory_Falign;
	//extern 	tMemory_GetBlock Wwise_Memory_GetBlock;
	//extern 	tMemory_GetBlockSize Wwise_Memory_GetBlockSize;
	//extern 	tMemory_GetMaxPools Wwise_Memory_GetMaxPools;
	//extern 	tMemory_GetNumPools Wwise_Memory_GetNumPools;
	//extern 	tMemory_GetPoolAttributes Wwise_Memory_GetPoolAttributes;
	//extern 	tMemory_GetPoolMemoryUsed Wwise_Memory_GetPoolMemoryUsed;
	//extern 	tMemory_GetPoolName Wwise_Memory_GetPoolName;
	//extern 	tMemory_GetPoolStats Wwise_Memory_GetPoolStats;
	//extern 	tMemory_IsInitialized Wwise_Memory_IsInitialized;
	//extern 	tMemory_Malign Wwise_Memory_Malign;
	//extern 	tMemory_Malloc Wwise_Memory_Malloc;
	//extern 	tMemory_ReleaseBlock Wwise_Memory_ReleaseBlock;
	//extern 	tMemory_SetMonitoring Wwise_Memory_SetMonitoring;
	//extern 	tMemory_SetPoolName Wwise_Memory_SetPoolName;
	//extern 	tMemory_Term Wwise_Memory_Term;

	//// Monitor;
	//extern 	tMonitor_PostCode Wwise_Monitor_PostCode;

	//// Motion Engine;
	//extern 	tMotion_AddPlayerMotionDevice Wwise_Motion_AddPlayerMotionDevice;
	//extern 	tMotion_RegisterMotionDevice Wwise_Motion_RegisterMotionDevice;
	//extern 	tMotion_RemovePlayerMotionDevice Wwise_Motion_RemovePlayerMotionDevice;
	//extern 	tMotion_SetPlayerListener Wwise_Motion_SetPlayerListener;
	//extern 	tMotion_SetPlayerVolume Wwise_Motion_SetPlayerVolume;

	//// Music Engine;
	//extern 	tMusic_GetDefaultInitSettings Wwise_Music_GetDefaultInitSettings;
	//extern 	tMusic_GetPlayingSegmentInfo Wwise_Music_GetPlayingSegmentInfo;
	//extern 	tMusic_Init Wwise_Music_Init;
	//extern 	tMusic_Term Wwise_Music_Term;

	//// Sound Engine;
	//extern 	tCancelBankCallbackCookie Wwise_Sound_CancelBankCallbackCookie;
	//extern 	tCancelEventCallback Wwise_Sound_CancelEventCallback;
	//extern 	tCancelEventCallbackCookie Wwise_Sound_CancelEventCallbackCookie;
	//extern 	tClearBanks Wwise_Sound_ClearBanks;
	//extern 	tClearPreparedEvents Wwise_Sound_ClearPreparedEvents;
	//extern 	tDynamicDialogue_ResolveDialogueEvent_UniqueID Wwise_Sound_DynamicDialogue_ResolveDialogueEvent_UniqueID;
	//extern 	tDynamicDialogue_ResolveDialogueEvent_Char Wwise_Sound_DynamicDialogue_ResolveDialogueEvent_Char;
	//extern 	tDynamicSequence_Break Wwise_Sound_DynamicSequence_Break;
	//extern 	tDynamicSequence_Close Wwise_Sound_DynamicSequence_Close;
	//extern 	tDynamicSequence_LockPlaylist Wwise_Sound_DynamicSequence_LockPlaylist;
	//extern 	tDynamicSequence_Open Wwise_Sound_DynamicSequence_Open;
	//extern 	tDynamicSequence_Pause Wwise_Sound_DynamicSequence_Pause;
	//extern 	tDynamicSequence_Play Wwise_Sound_DynamicSequence_Play;
	//extern 	tDynamicSequence_Resume Wwise_Sound_DynamicSequence_Resume;
	//extern 	tDynamicSequence_Stop Wwise_Sound_DynamicSequence_Stop;
	//extern 	tDynamicSequence_UnlockPlaylist Wwise_Sound_DynamicSequence_UnlockPlaylist;
	//extern 	tExecuteActionOnEvent_UniqueID Wwise_Sound_ExecuteActionOnEvent_UniqueID;
	//extern 	tExecuteActionOnEvent_Char Wwise_Sound_ExecuteActionOnEvent_Char;
	//extern 	tGetDefaultInitSettings Wwise_Sound_GetDefaultInitSettings;
	//extern 	tGetDefaultPlatformInitSettings Wwise_Sound_GetDefaultPlatformInitSettings;
	//extern 	tGetIDFromString Wwise_Sound_GetIDFromString;
	//extern 	tGetPanningRule Wwise_Sound_GetPanningRule;
	//extern 	tGetSourcePlayPosition Wwise_Sound_GetSourcePlayPosition;
	//extern 	tGetSpeakerConfiguration Wwise_Sound_GetSpeakerConfiguration;
	//extern 	tInit Wwise_Sound_Init;
	//extern 	tIsInitialized Wwise_Sound_IsInitialized;
	//extern 	tLoadBank_BankID_MemPoolID Wwise_Sound_LoadBank_BankID_MemPoolID;
	//extern 	tLoadBank_Void_UInt32_BankID Wwise_Sound_LoadBank_Void_UInt32_BankID;
	//extern 	tLoadBank_BankID_Callback Wwise_Sound_LoadBank_BankID_Callback;
	//extern 	tLoadBank_Void_UInt32_Callback Wwise_Sound_LoadBank_Void_UInt32_Callback;
	//extern 	tLoadBank_Char_MemPoolID Wwise_Sound_LoadBank_Char_MemPoolID;
	//extern 	tLoadBank_Char_Callback Wwise_Sound_LoadBank_Char_Callback;
	extern 	tPostEvent_Char Wwise_Sound_PostEvent_Char;
	//extern 	tPostEvent_UniqueID Wwise_Sound_PostEvent_UniqueID;
	//extern 	tPostTrigger_TriggerID Wwise_Sound_PostTrigger_TriggerID;
	//extern 	tPostTrigger_Char Wwise_Sound_PostTrigger_Char;
	//extern 	tPrepareBank_BankID_Callback Wwise_Sound_PrepareBank_BankID_Callback;
	//extern 	tPrepareBank_BankID_BankContent Wwise_Sound_PrepareBank_BankID_BankContent;
	//extern 	tPrepareBank_Char_Callback Wwise_Sound_PrepareBank_Char_Callback;
	//extern 	tPrepareBank_Char_BankContent Wwise_Sound_PrepareBank_Char_BankContent;
	//extern 	tPrepareEvent_EventID_UInt32 Wwise_Sound_PrepareEvent_EventID_UInt32;
	//extern 	tPrepareEvent_EventID_UInt32_Callback_Void Wwise_Sound_PrepareEvent_EventID_UInt32_Callback_Void;
	//extern 	tPrepareEvent_Char_UInt32 Wwise_Sound_PrepareEvent_Char_UInt32;
	//extern 	tPrepareEvent_Char_UInt32_Callback_Void Wwise_Sound_PrepareEvent_Char_UInt32_Callback_Void;
	//extern 	tPrepareGameSyncs_UInt32_UInt32_UInt32_Callback_Void Wwise_Sound_PrepareGameSyncs_UInt32_UInt32_UInt32_Callback_Void;
	//extern 	tPrepareGameSyncs_UInt32_UInt32_UInt32 Wwise_Sound_PrepareGameSyncs_UInt32_UInt32_UInt32;
	//extern 	tPrepareGameSyncs_Char_Char_UInt32_Callback_Void Wwise_Sound_PrepareGameSyncs_Char_Char_UInt32_Callback_Void;
	//extern 	tPrepareGameSyncs_Char_Char_UInt32 Wwise_Sound_PrepareGameSyncs_Char_Char_UInt32;
	//extern 	tQuery_GetActiveGameObjects Wwise_Sound_Query_GetActiveGameObjects;
	//extern 	tQuery_GetActiveListeners Wwise_Sound_Query_GetActiveListeners;
	//extern 	tQuery_GetCustomPropertyValue_Int32 Wwise_Sound_Query_GetCustomPropertyValue_Int32;
	//extern 	tQuery_GetCustomPropertyValue_Real32 Wwise_Sound_Query_GetCustomPropertyValue_Real32;
	//extern 	tQuery_GetEventIDFromPlayingID Wwise_Sound_Query_GetEventIDFromPlayingID;
	//extern 	tQuery_GetGameObjectAuxSendValues Wwise_Sound_Query_GetGameObjectAuxSendValues;
	//extern 	tQuery_GetGameObjectDryLevelValue Wwise_Sound_Query_GetGameObjectDryLevelValue;
	//extern 	tQuery_GetGameObjectFromPlayingID Wwise_Sound_Query_GetGameObjectFromPlayingID;
	//extern 	tQuery_GetIsGameObjectActive Wwise_Sound_Query_GetIsGameObjectActive;
	//extern 	tQuery_GetListenerPosition Wwise_Sound_Query_GetListenerPosition;
	//extern 	tQuery_GetMaxRadius_RadiusList Wwise_Sound_Query_GetMaxRadius_RadiusList;
	//extern 	tQuery_GetMaxRadius_GameObject Wwise_Sound_Query_GetMaxRadius_GameObject;
	//extern 	tQuery_GetObjectObstructionAndOcclusion Wwise_Sound_Query_GetObjectObstructionAndOcclusion;
	//extern 	tQuery_GetPlayingIDsFromGameObject Wwise_Sound_Query_GetPlayingIDsFromGameObject;
	//extern 	tQuery_GetPosition Wwise_Sound_Query_GetPosition;
	//extern 	tQuery_GetPositioningInfo Wwise_Sound_Query_GetPositioningInfo;
	extern 	tQuery_GetRTPCValue_Char Wwise_Sound_Query_GetRTPCValue_Char;
	//extern 	tQuery_GetRTPCValue_RTPCID Wwise_Sound_Query_GetRTPCValue_RTPCID;
	//extern 	tQuery_GetState_StateGroupID Wwise_Sound_Query_GetState_StateGroupID;
	//extern 	tQuery_GetState_Char Wwise_Sound_Query_GetState_Char;
	//extern 	tQuery_GetSwitch_SwitchGroupID Wwise_Sound_Query_GetSwitch_SwitchGroupID;
	//extern 	tQuery_GetSwitch_Char Wwise_Sound_Query_GetSwitch_Char;
	//extern 	tQuery_QueryAudioObjectIDs_UniqueID Wwise_Sound_Query_QueryAudioObjectIDs_UniqueID;
	extern 	tQuery_QueryAudioObjectIDs_Char Wwise_Sound_Query_QueryAudioObjectIDs_Char;
	//extern 	tRegisterCodec Wwise_Sound_RegisterCodec;
	//extern 	tRegisterGlobalCallback Wwise_Sound_RegisterGlobalCallback;
	//extern 	tRegisterPlugin Wwise_Sound_RegisterPlugin;
	//extern 	tRenderAudio Wwise_Sound_RenderAudio;
	//extern 	tSetActiveListeners Wwise_Sound_SetActiveListeners;
	extern 	tSetActorMixerEffect Wwise_Sound_SetActorMixerEffect;
	//extern 	tSetAttenuationScalingFactor Wwise_Sound_SetAttenuationScalingFactor;
	//extern 	tSetBankLoadIOSettings Wwise_Sound_SetBankLoadIOSettings;
	//extern 	tSetBusEffect_UniqueID Wwise_Sound_SetBusEffect_UniqueID;
	//extern 	tSetBusEffect_Char Wwise_Sound_SetBusEffect_Char;
	//extern 	tSetGameObjectAuxSendValues Wwise_Sound_SetGameObjectAuxSendValues;
	//extern 	tSetGameObjectOutputBusVolume Wwise_Sound_SetGameObjectOutputBusVolume;
	//extern 	tSetListenerPipeline Wwise_Sound_SetListenerPipeline;
	//extern 	tSetListenerPosition Wwise_Sound_SetListenerPosition;
	//extern 	tSetListenerScalingFactor Wwise_Sound_SetListenerScalingFactor;
	//extern 	tSetListenerSpatialization Wwise_Sound_SetListenerSpatialization;
	//extern 	tSetMaxNumVoicesLimit Wwise_Sound_SetMaxNumVoicesLimit;
	//extern 	tSetMultiplePositions Wwise_Sound_SetMultiplePositions;
	//extern 	tSetObjectObstructionAndOcclusion Wwise_Sound_SetObjectObstructionAndOcclusion;
	//extern 	tSetPanningRule Wwise_Sound_SetPanningRule;
	//extern 	tSetPosition Wwise_Sound_SetPosition;
	//extern 	tSetRTPCValue_RTPCID Wwise_Sound_SetRTPCValue_RTPCID;
	extern 	tSetRTPCValue_Char Wwise_Sound_SetRTPCValue_Char;
	//extern 	tSetState_StateGroupID Wwise_Sound_SetState_StateGroupID;
	//extern 	tSetState_Char Wwise_Sound_SetState_Char;
	//extern 	tSetSwitch_SwitchGroupID Wwise_Sound_SetSwitch_SwitchGroupID;
	//extern 	tSetSwitch_Char Wwise_Sound_SetSwitch_Char;
	//extern 	tSetVolumeThreshold Wwise_Sound_SetVolumeThreshold;
	//extern 	tStartOutputCapture Wwise_Sound_StartOutputCapture;
	//extern 	tStopAll Wwise_Sound_StopAll;
	//extern 	tStopOutputCapture Wwise_Sound_StopOutputCapture;
	//extern 	tStopPlayingID Wwise_Sound_StopPlayingID;
	//extern 	tTerm Wwise_Sound_Term;
	//extern 	tUnloadBank_BankID_MemPoolID Wwise_Sound_UnloadBank_BankID_MemPoolID;
	//extern 	tUnloadBank_BankID_Callback Wwise_Sound_UnloadBank_BankID_Callback;
	//extern 	tUnloadBank_Char_MemPoolID Wwise_Sound_UnloadBank_Char_MemPoolID;
	//extern 	tUnloadBank_Char_Callback Wwise_Sound_UnloadBank_Char_Callback;
	//extern 	tUnregisterAllGameObj Wwise_Sound_UnregisterAllGameObj;
	//extern 	tUnregisterGameObj Wwise_Sound_UnregisterGameObj;
	//extern 	tUnregisterGlobalCallback Wwise_Sound_UnregisterGlobalCallback;

	//// Rocksmith Custom Wwise_Sound Functions;

	//extern	tCloneActorMixerEffect Wwise_Sound_CloneActorMixerEffect;
	//extern 	tCloneBusEffect Wwise_Sound_CloneBusEffect;
	//extern 	tLoadBankUnique Wwise_Sound_LoadBankUnique;
	//extern 	tPlaySourcePlugin Wwise_Sound_PlaySourcePlugin;
	//extern 	tRegisterGameObj Wwise_Sound_RegisterGameObj;
	//extern 	tResetRTPCValue_RTPCID Wwise_Sound_ResetRTPCValue_RTPCID;
	//extern 	tResetRTPCValue_Char Wwise_Sound_ResetRTPCValue_Char;
	//extern 	tSeekOnEvent_UniqueID_Int32 Wwise_Sound_SeekOnEvent_UniqueID_Int32;
	//extern 	tSeekOnEvent_UniqueID_Float Wwise_Sound_SeekOnEvent_UniqueID_Float;
	extern 	tSeekOnEvent_Char_Int32 Wwise_Sound_SeekOnEvent_Char_Int32;
	//extern 	tSeekOnEvent_Char_Float Wwise_Sound_SeekOnEvent_Char_Float;
	//extern 	tSetEffectParam Wwise_Sound_SetEffectParam;
	//extern 	tSetPositionInternal Wwise_Sound_SetPositionInternal;
	//extern 	tStopSourcePlugin Wwise_Sound_StopSourcePlugin;
	//extern 	tUnloadBankUnique Wwise_Sound_UnloadBankUnique;

	//// Function Hijack

	//extern  tRegisterAllPlugins Rocksmith_RegisterAllPlugins;
	//extern	tSetAudioInputCallbacks Rocksmith_SetAudioInputCallbacks;
}

#ifdef _WWISE_LOGS
namespace WwiseLogging {
	void hook_log_PostEvent();
	void Setup_log_PostEvent();

	void hook_log_SetRTPCValue();
	void Setup_log_SetRTPCValue();
}
#endif