#ifndef _KEYBOARD_H
#define _KEYBOARD_H

#include "main.h"

uint8_t KEY_SCAN(void);
uint8_t KEY_ROW_SCAN(void);
void HW_KEY_FUNCTION(void);


#define KEY_CLO1_OUT_LOW  HAL_GPIO_WritePin(KEY_C_1_GPIO_Port,KEY_C_1_Pin,GPIO_PIN_RESET)
#define KEY_CLO2_OUT_LOW  HAL_GPIO_WritePin(KEY_C_2_GPIO_Port,KEY_C_2_Pin,GPIO_PIN_RESET)
#define KEY_CLO3_OUT_LOW  HAL_GPIO_WritePin(KEY_C_3_GPIO_Port,KEY_C_3_Pin,GPIO_PIN_RESET)


#define KEY_CLO1_OUT_HIGH  HAL_GPIO_WritePin(KEY_C_1_GPIO_Port,KEY_C_1_Pin,GPIO_PIN_SET)
#define KEY_CLO2_OUT_HIGH  HAL_GPIO_WritePin(KEY_C_2_GPIO_Port,KEY_C_2_Pin,GPIO_PIN_SET)
#define KEY_CLO3_OUT_HIGH  HAL_GPIO_WritePin(KEY_C_3_GPIO_Port,KEY_C_3_Pin,GPIO_PIN_SET)




#endif
