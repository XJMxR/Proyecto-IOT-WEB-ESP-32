# Proyecto ESP32 vinculado a Ubidots para medir niveles de ruido

Este proyecto utiliza un ESP32 para leer niveles de ruido de un sensor KY-038 y enviar los datos a **Ubidots** mediante MQTT. A continuación, se detallan los pasos para configurar y ejecutar el código.

## Requisitos previos

### Hardware
- **ESP32**
- **Sensor de sonido KY-038**
- Cables para las conexiones
- Fuente de alimentación para el ESP32

### Software
- Arduino IDE con las siguientes librerías instaladas:
  - `WiFi.h`
  - `UbidotsEsp32Mqtt`

### Cuenta en Ubidots
- Regístrate en [Ubidots](https://ubidots.com/).
- Obtén un token para conectar el dispositivo.

---

## Conexión del sensor KY-038 al ESP32

| **KY-038** Pin  | **ESP32** Pin |
|------------------|---------------|
| **VCC**         | 3.3V          |
| **GND**         | GND           |
| **A0 (Analógico)** | GPIO 34     |
| **D0 (Digital)** | GPIO 25      |

---

## Explicación del código

1. **Configuración Wi-Fi y Ubidots**:
   - En el código, introduce tus credenciales Wi-Fi y el token de Ubidots.
   - Define las etiquetas de dispositivo y variables para publicar los datos en la plataforma.

2. **Pines del sensor**:
   - Asigna el pin analógico del KY-038 a GPIO 34 del ESP32 para leer los niveles de sonido.
   - Asigna el pin digital del KY-038 a GPIO 25 para detectar el umbral de ruido.

3. **Funciones principales**:
   - **`setup()`**: 
     - Configura los pines del sensor.
     - Establece la conexión Wi-Fi y la comunicación con Ubidots.
   - **`loop()`**:
     - Lee los valores del sensor:
       - **Analógico**: Convierte los valores a decibeles utilizando `map()`.
       - **Digital**: Detecta si el nivel de ruido supera un umbral.
     - Publica los datos en Ubidots.
     - Mantiene la conexión con el servidor MQTT.

4. **Callback**:
   - La función `callback()` maneja los mensajes entrantes desde Ubidots.

---

## Pasos para implementar

1. **Configurar Arduino IDE**:
   - Instala las librerías necesarias:
     - Ve a **Herramientas > Administrar bibliotecas** y busca `UbidotsEsp32Mqtt`.
   - Selecciona la placa ESP32 y el puerto correcto en **Herramientas**.

2. **Editar el código**:
   - Modifica los valores de:
     - SSID y contraseña de tu red Wi-Fi.
     - Token de Ubidots.
     - Pines asignados para el sensor.

3. **Cargar el código**:
   - Conecta el ESP32 y sube el programa desde el Arduino IDE.

4. **Verificar la conexión**:
   - Abre el **Monitor Serial** para confirmar que el ESP32 está enviando datos correctamente a Ubidots.

---

## Capturas

![ubitdots](https://github.com/user-attachments/assets/fcb8c5ea-4c56-4846-9848-6fff6923583a)


---

## Solución de problemas

1. **No conecta a Wi-Fi**:
   - Verifica las credenciales.
   - Asegúrate de que la red Wi-Fi está disponible.

2. **Datos no aparecen en Ubidots**:
   - Revisa el token y las etiquetas de las variables en Ubidots.

3. **Error de subida**:
   - Asegúrate de que la placa y el puerto están correctamente configurados en el IDE.

---

Con este proyecto, podrás monitorizar niveles de ruido en tiempo real y visualizarlos en la plataforma Ubidots. 🚀
