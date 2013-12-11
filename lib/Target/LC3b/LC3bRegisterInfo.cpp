//===-- LC3bRegisterInfo.cpp.cpp - LC3b Register Information --------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the LC-3b implementation of the TargetRegisterInfo class.
//
//===----------------------------------------------------------------------===//

#include "LC3bRegisterInfo.h"

#define GET_REGINFO_ENUM
#define GET_REGINFO_TARGET_DESC
#include "LC3bGenRegisterInfo.inc"

#include <cassert>

using namespace llvm;

// Use return address register to initialize LC3bRegisterInfo
LC3bRegisterInfo::LC3bRegisterInfo(const LC3bTargetMachine& TM) : LC3bGenRegisterInfo(LC3b::R7){}

// No callee-saved registers in LC3b
//const uint16_t* LC3bRegisterInfo::getCalleeSavedRegs(const MachineFunction* MF) const{}

BitVector LC3bRegisterInfo::getReservedRegs(const MachineFunction& MF) const
{
   static const uint16_t ReservedLC3bRegs[] = {
      LC3b::R6, LC3b::R7, LC3b::PC, LC3b::PSR, LC3b::IR
   };
   BitVector Reserved(getNumRegs());
   typedef TargetRegisterClass::iterator RegIter;
   
   for(unsigned I = 0; I < array_lengthof(ReservedLC3bRegs); ++I){
      Reserved.set(ReservedLC3bRegs[I]);
   }
   
   return Reserved;
}

// No frame pointer in LC3b
//void LC3bRegisterInfo::eliminateFrameIndex(MachineBasicBlock::iterator MI,
//                         int SPAdj, unsigned FIOperandNum,
//                         RegScavenger *RS) const
//{}

// No frame pointer in LC3b
//unsigned LC3bRegisterInfo::getFrameRegister(const MachineFunction &MF) const{}
