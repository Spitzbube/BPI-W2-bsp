
CROSS_COMPILE=../../../../../toolchains/asdk64-4.9.4-a53-EL-3.10-g2.19-a64nt-160307/bin/aarch64-linux-

CC = $(CROSS_COMPILE)gcc
LD = $(CROSS_COMPILE)ld
OBJCOPY = $(CROSS_COMPILE)objcopy
OBJDUMP = $(CROSS_COMPILE)objdump


LOAD_ADDR = 0x01500000

ELF-y        := spirom
 
ELF := $(strip $(ELF-y)) 

BIN  := $(addsuffix .bin,$(ELF))
DIS  := $(addsuffix .dis,$(ELF))

SOBJS	:= start64.o cache64.o
COBJS	:= dvrmain.o util.o flashdev_s.o cache.o


OBJS	:= $(addprefix $(obj),$(COBJS))
SSOBJS	:= $(addprefix $(obj),$(SOBJS)) 


CFLAGS = -g -Os -fno-common -ffixed-r8 -D__KERNEL__ -fno-builtin -ffreestanding -pipe  -DCONFIG_ARM -D__ARM__  -march=armv8-a -D__EL__ -D__ARM_ARCH_8A__
CFLAGS += -DBoard_CPU_RTD1295


all:	$(OBJS) $(SSOBJS) $(ELF) $(BIN)

clean:
	-rm -f spirom *.o *.bin *.map *.dis
	
$(ELF): 	$(LIB) 
		$(LD) $(LDFLAGS) -g -Ttext $(LOAD_ADDR) \
			-o $@ -e start $(SOBJS) $(COBJS) $(LIB) \
			-L$(gcclibdir) -lgcc -Map dvrboot.map
			
$(BIN):
$(obj)%.bin:	$(obj)%
		$(OBJCOPY) -O binary $< $@ 2>/dev/null
		$(OBJDUMP) -hD $<  >$(DIS) 
		
#########################################################################

OBJ_DIR=.
ASM=$(CC)
$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) $(DFLAGS) $(IFLAGS) -c  $< -o $@
	
$(OBJ_DIR)/%.o: %.S
	$(ASM) $(ASFLAGS) $(DFLAGS) $(IFLAGS) -c $< -o $@
	
	
	
			