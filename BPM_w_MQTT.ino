#include <PubSubClient.h>
#include <WiFi.h>

const char *ssid = "Martins-2ghz";
const char *password = "EMNRBG188";

int PulseSensorPin = A0;  // Sensor de pulso conectado ao pino analógico A0 do NodeMCU

int Signal;               // Armazena o valor bruto do sinal do sensor
int Threshold = 200;      // Determina o limite para detectar um batimento cardíaco

unsigned long lastBeatTime = 0;  // Momento da última detecção de batimento
unsigned int bpm = 0;            // Armazena o batimento cardíaco por minuto

const char* mqtt_server = "mqtt.eclipseprojects.io";
const char* mqtt_topic = "sensor/bpm"; // Tópico para publicar os dados de BPM

WiFiClient espClient;
PubSubClient client(espClient);

void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Conectando a ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi conectado");
  Serial.print("Endereço IP: ");
  Serial.println(WiFi.localIP());
}

void reconnect() {
  // Loop até conseguir se conectar ao broker
  while (!client.connected()) {
    Serial.print("Tentando conexão MQTT...");
    // Tenta se conectar
    if (client.connect("ESP32Client")) {
      Serial.println("conectado");
    } else {
      Serial.print("falhou, rc=");
      Serial.print(client.state());
      Serial.println(" tentando novamente em 5 segundos");
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);       // Inicia a comunicação serial
  setup_wifi();
  client.setServer(mqtt_server, 1883);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  Signal = analogRead(PulseSensorPin);  // Lê o valor do sensor de pulso

  // Verifica se o sinal está acima do limite para detectar um batimento
  if (Signal > Threshold) {
    if ((millis() - lastBeatTime) > 200) {   // Verifica se passou tempo suficiente desde o último batimento
      bpm = 15000 / (millis() - lastBeatTime);   // Calcula o BPM
      lastBeatTime = millis();   // Atualiza o momento da última detecção de batimento
    }
  }

  // Imprime o BPM a cada segundo e publica no tópico MQTT
  static unsigned long lastPrintTime = 0;
  if (millis() - lastPrintTime >= 1000) {
    Serial.print("BPM: ");
    Serial.println(bpm);

    // Converte o valor de bpm para string e publica no tópico MQTT
    char bpmString[8];
    dtostrf(bpm, 1, 2, bpmString);
    client.publish(mqtt_topic, bpmString);

    lastPrintTime = millis();
  }

  delay(10); // Pequena pausa antes da próxima leitura do sensor
}
