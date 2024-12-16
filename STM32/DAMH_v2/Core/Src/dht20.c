/*
 * dht20.c
 *
 *  Created on: Dec 12, 2024
 *      Author: Acer
 */

#include "dht20.h"

extern I2C_HandleTypeDef hi2c2;

HAL_StatusTypeDef DHT20_Init(I2C_HandleTypeDef *hi2c) {
    uint8_t command = 0xAC; // Lệnh khởi tạo DHT20
    uint8_t init_data[3] = {command, 0x33, 0x00};
    HAL_StatusTypeDef ret;

    // Gửi lệnh khởi tạo
    ret = HAL_I2C_Master_Transmit(hi2c, DHT20_I2C_ADDRESS, init_data, 3, HAL_MAX_DELAY);
    HAL_Delay(10); // Đợi cảm biến khởi động
    return ret;
}

HAL_StatusTypeDef DHT20_Read(I2C_HandleTypeDef *hi2c, DHT20_Data *data) {
    uint8_t read_command = 0xAC;
    uint8_t raw_data[7];
    HAL_StatusTypeDef ret;

    // Gửi yêu cầu đọc dữ liệu
    uint8_t request_data[3] = {read_command, 0x33, 0x00};
    ret = HAL_I2C_Master_Transmit(hi2c, DHT20_I2C_ADDRESS, request_data, 3, HAL_MAX_DELAY);
    if (ret != HAL_OK) return ret;

    // Chờ một chút trước khi đọc
    HAL_Delay(80);

    // Đọc dữ liệu trả về
    ret = HAL_I2C_Master_Receive(hi2c, DHT20_I2C_ADDRESS, raw_data, 7, HAL_MAX_DELAY);
    if (ret != HAL_OK) return ret;

    // Kiểm tra bit trạng thái
    if ((raw_data[0] & 0x80) != 0) return HAL_ERROR;

    // Xử lý dữ liệu
    uint32_t humidity_raw = ((raw_data[1] << 16) | (raw_data[2] << 8) | raw_data[3]) >> 4;
    uint32_t temperature_raw = ((raw_data[3] & 0x0F) << 16) | (raw_data[4] << 8) | raw_data[5];

    data->humidity = ((float)humidity_raw / 1048576) * 100;
    data->temperature = ((float)temperature_raw / 1048576) * 200 - 50;

    return HAL_OK;
}

