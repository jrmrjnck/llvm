##===- lib/Target/LC3b/Makefile --------------------------*- Makefile -*-===##
# 
#                     The LLVM Compiler Infrastructure
#
# This file is distributed under the University of Illinois Open Source 
# License. See LICENSE.TXT for details.
# 
##===----------------------------------------------------------------------===##

LEVEL = ../../..
LIBRARYNAME = LLVMLC3bCodeGen
TARGET = LC3b

# Make sure that tblgen is run, first thing.
BUILT_SOURCES = \
	LC3bGenRegisterInfo.inc\
	LC3bGenInstrInfo.inc\
	LC3bGenSubtargetInfo.inc\
	LC3bGenCodeEmitter.inc\
	LC3bGenMCCodeEmitter.inc\
	LC3bGenAsmWriter.inc\
	LC3bGenCallingConv.inc\
	LC3bGenDAGISel.inc

DIRS = TargetInfo MCTargetDesc InstPrinter 

include $(LEVEL)/Makefile.common
