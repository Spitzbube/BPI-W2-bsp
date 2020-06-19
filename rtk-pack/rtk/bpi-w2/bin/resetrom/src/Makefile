
CROSS_COMPILE=../../../../../../toolchains/asdk64-4.9.4-a53-EL-3.10-g2.19-a64nt-160307/bin/aarch64-linux-

CC = $(CROSS_COMPILE)gcc
LD = $(CROSS_COMPILE)ld
OBJCOPY = $(CROSS_COMPILE)objcopy
OBJDUMP = $(CROSS_COMPILE)objdump


LOAD_ADDR = 0x00000000

ELF-y        := resetrom
 
ELF := $(strip $(ELF-y)) 

BIN  := $(addsuffix .bin,$(ELF))
DIS  := $(addsuffix .dis,$(ELF))

SOBJS	:= start64.o vectors.o cache.o
COBJS	:= timer.o main.o uart.o todo.o


OBJS	:= $(addprefix $(obj),$(COBJS))
SSOBJS	:= $(addprefix $(obj),$(SOBJS)) 

gcclibdir := $(shell dirname `$(CC) -print-libgcc-file-name`)

CFLAGS += -mlittle-endian -mtune=cortex-a53 -march=armv8-a -mcpu=cortex-a53 
CFLAGS += -march=armv8-a -mlittle-endian -mabi=lp64 -g -O2 -fuse-tls -fomit-frame-pointer -fno-common -fno-pic 
#CFLAGS += -fno-builtin -ffreestanding
 
all:	$(OBJS) $(SSOBJS) $(ELF) $(BIN)

clean:
	-rm -f resetrom *.o *.bin *.map *.dis
	
$(ELF): 	$(LIB) 
		$(LD) $(LDFLAGS) -g -T resetrom.lds  \
			-o $@ $(SOBJS) $(COBJS) $(LIB) \
			-L$(gcclibdir) -lgcc -Map resetrom.map
			
$(BIN):
$(obj)%.bin:	$(obj)%
##		$(OBJCOPY) -O binary $< $@ 2>/dev/null
		$(OBJDUMP) -hD $<  >$(DIS) 
		
#########################################################################

OBJ_DIR=.
ASM=$(CC)
$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) $(DFLAGS) $(IFLAGS) -c  $< -o $@
	
$(OBJ_DIR)/%.o: %.S
	$(ASM) $(ASFLAGS) $(DFLAGS) $(IFLAGS) -c $< -o $@
	
	
	
			
