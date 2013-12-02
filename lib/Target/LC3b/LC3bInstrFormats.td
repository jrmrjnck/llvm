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
   bits<3> src1;
   bits<3> src2;
   bits<3> dst;
   let Pattern = pattern;  
   let Inst{2-0}=src1;
   let Inst{8-6}=src2;
   let Inst{11-9}=dst;
}



class DestOneSrcForm<bits<4> opcode, SourceMode immsext5, SourceMode src2,
                     dag outs, dag ins, string asmstr, list<dag> pattern>
 : LC3bInst<opcode, outs, ins, DestOneSrc, asmstr>
{
   bits<5> immsext5;
   bits<3> src2;
   bits<3> dst;
   let Pattern = pattern;  
   let Inst{4-0}=immsext5;
   let Inst{8-6}=src2;
   let Inst{11-9}=dst;
}


class DestOneSrcForm_load<bits<4> opcode, SourceMode immsext5, SourceMode src2,
                     dag outs, dag ins, string asmstr, list<dag> pattern>
 : LC3bInst<opcode, outs, ins, DestOneSrc, asmstr>
{
   bits<6> immsext6;
   bits<3> src2;
   bits<3> dst;
   let Pattern = pattern;  
   let Inst{5-0}=immsext6;
   let Inst{8-6}=src2;
   let Inst{11-9}=dst;
}

class DestOneSrcForm_shf<bits<4> opcode, SourceMode immext4, SourceMode src2,
                     dag outs, dag ins, string asmstr, list<dag> pattern>
 : LC3bInst<opcode, outs, ins, DestOneSrc, asmstr>
{
   bits<4> immext4;
   bits<3> src2;
   bits<3> dst;
   let Pattern = pattern;  
   let Inst{3-0}=immext4;
   let Inst{8-6}=src2;
   let Inst{11-9}=dst;
}




class DestOneSrcForm_lea<bits<4> opcode, SourceMode immsext9, dag outs, dag ins, string asmstr, list<dag> pattern>
 : LC3bInst<opcode, outs, ins, DestOneSrc, asmstr>
{
   bits<9> immsext9;
   bits<3> dst;
   let Pattern = pattern;  
   let Inst{8-0}=immsext9;
   let Inst{11-9}=dst;
}

























class rrForm<bits<4> opcode, dag outs, dag ins, string asmstr, list<dag> pattern>
 : DestTwoSrcForm<opcode, SrcReg, SrcReg, outs, ins, asmstr, pattern>
{
   let Inst{5-3} = 0;
   
}


class riForm<bits<4> opcode, dag outs, dag ins, string asmstr, list<dag> pattern>
 : DestOneSrcForm<opcode, SrcImm, SrcReg, outs, ins, asmstr, pattern>
{
   let Inst{5} = 1;
}



class memForm<bits<4> opcode, dag outs, dag ins, string asmstr, list<dag> pattern>
 : DestOneSrcForm_load<opcode, SrcMem, SrcReg, outs, ins, asmstr, pattern>
{

}

class shfForm<bits<4> opcode,bits<2> select, dag outs, dag ins, string asmstr, list<dag> pattern>
 : DestOneSrcForm_shf<opcode, SrcImm, SrcReg, outs, ins, asmstr, pattern>
{
	let Inst {6-5}=select;
}

class leaForm<bits<4> opcode,dag outs, dag ins, string asmstr, list<dag> pattern>
 : DestOneSrcForm_lea<opcode, SrcImm,outs, ins, asmstr, pattern>
{
	
}




