#ifndef F407_REDIRECT_H
#define F407_REDIRECT_H

#include <stdio.h>  // 必须包含

#ifdef __GNUC__
// 对于 GCC (包括arm-none-eabi-g++), 重定义 __io_putchar
int __io_putchar(int ch) {
    HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, HAL_MAX_DELAY); // 将 &huart1 替换为你实际的串口句柄
    return ch;
}
#else
// 对于其他编译器 (如IAR, Keil的ARMCC)
int fputc(int ch, FILE *f) {
    HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, HAL_MAX_DELAY);
    return ch;
}
#endif

#endif //F407_REDIRECT_H