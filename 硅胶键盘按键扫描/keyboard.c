#include "keyboard.h"
#include "screen.h"


uint8_t Key_row[1]={0xff};
uint8_t flag=0;
uint8_t test;
uint8_t zero='0';

uint8_t KEY_ROW_SCAN(void){
	//读出行扫描状态
	Key_row[0] = HAL_GPIO_ReadPin(KEY_R_1_GPIO_Port,KEY_R_1_Pin)<<3;
	Key_row[0] = Key_row[0] | (HAL_GPIO_ReadPin(KEY_R_2_GPIO_Port,KEY_R_2_Pin)<<2);
	Key_row[0] = Key_row[0] | (HAL_GPIO_ReadPin(KEY_R_3_GPIO_Port,KEY_R_3_Pin)<<1);
	Key_row[0] = Key_row[0] | (HAL_GPIO_ReadPin(KEY_R_4_GPIO_Port,KEY_R_4_Pin));
	
	if(Key_row[0] != 0x0f)         //行扫描有变化，判断该列有按键按下
	{
		HAL_Delay(10);                    //消抖
		if(Key_row[0] != 0x0f)
			{   
				//printf("Key_Row_DATA = 0x%x\r\n",Key_row[0]);
				switch(Key_row[0])
				{
						case 0x07:         //0111 判断为该列第1行的按键按下
								return 1;
						case 0x0b:         //1011 判断为该列第2行的按键按下
								return 2;
						case 0x0d:         //1101 判断为该列第3行的按键按下
								return 3;
						case 0x0e:         //1110 判断为该列第4行的按键按下
								return 4;
						default :
								return 0;
				}
			}
			else return 0;
	}
	else return 0;
	
}


uint8_t KEY_SCAN(void){
	uint8_t Key_Num=0;       //1-16对应的按键数
	uint8_t key_row_num=0;        //行扫描结果记录
	
	
	KEY_CLO1_OUT_LOW;        
	if( (key_row_num=KEY_ROW_SCAN()) != 0 )
	{ 
			while(KEY_ROW_SCAN() != 0);
			Key_Num = 1 + (key_row_num-1)*3;
			//printf("Key_Clo_2\r\n");
	}
	KEY_CLO1_OUT_HIGH;
	
	KEY_CLO2_OUT_LOW;    
	if( (key_row_num=KEY_ROW_SCAN()) != 0 )
	{ 
			while(KEY_ROW_SCAN() != 0);
			Key_Num = 2 + (key_row_num-1)*3;
			//printf("Key_Clo_3\r\n");
	}
	KEY_CLO2_OUT_HIGH;
	
	KEY_CLO3_OUT_LOW;    
	if( (key_row_num=KEY_ROW_SCAN()) != 0 )
	{
			while(KEY_ROW_SCAN() != 0);
			Key_Num = 3 + (key_row_num-1)*3;
			//printf("Key_Clo_4\r\n");
	}
	KEY_CLO3_OUT_HIGH;
	
	return Key_Num;
	
}

void HW_KEY_FUNCTION(void);


