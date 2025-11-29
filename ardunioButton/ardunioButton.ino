class light{
  public:
  int pinNumber;
  bool isON;
  
  void turnON(){
    digitalWrite(pinNumber, HIGH);
    isON = 1;  
  }
  
  void turnOFF(){
    digitalWrite(pinNumber, LOW);
    isON = 0;  
  }
  light(int pin){
    pinNumber = pin;
     pinMode(pin, OUTPUT);
  }
};
class button{
  public:
  int bPin;
 bool pushed;
 button(int pin){
  bPin = pin;
  pinMode(bPin, INPUT);
  pushed = false;
}
bool isPressed(){
  pushed = digitalRead(bPin);
  return pushed;
}
};
light red(5);
light yellow(6);
light green(7);
button pedButton(8);
void setup()
{
  
}

  
void loop()
{
  green.turnON();
  pedButton.isPressed();
    delay(2000);
    green.turnOFF();

  yellow.turnON();
  pedButton.isPressed();
  delay(2000);
    yellow.turnOFF();
    
  red.turnON();
  if(pedButton.pushed == true)
  {
    delay(4000); /*extra time added if button was pressed during green or yellow*/
  red.turnOFF();
  pedButton.pushed = false;
  }
  else
  {
    delay(2000);
    red.turnOFF();
  }
   yellow.turnON();
   red.turnON();
   delay(2000);
   yellow.turnOFF();
   red.turnOFF();
}
