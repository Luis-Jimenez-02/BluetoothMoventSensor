# Español
Este codigo fue hecho en Arduino IDE pensado en la placa ESP32 que trae bluetooth integrado, usa el bluetooth clasico, para comunicarse por medio del serial.

Adicional al codigo, para probarlo en android se puede usar la aplicacion Bluetooth Serial Terminal

Este codigo básicamente toma la entrada de un sensor de movimiento PIR para hacer dos cosas: La primera es la encender un foco LED, la segunda es mandar una notificacion a la terminal que diga que detectó movimiento.

Desde el telefono, usando las MAC de la aplicacion, puede mandar un mensaje a la placa, para así prender o apagar el led de forma manual. Cabe resaltar que las MAC deben ser configuradas.

# English
This code was developed in Arduino IDE with the ESP32 board in mind, which comes with integrated Bluetooth. It utilizes classic Bluetooth for communication via serial.

In addition to the code, to test it on Android, you can use the Bluetooth Serial Terminal application.

Essentially, this code takes input from a PIR motion sensor to do two things: Firstly, it turns on an LED light, and secondly, it sends a notification to the terminal indicating motion detection.

From the phone, using the MAC addresses from the application, you can send a message to the board to manually turn the LED on or off. It's important to note that the MAC addresses must be configured.