//ONLY BLACK 

int rightmotor1=12;
int leftmotor1=10;
int rightmotor2=13;
int leftmotor2=11;

int SLeft,SCent,SRight;

int sensorleft=4;
int sensorcenter=3;
int sensorright=2;

void setup() 
{
 pinMode(rightmotor1,OUTPUT);
 pinMode(leftmotor1,OUTPUT);
 pinMode(rightmotor2,OUTPUT);
 pinMode(leftmotor2,OUTPUT);

 pinMode(sensorleft,INPUT);
 pinMode(sensorcenter,INPUT);
 pinMode(sensorright,INPUT);
}
void loop()
{
  SLeft = digitalRead(sensorleft);
  SCent = digitalRead(sensorcenter);
  SRight = digitalRead(sensorright);
  
  if(SLeft == 0 && SCent == 0 && SRight == 1)   //MOVE RIGHT
  {
    digitalWrite(rightmotor1,LOW);
    digitalWrite(rightmotor2,LOW);
    digitalWrite(leftmotor1,HIGH);
    digitalWrite(leftmotor2,LOW);
  }
  if(SLeft==0 && SCent==1 && SRight==0)         //move forward
  {
    digitalWrite(rightmotor1,HIGH);
    digitalWrite(rightmotor2,LOW);
    digitalWrite(leftmotor1,HIGH);
    digitalWrite(leftmotor2,LOW);
  }
  
  if(SLeft == 0 && SCent == 1 && SRight == 1)   //MOVE RIGHT
  {
    do{
    digitalWrite(rightmotor1,LOW);
    digitalWrite(rightmotor2,LOW);
    digitalWrite(leftmotor1,HIGH);
    digitalWrite(leftmotor2,LOW);
    SLeft = digitalRead(sensorleft);
    }while(SLeft == 0);
  }
  if(SLeft==1 && SCent==0 && SRight==0)         //MOVE LEFT 
  {
      digitalWrite(rightmotor1,HIGH);
      digitalWrite(rightmotor2,LOW);
      digitalWrite(leftmotor1,LOW);
      digitalWrite(leftmotor2,LOW); 
  }

  //if(SLeft==1 && SCent==0 && SRight==1);
  
  if(SLeft==1 && SCent==1 && SRight==0)         //MOVE LEFT
  { 
    do{
    digitalWrite(rightmotor1,HIGH);
    digitalWrite(rightmotor2,LOW);
    digitalWrite(leftmotor1,LOW);
    digitalWrite(leftmotor2,LOW);
    SRight = digitalRead(sensorright);
    }while(SRight == 0 );
  }
  if(SLeft==1 && SCent==1 && SRight==1)         //MOVE LEFT DEFAULT
  {
    digitalWrite(rightmotor1,HIGH);
    digitalWrite(rightmotor2,LOW);
    digitalWrite(leftmotor1,LOW);
    digitalWrite(leftmotor2,LOW);
  }
  delay(5);
}
