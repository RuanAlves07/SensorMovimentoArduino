#include <LiquidCrystal.h>

// Configuração do LCD
LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);

// Pinos
int rele = 8;
int PIR = 7;
int backLight = 13;

// Botões (usando pinos analógicos como digitais)
// Botões do painel que será usado como central para realizar os ajustes

const int BTN_DESLIGAR = A0;     // Botão 1, Esquerdo superior
const int BTN_TEMPORIZADOR = A1; // Botão 2, Centro superior
const int BTN_LIGAR = A2;        // Botão 3, Direita superior
const int BTN_30S = A3;          // Botão 4, Esquerdo inferior
const int BTN_60S = A4;          // Botão 5, Centro inferior
const int BTN_300S = A5;         // Botão 6, Direita inferior

// Variáveis de controle
unsigned long lastUpdate = 0;
int defaultTime = 30;
int remainingTime = 30;
bool motionDetected = false;
bool timerMode = true;

// Debounce do PIR
unsigned long lastPIRChange = 0;
const unsigned long DEBOUNCE_DELAY = 500;
int lastPIRState = LOW;

void setup() {
  pinMode(rele, OUTPUT);
  pinMode(PIR, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(backLight, HIGH);

  // Configuração dos botões com pull-up interno
  
  pinMode(BTN_LIGAR, INPUT_PULLUP);
  pinMode(BTN_TEMPORIZADOR, INPUT_PULLUP);
  pinMode(BTN_30S, INPUT_PULLUP);
  pinMode(BTN_60S, INPUT_PULLUP);
  pinMode(BTN_300S, INPUT_PULLUP);
  pinMode(BTN_DESLIGAR, INPUT_PULLUP); 

  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temporizador");
  lcd.setCursor(0, 1);
  lcd.print("30s");

  Serial.begin(9600);
}