const int LDR = A0;             // Pino analógico que o sensor está conectado
const int luz = 11;             // Pino Referente ao led ou rele
int valorsensor ;               // valor que sera armazenado o valor do LDR

int ref;

void setup() {
  pinMode(luz, OUTPUT);         // Coloca variavel luz é um sinal de saidad
  pinMode(LDR, INPUT);          // Coloca a variavel LDR como entrada
  Serial.begin(9600);           // inicializa a comunicação serial com a taxa de 9600 bps
}

void loop() {
  valorsensor = analogRead(LDR); // Faz a leitura do pino analógico LDR e armazena o valor na variavel valorsensor
  Serial.print("LDR : " );      // Mostra o valor no monitor serial
  Serial.println(valorsensor);
  
  ref = map(valorsensor, 344, 500, 255, 0);       /*observe, os valores mapeados devem ser utilizados de acordo com o que se le 
  no LDR. Esse valor varia de caso para caso.*/
  ref = constrain(ref, 0, 255);
  analogWrite(luz,ref);
  Serial.print("REF : " );      // Mostra o valor no monitor serial
  Serial.println(ref);
  delay(100);

}