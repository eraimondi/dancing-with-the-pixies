int tiempo;
int distancia;
int porcentaje;
const long interval = 5;
const long interval2 = 10;
unsigned long previousMillis = 0;
unsigned long previousMillis2 = 0;
void setup() {
  Serial.begin(9600);
  pinMode(9,OUTPUT);
  pinMode(8,INPUT);
  pinMode(13,OUTPUT);
}

void loop() {
  unsigned long currentMicros = micros();
  digitalWrite(13,HIGH);
  if(currentMicros - previousMillis >= interval){
  digitalWrite(9,LOW);
  previousMillis = currentMicros;
  }
  if(currentMicros - previousMillis2 >= interval2){
  digitalWrite(9,HIGH);
  previousMillis2 = currentMicros;
  }
  tiempo=pulseIn(8,HIGH);
  distancia = int(0.017*tiempo);
  porcentaje = (100-distancia);
  if( porcentaje <=3 && porcentaje >=(-16) ) porcentaje = 0;
  if( porcentaje > 100) porcentaje = 100;
  analogWrite(3,porcentaje*2.55);
  Serial.println(porcentaje);
  erial.println("Distancia");
  Serial.println(distancia);
  Serial.println(" cm");
  digitalWrite(13,LOW);

}
