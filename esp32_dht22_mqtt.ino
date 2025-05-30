#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <PubSubClient.h>
#include <DHTesp.h>

// Wi-Fi
const char* ssid = "Wokwi-GUEST";
const char* password = "";

// HiveMQ Cloud
const char* mqttServer = "06913b65a4074a33918b40135fc2664f.s1.eu.hivemq.cloud";
const int mqttPort = 8883;
const char* mqttUser = "userTeste";
const char* mqttPassword = "Teste123";
const char* mqttTopic = "esp32/dht";

WiFiClientSecure espClient;
PubSubClient client(espClient);

const int DHT_PIN = 18;
const int LED_PIN = 25;
DHTesp dhtSensor;

void connectWiFi() {
  Serial.print("Conectando ao Wi-Fi");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" Conectado!");
}

void connectMQTT() {
  espClient.setInsecure();  // Ignora verificação SSL
  client.setServer(mqttServer, mqttPort);
  while (!client.connected()) {
    Serial.print("Conectando ao MQTT...");
    String clientId = "esp32-" + String(random(0xffff), HEX);
    if (client.connect(clientId.c_str(), mqttUser, mqttPassword)) {
      Serial.println(" conectado!");
    } else {
      Serial.print(" falhou, rc=");
      Serial.print(client.state());
      Serial.println(" tentando novamente em 5s...");
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(DHT_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  dhtSensor.setup(DHT_PIN, DHTesp::DHT22);
  connectWiFi();
  connectMQTT();
}

void loop() {
  if (!client.connected()) {
    connectMQTT();
  }
  client.loop();

  TempAndHumidity data = dhtSensor.getTempAndHumidity();
  float tmp = data.temperature;

  Serial.println("Temp: " + String(tmp, 2) + "*C");
  Serial.println("Humidity: " + String(data.humidity, 2) + "%");
  Serial.println("---");

  if (tmp >= 20) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }

  // Publicar no tópico MQTT
  String payload = "{";
  payload += "\"temperature\":" + String(tmp, 2) + ",";
  payload += "\"humidity\":" + String(data.humidity, 2);
  payload += "}";

  client.publish(mqttTopic, payload.c_str());
  Serial.println("Publicado no MQTT: " + payload);

  delay(5000);
}
