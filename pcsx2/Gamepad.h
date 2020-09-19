/*  PCSX2 - PS2 Emulator for PCs
 *  Copyright (C) 2002-2020  PCSX2 Dev Team
 *
 *  PCSX2 is free software: you can redistribute it and/or modify it under the terms
 *  of the GNU Lesser General Public License as published by the Free Software Found-
 *  ation, either version 3 of the License, or (at your option) any later version.
 *
 *  PCSX2 is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 *  without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *  PURPOSE.  See the GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along with PCSX2.
 *  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "Common.h"
#include "PrecompiledHeader.h"
// basic funcs

s32 PADinit(u32 flags);
s32 PADopen(void *pDsp);
void PADclose();
void PADshutdown();
void PADsetSettingsDir(const char *dir);
void PADsetLogDir(const char *dir);

// PADkeyEvent is called every vsync (return NULL if no event)
keyEvent* PADkeyEvent();
u8 PADstartPoll(int pad);
u8 PADpoll(u8 value);
// returns: 1 if supported pad1
//			2 if supported pad2
//			3 if both are supported
u32 PADquery();
s32 PADsetSlot(u8 port, u8 slot);

// call to give a hint to the PAD plugin to query for the keyboard state. A
// good plugin will query the OS for keyboard state ONLY in this function.
// This function is necessary when multithreading because otherwise
// the PAD plugin can get into deadlocks with the thread that really owns
// the window (and input). Note that PADupdate can be called from a different
// thread than the other functions, so mutex or other multithreading primitives
// have to be added to maintain data integrity.
void PADupdate(int pad);

// Send a key event from wx-gui to pad
// Note: On linux GSOpen2, wx-gui and pad share the same event buffer. Wx-gui reads and deletes event
// before the pad saw them. So the gui needs to send them back to the pad.
void PADWriteEvent(keyEvent &evt);
	// extended funcs

void PADgsDriverInfo(GSdriverInfo *info);
void PADconfigure();
void PADabout();
s32 PADtest();
