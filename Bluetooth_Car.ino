
const int IN1 = 9;  //Change direction
const int IN2 = 8;  //Change direction
const int IN3 = 7;  //Motors on and off
const int IN4 = 6;

const int EN = 10;                                                                                                                                                                                                                                                                                                                     //const int lights = 13;
//const int horn = 8;

int pwm = 75;

char command = 'E'; 

void setup() {
  
 Serial.begin(9600);    // Initialize serial communication at 9600 bits per second:
 
 //Set pins as outputs
 
 pinMode(IN1, OUTPUT);
 pinMode(IN2, OUTPUT);
 pinMode(IN3, OUTPUT);
 pinMode(IN4, OUTPUT);

 pinMode(EN, OUTPUT);
 
 //pinMode(lights, OUTPUT);
 //pinMode(horn, OUTPUT);
 
 //void stop();
 
 //digitalWrite(lights, LOW);
// digitalWrite(horn, LOW); 
}

void Stop()
  {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    
  
  }
void Front()
  {  
  
    //This function  will turn Motors front.
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    
    
  
  }
  
void Back()
  {
     
    //This function will turn Motors backward.
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);

    
  
   
  }

void Left()
  { 
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
  }
  
void Right()
  {
    
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  }
  
/*void Lights()
  {
    if (digitalRead(lights)==LOW)
      digitalWrite(lights,HIGH);
    else
      digitalWrite(lights,LOW);
  }
  
void Horn()
  {
    int i;
    //for(i = 0; i < 4 ; i++)
      {
        digitalWrite(horn,HIGH);
        delay(200);
        digitalWrite(horn,LOW);
        delay(200);
        
        if(i=1)
          delay(400);
      }  
    
  }
/*  
void turbo()
 {
  if (speed == 200)
    speed = 255;
  else
    speed = 200;
 }
 */ 
void loop() {
  //delay(500);
  //recieve bluetooth signal
  if(Serial.available() > 0)      // Send data only when you receive data:
  {
      command = Serial.read();        //Read the incoming data & store into data
      Serial.print(command);
  }

  
    analogWrite(EN, pwm);
  
  //Serial.print("Switch");
  switch (command) {
  
    case 'F' : Front(); break;
    case 'B' : Back(); break;
    case 'L' : Left(); break;
    case 'R' : Right(); break;
   // case 'Q' : Lights(); break;
    //case 'H' : Horn(); break;
    case 'E' : Stop();break;
    //case 'T' : turbo();break;
    
    //case '.' : FullStop(); break;
    
    }
  
  command = ' ';
}
