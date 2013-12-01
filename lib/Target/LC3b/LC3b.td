//===-- LC3b.td --------------------------------------------*- tablegen -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source 
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This is top level entry for LC3b target
//
//===----------------------------------------------------------------------===//

include "llvm/Target/Target.td"

include "LC3bRegisterInfo.td"
include "LC3bSchedule.td"
include "LC3bInstrInfo.td"

def LC3bInstrInfo : InstrInfo;

//===----------------------------------------------------------------------===//
// LC3b processors supported.
//===----------------------------------------------------------------------===//

class Proc<string Name, list<SubtargetFeature> Features> 
 : Processor<Name, LC3bGenericItineraries, Features>;

def : Proc<"generic", []>;

def LC3bInstPrinter : AsmWriter {
	string AsmWriterClassName = "InstPrinter";
	bit isMCAsmWriter = 1;
}

// Will generate LC3bGenAsmWrite.inc included by LC3bInstPrinter.cpp, contents
// as follows,
// void LC3bInstPrinter::printInstruction(const MCInst *MI, raw_ostream &O) {...}
// const char *LC3bInstPrinter::getRegisterName(unsigned RegNo) {...}

def LC3b : Target {
	let InstructionSet = LC3bInstrInfo;
	let AssemblyWriters = [LC3bInstPrinter];
}
