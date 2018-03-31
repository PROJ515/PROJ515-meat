
#define ledPin 9

void setup() {
  // put your setup code here, to run once:
//test_led();
pinMode(13, OUTPUT);
pinMode(ledPin, OUTPUT);
digitalWrite(13, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
cycle_led();
}

void cycle_led(){
  
digitalWrite(ledPin, HIGH);
digitalWrite(13, HIGH);
delay(1000);

digitalWrite(ledPin, LOW);
digitalWrite(13, LOW);
delay(1000);
}


void test_led(){
  pinMode(13, OUTPUT);
digitalWrite(13, LOW);

digitalWrite(ledPin, LOW);
pinMode(ledPin, INPUT);

delay(1500);

digitalWrite(13, HIGH);

digitalWrite(ledPin, LOW);
pinMode(ledPin, OUTPUT);
digitalWrite(ledPin, LOW);

delay(750);

digitalWrite(13, LOW);
digitalWrite(ledPin, LOW);
pinMode(ledPin, INPUT);

}

