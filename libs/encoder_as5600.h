#ifndef _ENCODER_AS5600_H_ 
#define _ENCODER_AS5600_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#ifndef PI
#define PI 3.1415926535
#endif


#define AS5600_DEFAULT_ADDR 0x36u

const float AS5600_RAW_TO_DEGREES   = 360.0 / 4096;
const float AS5600_RAW_TO_RADIANS   = PI * 2.0 / 4096;
const float AS5600_RAW_TO_RPM       = 60 / 4096;




typedef void AS5600_Func;
typedef uint16_t AS5600_Data;

typedef enum {
    CW = 1,
    CCW = -1
} AS5600_ClockDirection;

typedef struct {
    /* data */
    uint32_t id;
    uint8_t addr;

    AS5600_Func (* _FUNC_GPIO_INIT)(uint32_t id);
    AS5600_Func (* _FUNC_SET_DIRECTION)(uint32_t id, AS5600_ClockDirection dir);
    AS5600_Func (* _FUNC_I2C_INIT)(uint32_t id);
    AS5600_Data (* _FUNC_I2C_GET_RAW_DATA)(uint32_t id);

} AS5600_InitTypeDef;

AS5600_InitTypeDef* AS5600_New(void);
void AS5600_Del(AS5600_InitTypeDef* handle);

void AS5600_Initialize(AS5600_InitTypeDef* handle, uint32_t id, uint8_t addr, 
                    AS5600_Func (* _func_gpio_init)(uint32_t id),
                    AS5600_Func (* _func_set_direction)(uint32_t id, AS5600_ClockDirection dir),
                    AS5600_Func (* _func_i2c_init)(uint32_t id),
                    AS5600_Data (* _func_i2c_get_raw_data)(uint32_t id));

void AS5600_SetDirection(AS5600_InitTypeDef* handle,AS5600_ClockDirection dir);

#ifdef __cplusplus
}
#endif

#endif
/* End */