# Projeto IoT: Monitoramento de Temperatura e Umidade com MQTT

Este projeto utiliza um ESP32, sensor DHT22 e um LED para monitorar a temperatura e umidade de um ambiente. Os dados são enviados em tempo real via protocolo MQTT para um broker na nuvem, permitindo a visualização remota dos valores. Caso a temperatura ultrapasse um limite definido (ex: 30°C), um LED é acionado como alerta visual.

## Componentes Utilizados
- ESP32
- Sensor DHT22 (temperatura e umidade)
- LED vermelho
- Resistor 220Ω
- Protoboard (simulada)

## Ferramentas e Tecnologias
- Arduino IDE
- Broker MQTT (HiveMQ / Mosquitto)
- Wi-Fi (simulado com Wokwi)
- Wokwi (simulador online gratuito)
- MQTT Explorer / HiveMQ Web Client

## Fluxo de Funcionamento
1. O ESP32 conecta-se à rede Wi-Fi.
2. O sensor DHT22 coleta dados de temperatura e umidade.
3. Os dados são publicados em um tópico MQTT no formato JSON.
4. Um cliente MQTT (como MQTT Explorer) recebe e exibe os dados.
5. Se a temperatura ≥ 20°C, o LED acende.
6. O LED apaga automaticamente abaixo do limite.

## Tópicos MQTT Utilizados
- `esp32/dht` → onde os dados de temperatura e umidade são publicados.
- Payload JSON:
```json
{ "temperature": 29.85, "humidity": 56.2 }
