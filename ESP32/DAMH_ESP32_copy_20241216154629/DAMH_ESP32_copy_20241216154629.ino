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
//   if (STM32Serial.available()) {
//     String data = STM32Serial.readStringUntil('\n'); // Đọc đến ký tự xuống dòng
//     Serial.println("Received raw data: " + data);

//     // Tách dữ liệu nhiệt độ và độ ẩm
//     String temperature = parseValue(data, "TEMP:");
//     String humidity = parseValue(data, "HUMI:");

//     // Hiển thị kết quả
//     if (temperature != "" && humidity != "") {
//       Serial.println("Temperature: " + temperature + " °C");
//       Serial.println("Humidity: " + humidity + " %");
//     } else {
//       Serial.println("Invalid data format.");
//     }
//   }
//   delay(20);
// }

// // Hàm tách giá trị dựa trên nhãn
// String parseValue(String data, String key) {
//   int startIndex = data.indexOf(key);
//   if (startIndex == -1) return ""; // Không tìm thấy nhãn

//   int endIndex = data.indexOf(';', startIndex);
//   if (endIndex == -1) endIndex = data.length(); // Không tìm thấy dấu ';'

//   return data.substring(startIndex + key.length(), endIndex);
// }













// #include <WiFi.h>
// #include <HardwareSerial.h>

// // Thông tin mạng Wi-Fi của bạn
// const char* ssid = "ACLAB";      // Tên Wi-Fi
// const char* password = "ACLAB2023";  // Mật khẩu Wi-Fi

// // UART Configuration
// HardwareSerial STM32Serial(2); // UART2 - RX: GPIO16, TX: GPIO17

// WiFiServer server(80); // Tạo server ở cổng 80

// // Biến lưu trữ nhiệt độ và độ ẩm
// String temperature = "N/A";
// String humidity = "N/A";

// void setup() {
//   Serial.begin(115200);

//   // Khởi tạo UART2
//   STM32Serial.begin(9600, SERIAL_8N1, 16, 17);
//   Serial.println("UART2 Initialized");

//   // Kết nối Wi-Fi
//   WiFi.begin(ssid, password);
//   Serial.print("Connecting to Wi-Fi");
//   while (WiFi.status() != WL_CONNECTED) {
//     delay(500);
//     Serial.print(".");
//   }
//   Serial.println("\nWi-Fi connected!");
//   Serial.println("IP address: " + WiFi.localIP().toString());

//   server.begin(); // Khởi động Web Server
// }

// void loop() {
//   // Đọc dữ liệu từ STM32
//   if (STM32Serial.available()) {
//     String data = STM32Serial.readStringUntil('\n');
//     Serial.println("Received data: " + data);

//     // Tách dữ liệu nhiệt độ và độ ẩm
//     temperature = parseValue(data, "TEMP:");
//     humidity = parseValue(data, "HUMI:");
//   }

//   // Chờ client kết nối đến web server
//   WiFiClient client = server.available();
//   if (client) {
//     Serial.println("New Client connected");
//     String currentLine = "";

//     while (client.connected()) {
//       if (client.available()) {
//         char c = client.read();
//         currentLine += c;

//         // Kết thúc request HTTP
//         if (c == '\n' && currentLine.length() == 1) {
//           sendWebPage(client); // Gửi giao diện web
//           break;
//         }
//       }
//     }
//     client.stop();
//     Serial.println("Client disconnected");
//   }
// }

// // Hàm tách giá trị từ chuỗi dữ liệu
// String parseValue(String data, String key) {
//   int startIndex = data.indexOf(key);
//   if (startIndex == -1) return "N/A";

//   int endIndex = data.indexOf(';', startIndex);
//   if (endIndex == -1) endIndex = data.length();

//   return data.substring(startIndex + key.length(), endIndex);
// }

// // Hàm gửi giao diện web cho client
// void sendWebPage(WiFiClient client) {
//   client.println("HTTP/1.1 200 OK");
//   client.println("Content-Type: text/html");
//   client.println("Connection: close");
//   client.println();
//   client.println("<!DOCTYPE HTML>");
//   client.println("<html>");
//   client.println("<head>");
//   client.println("<title>ESP32 Temperature and Humidity</title>");
//   client.println("<meta http-equiv='refresh' content='5'>"); // Tự động cập nhật sau 5 giây
//   client.println("</head>");
//   client.println("<body>");
//   client.println("<h1>ESP32 Web Server</h1>");
//   client.println("<h2>Temperature and Humidity Data</h2>");
//   client.println("<p><strong>Temperature:</strong> " + temperature + " &deg;C</p>");
//   client.println("<p><strong>Humidity:</strong> " + humidity + " %</p>");
//   client.println("</body>");
//   client.println("</html>");
// }




// #include <WiFi.h>
// #include <HardwareSerial.h>

// // Thông tin mạng Wi-Fi của bạn
// const char* ssid = "ACLAB";          // Tên Wi-Fi
// const char* password = "ACLAB2023";  // Mật khẩu Wi-Fi

// // UART Configuration
// HardwareSerial STM32Serial(2); // UART2 - RX: GPIO16, TX: GPIO17

// WiFiServer server(80); // Tạo server ở cổng 80

// // Biến lưu trữ nhiệt độ và độ ẩm
// String temperature = "N/A";
// String humidity = "N/A";

// void setup() {
//   Serial.begin(9600); // Sử dụng baud rate 9600 cho Serial Monitor
//   delay(1000);
//   Serial.println("ESP32 is starting...");

//   // Khởi tạo UART2 (STM32)
//   STM32Serial.begin(9600, SERIAL_8N1, 16, 17);
//   Serial.println("UART2 Initialized at 9600 baud");

//   // Kết nối Wi-Fi
//   WiFi.begin(ssid, password);
//   Serial.print("Connecting to Wi-Fi");
//   while (WiFi.status() != WL_CONNECTED) {
//     delay(500);
//     Serial.print(".");
//   }
//   Serial.println("\nWi-Fi connected!");
//   Serial.print("IP address: ");
//   Serial.println(WiFi.localIP());

//   server.begin(); // Khởi động Web Server
//   Serial.println("Web server started!");
// }

// void loop() {
//   // Đọc dữ liệu từ STM32
//   if (STM32Serial.available()) {
//     String data = STM32Serial.readStringUntil('\n');
//     Serial.println("Received data: " + data);

//     // Tách dữ liệu nhiệt độ và độ ẩm
//     temperature = parseValue(data, "TEMP:");
//     humidity = parseValue(data, "HUMI:");
//   }

//   // Chờ client kết nối đến web server
//   WiFiClient client = server.available();
//   if (client) {
//     Serial.println("New Client connected");
//     String currentLine = "";

//     while (client.connected()) {
//       if (client.available()) {
//         char c = client.read();
//         currentLine += c;

//         // Kết thúc request HTTP
//         if (c == '\n' && currentLine.length() == 1) {
//           sendWebPage(client); // Gửi giao diện web
//           break;
//         }
//       }
//     }
//     client.stop();
//     Serial.println("Client disconnected");
//   }
// }

// // Hàm tách giá trị từ chuỗi dữ liệu
// String parseValue(String data, String key) {
//   int startIndex = data.indexOf(key);
//   if (startIndex == -1) return "N/A";

//   int endIndex = data.indexOf(';', startIndex);
//   if (endIndex == -1) endIndex = data.length();

//   return data.substring(startIndex + key.length(), endIndex);
// }

// // Hàm gửi giao diện web cho client
// void sendWebPage(WiFiClient client) {
//   client.println("HTTP/1.1 200 OK");
//   client.println("Content-Type: text/html");
//   client.println("Connection: close");
//   client.println();
//   client.println("<!DOCTYPE HTML>");
//   client.println("<html>");
//   client.println("<head>");
//   client.println("<title>ESP32 Temperature and Humidity</title>");
//   client.println("<meta http-equiv='refresh' content='5'>"); // Tự động cập nhật sau 5 giây
//   client.println("</head>");
//   client.println("<body>");
//   client.println("<h1>ESP32 Web Server</h1>");
//   client.println("<h2>Temperature and Humidity Data</h2>");
//   client.println("<p><strong>Temperature:</strong> " + temperature + " &deg;C</p>");
//   client.println("<p><strong>Humidity:</strong> " + humidity + " %</p>");
//   client.println("</body>");
//   client.println("</html>");
// }

// void sendWebPage(WiFiClient client) {
//   Serial.println("Sending web page...");
  
//   // Gửi header HTTP chuẩn
//   client.println("HTTP/1.1 200 OK");
//   client.println("Content-Type: text/html");
//   client.println("Connection: close");
//   client.println();

//   // Gửi nội dung HTML
//   client.println("<!DOCTYPE html>");
//   client.println("<html>");
//   client.println("<head>");
//   client.println("<title>ESP32 Temperature and Humidity</title>");
//   client.println("<meta http-equiv='refresh' content='5'>");
//   client.println("<style>");
//   client.println("body { font-family: Arial, sans-serif; text-align: center; margin: 50px; }");
//   client.println("h1 { color: #333333; }");
//   client.println("</style>");
//   client.println("</head>");
//   client.println("<body>");
//   client.println("<h1>ESP32 Web Server</h1>");
//   client.println("<h2>Temperature and Humidity</h2>");
//   client.println("<p><strong>Temperature:</strong> " + temperature + " &deg;C</p>");
//   client.println("<p><strong>Humidity:</strong> " + humidity + " %</p>");
//   client.println("</body>");
//   client.println("</html>");
  
//   client.flush(); // Đảm bảo toàn bộ dữ liệu đã được gửi
//   client.stop();  // Đóng kết nối
//   Serial.println("Web page sent.");
// }


// #include <WiFi.h>
// #include <HardwareSerial.h>

// // Thông tin mạng Wi-Fi
// const char* ssid = "ACLAB";      // Tên Wi-Fi
// const char* password = "ACLAB2023";  // Mật khẩu Wi-Fi

// // UART Configuration
// HardwareSerial STM32Serial(2); // UART2 - RX: GPIO16, TX: GPIO17

// WiFiServer server(80); // Khởi động web server trên cổng 80

// // Biến lưu trữ nhiệt độ và độ ẩm
// String temperature = "N/A";
// String humidity = "N/A";

// void setup() {
//   Serial.begin(115200);
  
//   // Khởi tạo UART2
//   STM32Serial.begin(9600, SERIAL_8N1, 16, 17);
//   Serial.println("UART2 Initialized at 9600 baud");

//   // Kết nối Wi-Fi
//   WiFi.begin(ssid, password);
//   Serial.print("Connecting to Wi-Fi");
//   while (WiFi.status() != WL_CONNECTED) {
//     delay(500);
//     Serial.print(".");
//   }
//   Serial.println("\nWi-Fi connected!");
//   Serial.println("IP address: " + WiFi.localIP().toString());
  
//   server.begin(); // Bắt đầu server
//   Serial.println("Web server started!");
// }

// void loop() {
//   // Đọc dữ liệu từ STM32
//   if (STM32Serial.available()) {
//     String data = STM32Serial.readStringUntil('\n');
//     Serial.println("Received data: " + data);

//     // Tách dữ liệu nhiệt độ và độ ẩm
//     temperature = parseValue(data, "TEMP:");
//     humidity = parseValue(data, "HUMI:");
//     Serial.println("Parsed Temperature: " + temperature + " °C");
//     Serial.println("Parsed Humidity: " + humidity + " %");
//   }

//   // Chờ client kết nối
//   WiFiClient client = server.available();
//   if (client) {
//     Serial.println("\nNew Client connected");

//     String currentLine = ""; // Đọc request từ client
//     while (client.connected()) {
//       if (client.available()) {
//         char c = client.read();
//         Serial.write(c); // Log từng ký tự nhận được
//         currentLine += c;

//         // Kết thúc request HTTP (dấu xuống dòng kép)
//         if (c == '\n' && currentLine.length() == 1) {
//           Serial.println("End of client request. Sending HTTP response...");
//           Serial.println("Free Heap (Before): " + String(ESP.getFreeHeap())); // Log bộ nhớ trước khi gửi

//           sendWebPage(client); // Gửi phản hồi HTTP

//           Serial.println("Free Heap (After): " + String(ESP.getFreeHeap())); // Log bộ nhớ sau khi gửi
//           break;
//         }

//         // Reset dòng hiện tại nếu xuống dòng
//         if (c == '\n') {
//           currentLine = "";
//         }
//       }
//     }
//     client.stop(); // Đóng kết nối
//     Serial.println("Client disconnected");
//   }
// }

// // Hàm tách giá trị từ chuỗi dữ liệu
// String parseValue(String data, String key) {
//   int startIndex = data.indexOf(key);
//   if (startIndex == -1) return "N/A";

//   int endIndex = data.indexOf(';', startIndex);
//   if (endIndex == -1) endIndex = data.length();

//   return data.substring(startIndex + key.length(), endIndex);
// }

// // Hàm gửi giao diện web
// void sendWebPage(WiFiClient client) {
//   Serial.println("Sending web page...");

//   // Kiểm tra bộ nhớ trước khi gửi
//   Serial.println("Free Heap: " + String(ESP.getFreeHeap()));

//   client.println("HTTP/1.1 200 OK");
//   client.println("Content-Type: text/html");
//   client.println("Connection: close");
//   client.println();

//   client.println("<!DOCTYPE html>");
//   client.println("<html>");
//   client.println("<head>");
//   client.println("<title>ESP32 Temperature and Humidity</title>");
//   client.println("<meta http-equiv='refresh' content='5'>");
//   client.println("<style>");
//   client.println("body { font-family: Arial, sans-serif; text-align: center; margin: 50px; }");
//   client.println("h1 { color: #333333; }");
//   client.println("p { font-size: 1.2em; }");
//   client.println("</style>");
//   client.println("</head>");
//   client.println("<body>");
//   client.println("<h1>ESP32 Web Server</h1>");
//   client.println("<h2>Temperature and Humidity</h2>");
//   client.println("<p><strong>Temperature:</strong> " + temperature + " &deg;C</p>");
//   client.println("<p><strong>Humidity:</strong> " + humidity + " %</p>");
//   client.println("</body>");
//   client.println("</html>");

//   client.flush(); // Đảm bảo tất cả dữ liệu được gửi đi
//   delay(10);      // Thêm delay nhỏ để tránh ngắt kết nối sớm
//   Serial.println("Web page sent successfully.");
// }




#include <WiFi.h>
#include <WebServer.h> // Thư viện hỗ trợ web server cao cấp
#include <HardwareSerial.h>

const char* ssid = "ACLAB";
const char* password = "ACLAB2023";

// UART Configuration
HardwareSerial STM32Serial(2); // UART2 - RX: GPIO16, TX: GPIO17

WebServer server(80); // Khởi tạo WebServer trên cổng 80

String temperature = "N/A";
String humidity = "N/A";

void setup() {
  Serial.begin(115200);
  
  // Khởi tạo UART2
  STM32Serial.begin(115200, SERIAL_8N1, 16, 17);
  Serial.println("UART2 Initialized at 9600 baud");

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWi-Fi connected!");
  Serial.println("IP address: " + WiFi.localIP().toString());

  server.on("/", []() { sendWebPage(); });
  server.on("/data", []() { sendDataJSON(); });

  server.begin();
}

void loop() {
  // Đọc dữ liệu từ STM32
  if (STM32Serial.available()) {
    String data = STM32Serial.readStringUntil('\n');
    Serial.println("Received data: " + data);

    // Tách dữ liệu nhiệt độ và độ ẩm
    temperature = parseValue(data, "TEMP:");
    humidity = parseValue(data, "HUMI:");
    Serial.println("Parsed Temperature: " + temperature + " °C");
    Serial.println("Parsed Humidity: " + humidity + " %");
  }

  server.handleClient();
}

// void sendWebPage() {
//   server.send(200, "text/html",
//               "<!DOCTYPE html><html><body>"
//               "<h1>ESP32 Web Server</h1>"
//               "<p>Temperature: <span id='temperature'>Loading...</span></p>"
//               "<p>Humidity: <span id='humidity'>Loading...</span></p>"
//               "<script>setInterval(function() { fetch('/data').then(response => response.json()).then(data => { document.getElementById('temperature').textContent = data.temperature + ' °C'; document.getElementById('humidity').textContent = data.humidity + ' %'; }); }, 1000);</script>"
//               "</body></html>");
// }
void sendWebPage() {
  server.send(200, "text/html",
              "<!DOCTYPE html>"
              "<html lang='en'>"
              "<head>"
              "<meta charset='UTF-8'>"
              "<meta name='viewport' content='width=device-width, initial-scale=1.0'>"
              "<title>ESP32 Temperature & Humidity</title>"
              "<style>"
              "body { margin: 0; padding: 0; font-family: Arial, sans-serif; color: #fff; }"
              "body, html { height: 100%; overflow: hidden; }"
              "header { background: rgba(0, 0, 0, 0.7); text-align: center; padding: 20px 0; }"
              "header h1 { margin: 0; font-size: 32px; color: #FFD700; }"
              ".container { display: flex; justify-content: center; align-items: flex-start; height: 100%; background: url('https://statictuoitre.mediacdn.vn/thumb_w/640/2017/untitled-10-1504603921823.jpg') no-repeat center center/cover; padding-top: 130px;}"
              ".box { width: 250px; height: 150px; margin: 10px; display: flex; flex-direction: column; justify-content: center; align-items: center; background: rgba(0, 0, 0, 0.5); border-radius: 15px; box-shadow: 0 4px 10px rgba(0,0,0,0.3); }"
              ".box h2 { margin: 0; font-size: 24px; color: #FFD700; }"
              ".box p { font-size: 28px; font-weight: bold; margin: 10px 0 0; }"
              ".status { position: absolute; bottom: 10px; width: 100%; text-align: center; font-size: 14px; color: #fff; }"
              "</style>"
              "<script>"
              "function updateData() {"
              "  fetch('/data')"
              "    .then(response => response.json())"
              "    .then(data => {"
              "      document.getElementById('temperature').innerText = data.temperature + ' °C';"
              "      document.getElementById('humidity').innerText = data.humidity + ' %';"
              "      document.getElementById('status').innerText = 'Last updated: ' + new Date().toLocaleTimeString();"
              "    })"
              "    .catch(err => {"
              "      document.getElementById('status').innerText = 'Error updating data!';"
              "    });"
              "}"
              "setInterval(updateData, 1000);"
              "window.onload = updateData;"
              "</script>"
              "</head>"
              "<body>"
              "<header>"
              "<h1>ESP32 Temperature & Humidity Monitor</h1>"
              "</header>"
              "<div class='container'>"
              "<div class='box'>"
              "<h2>Temperature</h2>"
              "<p id='temperature'>Loading...</p>"
              "</div>"
              "<div class='box'>"
              "<h2>Humidity</h2>"
              "<p id='humidity'>Loading...</p>"
              "</div>"
              "</div>"
              "<p class='status' id='status'>Connecting...</p>"
              "</body>"
              "</html>");
}



void sendDataJSON() {
  server.send(200, "application/json", "{\"temperature\": \"" + temperature + "\", \"humidity\": \"" + humidity + "\"}");
}

// Hàm tách giá trị từ chuỗi dữ liệu
String parseValue(String data, String key) {
  int startIndex = data.indexOf(key);
  if (startIndex == -1) return "N/A";

  int endIndex = data.indexOf(';', startIndex);
  if (endIndex == -1) endIndex = data.length();

  return data.substring(startIndex + key.length(), endIndex);
}




// void sendWebPage(WiFiClient client) {
//   // client.println("HTTP/1.1 200 OK");
//   // client.println("Content-Type: text/html");
//   // client.println("Connection: close");
//   // client.println();

//   // // Gửi từng phần
//   // client.print("<!DOCTYPE html><html><body><h1>Temperature: ");
//   // client.print(temperature);
//   // client.print(" °C</h1><h1>Humidity: ");
//   // client.print(humidity);
//   // client.print(" %</h1></body></html>");

//   // client.flush();
//   // client.stop();
//   // Serial.println("Web page sent in chunks.");

//     client.println("HTTP/1.1 200 OK");
//   client.println("Content-Type: text/html");
//   client.println("Connection: close");
//   client.println();
//   client.println("<!DOCTYPE HTML>");
//   client.println("<html>");
//   client.println("<head>");
//   client.println("<title>ESP32 Temperature and Humidity</title>");
//   client.println("<meta http-equiv='refresh' content='5'>"); // Tự động cập nhật mỗi 5 giây
//   client.println("</head>");
//   client.println("<body>");
//   client.println("<h1>ESP32 Web Server</h1>");
//   client.println("<h2>Temperature and Humidity Data</h2>");
//   client.println("<p><strong>Temperature:</strong> " + temperature + " &deg;C</p>");
//   client.println("<p><strong>Humidity:</strong> " + humidity + " %</p>");
//   client.println("</body>");
//   client.println("</html>");
// }
// Hàm gửi giao diện web nối chuỗi
  // String html = "<!DOCTYPE html>\n";
  // html += "<html>\n";
  // html += "<head>\n";
  // html += "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n";
  // html += "<title>ESP32 Temperature and Humidity</title>\n";
  // html += "<style>\n";
  // html += "body {\n";
  // html += "  font-family: Arial, Helvetica, sans-serif;\n";
  // html += "  text-align: center;\n";
  // html += "  margin: 0;\n";
  // html += "  background-color: #f2f2f2;\n";
  // html += "}\n";
  // html += ".container {\n";
  // html += "  background-color: #fff;\n";
  // html += "  margin: 50px auto;\n";
  // html += "  padding: 20px;\n";
  // html += "  width: 300px;\n";
  // html += "  border-radius: 10px;\n";
  // html += "  box-shadow: 0px 0px 10px rgba(0, 0, 0, 0.1);\n";
  // html += "}\n";
  // html += "h1, h3 {\n";
  // html += "  color: #333333;\n";
  // html += "}\n";
  // html += "p {\n";
  // html += "  font-size: 1.2em;\n";
  // html += "  color: #007bff;\n";
  // html += "  margin: 10px 0;\n";
  // html += "}\n";
  // html += "</style>\n";
  // html += "</head>\n";
  // html += "<body>\n";
  // html += "<div class=\"container\">\n";
  // html += "  <h1>ESP32 Web Server</h1>\n";
  // html += "  <h3>Temperature and Humidity Data</h3>\n";
  // html += "  <p>Temperature: " + temperature + " &deg;C</p>\n";
  // html += "  <p>Humidity: " + humidity + " %</p>\n";
  // html += "</div>\n";
  // html += "</body>\n";
  // html += "</html>\n";

  // // Gửi HTTP header và nội dung
  // client.println("HTTP/1.1 200 OK");
  // client.println("Content-Type: text/html");
  // client.println("Connection: close");
  // client.println();
  // client.println(html);

  // client.flush(); // Đảm bảo tất cả dữ liệu được gửi đi
  // delay(10);
  // Serial.println("Web page sent successfully.");


// void sendWebPage(WiFiClient client) {
//   String html = "<!DOCTYPE html>\n";
//   html += "<html>\n";
//   html += "<head>\n";
//   html += "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n";
//   html += "<title>ESP32 Temperature and Humidity</title>\n";
//   html += "<style>\n";
//   html += "body {\n";
//   html += "  font-family: Arial, Helvetica, sans-serif;\n";
//   html += "  text-align: center;\n";
//   html += "  margin: 0;\n";
//   html += "  background-color: #f2f2f2;\n";
//   html += "}\n";
//   html += ".container {\n";
//   html += "  background-color: #fff;\n";
//   html += "  margin: 50px auto;\n";
//   html += "  padding: 20px;\n";
//   html += "  width: 300px;\n";
//   html += "  border-radius: 10px;\n";
//   html += "  box-shadow: 0px 0px 10px rgba(0, 0, 0, 0.1);\n";
//   html += "}\n";
//   html += "h1, h3 {\n";
//   html += "  color: #333333;\n";
//   html += "}\n";
//   html += "p {\n";
//   html += "  font-size: 1.2em;\n";
//   html += "  color: #007bff;\n";
//   html += "  margin: 10px 0;\n";
//   html += "}\n";
//   html += "</style>\n";
//   html += "</head>\n";
//   html += "<body>\n";
//   html += "<div class=\"container\">\n";
//   html += "  <h1>ESP32 Web Server</h1>\n";
//   html += "  <h3>Temperature and Humidity Data</h3>\n";
//   html += "  <p>Temperature: " + temperature + " &deg;C</p>\n";
//   html += "  <p>Humidity: " + humidity + " %</p>\n";
//   html += "</div>\n";
//   html += "</body>\n";
//   html += "</html>\n";

//   // Tính toán độ dài nội dung HTML
//   int contentLength = html.length();

//   // Gửi HTTP header với Content-Length
//   client.println("HTTP/1.1 200 OK");
//   client.println("Content-Type: text/html");
//   client.println("Connection: close");
//   client.println("Content-Length: " + String(contentLength));
//   client.println();
//   client.println(html);

//   client.flush(); // Đảm bảo tất cả dữ liệu được gửi đi
//   delay(10);
//   Serial.println("Web page sent successfully.");
// }


// #include <WiFi.h>

// const char* ssid = "ACLAB";
// const char* password = "ACLAB2023";

// WiFiServer server(80);

// void setup() {
//   Serial.begin(115200);
//   WiFi.begin(ssid, password);
//   while (WiFi.status() != WL_CONNECTED) {
//     delay(500);
//     Serial.print(".");
//   }
//   Serial.println("\nWi-Fi connected!");
//   Serial.println("IP address: " + WiFi.localIP().toString());

//   server.begin();
// }

// void loop() {
//   WiFiClient client = server.available();
//   if (client) {
//     Serial.println("New Client connected.");
//     client.println("HTTP/1.1 200 OK");
//     client.println("Content-Type: text/html");
//     client.println("Connection: close");
//     client.println();
//     // client.println("<!DOCTYPE html><html><body><h1>Hello, World!</h1></body></html>");
//     client.print("<!DOCTYPE html><html><body><h1>Temperature: ");
//     client.print(" °C</h1><h1>Humidity: ");
//     client.print(" %</h1></body></html>");

//     client.flush();
//     client.stop();
//     Serial.println("Response sent.");
//   }
// }


// void sendWebPage(WiFiClient client) {
//   client.println("HTTP/1.1 200 OK");
//   client.println("Content-Type: text/html");
//   client.println("Connection: close");
//   client.println();

//   // Gửi từng phần
//   client.print("<!DOCTYPE html><html><body><h1>Temperature: ");
//   client.print(" °C</h1><h1>Humidity: ");
//   client.print(" %</h1></body></html>");

//   client.flush();
//   client.stop();
//   Serial.println("Web page sent in chunks.");
// }