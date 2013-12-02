//===-- LC3bDagToDagISel.cpp - A dag to dag inst selector for LC3b --------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file defines an instruction selector for the LC-3b target.
//
//===----------------------------------------------------------------------===//

#include "LC3bTargetMachine.h"
#include "LC3bSubtarget.h"
#include "llvm/CodeGen/SelectionDAGISel.h"

using namespace llvm;

namespace
{
   class LC3bDagToDagISel : public SelectionDAGISel
   {
      const LC3bSubtarget& Subtarget;

   public:
      explicit LC3bDagToDagISel( LC3bTargetMachine& tm, CodeGenOpt::Level optLevel )
       : SelectionDAGISel(tm,optLevel),
         Subtarget(*tm.getSubtargetImpl())
      {}

      const char* getPassName() const
      {
         return "LC3b DAG->DAG Pattern Instruction Selection";
      }

   private:
      SDNode* Select( SDNode* n );

      #include "LC3bGenDAGISel.inc"
   };
}

SDNode* LC3bDagToDagISel::Select( SDNode* n )
{
   // FIXME
   return NULL;
}

FunctionPass* llvm::createLC3bISelDag( LC3bTargetMachine& tm, CodeGenOpt::Level optLevel )
{
   return new LC3bDagToDagISel( tm, optLevel );
}
