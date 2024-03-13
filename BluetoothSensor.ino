#include <BluetoothSerial.h>
#include <BTAddress.h>
#include <BTAdvertisedDevice.h>
#include <BTScan.h>

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable
it
#endif
BluetoothSerial SerialBT;

#define PIR_PIN 25 // Pin del sensor PIR
#define LED_PIN 18 // Pin del LED

int pirState = LOW;
String message = "";
char incomingChar;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32LJ"); // Nombre del dispositivo Bluetooth
  pinMode(PIR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  Serial.println("El dispositivo ha iniciado. ¡Puedes emparejarlo con Bluetooth!");
}

void loop() {
  pirState = digitalRead(PIR_PIN);

  if (pirState == HIGH) {
    digitalWrite(LED_PIN, HIGH);
    SerialBT.println("Movimiento detectado"); // Enviar notificación por Bluetooth
    delay(1000);
  } else {
    digitalWrite(LED_PIN, LOW);
    if (SerialBT.available()){
      char incomingChar = SerialBT.read();
      if (incomingChar != '\n'){
        message += String(incomingChar);
      }
        else{
        message = "";
      }
      Serial.write(incomingChar);
    }

    // Comprobar el mensaje
    if (message =="led_on"){
      digitalWrite(LED_PIN, HIGH); 
    }
    else if (message =="led_off"){
      digitalWrite(LED_PIN, LOW);
    }
  }

  delay(30);
}