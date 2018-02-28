include make.config
all:recast main
	@echo "Done"
	$(CXX) $(CPPFLAGS) recast/recast.a main/main.a -o $(TARGET)
	./$(TARGET)


.PHONY: clean recast main

recast:
	@echo "===> Building $@.a:" && $(MAKE) -C $@

main:
	@echo "===> Building $@.a:" && $(MAKE) -C $@

clean:
	$(RM) $(TARGET)
	@$(MAKE) -C recast $@
	@$(MAKE) -C main $@
