//===-- LC3bRegisterInfo.h - LC3b Register Information Impl -----*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// \brief This file contains the LC-3b implementation of the MRegisterInfo 
///        class
///
//===----------------------------------------------------------------------===//

#ifndef LC3BREGISTERINFO_H
#define LC3BREGISTERINFO_H

#include "LC3b.h"
#include "llvm/Target/TargetRegisterInfo.h"
#include "llvm/ADT/BitVector.h"

#define GET_REGINFO_HEADER
#include "LC3bGenRegisterInfo.inc"

namespace llvm
{
class LC3bTargetMachine;

class LC3bRegisterInfo : public LC3bGenRegisterInfo
{
   LC3bTargetMachine& TM;

public:
   // Defined in .cpp file
   LC3bRegisterInfo(LC3bTargetMachine& tm);

   // Implement pure virtual functions from TargetRegisterInfo
//   const uint16_t* getCalleeSavedRegs(const MachineFunction* MF = 0) const;
  
   BitVector getReservedRegs(const MachineFunction& MF) const;

//   void eliminateFrameIndex(MachineBasicBlock::iterator MI,
//                            int SPAdj, unsigned FIOperandNum,
//                            RegScavenger *RS = NULL) const;

//   unsigned getFrameRegister(const MachineFunction &MF) const;
};

}

#endif // !LC3BREGISTERINFO_H
