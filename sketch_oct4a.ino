/* send.ino Example sketch for IRLib2
 *  Illustrates how to send a code.
 */
#include <IRLibSendBase.h>    // First include the send base
//Now include only the protocols you wish to actually use.
//The lowest numbered protocol should be first but remainder 
//can be any order.   
#include <IRLib_P02_Sony.h>   
#include <IRLibCombo.h>     // After all protocols, include this
// All of the above automatically creates a universal sending
// class called "IRsend" containing only the protocols you want.
// Now declare an instance of that sender.

IRsend mySender;

void setup() {
  Serial.begin(9600);
  delay(2000); while (!Serial); //delay for Leonardo
  Serial.println(F("Every time you press a key is a serial monitor we will send."));
}

void loop() {
  int codes[] ={0x0000000000000441,
    0x0000000000000561,
    0x0000000000000C41,
    0x0000000000000A41,
    0x0000000000000841,
    0x0000000000000041,
    0x0000000000000896,
    0x0000000000000096,
    0x0000000000000CD6,
    0x00000000000004D1,
    0x00000000000009D1,
    0x00000000000001D1,
    0x00000000000000D1,
    0x00000000000008D1,
    0x00000000000007D1,
    0x000000000000055E,
    0x000000000000095E,
    0x000000000000015E,
    0x000000000000005E,
    0x000000000000085E,
    0x0000000000000EC1,
    0x00000000000004C1,
    0x00000000000001C1,
    0x0000000000000CC1,
    0x00000000000002C1,
    0x000000000000004E,
    0x000000000000058E,
    0x000000000000018E,
    0x0000000000000D8E,
    0x000000000000038E,
    0x00000000000008C6,
    0x0000000000000281,
    0x0000000000000481,
    0x0000000000000C81};

  int counter= 0;
  while(true){
      if (Serial.read() != -1) {
        mySender.send(SONY,codes[counter], 12);
        Serial.println(F("Sent signal:"));
        Serial.println(counter);
        Serial.println(codes[counter]);
        counter +=1;
  }
  }
}