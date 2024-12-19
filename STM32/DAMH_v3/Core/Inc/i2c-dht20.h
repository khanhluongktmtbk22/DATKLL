/*
 * i2c-dht20.h
 *
 *  Created on: Dec 18, 2024
 *      Author: Acer
 */

#ifndef INC_I2C_DHT20_H_
#define INC_I2C_DHT20_H_

#include "stm32f1xx_hal.h" // Thay đổi tùy theo dòng STM32 bạn dùng

#define DHT20_I2C_ADDRESS 0x38 << 1 // Địa chỉ của DHT20 (shift để phù hợp với HAL)

// Cấu trúc dữ liệu trả về từ DHT20
typedef struct {
    float temperature;
    float humidity;
} DHT20_Data;

// Khởi tạo DHT20
HAL_StatusTypeDef DHT20_Init();

// Đọc dữ liệu từ DHT20
HAL_StatusTypeDef DHT20_Read(DHT20_Data *data);

#endif /* INC_I2C_DHT20_H_ */
