
const int buttonPin = 4;    // the number of the pushbutton pin
const int relePin = 5;      // the number of the Rele pin
const int button2Pin = 2;
const int ledPin = 13;
int releState = HIGH;       
int buttonState;            
int lastButtonState = LOW;  
unsigned long lastDebounceTime = 0; 
unsigned long debounceDelay = 50;   

void setup(){
  pinMode(buttonPin, INPUT);
  pinMode(relePin, OUTPUT);
  pinMode(button2Pin, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(relePin, releState);
}

void loop(){
  int reading = digitalRead(buttonPin);

  if (reading != lastButtonState){
    lastDebounceTime = millis(); }

if ((millis() - lastDebounceTime) > debounceDelay){
  if (reading != buttonState){
      buttonState = reading;
  if (buttonState == HIGH){
      releState = !releState;}}}

  digitalWrite(relePin, releState);
  lastButtonState = reading;

  digitalWrite(13, 1-digitalRead(button2Pin));
}
