//===- LC3bCallingConv.td - Calling Conventions for LC3b ---*- tablegen -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
// This describes the calling conventions for LC3b architecture.
//===----------------------------------------------------------------------===//

/// CCIfSubtarget - Match if the current subtarget has a feature F.

class CCIfSubtarget<string F, CCAction A>: CCIf<!strconcat("State.getTarget().getSubtarget<LC3bSubtarget>().", F), A>; 

def CSR_O32 : CalleeSavedRegs<(add LR, FP,(sequence "S%u", 2, 0))>;







//===-- LC3bCallingConv.td - Calling Conventions for LC3b --*- tablegen -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
// This describes the calling conventions for LC3b architecture.
//===----------------------------------------------------------------------===//

/// CCIfSubtarget - Match if the current subtarget has a feature F.

class CCIfSubtarget<string F, CCAction A> : CCIf<!strconcat("State.getTarget().getSubtarget<LC3bSubtarget>().", F), A>;

def RetCC_LC3bEABI : CallingConv<[
  // i16 are returned in registers R0, R1, R2, R3, R4
  CCIfType<[i16], CCAssignToReg<[R0, R1, R2, R3, R4]>>
]>;

//===----------------------------------------------------------------------===//
// LC3b EABI Calling Convention
//===----------------------------------------------------------------------===//

def CC_LC3bEABI : CallingConv<[
  // Promote i8 arguments to i16.
  CCIfType<[i8], CCPromoteToType<i16>>,
  // Integer values get stored in stack slots that are 2 bytes in
  // size and 2-byte aligned.
  CCIfType<[i16], CCAssignToStack<6, 6>>
]>;


//===----------------------------------------------------------------------===//
// LC3b Calling Convention Dispatch
//===----------------------------------------------------------------------===//

def CC_LC3b : CallingConv<[ CCDelegateTo<CC_LC3bEABI> ]>;


def RetCC_LC3b : CallingConv<[ CCDelegateTo<RetCC_LC3bEABI> ]>; // lbd document - mark - def RetCC_LC3b

def CSR_O16 : CalleeSavedRegs<(add R7, R6, (sequence "S%u", 2, 0))>;
