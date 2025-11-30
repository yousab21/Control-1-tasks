class light{
  public:
  int pinNumber;
  bool isON;
  
  public:
  void turnON(){
    digitalWrite(pinNumber, HIGH);
    isON = 1;  
  }
  
  void turnOFF(){
    digitalWrite(pinNumber, LOW);
    isON = 0;  
  }
  light(int pin){
    pinNumber = pin ;
  }
};


class Button{
  public:
  int pinNumber;
  bool state = HIGH;
    
  public:
  void checkState(){
	state = digitalRead(pinNumber);
  }
  
  Button(int pin){
    pinNumber = pin;
  }
};
    
  
void setup()
{
   pinMode(5, OUTPUT); 
   pinMode(6, OUTPUT);
   pinMode(7, OUTPUT);
   pinMode(8, INPUT_PULLUP); // input_pullup => not pressed -> high, pressed -> low
}

   light red(5);
   light yellow(6);
   light green(7);
   Button button(8);

void loop()
{
  	unsigned long startTime = millis(); // millis() returns the time since the simulation started
 	green.turnON();
    while (millis() - startTime <= 2000)
    {
      if (button.state == HIGH) // if statement to make sure the checkState function doesn't make the state HIGH again after pressing the button once
      {
		     button.checkState(); // check button state while green light is on without freezing the program with delay()
      }
    }
  	green.turnOFF();

  	startTime = millis();
  	yellow.turnON();
	while (millis() - startTime <= 2000)
    {
      if (button.state == HIGH)
      {
		     button.checkState();
      }
    }
  	yellow.turnOFF();

	red.turnON();
  	if (button.state == LOW)
    {
  		  delay(6000);
      	button.state = HIGH;
        red.turnOFF();
    }
  	else
    {
      	delay(2000);
  		  red.turnOFF();
    }
}
