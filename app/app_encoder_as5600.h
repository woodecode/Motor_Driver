#ifndef _APP_AS5600_H_
#define _APP_AS5600_H_

#ifdef __cplusplus
extern "C"{
#endif

#define __as5600_unused(x) (void)(x)


#include "encoder_as5600.h"

/* simulate I2C using software */
#define _USE_SOFTWARE_I2C 1

#if _USE_SOFTWARE_I2C

#define HW_I2C_SDA_HIGH()  ((void *)0)
#define HW_I2C_SDA_LOW()   ((void *)0)
#define HW_I2C_SCL_HIGH()  ((void *)0)
#define HW_I2C_SCL_LOW()   ((void *)0)
#define HW_I2C_SDA_STATE() ((void *)0)

// 延时函数
void    HW_I2C_Delay(void);
void    HW_I2C_Start(void);
void    HW_I2C_Stop(void);
void    HW_I2C_WriteByte(uint8_t data);
uint8_t HW_I2C_ReadByte(uint8_t ack);
uint8_t HW_I2C_WriteData(uint8_t devAddr, uint8_t regAddr, uint8_t *pData, uint16_t len);
uint8_t HW_I2C_ReadData(uint8_t devAddr, uint8_t regAddr, uint8_t *pData, uint16_t len);

#endif

AS5600_Func app_as5600_func_gpio_init(uint32_t id);
AS5600_Func app_as5600_func_set_direction(uint32_t id, AS5600_ClockDirection dir);
AS5600_Func app_as5600_func_i2c_init(uint32_t id);
AS5600_Data app_as5600_func_i2c_get_raw_data(uint32_t id);

#ifdef __cplusplus
}
#endif

#endif

/*End*/