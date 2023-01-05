#include "app_encoder_as5600.h"


AS5600_Func app_as5600_func_gpio_init(uint32_t id)
{
    __as5600_unused(id);
}

AS5600_Func app_as5600_func_set_direction(uint32_t id, AS5600_ClockDirection dir)
{
    __as5600_unused(id);
}

AS5600_Func app_as5600_func_i2c_init(uint32_t id)
{
    __as5600_unused(id);
}

AS5600_Data app_as5600_func_i2c_get_raw_data(uint32_t id)
{
    __as5600_unused(id);
}


/***********************************************************/
/* The following code is used to implement a simple I2C communication */
/***********************************************************/
#if _USE_SOFTWARE_I2C

// 延时函数
void HW_I2C_Delay(void)
{
    int i = 1000;
    while (i--);
}

// 启动信号
void HW_I2C_Start(void)
{
    I2C_SDA_HIGH();
    I2C_SCL_HIGH();
    I2C_Delay();
    I2C_SDA_LOW();
    I2C_Delay();
    I2C_SCL_LOW();
    I2C_Delay();
}

// 停止信号
void HW_I2C_Stop(void)
{
    I2C_SCL_LOW();
    I2C_SDA_LOW();
    I2C_Delay();
    I2C_SCL_HIGH();
    I2C_Delay();
    I2C_SDA_HIGH();
    I2C_Delay();
}

// 写一个字节
void HW_I2C_WriteByte(uint8_t data)
{
    uint8_t i;
    for (i = 0; i < 8; i++) {
        if (data & 0x80) {
            I2C_SDA_HIGH();
        } else {
            I2C_SDA_LOW();
        }
        I2C_SCL_HIGH();
        I2C_Delay();
        I2C_SCL_LOW();
        I2C_Delay();
        data <<= 1;
    }
    I2C_SDA_HIGH();
    I2C_SCL_HIGH();
    I2C_Delay();
    I2C_SCL_LOW();
    I2C_Delay();
}

uint8_t HW_I2C_ReadByte(uint8_t ack)
{
    uint8_t i;
    uint8_t data = 0;
    I2C_SDA_HIGH();
    for (i = 0; i < 8; i++) {
        data <<= 1;
        I2C_SCL_HIGH();
        I2C_Delay();
        if (I2C_SDA_STATE()) {
            data |= 0x01;
        }
        I2C_SCL_LOW();
        I2C_Delay();
    }
    if (ack) {
        I2C_SDA_LOW();
    }else {
        I2C_SDA_HIGH();
    }
    I2C_SCL_HIGH();
    I2C_Delay();
    I2C_SCL_LOW();
    I2C_Delay();
    return data;
}

// 写数据
uint8_t HW_I2C_WriteData(uint8_t devAddr, uint8_t regAddr, uint8_t *pData, uint16_t len)
{
    uint16_t i;
    I2C_Start();
    I2C_WriteByte(devAddr << 1);
    I2C_WriteByte(regAddr);
    for (i = 0; i < len; i++) {
        I2C_WriteByte(pData[i]);
    }
    I2C_Stop();
    return 0;
}

// 读数据
uint8_t HW_I2C_ReadData(uint8_t devAddr, uint8_t regAddr, uint8_t *pData, uint16_t len)
{
    uint16_t i;
    I2C_Start();
    I2C_WriteByte(devAddr << 1);
    I2C_WriteByte(regAddr);
    I2C_Start();
    I2C_WriteByte((devAddr << 1) | 0x01);
    for (i = 0; i < len; i++) {
        pData[i] = I2C_ReadByte(i == (len - 1));
    }
    I2C_Stop();
    return 0;
}

#endif
/*End*/