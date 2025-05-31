# Projeto IoT: Monitoramento de Temperatura e Umidade com MQTT

Este projeto utiliza um microcontrolador **ESP32**, um sensor **DHT22** e um **LED** para monitorar a temperatura e a umidade de um ambiente. Quando a temperatura atinge ou ultrapassa 20 °C, o LED é acionado automaticamente como alerta. Os dados coletados são enviados para um **broker MQTT na nuvem (HiveMQ)**, permitindo o monitoramento remoto via internet.

---

## Funcionalidades

- Leitura de **temperatura e umidade** com sensor DHT22  
- Publicação dos dados no formato **JSON** via protocolo MQTT  
- Acesso remoto em tempo real usando **HiveMQ Web Client**  
- **Acionamento do LED** sempre que a temperatura ≥ 20 °C  
- Comunicação segura via **TLS (porta 8884)**  

---

## Fluxo de Funcionamento

1. O ESP32 conecta-se automaticamente ao Wi-Fi.
2. O sensor DHT22 realiza a leitura dos dados.
3. Os dados são publicados no tópico MQTT `esp32/dht` no formato JSON.
4. Um cliente MQTT (ex: HiveMQ Web Client) recebe os dados.
5. Se a temperatura for ≥ 20 °C, o LED acende.
6. Se a temperatura for < 20 °C, o LED apaga automaticamente.

---

## Materiais Utilizados

| Componente | Descrição |
|------------|-----------|
| **ESP32**  | Microcontrolador com Wi-Fi |
| **DHT22**  | Sensor de temperatura e umidade |
| **LED**    | Atuador visual (alerta de temperatura) |
| **Resistor 220 Ω** | Limitador de corrente para o LED |
| **Software** | [Wokwi](https://wokwi.com/) (simulação), [IDE Arduino](https://www.arduino.cc/en/software), [HiveMQ Web Client](https://www.hivemq.com/demos/websocket-client/) |

---

## Tópicos MQTT

| Tópico       | Descrição                      |
|--------------|--------------------------------|
| `esp32/dht`  | Publicação de dados JSON com temperatura e umidade |

**Exemplo de payload enviado:**
```json
{
  "temperature": 24.00,
  "humidity": 40.00
}
```

---

## Bibliotecas Utilizadas

- [`DHT sensor library for ESPx`](https://github.com/beegee-tokyo/DHTesp)
- [`PubSubClient`](https://github.com/knolleary/pubsubclient)

---

## Resultados Esperados

- Os dados são recebidos no HiveMQ Web Client a cada 5 segundos.
- O LED acende quando a temperatura for ≥ 20 °C.
- A comunicação é realizada via protocolo MQTT sobre **TLS**, garantindo segurança.

---

## Autor

**Marielle Santos da Silva**  
Estudante de Análise e Desenvolvimento de Sistemas  
Universidade Presbiteriana Mackenzie  
