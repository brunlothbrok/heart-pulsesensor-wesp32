# Trabalho Objetos Inteligentes Conectados - Mackenzie 2024
## Monitor Batimentos Cardíacos IOT
## O Codigo fonte do projeto se encontra na Branch Master
## Descrição do Projeto

Este projeto envolve a criação de um monitor de batimentos cardíacos utilizando o microcontrolador ESP32, um sensor de pulsação (PulseSensor), uma protoboard e fios para as conexões. O monitor envia os dados de batimentos cardíacos para a internet usando o protocolo MQTT, permitindo a monitoração remota em tempo real.

### Componentes Necessários

ESP32: Microcontrolador com conectividade Wi-Fi e Bluetooth. 

PulseSensor: Sensor que detecta os batimentos cardíacos.

Protoboard: Placa para montagem de circuitos temporários.

Jumpers (Wires): Fios para conectar os componentes.

Fonte de Alimentação: Com cabo micro-usb para alimentar o ESP32 e o sensor.  

## Montagem do Circuito

### Conexão do PulseSensor ao ESP32:

VCC do PulseSensor ao 3.3V do ESP32.

GND do PulseSensor ao GND do ESP32.

Sinal do PulseSensor a um pino analógico (A0) do ESP32.

Montagem na Protoboard:

Conecte o ESP32 e o PulseSensor na protoboard utilizando os jumpers.

### Modelo de montagem na Protoboard com imagem

![Circuit diagram of a Pulse Sensor with ESP8266 using Arduino ](https://github.com/brunlothbrok/heart-pulsesensor-wesp32/assets/170212070/b38f840e-f0b6-4149-8f04-e134a08b3e03)

## Explicação do Funcionamento

### Configuração Wi-Fi e MQTT:

O ESP32 se conecta a uma rede Wi-Fi.

Estabelece uma conexão com o broker MQTT especificado.

### Leitura dos Batimentos Cardíacos:

O PulseSensor detecta os batimentos cardíacos.

A frequência cardíaca (BPM) é calculada e verificada se é um batimento novo.

### Publicação dos Dados:

Os dados de BPM são enviados para o broker MQTT no tópico especificado.

Esses dados podem ser monitorados remotamente através de um cliente MQTT.

Este projeto oferece uma maneira prática de monitorar os batimentos cardíacos em tempo real usando a conectividade IoT, sendo útil para aplicações de saúde e bem-estar.

## Video demonstração total do projeto:

Link: https://www.youtube.com/watch?v=HgSdE-vFvLw

## Descrição do Hardware Utilizado

Para este projeto, utilizamos uma série de componentes de hardware e plataformas de desenvolvimento que permitem a criação de um monitor de batimentos cardíacos com conectividade à internet. Aqui está uma descrição detalhada de cada componente utilizado:

### 1. Plataforma de Desenvolvimento

Arduino IDE:

Descrição: Ambiente de desenvolvimento integrado (IDE) utilizado para programar microcontroladores como o ESP32. Fornece uma interface amigável para escrever, compilar e carregar código nos dispositivos.

Uso: Escrever o código do projeto, compilar e carregar o firmware no ESP32.

### 2. Microcontrolador

ESP32:

Descrição: Um microcontrolador potente com conectividade Wi-Fi e Bluetooth. Possui diversos pinos de entrada/saída digitais e analógicos, tornando-o ideal para projetos IoT.

Uso: Coleta os dados do sensor de batimentos cardíacos e envia-os via protocolo MQTT para um broker na internet.

### 3. Sensor

PulseSensor:

Descrição: Um sensor de frequência cardíaca que mede o pulso através da ponta do dedo ou do lóbulo da orelha. Possui três pinos: VCC, GND e Sinal.

Uso: Detecta os batimentos cardíacos e envia um sinal analógico correspondente ao ESP32.

### 4. Protoboard e Wires

Protoboard:

Descrição: Uma placa de ensaio usada para montagem temporária de circuitos eletrônicos. Facilita a conexão de componentes sem necessidade de solda.

Uso: Montar o circuito temporário conectando o ESP32 ao PulseSensor e aos fios.

Jumpers (Wires):

Descrição: Fios de conexão usados para ligar componentes na protoboard.

Uso: Conectar os pinos do PulseSensor aos pinos correspondentes do ESP32 na protoboard.

### 5. Fonte de Alimentação

Fonte de Alimentação com cabo micro-usb:

Descrição: Uma unidade que fornece energia elétrica ao circuito. Fonte utilizada via cabo micro-usb.

Uso: Alimentar o ESP32 e o PulseSensor.

### 6. Broker e Conexão MQTT

HiveMQ:

Descrição: Plataforma que fornece serviços de broker MQTT. Utilizada para gerenciar e monitorar a conexão e os dados transmitidos pelo protocolo MQTT.

## Documentação das Interfaces, Protocolos e Módulos de Comunicação

### 1. Interfaces

ESP32 Interfaces

#### GPIO (General Purpose Input/Output):

Descrição: Pinos multifuncionais que podem ser configurados como entrada ou saída digital.

Uso: Conectar o PulseSensor ao ESP32 (pinos VCC, GND e sinal analógico).

#### ADC (Analog to Digital Converter):

Descrição: Converte sinais analógicos em digitais. O ESP32 possui múltiplos canais ADC.

Uso: Leitura do sinal analógico do PulseSensor.

#### Wi-Fi:

Descrição: Interface de conectividade sem fio, permitindo que o ESP32 se conecte a redes Wi-Fi.

Uso: Estabelecer conexão com a internet para comunicação MQTT.

PulseSensor Interfaces

#### VCC:

Descrição: Pino de alimentação.

Uso: Conectado ao 3.3V do ESP32 para fornecer energia ao sensor.

#### GND:

Descrição: Pino de terra.

Uso: Conectado ao GND do ESP32.

#### Signal:

Descrição: Pino de saída do sinal analógico.

Uso: Conectado a um pino ADC do ESP32 para leitura do sinal dos batimentos cardíacos.

### 2. Protocolos

Wi-Fi

#### IEEE 802.11:

Descrição: Padrão de redes sem fio utilizado pelo ESP32 para se conectar a uma rede local.

Configuração: Especificada no código para conectar-se a uma rede SSID e senha definidos pelo usuário.

### MQTT (Message Queuing Telemetry Transport)

Descrição: Protocolo de mensagem leve ideal para dispositivos IoT com recursos limitados.

#### Características:

Publicação/Assinatura: Modelo de comunicação onde dispositivos publicam mensagens em tópicos específicos e outros dispositivos se inscrevem para receber essas mensagens.

Qualidade de Serviço (QoS): Define a confiabilidade da entrega da mensagem (QoS 0, 1 ou 2).

Persistência: Mensagens podem ser retidas no broker até que novos clientes se conectem.

#### Uso no Projeto:

Publicação: O ESP32 publica dados de BPM no tópico sensor/batimentos.

Broker: Utilizado o broker público mqtt.eclipseprojects.io.

Uso: Facilitar a conexão MQTT e monitorar os dados de batimentos cardíacos enviados pelo ESP32.

#### Broker MQTT Eclipse (mqtt.eclipseprojects.io):

Descrição: Um broker MQTT de código aberto e gratuito, mantido pela Eclipse Foundation. Facilita a comunicação entre dispositivos IoT.

Uso: Servidor ao qual o ESP32 se conecta para enviar os dados dos batimentos cardíacos via MQTT.

# O CÓDIGO FONTE DO PROJETO SE ENCONTRA NA BRANCH MASTER
