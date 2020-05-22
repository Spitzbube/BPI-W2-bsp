/************************************************************************
 *
 *  external_param.h
 *
 *  external parameters format
 *
 *
 ************************************************************************/

#ifndef EXTERN_PARAM_H
#define EXTERN_PARAM_H

/************************************************************************
 *  Definitions
*************************************************************************/

typedef struct{

	unsigned int    secure_mode; //144
	unsigned int 	flash_type; //148

	unsigned int 	region; //152

	unsigned int 	mac_hi; //156
	unsigned int 	mac_lo; //160

	unsigned char * logo_img_saddr; //168
	unsigned int 	logo_img_len;
	unsigned int 	logo_type;
	unsigned int 	logo_offset;
	unsigned int 	logo_reg_5370;
	unsigned int 	logo_reg_5374;
	unsigned int 	logo_reg_5378;
	unsigned int 	logo_reg_537c;

	unsigned int 	rescue_img_size; //204
	unsigned int 	rescue_img_addr; //208
	unsigned char * rescue_img_part0_saddr; //216
	unsigned int 	rescue_img_part0_len; //224
	unsigned char * rescue_img_part1_saddr; //232
	unsigned int 	rescue_img_part1_len; //240

	unsigned char * env_param_saddr; //248

	unsigned char * logo2_img_saddr; //256
	unsigned int 	logo2_img_len;
	unsigned int 	logo2_type;
	unsigned int 	logo2_offset;
	unsigned int 	logo2_reg_5370;
	unsigned int 	logo2_reg_5374;
	unsigned int 	logo2_reg_5378;
	unsigned int 	logo2_reg_537c;

	unsigned char * logo3_img_saddr;
	unsigned int 	logo3_img_len;
	unsigned int 	logo3_type;
	unsigned int 	logo3_offset;
	unsigned int 	logo3_reg_5370;
	unsigned int 	logo3_reg_5374;
	unsigned int 	logo3_reg_5378;
	unsigned int 	logo3_reg_537c;

	unsigned char * logo4_img_saddr;
	unsigned int 	logo4_img_len;
	unsigned int 	logo4_type;
	unsigned int 	logo4_offset;
	unsigned int 	logo4_reg_5370;
	unsigned int 	logo4_reg_5374;
	unsigned int 	logo4_reg_5378;
	unsigned int 	logo4_reg_537c;

	unsigned char * array_img_saddr; //376
	unsigned int 	array_img_size; //384

	// HDMI keys (additional one byte is used as string terminating symbol '\0')
	unsigned char 	hdmi_key1[112+1]; //388 = 0x184
	unsigned char 	hdmi_key2[112+1];
	unsigned char 	hdmi_key3[112+1];
	unsigned char 	hdmi_key4[112+1];
	unsigned char 	hdmi_key5[112+1]; //840 = 0x348
	unsigned char 	hdmi_key6[10+1]; //953 = 0x3b9

	// customize value (additional one byte is used as string terminating symbol '\0')
	unsigned char 	custom_field[32+1]; //964 = 0x3c4

	unsigned char * logo5_img_saddr;
	unsigned int 	logo5_img_len;
	unsigned int 	logo5_type;
	unsigned int 	logo5_offset;
	unsigned int 	logo5_reg_5370;
	unsigned int 	logo5_reg_5374;
	unsigned int 	logo5_reg_5378;
	unsigned int 	logo5_reg_537c;

	unsigned char * logo6_img_saddr;
	unsigned int 	logo6_img_len;
	unsigned int 	logo6_type;
	unsigned int 	logo6_offset;
	unsigned int 	logo6_reg_5370;
	unsigned int 	logo6_reg_5374;
	unsigned int 	logo6_reg_5378;
	unsigned int 	logo6_reg_537c;

	unsigned char * logo7_img_saddr;
	unsigned int 	logo7_img_len;
	unsigned int 	logo7_type;
	unsigned int 	logo7_offset;
	unsigned int 	logo7_reg_5370;
	unsigned int 	logo7_reg_5374;
	unsigned int 	logo7_reg_5378;
	unsigned int 	logo7_reg_537c;

	unsigned char * logo8_img_saddr;
	unsigned int 	logo8_img_len;
	unsigned int 	logo8_type;
	unsigned int 	logo8_offset;
	unsigned int 	logo8_reg_5370;
	unsigned int 	logo8_reg_5374;
	unsigned int 	logo8_reg_5378;
	unsigned int 	logo8_reg_537c;

	unsigned char * bootcode_img_saddr;
	unsigned int 	bootcode_img_size;

	unsigned int 	data_start_blk; //1172
	unsigned int 	fsbl_addr;
	unsigned int 	fsbl_os_addr;
	unsigned int 	bl31_addr;
	unsigned int 	Kpublic_fw_addr;
	unsigned int 	Kpublic_tee_addr;
} __attribute__((aligned(8))) t_extern_param;

extern t_extern_param *ext_para_ptr;

#endif //#ifndef EXTERN_PARAM_H
