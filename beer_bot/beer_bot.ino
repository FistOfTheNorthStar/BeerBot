#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
#include <NewPing.h>

//rotation speed
#define ROTATION_SPEED 5

//main motors for the ROBOT
#define LOWER_MAIN_LIFT 6
#define UPPER_MAIN_LIFT 7

//servo Futada S3003, 50Hz
#define ROTATE_DISC 15
//int RotateDiscHz = 50;

uint16_t currentPos_ROTATE_DISC = 375;
uint16_t newPos_ROTATE_DISC = 375;
// 0 for stay put, 1 rotate
byte move_ROTATE_DISC = 0;
byte move_ARM1 = 0;
byte move_HAND1 = 0;
byte move_OPENER = 0;
byte move_LOWER_MAIN_LIFT = 0;

//MG995
#define ARM_1 11
#define HAND_1 10
#define OPENER 9

int valueForAngle = 200;

uint8_t RotateDisc = 6;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pwm.begin();
  pwm.setPWMFreq(60);  // 60Hz seems to be working
  yield();

}
void loop() {
 
  //disc rotating
  if(move_ROTATE_DISC == 1 && currentPos_ROTATE_DISC < newPos_ROTATE_DISC){
     
  } else if(move_ROTATE_DISC == 1 && currentPos_ROTATE_DISC > newPos_ROTATE_DISC){
    
  }

  //disc rotating
  if(move_ROTATE_DISC == 1 && currentPos_ROTATE_DISC < newPos_ROTATE_DISC){
     
  } else if(move_ROTATE_DISC == 1 && currentPos_ROTATE_DISC > newPos_ROTATE_DISC){
    
  }

  //disc rotating
  if(move_ROTATE_DISC == 1 && currentPos_ROTATE_DISC < newPos_ROTATE_DISC){
     
  } else if(move_ROTATE_DISC == 1 && currentPos_ROTATE_DISC > newPos_ROTATE_DISC){
    
  }

  //disc rotating
  if(move_ROTATE_DISC == 1 && currentPos_ROTATE_DISC < newPos_ROTATE_DISC){
     
  } else if(move_ROTATE_DISC == 1 && currentPos_ROTATE_DISC > newPos_ROTATE_DISC){
    
  }

  //disc rotating
  if(move_ROTATE_DISC == 1 && currentPos_ROTATE_DISC < newPos_ROTATE_DISC){
     
  } else if(move_ROTATE_DISC == 1 && currentPos_ROTATE_DISC > newPos_ROTATE_DISC){
    
  }

  //disc rotating
  if(move_ROTATE_DISC == 1 && currentPos_ROTATE_DISC < newPos_ROTATE_DISC){
     
  } else if(move_ROTATE_DISC == 1 && currentPos_ROTATE_DISC > newPos_ROTATE_DISC){
    
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

//rotate the robot motors downward
void rotateDown(uint16_t &newPos, uint16_t &currentPos, int motor_number) {
  for (currentPos; currentPos >= newPos; currentPos--) {
    pwm.setPWM(motor_number, 0, currentPos);
    delay(ROTATION_SPEED);
    if (currentPos == newPos){
      currentPos = newPos;
    }
  } 
}

//up motion
void rotateUp(uint16_t &newPos, uint16_t &currentPos, int motor_number) {
  for (currentPos; currentPos <= newPos; currentPos++) {
    pwm.setPWM(motor_number, 0, currentPos);
    delay(ROTATION_SPEED);
    if (currentPos == newPos){
      currentPos = newPos;
    }
  }
}


