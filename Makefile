all:
	$(MAKE) -C loadelf
	$(MAKE) -C elfloader
	$(MAKE) -C testapp

clean:
	$(MAKE) -C loadelf clean
	$(MAKE) -C elfloader clean
	$(MAKE) -C testapp clean

run: all
	ps2client -h 192.168.1.10 execee host:testapp/test_loader.elf
