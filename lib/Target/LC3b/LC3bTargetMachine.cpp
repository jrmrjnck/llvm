//===-- LC3bTargetMachine.cpp - LC3b Target Spec ----------------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// Implements the info about LC3b target spec.
//
//===----------------------------------------------------------------------===//

#include "LC3bTargetMachine.h"
#include "LC3b.h"
#include "llvm/PassManager.h"
#include "llvm/CodeGen/Passes.h"
#include "llvm/Support/TargetRegistry.h"

using namespace llvm;

extern "C" void LLVMInitializeLC3bTarget() {
	RegisterTargetMachine<LC3bTargetMachine> X(TheLC3bTarget);
}

// The stack is always 8 byte aligned
// On function prologue, the stack is created by decrementing
// its pointer. Once decremented, all references are done with positive
// offset from the stack/frame pointer, using StackGrowsUp enables
// an easier handling.
// Using CodeModel::Large enables different CALL behavior.
LC3bTargetMachine::LC3bTargetMachine(const Target &T,
                                     StringRef TT,
                                     StringRef CPU,
                                     StringRef FS,
                                     const TargetOptions &Options,
                                     Reloc::Model RM,
                                     CodeModel::Model CM,
                                     CodeGenOpt::Level OL)
 : LLVMTargetMachine(T, TT, CPU, FS, Options, RM, CM, OL), 
   Subtarget(TT, CPU, FS),
   DL(("e-p:16:16:16-i8:8:8-i16:16:16-n16")),
   InstrInfo(*this), 
   FrameLowering(Subtarget), 
   TLInfo(*this), 
   TSInfo(*this) 
{
   initAsmInfo();
}

namespace {
/// LC3b Code Generator Pass Configuration Options.
class LC3bPassConfig : public TargetPassConfig {
public:
	LC3bPassConfig(LC3bTargetMachine *TM, PassManagerBase &PM)
		: TargetPassConfig(TM, PM) {}
	LC3bTargetMachine &getLC3bTargetMachine() const {
		return getTM<LC3bTargetMachine>();
	}
	const LC3bSubtarget &getLC3bSubtarget() const {
		return *getLC3bTargetMachine().getSubtargetImpl();
	}
};

} // namespace

TargetPassConfig *LC3bTargetMachine::createPassConfig(PassManagerBase &PM) {
	return new LC3bPassConfig(this, PM);
}
