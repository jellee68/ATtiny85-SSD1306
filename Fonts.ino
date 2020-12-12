

#include <avr/pgmspace.h>
#include "SSD1306_minimal.h"
#include "font5x7.h"
#include "font8x16.h"
#include "font6x8.h"

SSD1306_Mini oled;

void prepareDisplay(){
  oled.clear();
  oled.startScreen();
}


void setup(){
    
  oled.init(0x3c);
  oled.clear();
  prepareDisplay();
  oled.print8x16String( 0, 0, "Font 8X16" ) ; 
  oled.cursorTo (0, 3);
  oled.print6x8String( "Font 6x8" );
  oled.cursorTo (0, 5);
  oled.print5x7String( "Font 5x7" );
}    

void loop(){
    
  
}
  
  
