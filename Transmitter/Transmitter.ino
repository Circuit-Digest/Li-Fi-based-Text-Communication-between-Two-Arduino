//Transmitter Side:
#include <Keypad.h>
const byte ROW = 4;
const byte COL = 4;
char keyscode[ROW][COL] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPin[ROW] = {A5, A4, A3, A2};
byte colPin[COL] = {A1, A0, 12, 11};
Keypad customKeypad = Keypad( makeKeymap(keyscode), rowPin, colPin, ROW, COL);
char keycount = 0;
char code[5];
void setup() 
{
  Serial.begin(9600);
  pinMode(8,OUTPUT);
  digitalWrite(8,LOW);
}
void loop()
{
  char customKey = customKeypad.getKey();
  if (customKey) {
    Serial.println(customKey);
   if (customKey == '1')
  {
    digitalWrite(8,HIGH);
    delay(10);
    digitalWrite(8,LOW);
  }
  else if (customKey == '2')
  {
    digitalWrite(8,HIGH);
    delay(20);
    digitalWrite(8,LOW);
  }
  else if (customKey == '3')
  {
    digitalWrite(8,HIGH);
    delay(30);
    digitalWrite(8,LOW);
  }
  else if (customKey == '4')
  {
    digitalWrite(8,HIGH);
    delay(40);
    digitalWrite(8,LOW);
  }
  else if (customKey == '5')
  {
    digitalWrite(8,HIGH);
    delay(50);
    digitalWrite(8,LOW);
  }
  else if (customKey == '6')
  {
    digitalWrite(8,HIGH);
    delay(60);
    digitalWrite(8,LOW);
  }
  else if (customKey == '7')
  {
    digitalWrite(8,HIGH);
    delay(70);
    digitalWrite(8,LOW);
  }
  else if (customKey == '8')
  {
    digitalWrite(8,HIGH);
    delay(80);
    digitalWrite(8,LOW);
  }
  else if (customKey == '9')
  {
    digitalWrite(8,HIGH);
    delay(90);
    digitalWrite(8,LOW);
  }
  else if (customKey == '*')
  {
    digitalWrite(8,HIGH);
    delay(100);
    digitalWrite(8,LOW);
  }
  else if (customKey == '0')
  {
    digitalWrite(8,HIGH);
    delay(110);
    digitalWrite(8,LOW);
  }
  else if (customKey == '#')
  {
    digitalWrite(8,HIGH);
    delay(120);
    digitalWrite(8,LOW);
  }
  else if (customKey == 'A')
  {
    digitalWrite(8,HIGH);
    delay(130);
    digitalWrite(8,LOW);
  }
  else if (customKey == 'B')
  {
    digitalWrite(8,HIGH);
    delay(140);
    digitalWrite(8,LOW);
  }
  else if (customKey == 'C')
  {
    digitalWrite(8,HIGH);
    delay(150);
    digitalWrite(8,LOW);
  }
  else if (customKey == 'D')
  {
    digitalWrite(8,HIGH);
    delay(160);
    digitalWrite(8,LOW);
  }
  else;
  } 
}
