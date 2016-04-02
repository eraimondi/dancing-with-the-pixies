int tiempo;
int distancia;
void setup() {
  Serial.begin(9600);
  pinMode(9,OUTPUT);
  pinMode(8,INPUT);
}

void loop() {
  digitalWrite(9,LOW);
  delayMicroseconds(5);
  digitalWrite(9,HIGH);
  delayMicroseconds(10);
  tiempo=pulseIn(8,HIGH);
  distancia = int(0.017*tiempo);
  analogWrite(3,distancia);
  Serial.println("Distancia");
  Serial.println(distancia);
  Serial.println(" cm");

}
