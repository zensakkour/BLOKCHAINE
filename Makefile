CC=gcc
export CC
VALGRIND=0
DEBUG=$(VALGRIND)
export DEBUG
export VALGRIND
EXTERNAL_LIBS=-lssl -lcrypto
export EXTERNAL_LIBS

# find current Makefiles directory i.e project root
ROOT_MAKEFILE=$(abspath $(lastword $(MAKEFILE_LIST)))
D_ROOT := $(patsubst %/,%,$(dir $(ROOT_MAKEFILE)))
export D_ROOT

# add the root as include directory
C_INCLUDE_PATH=$(D_ROOT)
export C_INCLUDE_PATH

D_LIB=$(D_ROOT)/lib
D_TEST=$(D_ROOT)/test
SUBDIRS = $(D_LIB) $(D_TEST)
export D_LIB D_TEST

export PERFORMANCETESTS

ifneq ($(words $(D_ROOT)),1)
$(error Seems like your path "$(D_ROOT)" has spaces in it! Compilation cannot continue! )
endif

all:
	for sdir in $(SUBDIRS); do \
		$(MAKE) -C $$sdir; \
	done

clean:
	for sdir in $(SUBDIRS); do \
		$(MAKE) -C $$sdir clean; \
	done

test:: all
	$(MAKE) -C ./test alltests


