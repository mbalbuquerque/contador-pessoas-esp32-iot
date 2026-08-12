#include <WiFi.h>
#include <ThingSpeak.h>

// Configurações do Wi-Fi simulado do Wokwi
const char* SSID = "Wokwi-GUEST";
const char* PASSWORD = "";

// Configurações do ThingSpeak (Substitua pelos seus dados depois)
unsigned long CanalID = 1234567;          // Coloque o ID do seu canal aqui
const char* ChaveEscrita = "SUA_CHAVE";   // Coloque sua Write API Key aqui

const int pinoPIR = 13;
const int pinoLED = 12;

int contadorPessoas = 0;
bool movimentoDetectado = false;

WiFiClient cliente;

void setup() {
  Serial.begin(115200);
  pinMode(pinoPIR, INPUT);
  pinMode(pinoLED, OUTPUT);

  // Conectando ao Wi-Fi do Wokwi
  Serial.print("Conectando ao Wi-Fi");
  WiFi.begin(SSID, PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConectado com sucesso!");

  ThingSpeak.begin(cliente);
}

void loop() {
  int estadoPIR = digitalRead(pinoPIR);

  // Detecta quando o sensor muda de "sem movimento" para "com movimento"
  if (estadoPIR == HIGH && !movimentoDetectado) {
    movimentoDetectado = true;
    contadorPessoas++;
    digitalWrite(pinoLED, HIGH); // Acende o LED
    
    Serial.print("Movimento detectado! Total de pessoas: ");
    Serial.println(contadorPessoas);
    delay(1000); // Evita contar a mesma pessoa várias vezes seguidas
  } 
  
  if (estadoPIR == LOW) {
    movimentoDetectado = false;
    digitalWrite(pinoLED, LOW); // Apaga o LED
  }

  // Envia os dados para a nuvem a cada 15 segundos (tempo mínimo do ThingSpeak gratuito)
  static unsigned long ultimoEnvio = 0;
  if (millis() - ultimoEnvio > 15000) {
    ultimoEnvio = millis();

    // Define o valor do Campo 1 com o nosso contador
    ThingSpeak.setField(1, contadorPessoas);
    
    // Envia para o ThingSpeak
    int statusDeRetorno = ThingSpeak.writeFields(CanalID, ChaveEscrita);

    if (statusDeRetorno == 200) {
      Serial.println("Dados enviados para a nuvem com sucesso!");
    } else {
      Serial.println("Erro ao enviar dados. Código: " + String(statusDeRetorno));
    }
  }
}
