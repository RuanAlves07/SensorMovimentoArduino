  #include <LiquidCrystal.h>

  // Configuração do LCD
  LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);

  // Pinos
  int rele = 8;
  int PIR = 7;
  int backLight = 13;
  int piezoPin = 6; // 

  // Botões (usando pinos analógicos como digitais)
  const int BTN_LIGAR = A2;
  const int BTN_TEMPORIZADOR = A1;
  const int BTN_30S = A3;
  const int BTN_60S = A4;
  const int BTN_300S = A5;
  const int BTN_DESLIGAR = A0;

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

  // Função para tocar um bip curto
  void bip() {
    tone(piezoPin, 400, 200); 
    delay(210); 
  }

 // inicio da estrutura do código
  void setup() {
    pinMode(rele, OUTPUT);
    pinMode(PIR, INPUT);
    pinMode(backLight, OUTPUT); 
    digitalWrite(backLight, HIGH);

    // Configuração dos botões com pull-up interno
    pinMode(BTN_LIGAR, INPUT_PULLUP);
    pinMode(BTN_TEMPORIZADOR, INPUT_PULLUP);
    pinMode(BTN_30S, INPUT_PULLUP);
    pinMode(BTN_60S, INPUT_PULLUP);
    pinMode(BTN_300S, INPUT_PULLUP);
    pinMode(BTN_DESLIGAR, INPUT_PULLUP);

    // Configuração do piezo
    pinMode(piezoPin, OUTPUT);

    lcd.begin(16, 2);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Temporizador");
    lcd.setCursor(0, 1);
    lcd.print("30s");

    // Serial.begin(9600);
  }

  void loop() {
    // Leitura do PIR 
    int currentPIRState = digitalRead(PIR);
    if (millis() - lastPIRChange >= DEBOUNCE_DELAY) {
      if (currentPIRState != lastPIRState) {
        lastPIRState = currentPIRState;
        lastPIRChange = millis();
      }
    }
    motionDetected = (lastPIRState == HIGH);

    // Leitura dos botões 
    bool btnLigar = digitalRead(BTN_LIGAR) == LOW;
    bool btnTemp = digitalRead(BTN_TEMPORIZADOR) == LOW;
    bool btn30s = digitalRead(BTN_30S) == LOW;
    bool btn60s = digitalRead(BTN_60S) == LOW;
    bool btn300s = digitalRead(BTN_300S) == LOW;
    bool btnDesligar = digitalRead(BTN_DESLIGAR) == LOW;

    // Verifica se algum botão foi pressionado e toca o bip 
    if (btnLigar || btnTemp || btn30s || btn60s || btn300s || btnDesligar) {
      bip(); // Toca o som
    }

    //  Botões de tempo 
    if (btn30s) {
      defaultTime = 30;
      if (timerMode) remainingTime = 30;
      lcd.setCursor(0, 1);
      lcd.print("Tempo: 30s      ");
    }
    if (btn60s) {
      defaultTime = 60;
      if (timerMode) remainingTime = 60;
      lcd.setCursor(0, 1);
      lcd.print("Tempo: 60s      ");
    }
    if (btn300s) {
      defaultTime = 300;
      if (timerMode) remainingTime = 300;
      lcd.setCursor(0, 1);
      lcd.print("Tempo: 300s     ");
    }

    // Botões de controle 
    if (btnLigar) {
      timerMode = false;
      digitalWrite(rele, HIGH);
      lcd.setCursor(0, 0);
      lcd.print("Luz: LIGADA    ");  // 16 caracteres para preencher
      lcd.setCursor(0, 1);
      lcd.print("                "); // Limpa a linha 1
    }
    if (btnTemp) {
      timerMode = true;
      remainingTime = defaultTime;
      lcd.setCursor(0, 0);
      lcd.print("Temporizador   ");
      lcd.setCursor(0, 1);
      lcd.print("Tempo: ");
      lcd.print(remainingTime);
      lcd.print("s             "); // completa com espaços
    }
    if (btnDesligar) {
      timerMode = false;
      digitalWrite(rele, LOW);
      lcd.setCursor(0, 0);
      lcd.print("Luz: DESLIGADA ");   // 16 caracteres
      lcd.setCursor(0, 1);
      lcd.print("                "); // Limpa a linha 1
    }
    // Modo Temporizador 
    if (timerMode) {
      if (millis() - lastUpdate >= 1000) {
        lastUpdate = millis();

        if (motionDetected) {
          remainingTime = defaultTime;
        } else {
          if (remainingTime > 0) {
            remainingTime--;
          }
        }

        lcd.setCursor(0, 1);
        lcd.print("                ");
        lcd.setCursor(0, 1);
        lcd.print("Tempo: ");
        lcd.print(remainingTime);
        lcd.print("s");

        digitalWrite(rele, (remainingTime > 0) ? HIGH : LOW);

        lcd.setCursor(14, 0);
        lcd.print(motionDetected ? "M" : " ");
      }
    }

    digitalWrite(LED_BUILTIN, digitalRead(rele));
    delay(50);
  }