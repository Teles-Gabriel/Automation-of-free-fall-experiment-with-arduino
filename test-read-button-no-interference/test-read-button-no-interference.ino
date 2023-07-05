const int pinBotao = 2;  // Pino do botão
bool botaoPressionado = false;  // Variável para controlar o estado do botão

void setup() {
  pinMode(pinBotao, INPUT);  // Configura o pino do botão como entrada
  Serial.begin(9600);  // Inicializa a comunicação serial para debug (opcional)
}

void loop() {
  // Lê o estado atual do botão
  bool estadoBotao = digitalRead(pinBotao);

  // Verifica se o botão foi pressionado
  if (estadoBotao == HIGH && !botaoPressionado) { // Executa o código que você deseja quando o botão é pressionado
    Serial.println("Botão pressionado!");

    botaoPressionado = true;  // Atualiza o estado do botão para evitar repetições
  }

  // Verifica se o botão foi solto
  if (estadoBotao == LOW) {
    botaoPressionado = false;  // Atualiza o estado do botão para permitir uma nova leitura
  }
}
