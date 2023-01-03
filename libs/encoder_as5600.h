#ifndef _ENCODER_AS5600_H_ 
#define _ENCODER_AS5600_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

typedef void AS5600_Func;
typedef uint16_t AS5600_I2C_DATA;

typedef struct {
    /* data */
    uint32_t id;

    AS5600_Func (* _FUNC_I2C_Init)(void);
    AS5600_I2C_DATA (* _FUNC_I2C_GetRawData)(void);

} AS5600_InitTypeDef;

AS5600_InitTypeDef* AS5600_New(void);
void AS5600_Del(AS5600_InitTypeDef* handle);



#ifdef __cplusplus
}
#endif

#endif
/* End */