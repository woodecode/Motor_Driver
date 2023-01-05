#include "encoder_as5600.h"

AS5600_InitTypeDef* AS5600_New(void)
{
    return malloc(sizeof(AS5600_InitTypeDef));
}

void AS5600_Del(AS5600_InitTypeDef* handle)
{
    free(handle);
}

void AS5600_Initialize(AS5600_InitTypeDef* handle, uint32_t id, uint8_t addr, 
                    AS5600_Func (* _func_gpio_init)(uint32_t id),
                    AS5600_Func (* _func_set_direction)(uint32_t id, AS5600_ClockDirection dir),
                    AS5600_Func (* _func_i2c_init)(uint32_t id),
                    AS5600_Data (* _func_i2c_get_raw_data)(uint32_t id))
{
    /* initialize parameters */
    handle->id = id;
    handle->addr = addr;

    handle->_FUNC_GPIO_INIT = _func_gpio_init;
    handle->_FUNC_SET_DIRECTION = _func_set_direction;
    handle->_FUNC_I2C_INIT = _func_i2c_init;
    handle->_FUNC_I2C_GET_RAW_DATA = _func_i2c_get_raw_data;
    
    /* execute hardware initialization code */
    handle->_FUNC_GPIO_INIT(handle->id);
    handle->_FUNC_I2C_INIT(handle->id);
}

void AS5600_SetDirection(AS5600_InitTypeDef* handle,AS5600_ClockDirection dir)
{
    handle->_FUNC_SET_DIRECTION(handle->id,dir);
}

/*End*/