// snimac DALLAS DS18b20
#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 2  // Pin pre Dallas DS18B20
#define LED_PIN 5       // Pin pre LED diódu
#define prah_teplota 25

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup() {
    pinMode(LED_PIN, OUTPUT);
    sensors.begin();
    Serial.begin(115200);
    Serial.println("Zaciatok programu");
}

void loop() {
  //snimanie teploty
    sensors.requestTemperatures();
    float temperature = sensors.getTempCByIndex(0); //ziskanie teploty

    //vykreslenie na serialovy monitor
    Serial.print("Teplota: "); //vykreslenie bez odriadkovania
    Serial.print(temperature);
    Serial.println(" °C");  //vykreslenie s odriadkovanim
    
    // Zapnutie LED pri prekročení 30 °C, inak vypnutie
    if (temperature > prah_teplota) {
        digitalWrite(LED_PIN, HIGH);
    } else {
        digitalWrite(LED_PIN, LOW);
    }
    // perioda vzorkovania
    delay(1000);
}