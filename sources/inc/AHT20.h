#ifndef F407_AHT20_H
#define F407_AHT20_H

#ifdef __cplusplus
extern "C" {
#endif

#include "i2c.h"

    constexpr uint8_t AHT20_ADDR =      0x38;
    constexpr uint8_t AHT_RESET =       0xBA;
    inline uint8_t AHT_READ =           0x71;
    constexpr uint8_t AHT_INIT[3] =     {0xBE, 0x08, 0x00};
    constexpr uint8_t AHT_TIGGER[3] =   {0xAC, 0X33, 0x00};
    namespace O431{
        class AHT20 {
        public:
            AHT20();                                                    // 构造函数，默认I2C接口1

            explicit AHT20(I2C_HandleTypeDef *HI2C);                    // 含参构造函数，用于指定I2C接口
            ~AHT20();

            void AHT_Read();                                            // 数值读取函数
            [[nodiscard]] float get_Value_Temperature() const;          // 向外部提供温度数据接口
            [[nodiscard]] float get_Value_Humidity() const;             // 向外部提供湿度数据接口

        private:
            I2C_HandleTypeDef *hi2c;
            volatile float temperature;
            volatile float humidity;

        };
    }

#ifdef __cplusplus
}
#endif

#endif //F407_AHT20_H