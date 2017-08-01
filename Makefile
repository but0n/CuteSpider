

all:src
	@echo "Finished"

.PHONY: clean src

src:
	@echo "Compiling $@"
	@$(MAKE) -C $@ $@

clean:
	@$(MAKE) -C src $@
