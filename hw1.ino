#include <Ultrasonic.h>
#include<LiquidCrystal.h>
#define TRIGGER 12
#define ECHO 13
#define MAXword 40
#define ROW(x) (x / 2)
#define COL(x) (x % 20)
LiquidCrystal lcd(11, 10, 9, 8, 7, 6); 
Ultrasonic ultrasonic(TRIGGER, ECHO);
void setup() 
{
Serial.begin(9600);
 Serial.println("04050343 04050794 START");
  lcd.begin(20, 2);
  lcd.home();
lcd.cursor(); // 游標
lcd.blink(); // 游標閃爍
}
void loop()
{

float cm, in;
long ms = ultrasonic.timing();
cm = ultrasonic.convert(ms, Ultrasonic::CM); 
in = ultrasonic.convert(ms, Ultrasonic::IN);
Serial.print("MS: "); Serial.print(ms);
Serial.print(", CM: "); Serial.print(cm);
Serial.print(", IN: "); Serial.println(in);
//04050343 04050794
lcd.print("MS = ");
lcd.print(ms);
//lcd.setCursor(0, 1); 
lcd.print(" CM = ");
lcd.print(cm);



delay(2000);
lcd.clear();

}
