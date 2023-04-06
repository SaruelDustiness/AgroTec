// C++ code
//
#include <WiFi.h>
#include <DHT.h>

//criar constantes da rede
const char* ssid = "POCO";
const char* password = "abracadabra";

#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  WiFi.begin(ssid, password);
  WiFi.mode(WIFI_MODE_STA);

  pinMode(12, OUTPUT);
  pinMode(14, OUTPUT);

  Serial.begin(9200);
  dht.begin();
}

void loop()
{

  while (WiFi.status() != WL_CONNECTED) {
    digitalWrite(12, HIGH);
    digitalWrite(14, LOW);
  }
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());

  digitalWrite(12, LOW);
  digitalWrite(14, HIGH);

  if (WiFi.status() != WL_CONNECTED) {
    WiFi.begin(ssid, password);
  }

  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  if (!isnan(temperature) && !isnan(humidity)) {
    Serial.print("Temperatura: ");
    Serial.println(temperature);
    Serial.print("Umidade: ");
    Serial.println(humidity);
  }
  delay(4000);

}
