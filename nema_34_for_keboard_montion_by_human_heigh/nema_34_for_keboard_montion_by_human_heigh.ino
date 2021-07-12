#define dir 9
#define pul 8
#define buttonDown 12
#define ena 13
#define buttonUP 3
#define echoPin 4//sesi gonderen
#define trigPin 3//sesi qebul eden
long vaxt; //gedib gelme vaxti
int distance;//cism mesafesi
int x=200; // LIMIT step delay//3200//4000//

void setup() {     
  Serial.begin(9600);//Start serial protocol    
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);       
  pinMode(dir, OUTPUT);      
  pinMode(pul, OUTPUT); 
  digitalWrite(dir,HIGH);
  digitalWrite(pul, LOW);
}
void loop() {
  digitalWrite(trigPin,LOW);//default position
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);//send sound
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  vaxt=pulseIn(echoPin,HIGH);//accept sound
  distance=(vaxt*0.034/2);//calculate distance by time and speed "the sound speed is default for all condition" 
  for(int j=0; j<1500; j++) {
  int buttonDownCase=digitalRead(buttonDown);//read button down
  int buttonUPCase=digitalRead(buttonUP);//read button up
  for(int i=0; i<1000; i++) {//  for(int i=0; i<6; i++) {
  if(buttonDownCase==0){//increase analog  the speed
  digitalWrite(pul,HIGH);
  delayMicroseconds(x);        
  digitalWrite(pul, LOW); 
 // delayMicroseconds(x);
  }
  }
  if(x>200) x--;//for increase speed (decrease pul time)
  if  (buttonDownCase==1){//change direction motor 
     digitalWrite(dir,HIGH);
     digitalWrite(pul,HIGH);
     delayMicroseconds(x);        
     digitalWrite(pul, LOW); 
   
  }
   if(buttonUPCase==1){//stop in start position 
    digitalWrite(ena,HIGH);//switch off motor 
  }
    /*Serial.print("Distance : ");
    Serial.print(distance);
    Serial.println(" cm ");
    delay(1000);*/
    /*Serial.print("buttonDown Case:");
    Serial.print(buttonDownCase);
    Serial.println(" ");
    delay(2000);//serial delay second

    Serial.print("buttonUp Case:");
    Serial.print(buttonUPCase);
    Serial.println(" ");
    delay(2000);*/
  
} 
}
