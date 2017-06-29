TARGET=../user.out
TC=
CC=@echo "CC $@";$(TC)gcc
AR=@echo "AR $@";$(TC)ar

LIBDIR=-I.
COMMONFLAGS=-Wall -std=c99


CFLAGS=$(COMMONFLAGS) $(LIBDIR)

TARG = $(subst .c,.o,$(wildcard *.c))

client:app.a
	$(CC) $(CFLAGS) -o $(TARGET) $^

app.a:$(TARG)
	@$(AR) cr $@ $^

.PHONY: clean
clean:
	rm -rf $(TARG) *.a $(TARGET)
