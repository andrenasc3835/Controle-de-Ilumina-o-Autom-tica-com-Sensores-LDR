#include <LiquidCrystal.h> // Inclui a biblioteca para o LCD

// Definição dos pinos do LCD
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); // Cria um objeto LCD

// Definição dos pinos do sensor LDR e do relé
const int sensorLDR1 = A0; // Pino analógico para o sensor LDR 1
const int sensorLDR2 = A1; // Pino analógico para o sensor LDR 2
const int relePino = 10;   // Pino digital para o relé

// Variáveis
int valorLDR1; // Variável para armazenar o valor do sensor LDR 1
int valorLDR2; // Variável para armazenar o valor do sensor LDR 2
int mediaSensores; // Variável para armazenar a média dos valores dos sensores

void setup() {
  // Inicialização do LCD
  lcd.begin(16, 2); // Inicializa o LCD com 16 colunas e 2 linhas

  // Configuração dos pinos
  pinMode(sensorLDR1, INPUT); // Configura o pino do sensor LDR 1 como entrada
  pinMode(sensorLDR2, INPUT); // Configura o pino do sensor LDR 2 como entrada
  pinMode(relePino, OUTPUT);  // Configura o pino do relé como saída

  // Exibe a mensagem no LCD
  lcd.clear();
  lcd.print("Bem-vindo a");
  lcd.setCursor(0, 1);
  lcd.print("Cidade do Futuro");
  delay(2000); // Aguarda 2 segundos
  lcd.clear(); // Limpa a tela após 2 segundos
}

void loop() {
  valorLDR1 = analogRead(sensorLDR1); // Lê o valor do sensor LDR 1
  valorLDR2 = analogRead(sensorLDR2); // Lê o valor do sensor LDR 2

  // Calcula a média dos valores dos sensores
  mediaSensores = (valorLDR1 + valorLDR2) / 2;

  // Define um limite para acender ou apagar os LEDs (pode ser ajustado conforme necessário)
  int limite = 500;

  // Verifica se a média dos sensores está acima do limite para apagar os LEDs
  if (mediaSensores > limite) {
    digitalWrite(relePino, LOW); // Desliga o relé, apagando os LEDs
    lcd.setCursor(0, 0);
    lcd.print("Luz apagada");
  } else {
    digitalWrite(relePino, HIGH); // Liga o relé, acendendo os LEDs
    lcd.setCursor(0, 0);
    lcd.print("Luz acesa  ");
  }
  
  // Exibe os valores dos sensores no LCD
  lcd.setCursor(0, 1);
  lcd.print("LDR1: ");
  lcd.print(valorLDR1);
  lcd.print(" LDR2: ");
  lcd.print(valorLDR2);

  delay(100); // Pequeno atraso para estabilidade
}
