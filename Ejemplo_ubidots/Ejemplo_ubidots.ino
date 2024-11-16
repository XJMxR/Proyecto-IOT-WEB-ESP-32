#include <WiFi.h>
#include "UbidotsEsp32Mqtt.h"

const char* SSID = "motorola one vision 8615";
const char* PASSWORD = "31e77e9c6bb6c";
#define TOKEN "BBUS-KUuotP0hBAvX4OhH2fOrFTUb7SghPs"
#define DEVICE_LABEL "Sound"
#define VARIABLE_LABEL_ANALOG "nivel_ruido"
#define VARIABLE_LABEL_DIGITAL "Decibeles"

// Pines de conexión
#define SOUND_SENSOR_ANALOG_PIN 34 // A0 del KY-038
#define SOUND_SENSOR_DIGITAL_PIN 25 // D0 del KY-038

Ubidots ubidots(TOKEN);

/****************************************
 * Auxiliar Functions
 ****************************************/

// Función de callback para manejar mensajes entrantes
void callback(char *topic, byte *payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}

/****************************************
 * Main Functions
 ****************************************/

void setup() {
  Serial.begin(115200);
  pinMode(SOUND_SENSOR_DIGITAL_PIN, INPUT);  // Configura el pin digital como entrada

  ubidots.setDebug(true);  // Activa los mensajes de depuración
  ubidots.connectToWifi(SSID,PASSWORD);
  ubidots.setCallback(callback);
  ubidots.setup();
  ubidots.reconnect();
}

void loop() {
  if (!ubidots.connected()) {
    ubidots.reconnect();
  }

  // Leer salida analógica (nivel de sonido)
  int valor_analogico = analogRead(SOUND_SENSOR_ANALOG_PIN);
  float nivel_ruido_db = map(valor_analogico, 0, 4095, 0, 120);  // Ajusta a rango de 0-120 dB

  // Leer salida digital (detección de umbral)
  int umbral_ruido = digitalRead(SOUND_SENSOR_DIGITAL_PIN);

  // Publicar datos en Ubidots
  ubidots.add(VARIABLE_LABEL_ANALOG, nivel_ruido_db);
  ubidots.add(VARIABLE_LABEL_DIGITAL, umbral_ruido);

  // Enviar datos a Ubidots usando MQTT
  bool sent = ubidots.publish(DEVICE_LABEL);
  
  if (sent) {
    Serial.println("Datos enviados exitosamente a Ubidots.");
  } else {
    Serial.println("Error al enviar datos a Ubidots.");
  }

  ubidots.loop();  // Mantener la conexión con el servidor MQTT
  delay(1500);     // Esperar 1.5 segundos antes de la próxima lectura
}