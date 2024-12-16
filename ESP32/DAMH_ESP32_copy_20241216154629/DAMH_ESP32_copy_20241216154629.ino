// #include <WiFi.h>
// #include <WebServer.h>

// const char* ssid = "ESP32 Wifi";
// const char* password = "12345";

// IPAddress local_ip(192,168,49,15);
// IPAddress gateway(192,168,49,1);
// IPAddress subnet(255,255,255,0);

// WebServer server(80);

// unit8_t LedPin = 2;
// bool LedStatus = LOW;

// void event_OnConnect(){
//   LedStatus = LOW;
//   Serial.println("chan so 2 cua esp32 dang tat");
//   server.send(200,"text/html", HTMLGui(LedStatus));
// }

// void event_ledon(){
//   LedStatus = HIGH;
//   Serial.println("chan so 2 cua esp32 dang bat");
//   server.send(200,"text/html", HTMLGui(LedStatus));
// }

// void event_ledoff(){
//   server.send(400,"text/html", "NotFound");
// }

// void event_NotFound(){
//   LedStatus = LOW;
//   Serial.println("chan so 2 cua esp32 dang tat");
//   server.send(200,"text/html", HTMLGui(LedStatus));
// }

// void setup() {
//   // put your setup code here, to run once:
// Serial.begin(115200);
// pinMode(LedPin, OUTPUT);

// WiFi.softAP(ssid, password);
// WiFi.softAPConfig(local_ip, gateway, subnet);
// delay(100);

// server.on("/", event_OnConnect);
// server.on("/ledon", event_ledon);
// server.on("/ledo", event_ledoff);
// server.onNotFound(event_NotFound)


// server.begin();
// Serial.println("Server is Starting");
// }

// void loop() {
//   // put your main code here, to run repeatedly:
//   server.handleClient();
//   if(LedStatus ==1){
//     digitalWrite(LedPin, 1);
//   }
//   else{
//     digitalWrite(LedPin, 0);
//   }
  
// }

// String HTMLGui(uint8_t led) {
//   String str = "<!DOCTYPE html>\n";
//   str += "<html>\n";
//   str += "<head>\n";
//   str += "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n";
//   str += "<style>\n";
//   str += "html {\n";
//   str += "  font-family: Arial, Helvetica, sans-serif;\n";
//   str += "  margin: 0px auto;\n";
//   str += "  text-align: center;\n";
//   str += "}\n";
//   str += ".container {\n";
//   str += "  background-color: #a7a3a8;\n";
//   str += "  width: 300px;\n";
//   str += "  border-radius: 10px;\n";
//   str += "  margin: auto;\n";
//   str += "  padding: 10px;\n";
//   str += "}\n";
//   str += "h1 {\n";
//   str += "  color: #fff;\n";
//   str += "  margin: 50px 30px;\n";
//   str += "}\n";
//   str += "h3 {\n";
//   str += "  color: #fff;\n";
//   str += "  margin-bottom: 50px;\n";
//   str += "}\n";
//   str += ".button {\n";
//   str += "  display: block;\n";
//   str += "  width: 80px;\n";
//   str += "  border: none;\n";
//   str += "  color: white;\n";
//   str += "  padding: 13px 30px;\n";
//   str += "  text-decoration: none;\n";
//   str += "  font-size: 25px;\n";
//   str += "  margin: 0px auto 35px;\n";
//   str += "  cursor: pointer;\n";
//   str += "  border-radius: 4px;\n";
//   str += "}\n";
//   str += ".button-off {\n";
//   str += "  background-color: red;\n";
//   str += "}\n";
//   str += ".button:active {\n";
//   str += "  background-color: blue;\n";
//   str += "}\n";
//   str += "p {\n";
//   str += "  color: red;\n";
//   str += "  margin-top: 10px;\n";
//   str += "}\n";
//   str += "</style>\n";
//   str += "</head>\n";
//   str += "<body>\n";
  
//   // Nội dung HTML tùy chỉnh với led (ví dụ: hiển thị trạng thái của LED)
//   str += "<div class=\"container\">\n";
//   str += "<h1>LED Status</h1>\n";
//   str += "<h3>Current LED state: ";
//   if (led == 1) {
//     str += "ON";
//   } else {
//     str += "OFF";
//   }
//   str += "</h3>\n";
//   str += "<a href=\"/toggle\" class=\"button button-off\">Toggle LED</a>\n";  // Giả định có một đường dẫn để thay đổi trạng thái LED
//   str += "</div>\n";
  
//   str += "</body>\n";
//   str += "</html>\n";
  
//   return str;
// }


// #include <WiFi.h>
// #include <WebServer.h>

// const char* ssid = "ESP32 Wifi";
// const char* password = "12345678";  // Đảm bảo mật khẩu có ít nhất 8 ký tự

// IPAddress local_ip(192,168,49,15);
// IPAddress gateway(192,168,49,1);
// IPAddress subnet(255,255,255,0);

// WebServer server(80);

// uint8_t LedPin = 2;  // Sử dụng GPIO2 cho LED
// bool LedStatus = LOW; // Trạng thái LED ban đầu là OFF

// // Hàm xử lý khi truy cập trang chính
// void event_OnConnect() {
//   server.send(200, "text/html", HTMLGui(LedStatus));
// }

// // Hàm xử lý khi nhấn nút chuyển đổi trạng thái LED
// void event_toggle_led() {
//   // Chuyển trạng thái LED từ ON sang OFF hoặc ngược lại
//   LedStatus = !LedStatus;  // Tính năng toggle
//   digitalWrite(LedPin, LedStatus);  // Cập nhật trạng thái LED
//   server.send(200, "text/html", HTMLGui(LedStatus));  // Gửi lại trang HTML với trạng thái mới
// }

// void setup() {
//   // Bắt đầu serial để kiểm tra
//   Serial.begin(115200);
//   pinMode(LedPin, OUTPUT);

//   // Cấu hình ESP32 làm điểm truy cập (Access Point)
//   WiFi.softAP(ssid, password);
//   WiFi.softAPConfig(local_ip, gateway, subnet);
//   delay(100);

//   // Định nghĩa các tuyến đường cho server
//   server.on("/", event_OnConnect);  // Hiển thị trang chính
//   server.on("/toggle", event_toggle_led);  // Đổi trạng thái LED khi nhấn nút

//   // Bắt đầu server
//   server.begin();
//   Serial.println("Server is Starting");
// }

// void loop() {
//   // Xử lý yêu cầu từ client
//   server.handleClient();
// }

// // Hàm tạo HTML cho giao diện
// String HTMLGui(uint8_t led) {
//   String str = "<!DOCTYPE html>\n";
//   str += "<html>\n";
//   str += "<head>\n";
//   str += "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n";
//   str += "<style>\n";
//   str += "html {\n";
//   str += "  font-family: Arial, Helvetica, sans-serif;\n";
//   str += "  margin: 0px auto;\n";
//   str += "  text-align: center;\n";
//   str += "}\n";
//   str += ".container {\n";
//   str += "  background-color: #a7a3a8;\n";
//   str += "  width: 300px;\n";
//   str += "  border-radius: 10px;\n";
//   str += "  margin: auto;\n";
//   str += "  padding: 10px;\n";
//   str += "}\n";
//   str += "h1 {\n";
//   str += "  color: #fff;\n";
//   str += "  margin: 50px 30px;\n";
//   str += "}\n";
//   str += "h3 {\n";
//   str += "  color: #fff;\n";
//   str += "  margin-bottom: 50px;\n";
//   str += "}\n";
//   str += ".button {\n";
//   str += "  display: block;\n";
//   str += "  width: 180px;\n";
//   str += "  border: none;\n";
//   str += "  color: white;\n";
//   str += "  padding: 13px 30px;\n";
//   str += "  text-decoration: none;\n";
//   str += "  font-size: 25px;\n";
//   str += "  margin: 0px auto 35px;\n";
//   str += "  cursor: pointer;\n";
//   str += "  border-radius: 4px;\n";
//   str += "}\n";
//   str += ".button-on {\n";
//   str += "  background-color: green;\n";
//   str += "}\n";
//   str += ".button-off {\n";
//   str += "  background-color: red;\n";
//   str += "}\n";
//   str += ".button:active {\n";
//   str += "  background-color: blue;\n";
//   str += "}\n";
//   str += "p {\n";
//   str += "  color: red;\n";
//   str += "  margin-top: 10px;\n";
//   str += "}\n";
//   str += "</style>\n";
//   str += "</head>\n";
//   str += "<body>\n";
  
//   // Nội dung HTML tùy chỉnh với LED (hiển thị trạng thái LED)
//   str += "<div class=\"container\">\n";
//   str += "<h1>LED Status</h1>\n";
//   str += "<h3>Current LED state: ";
//   if (led == HIGH) {
//     str += "ON";
//   } else {
//     str += "OFF";
//   }
//   str += "</h3>\n";
  
//   // Nút nhấn để chuyển trạng thái LED
//   if (led == HIGH) {
//     str += "<a href=\"/toggle\" class=\"button button-off\">Turn OFF LED</a>\n";
//   } else {
//     str += "<a href=\"/toggle\" class=\"button button-on\">Turn ON LED</a>\n";
//   }
  
//   str += "</div>\n";
//   str += "</body>\n";
//   str += "</html>\n";
  
//   return str;
// }


// #include <HardwareSerial.h>

// // Cấu hình UART
// HardwareSerial STM32Serial(2); // Sử dụng UART2

// void setup() {
//   // Khởi tạo Serial Debug để in ra màn hình
//   Serial.begin(9600); 
//   Serial.println("ESP32 UART Receiver Initialized");

//   // Khởi tạo UART2
//   // RX = GPIO16, TX = GPIO17 (có thể thay đổi theo thiết lập phần cứng của bạn)
//   STM32Serial.begin(9600, SERIAL_8N1, 16, 17); 
// }

// void loop() {
//   if (STM32Serial.available()>1) {
//     String data = STM32Serial.readString(); // Đọc toàn bộ dữ liệu
//     Serial.println("Received from STM32: " + data);
//   }
//   delay(20);
// }

#include <HardwareSerial.h>

// Cấu hình UART
HardwareSerial STM32Serial(2); // Sử dụng UART2

void setup() {
  // Khởi tạo Serial Debug để in ra màn hình
  Serial.begin(9600);
  Serial.println("ESP32 UART Receiver Initialized");

  // Khởi tạo UART2
  // RX = GPIO16, TX = GPIO17 (có thể thay đổi theo thiết lập phần cứng của bạn)
  STM32Serial.begin(9600, SERIAL_8N1, 16, 17);
}

void loop() {
  if (STM32Serial.available()) {
    String data = STM32Serial.readStringUntil('\n'); // Đọc đến ký tự xuống dòng
    Serial.println("Received raw data: " + data);

    // Tách dữ liệu nhiệt độ và độ ẩm
    String temperature = parseValue(data, "TEMP:");
    String humidity = parseValue(data, "HUMI:");

    // Hiển thị kết quả
    if (temperature != "" && humidity != "") {
      Serial.println("Temperature: " + temperature + " °C");
      Serial.println("Humidity: " + humidity + " %");
    } else {
      Serial.println("Invalid data format.");
    }
  }
  delay(20);
}

// Hàm tách giá trị dựa trên nhãn
String parseValue(String data, String key) {
  int startIndex = data.indexOf(key);
  if (startIndex == -1) return ""; // Không tìm thấy nhãn

  int endIndex = data.indexOf(';', startIndex);
  if (endIndex == -1) endIndex = data.length(); // Không tìm thấy dấu ';'

  return data.substring(startIndex + key.length(), endIndex);
}

