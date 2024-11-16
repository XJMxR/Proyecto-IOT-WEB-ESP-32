#include <WiFi.h>
#include <WebSocketsServer.h>

const char* ssid = "POCO X5 Pro 5G";  // Cambia por tu SSID
const char* password = "Facil123";      // Cambia por tu contraseña

WebSocketsServer webSocket = WebSocketsServer(81);
const int analogPin = 34;  // Pin A0 conectado al KY-038

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando a WiFi...");
  }
  Serial.println("Conectado. IP: " + WiFi.localIP().toString());

  webSocket.begin();
  webSocket.onEvent(webSocketEvent);
}

void loop() {
  webSocket.loop();

  int nivelRuido = analogRead(analogPin);  // Leer nivel de sonido
  String mensaje = String(nivelRuido);

  webSocket.broadcastTXT(mensaje);  // Enviar valor a los clientes
  delay(500);                       // Ajusta según sea necesario
}

void webSocketEvent(uint8_t num, WStype_t type, uint8_t* payload, size_t length) {
  if (type == WStype_CONNECTED) {
    Serial.printf("Cliente %u conectado\n", num);
  } else if (type == WStype_TEXT) {
    Serial.printf("Mensaje recibido: %s\n", payload);
  }
}
