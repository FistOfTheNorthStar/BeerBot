#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

//max pulse 4096
//main motors for the ROBOT
#define LOWER_MAIN_LIFT 6
#define UPPER_MAIN_LIFT 7
#define SERVOMIN_S3315D  140
#define SERVOMAX_S3315D  570

//servo Futada S3003, 50Hz
#define ROTATE_DISC 15
//int RotateDiscHz = 50;
#define SERVOMIN_S3003 140
#define SERVOMAX_S3003 610
uint16_t currentPos_ROTATE_DISC = 375;
uint16_t newPos_ROTATE_DISC = 375;
// 0 for stay put, 1 rotate
byte move_ROTATE_DISC = 0;
#define ROTATE_DISC_SPEED 5

//MG995
#define ARM_1 11
#define HAND_1 10
#define OPENER 9
#define SERVOMIN_MG995 140
#define SERVOMAX 580

int valueForAngle = 200;

uint8_t RotateDisc = 6;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pwm.begin();
  
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates

  yield();

}

/*
void setServoPulse(uint8_t n, double pulse) {
  double pulselength;
  
  pulselength = 1000000;   // 1,000,000 us per second
  pulselength /= 60;   // 60 Hz
  Serial.print(pulselength); Serial.println(" us per period"); 
  pulselength /= 4096;  // 12 bits of resolution
  Serial.print(pulselength); Serial.println(" us per bit"); 
  pulse *= 1000;
  pulse /= pulselength;
  Serial.println(pulse);
  pwm.setPWM(n, 0, pulse);
}
*/

void loop() {
  //Serial.println(servonum);


  //disc rotating
  if(move_ROTATE_DISC == 1 && currentPos_ROTATE_DISC < newPos_ROTATE_DISC){
    for (currentPos_ROTATE_DISC; currentPos_ROTATE_DISC <= newPos_ROTATE_DISC; currentPos_ROTATE_DISC++) {
      pwm.setPWM(ROTATE_DISC, 0, currentPos_ROTATE_DISC);
      delay(ROTATE_DISC_SPEED);
      if (currentPos_ROTATE_DISC == newPos_ROTATE_DISC){
        currentPos_ROTATE_DISC = newPos_ROTATE_DISC;
      }
    }
  } else if(move_ROTATE_DISC == 1 && currentPos_ROTATE_DISC > newPos_ROTATE_DISC){
    for (currentPos_ROTATE_DISC; currentPos_ROTATE_DISC >= newPos_ROTATE_DISC; currentPos_ROTATE_DISC--) {
      pwm.setPWM(ROTATE_DISC, 0, currentPos_ROTATE_DISC);
      delay(ROTATE_DISC_SPEED);
      if (currentPos_ROTATE_DISC == newPos_ROTATE_DISC){
        currentPos_ROTATE_DISC = newPos_ROTATE_DISC;
      }
    } 
  }
  
  
  if(Serial.available()){
    int f = Serial.parseInt();
    if (f >= 0 && f < 4096){
      valueForAngle = f;
    }
  }

  pwm.setPWM(RotateDisc, 0, valueForAngle);
  delay(500);
  /*
  for (uint16_t pulselen = SERVOMIN_S3003; pulselen < SERVOMAX_S3003; pulselen++) {
    pwm.setPWM(ROTATE_DISC, 0, pulselen);
    delay(5);
  }

  delay(500);
  for (uint16_t pulselen = SERVOMAX_S3003; pulselen > SERVOMIN_S3003; pulselen--) {
    pwm.setPWM(ROTATE_DISC, 0, pulselen);
    delay(5);
  }
*/
  delay(500);
  
  

}
