#define dir 9
#define pul 8
#define buttonDown 12
#define ena 13
#define buttonUP 3
int x=900; // LIMIT step delay

void setup() {     
  Serial.begin(9600);//Start serial protocol           
  pinMode(dir, OUTPUT);      
  pinMode(pul, OUTPUT); 
  digitalWrite(dir,LOW);
  digitalWrite(pul, LOW);
}
void loop() {
  for(int j=0; j<1500; j++) {
  int buttonDownCase=digitalRead(buttonDown);//read button down
  int buttonUPCase=digitalRead(buttonUP);//read button up
  for(int i=0; i<150; i++) {//  for(int i=0; i<6; i++) {
  if(buttonDownCase==0){//increase analog  the speed
  digitalWrite(pul,HIGH);
  delayMicroseconds(x);        
  digitalWrite(pul, LOW); 
 // delayMicroseconds(x);
  }
  }
  if(x>100) x-=2;
  if  (buttonDownCase==1){//change direction motor
     digitalWrite(dir,HIGH);
     digitalWrite(pul,HIGH);
     delayMicroseconds(x);        
     digitalWrite(pul, LOW); 
   
  }
   if(buttonUPCase==1){
    digitalWrite(ena,HIGH);//switch off motor 
  }
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
