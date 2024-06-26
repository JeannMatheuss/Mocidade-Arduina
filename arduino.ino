int greenLED = 8;  // Define o pino digital 8 como saída para o LED verde
int yellowLED = 7; // Define o pino digital 7 como saída para o LED amarelo
int redLED = 4;    // Define o pino digital 4 como saída para o LED vermelho
int BUZZER = 3;    // Define o pino digital 3 como saída para o buzzer
int LDR = A0;      // Define o pino analógico A0 como entrada para o LDR (Light Dependent Resistor)
 
int valorLDR;       // Variável para armazenar o valor lido do LDR
int luminosidadeLuz;
 
void setup() {
  Serial.begin(9600); // Inicia a comunicação serial com uma taxa de 9600 bauds
  pinMode(greenLED, OUTPUT);  // Configura o pino do LED verde como saída
  pinMode(yellowLED, OUTPUT); // Configura o pino do LED amarelo como saída
  pinMode(redLED, OUTPUT);    // Configura o pino do LED vermelho como saída
  pinMode(BUZZER, OUTPUT);    // Configura o pino do buzzer como saída
  pinMode(LDR, INPUT);        // Configura o pino do LDR como entrada
}
 
void loop() {
  valorLDR = analogRead(LDR); // Lê o valor analógico do LDR e armazena em 'valorLDR'
  luminosidadeLuz = map(valorLDR, 700, 974, 0, 100); // Mapeia o valor lido do LDR para o intervalo de 0 a 100 (luminosidade)
  Serial.println(valorLDR);
  Serial.print("Luminosidade da Luz: "); // Imprime a string na porta serial
  Serial.println(luminosidadeLuz);        // Imprime o valor da luminosidade da luz na porta serial
  if (luminosidadeLuz <= 20) { // Se a luminosidade for menor ou igual a 20
    digitalWrite(greenLED, HIGH); // Acende o LED verde
    digitalWrite(yellowLED, LOW); // Apaga o LED amarelo
    digitalWrite(redLED, LOW);    // Apaga o LED vermelho
    digitalWrite(BUZZER, LOW);    // Desliga o buzzer
  } else if (luminosidadeLuz > 20 && luminosidadeLuz <= 50) { // Se a luminosidade estiver entre 20 e 50
    digitalWrite(greenLED, LOW);   // Apaga o LED verde
    digitalWrite(yellowLED, HIGH); // Acende o LED amarelo
    digitalWrite(redLED, LOW);     // Apaga o LED vermelho
    digitalWrite(BUZZER, HIGH);    // Liga o buzzer
    tone(BUZZER, 2000, 3000);      // Produz um tom no buzzer com frequência de 2000Hz por 3000ms
    delay(5000);                    // Aguarda 5 segundos
  } else { // Se a luminosidade for maior que 50
    digitalWrite(greenLED, LOW);   // Apaga o LED verde
    digitalWrite(yellowLED, LOW);  // Apaga o LED amarelo
    digitalWrite(redLED, HIGH);    // Acende o LED vermelho
    digitalWrite(BUZZER, HIGH);    // Liga o buzzer
    tone(BUZZER, 2000, 1000);      // Produz um tom no buzzer com frequência de 2000Hz por 1000ms
  }
  delay(3000); // Aguarda 3 segundos antes de repetir o loop
}