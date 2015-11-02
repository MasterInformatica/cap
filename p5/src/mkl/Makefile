PROGRAM=cholesky

TARGETS=$(PROGRAM)-3


CC = icc

CFLAGS = -DVERBOSE
CFLAGS_P =
MKL_LIB_DIR=/opt/intel/mkl/lib/intel64/
MKL_INC_DIR=/opt/intel/mkl/include/


LIBS  = -L$(MKL_LIB_DIR) -lmkl_sequential -lmkl_core -lmkl_rt -lpthread
INCS  = -I$(MKL_INC_DIR)

EXTRA = -std=c99 -Wall -Wno-unused 

$(PROGRAM)-3: $(PROGRAM).c $(MKL_CHECK)
	$(CC) $(GFLAGS) $(CFLAGS) $(CFLAGS_P) $(EXTRA) -O3 $(INCS) -o $@ $< $(LIBS)

clean:
	rm -f $(CC)_* *.o *~ $(TARGETS) 

