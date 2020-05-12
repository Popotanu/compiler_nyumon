CFLAGS=-std=c11 -g -static

tanucc: tanucc.c

test: tanucc
				./test.sh
clean:
				rm -f tanucc *o. *~ tmp*

.PHONY: test clean
