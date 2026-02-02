
const int analog = A0;
const int analog1 = A1;
int ValorLido= 0;
double Volts = 0;
double tempC = 0;


#define liga 12
#define automatico 10
#define desliga 11
#define ledMod 4

#define echo 7
#define trig 6

#define ledFogo 2

#define buzzer 9 

void setup() {
  Serial.begin(9600);

  pinMode(liga, INPUT);
  pinMode(automatico, INPUT);
  pinMode(desliga, INPUT);
  
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  
  pinMode(ledFogo, OUTPUT);
  pinMode(ledMod, OUTPUT);

  // digitalWrite(desliga, HIGH);
  // digitalWrite(liga, HIGH);
  // digitalWrite(automatico, HIGH);

}

void loop() {
 
  if(digitalRead(automatico) == HIGH){ // clicado
    	autonomo();// automatico
  } 
  else{
    if(digitalRead(automatico) == LOW){ // não clicado
    	manuseado(); // manual
  }
  

  
  }};


int tipo (){

  int valor = 0;
  if(digitalRead(desliga) == HIGH){
    valor = 2; 
  }else { 
    if(digitalRead(liga) == HIGH){
    valor = 1; 
  }
  }
  return valor;

};
  
  void acordado(){
    
    float dist = distancia(); //medindo agua
    
    Serial.print("  distancia: ");
  	Serial.println(dist);
    
    if (dist > 0 && dist < 200){ // tem agua
    	digitalWrite(ledFogo, HIGH);
      	//alarmeIncendio();
    }else{
    	digitalWrite(ledFogo, LOW);
    }
  
   
    
  };


  void dormindo(){
    Serial.print("Dormindo");

    digitalWrite(ledFogo, LOW);
    
    //Desliga tudo e se apaga
    
  };
  void manuseado(){
    Serial.print("Manuseio");
    digitalWrite(ledMod, HIGH);
    
    int valor = tipo();

    if(valor == 1){
        acordado();
    }
   	if(valor == 2){
        dormindo();
    }
    delay(500);
    digitalWrite(ledMod, LOW);
    delay(500);
    digitalWrite(ledMod, HIGH);
    delay(500);
    digitalWrite(ledMod, LOW);
    delay(500);
    digitalWrite(ledMod, HIGH);
    delay(500);
    digitalWrite(ledMod, LOW);
    
  };
  void autonomo(){
    digitalWrite(ledMod, HIGH);
    Serial.print("Autonomo");
    
    int temp = analogRead(analog);
  int luz   = analogRead(analog1);

  float voltage = temp * (5.0 / 1023.0);
  float tempC = (voltage - 0.5) * 100;

  Serial.print("Temp: ");
  Serial.print(tempC);
  Serial.print(" | IR: ");
  Serial.println(luz);

  if (tempC > 50 && luz > 80) { //erro tempC > 50 && luz > 80
    alarmeIncendio();
   	float dist = distancia(); //medindo agua
    
    Serial.print("  distancia: ");
  	Serial.println(dist);
    
    if (dist > 0 && dist < 200){ // tem agua
    	digitalWrite(ledFogo, HIGH);
      	alarmeIncendio();
    }else{
    	digitalWrite(ledFogo, LOW);
    }
  } else {
	digitalWrite(ledFogo, LOW);
  }

  delay(2500);
  };

  


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

  //for (int i = 0; i < 3; i++) {
    //tone(buzzer, 1800);
    //delay(120);
    ///noTone(buzzer);
    ///delay(80);
 // }

};

float distancia() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  long duracao = pulseIn(echo, HIGH, 30000); // timeout 30ms

  if (duracao == 0) return -1; // erro / fora de alcance

  float cm = duracao * 0.0343 / 2.0;
  return cm;
};
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
