//исходный код работы с клавиатурой взят с сайта https://habr.com/ru/post/460409/

#include <Keypad.h>

const byte ROWS = 4;           //число строк у нашей клавиатуры
const byte COLS = 4;           //число столбцов у нашей клавиатуры
char hexaKeys[ROWS][COLS] = {  // здесь мы располагаем названия наших клавиш, как на клавиатуре,для удобства пользования
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};

byte rowPins[ROWS] = { 5, 4, 3, 2 };  //к каким выводам подключаем управление строками
byte colPins[COLS] = { 9, 8, 7, 6 };  //к каким выводам подключаем управление столбцами

//передаем все эти данные библиотеке:
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

#include <SoftwareSerial.h> // подключаем программный последовательный порт
SoftwareSerial mySerial(10, 11);  // RX, TX //пины, которые поделючаем к digispark rx->tx, tx->rx

void setup() {
  mySerial.begin(4800);//следим, что бы скорость совпадала со скетчем в digispark
}

void loop() {
  String buf;
  char customKey = customKeypad.getKey();  //записывем нажатый символ
  if (customKey) {                         //если что-то нажато
    switch (customKey) {
      case '*':
        buf = "Admin"; //login
        mySerial.println(buf);
        break;
      case '#':
        buf = "pass"; //password
        mySerial.println(buf);
        break;
      case '0':
        buf = "Hello, {UserName}!";
        mySerial.println(buf);
        break;
      case '1':
        buf = "Best Regards, mr. Anderson";
        mySerial.println(buf);
      case '2':
        break;
        buf = "Hello_there!";
        mySerial.println(buf);
        break;
	  case '3':
        buf = "Obi-Wan_Kenobi!!";	  
        mySerial.println(buf);
        break;
    }
  }
}