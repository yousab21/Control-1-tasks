
class light{
  public:
  int pinNumber;
  bool isON = 0;
  
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

  class button {
    public:
        int pinNumber;
        bool current;
        bool last;
        bool latched;
    
        button(int p) : pinNumber(p), current(HIGH), last(HIGH), latched(false) {}
    
        void checkState() {
            last = current;
            current = digitalRead(pinNumber);
    
            // detect rising edge
            if (last == LOW && current == HIGH) {
                latched = true;
            }
        }
    
        bool wasPressed() {
            return latched;
        }
    
        void reset() {
            latched = false;
        }
    };
    

// Create light and button objects
  light red(5);
  light yellow(6);
  light green(7);
  button button(8);


//setting up intervalts
unsigned long ledShortInterval = 2000;
unsigned long ledLongInterval = 7000;
unsigned long cycleStart = 0;
unsigned long now = 0;


void setup()
{
  //initialize pins
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, INPUT_PULLUP);
  //start the cycle with green light on
  green.turnON();
}


void loop()
{
  now = millis();
  button.checkState();

  //green cycle
  if (green.isON && (now - cycleStart >= ledShortInterval)){
    green.turnOFF();
    yellow.turnON();
    cycleStart = now;
  }

  //yellow cyclw
  else if (yellow.isON && (now - cycleStart >= ledShortInterval)){
    yellow.turnOFF();
    red.turnON();
    cycleStart = now;
  }

  else if (red.isON){
    //do the long delay if button is pressed
    if(button.wasPressed()){
      if (now - cycleStart >= ledLongInterval){
        red.turnOFF();
        green.turnON();
        cycleStart = now;
        button.reset();
      }
    }
    else{
      if (now - cycleStart >= ledShortInterval){
        red.turnOFF();
        green.turnON();
        cycleStart = now;
      }
    }
  }
}
