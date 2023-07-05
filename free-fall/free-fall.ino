const int pinBotao = 7;  // Pino do botão

bool botaoPressionado = false;  // Variável para controlar o estado do botão

int sensor = A0; // Pino do sensor

float height = 0.4091; // Altura entre a esfera e o sensor

float bobina = 3; // Porta para alimentar a bobina

//Váriáveis para guardar o valor do tempo de inicio e fim
unsigned long startTime;

unsigned long stopTime;


void setup() {

    Serial.begin(9600);  // Inicializa a comunicação serial para debug (opcional)
    
    pinMode (pinBotao, INPUT); // Define a porta D7 como entrada, para ler o botão ligado a porta D7

    pinMode (sensor, INPUT); // Define a porta A0 como entrada para ler o fototransistor/sensor

    pinMode (bobina, OUTPUT); // Define a porta D3 como saída de tensão

    Serial.println("Pronto para medir o tempo de queda");

    Serial.println(" ");

}

void loop() {
  // Lê o estado atual do botão
  bool estadoBotao = digitalRead(pinBotao);

  digitalWrite(bobina, HIGH); // Faz com que a porta D3 funcione com 5V para ligar a bobina

  // Verifica se o botão foi pressionado
  if (estadoBotao == HIGH && !botaoPressionado) {// Executa o código que você deseja quando o botão é pressionado

    Serial.println("Botão pressionado!");

    digitalWrite (bobina, LOW);

    startTime = millis();

    Serial.println(" Inicio da medida ---");

    Serial.println("Esfera caindo...Contando tempo...");

    botaoPressionado = true;  // Atualiza o estado do botão para evitar repetições
  
  }

  // Verifica se o botão foi solto
  if (estadoBotao == LOW) {
    
    botaoPressionado = false;  // Atualiza o estado do botão para permitir uma nova leitura
 
  }
  
  if (analogRead(sensor) > 250 ){

    stopTime = millis();

    float intervalo = stopTime - startTime;

    float tempo = (intervalo/1000);

    float gravity = (2 * height) / (tempo*tempo);

 //   Serial.println("tempo(ms):");

 //   Serial.println(intervalo);

    Serial.println("tempo(s):");
    Serial.println(tempo, 3);
    
    Serial.println("Aceleracao da gravidade = ");
    Serial.print(gravity);

    Serial.println(" metros por segundo ao quadrado (m /s²)|Aguarde 5 segundos...");
    delay(5000);
    Serial.println("Pronto para proxima medida"); 
    }
}
