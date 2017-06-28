TC=
CC=@echo "CC $@";$(TC)gcc
AR=$(TC)ar

LIBDIR=-I.
COMMONFLAGS=-Wall -std=c99

LIDLIBS+=-lm

CFLAGS=$(COMMONFLAGS) $(LIBDIR)

TARG = $(subst .c,.o,$(wildcard *.c))

src:$(TARG)

%.a:%.o
	@echo "AR $@"
	@$(AR) cr $@ $<

.PHONY: clean
clean:
	rm -rf $(TARG)
