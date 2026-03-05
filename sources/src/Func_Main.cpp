#include "Func_Main.h"
#include "AHT20.h"
#include "Clock_3078.h"

// 串口及其重定向头文件
#include "usart.h"
#include "Redirect.h"

#include <cstring>
#include <cstdio>
#include <memory>

int Func_Main() {

    static char message[50];
    const auto aht20 = std::make_unique<O431::AHT20>();
    const auto clock = std::make_unique<O431::Clock_3078>();

    HAL_GPIO_WritePin(LED_GPIO_Port,LED_Pin,GPIO_PIN_RESET);
    for (;;) {
        aht20->AHT_Read();
        sprintf(message, "温度：%.1f C，湿度：%.1f%%\r\n",aht20->get_Value_Temperature(),aht20->get_Value_Humidity());
        HAL_UART_Transmit(&huart1,reinterpret_cast<uint8_t*>(message),strlen(message),HAL_MAX_DELAY);
        HAL_Delay(1000);
        const O431::TIME time = clock->Clock_GetTime();
        sprintf(message,"时间：%d:%d:%d,第%d周，%d年%d月%d日\r\n", time.hour,time.min,time.sec,time.week,time.year,time.month,time.day);
        HAL_UART_Transmit(&huart1,reinterpret_cast<uint8_t*>(message),strlen(message),HAL_MAX_DELAY);
    }
}
