EE_BIN = test_loader.elf
EE_OBJS = main.o
EE_INCS = -I../loadelf/include
EE_LDFLAGS = -L../loadelf/lib
EE_LIBS = -lloadelf

all: $(EE_BIN)

run: all
	ps2client -h 192.168.1.10 execee host:$(EE_BIN)

reset: clean
	ps2client -h 192.168.1.10 reset

clean:
	rm -f -r $(EE_OBJS) $(EE_BIN)

include $(PS2SDK)/samples/Makefile.pref
include $(PS2SDK)/samples/Makefile.eeglobal
