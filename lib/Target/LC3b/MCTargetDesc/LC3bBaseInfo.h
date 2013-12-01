//===-- LC3bBaseInfo.h - Top level definitions for LC3b MC ------*- C++ -*-===//
//
// The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains small standalone helper functions and enum definitions for
// the LC3b target useful for the compiler back-end and the MC libraries.
//
//===----------------------------------------------------------------------===//

#ifndef LC3BBASEINFO_H
#define LC3BBASEINFO_H

#include "LC3bFixupKinds.h"
#include "LC3bMCTargetDesc.h"
#include "llvm/MC/MCExpr.h"
#include "llvm/Support/DataTypes.h"
#include "llvm/Support/ErrorHandling.h"

namespace llvm {
   // LC3bII - This namespace holds all of the target specific flags that
   // instruction info tracks.
   namespace LC3bII {
      /// Target Operand Flag enum.
      enum {
         //===------------------------------------------------------------------===//
         // Instruction encodings. These are the standard/most common forms for
         // LC3b instructions.
         //
         // Pseudo - This represents an instruction that is a pseudo instruction
         // or one that has not been implemented yet. It is illegal to code generate
         // it, but tolerated for intermediate implementation stages.
         //FIXME
         Pseudo = 0,
         NoSrc = 1,
         OneSrc = 2,
         DestOneSrc = 3,
         DestTwoSrc = 4,

         //FIXME
         FormMask = 7 
      };
   }
   /// getLC3bRegisterNumbering - Given the enum value for some register,
   /// return the number that it corresponds to.
   inline static unsigned getLC3bRegisterNumbering(unsigned RegEnum)
   {
      switch (RegEnum) {
         //FIXME
         case LC3b::R0:
            return 0;
         case LC3b::R1:
            return 1;
         case LC3b::R2:
            return 2;
         case LC3b::R3:
            return 3;
         case LC3b::R4:
            return 4;
         case LC3b::R5:
            return 5;
         case LC3b::R6:
            return 6;
         case LC3b::R7:
            return 7;
         default: llvm_unreachable("Unknown register number!");
      }
   }
}

#endif // !LC3BBASEINFO_H
