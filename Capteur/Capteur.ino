
void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
}

void loop() {
  Serial.print(detect(0, millis(), 0));
  Serial.print("\n");
}

int detect(float pulses, float ms, float base){
  delay(100);
  if (analogRead(0) - base > 100){
    pulses++;
    delay(250);
  }
  
  
  if(pulses > 4){
    return (pulses*60)/((millis()-ms)/1000);
  }
  
  return detect(pulses, ms, analogRead(0));
}
