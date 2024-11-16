# Indicador de Ruido en Tiempo Real

Este proyecto utiliza un **ESP32** para medir los niveles de ruido en tiempo real mediante un sensor KY-038 y muestra la información en una página web interactiva a través de WebSockets.



## Características

- **Medición en tiempo real**: Lee los datos del sensor de sonido conectado al ESP32.
- **Visualización interactiva**: Una página web muestra los niveles de ruido y un indicador LED virtual que cambia de color según la intensidad.
- **Conexión WebSocket**: Comunicación en tiempo real entre el ESP32 y la interfaz web.
- **Configuración adaptable**: Umbrales ajustables para definir niveles de ruido aceptables.



## ¿Qué es WebSocket y por qué se usa?

**WebSocket** es un protocolo que permite una comunicación bidireccional en tiempo real entre un cliente (como un navegador web) y un servidor (en este caso, el ESP32). A diferencia de las conexiones HTTP tradicionales, donde cada solicitud del cliente genera una respuesta del servidor, WebSocket establece un canal persistente, lo que lo hace ideal para aplicaciones que necesitan actualizar información de manera continua y eficiente.



En este proyecto:

1. **ESP32 como servidor WebSocket**:
   - Actúa como el punto central que recopila datos del sensor KY-038 y los envía a todos los clientes conectados en tiempo real.
   - Es eficiente, ya que evita la sobrecarga de abrir y cerrar conexiones para cada transmisión.

2. **Cliente web como receptor**:
   - Usa un navegador web para conectarse al servidor WebSocket del ESP32.
   - Recibe los datos continuamente y los utiliza para actualizar la interfaz gráfica sin necesidad de recargar la página.

Las ventajas de WebSocket en este proyecto incluyen:
- **Baja latencia**: Los datos se transmiten tan pronto como están disponibles.
- **Eficiencia**: Reduce el consumo de recursos del ESP32 y del navegador.
- **Experiencia fluida**: Permite una actualización constante de la interfaz sin interrupciones.



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

![image](https://github.com/user-attachments/assets/c07d23fd-f59e-4244-bc15-606c80174f68)



## Mejoras futuras

- Agregar un registro de datos para almacenar niveles de ruido a lo largo del tiempo.
- Implementar una interfaz de usuario más avanzada con gráficos en tiempo real.
- Compatibilidad con dispositivos móviles.

## Equipo 

Grupo IOT 2024B
