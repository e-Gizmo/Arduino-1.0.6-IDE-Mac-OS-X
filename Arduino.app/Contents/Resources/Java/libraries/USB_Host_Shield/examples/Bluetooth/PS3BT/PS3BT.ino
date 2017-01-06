/*
 Example sketch for the PS3 Bluetooth library - developed by Kristian Lauszus
 For more information visit my blog: http://blog.tkjelectronics.dk/ or 
 send me an e-mail:  kristianl@tkjelectronics.com
 */

#include <PS3BT.h>
USB Usb;
BTD Btd(&Usb); // You have to create the Bluetooth Dongle instance like so
/* You can create the instance of the class in two ways */
PS3BT PS3(&Btd); // This will just create the instance
//PS3BT PS3(&Btd,0x00,0x15,0x83,0x3D,0x0A,0x57); // This will also store the bluetooth address - this can be obtained from the dongle when running the sketch

boolean printTemperature;
boolean printAngle;

void setup() {
  Serial.begin(115200);

  if (Usb.Init() == -1) {
    Serial.print(F("\r\nOSC did not start"));
    while(1); //halt
  }
  Serial.print(F("\r\nPS3 Bluetooth Library Started"));
}
void loop() {
  Usb.Task();

  if(PS3.PS3Connected || PS3.PS3NavigationConnected) {
    if(PS3.getAnalogHat(LeftHatX) > 137 || PS3.getAnalogHat(LeftHatX) < 117 || PS3.getAnalogHat(LeftHatY) > 137 || PS3.getAnalogHat(LeftHatY) < 117 || PS3.getAnalogHat(RightHatX) > 137 || PS3.getAnalogHat(RightHatX) < 117 || PS3.getAnalogHat(RightHatY) > 137 || PS3.getAnalogHat(RightHatY) < 117) {
      if(PS3.getAnalogHat(LeftHatX) > 137 || PS3.getAnalogHat(LeftHatX) < 117) {
        Serial.print(F("LeftHatX: ")); 
        Serial.print(PS3.getAnalogHat(LeftHatX));
        Serial.print("\t");
      } if(PS3.getAnalogHat(LeftHatY) > 137 || PS3.getAnalogHat(LeftHatY) < 117) {    
        Serial.print(F("LeftHatY: ")); 
        Serial.print(PS3.getAnalogHat(LeftHatY));
        Serial.print("\t");
      } if(PS3.getAnalogHat(RightHatX) > 137 || PS3.getAnalogHat(RightHatX) < 117) {
        Serial.print(F("RightHatX: ")); 
        Serial.print(PS3.getAnalogHat(RightHatX));
        Serial.print("\t");      
      } if(PS3.getAnalogHat(RightHatY) > 137 || PS3.getAnalogHat(RightHatY) < 117) {
        Serial.print(F("RightHatY: ")); 
        Serial.print(PS3.getAnalogHat(RightHatY));  
      }
      Serial.println("");
    }

    //Analog button values can be read from almost all buttons
    if(PS3.getAnalogButton(L2_ANALOG) > 0 || PS3.getAnalogButton(R2_ANALOG) > 0) {
      if(PS3.getAnalogButton(L2_ANALOG) > 0) {
        Serial.print(F("L2: ")); 
        Serial.print(PS3.getAnalogButton(L2_ANALOG));
        Serial.print("\t"); 
      } if(PS3.getAnalogButton(R2_ANALOG) > 0) {
        Serial.print(F("R2: ")); 
        Serial.print(PS3.getAnalogButton(R2_ANALOG)); 
      }
      Serial.println("");
    }

    if(PS3.buttonPressed)     
    {
      Serial.print(F("PS3 Controller"));

      if(PS3.getButton(PS)) {
        Serial.print(F(" - PS"));
        PS3.disconnect();
      } else {
        if(PS3.getButton(TRIANGLE))
          Serial.print(F(" - Traingle"));
        if(PS3.getButton(CIRCLE))
          Serial.print(F(" - Circle"));
        if(PS3.getButton(CROSS))
          Serial.print(F(" - Cross"));
        if(PS3.getButton(SQUARE))
          Serial.print(F(" - Square"));

        if(PS3.getButton(UP)) {
          Serial.print(F(" - Up"));          
          if(PS3.PS3Connected) {
            PS3.setAllOff();
            PS3.setLedOn(LED4);
          }
        } if(PS3.getButton(RIGHT)) {
          Serial.print(F(" - Right"));
          if(PS3.PS3Connected) {
            PS3.setAllOff();
            PS3.setLedOn(LED1); 
          }         
        } if(PS3.getButton(DOWN)) {
          Serial.print(F(" - Down"));
          if(PS3.PS3Connected) {
            PS3.setAllOff();
            PS3.setLedOn(LED2);          
          }
        } if(PS3.getButton(LEFT)) {          
          Serial.print(F(" - Left"));          
          if(PS3.PS3Connected) {
            PS3.setAllOff();         
            PS3.setLedOn(LED3);            
          }         
        } 

        if(PS3.getButton(L1))
          Serial.print(F(" - L1"));  
        //if(PS3.getButton(L2))
        //Serial.print(F(" - L2"));
        if(PS3.getButton(L3))
          Serial.print(F(" - L3")); 
        if(PS3.getButton(R1))
          Serial.print(F(" - R1"));  
        //if(PS3.getButton(R2))
        //Serial.print(F(" - R2"));              
        if(PS3.getButton(R3))
          Serial.print(F(" - R3"));

        if(PS3.getButton(SELECT)) {
          Serial.print(F(" - Select - ")); 
          Serial.print(PS3.getStatusString());        
        } if(PS3.getButton(START)) {
          Serial.print(F(" - Start"));              
          printAngle = !printAngle;
          while(PS3.getButton(START))
            Usb.Task();
        }                    
        Serial.println("");          
      }             
    }
    if(printAngle) {
      Serial.print(F("Pitch: "));               
      Serial.print(PS3.getAngle(Pitch));                  
      Serial.print(F("\tRoll: ")); 
      Serial.println(PS3.getAngle(Roll));
    }
  }
  else if(PS3.PS3MoveConnected)
  {
    if(PS3.getAnalogButton(T_ANALOG) > 0) {
      Serial.print(F("T: ")); 
      Serial.println(PS3.getAnalogButton(T_ANALOG)); 
    } if(PS3.buttonPressed) {
      Serial.print(F("PS3 Move Controller"));

      if(PS3.getButton(PS)) {
        Serial.print(F(" - PS"));
        PS3.disconnect();
      } else {
        if(PS3.getButton(SELECT)) {
          Serial.print(F(" - Select"));
          printTemperature = !printTemperature;
          while(PS3.getButton(SELECT))
            Usb.Task();          
        } if(PS3.getButton(START)) {
          Serial.print(F(" - Start"));
          printAngle = !printAngle;
          while(PS3.getButton(START))
            Usb.Task();                              
        } if(PS3.getButton(TRIANGLE)) {            
          Serial.print(F(" - Triangle"));
          PS3.moveSetBulb(Red);
        } if(PS3.getButton(CIRCLE)) {
          Serial.print(F(" - Circle"));
          PS3.moveSetBulb(Green);
        } if(PS3.getButton(SQUARE)) {
          Serial.print(F(" - Square"));
          PS3.moveSetBulb(Blue);
        } if(PS3.getButton(CROSS)) {
          Serial.print(F(" - Cross"));
          PS3.moveSetBulb(Yellow);
        } if(PS3.getButton(MOVE)) {     
          PS3.moveSetBulb(Off);                        
          Serial.print(F(" - Move"));
          Serial.print(F(" - ")); 
          Serial.print(PS3.getStatusString());
        }
        //if(PS3.getButton(T))
        //Serial.print(F(" - T"));

        Serial.println("");
      }
    }
    if(printAngle) {
      Serial.print(F("Pitch: "));               
      Serial.print(PS3.getAngle(Pitch));                  
      Serial.print(F("\tRoll: ")); 
      Serial.println(PS3.getAngle(Roll));
    }
    else if(printTemperature) {
      Serial.print(F("Temperature: "));
      Serial.println(PS3.getTemperature());
    }
  }
}
