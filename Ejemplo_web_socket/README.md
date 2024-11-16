# Indicador de Ruido en Tiempo Real

Este proyecto utiliza un **ESP32** para medir los niveles de ruido en tiempo real mediante un sensor KY-038 y muestra la información en una página web interactiva a través de WebSockets.

## Características

- **Medición en tiempo real**: Lee los datos del sensor de sonido conectado al ESP32.
- **Visualización interactiva**: Una página web muestra los niveles de ruido y un indicador LED virtual que cambia de color según la intensidad.
- **Conexión WebSocket**: Comunicación en tiempo real entre el ESP32 y la interfaz web.
- **Configuración adaptable**: Umbrales ajustables para definir niveles de ruido aceptables.

## Tecnologías utilizadas

- **Hardware**: ESP32, sensor KY-038.
- **Frontend**: HTML, CSS, JavaScript.
- **Backend**: Servidor WebSocket implementado en el ESP32.

## Cómo funciona

1. El ESP32 se conecta a una red Wi-Fi y actúa como servidor WebSocket.
2. Lee los valores analógicos del sensor KY-038 y los envía a los clientes conectados mediante WebSockets.
3. La página web interpreta los datos y:
   - Muestra el nivel de ruido en texto.
   - Cambia el color de un LED virtual:
     - Verde: Ruido bajo.
     - Rojo: Ruido alto.

## Configuración

1. **ESP32**:
   - Configura las credenciales de Wi-Fi en el archivo `.ino`.
   - Ajusta el umbral de ruido en la página web si es necesario (`if (ruido >= 450)`).
2. **Página web**:
   - Reemplaza `192.168.212.72` con la dirección IP local del ESP32.

## Requisitos

- ESP32 con soporte para Wi-Fi.
- Sensor KY-038 o equivalente.
- Navegador web compatible con WebSockets.

## Uso

1. Sube el código al ESP32 usando Arduino IDE.
2. Conecta el sensor KY-038 al pin analógico A0 del ESP32.
3. Abre la página web incluida (`index.html`) en un navegador y verifica la conexión con el ESP32.
4. Observa los niveles de ruido en tiempo real.

## Captura de pantalla

![Indicador de ruido](ruta/a/imagen.png)

## Mejoras futuras

- Agregar un registro de datos para almacenar niveles de ruido a lo largo del tiempo.
- Implementar una interfaz de usuario más avanzada con gráficos en tiempo real.
- Compatibilidad con dispositivos móviles.

## Licencia

Este proyecto está disponible bajo la licencia MIT.
