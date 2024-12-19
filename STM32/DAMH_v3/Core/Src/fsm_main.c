/*
 * fsm_main.c
 *
 *  Created on: Dec 18, 2024
 *      Author: Acer
 */

#include "fsm_main.h"

void fsm_main(){
    switch (current_state) {
    	case INIT:
    		lcd_init();
    		current_state = READING;
    		break;

        case READING:
            if (DHT20_Read(&sensor_data) == HAL_OK) {
                current_state = UPDATING_DISPLAY; // Chuyển sang trạng thái cập nhật hiển thị
            } else {
                current_state = ERROR_DISPLAY; lcd_send_string("Read Err!");  // Chuyển sang trạng thái lỗi
            }
            break;

        case UPDATING_DISPLAY:
            sprintf(buffer1, "TEMP:%.1f", sensor_data.temperature);
            sprintf(buffer2, "HUMI:%.1f", sensor_data.humidity);
            sprintf(sendBuffer, "%s;%s\n", buffer1, buffer2);
            UART_SendString(sendBuffer);
            // Cập nhật nhiệt độ nếu thay đổi
            if (sensor_data.temperature != last_temperature) {
                lcd_goto_XY(1, 0); // Vị trí dòng 1
                lcd_send_string("TEMP:"); // Ghi nhãn
                char temp_display[8];
                sprintf(temp_display, "%.1f \xDF""C", sensor_data.temperature); // Định dạng nhiệt độ
                lcd_send_string(temp_display); // Hiển thị nhiệt độ
                last_temperature = sensor_data.temperature; // Cập nhật giá trị cũ
            }

            // Cập nhật độ ẩm nếu thay đổi
            if (sensor_data.humidity != last_humidity) {
                lcd_goto_XY(0, 0); // Vị trí dòng 2
                lcd_send_string("HUMI:"); // Ghi nhãn
                char hum_display[8];
                sprintf(hum_display, "%.1f %%", sensor_data.humidity); // Định dạng độ ẩm
                lcd_send_string(hum_display); // Hiển thị độ ẩm
                last_humidity = sensor_data.humidity; // Cập nhật giá trị cũ
            }

            Led_RGB_temp();

            // Quay lại trạng thái đọc dữ liệu
            current_state = READING;
            break;

        case ERROR_DISPLAY:
            // Hiển thị thông báo lỗi
            lcd_clear_display();
            lcd_goto_XY(0, 0);
            lcd_send_string("Read Err!");

            // Quay lại trạng thái đọc dữ liệu
            HAL_Delay(1000);
            current_state = READING;
            break;

        default:
            // Xử lý trạng thái không hợp lệ (nếu cần)
            current_state = INIT;
            break;
    }
}
