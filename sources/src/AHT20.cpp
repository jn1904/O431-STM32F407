#include "AHT20.h"
#include "i2c.h"

uint8_t test_AHT20(I2C_HandleTypeDef* HI2C);
float cal_Temperature(float date);
float cal_Humidity(float date);

O431::AHT20::AHT20() {
    hi2c = &hi2c1;
    temperature = 0;
    humidity = 0;
    HAL_I2C_Init(hi2c);
    HAL_Delay(40);
    if ((test_AHT20(hi2c) & 0x08) == 0x00){
        HAL_I2C_Master_Transmit(&hi2c1,AHT20_ADDR,const_cast<uint8_t *>(AHT_INIT),3,HAL_MAX_DELAY);
    }
}

O431::AHT20::AHT20(I2C_HandleTypeDef *HI2C) {
    hi2c = HI2C;
    temperature = 0;
    humidity = 0;
    HAL_I2C_Init(hi2c);
    HAL_Delay(40);
    if (test_AHT20(hi2c)) {
        HAL_I2C_Master_Transmit(hi2c,AHT20_ADDR,const_cast<uint8_t *>(AHT_INIT),3,HAL_MAX_DELAY);
    }
}

O431::AHT20::~AHT20() {
    return;
}

void O431::AHT20::AHT_Read() {
    uint8_t buffer_Receive[6];
    HAL_I2C_Master_Transmit(hi2c,AHT20_ADDR,const_cast<uint8_t *>(AHT_TIGGER),3,HAL_MAX_DELAY);
    HAL_Delay(80);
    HAL_I2C_Master_Receive(hi2c,AHT20_ADDR,buffer_Receive,6,HAL_MAX_DELAY);
    if ( (buffer_Receive[0] & 0x80) == 0x00) {
        uint32_t date= (static_cast<uint32_t>(buffer_Receive[1]) << 12) +
                                 (static_cast<uint32_t>(buffer_Receive[2]) << 4) +
                                 (static_cast<uint32_t>(buffer_Receive[3]) >> 4);

        humidity = cal_Humidity(static_cast<float>(date));


        date = ((static_cast<uint32_t>(buffer_Receive[3]) & 0x0F) << 16) +
                                    (static_cast<uint32_t>(buffer_Receive[4]) << 8) +
                                    static_cast<uint32_t>(buffer_Receive[5]);

        temperature = cal_Temperature(static_cast<float>(date));
    }

}

float O431::AHT20::get_Value_Humidity() const {
    return humidity;
}

float O431::AHT20::get_Value_Temperature() const {
    return temperature;
}

uint8_t test_AHT20(I2C_HandleTypeDef* HI2C) {
    uint8_t buffer_Receive = 0;
    HAL_I2C_Master_Receive(HI2C,AHT20_ADDR,&buffer_Receive,1,HAL_MAX_DELAY);
    return buffer_Receive;
}

float cal_Temperature(const float date) {
    return date * 200.0f / (1 << 20) - 50.0f;
}
float cal_Humidity(const float date) {
    return date * 100.0f / (1 << 20);
}