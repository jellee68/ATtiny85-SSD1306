

#include <avr/pgmspace.h>
#include "SSD1306_minimal.h"
#include "font5x7.h"
#include "font8x16.h"
#include "font6x8.h"


SSD1306_Mini oled;

//Convert image to bitmap at https://diyusthad.com/image2cpp
const unsigned char img_logo [] PROGMEM = {
  // 'VW, 30x30px
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x60, 0xe0, 0x10, 0x10, 0x10, 0x10, 
  0x10, 0x10, 0xe0, 0x60, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0xf8, 0x0e, 0x3d, 0xf0, 0xc0, 0x00, 0x00, 0x01, 0x07, 0x3c, 0x70, 0x70, 0x1c, 0x07, 
  0x01, 0x00, 0x00, 0xc0, 0xf0, 0x1d, 0x0e, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x07, 0x10, 0x60, 0xc0, 0x83, 0x0f, 0x3c, 0xf0, 0x38, 0x0e, 0x03, 0x03, 0x0e, 0x78, 0xf0, 0x3c, 
  0x07, 0x83, 0xc0, 0x20, 0x10, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x01, 0x00, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x02, 0x02, 0x00, 0x01, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};



void prepareDisplay(){
  oled.clear();
  oled.startScreen();
}


void setup(){
  
 
  oled.init(0x3c);
  oled.clear();
  prepareDisplay();

  oled.drawImage( img_logo, 75,2, 30, 4);

  oled.print8x16String( 0, 0, "Font 8X16" ) ; //Larger fonts need start position as they are printed acros to rows.
  oled.cursorTo (0, 3);
  oled.print6x8String( "Font 6x8" );
  oled.cursorTo (0, 5);
  oled.print5x7String( "Font 5x7" ); 
  
  
}    

void loop(){
     
    char buf[10];
    long ti= millis() ;

    ti=ti/1000 ;
    
    sprintf(buf, "%ld" , ti);
    
   //print to display
   oled.print8x16String( 80, 6, buf );
    
  }
  
  
