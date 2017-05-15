#include <Ultrasonic.h>
#include<LiquidCrystal.h>
#define TRIGGER 12
#define ECHO 13
#define MAXword 40
#define ROW(x) (x / 2)
#define COL(x) (x % 20)
LiquidCrystal lcd(11, 10, 9, 8, 7, 6); 
Ultrasonic ultrasonic(TRIGGER, ECHO);

const byte intPin=2;
volatile boolean SW=LOW; 
volatile boolean STOP=LOW;
const byte stopPin=5;

void setup() 
{
  Serial.begin(9600);
  Serial.println("04050343 04050794 START");
  lcd.begin(20, 2);
  lcd.cursor(); // 游標
  lcd.blink(); // 游標閃爍
  
  //pinMode(ledPin, OUTPUT); 
  pinMode(intPin, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP); 
 // digitalWrite(ledPin, ledState); //set LED OFF 
  attachInterrupt(0, int0, LOW); //assign int0 
}
void loop() 
{
  STOP = digitalRead(5);
 if (STOP) 
  {
    interrupts();
    }
  else 
  {
     noInterrupts();
  }
}
void int0()
{ 
  SW=!SW; //reverse state
 float cm, in;
long ms = ultrasonic.timing();
cm = ultrasonic.convert(ms, Ultrasonic::CM); 
in = ultrasonic.convert(ms, Ultrasonic::IN);
Serial.print("MS: "); Serial.print(ms);
Serial.print(", CM: "); Serial.print(cm);
Serial.print(", IN: "); Serial.println(in);
//04050343 04050794
lcd.home();
lcd.print("MS = ");
lcd.print(ms);
//lcd.setCursor(0, 1); 
lcd.print(" CM = ");
lcd.print(cm);
//lcd.clear();

 // delay(2000);

}
