const int analog1 = A1;

#define bomba 11
#define liga 12
#define automatico 13

#define echo 10
#define trig 9

#define ledMod 4

#define buzzer 3


void setup() {
  Serial.begin(9600);

  pinMode(trig, OUTPUT);
  pinMode(bomba, OUTPUT);
  pinMode(echo, INPUT);

  pinMode(ledMod, OUTPUT);
  pinMode(automatico, INPUT);

  Serial.println("Teste HC-SR04 / HCR01 iniciado");
}

void loop() {
  if (digitalRead(automatico) == HIGH) { // automático
    digitalWrite(ledMod, HIGH);
    autonomo();
  } else { 
    if(digitalRead(liga) == HIGH){
      manual();
    }else{
      desliga();
    }
  }
    
  delay(1000);
}

 void desliga(){
  digitalWrite(ledMod, LOW);
  digitalWrite(bomba, LOW);
  delay(1000);
 }

void manual(){
  digitalWrite(ledMod, HIGH);
  delay(300);
  digitalWrite(ledMod, LOW);

  distancia();
  
  digitalWrite(ledMod, HIGH);
}

void autonomo() {
  digitalWrite(ledMod, HIGH);
  Serial.print("Autonomo");
  int luz  = analogRead(analog1);
  
  Serial.print(" | IR: ");
  Serial.println(luz);

  if (luz > 20) {
    alarmeIncendio();
    distancia();

  }else{
    digitalWrite(bomba, LOW);
    }
}

void distancia(){
  long duracao;
  float distancia;

  // Garante pulso limpo
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  // Envia pulso
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  // Lê o tempo do eco
  duracao = pulseIn(echo, HIGH);

  // Calcula distância (cm)
  distancia = duracao * 0.034 / 2;

  Serial.print("Distância: ");
  Serial.print(distancia);
  Serial.println(" cm");

  if (distancia < 40){
    digitalWrite(bomba, HIGH);
    
  }else{
    digitalWrite(bomba, LOW);
  }
  delay(1000);
}

void alarmeIncendio() {
  tone(buzzer, 2500);
  delay(200);
  noTone(buzzer);
  delay(100);

  tone(buzzer, 2500);
  delay(200);
  noTone(buzzer);
  delay(100);

  tone(buzzer, 2500);
  delay(300);
  noTone(buzzer);
  delay(150);
}

















