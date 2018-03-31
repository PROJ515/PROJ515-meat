
#include <Servo.h>
//J4 and J1
#define f1_grip_pin 20
#define f1_sense A0
#define f1_rotate_pin 3

//J7 and J2
#define f2_grip_pin 22
#define f2_sense A1
#define f2_rotate_pin 4

//J8 and J3
#define f3_grip_pin 21
#define f3_sense A3
#define f3_rotate_pin 5

//J6 and J5
#define f4_grip_pin 23
#define f4_sense A2
#define f4_rotate_pin 6

#define rot_low_lim 100
#define rot_high_lim 170
#define rot_mid 135

Servo f1_rotate;  // create servo object to control a servo
Servo f2_rotate;
Servo f3_rotate;
Servo f4_rotate;

Servo f1_grip;
Servo f2_grip;
Servo f3_grip;
Servo f4_grip;

// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
int val;

void setup() {
  Serial.begin(38400);
    while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  
  pinMode(13, OUTPUT);
  
  f1_grip.attach(f1_grip_pin);
  f2_grip.attach(f2_grip_pin);
  f3_grip.attach(f3_grip_pin);
  f4_grip.attach(f4_grip_pin);

  f1_rotate.attach(f1_rotate_pin);
  f2_rotate.attach(f2_rotate_pin);
  f3_rotate.attach(f3_rotate_pin);
  f4_rotate.attach(f4_rotate_pin);
  rot_setup();
  //pincer();
}
int inByte = 135;

void loop() {

  if (Serial.available() > 0) {
    // get incoming byte:
    //inByte = Serial.read();
    //Serial.println(inByte);
    inByte = Serial.parseInt(); //read int or parseFloat for ..float...
    if ((inByte > 89) && (inByte < 181)){
    f1_grip.write(inByte);
    f2_grip.write(inByte);
    f3_grip.write(inByte);
    f4_grip.write(inByte);
    } else if (inByte == 200){
      pincer();
    } else if (inByte == 300){
      rot_setup();
    }
  }

  
  /*
  for (pos = 90; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    val = analogRead(A0);
    Serial.print("analog 0 is: ");
    Serial.println(val);
    val > 500 ? digitalWrite(13, HIGH) : digitalWrite(13, LOW);
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 90; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    val = analogRead(A0);
    Serial.print("analog 0 is: ");
    Serial.println(val);
    val > 500 ? digitalWrite(13, HIGH) : digitalWrite(13, LOW);
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  */
}

void rot_setup(){

  f1_rotate.write(rot_mid);
  f2_rotate.write(rot_mid);
  f3_rotate.write(rot_mid);
  f4_rotate.write(rot_mid);
  
}

void pincer(){
  f1_rotate.write(rot_high_lim);
  f2_rotate.write(rot_low_lim);
  f3_rotate.write(rot_low_lim);
  f4_rotate.write(rot_high_lim);
}

void check_gripper(){
f1_rotate.write(rot_low_lim);
delay(750);
f1_rotate.write(rot_high_lim);
delay(750);
f1_rotate.write(rot_mid);

delay(750);

f2_rotate.write(rot_low_lim);
delay(750);
f2_rotate.write(rot_high_lim);
delay(750);
f2_rotate.write(rot_mid);

delay(750);

f3_rotate.write(rot_low_lim);
delay(750);
f3_rotate.write(rot_high_lim);
delay(750);
f3_rotate.write(rot_mid);

delay(750);

f4_rotate.write(rot_low_lim);
delay(750);
f4_rotate.write(rot_high_lim);
delay(750);
f4_rotate.write(rot_mid);

delay(750);

f1_grip.write(rot_low_lim);
delay(750);
f1_grip.write(rot_high_lim);
delay(750);
f1_grip.write(rot_mid);

delay(750);

f2_grip.write(rot_low_lim);
delay(750);
f2_grip.write(rot_high_lim);
delay(750);
f2_grip.write(rot_mid);

delay(750);

f3_grip.write(rot_low_lim);
delay(750);
f3_grip.write(rot_high_lim);
delay(750);
f3_grip.write(rot_mid);

delay(750);

f4_grip.write(rot_low_lim);
delay(750);
f4_grip.write(rot_high_lim);
delay(750);
f4_grip.write(rot_mid);

delay(750);
}
