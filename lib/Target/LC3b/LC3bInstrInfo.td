//===- LC3bInstrInfo.td - Target Description for LC3b Target -*- tablegen -*-=//
//
//						The LLVM Compiler Infrastructure
//
// This file is a project of EE382V, Code Generation and Optimization course,
// at the University of Texas at Austin
//
//===----------------------------------------------------------------------===//

include "LC3bInstrFormats.td"

def ADDrr : rrForm<0x1, (outs LC3bRegs:$dst), (ins LC3bRegs:$src1, LC3bRegs:$src2),
                   "", [(set LC3bRegs:$dst, (add LC3bRegs:$src1, LC3bRegs:$src2))]>;

/*def ADDri :*/

/*def ANDrr :*/

/*def ANDri :*/

/*def BR :*/

/*def JMP :*/

/*def JSRi :*/

/*def JSRr :*/

/*def LDB :*/

/*def LDW :*/

/*def LEA :*/

/*def RTI :*/

/*def LSHF :*/

/*def RSHFL :*/

/*def RSHFA :*/

/*def STB :*/

/*def STW :*/

/*def TRAP :*/

/*def XORrr :*/

/*def XORri :*/
