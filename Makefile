
SRCTARGET=core.o

all:src client
	@echo "Finished"

.PHONY: clean src client

src:
	@echo "Compiling $@"
	@$(MAKE) -C $@ $@

client:
	@echo "Compiling $@"
	@$(MAKE) -C $@ $@


clean:
	@$(MAKE) -C src $@
	@$(MAKE) -C client $@
