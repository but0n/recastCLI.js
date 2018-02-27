include ../make.config

LIBDIR+=-I../recast/

all:$(TARG)
	@$(AR) cr main.a $^

.PHONY: clean
clean:
	rm -rf *.o *.a