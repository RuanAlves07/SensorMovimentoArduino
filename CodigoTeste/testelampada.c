#include <LiquidCrystal.h>

// Configuração do LCD
LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);

// Pinos
int rele = 8;
int backLight = 13;

void setup() {
  pinMode(rele, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(backLight, HIGH);

  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Teste Lampada");
  lcd.setCursor(0, 1);
  lcd.print("1s...         ");

  // Liga a lâmpada por 1 segundo
  digitalWrite(rele, HIGH);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);

  // Desliga a lâmpada
  digitalWrite(rele, LOW);
  digitalWrite(LED_BUILTIN, LOW);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Teste Finalizado");
  lcd.setCursor(0, 1);
  lcd.print("Lampada OK      ");

  Serial.begin(9600);
}

void loop() {
  delay(1000);
}
