//===-- LC3bInstPrinter.cpp - Convert LC3b MCInst to assembly syntax ------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This class prints an LC3b MCInst to a .s file.
//
//===----------------------------------------------------------------------===//

#define DEBUG_TYPE "asm-printer"
#include "LC3bInstPrinter.h"
#include "LC3b.h"
#include "llvm/MC/MCAsmInfo.h"
#include "llvm/MC/MCExpr.h"
#include "llvm/MC/MCInst.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Support/FormattedStream.h"
using namespace llvm;


// Include the auto-generated portion of the assembly writer.
#include "LC3bGenAsmWriter.inc"

void LC3bInstPrinter::printInst(const MCInst *MI, raw_ostream &O,
                                  StringRef Annot) {
}

void LC3bInstPrinter::printPCRelImmOperand(const MCInst *MI, unsigned OpNo,
                                             raw_ostream &O) {
}

void LC3bInstPrinter::printOperand(const MCInst *MI, unsigned OpNo,
                                     raw_ostream &O, const char *Modifier) {
}

void LC3bInstPrinter::printSrcMemOperand(const MCInst *MI, unsigned OpNo,
                                           raw_ostream &O,
                                           const char *Modifier) {
}

void LC3bInstPrinter::printCCOperand(const MCInst *MI, unsigned OpNo,
                                       raw_ostream &O) {
}
