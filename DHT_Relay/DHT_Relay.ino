#include "DHT.h"

#define DHTPIN A5
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

#define RelayPin 7
const float KickOnTemp = 78.0;
const float KickOffTemp = 76.0;

unsigned long seconds = 1000L; // !!! SEE THE CAPITAL "L" USED!!!
unsigned long minutes = seconds * 60;


void setup() {
    Serial.begin(9600);
    Serial.println(F("DHTxx test!"));
    pinMode(RelayPin, OUTPUT);
    dht.begin();
}

void loop() {
    // Wait a few seconds between measurements.
    delay(2000);

    // Reading temperature or humidity takes about 250 milliseconds!
    // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
    float h = dht.readHumidity();
    // Read temperature as Celsius (the default)
    float t = dht.readTemperature();
    // Read temperature as Fahrenheit (isFahrenheit = true)
    float f = dht.readTemperature(true);

    // Check if any reads failed and exit early (to try again).
    if (isnan(h) || isnan(t) || isnan(f)) {
        Serial.println(F("Failed to read from DHT sensor!"));
        return;
    }

    // Compute heat index in Fahrenheit (the default)
    float hif = dht.computeHeatIndex(f, h);
    // Compute heat index in Celsius (isFahreheit = false)
    float hic = dht.computeHeatIndex(t, h, false);

    Serial.print(F("Humidity: "));
    Serial.print(h);
    Serial.print(F("%  Temperature: "));
    Serial.print(t);
    Serial.print(F("°C "));
    Serial.print(f);
    Serial.print(F("°F  Heat index: "));
    Serial.print(hic);
    Serial.print(F("°C "));
    Serial.print(hif);
    Serial.println(F("°F"));

    if (TempBelowKickOffTemp(f))
    {
        AcOn(false);
        delay(3 * minutes);
    }
    else if (TempAboveKickOnTemp(f)) {
        AcOn(true);
        delay(3 * minutes);
    }
    
}

bool TempBelowKickOffTemp(float f) {
    if (hif <= KickOffTemp)
    {
        return true;
    }
    return false;
}

bool TempAboveKickOnTemp(float f) {
    if (hif >= KickOnTemp)
    {
        return true;
    }
    return false;
}

void AcOn(bool On) {
    if (On)
    {
        digitalWrite(RelayPin, HIGH);
    }
    else {
        digitalWrite(RelayPin, LOW);
    }
}