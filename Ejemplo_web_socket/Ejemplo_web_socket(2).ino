#include <WiFi.h>
#include <WebSocketsServer.h>

const char* ssid = "";      // Cambia por tu SSID
const char* password = "";  // Cambia por tu contraseña

WebSocketsServer webSocket = WebSocketsServer(81); 
const int analogPin = 34;  // Pin A0 conectado al KY-038
const int digitalPin = 25; // Pin D0 conectado al KY-038 (elige uno de los pines digitales del ESP32)

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

  pinMode(digitalPin, INPUT);  // Configura el pin digital como entrada
}

void loop() {
  webSocket.loop();

  int nivelRuido = analogRead(analogPin);  // Leer nivel de sonido en la entrada analógica
  int estadoRuido = digitalRead(digitalPin);  // Leer el estado de la entrada digital (0 o 1)

  // Mostrar valores en la consola
  Serial.print("Nivel de ruido (analógico): ");
  Serial.println(nivelRuido);
  Serial.print("Detección de ruido (digital): ");
  Serial.println(estadoRuido == HIGH ? "Ruido detectado" : "No detectado");

  String mensaje = String(nivelRuido);
  webSocket.broadcastTXT(mensaje);  // Enviar valor analógico a los clientes WebSocket
  delay(500);  // Ajusta según sea necesario
}

void webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t length) {
  if (type == WStype_CONNECTED) {
    Serial.printf("Cliente %u conectado\n", num);
  } else if (type == WStype_TEXT) {
    Serial.printf("Mensaje recibido: %s\n", payload);
  }
}
