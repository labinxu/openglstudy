.PHONY: all clean
ROOT_DIR=$(shell pwd)
ROOT_DIR := $(patsubst %/build,%/,$(ROOT_DIR))
export ROOT = $(ROOT_DIR)
DIRS = $(ROOT)/tools/src $(ROOT)/test
RM = rm
RMFLAGS = -rf
RMS = $(ROOT)/build/exes $(ROOT)/build/libs
all:
	@set -e; \
	for dir in $(DIRS); \
	do \
	cd $$dir && $(MAKE) ; \
	done
	cp $(ROOT)/tools/libs/* $(ROOT)/build/exes/
	@echo "Completed :-)"

clean:
	@set -e; \
	for dir in $(DIRS); \
	do \
	cd $$dir && $(MAKE) clean; \
	done
	$(RM) $(RMFLAGS) $(RMS)
	@echo "Completed :-)"
