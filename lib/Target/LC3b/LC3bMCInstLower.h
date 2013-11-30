//==-- LC3bMCInstLower.h - Convert LC3b MachineInstr to an MCInst -*-C++-*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains code to lower LC3b MachineInstrs to their corresponding
// MCInst records.
//
//===----------------------------------------------------------------------===//

#ifndef LC3BMCINSTLOWER_H
#define LC3BMCINSTLOWER_H

#include "llvm/ADT/SmallVector.h"
#include "llvm/CodeGen/MachineOperand.h"
#include "llvm/Support/Compiler.h"

namespace llvm {

class MCContext;
class MCInst;
class MCOperand;
class MachineInstr;
class MachineFunction;
class Mangler;
class LC3bAsmPrinter;
/// LC3bMCInstLower - This class is used to lower an MachineInstr into an MCInst.
class LLVM_LIBRARY_VISIBILITY LC3bMCInstLower {
	typedef MachineOperand::MachineOperandType MachineOperandType;
	MCContext *Ctx;
	Mangler *Mang;
	LC3bAsmPrinter &AsmPrinter;
public:
	LC3bMCInstLower(LC3bAsmPrinter &asmprinter);
	void Initialize(Mangler *mang, MCContext* C);
	void Lower(const MachineInstr *MI, MCInst &OutMI) const;
private:
	MCOperand LowerSymbolOperand(const MachineOperand &MO,
	MachineOperandType MOTy, unsigned Offset) const;
	MCOperand LowerOperand(const MachineOperand& MO, unsigned offset = 0) const;
};
}

#endif // !LC3BMCINSTLOWER_H
