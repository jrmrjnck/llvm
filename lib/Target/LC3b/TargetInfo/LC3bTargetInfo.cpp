//===-- LC3bTargetInfo.cpp - LC3b Target Implementation ---------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include "LC3b.h"
#include "llvm/IR/Module.h"
#include "llvm/Support/TargetRegistry.h"

using namespace llvm;

Target llvm::TheLC3bTarget;

extern "C" void LLVMInitializeLC3bTargetInfo() { 
  RegisterTarget<Triple::lc3b> 
    X(TheLC3bTarget, "lc3b", "LC3b [experimental]");
}
