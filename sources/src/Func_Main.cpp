#include "Func_Main.h"
#include "AHT20.h"
#include "usart.h"
#include "Redirect.h"

#include <cstring>
#include <cstdio>
#include <memory>

int Func_Main() {
    static char message[50];
    const auto aht20 = std::make_unique<AHT20>();

    for (;;) {
        aht20->AHT_Read();
        sprintf(message, "温度：%.1f C，湿度：%.1f%%\r\n",aht20->get_Value_Temperature(),aht20->get_Value_Humidity());
        HAL_UART_Transmit(&huart1,reinterpret_cast<uint8_t*>(message),strlen(message),TIME_OUT_TIME);
        HAL_Delay(1000);
    }
}