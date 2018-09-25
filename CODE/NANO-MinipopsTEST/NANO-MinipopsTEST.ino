int state;

void setup() {

  Serial.begin(9600);

  //JUMPERS
  pinMode(2,INPUT_PULLUP);
  pinMode(3,INPUT_PULLUP);
  pinMode(4,INPUT_PULLUP);
  pinMode(5,INPUT_PULLUP);
  pinMode(6,INPUT_PULLUP);
  pinMode(7,INPUT_PULLUP);
  pinMode(8,INPUT_PULLUP);
  pinMode(9,INPUT_PULLUP);

  //SWITCH
  pinMode(10,INPUT_PULLUP);

  //ANALOG INPUTS
  pinMode(A4,INPUT);
  pinMode(A5,INPUT);

  //LED
  pinMode(13,OUTPUT);
}

void blinkLED(){
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);                       // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(500);  
}

void toggleTone(){
  if (state){
  tone(11,50);
  } else { 
  tone(11,100);}
  state = !state;
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(10) == 1){
    Serial.println("System ON");
    Serial.println("");
    
    blinkLED();
    
    toggleTone();
    
    Serial.println("DIGITAL READINGS");
    Serial.print("SW1: ");
    Serial.print(digitalRead(9));
    Serial.print(" SW2: ");
    Serial.print(digitalRead(8));
    Serial.print(" SW3: ");
    Serial.print(digitalRead(7));
    Serial.print(" SW4: ");
    Serial.print(digitalRead(6));
    Serial.print(" SW5: ");
    Serial.print(digitalRead(5));
    Serial.print(" SW6: ");
    Serial.print(digitalRead(4));
    Serial.print(" SW7: ");
    Serial.print(digitalRead(3));
    Serial.print(" SW8: ");
    Serial.println(digitalRead(2));

    Serial.println("ANALOG READINGS");
    Serial.print("A4: ");
    Serial.print(analogRead(A4));
    Serial.print(" A5: ");
    Serial.println(analogRead(A5));
    Serial.println("");

    tone(11, 110);
  }
  else {  Serial.println("System OFF");
  delay(1000);
  }

}


