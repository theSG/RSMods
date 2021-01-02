﻿using System;
using System.IO;
using System.Windows.Forms;
using System.Diagnostics;
using System.Collections.Generic;
using RSMods.Util;
using System.Drawing;

namespace RSMods
{
    class WriteSettings
    {
        // Default Colors
        public static Color defaultBackgroundColor = Color.Azure;
        public static Color defaultTextColor = Color.Black;

        #region Default Settings
        public static Dictionary<string, Dictionary<string, string>> Settings = new Dictionary<string, Dictionary<string, string>>()
        {
            // Section                           mod   default
            {"[SongListTitles]", new Dictionary<string, string> {

                { ReadSettings.Songlist1Identifier, "Define Song List 1 Here" }, // Songlist 1
                { ReadSettings.Songlist2Identifier, "Define Song List 2 Here" }, // Songlist 2
                { ReadSettings.Songlist3Identifier, "Define Song List 3 Here" }, // Songlist 3
                { ReadSettings.Songlist4Identifier, "Define Song List 4 Here" }, // Songlist 4
                { ReadSettings.Songlist5Identifier, "Define Song List 5 Here" }, // Songlist 5
                { ReadSettings.Songlist6Identifier, "Define Song List 6 Here" }, // Songlist 6
            }},
            {"[Keybinds]", new Dictionary<string, string> {
                { ReadSettings.ToggleLoftIdentifier, "" }, // Toggle Loft
                { ReadSettings.ShowSongTimerIdentifier, "" }, // Show Song Timer
                { ReadSettings.ForceReEnumerationIdentifier, "" }, // Force ReEnumeration
                { ReadSettings.RainbowStringsIdentifier, "" }, // Rainbow Strings
                { ReadSettings.RainbowNotesIdentifier, "" }, // Rainbow Notes
                { ReadSettings.RemoveLyricsKeyIdentifier, "" }, // Remove Lyrics Key
                { ReadSettings.RRSpeedKeyIdentifier, "" } // Riff Repeater Above 100% key.
            }},
            {"[Audio Keybindings]", new Dictionary<string, string>
            {
                { ReadSettings.MasterVolumeKeyIdentifier, "" }, // Master Volume (Hidden in the in-game mixer)
                { ReadSettings.SongVolumeKeyIdentifier, "" }, // Song Volume
                { ReadSettings.Player1VolumeKeyIdentifier, "" }, // Player 1 Guitar / Bass Volume
                { ReadSettings.Player2VolumeKeyIdentifier, "" }, // Player 2 Guitar / Bass Volume
                { ReadSettings.MicrophoneVolumeKeyIdentifier, "" }, // Microphone Volume
                { ReadSettings.VoiceOverVolumeKeyIdentifier, "" }, // Rocksmith Dad Volume
                { ReadSettings.SFXVolumeKeyIdentifier, "" }, // SFX Volume
                { ReadSettings.ChangeSelectedVolumeKeyIdentifier, "" }, // Change Selected Volume
            }},
            {"[Toggle Switches]", new Dictionary<string, string>
            {
                { ReadSettings.ToggleLoftEnabledIdentifier, "off" }, // Toggle Loft Enabled / Disabled
                { ReadSettings.VolumeControlEnabledIdentifier, "off" }, // Volume Control Enabled / Disabled
                { ReadSettings.ShowSongTimerEnabledIdentifier, "off" }, // Show Song Timer Enabled / Disabled
                { ReadSettings.ForceReEnumerationEnabledIdentifier, "off" }, // Force ReEnumeration Manual / Automatic / Disabled
                { ReadSettings.RainbowStringsEnabledIdentifier, "off" }, // Rainbow String Enabled / Disabled
                { ReadSettings.RainbowNotesEnabledIdentifier, "off" }, // Rainbow Notes Enabled / Disabled
                { ReadSettings.ExtendedRangeEnabledIdentifier, "off" }, // Extended Range Enabled / Disabled
                { ReadSettings.ExtendedRangeDropTuningIdentifier, "off" }, // Extended Range on Drop Tunings (Drop A, Drop B, etc)
                { ReadSettings.CustomStringColorNumberIndetifier, "0" }, // Custom String Colors (0 - Default, 1 - ZZ, 2 - Custom Colors)
                //{ ReadSettings.DiscoModeIdentifier, "off" }, // Disco Mode Enabled / Disabled
                { ReadSettings.RemoveHeadstockIdentifier, "off" }, // Remove Headstock Enabled / Disabled
                { ReadSettings.RemoveSkylineIdentifier, "off" }, // Remove Skyline Enabled / Disabled
                { ReadSettings.GreenScreenWallIdentifier, "off"}, // Greenscreen Back Wall Enabled / Disabled
                { ReadSettings.ForceProfileEnabledIdentifier, "off" }, // Force Load Profile On Game Boot Enabled / Disabled
                { ReadSettings.FretlessModeEnabledIdentifier, "off" }, // Fretless Mode Enabled / Disabled
                { ReadSettings.RemoveInlaysIdentifier, "off" }, // Remove Inlay Markers Enabled / Disabled
                { ReadSettings.ToggleLoftWhenIdentifier, "manual" }, // Define how or when the loft is disabled - game startup, on key command, or in song only
                { ReadSettings.RemoveLaneMarkersIdentifier, "off" }, // Remove Lane Markers Enabled / Disabled
                { ReadSettings.ToggleSkylineWhenIdentifier, "song" }, // Define how or when the skyline is disabled - game startup, or in song only
                { ReadSettings.RemoveLyricsIdentifier, "off" }, // Remove Song Lyrics Enabled / Disabled
                { ReadSettings.RemoveLyricsWhenIdentifier, "manual" }, // When should we remove lyrics Manual / Automatic
                { ReadSettings.GuitarSpeakIdentifier, "off" }, // Guitar Speak Enabled / Disabled
                { ReadSettings.RemoveHeadstockWhenIdentifier, "song" }, // Remove Headstock When Startup / Song
                { ReadSettings.ScreenShotScoresIdentifier, "off" }, // Screenshot Scores When You Finish A Song
                { ReadSettings.RiffRepeaterAboveHundredIdentifier, "off" }, // Allow the user to go above 100% speed in LAS Riff Repeater
                { ReadSettings.MidiAutoTuningIdentifier, "off" }, // Should we be ready to send MIDI signals to a device.
                { ReadSettings.MidiAutoTuningDeviceIdentifier, "" }, // Device we should send MIDI signals to.
                { ReadSettings.ChordsModeIdentifier, "off" }, // Is the pedal using Chords Mode.
                { ReadSettings.ShowCurrentNoteOnScreenIdentifier, "off" }, // Display Current Note Name
                { ReadSettings.OnScreenFontIdentifier, "Arial" }, // Font to use when we show text over Rocksmith
                { ReadSettings.ProfileToLoadIdentifier, "" }, // Default profile to load.
            }},
            {"[String Colors]", new Dictionary<string, string>
            {
                { ReadSettings.String0Color_N_Identifier, "ff4f5a" }, // Default Low E String Color (HEX) | Red
                { ReadSettings.String1Color_N_Identifier, "e2c102" }, // Default A String Color (HEX) | Yellow
                { ReadSettings.String2Color_N_Identifier, "1dacf9" }, // Default D String Color (HEX) | Blue
                { ReadSettings.String3Color_N_Identifier, "ff9216" }, // Default G String Color (HEX) | Orange
                { ReadSettings.String4Color_N_Identifier, "3fcc0c" }, // Default B String Color (HEX) | Green
                { ReadSettings.String5Color_N_Identifier, "c825ed" }, // Default High E String Color (HEX) | Purple

                { ReadSettings.String0Color_CB_Identifier, "00c68e" }, // Colorblind Low E String Color (HEX) | Red
                { ReadSettings.String1Color_CB_Identifier, "ff4f5a" }, // Colorblind A String Color (HEX) | Yellow
                { ReadSettings.String2Color_CB_Identifier, "e2c102" }, // Colorblind D String Color (HEX) | Blue
                { ReadSettings.String3Color_CB_Identifier, "1dacf9" }, // Colorblind G String Color (HEX) | Orange
                { ReadSettings.String4Color_CB_Identifier, "ff9216" }, // Colorblind B String Color (HEX) | Green
                { ReadSettings.String5Color_CB_Identifier, "3fcc0c" }, // Colorblind High E String Color (HEX) | Purple
            }},
            {"[Mod Settings]", new Dictionary<string, string>
            {
                { ReadSettings.ExtendedRangeTuningIdentifier, "-5" }, // Enable Extended Range Mode When Low E Is X Below E
                { ReadSettings.CheckForNewSongIntervalIdentifier, "5000" }, // Enumerate new CDLC / ODLC every X ms
                { ReadSettings.RiffRepeaterSpeedIntervalIdentifier, "1" }, // The rate of how much one key press should gain the Riff Repeater speed.
                { ReadSettings.TuningPedalIdentifier, "" }, // What tuning pedal does the user use?
                { ReadSettings.VolumeControlIntervalIdentifier, "5" } // By what number should we increase / decrease the volume.
            }},

            {"[Guitar Speak]", new Dictionary<string, string>
            {
                { ReadSettings.GuitarSpeakDeleteIdentifier, "" }, // Guitar Speak Press Delete When Midi Note = (0{C-1} - 96{C7})
                { ReadSettings.GuitarSpeakSpaceIdentifier, "" }, // Guitar Speak Press Space " " When Midi Note = (0{C-1} - 96{C7})
                { ReadSettings.GuitarSpeakEnterIdentifier, "" }, // Guitar Speak Press Enter / Return When Midi Note = (0{C-1} - 96{C7})
                { ReadSettings.GuitarSpeakTabIdentifier, "" }, // Guitar Speak Press Tab When Midi Note = (0{C-1} - 96{C7})
                { ReadSettings.GuitarSpeakPGUPIdentifier, "" }, // Guitar Speak Press Page Up When Midi Note = (0{C-1} - 96{C7})
                { ReadSettings.GuitarSpeakPGDNIdentifier, "" }, // Guitar Speak Press Page Down When Midi Note = (0{C-1} - 96{C7})
                { ReadSettings.GuitarSpeakUPIdentifier, "" }, // Guitar Speak Press Up Arrow When Midi Note = (0{C-1} - 96{C7})
                { ReadSettings.GuitarSpeakDNIdentifier, "" }, // Guitar Speak Press Down Arrow When Midi Note = (0{C-1} - 96{C7})
                { ReadSettings.GuitarSpeakESCIdentifier, "" }, // Guitar Speak Press Escape When Midi Note = (0{C-1} - 96{C7})
                { ReadSettings.GuitarSpeakCloseIdentifier, "" }, // Stop using Guitar Speak when Midi Note = (0{C-1} - 96{C7})
                { ReadSettings.GuitarSpeakOBracketIdentifier, "" }, // Guitar Speak Press Open Bracket "{" When Midi Note = (0{C-1} - 96{C7})
                { ReadSettings.GuitarSpeakCBracketIdentifier, "" }, // Guitar Speak Press Close Bracket "}" When Midi Note = (0{C-1} - 96{C7})
                { ReadSettings.GuitarSpeakTildeaIdentifier, "" }, // Guitar Speak Press Tilde / Tilda "~" When Midi Note = (0{C-1} - 96{C7})
                { ReadSettings.GuitarSpeakForSlashIdentifier, "" }, // Guitar Speak Press Forward Slash "/" When Midi Note = (0{C-1} - 96{C7})
                { ReadSettings.GuitarSpeakTuningIdentifier, "off" }, // Use Guitar Speak in Tuning Menus
            }},
            {"[Highway Colors]", new Dictionary<string, string>
            {
                { ReadSettings.CustomHighwayColorsIdentifier, "off" }, // Should we use Custom Noteway Colors
                { ReadSettings.CustomHighwayNumberedIdentifier, "" }, // Numbered Frets Color
                { ReadSettings.CustomHighwayUnNumberedIdentifier, "" }, // UnNumbered Frets Color
                { ReadSettings.CustomHighwayGutterIdentifier, "" }, // Sides of Note Highway Color
                { ReadSettings.CustomFretNubmersIdentifier, "" }, // Fret Numbers Color
            }},
            {"[GUI Settings]", new Dictionary<string, string>
            {
                { ReadSettings.CustomGUIThemeIdentifier, "off"}, // Use a Custom GUI theme.
                { ReadSettings.CustomGUIBackgroundColorIdentifier, "F0FFFF" }, // Custom Theme Background Color
                { ReadSettings.CustomGUITextColorIdentifier, "000000" }, // Custom Theme Text Color
                { ReadSettings.BackupProfileIdentifier, "on" }, // Should we backup profiles
                { ReadSettings.NumberOfBackupsIdentifier, "50" }, // How many backups should we store before we start deleting them.
            }},
        };
        #endregion
        #region Save Settings
        public static Dictionary<string, Dictionary<string, string>> saveSettings = new Dictionary<string, Dictionary<string, string>>()
        {
            // [Section]                         mod    setting
            {"[SongListTitles]", new Dictionary<string, string> {
                { ReadSettings.Songlist1Identifier, ReadSettings.ProcessSettings(ReadSettings.Songlist1Identifier) }, // Songlist 1
                { ReadSettings.Songlist2Identifier, ReadSettings.ProcessSettings(ReadSettings.Songlist2Identifier) }, // Songlist 2
                { ReadSettings.Songlist3Identifier, ReadSettings.ProcessSettings(ReadSettings.Songlist3Identifier) }, // Songlist 3
                { ReadSettings.Songlist4Identifier, ReadSettings.ProcessSettings(ReadSettings.Songlist4Identifier) }, // Songlist 4
                { ReadSettings.Songlist5Identifier, ReadSettings.ProcessSettings(ReadSettings.Songlist5Identifier) }, // Songlist 5
                { ReadSettings.Songlist6Identifier, ReadSettings.ProcessSettings(ReadSettings.Songlist6Identifier) }, // Songlist 6
            }},
            {"[Keybinds]", new Dictionary<string, string> {
                { ReadSettings.ToggleLoftIdentifier, ReadSettings.ProcessSettings(ReadSettings.ToggleLoftIdentifier) }, // Toggle Loft
                { ReadSettings.ShowSongTimerIdentifier, ReadSettings.ProcessSettings(ReadSettings.ShowSongTimerIdentifier) }, // Show Song Timer
                { ReadSettings.ForceReEnumerationIdentifier, ReadSettings.ProcessSettings(ReadSettings.ForceReEnumerationIdentifier) }, // Force ReEnumeration
                { ReadSettings.RainbowStringsIdentifier, ReadSettings.ProcessSettings(ReadSettings.RainbowStringsIdentifier) }, // Rainbow Strings
                { ReadSettings.RainbowNotesIdentifier, ReadSettings.ProcessSettings(ReadSettings.RainbowNotesIdentifier) }, // Rainbow Notes
                { ReadSettings.RemoveLyricsKeyIdentifier, ReadSettings.ProcessSettings(ReadSettings.RemoveLyricsKeyIdentifier) }, // Remove Lyrics Key
                { ReadSettings.RRSpeedKeyIdentifier, ReadSettings.ProcessSettings(ReadSettings.RRSpeedKeyIdentifier) } // Riff Repeater Above 100% Key
            }},
            {"[Audio Keybindings]", new Dictionary<string, string>
            {
                { ReadSettings.MasterVolumeKeyIdentifier, ReadSettings.ProcessSettings(ReadSettings.MasterVolumeKeyIdentifier) }, // Master Volume (Hidden in the in-game mixer)
                { ReadSettings.SongVolumeKeyIdentifier, ReadSettings.ProcessSettings(ReadSettings.SongVolumeKeyIdentifier) }, // Song Volume
                { ReadSettings.Player1VolumeKeyIdentifier, ReadSettings.ProcessSettings(ReadSettings.Player1VolumeKeyIdentifier) }, // Player 1 Guitar / Bass Volume
                { ReadSettings.Player2VolumeKeyIdentifier, ReadSettings.ProcessSettings(ReadSettings.Player2VolumeKeyIdentifier) }, // Player 2 Guitar / Bass Volume
                { ReadSettings.MicrophoneVolumeKeyIdentifier, ReadSettings.ProcessSettings(ReadSettings.MicrophoneVolumeKeyIdentifier) }, // Microphone Volume
                { ReadSettings.VoiceOverVolumeKeyIdentifier, ReadSettings.ProcessSettings(ReadSettings.VoiceOverVolumeKeyIdentifier) }, // Rocksmith Dad Volume
                { ReadSettings.SFXVolumeKeyIdentifier, ReadSettings.ProcessSettings(ReadSettings.SFXVolumeKeyIdentifier) }, // SFX Volume
                { ReadSettings.ChangeSelectedVolumeKeyIdentifier, ReadSettings.ProcessSettings(ReadSettings.ChangeSelectedVolumeKeyIdentifier) }, // Change Selected Volume
            }},
            {"[Toggle Switches]", new Dictionary<string, string>
            {
                { ReadSettings.ToggleLoftEnabledIdentifier, ReadSettings.ProcessSettings(ReadSettings.ToggleLoftEnabledIdentifier) }, // Toggle Loft Enabled / Disabled
                { ReadSettings.VolumeControlEnabledIdentifier, ReadSettings.ProcessSettings(ReadSettings.VolumeControlEnabledIdentifier) }, // Volume Control Enabled / Disabled
                { ReadSettings.ShowSongTimerEnabledIdentifier, ReadSettings.ProcessSettings(ReadSettings.ShowSongTimerEnabledIdentifier) }, // Show Song Timer Enabled / Disabled
                { ReadSettings.ForceReEnumerationEnabledIdentifier, ReadSettings.ProcessSettings(ReadSettings.ForceReEnumerationEnabledIdentifier) }, // Force ReEnumeration Manual / Automatic / Disabled
                { ReadSettings.RainbowStringsEnabledIdentifier, ReadSettings.ProcessSettings(ReadSettings.RainbowStringsEnabledIdentifier) }, // Rainbow String Enabled / Disabled
                { ReadSettings.RainbowNotesEnabledIdentifier, ReadSettings.ProcessSettings(ReadSettings.RainbowNotesEnabledIdentifier) }, // Rainbow Notes Enabled / Disabled
                { ReadSettings.ExtendedRangeEnabledIdentifier, ReadSettings.ProcessSettings(ReadSettings.ExtendedRangeEnabledIdentifier) }, // Extended Range Enabled / Disabled
                { ReadSettings.ExtendedRangeDropTuningIdentifier, ReadSettings.ProcessSettings(ReadSettings.ExtendedRangeDropTuningIdentifier) }, // Extended Range on Drop Tunings (Drop A, Drop B, etc)
                { ReadSettings.CustomStringColorNumberIndetifier, ReadSettings.ProcessSettings(ReadSettings.CustomStringColorNumberIndetifier) }, // Custom String Colors (0 - Default, 1 - ZZ, 2 - Custom Colors)
                //{ ReadSettings.DiscoModeIdentifier, ReadSettings.ProcessSettings(ReadSettings.DiscoModeIdentifier) }, // Disco Mode Enabled / Disabled
                { ReadSettings.RemoveHeadstockIdentifier, ReadSettings.ProcessSettings(ReadSettings.RemoveHeadstockIdentifier) }, // Remove Headstock Enabled / Disabled
                { ReadSettings.RemoveSkylineIdentifier, ReadSettings.ProcessSettings(ReadSettings.RemoveSkylineIdentifier) }, // Remove Skyline Enabled / Disabled
                { ReadSettings.GreenScreenWallIdentifier, ReadSettings.ProcessSettings(ReadSettings.GreenScreenWallIdentifier)}, // Greenscreen Back Wall Enabled / Disabled
                { ReadSettings.ForceProfileEnabledIdentifier, ReadSettings.ProcessSettings(ReadSettings.ForceProfileEnabledIdentifier) }, // Force Load Profile On Game Boot Enabled / Disabled
                { ReadSettings.FretlessModeEnabledIdentifier, ReadSettings.ProcessSettings(ReadSettings.FretlessModeEnabledIdentifier) }, // Fretless Mode Enabled / Disabled
                { ReadSettings.RemoveInlaysIdentifier, ReadSettings.ProcessSettings(ReadSettings.RemoveInlaysIdentifier) }, // Remove Inlay Markers Enabled / Disabled
                { ReadSettings.ToggleLoftWhenIdentifier, ReadSettings.ProcessSettings(ReadSettings.ToggleLoftWhenIdentifier) }, // Define how or when the loft is disabled - game startup, on key command, or in song only
                { ReadSettings.RemoveLaneMarkersIdentifier, ReadSettings.ProcessSettings(ReadSettings.RemoveLaneMarkersIdentifier) }, // Remove Lane Markers Enabled / Disabled
                { ReadSettings.ToggleSkylineWhenIdentifier, ReadSettings.ProcessSettings(ReadSettings.ToggleSkylineWhenIdentifier) }, // Define how or when the skyline is disabled - game startup, or in song only
                { ReadSettings.RemoveLyricsIdentifier, ReadSettings.ProcessSettings(ReadSettings.RemoveLyricsIdentifier) }, // Remove Song Lyrics Enabled / Disabled
                { ReadSettings.RemoveLyricsWhenIdentifier, ReadSettings.ProcessSettings(ReadSettings.RemoveLyricsWhenIdentifier) }, // Remove Song Lyrics When Manual / Automatic
                { ReadSettings.GuitarSpeakIdentifier, ReadSettings.ProcessSettings(ReadSettings.GuitarSpeakIdentifier) }, // Guitar Speak Enabled / Disabled
                { ReadSettings.RemoveHeadstockWhenIdentifier, ReadSettings.ProcessSettings(ReadSettings.RemoveHeadstockWhenIdentifier) }, // Remove Headstock When Startup / Song
                { ReadSettings.ScreenShotScoresIdentifier, ReadSettings.ProcessSettings(ReadSettings.ScreenShotScoresIdentifier) }, // Screenshot Scores When You Finish A Song
                { ReadSettings.RiffRepeaterAboveHundredIdentifier, ReadSettings.ProcessSettings(ReadSettings.RiffRepeaterAboveHundredIdentifier) }, // Allow the user to go above 100% speed in LAS Riff Repeater
                { ReadSettings.MidiAutoTuningIdentifier, ReadSettings.ProcessSettings(ReadSettings.MidiAutoTuningIdentifier) }, // Should we be ready to send MIDI signals to a device.
                { ReadSettings.MidiAutoTuningDeviceIdentifier, ReadSettings.ProcessSettings(ReadSettings.MidiAutoTuningDeviceIdentifier) }, // Device we should send MIDI signals to.
                { ReadSettings.ChordsModeIdentifier, ReadSettings.ProcessSettings(ReadSettings.ChordsModeIdentifier) }, // Is the pedal using Chords Mode.
                { ReadSettings.ShowCurrentNoteOnScreenIdentifier, ReadSettings.ProcessSettings(ReadSettings.ShowCurrentNoteOnScreenIdentifier) }, // Display Current Note Name
                { ReadSettings.OnScreenFontIdentifier, ReadSettings.ProcessSettings(ReadSettings.OnScreenFontIdentifier) }, // Font to use when we show text over Rocksmith
                { ReadSettings.ProfileToLoadIdentifier, ReadSettings.ProcessSettings(ReadSettings.ProfileToLoadIdentifier) }, // Profile To Load
            }},
            {"[String Colors]", new Dictionary<string, string>
            {
                { ReadSettings.String0Color_N_Identifier, ReadSettings.ProcessSettings(ReadSettings.String0Color_N_Identifier) }, // Default Low E String Color (HEX) | Red
                { ReadSettings.String1Color_N_Identifier, ReadSettings.ProcessSettings(ReadSettings.String1Color_N_Identifier) }, // Default A String Color (HEX) | Yellow
                { ReadSettings.String2Color_N_Identifier, ReadSettings.ProcessSettings(ReadSettings.String2Color_N_Identifier) }, // Default D String Color (HEX) | Blue
                { ReadSettings.String3Color_N_Identifier, ReadSettings.ProcessSettings(ReadSettings.String3Color_N_Identifier) }, // Default G String Color (HEX) | Orange
                { ReadSettings.String4Color_N_Identifier, ReadSettings.ProcessSettings(ReadSettings.String4Color_N_Identifier) }, // Default B String Color (HEX) | Green
                { ReadSettings.String5Color_N_Identifier, ReadSettings.ProcessSettings(ReadSettings.String5Color_N_Identifier) }, // Default High E String Color (HEX) | Purple

                { ReadSettings.String0Color_CB_Identifier, ReadSettings.ProcessSettings(ReadSettings.String0Color_CB_Identifier) }, // Colorblind Low E String Color (HEX) | Red
                { ReadSettings.String1Color_CB_Identifier, ReadSettings.ProcessSettings(ReadSettings.String1Color_CB_Identifier) }, // Colorblind A String Color (HEX) | Yellow
                { ReadSettings.String2Color_CB_Identifier, ReadSettings.ProcessSettings(ReadSettings.String2Color_CB_Identifier) }, // Colorblind D String Color (HEX) | Blue
                { ReadSettings.String3Color_CB_Identifier, ReadSettings.ProcessSettings(ReadSettings.String3Color_CB_Identifier) }, // Colorblind G String Color (HEX) | Orange
                { ReadSettings.String4Color_CB_Identifier, ReadSettings.ProcessSettings(ReadSettings.String4Color_CB_Identifier) }, // Colorblind B String Color (HEX) | Green
                { ReadSettings.String5Color_CB_Identifier, ReadSettings.ProcessSettings(ReadSettings.String5Color_CB_Identifier) }, // Colorblind High E String Color (HEX) | Purple
            }},
            {"[Mod Settings]", new Dictionary<string, string>
            {
                { ReadSettings.ExtendedRangeTuningIdentifier, ReadSettings.ProcessSettings(ReadSettings.ExtendedRangeTuningIdentifier) }, // Enable Extended Range Mode When Low E Is X Below E
                { ReadSettings.CheckForNewSongIntervalIdentifier, ReadSettings.ProcessSettings(ReadSettings.CheckForNewSongIntervalIdentifier) }, // Enumerate new CDLC / ODLC every X ms
                { ReadSettings.RiffRepeaterSpeedIntervalIdentifier, ReadSettings.ProcessSettings(ReadSettings.RiffRepeaterSpeedIntervalIdentifier) }, // The rate of how much one key press should gain the Riff Repeater speed.
                { ReadSettings.TuningPedalIdentifier, ReadSettings.ProcessSettings(ReadSettings.TuningPedalIdentifier) }, // What tuning pedal does the user use?
                { ReadSettings.VolumeControlIntervalIdentifier, ReadSettings.ProcessSettings(ReadSettings.VolumeControlIntervalIdentifier) }, // By what number should we increase / decrease the volume.
            }},
            {"[Guitar Speak]", new Dictionary<string, string>
            {
                { ReadSettings.GuitarSpeakDeleteIdentifier, ReadSettings.ProcessSettings(ReadSettings.GuitarSpeakDeleteIdentifier) }, // Guitar Speak Press Delete When Midi Note = (0{C-1} - 96{C7})
                { ReadSettings.GuitarSpeakSpaceIdentifier, ReadSettings.ProcessSettings(ReadSettings.GuitarSpeakSpaceIdentifier) }, // Guitar Speak Press Space " " When Midi Note = (0{C-1} - 96{C7})
                { ReadSettings.GuitarSpeakEnterIdentifier, ReadSettings.ProcessSettings(ReadSettings.GuitarSpeakEnterIdentifier) }, // Guitar Speak Press Enter / Return When Midi Note = (0{C-1} - 96{C7})
                { ReadSettings.GuitarSpeakTabIdentifier, ReadSettings.ProcessSettings(ReadSettings.GuitarSpeakTabIdentifier) }, // Guitar Speak Press Tab When Midi Note = (0{C-1} - 96{C7})
                { ReadSettings.GuitarSpeakPGUPIdentifier, ReadSettings.ProcessSettings(ReadSettings.GuitarSpeakPGUPIdentifier) }, // Guitar Speak Press Page Up When Midi Note = (0{C-1} - 96{C7})
                { ReadSettings.GuitarSpeakPGDNIdentifier, ReadSettings.ProcessSettings(ReadSettings.GuitarSpeakPGDNIdentifier) }, // Guitar Speak Press Page Down When Midi Note = (0{C-1} - 96{C7})
                { ReadSettings.GuitarSpeakUPIdentifier, ReadSettings.ProcessSettings(ReadSettings.GuitarSpeakUPIdentifier) }, // Guitar Speak Press Up Arrow When Midi Note = (0{C-1} - 96{C7})
                { ReadSettings.GuitarSpeakDNIdentifier, ReadSettings.ProcessSettings(ReadSettings.GuitarSpeakDNIdentifier) }, // Guitar Speak Press Down Arrow When Midi Note = (0{C-1} - 96{C7})
                { ReadSettings.GuitarSpeakESCIdentifier, ReadSettings.ProcessSettings(ReadSettings.GuitarSpeakESCIdentifier) }, // Guitar Speak Press Escape When Midi Note = (0{C-1} - 96{C7})
                { ReadSettings.GuitarSpeakCloseIdentifier, ReadSettings.ProcessSettings(ReadSettings.GuitarSpeakCloseIdentifier) }, // Stop using Guitar Speak when Midi Note = (0{C-1} - 96{C7})
                { ReadSettings.GuitarSpeakOBracketIdentifier, ReadSettings.ProcessSettings(ReadSettings.GuitarSpeakOBracketIdentifier) }, // Guitar Speak Press Open Bracket "{" When Midi Note = (0{C-1} - 96{C7})
                { ReadSettings.GuitarSpeakCBracketIdentifier, ReadSettings.ProcessSettings(ReadSettings.GuitarSpeakCBracketIdentifier) }, // Guitar Speak Press Close Bracket "}" When Midi Note = (0{C-1} - 96{C7})
                { ReadSettings.GuitarSpeakTildeaIdentifier, ReadSettings.ProcessSettings(ReadSettings.GuitarSpeakTildeaIdentifier) }, // Guitar Speak Press Tilde / Tilda "~" When Midi Note = (0{C-1} - 96{C7})
                { ReadSettings.GuitarSpeakForSlashIdentifier, ReadSettings.ProcessSettings(ReadSettings.GuitarSpeakForSlashIdentifier) }, // Guitar Speak Press Forward Slash "/" When Midi Note = (0{C-1} - 96{C7})
                { ReadSettings.GuitarSpeakTuningIdentifier, ReadSettings.ProcessSettings(ReadSettings.GuitarSpeakTuningIdentifier) },  // Use Guitar Speak in Tuning Menus
            }},
            {"[Highway Colors]", new Dictionary<string, string>
            {
                { ReadSettings.CustomHighwayColorsIdentifier, ReadSettings.ProcessSettings(ReadSettings.CustomHighwayColorsIdentifier) }, // Should we use Custom Noteway Colors
                { ReadSettings.CustomHighwayNumberedIdentifier, ReadSettings.ProcessSettings(ReadSettings.CustomHighwayNumberedIdentifier) }, // Numbered Frets Color
                { ReadSettings.CustomHighwayUnNumberedIdentifier, ReadSettings.ProcessSettings(ReadSettings.CustomHighwayUnNumberedIdentifier) }, // UnNumbered Frets Color
                { ReadSettings.CustomHighwayGutterIdentifier, ReadSettings.ProcessSettings(ReadSettings.CustomHighwayGutterIdentifier) }, // Sides of Note Highway Color
                { ReadSettings.CustomFretNubmersIdentifier, ReadSettings.ProcessSettings(ReadSettings.CustomFretNubmersIdentifier) }, // Fret Numbers Color
            }},
            {"[GUI Settings]", new Dictionary<string, string>
            {
                { ReadSettings.CustomGUIThemeIdentifier, ReadSettings.ProcessSettings(ReadSettings.CustomGUIThemeIdentifier) }, // Use a Custom GUI theme.
                { ReadSettings.CustomGUIBackgroundColorIdentifier, ReadSettings.ProcessSettings(ReadSettings.CustomGUIBackgroundColorIdentifier) }, // Custom Theme Background Color
                { ReadSettings.CustomGUITextColorIdentifier, ReadSettings.ProcessSettings(ReadSettings.CustomGUITextColorIdentifier) }, // Custom Theme Text Color
                { ReadSettings.BackupProfileIdentifier, ReadSettings.ProcessSettings(ReadSettings.BackupProfileIdentifier) }, // Should we backup the user's profile
                { ReadSettings.NumberOfBackupsIdentifier, ReadSettings.ProcessSettings(ReadSettings.NumberOfBackupsIdentifier) } // How many backups should we store before we start deleting them
            }},
        };
        #endregion
        #region Write Settings
        public static void WriteINI(Dictionary<string, Dictionary<string, string>> DictionaryToWrite)
        {
            using (StreamWriter sw = File.CreateText(Path.Combine(GenUtil.GetRSDirectory(), "RSMods.ini")))
            {
                foreach (string section in DictionaryToWrite.Keys)
                {
                    sw.WriteLine(section);
                    foreach (KeyValuePair<string, string> entry in DictionaryToWrite[section])
                    {
                        sw.WriteLine(entry.Key + entry.Value);
                    }
                }
            }
        }
        #endregion
        #region Is RS Void
        public static void IsVoid(string installLocation) // Anti-Piracy Check (False = Real, True = Pirated) || Modified from Beat Saber Mod Assistant
        {
            if(File.Exists(Path.Combine(installLocation, "IGG-GAMES.COM.url")) || File.Exists(Path.Combine(installLocation, "SmartSteamEmu.ini")) || File.Exists(Path.Combine(installLocation, "GAMESTORRENT.CO.url")) || File.Exists(Path.Combine(installLocation, "Codex.ini")) || File.Exists(Path.Combine(installLocation, "Skidrow.ini")))
            {
                MessageBox.Show("You're pretty stupid. The DLL that works with this GUI, doesn't support pirated copies.", "ARGGGG", MessageBoxButtons.OK, MessageBoxIcon.Error);
                Process.Start("https://store.steampowered.com/app/221680/");
                Environment.Exit(1);
                return;
            }  
        }
        #endregion
    }
}
