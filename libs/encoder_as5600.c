#include "encoder_as5600.h"

AS5600_InitTypeDef* AS5600_New(void)
{
    return malloc(sizeof(AS5600_InitTypeDef));
}

void AS5600_Del(AS5600_InitTypeDef* handle)
{
    free(handle);
}

/*End*/