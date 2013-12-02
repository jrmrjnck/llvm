//===-- LC3bAsmPrinter.cpp - LC3b LLVM Assembly Printer -------------------===//
//
//
//					The LLVM Compiler Infrastructure
//
//
//===----------------------------------------------------------------------===//
//
// This file contains a printer that converts from our internal representation
// of machine-dependent LLVM code to GAS-format LC3b assembly language.
//
//===----------------------------------------------------------------------===//

#define DEBUG_TYPE "LC3b-asm-printer"
#include "LC3bAsmPrinter.h"
#include "LC3b.h"
#include "LC3bInstrInfo.h"
#include "InstPrinter/LC3bInstPrinter.h"
#include "MCTargetDesc/LC3bBaseInfo.h"
#include "llvm/ADT/SmallString.h"
#include "llvm/ADT/StringExtras.h"
#include "llvm/ADT/Twine.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Instructions.h"
#include "llvm/CodeGen/MachineFunctionPass.h"
#include "llvm/CodeGen/MachineConstantPool.h"
#include "llvm/CodeGen/MachineFrameInfo.h"
#include "llvm/CodeGen/MachineInstr.h"
#include "llvm/CodeGen/MachineMemOperand.h"
#include "llvm/MC/MCStreamer.h"
#include "llvm/MC/MCAsmInfo.h"
#include "llvm/MC/MCInst.h"
#include "llvm/MC/MCSymbol.h"
#include "llvm/Support/TargetRegistry.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Target/Mangler.h"
#include "llvm/Target/TargetLoweringObjectFile.h"
#include "llvm/Target/TargetOptions.h"
using namespace llvm;

bool LC3bAsmPrinter::runOnMachineFunction(MachineFunction &MF) {
	LC3bFI = MF.getInfo<LC3bFunctionInfo>();
	AsmPrinter::runOnMachineFunction(MF);
	return true;
}

//- EmitInstruction() must exists or will have run time error.
void LC3bAsmPrinter::EmitInstruction(const MachineInstr *MI) {
	if (MI->isDebugValue()) {
		SmallString<128> Str;
		raw_svector_ostream OS(Str);
		PrintDebugValueComment(MI, OS);
		return;
	}
	MCInst TmpInst0;
	MCInstLowering.Lower(MI, TmpInst0);
	OutStreamer.EmitInstruction(TmpInst0);
}

// Functions for printing integers out in LC3b assembly format

void LC3bAsmPrinter::printHex32(unsigned Value, raw_ostream &O) {
	O << "x";
	for (int i = 7; i >= 0; i--)
		O.write_hex((Value & (0xF << (i*4))) >> (i*4));
}

void LC3bAsmPrinter::printHex16(unsigned Value, raw_ostream &O) {
	O << "x";
	for (int i = 7; i >= 0; i--)
		O.write_hex((Value & (0xF << (i*4))) >> (i*4));
}


void LC3bAsmPrinter::printDecimal32(unsigned Value, raw_ostream &O) {
	O << "#";
	O << Value;
}

void LC3bAsmPrinter::printDecimal16(unsigned Value, raw_ostream &O) {
	O << "#";
	O << Value;	
}

//===----------------------------------------------------------------------===//
// Frame and Set directives
//===----------------------------------------------------------------------===//

/////////////////////////////////////////////////////////////////////////
//-> .frame $sp,8,$lr
// .mask 0x00000000,0
// .set noreorder
// .set nomacro
/////////////////////////////////////////////////////////////////////////
/// Frame Directive
void LC3bAsmPrinter::emitFrameDirective() {
	/*const TargetRegisterInfo &RI = *TM.getRegisterInfo();
	unsigned stackReg = RI.getFrameRegister(*MF);
	unsigned returnReg = RI.getRARegister();
	unsigned stackSize = MF->getFrameInfo()->getStackSize();
	if (OutStreamer.hasRawTextSupport())
		OutStreamer.EmitRawText("\t.frame\t$" 
			+ StringRef(LC3bInstPrinter::getRegisterName(stackReg)).lower() 
			+ "," + Twine(stackSize) + ",$" 
			+ StringRef(LC3bInstPrinter::getRegisterName(returnReg)).lower()
			);
	*/
}

/// Emit Set directives.
const char *LC3bAsmPrinter::getCurrentABIString() const {
   llvm_unreachable("Unknown LC3b ABI");;
}

/////////////////////////////////////////////////////////////////////////
// 		.type main,	@function
//	-> 	.ent main # @main
// 	main:
/////////////////////////////////////////////////////////////////////////

void LC3bAsmPrinter::EmitFunctionEntryLabel() {
	if (OutStreamer.hasRawTextSupport()) {
		
	}
	//OutStreamer.EmitRawText("\t.ent\t" + Twine(CurrentFnSym->getName()));
	//OutStreamer.EmitLabel(CurrentFnSym);
}

/// EmitFunctionBodyStart - Targets can override this to emit stuff before
/// the first basic block in the function.

void LC3bAsmPrinter::EmitFunctionBodyStart() {

	MCInstLowering.Initialize(Mang, &MF->getContext());
	emitFrameDirective();
	if (OutStreamer.hasRawTextSupport()) {
		OutStreamer.EmitRawText(".orig x3000 ; Function=" + Twine(CurrentFnSym->getName()));
		OutStreamer.EmitRawText("\n");
	}
}

/// EmitFunctionBodyEnd - Targets can override this to emit stuff after
/// the last basic block in the function.

void LC3bAsmPrinter::EmitFunctionBodyEnd() {

	if (OutStreamer.hasRawTextSupport()) {
		OutStreamer.EmitRawText(".end ; Function=" + Twine(CurrentFnSym->getName()));
	}
	
}

void LC3bAsmPrinter::EmitStartOfAsmFile(Module &M) {
	if (OutStreamer.hasRawTextSupport()) {
		// do nothing
	}
	
}

void LC3bAsmPrinter::EmitEndOfAsmFile(Module &M) {
	if (OutStreamer.hasRawTextSupport()) {
		// do nothing
	}
}


MachineLocation LC3bAsmPrinter::getDebugValueLocation(const MachineInstr *MI) const {
// Handles frame addresses emitted in LC3bInstrInfo::emitFrameIndexDebugValue.
	assert(MI->getNumOperands() == 4 && "Invalid no. of machine operands!");
	assert(MI->getOperand(0).isReg() && MI->getOperand(1).isImm() && "Unexpected MachineOperand types");
	return MachineLocation(MI->getOperand(0).getReg(), MI->getOperand(1).getImm());
}
void LC3bAsmPrinter::PrintDebugValueComment(const MachineInstr *MI, raw_ostream &OS) {
	OS << "PrintDebugValueComment()";
}

// Force static initialization.
extern "C" void LLVMInitializeLC3bAsmPrinter() {
	RegisterAsmPrinter<LC3bAsmPrinter> X(TheLC3bTarget);
}

