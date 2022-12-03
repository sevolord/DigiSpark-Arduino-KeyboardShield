# DigiSpark-Arduino-KeyboardShield
DigiSpark emulates HID keyboard Arduino Nano has more pins, connects keypad and stores text.

Проект аппаратного хранилища паролей.
Нажимем кнопку на кейпаде - забитый под этот кейпад пароль вводится.
Но нужно следить за раскладкой. 

Проект реализован на связке arduino nano, которая имеет больше ног и больше памяти, и на DigiSpark, которая из коробки умеет притворятся HID клавиатурой. 
Наиболее ценное в этом проекте то, что найдена библиотека, которая позволяет реализоваывать на DigiSpark и HID, и SoftSerial одновременно:
https://github.com/J-Rios/Digispark_SoftSerial-INT0
