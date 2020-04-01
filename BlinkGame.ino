bool go = true;
int theLED = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //for bug killin time
  /*
   * for(int i=3; i<=11; i++){
   *    pinMode(i, OUTPUT);
   * }
   */
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

  pinMode(2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), smash, LOW);
}

void smash(){
  go = false;
}

void loop() {
  // put your main code here, to run repeatedly:
  if(go){
    for(int i=3; i<=11; i++){
      if(go){
        theLED = i;
        digitalWrite(i, HIGH);
        delay(100);
        digitalWrite(i, LOW);
      }
      else{
        break;
      }
    }//end of sweepUp
  
    for(int i=11; i>=3; i--){
      if(go){
        theLED = i;
        digitalWrite(i, HIGH);
        delay(100);
        digitalWrite(i,LOW);
      }
      else{
        break;
      }
    }//end of sweepDown
  }//end of if go for loop section
  else{
    digitalWrite(theLED, HIGH);
    delay(100);
    digitalWrite(theLED, LOW);
    delay(100);
  }//end of else if go

}//end of loop function
