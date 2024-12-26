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
