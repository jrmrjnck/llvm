//===-- LC3bInstLower.cpp - Convert LC3b MachineInstr to an MCInst --------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains code to lower LC-3b MachineInstrs to their corresponding
// MCInst records.
//
//===----------------------------------------------------------------------===//

#include "LC3bMCInstLower.h"
#include "LC3bAsmPrinter.h"
#include "LC3bInstrInfo.h"
#include "MCTargetDesc/LC3bBaseInfo.h"
#include "llvm/CodeGen/MachineFunction.h"
#include "llvm/CodeGen/MachineInstr.h"
#include "llvm/CodeGen/MachineOperand.h"
#include "llvm/MC/MCContext.h"
#include "llvm/MC/MCExpr.h"
#include "llvm/MC/MCInst.h"
#include "llvm/Target/Mangler.h"

using namespace llvm;

LC3bMCInstLower::LC3bMCInstLower(LC3bAsmPrinter &asmprinter) : AsmPrinter(asmprinter) {}

void LC3bMCInstLower::Initialize(Mangler *M, MCContext* C) {
	Mang = M;
	Ctx = C;
}

MCOperand LC3bMCInstLower::LowerSymbolOperand(const MachineOperand &MO, MachineOperandType MOTy, unsigned Offset) const {
	MCSymbolRefExpr::VariantKind Kind;
	const MCSymbol *Symbol;
	switch(MO.getTargetFlags()) {
		default:
			llvm_unreachable("Invalid target flag!");
	}
	switch (MOTy) {
		case MachineOperand::MO_GlobalAddress:
         // FIXME
			//Symbol = Mang->getSymbol(MO.getGlobal());
			break;
		default:
			llvm_unreachable("<unknown operand type>");
	}
	const MCSymbolRefExpr *MCSym = MCSymbolRefExpr::Create(Symbol, Kind, *Ctx);
	if (!Offset)
		return MCOperand::CreateExpr(MCSym);
	// Assume offset is never negative.
	assert(Offset > 0);
	const MCConstantExpr *OffsetExpr = MCConstantExpr::Create(Offset, *Ctx);
	const MCBinaryExpr *AddExpr = MCBinaryExpr::CreateAdd(MCSym, OffsetExpr, *Ctx);
	return MCOperand::CreateExpr(AddExpr);
}

MCOperand LC3bMCInstLower::LowerOperand(const MachineOperand& MO, unsigned offset) const {
	MachineOperandType MOTy = MO.getType();
	switch (MOTy) {
		default: llvm_unreachable("unknown operand type");
		case MachineOperand::MO_Register:
			// Ignore all implicit register operands.
			if (MO.isImplicit()) break;
			return MCOperand::CreateReg(MO.getReg());
		case MachineOperand::MO_Immediate:
			return MCOperand::CreateImm(MO.getImm() + offset);
		case MachineOperand::MO_RegisterMask:
			break;
	}
	return MCOperand();
}

void LC3bMCInstLower::Lower(const MachineInstr *MI, MCInst &OutMI) const {
	OutMI.setOpcode(MI->getOpcode());
	for (unsigned i = 0, e = MI->getNumOperands(); i != e; ++i) {
		const MachineOperand &MO = MI->getOperand(i);
		MCOperand MCOp = LowerOperand(MO);
		if (MCOp.isValid())
			OutMI.addOperand(MCOp);
	}
}
