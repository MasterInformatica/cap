PROGRAM=cholesky

TARGETS=$(PROGRAM)-3 $(PROGRAM)-2 $(PROGRAM)-1 $(PROGRAM)-0 $(PROGRAM)-g

CC = gcc

CFLAGS = -DVERBOSE
CFLAGS_P =

LIBS  = -Wl,-L/usr/lib/lapack/  -lm

EXTRA = -std=c99 -Wall -Wno-unused 

all: $(TARGETS)

$(PROGRAM)-3: $(PROGRAM).c $(MKL_CHECK)
	$(CC) $(GFLAGS) $(CFLAGS) $(CFLAGS_P) $(EXTRA) -O3 $(INCS) -o $@ $< $(LIBS)

$(PROGRAM)-2: $(PROGRAM).c $(MKL_CHECK)
	$(CC) $(GFLAGS) $(CFLAGS) $(CFLAGS_P) $(EXTRA) -O2 $(INCS) -o $@ $< $(LIBS)

$(PROGRAM)-1: $(PROGRAM).c $(MKL_CHECK)
	$(CC) $(GFLAGS) $(CFLAGS) $(CFLAGS_P) $(EXTRA) -O1 $(INCS) -o $@ $< $(LIBS)

$(PROGRAM)-0: $(PROGRAM).c $(MKL_CHECK)
	$(CC) $(GFLAGS) $(CFLAGS) $(CFLAGS_P) $(EXTRA) -O0 $(INCS) -o $@ $< $(LIBS)

$(PROGRAM)-g: $(PROGRAM).c $(MKL_CHECK)
	$(CC) $(GFLAGS) $(CFLAGS) $(CFLAGS_P) $(EXTRA) -g $(INCS) -o $@ $< $(LIBS)


FLAGS_O1 = fauto-inc-dec fbranch-count-reg fcombine-stack-adjustments fcompare-elim fcprop-registers fdce fdefer-pop fdelayed-branch fdse fforward-propagate fguess-branch-probability fif-conversion2 fif-conversion finline-functions-called-once fipa-pure-const fipa-profile fipa-reference fmerge-constants fmove-loop-invariants freorder-blocks fshrink-wrap fsplit-wide-types fssa-backprop fssa-phiopt ftree-bit-ccp ftree-ccp ftree-ch ftree-coalesce-vars ftree-copy-prop ftree-dce ftree-dominator-opts ftree-dse ftree-forwprop ftree-fre ftree-phiprop ftree-sink ftree-slsr ftree-sra ftree-pta ftree-ter funit-at-a-time

FLAGS_O2 = fthread-jumps falign-functions  falign-jumps falign-loops  falign-labels fcaller-saves fcrossjumping fcse-follow-jumps  fcse-skip-blocks fdelete-null-pointer-checks fdevirtualize fdevirtualize-speculatively fexpensive-optimizations fgcse  fgcse-lm  fhoist-adjacent-loads finline-small-functions findirect-inlining fipa-cp fipa-cp-alignment fipa-sra fipa-icf fisolate-erroneous-paths-dereference flra-remat foptimize-sibling-calls foptimize-strlen fpartial-inlining fpeephole2 freorder-blocks-algorithm=stc freorder-blocks-and-partition freorder-functions frerun-cse-after-loop  fsched-interblock  fsched-spec fschedule-insns  fschedule-insns2 fstrict-aliasing fstrict-overflow ftree-builtin-call-dce ftree-switch-conversion ftree-tail-merge ftree-pre ftree-vrp fipa-ra

# -------------> gcc -Q --help=optimi
FLAGS_MINE = Ofast Os falign-functions falign-jumps falign-labels falign-loops fasynchronous-unwind-tables fbranch-count-reg fbranch-probabilities fbranch-target-load-optimize fbranch-target-load-optimize2 fbtr-bb-exclusive fcaller-saves fcombine-stack-adjustments fcommon fcompare-elim fconserve-stack fcprop-registers fcrossjumping fcse-follow-jumps fcx-fortran-rules fcx-limited-range fdata-sections fdce fdefer-pop fdelayed-branch fdelete-null-pointer-checks fdevirtualize fdse fearly-inlining fexceptions fexpensive-optimizations ffinite-math-only ffloat-store fforward-propagate fgcse fgcse-after-reload fgcse-las fgcse-lm fgcse-sm fgraphite-identity fguess-branch-probability fhandle-exceptions fif-conversion fif-conversion2 finline-functions finline-functions-called-once finline-small-functions fipa-cp fipa-cp-clone fipa-matrix-reorg fipa-profile fipa-pta fipa-pure-const fipa-reference fipa-sra fivopts fjump-tables floop-block floop-flatten floop-interchange floop-parallelize-all floop-strip-mine flto-report fltrans fmath-errno fmerge-all-constants fmerge-constants fmodulo-sched fmove-loop-invariants fnon-call-exceptions fnothrow-opt fomit-frame-pointer foptimize-register-move foptimize-sibling-calls fpack-struct fpack-struct=<number> fpeel-loops fpeephole fpeephole2 fpredictive-commoning fprefetch-loop-arrays freg-struct-return fregmove frename-registers freorder-blocks freorder-blocks-and-partition freorder-functions frerun-cse-after-loop freschedule-modulo-scheduled-loops frounding-math frtti fsched-critical-path-heuristic fsched-dep-count-heuristic fsched-group-heuristic fsched-interblock fsched-last-insn-heuristic fsched-pressure fsched-rank-heuristic fsched-spec fsched-spec-insn-heuristic fsched-spec-load fsched-spec-load-dangerous fsched-stalled-insns fsched-stalled-insns-dep fsched2-use-superblocks fschedule-insns fschedule-insns2 fsection-anchors fsel-sched-pipelining fsel-sched-pipelining-outer-loops fsel-sched-reschedule-pipelined fselective-scheduling fselective-scheduling2 fshort-double fshort-enums fshort-wchar fsignaling-nans fsigned-zeros fsingle-precision-constant fsplit-ivs-in-unroller fsplit-wide-types fstrict-aliasing fstrict-enums fthread-jumps fno-threadsafe-statics ftoplevel-reorder ftrapping-math ftrapv ftree-bit-ccp ftree-builtin-call-dce ftree-ccp ftree-ch ftree-copy-prop ftree-copyrename ftree-cselim ftree-dce ftree-dominator-opts ftree-dse ftree-forwprop ftree-fre ftree-loop-distribute-patterns ftree-loop-distribution ftree-loop-if-convert ftree-loop-if-convert-stores ftree-loop-im ftree-loop-ivcanon ftree-loop-optimize ftree-lrs ftree-phiprop ftree-pre ftree-pta ftree-reassoc ftree-scev-cprop ftree-sink ftree-slp-vectorize ftree-sra ftree-switch-conversion ftree-ter ftree-vect-loop-version ftree-vectorize ftree-vrp funit-at-a-time funroll-all-loops funroll-loops funsafe-loop-optimizations funsafe-math-optimizations funswitch-loops funwind-tables fvar-tracking fvar-tracking-assignments fvar-tracking-assignments-toggle fvar-tracking-uninit fvariable-expansion-in-unroller fvect-cost-model fvpt fweb fwhole-program fwpa fwrapv

all_flags_O1: $(PROGRAM).c $(MKL_CHECK)
	$(CC) $(GFLAGS) $(CFLAGS) $(CFLAGS_P) $(EXTRA) -O0 $(INCS) -o $(PROGRAM)_all_O1_NONE $< $(LIBS)
	@$(foreach flag, $(FLAGS_O1) , $(CC) $(GFLAGS) $(GFLAGS) $(CFLAGS_P) $(EXTRA) -$(flag) $(INCS) -o $(PROGRAM)_all_O1_$(flag) $< $(LIBS);)

all_flags_O2: $(PROGRAM).c $(MKL_CHECK)
	$(CC) $(GFLAGS) $(CFLAGS) $(CFLAGS_P) $(EXTRA) -O0 $(INCS) -o $(PROGRAM)_all_O2_NONE $< $(LIBS)
	@$(foreach flag, $(FLAGS_O2) , $(CC) $(GFLAGS) $(GFLAGS) $(CFLAGS_P) $(EXTRA) -$(flag) $(INCS) -o $(PROGRAM)_all_O2_$(flag) $< $(LIBS);)

all_flags_MINE: $(PROGRAM).c $(MKL_CHECK)
	$(CC) $(GFLAGS) $(CFLAGS) $(CFLAGS_P) $(EXTRA) -O0 $(INCS) -o $(PROGRAM)_all_MINE_NONE $< $(LIBS)
	@$(foreach flag, $(FLAGS_MINE) , $(CC) $(GFLAGS) $(GFLAGS) $(CFLAGS_P) $(EXTRA) -$(flag) $(INCS) -o $(PROGRAM)_all_MINE_$(flag) $< $(LIBS);)

clean:
	rm -f $(CC)_* *.o *~ $(TARGETS) $(PROGRAM)_all_* 
