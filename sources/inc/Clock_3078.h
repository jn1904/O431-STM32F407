

#ifndef F407_CLOCK_3078_H
#define F407_CLOCK_3078_H

#ifdef __cplusplus
extern "C" {
#endif

#include "i2c.h"

    constexpr uint8_t SD3078_ADDR = 0x64;
    constexpr uint8_t SD3078_READ_ADDR = 0x64;
    constexpr uint8_t SD3078_WRITE_ADDR = 0x65;

    namespace O431{
        struct TIME{
            uint8_t mode = 0;

            uint8_t sec = 0;
            uint8_t min = 0;
            uint8_t hour = 0;
            uint8_t week = 0;
            uint8_t day = 0;
            uint8_t month = 0;
            uint8_t year = 0;
        };
        struct ALARM{
            TIME time;
            uint8_t enable = 0;
        };


        class Clock_3078{
        public:
            Clock_3078();
            explicit Clock_3078(I2C_HandleTypeDef* HI2C);
            ~Clock_3078();

            TIME Clock_GetTime();
            void Clock_SetTime(uint8_t addr_time,uint8_t time);
            void Clock_SetTime(TIME time);
            ALARM Alarm_GetAlarm();
            void Alarm_SetTime(uint8_t addr_time,uint8_t time);
            void Alarm_SetTime(ALARM alarm);




        private:
            TIME time;
            ALARM alarm;
            I2C_HandleTypeDef* hi2c;

        };
    }

#ifdef __cplusplus
}
#endif

#endif //F407_CLOCK_3078_H