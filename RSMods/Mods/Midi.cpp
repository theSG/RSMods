#include "Midi.hpp"

// Midi codes should follow this guide: http://fmslogo.sourceforge.net/manual/midi-table.html
namespace Midi {
	std::vector<MIDIOUTCAPSA> midiOutDevices;
	std::vector<MIDIINCAPSA> midiInDevices;
	int SelectedMidiOutDevice = 0, SelectedMidiInDevice = 0, MidiCC = 0, MidiPC = 666;
	unsigned int NumberOfOutPorts, NumberOfInPorts;

	/// <summary>
	/// Startup MIDI processing
	/// </summary>
	void InitMidi() {
		try {
			RtMidiIn midiin;
			std::cout << "Starting MIDI" << std::endl;
		}
		catch (RtMidiError& error) {
			std::cout << "(MIDI) " << error.getMessage() << std::endl;
		}
	}

	/// <summary>
	/// Get all MIDI devices connected.
	/// </summary>
	void GetMidiDeviceNames() {
		NumberOfOutPorts = midiOutGetNumDevs();
		NumberOfInPorts = midiInGetNumDevs();
		for (int device = 0; device < NumberOfOutPorts; device++) {
			MIDIOUTCAPSA temp;
			midiOutGetDevCapsA(device, &temp, sizeof(MIDIOUTCAPSA));
			midiOutDevices.push_back(temp);
		}
		for (int device = 0; device < NumberOfInPorts; device++) {
			MIDIINCAPSA temp;
			midiInGetDevCapsA(device, &temp, sizeof(MIDIINCAPSA));
			midiInDevices.push_back(temp);
		}
	}

	/// <summary>
	/// Look through all MIDI devices to hook the one specified by the user.
	/// </summary>
	/// <param name="ChordsMode"> - Does the user have a pedal with Chorus Mode, and is it being used?</param>
	/// <param name="PedalToUse"> - What pedal is the user using?</param>
	/// <param name="MidiOutDevice"> - Name of MIDI device to send MIDI to.</param>
	/// <param name="MidiInDevice"> - Name of MIDI device to listen to.</param>
	void ReadMidiSettingsFromINI(std::string ChordsMode, int PedalToUse, std::string MidiOutDevice, std::string MidiInDevice) {
		if (ChordsMode == "on") { // Is Chords mode on (only some pedals)
			Digitech::DIGITECH_CHORDS_MODE = true;
			std::cout << "(MIDI) Chords Mode: Enabled" << std::endl;
		}
		
		if (PedalToUse != NULL)
			selectedPedal = supportedPedals.at((PedalToUse - 1) % supportedPedals.size());
		else
			return;

		std::cout << "(MIDI) Pedal To Use: " << selectedPedal.pedalName << std::endl;

		GetMidiDeviceNames();

		FindMidiOutDevices(MidiOutDevice);
		FindMidiInDevices(MidiInDevice);
	}

	void FindMidiOutDevices(std::string deviceToLookFor) {
		for (int device = 0; device < NumberOfOutPorts; device++) {

			std::string deviceName = "";

			// Parse Char Buffer, since the name is a null-terminated string, we need to terminate it ourselves in a string.
			for (int i = 0; i < 32; i++) {
				if (midiOutDevices.at(device).szPname[i] == (char)0)
					break;
				deviceName.push_back(midiOutDevices.at(device).szPname[i]);
			}

			if (deviceName.find(deviceToLookFor) != std::string::npos) {
				std::cout << "(MIDI) Connecting To Midi OUT Device: " << midiOutDevices.at(device).szPname << std::endl;
				SelectedMidiOutDevice = device;
				break;
			}
			else
				std::cout << "(MIDI) Available MIDI OUT device: " << midiOutDevices.at(device).szPname << std::endl;
		}
	}
	void FindMidiInDevices(std::string deviceToLookFor) {
		for (int device = 0; device < NumberOfInPorts; device++) {

			std::string deviceName = "";

			// Parse Char Buffer, since the name is a null-terminated string, we need to terminate it ourselves in a string.
			for (int i = 0; i < 32; i++) {
				if (midiInDevices.at(device).szPname[i] == (char)0)
					break;
				deviceName.push_back(midiInDevices.at(device).szPname[i]);
			}

			if (deviceName.find(deviceToLookFor) != std::string::npos) {
				std::cout << "(MIDI) Connecting To Midi IN Device: " << midiInDevices.at(device).szPname << std::endl;
				SelectedMidiInDevice = device;
				break;
			}
			else
				std::cout << "(MIDI) Available MIDI IN device: " << midiInDevices.at(device).szPname << std::endl;
		}
	}

	bool IsValidMidiMessage(std::vector<unsigned char>* message) {
		size_t messageSize = message->size();

		if (messageSize < 1) // Empty Message
			return false;

		switch (message->at(0)) {
			case MidiCommands::NoteOff:
				if (messageSize != 3) {
					std::cout << "(MIDI IN) Invalid NoteOff" << std::endl;
					return false;
				}
				std::cout << "(MIDI IN) NoteOff. Key = " << (int)message->at(1) << ". Velocity = " << (int)message->at(2) << std::endl;
				break;
			case MidiCommands::NoteOn:
				if (messageSize != 3) {
					std::cout << "(MIDI IN) Invalid NoteOn" << std::endl;
					return false;
				}
				std::cout << "(MIDI IN) NoteOn. Key = " << (int)message->at(1) << ". Velocity = " << (int)message->at(2) << std::endl;
				break;
			case MidiCommands::AfterTouch:
				if (messageSize != 3) {
					std::cout << "(MIDI IN) Invalid AfterTouch" << std::endl;
					return false;
				}
				std::cout << "(MIDI IN) AfterTouch. Key = " << (int)message->at(1) << ". Touch = " << (int)message->at(2) << std::endl;
				break;
			case MidiCommands::CC:
				if (messageSize != 3) {
					std::cout << "(MIDI IN) Invalid CC" << std::endl;
					return false;
				}

				std::cout << "(MIDI IN) CC. Controller# = " << (int)message->at(1) << ". Value = " << std::dec << (int)message->at(2) << std::endl;

				// Current Midi In mod to test | Midi RR Speed > 100%
				RiffRepeater::SetSpeed((message->at(2) * 2), true);
				RiffRepeater::EnableTimeStretch();

				// Midi In Mod already tested | Controlling WAH with expression pedal.
					//WwiseVariables::Wwise_Sound_SetRTPCValue_Char("Pedal_USWah_Auto", 1, 0x1234, 0, AkCurveInterpolation_Linear);
					//WwiseVariables::Wwise_Sound_SetRTPCValue_Char("Pedal_USWah_Auto", 1, AK_INVALID_GAME_OBJECT, 0, AkCurveInterpolation_Linear);
					//WwiseVariables::Wwise_Sound_SetRTPCValue_Char("Pedal_USWah_Sens", ceil((int)message->at(2) / 127.f * 100.f), 0x1234, 0, AkCurveInterpolation_Linear);
					//WwiseVariables::Wwise_Sound_SetRTPCValue_Char("Pedal_USWah_Sens", ceil((int)message->at(2) / 127.f * 100.f), AK_INVALID_GAME_OBJECT, 0, AkCurveInterpolation_Linear);

					//WwiseVariables::Wwise_Sound_SetRTPCValue_Char("Bass_Pedal_BassWah_Auto", 1, 0x1234, 0, AkCurveInterpolation_Linear);
					//WwiseVariables::Wwise_Sound_SetRTPCValue_Char("Bass_Pedal_BassWah_Auto", 1, AK_INVALID_GAME_OBJECT, 0, AkCurveInterpolation_Linear);
					//WwiseVariables::Wwise_Sound_SetRTPCValue_Char("Bass_Pedal_BassWah_Sens", ceil((int)message->at(2) / 127.f * 100.f), 0x1234, 0, AkCurveInterpolation_Linear);
					//WwiseVariables::Wwise_Sound_SetRTPCValue_Char("Bass_Pedal_BassWah_Sens", ceil((int)message->at(2) / 127.f * 100.f), AK_INVALID_GAME_OBJECT, 0, AkCurveInterpolation_Linear);

					//WwiseVariables::Wwise_Sound_SetRTPCValue_Char("Pedal_ModernWah_Auto", 1, 0x1234, 0, AkCurveInterpolation_Linear);
					//WwiseVariables::Wwise_Sound_SetRTPCValue_Char("Pedal_ModernWah_Auto", 1, AK_INVALID_GAME_OBJECT, 0, AkCurveInterpolation_Linear);
					//WwiseVariables::Wwise_Sound_SetRTPCValue_Char("Pedal_ModernWah_Sens", ceil((int)message->at(2) / 127.f * 100.f), 0x1234, 0, AkCurveInterpolation_Linear);
					//WwiseVariables::Wwise_Sound_SetRTPCValue_Char("Pedal_ModernWah_Sens", ceil((int)message->at(2) / 127.f * 100.f), AK_INVALID_GAME_OBJECT, 0, AkCurveInterpolation_Linear);

					//WwiseVariables::Wwise_Sound_SetRTPCValue_Char("Pedal_UKWah_Auto", 1, 0x1234, 0, AkCurveInterpolation_Linear);
					//WwiseVariables::Wwise_Sound_SetRTPCValue_Char("Pedal_UKWah_Auto", 1, AK_INVALID_GAME_OBJECT, 0, AkCurveInterpolation_Linear);
					//WwiseVariables::Wwise_Sound_SetRTPCValue_Char("Pedal_UKWah_Sens", ceil((int)message->at(2) / 127.f * 100.f), 0x1234, 0, AkCurveInterpolation_Linear);
					//WwiseVariables::Wwise_Sound_SetRTPCValue_Char("Pedal_UKWah_Sens", ceil((int)message->at(2) / 127.f * 100.f), AK_INVALID_GAME_OBJECT, 0, AkCurveInterpolation_Linear);
				break;
			case MidiCommands::PC:
				if (messageSize != 2) {
					std::cout << "(MIDI IN) Invalid PC" << std::endl;
					return false;
				}
				std::cout << "(MIDI IN) PC. Instrument# = " << (int)message->at(1) << std::endl;
				break;
			case MidiCommands::Pressure:
				if (messageSize != 2) {
					std::cout << "(MIDI IN) Invalid Pressure" << std::endl;
					return false;
				}
				std::cout << "(MIDI IN) Pressure. Pressure = " << (int)message->at(1) << std::endl;
				break;
			case MidiCommands::PitchBend: // Pitch Bend
				if (messageSize != 3) {
					std::cout << "(MIDI IN) Invalid PitchBend" << std::endl;
					return false;
				}
				std::cout << "(MIDI IN) PitchBend. LSB = " << (int)message->at(1) << ". MSB = " << (int)message->at(2) << std::endl;
				break;
			default:
				if (message->at(0) >= 0xF0) { // System Command
					std::cout << "(MIDI IN) System: ";
					for (int i = 0; i < messageSize; i++) {
						std::cout << (int)message->at(i) << " ";
					}
					std::cout << std::endl;
				}
				else { // Unknown Midi Command
					std::cout << "(MIDI IN) Unknown: ";
					for (int i = 0; i < messageSize; i++) {
						std::cout << (int)message->at(i) << " ";
					}
					std::cout << std::endl;
					return false; 
				}
				break;
		}
		return true;
	}

	void RespondToMidiIn(double deltaTime, std::vector<unsigned char>* message, void* userData) {
		IsValidMidiMessage(message);
	}

	unsigned WINAPI ListenToMidiInThread() {
		RtMidiIn* midiin = new RtMidiIn();

		NumberOfInPorts = midiInGetNumDevs();
		if (NumberOfInPorts == 0) {
			std::cout << "No MIDI IN ports available!" << std::endl;
			delete midiin;
			return -1;
		}

		midiin->openPort(SelectedMidiInDevice);
		midiin->setCallback(&RespondToMidiIn);
		midiin->ignoreTypes(false, false, true);

		while (!D3DHooks::GameClosing) {
			Sleep(50);
		}
		return 0;
	}

	/// <summary>
	/// Send PC to pedal.
	/// </summary>
	/// <param name="programChange"> - Value of PC</param>
	/// <param name="alternativeChannel"> - Channel to use over the default. Mainly used for software pedals.</param>
	/// <returns>Message was sent or not.</returns>
	bool SendProgramChange(char programChange, char alternativeChannel) {
		RtMidiOut* midiout = new RtMidiOut();
		std::vector<unsigned char> message;

		char channel = alternativeChannel == (char)255 ? selectedPedal.PC_Channel : alternativeChannel; // If we want to bypass the PC channel (mainly for software pedals) then alternative channel won't be default.

		if (selectedPedal.pedalName == MidiPedal().pedalName) {
			std::cout << "(MIDI) SendPC: DUMMY PEDAL" << std::endl;
			return false;
		}

		// Check available ports.
		NumberOfOutPorts = midiOutGetNumDevs();
		if (NumberOfOutPorts == 0) {
			std::cout << "No MIDI OUT ports available!" << std::endl;
			delete midiout;
			sendPC = false;
			return false;
		}

		try {
			midiout->openPort(SelectedMidiOutDevice);

			// Send MIDI message
			message.push_back(programChangeStatus + channel); // Say it's a Program Change + channel
			message.push_back(programChange); // What program we changing to?
			midiout->sendMessage(&message);
			std::cout << "Sent Midi Message: PC" << (int)channel << ": " << (int)programChange << std::endl;
		}
		catch (RtMidiError& error) {
			std::cout << "(MIDI) Error: " << error.getMessage() << std::endl;
		}

		// Clean up
		delete midiout;
		sendPC = false;
		lastPC = programChange;
		return true;
	}

	/// <summary>
	/// Send CC to pedal
	/// </summary>
	/// <param name="toePosition"> - Value of CC</param>
	/// <param name="alternativeBank"> - Bank to use over the default one. Mainly used for software pedals.</param>
	/// <param name="alternativeChannel"> - Channel to use over the default. Mainly used for software pedals.</param>
	/// <returns>Message wwas sent or not.</returns>
	bool SendControlChange(char toePosition, char alternativeBank, char alternativeChannel) {
		char bank = alternativeBank == (char)255 ? selectedPedal.CC_Bank : alternativeBank; // If we want to bypass the CC bank (mainly for software pedals) then alternative bank won't be default.
		char channel = alternativeChannel == (char)255 ? selectedPedal.CC_Channel : alternativeChannel; // If we want to bypass the CC channel (mainly for software pedals) then alternative channel won't be default.

		if (selectedPedal.pedalName == MidiPedal().pedalName) {
			std::cout << "(MIDI) SendCC: DUMMY PEDAL" << std::endl;
			return false;
		}

		RtMidiOut* midiout = new RtMidiOut();
		std::vector<unsigned char> message;

		// Check available ports.
		NumberOfOutPorts = midiOutGetNumDevs();
		if (NumberOfOutPorts == 0) {
			std::cout << "No MIDI ports available!" << std::endl;
			delete midiout;
			sendCC = false;
			return false;
		}

		try {
			// Open first available port.
			midiout->openPort(SelectedMidiOutDevice);

			// Send MIDI Message
			message.push_back(controlChangeStatus + channel); // Say it's a Control Change + channel#
			// send backwards
			message.push_back(toePosition); // New Control Value || 0 = off, 127 = on
			message.push_back(bank); // Bank to change

			midiout->sendMessage(&message);
			std::cout << "Sending Midi Message: CC" << (int)channel << ": " << (int)bank << " " << (int)toePosition << std::endl;
		}
		catch (RtMidiError& error) {
			std::cout << "(MIDI) Error: " << error.getMessage() << std::endl;
		}

		// Clean up
		delete midiout;
		sendCC = false;
		lastCC = toePosition;
		return true;
	}

	/// <summary>
	/// Send a command to the pedal to change to a specific setting based on the current song's tuning.
	/// </summary>
	void AutomateTuning() {
		if (!alreadyAutomatedTuningInThisSong) {
			alreadyAutomatedTuningInThisSong = true;

			if (!selectedPedal.supportsDropTuning) {
				std::cout << "Your pedal doesn't support drop tuning." << std::endl;
				return;
			}

			Sleep(1500); // The menu is called when the animation starts. The tuning isn't set at that point, so we need to wait to get the value. This doesn't seem to lag the game.

			int* highestLowestTuning = MemHelpers::GetHighestLowestString();

			int highestTuning = highestLowestTuning[0];
			int lowestTuning = highestLowestTuning[1];

			// Invalid pointer check
			if (highestTuning == 666 && lowestTuning == 666) {
				std::cout << "(MIDI) Unable to read tuning in song." << std::endl;
				return;
			}
			
			delete[] highestLowestTuning;

			int TrueTuning_Hertz = MemHelpers::GetTrueTuning();

			if (TrueTuning_Hertz < 260) // Give some leeway for A220 and it's true tuned offsets
				highestTuning -= 12;
			if (highestTuning - 1 == lowestTuning) highestTuning = lowestTuning; //slightly better 7string workaround
			selectedPedal.autoTuneFunction(highestTuning + tuningOffset, TrueTuning_Hertz);
			std::cout << "(MIDI) Triggered Mod: Automated Tuning (Song)" << std::endl;
		}
	}

	void AutomateTuningOnPreset() {
		if (alreadyAutomatedTuningInThisSong) {

			if (!selectedPedal.supportsDropTuning) {
				std::cout << "Your pedal doesn't support drop tuning." << std::endl;
				return;
			}

			int* highestLowestTuning = MemHelpers::GetHighestLowestString();

			int highestTuning = highestLowestTuning[0];
			int lowestTuning = highestLowestTuning[1];

			// Invalid pointer check
			if (highestTuning == 666 && lowestTuning == 666) {
				std::cout << "(MIDI) Unable to read tuning in song." << std::endl;
				return;
			}

			delete[] highestLowestTuning;

			int TrueTuning_Hertz = MemHelpers::GetTrueTuning();

			if (TrueTuning_Hertz < 260) // Give some leeway for A220 and it's true tuned offsets
				highestTuning -= 12;
			if (highestTuning - 1 == lowestTuning) highestTuning = lowestTuning; //slightly better 7string workaround
			selectedPedal.autoTuneFunction(highestTuning + tuningOffset, TrueTuning_Hertz);
			//std::cout << "(MIDI) Triggered Mod: Automated Tuning on Preset (Song)" << std::endl;
		}
	}

	void AttemptTuningInTuner() {
		if (!alreadyAttemptedTuningInTuner) {
			alreadyAttemptedTuningInTuner = true;

			if (!selectedPedal.supportsDropTuning) {
				std::cout << "(MIDI) Your pedal doesn't support drop tuning." << std::endl;
				return;
			}

			Sleep(2000); // The menu is called when the animation starts. We need to wait for the tuning name to appear in the bottom-right corner so we can read it and get the tuning we need.

			int* highestLowestTuning = MemHelpers::GetHighestLowestString(MemHelpers::GetTuningAtTuner());

			int highestTuning = highestLowestTuning[0];
			int lowestTuning = highestLowestTuning[1];

			// Invalid pointer check
			if (highestTuning == 666 && lowestTuning == 666) {
				std::cout << "(MIDI) Cannot read tuning in tuner. Will attempt to automate tuning once the user is in the song." << std::endl;
				return;
			}

			delete[] highestLowestTuning;

			int TrueTuning_Hertz = MemHelpers::GetTrueTuning();

			// highestLowestTuning accounts for true tuning of A220. Do not add a check for it here.
			if (highestTuning - 1 == lowestTuning) highestTuning = lowestTuning; //slightly better 7string workaround
			selectedPedal.autoTuneFunction(highestTuning + tuningOffset, TrueTuning_Hertz);
			std::cout << "(MIDI) Triggered Mod: Automated Tuning (Tuner)" << std::endl;
			alreadyAutomatedTuningInThisSong = true;
		}
	}

	/// <summary>
	/// Send a command to the pedal to turn off the modifications we did for the current song's tuning, and true-tuning.
	/// </summary>
	void RevertAutomatedTuning() { // Turn off the pedal after we are done with a song.

		if (selectedPedal.pedalName == MidiPedal().pedalName)
			return;

		if (lastPC != 666 || selectedPedal.softwarePedal) { // If the song is in E Standard, and we leave, it tries to use "Bypass +2 OCT Whammy"

			std::cout << "(MIDI) Attmepting to turn off automatic tuning" << std::endl;

			if (selectedPedal.softwarePedal) {
				if (Midi::Software::sentSemitoneInThisSong) {
					if (Midi::Software::sendSemitoneCommand == programChangeStatus)
						SendProgramChange(Midi::Software::semiToneShutoffTrigger);
					else if (Midi::Software::sendSemitoneCommand == controlChangeStatus)
						SendControlChange(Midi::Software::semiToneShutoffTrigger);

					Midi::Software::sentSemitoneInThisSong = false;
				}
				if (Midi::Software::sentTrueTuningInThisSong) {
					if (Midi::Software::sendTrueTuningCommand == programChangeStatus)
						SendProgramChange(Midi::Software::trueTuningShutoffTrigger, Midi::Software::sendTrueTuningChannel);
					else if (Midi::Software::sendTrueTuningCommand == controlChangeStatus)
						SendControlChange(Midi::Software::trueTuningShutoffTrigger, Midi::Software::trueTuningBank, Midi::Software::sendTrueTuningChannel);
				}

				Midi::Software::sentTrueTuningInThisSong = false;
				alreadyAutomatedTuningInThisSong = false;
				alreadyAutomatedTrueTuningInThisSong = false;
				return;
			}
			
			std::map<char, char> activeBypassMap = selectedPedal.activeBypassMap;
			char originalPC = lastPC;

			if (lastPC_TUNING != 0 && lastPC_TUNING != lastPC)  // If the user was in a song that requires a down tune AND true tuning, we use this. Ex: If 6 was 9 (Eb Standard AND A431)
				SendProgramChange(activeBypassMap.find(lastPC_TUNING)->second);

			if (activeBypassMap.find(originalPC) != activeBypassMap.end())
				SendProgramChange(activeBypassMap.find(originalPC)->second); // Send the bypass code to revert back to normal guitar.

			if (lastCC != 0)
				SendControlChange(0); // Reset the expression pedal
		}

		alreadyAutomatedTuningInThisSong = false;
		alreadyAutomatedTrueTuningInThisSong = false;
		lastPC_TUNING = 0;
	}

	/// <summary>
	/// Send PC Value Async
	/// </summary>
	/// <param name="program"> - Value of PC</param>
	/// <param name="shouldWeSendPC"> - Should we stop sending PC values?</param>
	void SendDataToThread_PC(char program, bool shouldWeSendPC) {
		sendPC = shouldWeSendPC;
		dataToSendPC = program;
	}

	/// <summary>
	/// Send CC Value Async
	/// </summary>
	/// <param name="toePosition"> - Value of CC</param>
	/// <param name="shouldWeSendCC"> - Should we stop sending CC values?</param>
	void SendDataToThread_CC(char toePosition, bool shouldWeSendCC) {
		sendCC = shouldWeSendCC;
		dataToSendCC = toePosition;
	}

	/// <summary>
	/// Returns the tuning name based on what the offset is.
	/// </summary>
	/// <param name="offset"> - How far from E standard is the user.</param>
	/// <returns> - Tuning Name</returns>
	std::string GetTuningOffsetName(int offset) {
		switch (offset) {
			case -3: 
				return "G Standard / Drop F (Up)";
				break;
			case -2:
				return "F# Standard / Drop E (Up)";
				break;
			case -1:
				return "F Standard / Drop Eb (Up)";
				break;
			case 0:
				return "E Standard / Drop D";
				break;
			case 1:
				return "Eb Standard / Drop C#";
				break;
			case 2:
				return "D Standard / Drop C";
				break;
			case 3:
				return "C# Standard / Drop B";
				break;
			case 4:
				return "C Standard / Drop A#";
				break;
			case 5:
				return "B Standard / Drop A";
				break;
			case 6:
				return "A# Standard / Drop G#";
				break;
			case 7:
				return "A Standard / Drop G";
				break;
			case 8:
				return "G# Standard / Drop F#";
				break;
			case 9:
				return "G Standard / Drop F (Down)";
				break;
			case 10:
				return "F# Standard / Drop E (Down)";
				break;
			case 11:
				return "F Standard / Drop E (Down)";
				break;
			case 12:
				return "E Standard / Drop Eb (Down)";
				break;
			default:
				return "UNKNOWN TUNING";
				break;
		}
	}

	// Pedal Specific Functions

	// Digitech
	namespace Digitech {
		namespace WhammyDT {
			/// <summary>
			/// Auto Tune with the pedal "Digitech Whammy DT". Tuning names (in comments) are based off a guitar in E Standard.
			/// </summary>
			/// <param name="highestTuning"> - Highest tuned string in the current song's tuning</param>
			void AutoTuning(int highestTuning, float TrueTuning_Hertz) {
				bool alreadyAttemptedTrueTune = false;

				switch (highestTuning) {

					// Above E Standard
				case 12:
					SendProgramChange(49); // E Standard +OCT
					lastPC_TUNING = 49;
					break;
				case 11:
					[[fallthrough]];
				case 10:
					[[fallthrough]];
				case 9:
					[[fallthrough]];
				case 8:
					[[fallthrough]];
				case 7:

					SendProgramChange(48); // B Standard
					lastPC_TUNING = 48;

					if (highestTuning > 7) { // If the pedal doesn't have a dedicated setting, let's force it to work ;) | Needs to be below SendPC or it will not turn off the Whammy side
						AutoTrueTuningPastLimits(highestTuning - 7, TrueTuning_Hertz);
						alreadyAttemptedTrueTune = true;
					}
					break;
				case 6:
					SendProgramChange(47); // Bb Standard
					lastPC_TUNING = 47;
					break;
				case 5:
					SendProgramChange(46); // A Standard
					lastPC_TUNING = 46;
					break;
				case 4:
					SendProgramChange(45); // Ab Standard
					lastPC_TUNING = 45;
					break;
				case 3:
					SendProgramChange(44); // G Standard
					lastPC_TUNING = 44;
					break;
				case 2:
					SendProgramChange(43); // F# Standard
					lastPC_TUNING = 43;
					break;
				case 1:
					SendProgramChange(42); // F Standard
					lastPC_TUNING = 42;
					break;

					// E Standard
				case 0:
					lastPC = 666; // E Standard. Doesn't do anything, just sets the proper lastPC.
					lastPC_TUNING = 0;
					break;

					// Below E Standard
				case -1:
					SendProgramChange(59); // Eb Standard
					lastPC_TUNING = 59;
					break;
				case -2:
					SendProgramChange(58); // D Standard
					lastPC_TUNING = 58;
					break;
				case -3:
					SendProgramChange(57); // C# Standard
					lastPC_TUNING = 57;
					break;
				case -4:
					SendProgramChange(56); // C Standard
					lastPC_TUNING = 56;
					break;
				case -5:
					SendProgramChange(55); // B Standard
					lastPC_TUNING = 55;
					break;
				case -6:
					SendProgramChange(54); // Bb Standard
					lastPC_TUNING = 54;
					break;
				case -7:
					[[fallthrough]];
				case -8:
					[[fallthrough]];
				case -9:
					[[fallthrough]];
				case -10:
					[[fallthrough]];
				case -11:
					SendProgramChange(53); // A Standard
					lastPC_TUNING = 53;

					if (highestTuning < -7) { // If the pedal doesn't have a dedicated setting, let's force it to work ;) | Needs to be below SendPC or it will not turn off the Whammy side
						AutoTrueTuningPastLimits(highestTuning + 7, TrueTuning_Hertz);
						alreadyAttemptedTrueTune = true;
					}
					break;
				case -12:
					SendProgramChange(52); // E Standard -OCT
					lastPC_TUNING = 52;
					break;

				default:

					if (highestTuning <= 24.0f || highestTuning >= -36.0f) { // Attempt to fake it, and maybe we'll make it.
						AutoTrueTuningPastLimits(highestTuning, TrueTuning_Hertz);
						alreadyAttemptedTrueTune = true;
					}
					else
						lastPC = 666; // Doesn't do anything, just sets the proper lastPC.
					break;
				}

				if (!alreadyAttemptedTrueTune && TrueTuning_Hertz != 440.f && TrueTuning_Hertz != 220.f)
					AutoTrueTuning(TrueTuning_Hertz);
			}

			/// <summary>
			/// Auto Tuning (past limits of pedal) and True-Tune with the pedal "Digitech Whammy DT". Based on the work done by PoizenJam.
			/// </summary>
			/// <param name="relativeTuning"> - Tuning from song minus what has already been tuned</param>
			/// <param name="TrueTuning_Hertz"> - True tuning (non-concert pitch)</param>
			void AutoTrueTuningPastLimits(int relativeTuning, float TrueTuning_Hertz) {
				int temp_PC, temp_CC;
				float Target_Hertz, Target_Semitones;

				// Find Target Hertz of combined True Tuning and Drop Tuning. If A < 260, double it before calculation.
				if (TrueTuning_Hertz < 260.0f)
					Target_Hertz = (float)(TrueTuning_Hertz * 2.0f * powf(2.0f, (relativeTuning / 12.0f)));
				else
					Target_Hertz = (float)(TrueTuning_Hertz * powf(2.0f, (relativeTuning / 12.0f)));

				// Convert Target_Hertz to Semitones(relative to A440)
				Target_Semitones = (float)(12.0f * log2(Target_Hertz / 440.0f));

				// Calculate PC needed to achieve target Semitones. If-Else block :(
				if ((roundf(Target_Semitones * 100) / 100) < -24.00f)
					temp_PC = 9;
				else if ((roundf(Target_Semitones * 100) / 100) < -12.00f)
					temp_PC = 8;
				else if ((roundf(Target_Semitones * 100) / 100) < -7.00f)
					temp_PC = 7;
				else if ((roundf(Target_Semitones * 100) / 100) < -5.00f)
					temp_PC = 6;
				else if ((roundf(Target_Semitones * 100) / 100) < 0.00f)
					temp_PC = 5;
				else if ((roundf(Target_Semitones * 100) / 100) < -2.00f)
					temp_PC = 4;
				else if ((roundf(Target_Semitones * 100) / 100) < 5.00f)
					temp_PC = 3;
				else if ((roundf(Target_Semitones * 100) / 100) < 7.00f)
					temp_PC = 2;
				else if ((roundf(Target_Semitones * 100) / 100) < 12.00f)
					temp_PC = 1;
				else
					temp_PC = 0;

				temp_CC = roundf(Target_Semitones * (127.0f / Digitech::WhammyDT::semiTones.at(temp_PC)));

				// Does the song actually NEED us to do any changes?
				if (temp_CC != 0) {
					SendProgramChange(temp_PC);
					SendControlChange(temp_CC);
				}
			}

			/// <summary>
			/// Auto True-Tune with the pedal "Digitech Whammy DT"
			/// </summary>
			/// <param name="TrueTuning_Hertz"> - True Tuning (non-concert pitch)</param>
			void AutoTrueTuning(int TrueTuning_Hertz) {

				if (TrueTuning_Hertz < 260)
					TrueTuning_Hertz *= 2;

				if (TrueTuning_Hertz == 440) // A440
					return;


				// Above A440
				else if (TrueTuning_Hertz > 440) {
					SendProgramChange(3); // Leave at +4th
					SendControlChange((char)(TrueTuning_Hertz - 440));
				}

				// Below A440
				else {
					SendProgramChange(4); // Leave at -2nd
					SendControlChange((char)round(1127.43 - (2.56667 * TrueTuning_Hertz)));
				}
			}
		}
		namespace BassWhammy {
			/// <summary>
			/// Auto Tune and True-Tune with the pedal "Digitech Whammy Bass". Made by PoizenJam.
			/// </summary>
			/// <param name="highestTuning"> - Highest tuned string in the current song.</param>
			/// <param name="TrueTuning_Hertz"> - True Tuning (non-concert pitch)</param>
			void AutoTuningAndTrueTuning(int highestTuning, float TrueTuning_Hertz) {
				int temp_PC, temp_CC, offset = 0;
				float Target_Hertz, Target_Semitones;

				// Chords Mode Offset
				if (Digitech::DIGITECH_CHORDS_MODE)
					offset = 42;

				// Find Target Hertz of combined True Tuning and Drop Tuning. If A < 260, double it before calculation.
				if (TrueTuning_Hertz < 260.0f)
					Target_Hertz = (float)(TrueTuning_Hertz * 2.0f * powf(2.0f, (highestTuning / 12.0f)));
				else
					Target_Hertz = (float)(TrueTuning_Hertz * powf(2.0f, (highestTuning / 12.0f)));

				// Convert Target_Hertz to Semitones(relative to A440)
				Target_Semitones = (float)(12.0f * log2(Target_Hertz / 440.0f));

				// Calculate PC (pre-digitech offset) needed to achieve target Semitones. If-Else block :(
				if ((roundf(Target_Semitones * 100) / 100) < -12.00f)
					temp_PC = 10;
				else if ((roundf(Target_Semitones * 100) / 100) < -7.00f)
					temp_PC = 9;
				else if ((roundf(Target_Semitones * 100) / 100) < -5.00f)
					temp_PC = 8;
				else if ((roundf(Target_Semitones * 100) / 100) < -2.00f)
					temp_PC = 7;
				else if ((roundf(Target_Semitones * 100) / 100) < 0.00f)
					temp_PC = 6;
				else if ((roundf(Target_Semitones * 100) / 100) < 2.00f)
					temp_PC = 5;
				else if ((roundf(Target_Semitones * 100) / 100) < 5.00f)
					temp_PC = 4;
				else if ((roundf(Target_Semitones * 100) / 100) < 7.00f)
					temp_PC = 3;
				else if ((roundf(Target_Semitones * 100) / 100) < 12.00f)
					temp_PC = 2;
				else
					temp_PC = 1;

				temp_CC = roundf(Target_Semitones * (127.0f / Digitech::BassWhammy::semiTones.at(temp_PC - 1)));

				// Does the song actually NEED us to do any changes?
				if (temp_CC != 0) {
					SendProgramChange(temp_PC + offset - 1);
					SendControlChange(temp_CC);
				}
			}
		}
		namespace Whammy {
			/// <summary>
			/// Auto Tune and True-Tune with the pedal "Digitech Whammy". Made by PoizenJam.
			/// </summary>
			/// <param name="highestTuning"> - Highest tuned string in the current song.</param>
			/// <param name="TrueTuning_Hertz"> - True Tuning (non-concert pitch)</param>
			void AutoTuningAndTrueTuning(int highestTuning, float TrueTuning_Hertz) {
				int temp_PC, temp_CC, offset = 0;
				float Target_Hertz, Target_Semitones;

				// Chords Mode Offset
				if (Digitech::DIGITECH_CHORDS_MODE)
					offset = 42;

				// Find Target Hertz of combined True Tuning and Drop Tuning. If A < 260, double it before calculation.
				if (TrueTuning_Hertz < 260.0f)
					Target_Hertz = (float)(TrueTuning_Hertz * 2.0f * powf(2.0f, (highestTuning / 12.0f)));
				else
					Target_Hertz = (float)(TrueTuning_Hertz * powf(2.0f, (highestTuning / 12.0f)));

				// Convert Target_Hertz to Semitones(relative to A440)
				Target_Semitones = (float)(12.0f * log2(Target_Hertz / 440.0f));

				// Calculate PC needed to achieve target Semitones. If-Else block :(
				if ((roundf(Target_Semitones * 100) / 100) < -24.00f)
					temp_PC = 10;
				else if ((roundf(Target_Semitones * 100) / 100) < -12.00f)
					temp_PC = 9;
				else if ((roundf(Target_Semitones * 100) / 100) < -7.00f)
					temp_PC = 8;
				else if ((roundf(Target_Semitones * 100) / 100) < -5.00f)
					temp_PC = 7;
				else if ((roundf(Target_Semitones * 100) / 100) < -2.00f)
					temp_PC = 6;
				else if ((roundf(Target_Semitones * 100) / 100) < 0.00f)
					temp_PC = 5;
				else if ((roundf(Target_Semitones * 100) / 100) < 5.00f)
					temp_PC = 4;
				else if ((roundf(Target_Semitones * 100) / 100) < 7.00f)
					temp_PC = 3;
				else if ((roundf(Target_Semitones * 100) / 100) < 12.00f)
					temp_PC = 2;
				else
					temp_PC = 1;

				temp_CC = roundf(Target_Semitones * (127.0f / Digitech::Whammy::semiTones.at(temp_PC - 1)));

				// Does the song actually NEED us to do any changes?
				if (temp_CC != 0) {
					SendProgramChange(temp_PC + offset - 1);
					SendControlChange(temp_CC);
				}
			}
		}
	}

	namespace Software {
		/// <summary>
		/// Auto tuning for a software pedal
		/// </summary>
		/// <param name="highestTuning"> - Highest tuned string in the current song.</param>
		/// <param name="TrueTuning_Hertz"> - True Tuning (non-concert pitch)</param>
		void AutoTuning(int highestTuning, float TrueTuning_Hertz) {
			if (Settings::async_UpdateMidiSettings) {
				ReloadSettings();
				Settings::async_UpdateMidiSettings = false;
			}

			if (semiToneMap.find(highestTuning) != semiToneMap.end()) {
				if (sendSemitoneCommand == programChangeStatus)
					SendProgramChange(semiToneMap.find(highestTuning)->second);
				else if (sendSemitoneCommand == controlChangeStatus)
					SendControlChange(semiToneMap.find(highestTuning)->second);

				sentSemitoneInThisSong = true;
			}
			else
				//std::cout << "(MIDI) Software Pedal Error: Attempted to tune to " << highestTuning << " but the user doesn't have a value set for it." << std::endl;

			if (TrueTuning_Hertz < 260.f)
				TrueTuning_Hertz *= 2;
			if (TrueTuning_Hertz < 416.f)
				TrueTuning_Hertz = 440;
			if (TrueTuning_Hertz > 465.f)
				TrueTuning_Hertz = 440;

			if (TrueTuning_Hertz != 440)
				AutoTrueTuning(TrueTuning_Hertz);
		}

		void AutoTrueTuning(float TrueTuning_Hertz) {

			if (TrueTuning_Hertz < 260.f)
				TrueTuning_Hertz *= 2;
			if (TrueTuning_Hertz < 416.f)
				TrueTuning_Hertz = 440;
			if (TrueTuning_Hertz > 465.f)
				TrueTuning_Hertz = 440;

			if (trueTuningMap.find(TrueTuning_Hertz) != trueTuningMap.end()) {
				if (sendTrueTuningCommand == programChangeStatus)
					SendProgramChange(trueTuningMap.find(TrueTuning_Hertz)->second, sendTrueTuningChannel);
				else if (sendTrueTuningCommand == controlChangeStatus)
					SendControlChange(trueTuningMap.find(TrueTuning_Hertz)->second, trueTuningBank, sendTrueTuningChannel);

				Midi::Software::sentTrueTuningInThisSong = true;
			}
			else
				std::cout << "(MIDI) Software Pedal Error: Attempted to truetune to A" << TrueTuning_Hertz << " but the user doesn't have a value set for it." << std::endl;
		}

		void ReloadSettings() {
			semiToneMap.clear();
			trueTuningMap.clear();

			LoadSemitoneSettings();
			FillSemitoneMap();
			FillTrueTuningMap();
			LoadTrueTuningSettings();

		}

		void FillSemitoneMap() {
			std::string triggers = Settings::ReturnSettingValue("AutoTuneForSoftwareSemitoneTriggers");
			std::string delim = ", ";
			std::vector<std::string> separated;
			size_t position = 0;

			// String of triggers -> List of triggers
			while ((position = triggers.find(delim)) != std::string::npos) {
				separated.push_back(triggers.substr(0, position));
				triggers.erase(0, position + delim.length());
			}
			separated.push_back(triggers); // If we don't do this, the last value won't get thrown in if the user forgot a trailing comma

			delim = " ";

			// List of triggers (string) -> Map of triggers (char, char)
			for (int i = 0; i < separated.size(); i++) {

				std::string semiTone_string = separated[i].substr(0, separated[i].find(delim));
				std::string command_string = separated[i].erase(0, separated[i].find(delim) + delim.length());
				char semiTone = std::atoi(semiTone_string.c_str());
				char command = std::atoi(command_string.c_str());

				if (semiToneMap.count(semiTone) == 0)
					semiToneMap[semiTone] = command;
				else
					std::cout << "(MIDI) Software Pedal Error: Semitone Triggers for " << semiTone << " is already set to " << semiToneMap[semiTone] << " found in the " << std::distance(semiToneMap.begin(), semiToneMap.find(semiTone)) << " position" << std::endl;
			}

			std::cout << "(MIDI) Software Pedal: Semitone Triggers" << std::endl;

			for (std::map<char, char>::iterator it = semiToneMap.begin(); it != semiToneMap.end(); it++)
				std::cout << "Semitone = " << (int)it->first << ", Value To Send = " << (int)it->second << std::endl;

			std::cout << "(MIDI) Software Pedal: Semitone Triggers --END" << std::endl;
		}

		void LoadSemitoneSettings() {
			std::string settings = Settings::ReturnSettingValue("AutoTuneForSoftwareSemitoneSettings");
			std::string delim = ", ";
			std::vector<std::string> separated;
			size_t position = 0;

			// String of settings -> List of settings
			while ((position = settings.find(delim)) != std::string::npos) {
				separated.push_back(settings.substr(0, position));
				settings.erase(0, position + delim.length());
			}
			separated.push_back(settings); // If we don't do this, the last value won't get thrown in if the user forgot a trailing comma

			if (separated.size() > 0) {
				semiToneShutoffTrigger = std::atoi(separated.at(0).c_str());

				if (separated.size() > 1) {
					if (separated.at(1) == "PC") {
						sendSemitoneCommand = programChangeStatus;
						if (separated.size() > 2)
							selectedPedal.PC_Channel = std::atoi(separated.at(2).c_str()) % 16; // Only 16 channels are supported.
						else
							std::cout << "SOFTWARE LOADSETTINGS ERROR (semitones): PC set as the send method but no channel is specified" << std::endl;
					}
						
					if (separated.at(1) == "CC") {
						sendSemitoneCommand = controlChangeStatus;
						if (separated.size() > 2) {
							selectedPedal.CC_Channel = std::atoi(separated.at(2).c_str()) % 16; // Only 16 channels are supported.
							if (separated.size() > 3)
								selectedPedal.CC_Bank = std::atoi(separated.at(3).c_str());
							else
								std::cout << "SOFTWARE LOAD SETTINGS ERROR (semitones): CC set as the send method but no bank is specified. Defaulting to Bank 0." << std::endl;
						}
						else
							std::cout << "SOFTWARE LOADSETTINGS ERROR (semitones): CC set as the send method but no channel is specified. Defaulting to Channel 0." << std::endl;
					}
				}
			}
			else {
				std::cout << "SOFTWARE LOADSETTINGS ERROR (semitones): No settings to load!" << std::endl;
			}
		}

		void FillTrueTuningMap() {
			std::string triggers = Settings::ReturnSettingValue("AutoTuneForSoftwareTrueTuningTriggers");
			std::string delim = ", ";
			std::vector<std::string> separated;
			size_t position = 0;

			// String of triggers -> List of triggers
			while ((position = triggers.find(delim)) != std::string::npos) {
				separated.push_back(triggers.substr(0, position));
				triggers.erase(0, position + delim.length());
			}
			separated.push_back(triggers); // If we don't do this, the last value won't get thrown in if the user forgot a trailing comma

			delim = " ";

			// List of triggers (string) -> Map of triggers (int, char)
			for (int i = 0; i < separated.size(); i++) {

				std::string semiTone_string = separated[i].substr(0, separated[i].find(delim));
				std::string command_string = separated[i].erase(0, separated[i].find(delim) + delim.length());
				int trueTuning = std::atoi(semiTone_string.c_str());
				char command = std::atoi(command_string.c_str());

				if (trueTuningMap.count(trueTuning) == 0)
					trueTuningMap[trueTuning] = command;
				else
					std::cout << "(MIDI) Software Pedal Error: TrueTuning Triggers for " << trueTuning << " is already set to " << trueTuningMap[trueTuning] << " found in the " << std::distance(trueTuningMap.begin(), trueTuningMap.find(trueTuning)) << " position" << std::endl;
			}

			std::cout << "(MIDI) Software Pedal: TrueTuning Triggers" << std::endl;

			for (std::map<int, char>::iterator it = trueTuningMap.begin(); it != trueTuningMap.end(); it++)
				std::cout << "True Tuning = A" << it->first << ", Value To Send = " << (int)it->second << std::endl;

			std::cout << "(MIDI) Software Pedal: TrueTuning Triggers --END" << std::endl;
		}

		void LoadTrueTuningSettings() {
			std::string settings = Settings::ReturnSettingValue("AutoTuneForSoftwareTrueTuningSettings");
			std::string delim = ", ";
			std::vector<std::string> separated;
			size_t position = 0;

			// String of settings -> List of settings
			while ((position = settings.find(delim)) != std::string::npos) {
				separated.push_back(settings.substr(0, position));
				settings.erase(0, position + delim.length());
			}
			separated.push_back(settings); // If we don't do this, the last value won't get thrown in if the user forgot a trailing comma

			if (separated.size() > 0) {
				trueTuningShutoffTrigger = std::atoi(separated.at(0).c_str());

				if (separated.size() > 1) {
					if (separated.at(1) == "PC") {
						sendTrueTuningCommand = programChangeStatus;
						if (separated.size() > 2)
							sendTrueTuningChannel = std::atoi(separated.at(2).c_str()) % 16; // Only 16 channels are supported.
						else
							std::cout << "SOFTWARE LOADSETTINGS ERROR (truetuning): PC set as the send method but no channel is specified" << std::endl;
					}
					if (separated.at(1) == "CC") {
						sendTrueTuningCommand = controlChangeStatus;

						if (separated.size() > 2) {
							sendTrueTuningChannel = std::atoi(separated.at(2).c_str()) % 16; // Only 16 channels are supported.
							if (separated.size() > 3)
								trueTuningBank = std::atoi(separated.at(3).c_str());
							else
								std::cout << "SOFTWARE LOAD SETTINGS ERROR (truetuning): CC set as the send method but no bank is specified. Defaulting to Bank 0." << std::endl;
						}
						else
							std::cout << "SOFTWARE LOADSETTINGS ERROR (truetuning): CC set as the send method but no channel is specified. Defaulting to Channel 0." << std::endl;

					}
				}
			}
			else {
				std::cout << "SOFTWARE LOADSETTINGS ERROR (truetuning): No settings to load!" << std::endl;
			}
		}
	}
}