# contador-pessoas-esp32-iot
Aula 1 Unidade Currícular IOT

### 🌐 Contador de Pessoas com ESP32 e IoT (Wokwi + ThingSpeak)

Este é um projeto inicial de Internet das Coisas (IoT) desenvolvido para registrar o fluxo de pessoas em um ambiente utilizando o simulador online Wokwi e a plataforma de nuvem ThingSpeak. 

### 🚀 Como Funciona

O sistema utiliza um sensor de movimento para detectar a passagem de pessoas. Cada detecção acende um LED indicador e soma +1 em um contador interno. A cada 15 segundos, o número total de pessoas é enviado via Wi-Fi para o banco de dados do ThingSpeak, permitindo acompanhar os gráficos em tempo real pelo celular ou computador. 

### 🛠️ Componentes Utilizados

* Placa ESP32
* Sensor de Movimento PIR
* LED Difuso (Indicador Visual)
* Resistor de 220 Ohms
* Plataforma ThingSpeak (Nuvem/Gráficos)

### 📌 Como Executar o Projeto

1. Clone este repositório.
2. Abra o código sketch.ino em sua IDE Arduino ou copie-o para o simulador Wokwi.
3. Configure suas credenciais de Wi-Fi e as chaves de API do seu canal ThingSpeak no código.
4. Faça o upload e abra o Monitor Serial para acompanhar o envio de dados.
