#define pinBotao 2

int door[8] = {10,9,6,7,8,11,12,5};
int numero = 10;
boolean botaoAtu = false;
boolean botaoAnt = false;
byte displayConfig [11][8] = {{1,1,1,1,1,1,0,0}, 
                              {0,1,1,0,0,0,0,0},
                              {1,1,0,1,1,0,1,0},
                              {1,1,1,1,0,0,1,0},
                              {0,1,1,0,0,1,1,0},
                              {1,0,1,1,0,1,1,0},
                              {1,0,1,1,1,1,1,0},
                              {1,1,1,0,0,0,0,0},
                              {1,1,1,1,1,1,1,0},
                              {1,1,1,1,0,1,1,1},
                              {0,0,0,0,0,0,0,0}};

void setup() {
  // put your setup code here, to run once:
  pinMode(pinBotao, INPUT);

  for (int nP = 0; nP <= 7; nP++){
    pinMode(door[nP], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  botaoAtu = digitalRead(pinBotao);

  if(botaoAtu && !botaoAnt){
    numero++;

    if (numero > 9){
      numero = 0;
    }
  }
  botaoAnt = botaoAtu;

  for(int nD = 0; nD <= 7; nD++){
    digitalWrite(door[nD], displayConfig[numero][nD]);  
  }

}
