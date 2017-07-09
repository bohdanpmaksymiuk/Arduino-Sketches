//We always have to include the library
#include "LedControl.h"

/*
 Now we need a LedControl to work with.
 ***** These pin numbers will probably not work with your hardware *****
 pin 12 is connected to the DataIn 
 pin 11 is connected to the CLK 
 pin 10 is connected to LOAD 
 ***** Please set the number of devices you have *****
 But the maximum default of 8 MAX72XX wil also work.
 */
LedControl lc=LedControl(12,11,10,4);

/* we always wait a bit between updates of the display */
unsigned long delaytime=500;

/* 
 This time we have more than one device. 
 But all of them have to be initialized 
 individually.
 */


void setup() {
  Serial.begin(9600);
  int devices=lc.getDeviceCount();
 
  for(int address=0;address<devices;address++) {
    /*The MAX72XX is in power-saving mode on startup*/
    lc.shutdown(address,false);
    lc.setIntensity(address,1); /* Set the brightness to a medium values */
    lc.clearDisplay(address);
  }
}

void printValue(String name, int value) {
  Serial.print(name +"=");
  Serial.println(value);
}
void setLed(int x,int y) {
   int devices=lc.getDeviceCount();
   
   int device = (x/8);
   int x1 = 8-(((x)%8)+1);
   
   //Serial.println("-----------");
   //printValue("x",x);
   //printValue("x1",x1);
   //printValue("device",device);  
   
   lc.setLed(device,y,x1,true);
}

void loop() { 
  //read the number cascaded devices
  int devices=lc.getDeviceCount();
  //for(int row=0;row<8*4;row++) {
  
    for(int col=0;col<8*4;col++) {
      //setLed(col,0);
      setLed(col,1);
      //setLed(col,2);
      setLed(col,3);
      //setLed(col,4);
      setLed(col,5);
      //setLed(col,6);
      setLed(col,7);    
    }
  //}

  
  //we have to init all devices in a loop
  //for(int row=0;row<8;row++) {
  //  for(int col=0;col<8;col++) {
   //   for(int address=0;address<devices;address++) {
   //     delay(delaytime);
   //     lc.setLed(address,row,col,true);
   //     delay(delaytime);
   //     lc.setLed(address,row,col,false);
   //   }
   // }
  //}
}
