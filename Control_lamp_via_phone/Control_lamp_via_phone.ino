/**********************************************************************************************/
/** Desc    : Control the room lamp via phone                                                */
/** Author  : 3li Al_Refaee                                                                 */
/** Date    : 5 july 2021                                                                  */
/** version : 1.0v                                                                        */
/*****************************************************************************************/

/*
   -- New project --
   
   This source code of graphical user interface 
   has been generated automatically by RemoteXY editor.
   To compile this code using RemoteXY library 3.1.6 or later version 
   download by link http://remotexy.com/en/library/
   To connect using RemoteXY mobile app by link http://remotexy.com/en/download/                   
     - for ANDROID 4.7.12 or later version;
     - for iOS 1.4.7 or later version;
    
   This source code is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.    
*/

//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////

// RemoteXY select connection mode and include library 

#define REMOTEXY_MODE__SOFTSERIAL
#include <SoftwareSerial.h>

#include <RemoteXY.h>

// RemoteXY connection settings 
#define REMOTEXY_SERIAL_RX 2
#define REMOTEXY_SERIAL_TX 3
#define REMOTEXY_SERIAL_SPEED 9600
#define REMOTEXY_ACCESS_PASSWORD "123456789"


// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =   // 61 bytes
  { 255,3,0,0,0,54,0,16,17,1,2,1,37,6,22,11,2,26,31,31,
  79,78,0,79,70,70,0,2,1,38,29,22,11,2,26,31,31,79,78,0,
  79,70,70,0,2,1,38,53,22,11,2,26,31,31,79,78,0,79,70,70,
  0 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  uint8_t switch_1; // =1 if switch ON and =0 if OFF 
  uint8_t switch_2; // =1 if switch ON and =0 if OFF 
  uint8_t switch_3; // =1 if switch ON and =0 if OFF 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop)

/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////

#define PIN_SWITCH_1 A0
#define PIN_SWITCH_2 A1
#define PIN_SWITCH_3 A2


void setup() 
{
  RemoteXY_Init (); 
  
  pinMode (PIN_SWITCH_1, OUTPUT);
  pinMode (PIN_SWITCH_2, OUTPUT);
  pinMode (PIN_SWITCH_3, OUTPUT);
  
  // TODO you setup code
  
}

void loop() 
{ 
  RemoteXY_Handler ();
  
  digitalWrite(PIN_SWITCH_1, (RemoteXY.switch_1==0)?LOW:HIGH);
  digitalWrite(PIN_SWITCH_2, (RemoteXY.switch_2==0)?LOW:HIGH);
  digitalWrite(PIN_SWITCH_3, (RemoteXY.switch_3==0)?LOW:HIGH);
  
  // TODO you loop code
  // use the RemoteXY structure for data transfer
  // do not call delay() 


}
