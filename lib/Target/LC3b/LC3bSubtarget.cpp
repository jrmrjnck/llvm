//===-- LC3bSubtarget.cpp - LC3b Subtarget Information --------------------===//
//
//                    The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file implements the LC3b specific subclass of TargetSubtargetInfo.
//
//===----------------------------------------------------------------------===//

#include "LC3bSubtarget.h"
#include "LC3b.h"
#include "llvm/Support/TargetRegistry.h"

#define GET_SUBTARGETINFO_ENUM
#define GET_SUBTARGETINFO_TARGET_DESC
#define GET_SUBTARGETINFO_CTOR
#include "LC3bGenSubtargetInfo.inc"

using namespace llvm;

void LC3bSubtarget::anchor() {}

LC3bSubtarget::LC3bSubtarget(const std::string &TT,
                             const std::string &CPU,
                             const std::string &FS)
 : LC3bGenSubtargetInfo(TT, CPU, FS)
{
   std::string CPUName = CPU;
   if (CPUName.empty())
      CPUName = "generic";
   // Parse features string.
   ParseSubtargetFeatures(CPUName, FS);

   // FIXME
   // Initialize scheduling itinerary for the specified CPU.
   //InstrItins = getInstrItineraryForCPU(CPUName);
}
