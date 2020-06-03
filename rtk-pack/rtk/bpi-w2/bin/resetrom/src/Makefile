
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

SOBJS	:= start64.o vectors.o
COBJS	:= main.o uart.o todo.o


OBJS	:= $(addprefix $(obj),$(COBJS))
SSOBJS	:= $(addprefix $(obj),$(SOBJS)) 


CFLAGS = -O2 -fno-common -fno-builtin -ffreestanding -fomit-frame-pointer -pipe -march=armv8-a

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
	
	
	
			
