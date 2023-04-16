//Pill Buddy
//Global Variables
//Hackathon '23
//This code will dispense medicine to the elderly as part of a reminder system.

//------------------------------------------------//

//LCD variables
#include <LiquidCrystal.h> //LCD library
LiquidCrystal lcd(13,12,11,10,9,8);

//Buttons
int demo_button =  6;
int demo_value;

int dispense_button = 5;
int dispense_value;

//Micro-Servo 1 Variables
#include <Servo.h>

Servo myservo; //include the servo library
int servopin=4; //create a servo object 


//LEDS 
int blue = 3;//Red LED pin12 
int green = 2;//Blue LED pin11 
int red = 1;//Second Red LED pin8 


//Piezo 
int sound=7;//Piezo speaker pin7 

#define NOTE_A3  220
#define NOTE_C4  262
#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_G4  392
#define NOTE_A4  440


//----------------------------------------------------//

void setup()
{
  
  //LCD instructions - begin LCD
  lcd.begin(16,2);
  
  //button functions
  pinMode(demo_button, INPUT_PULLUP);
  pinMode(dispense_button, INPUT_PULLUP);
 


  //Micro-Servos set-up
  myservo.attach(servopin);
  myservo.write(0);

  //LEDs set-up
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);

  //Piezo set-up
  pinMode(sound, OUTPUT); 
  
}
//--------------------------------------------------//

void loop()
{
  lcd.clear();
  
 //READ demo & dispense button 
  demo_value = digitalRead(demo_button);
  dispense_value = digitalRead(dispense_button);
  // start a demo
  if(demo_value == LOW){
    delay(300); //wait 3 seconds
    //display
      lcd.setCursor(0,0);
      lcd.print("Medication!"); 
    //alarm
      while(dispense_value == HIGH){
    	playIceSpice();
        //redFor(100);
        dispense_value = digitalRead(dispense_button);
        if(dispense_value == LOW){
          lcd.clear();
          break;
        }
        }
    //spin
  	  lcd.setCursor(0,0);
      lcd.print("Bye!");
      spinServo(); 
      delay(5000);
      }
              
    }
    
  
 
//--------------FUNCTIONS--------------//

//function that turns the servo to next pill slot
void spinServo(){
  return; //NEED TO COMPLETE
}

//Functions for alarm song
void playIceSpice() {
  //line 1
  A(161, "red");
  A(161, "blue");
  C(161,"green");
  D(161, "red");
  C(322,"blue");
  delay(161);
  //line 2
  A(161,"green");
  A(161,"red");
  C(161,"blue");
  E(161,"green");
  D(322,"red");
  delay(161);
  //line 3
  A(161,"blue");
  A(161,"green");
  C(161,"red");
  D(161,"blue");
  C(322,"green");
  delay(161);
  //line 4
  F4(161, "red");
  G(161,"blue");
  Ah(161,"green");
  E(161,"red");
  E(161,"blue");
  D(161,"green");
  C(322,"red");
  delay(644); 
}


void A(int n, String color){
  tone(sound,NOTE_A3);
  ledon(color);
  delay(n);
  noTone(sound);
  ledoff();
  delay(10);
}

void Ah(int n, String color){
  tone(sound,NOTE_A4);
  ledon(color);
  delay(n);
  noTone(sound);
  ledoff();
  delay(10);
}

void C(int n, String color){
  tone(sound,NOTE_C4);
  ledon(color);
  delay(n);
  noTone(sound);
  ledoff();
  delay(10);
}

void D(int n, String color){
  tone(sound,NOTE_D4);
  ledon(color);
  delay(n);
  noTone(sound);
  ledoff();
  delay(10);
}

void E(int n, String color){
  tone(sound,NOTE_E4);
  ledon(color);
  delay(n);
  noTone(sound);
  ledoff();
  delay(10);
}

void F4(int n, String color){
  tone(sound,NOTE_F4);
  ledon(color);
  delay(n);
  noTone(sound);
  ledoff();
  delay(10);
}

void G(int n, String color){
  tone(sound,NOTE_G4);
  ledon(color);
  delay(n);
  noTone(sound);
  ledoff();
  delay(10);
}

void ledon(String color)
{ 
  if (color == "blue") 
  { 
    digitalWrite(blue, HIGH);
  } 
  else if (color == "green") 
  { 
    digitalWrite(green, HIGH);
  } 
  else if (color == "red") 
  { 
    digitalWrite(red, HIGH); 
  } 
  else if (color == "all") 
  { 
    digitalWrite(blue, HIGH);
    digitalWrite(green, HIGH);
    digitalWrite(red, HIGH);
  }  
} 

void ledoff() 

{ 
  digitalWrite(blue, LOW); 
  digitalWrite(green, LOW); 
  digitalWrite(red, LOW); 
}