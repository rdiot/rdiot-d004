/* 650nm Laser Diode Module (KY-008) [D004] : http://rdiot.tistory.com/293 [RDIoT Demo] */

#include "U8glib.h"
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE);
 
int laserPin = 10;
int btnPin = 2;
 
void setup() {
  // put your setup code here, to run once:
   pinMode (laserPin, OUTPUT); // laser
   pinMode (btnPin, INPUT); // button
}
 
void loop(void) {
  // picture loop
  u8g.firstPage();  
  do {
    draw();
  } while( u8g.nextPage() );
  
  // rebuild the picture after some delay
  delay(500);
}
 
void draw(void) {
  u8g.setFont(u8g_font_9x15B);
  u8g.setPrintPos(0, 12); 
  u8g.println("Laser Emit");
 
  u8g.setFont(u8g_font_fub17);
  u8g.setPrintPos(0,40);
 
  int btn = digitalRead(btnPin);
  u8g.print("btn="+(String)btn);
 
  if(btn == 1)
  {
    digitalWrite (laserPin, HIGH);
  }
  else
  {
    digitalWrite (laserPin, LOW);
  }
 
/*
   digitalWrite (laserPin, HIGH); // Turn Laser On
   delay (1000); // On For Half a Second
   digitalWrite (laserPin, LOW); // Turn Laser Off
   delay (500); // Off for half a second
*/
 
}
