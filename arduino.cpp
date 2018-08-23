//Sharon Liu, Liam David, Sidharth Rampally
//include <Servo.h>

int REDLED=7;
int GREENLED=8;
int BUTTONL=3;
int BUTTONR=4;
Servo SERVOL;
Servo SERVOR;

void setup() {
  pinMode(REDLED,OUTPUT);
  pinMode(GREENLED,OUTPUT);
  
  pinMode(BUTTONL,INPUT);
  pinMode(BUTTONR,INPUT);
  
  SERVOL.attach(12);
  SERVOR.attach(13);
  }

void loop() {
  int TIME=0;
  
  SERVOL.write(240);
  SERVOR.write(240);
    
  while(digitalRead(BUTTONL)==LOW&&digitalRead(BUTTONR)==LOW&&TIME<=10000){
    delay(1);
    TIME++;
  }
  delay(200);
  if(digitalRead(BUTTONL)==HIGH&&digitalRead(BUTTONR)==LOW&&TIME<=10000){
    SERVOL.write(128);
    SERVOR.write(64);
    delay(2000);
    
    for(int x=0;x<5;x++){
      digitalWrite(REDLED,HIGH);
      delay(200);
      digitalWrite(REDLED,LOW);
      delay(200);
    }
  }

  else if(digitalRead(BUTTONL)==LOW&&digitalRead(BUTTONR)==HIGH&&TIME<=10000){
    SERVOL.write(64);
    SERVOR.write(128);
    delay(2000);
    
    for(int x=0;x<4;x++){
      digitalWrite(GREENLED,HIGH);
      delay(200);
      digitalWrite(GREENLED,LOW);
      delay(200);
    }
  }

  else if(digitalRead(BUTTONL)==HIGH&&digitalRead(BUTTONR)==HIGH&&TIME<=10000){
    SERVOL.write(128);
    SERVOR.write(128);
        
    for(int x=0;x<8;x++){
      digitalWrite(REDLED,HIGH);
      digitalWrite(GREENLED,HIGH);
      delay(200);
      digitalWrite(REDLED,LOW);
      digitalWrite(GREENLED,LOW);
      delay(200);
    }

    SERVOL.write(255);
    SERVOR.write(0);
    delay(1000);
    SERVOR.write(255);
  }
    SERVOL.detach();
    SERVOR.detach();
    while(true); 
}

