
SRCTARGET=core.o

all:src client zmb.out
	@echo "Finished"

.PHONY: clean src client

src:
	@echo "Compiling $@"
	@$(MAKE) -C $@ $@

client:
	@echo "Compiling $@"
	@$(MAKE) -C $@ $@

zmb.out:
	@echo "Compiling $@"
	@$(MAKE) -C zombie $@


clean:
	@$(MAKE) -C src $@
	@$(MAKE) -C client $@
	@$(MAKE) -C zombie $@

