// Configurações
const int ledRed = A1;
const int ledGreen = A2;
const int ledBlue = A0;
const int resistor = A3;

// Variáveis
int red = 255;
int green = 0;
int blue = 0;

void setup() {
  // Configura os pinos como saída
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledBlue, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Lê o valor do resistor
  int res = analogRead(resistor);
  Serial.println(res);

  // Verifica a faixa do resistor
  if (res < 170) {
    // Faixa 1 
    red = 0;
    green = 255;
    blue = 255;
  } else if (res < 370) {
    // Faixa 2
    red = 255;
    green = 0;
    blue = 255;
  } else if (res < 540) {
    // Faixa 3
    red = 255;
    green = 0;
    blue = 0;
  } else if (res < 710) {
    // Faixa 4
    red = 255;
    green = 255;
    blue = 0;
  } else if (res < 880) {
    // Faixa 5
    red = 0;
    green = 255;
    blue = 0;
  } else {
    // Faixa 6
    red = 0;
    green = 0;
    blue = 255;
  }

  // Escreve os valores no LED
  analogWrite(ledRed, red);
  analogWrite(ledGreen, green);
  analogWrite(ledBlue, blue);

  // Aguarda 100 milissegundos
  delay(100);
}
