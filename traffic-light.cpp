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

void setup()
{
  pinMode(5, OUTPUT); 
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, INPUT);
}

  light red(5);
  light yellow(6);
  light green(7);

void loop()
{
	red.turnON();
  	delay(2000);
  	red.turnOFF();

  	yellow.turnON();
 	delay(2000);
  	yellow.turnOFF();

	green.turnON();
    delay(2000);
  	green.turnOFF();

}
