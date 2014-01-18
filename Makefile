.PHONY: clean All

All:
	@echo "----------Building project:[ t1b1dataprocessortests - Debug ]----------"
	@cd "t1b1dataprocessortests" && $(MAKE) -f  "t1b1dataprocessortests.mk"
clean:
	@echo "----------Cleaning project:[ t1b1dataprocessortests - Debug ]----------"
	@cd "t1b1dataprocessortests" && $(MAKE) -f  "t1b1dataprocessortests.mk" clean
