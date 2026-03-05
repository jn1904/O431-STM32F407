#ifndef __CLOCK_3078_REG_H
#define __CLOCK_3078_REG_H

#ifdef __cplusplus
extern "C" {
#endif
    #include <sys/_stdint.h>

    // 时钟寄存器地址
    constexpr uint8_t TIME_REG_SEC =                    0x00;
    constexpr uint8_t TIME_REG_MIN =                    0x01;
    constexpr uint8_t TIME_REG_HOUR =                   0x02;
    constexpr uint8_t TIME_REG_WEEK =                   0x03;
    constexpr uint8_t TIME_REG_DAY =                    0x04;
    constexpr uint8_t TIME_REG_MONTH =                  0x05;
    constexpr uint8_t TIME_REG_YEAR =                   0x06;
    // 时间报警寄存器地址
    constexpr uint8_t ALARM_REG_SEC =                   0x07;
    constexpr uint8_t ALARM_REG_MIN =                   0x08;
    constexpr uint8_t ALARM_REG_HOUR =                  0x09;
    constexpr uint8_t ALARM_REG_WEEK =                  0x0A;
    constexpr uint8_t ALARM_REG_DAY =                   0x0B;
    constexpr uint8_t ALARM_REG_MONTH =                 0x0C;
    constexpr uint8_t ALARM_REG_YEAR =                  0x0D;
    constexpr uint8_t ALARM_REG_ALLOW =                 0x0E;
    // 控制寄存器地址
    constexpr uint8_t CTRL_REG_CTR1 =                   0x0F;
    constexpr uint8_t CTRL_REG_CTR2 =                   0x10;
    constexpr uint8_t CTRL_REG_CTR3 =                   0x11;
    constexpr uint8_t CTRL_REG_TTF =                    0x12;
    constexpr uint8_t CTRL_REG_COUNTDOWN1 =             0x13;
    constexpr uint8_t CTRL_REG_COUNTDOWN2 =             0x14;
    constexpr uint8_t CTRL_REG_COUNTDOWN3 =             0x15;
    // 温度寄存器地址
    constexpr uint8_t TEMP_REG =                        0x16;
    // IIC控制寄存器地址
    constexpr uint8_t IIC_CTRL_REG =                    0x17;
    // 充电寄存器地址
    constexpr uint8_t CHARGE_REG =                      0x18;
    // 拓展控制寄存器
    constexpr uint8_t CTRL_REG_CTR4 =                   0x19;
    constexpr uint8_t CTRL_REG_CTR5 =                   0x1A;
    // 电池电量寄存器
    constexpr uint8_t BAT_VAL_REG =                     0x1B;
    // 温度报警寄存器
    constexpr uint8_t TEMP_ALARM_HIGH =                 0x1C;
    constexpr uint8_t TEMP_ALARM_LOW =                  0x1D;
    constexpr uint8_t TEMP_ALARM_HIGH_HIS =             0x1E;
    constexpr uint8_t TEMP_ALARM_LOW_HIS =              0x1F;
    // 历史极点温度时间记录寄存器
    constexpr uint8_t TEMP_LOW_TIME_MIN =               0x20;
    constexpr uint8_t TEMP_LOW_TIME_HOUR =              0x21;
    constexpr uint8_t TEMP_LOW_TIME_WEEk =              0x22;
    constexpr uint8_t TEMP_LOW_TIME_DAY =               0x23;
    constexpr uint8_t TEMP_LOW_TIME_MONTH =             0x24;
    constexpr uint8_t TEMP_LOW_TIME_YEAR =              0x25;
    constexpr uint8_t TEMP_HIGH_TIME_MIN =              0x26;
    constexpr uint8_t TEMP_HIGH_TIME_HOUR =             0x27;
    constexpr uint8_t TEMP_HIGH_TIME_WEEk =             0x28;
    constexpr uint8_t TEMP_HIGH_TIME_DAY =              0x29;
    constexpr uint8_t TEMP_HIGH_TIME_MONTH =            0x2A;
    constexpr uint8_t TEMP_HIGH_TIME_YEAR =             0x2B;
/*
 *  用户RAM地址为0x2C~0x71
 *  ID地址为0x73~0x79
 */



#ifdef __cplusplus
}
#endif
#endif