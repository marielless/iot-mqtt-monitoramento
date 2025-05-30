# 🌡️ Projeto IoT: Monitoramento de Temperatura e Umidade com MQTT

Este projeto utiliza um ESP32, sensor DHT22 e um LED para monitorar a temperatura e umidade de um ambiente. Os dados são enviados em tempo real via protocolo MQTT para um broker na nuvem, permitindo a visualização remota dos valores. Caso a temperatura ultrapasse um limite definido (ex: 20 °C), um LED é acionado como alerta visual.

---

## 🔧 Materiais Utilizados

| Componente | Descrição |
|------------|-----------|
| ESP32      | Placa microcontrolada com Wi-Fi embutido |
| DHT22      | Sensor de temperatura e umidade de alta precisão |
| LED        | Atuador visual de alerta para temperatura |
| Resistor   | 220 Ω (proteção para o LED) |
| Software   | [Wokwi](https://wokwi.com/) (simulador online), [HiveMQ](https://www.hivemq.com/) (broker MQTT), [IDE Arduino](https://www.arduino.cc/en/software) |

---

## ⚙️ Funcionamento e Funcionalidades

1. O ESP32 conecta-se automaticamente à rede Wi-Fi configurada.
2. O sensor DHT22 realiza leituras periódicas de temperatura e umidade.
3. Os dados coletados são enviados no formato JSON para o tópico MQTT `esp32/dht`.
4. Um cliente MQTT (como o [MQTT Explorer](https://mqtt-explorer.com/) ou o [HiveMQ Web Client](https://www.hivemq.com/demos/websocket-client/)) pode visualizar as mensagens em tempo real.
5. Se a temperatura ≥ 20 °C, o LED acende automaticamente.
6. Quando a temperatura retorna abaixo de 20 °C, o LED apaga.

### Destaques da solução

- Comunicação segura com HiveMQ via TLS (porta 8883)
- Mensagens publicadas em JSON
- Visualização em tempo real de dados com clientes MQTT
- Funciona em simulação 100% online no [Wokwi](https://wokwi.com/)

---

## Tópico MQTT Utilizado

- Tópico: `esp32/dht`
- Exemplo de Payload publicado:

```json
{
  "temperature": 29.85,
  "humidity": 56.2
}
