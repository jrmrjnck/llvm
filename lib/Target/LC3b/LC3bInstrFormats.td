//===-- LC3bInstrFormats.td - LC-3b Instruction Formats ----*- tablegen -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source 
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

class Format<bits<3> val> {
   bits<3> Value = val;
}

def PseudoFrm  : Format<0>;
def NoSrc      : Format<1>;
def OneSrc     : Format<2>;
def DestOneSrc : Format<3>;
def DestTwoSrc : Format<4>;

class SourceMode<bits<2> val> {
   bits<2> Value = val;
}

def SrcReg : SourceMode<0>;
def SrcMem : SourceMode<1>;
def SrcImm : SourceMode<2>;

class DestMode<bit val> {
   bit Value = val;
}

def DstReg : DestMode<0>;
def DstMem : DestMode<1>;

class LC3bInst<bits<4> opcode, dag outs, dag ins, Format f, string asmstr> : Instruction
{
   field bits<16> Inst;

   let Namespace = "LC3b";

   let OutOperandList = outs;
   let InOperandList  = ins;
   let AsmString      = asmstr;

   Format form = f;

   // Define how we want to layout out TargetSpecific information field... this
   // should be kept up-to-date with the fields in LC3bInstrInfo.h.
   let TSFlags{2-0} = f.Value;

   let Inst{15-12} = opcode;
}

class DestTwoSrcForm<bits<4> opcode, SourceMode src1, SourceMode src2,
                     dag outs, dag ins, string asmstr, list<dag> pattern>
 : LC3bInst<opcode, outs, ins, DestTwoSrc, asmstr>
{
   let Pattern = pattern;
}

class rrForm<bits<4> opcode, dag outs, dag ins, string asmstr, list<dag> pattern>
 : DestTwoSrcForm<opcode, SrcReg, SrcReg, outs, ins, asmstr, pattern>
{
   let Inst{5-3} = 0;
}
