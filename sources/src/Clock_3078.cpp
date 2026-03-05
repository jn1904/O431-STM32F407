#include "Clock_3078.h"
#include "Clock_3078_Reg.h"

#include "i2c.h"

void SD3078_Write_Byte(uint8_t reg, uint8_t data);
uint8_t SD3078_Read_Byte(uint8_t reg);

namespace O431 {
    Clock_3078::Clock_3078() {
        hi2c = &hi2c1;
        HAL_I2C_Init(hi2c);
    }

    Clock_3078::Clock_3078(I2C_HandleTypeDef *HI2C) {
        hi2c = HI2C;
        HAL_I2C_Init(hi2c);
    }

    Clock_3078::~Clock_3078(){
        return;
    }

    TIME Clock_3078::Clock_GetTime() {
        HAL_I2C_Master_Transmit(hi2c,SD3078_ADDR,reinterpret_cast<uint8_t*>(SD3078_READ_ADDR),1,HAL_MAX_DELAY);
        uint8_t buffer_hour = 0;
        HAL_I2C_Mem_Read(hi2c,SD3078_ADDR,TIME_REG_SEC,1,reinterpret_cast<uint8_t *>(time.sec),1,HAL_MAX_DELAY);
        HAL_I2C_Mem_Read(hi2c,SD3078_ADDR,TIME_REG_MIN,1,reinterpret_cast<uint8_t *>(time.min),1,HAL_MAX_DELAY);
        HAL_I2C_Mem_Read(hi2c,SD3078_ADDR,TIME_REG_HOUR,1,reinterpret_cast<uint8_t *>(buffer_hour),1,HAL_MAX_DELAY);
        HAL_I2C_Mem_Read(hi2c,SD3078_ADDR,TIME_REG_WEEK,1,reinterpret_cast<uint8_t *>(time.week),1,HAL_MAX_DELAY);
        HAL_I2C_Mem_Read(hi2c,SD3078_ADDR,TIME_REG_DAY,1,reinterpret_cast<uint8_t *>(time.day),1,HAL_MAX_DELAY);
        HAL_I2C_Mem_Read(hi2c,SD3078_ADDR,TIME_REG_MONTH,1,reinterpret_cast<uint8_t *>(time.month),1,HAL_MAX_DELAY);
        HAL_I2C_Mem_Read(hi2c,SD3078_ADDR,TIME_REG_YEAR,1,reinterpret_cast<uint8_t *>(time.year),1,HAL_MAX_DELAY);
        time.mode = buffer_hour >> 7;
        time.hour = buffer_hour & 0x7F;
        return time;
    }
}
