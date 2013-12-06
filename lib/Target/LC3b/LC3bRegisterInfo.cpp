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

const uint16_t* LC3bRegisterInfo::getCalleeSavedRegs(const MachineFunction* MF) const
{
   // FIXME
   //assert(false && "Unimplemented");
   return NULL;
}

BitVector LC3bRegisterInfo::getReservedRegs(const MachineFunction& MF) const
{
   // FIXME
   //assert(false && "Unimplemented");
   return BitVector(9,false);
}

void LC3bRegisterInfo::eliminateFrameIndex(MachineBasicBlock::iterator MI,
                         int SPAdj, unsigned FIOperandNum,
                         RegScavenger *RS) const
{
   // FIXME
   //assert(false && "Unimplemented");
}

unsigned LC3bRegisterInfo::getFrameRegister(const MachineFunction &MF) const
{
   // FIXME
   //assert(false && "Unimplemented");
   return unsigned();
}
