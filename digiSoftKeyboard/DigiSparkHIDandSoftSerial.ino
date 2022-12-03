#include <SoftSerial_INT0.h>          //https://github.com/J-Rios/Digispark_SoftSerial-INT0
#include "DigiKeyboardMultilang.h"


#define P_RX 2                        // Reception PIN (SoftSerial)
#define P_TX 1                        // Transmition PIN (SoftSerial)

SoftSerial mySerial(P_RX, P_TX);  

void setup() {
  mySerial.begin(4800);
  //mySerial.println("Hello, world?");
}

void loop() {
  DigiKeyboard.sendKeyStroke(0);
  if (mySerial.available()) {
    DigiKeyboard.print((char)mySerial.read());
  }
}
