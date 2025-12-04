# Sensor de Movimento Arduino 🚀

Um projeto Arduino que implementa um sistema inteligente de controle de iluminação com sensor de movimento PIR (Passive Infrared), temporizador configurável e painel de controle com display LCD.

## 📋 Estrutura do Repositório

SensorMovimentoArduino/

├── CodigoFinal/

│ └── codigosensor.c # Código principal do sistema

├── CodigoTeste/

│ └── testelampada.c # Código de teste da lâmpada

├── Apresentação/ # Documentação e apresentações

├── Documentação/ # Documentação do projeto

└── README.md # Este arquivo


## 🎯 Descrição do Projeto

O projeto implementa um sistema de controle de iluminação automatizado para Arduino que:

- **Detecta movimento** usando um sensor PIR
- **Controla uma lâmpada/LED** através de um relé
- **Oferece temporizador inteligente** com 3 opções de tempo (30s, 60s, 300s)
- **Painel de controle** com 6 botões para interação do usuário
- **Display LCD 16x2** para visualização de status e informações
- **Modo automático** que reinicia o temporizador ao detectar movimento
- **Modo manual** para ligar/desligar a luz manualmente

## 🔧 Componentes Utilizados

### Hardware
- **Microcontrolador**: Arduino (Uno ou compatível)
- **Sensor PIR**: Para detectar movimento
- **Relé**: Para controlar a lâmpada/carga
- **Display LCD**: 16x2 caracteres com backlight
- **Botões**: 6 botões de controle (painel)
- **LED**: Para indicação de status
- **Fonte de alimentação**: Conforme especificação do projeto

### Pinos Utilizados

| Componente | Pino |
|-----------|------|
| Relé | 8 |
| Sensor PIR | 7 |
| Backlight LCD | 13 |
| Botão Desligar | A0 |
| Botão Temporizador | A1 |
| Botão Ligar | A2 |
| Botão 30s | A3 |
| Botão 60s | A4 |
| Botão 300s | A5 |
| LCD RS | 12 |
| LCD E | 11 |
| LCD D4 | 10 |
| LCD D5 | 5 |
| LCD D6 | 4 |
| LCD D7 | 3 |
| LCD D8 | 2 |
| LED Embutido | 13 |

## 📁 Descrição dos Arquivos

SensorMovimentoArduino/

│

├── CodigoFinal/

│ └── codigosensor.c # Código principal do sistema

│

├── CodigoTeste/

│ └── testelampada.c # Código de teste da lâmpada

│

├── Apresentação/ # Arquivos de apresentação do projeto

│

├── Documentação/ # Documentação técnica (em desenvolvimento)

│

└── README.md # Este arquivo



## 🔧 Componentes Utilizados

### Hardware
- **Microcontrolador**: Arduino (Uno ou compatível)
- **Sensor**: PIR (Motion Sensor) - Pino 7
- **Atuador**: Relé 5V - Pino 8
- **Display**: LCD 16x2 com backlight - Pinos 12, 11, 10, 5, 4, 3, 2
- **Botões**: 6 botões de controle (Pinos A0-A5)
- **LED**: LED integrado (Pino 13) para feedback visual

### Software
- Arduino IDE
- Biblioteca: `LiquidCrystal`

### Painel de Controle (6 Botões)

#### Linha Superior
- **Botão 1 (Esquerdo)**: Desligar luz
- **Botão 2 (Centro)**: Ativar modo temporizador
- **Botão 3 (Direita)**: Ligar luz manualmente

#### Linha Inferior (Seletor de Tempo)
- **Botão 4 (Esquerdo)**: 30 segundos
- **Botão 5 (Centro)**: 60 segundos
- **Botão 6 (Direita)**: 300 segundos (5 minutos)

## ⚙️ Funcionamento

### Modo Temporizador (Automático)

1. Sistema aguarda detecção de movimento pelo sensor PIR
2. Quando movimento é detectado:
   - Luz acende automaticamente
   - Temporizador retorna ao tempo padrão configurado
3. Quando movimento não é mais detectado:
   - Temporizador começa a contar regressivamente
   - Luz permanece ligada enquanto há tempo restante
   - Luz desliga quando o temporizador chega a zero
4. O tempo pode ser configurado entre 30s, 60s ou 300s

### Modo Manual

- **Botão Ligar**: Aciona a lâmpada permanentemente
- **Botão Desligar**: Desativa a lâmpada
- **Botão Temporizador**: Retorna ao modo automático

### Display LCD

O LCD exibe em tempo real:
- **Linha 1**: Estado atual (Temporizador / Luz: LIGADA / Luz: DESLIGADA)
- **Linha 2**: Tempo restante no modo temporizador ou mensagens de status
- **Indicador M**: Pisca na posição [14,0] quando movimento é detectado

## 📂 Arquivos do Projeto

### `CodigoFinal/codigosensor.c`
**Código principal do sistema**
- Implementação completa do controlador de iluminação
- Lógica de detecção de movimento com debounce
- Controle de temporizador configurável
- Interface LCD com feedback em tempo real
- Controle dos 6 botões
- Debug via Serial Monitor (9600 baud)

### `CodigoTeste/testelampada.c`
**Código de teste simples**
- Testa o funcionamento da lâmpada via relé
- Aciona a lâmpada por 1 segundo
- Exibe mensagem de teste no LCD
- Útil para verificação inicial de funcionamento
- Valida a conexão do relé e LED
