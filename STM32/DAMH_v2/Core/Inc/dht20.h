#ifndef DHT20_H
#define DHT20_H

#include "stm32f1xx_hal.h" // Thay đổi tùy theo dòng STM32 bạn dùng

#define DHT20_I2C_ADDRESS 0x38 << 1 // Địa chỉ của DHT20 (shift để phù hợp với HAL)

// Cấu trúc dữ liệu trả về từ DHT20
typedef struct {
    float temperature;
    float humidity;
} DHT20_Data;

// Khởi tạo DHT20
HAL_StatusTypeDef DHT20_Init(I2C_HandleTypeDef *hi2c);

// Đọc dữ liệu từ DHT20
HAL_StatusTypeDef DHT20_Read(I2C_HandleTypeDef *hi2c, DHT20_Data *data);

#endif
