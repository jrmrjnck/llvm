# Be sure to add your build dir to your path so that the new clang and llc binaries are used
# (e.g. `PATH=~/llvm/Debug+Asserts/bin:$PATH make`)

all : test.s

test.ll : test.c
	clang -S -emit-llvm test.c -o test.ll

test.s : test.ll
	llc -march=lc3b test.ll -o test.s --stats
