// DLL Hijack. Do NOT remove this line!
#include "Proxy.hpp"

// DLL Settings
#include "MemHelpers.hpp"
#include "Lib/Detours/detours.h"
#include "Offsets.hpp"
#include "MemUtil.hpp"
#include "Settings.hpp"
#include "Structs.hpp"
#include "Functions.hpp"
#include "D3D/D3D.hpp"
#include "D3D/D3DHooks.hpp"
#include "WwiseHijack.hpp"

// Windows Libraries
#include <process.h>
#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>

// Mods
#include "Mods/Enumeration.hpp"
#include "Mods/CustomSongTitles.hpp"
#include "Mods/CollectColors.hpp"
#include "Mods/GuitarSkeletons.hpp"
#include "Mods/GuitarSpeak.hpp"
#include "Mods/DisableControllers.hpp"
#include "Mods/Midi.hpp"
#include "Mods/VolumeControl.hpp"
#include "Mods/LaunchOnExternalMonitor.hpp"
#include "Mods/VoiceOverControl.hpp"
#include "Mods/RiffRepeater.hpp"
#include "Mods/AudioDevices.hpp"
#include "Mods/TrueTuning.hpp"
#include "Mods/BugPrevention.hpp"

std::vector<std::string> effectQueue;
std::vector<std::string> enabledEffects;

bool takenScreenshotOfThisScreen = false; // Has the user taken a screenshot of their scores in this menu
bool saveNewRRSpeedToFile = false;

// Mixer Values
inline unsigned int currentVolumeIndex = 1; // Mixer volume to change. 0 - Disabled, 1 - Master, 2 - Song, 3 - P1, 4 - P2, 5 - Mic, 6 - VO, 7 - SFX

inline std::vector<std::string> mixerInternalNames = { // Needs to be char* as that's what SetRTPCValue needs.
		{""}, // Disabled (Don't show the user any values)
//		{"Master_Volume"}, // Master Volume
		{"Mixer_Music"}, // Song Volume
//		{"Mixer_Player1"}, // Player 1 Guitar & Bass (both are handled with this singular name)
//		{"Mixer_Player2"}, // Player 2 Guitar & Bass (both are handled with this singular name)
//		{"Mixer_Mic"}, // My Microphone Volume
//		{"Mixer_VO"}, // Rocksmith Dad Voice Over
//		{"Mixer_SFX"}, // Menu SFX Volume
};

inline std::vector<std::string> drawMixerTextName = {
	{""},
//	{"Master Volume: "},
	{"Song Volume: "},
//	{"Player 1 Volume: "},
//	{"Player 2 Volume: "},
//	{"Microphone Volume: "},
//	{"Voice-Over Volume: "},
//	{"SFX Volume: "},
};

// True Tuning Override Values
inline unsigned int currentTrueTuningIndex = 0; //

inline std::vector<float> tuningInternalValue = {
		{440.0000}, //E Standard
		{466.1638}, //Eb Standard
		{493.8833}, //D Standard
		{523.2511}, //C# Standard
		{554.3653}, //C Standard
		{587.3295}, //B Standard
		{622.2540}, //A# Standard
		{659.2551}, //A Standard
		{369.9944}, //G Standard
		{391.9954}, //F# Standard
		{415.3047}, //F Standard
};

inline std::vector<std::string> drawTuningName = {
		{"Perfect unison (P1)"}, // (440.0000); //E
		{"-1 Minor second (m2)"}, // (466.1638); //Eb
		{"-2 Major second (M2)"}, // (493.8833); //D
		{"-3 Minor third (m3)"}, // (523.2511); //C#
		{"-4 Major third (M3)"}, // (554.3653); //C
		{"-5 Perfect fourth (P4)"}, // (587.3295); //B
		{"-6 Diminished fifth (d5)"}, // (622.2540); //A#
		{"-7 Perfect fifth (P5)"}, // (659.2551); //A
		{"+3 Minor third (m3)"}, // (369.9944); //G
		{"+2 Major second (M2)"}, // (391.9954); //F#
		{"+1 Minor second (m2)"}, // (415.3047); //F
};

inline std::string selectedUser = "";
bool drawTone = false;
std::string drawToneName = "";
bool drawSomeStuff = false;
auto drawSomeStuffTime = std::chrono::steady_clock::time_point();
bool Contains(std::string str, const char* key){ return str.find(key) != std::string::npos; }