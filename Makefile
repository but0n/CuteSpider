
SRCTARGET=core.o

all:src
	@echo "Finished"

.PHONY: clean src

src:
	@echo "Compiling $@"
	@$(MAKE) -C src $@


clean:
	@$(MAKE) -C src $@
	rm -rf app.bin
