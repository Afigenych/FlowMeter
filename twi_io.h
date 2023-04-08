// twi_io

 
 #define BAUD_RATE_TWI	30
 #define ADDR_SS			0x20
 #define ADDR_LED			0x21
 #define ADDR_IR			0x22
 #define ADDR_MPR121		0x5B // pin ADDR connected with VCC (GND))
 #define ADDR_RTC_EEPROM	0x57
 #define ADDR_RTC_SRAM_RTCC	0x6F
 
 
 #define TWI_ST_UNKNOWN		0x00
 #define TWI_ST_OWNER		0x01
 #define TWI_ST_BUZY		0x02
 #define TWI_ST_IDLE		0x03
 
 #define TWI_HOST_CASE_M1		0x01
 #define TWI_HOST_CASE_M2		0x02
 #define TWI_HOST_CASE_M3		0x03
 #define TWI_HOST_CASE_M4		0x04
 
 typedef volatile struct twi_state {
	 uint8_t twi_state;
	 uint8_t twi_case;
	 uint8_t twi_bus_status;
	 uint8_t twi_host_operation; 
	 }TWI_STATE_t;
	 
extern TWI_STATE_t twi_state; 
extern TWI_STATE_t * ptwi_state;

 
 #define TWI_RD 0x01
 #define TWI_WR 0x00
 
 #define RD_ONE_BYTE 0x01
 #define RD_TWO_BYTE 0x02
 
 #define MPR121_BUF_SIZE	0x02
 
 typedef volatile struct twi_iobuf {
	 uint8_t dev_addr;
	 uint8_t reg_addr;
	 uint8_t command;
	 uint8_t data_length;
	 uint8_t * data_buf;
	 
	 } TWI_IOBUF_t;
	 
extern TWI_IOBUF_t twi_iobuf;
extern TWI_IOBUF_t * ptwi_iobuf;

typedef volatile struct twi_bus_state	{
	
	} TWI_BUS_STATE_t;
extern TWI_BUS_STATE_t twi_bus_state;
extern TWI_BUS_STATE_t * ptwi_bus_state;


 //void twi_io (void);
 void twi_io_readIR (void);
 void twi_io_readKB (void);
 void twi_io_writeKB (void);
 void twi_io_RTC (void);
 void twi_io_writeLCD(void);
 void twi_io_writeCS (void);
 void twi_io_write_mpr121 (void);
// void twi_io_init_mpr121 (uint8_t addr_reg, uint8_t direction, uint8_t data_length, uint8_t * pdata_buf);
// void twi_io (uint8_t, void *);
uint8_t set_twi_bus_idle (void);
void twi_set_addr (uint8_t addr, uint8_t direction);
uint8_t twi_status_operation (void);
void twi_send_byte (uint8_t);