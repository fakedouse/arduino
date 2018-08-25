// роботехника18.рф

#include "DHT.h" // подключаем библиотеку для датчика

DHT dht(2, DHT11); // сообщаем на каком порту будет датчик

int led = 13;

void setup() // процедура setup

{

dht.begin(); // запускаем датчик влажности DHT11
pinMode(led, OUTPUT);
Serial.begin(9600); // подключаем монитор порта
Serial.println("DHT TEST"); // пишем один раз

}

void loop() // процедура loop

{

// считываем температуру (t) и влажность (h) каждые 250 мс

float h = dht.readHumidity();
float t = dht.readTemperature();
int blinked;

// выводим температуру (t) и влажность (h) на монитор порта

Serial.print("Humidity: ");
Serial.print(h);
Serial.print(" %\t");
Serial.print("Temperature: ");
Serial.print(t);
Serial.println(" *C");

if (h > 20 && h <= 40) 
  {
    blinked = 1;
  } else if (h > 40 && h <= 60) {
    blinked = 2;
  } else if (60 < h && h <= 80) {
    blinked = 3;
  } else if (80 < h && h <= 90) {
    blinked = 4;
  } else {
    blinked = 5;
  }
Serial.print("Blinked: ");
Serial.println(blinked);

switch (blinked) {
  case 1:
    digitalWrite(led, HIGH);
    delay(1500);
    digitalWrite(led, LOW);
    delay(1500);
    break;
  case 2:
    digitalWrite(led, HIGH);
    delay(1000);
    digitalWrite(led, LOW);
    delay(1000);
    break;
  case 3:
    digitalWrite(led, HIGH);
    delay(500);
    digitalWrite(led, LOW);
    delay(500);
    break;
  case 4:
    digitalWrite(led, HIGH);
    delay(300);
    digitalWrite(led, LOW);
    delay(300);
    break;
  case 5:
    digitalWrite(led, HIGH);
    delay(100);
    digitalWrite(led, LOW);
    delay(100);
    break;
  default:
    digitalWrite(led, LOW);
    break;
  }
}
