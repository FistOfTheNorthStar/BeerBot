#define ROTATE_DISC_SPEED 5
//how far the motors can rotate
#define SERVOMIN_S3315D  140
#define SERVOMAX_S3315D  570
#define SERVOMIN_S3003 140
#define SERVOMAX_S3003 610
#define SERVOMIN_MG995 140
#define SERVOMAX_MG995 580

//check that values are wihin limits
void checkPosValIsProper(uint16_t &newPos, uint16_t &currentPos, int motor_number){
  if (motor_number == 6 || motor_number == 7){
    
    if (newPos > SERVOMAX_S3315D){
      newPos = SERVOMAX_S3315D;
    } else if (newPos < SERVOMIN_S3315D){
      newPos = SERVOMIN_S3315D;
    }

    if (currentPos > SERVOMAX_S3315D){
      currentPos = SERVOMAX_S3315D;
    } else if (currentPos < SERVOMIN_S3315D){
      currentPos = SERVOMIN_S3315D:
    }
  } else if (motor_number == 9 || motor_number == 10 || motor_number == 11){
    
    if (newPos > SERVOMAX_MG995){
      newPos = SERVOMAX_MG995;
    } else if (newPos < SERVOMIN_MG995){
      newPos = SERVOMIN_MG995;
    }

    if (currentPos > SERVOMAX_MG995){
      currentPos = SERVOMAX_MG995;
    } else if (currentPos < SERVOMIN_MG995){
      currentPos = SERVOMIN_MG995:
    }
  } else if (motor_number == 15) {
    
    if (newPos > SERVOMAX_S3003){
      newPos = SERVOMAX_S3003;
    } else if (newPos < SERVOMIN_S3003){
      newPos = SERVOMIN_S3003;
    }

    if (currentPos > SERVOMAX_S3003){
      currentPos = SERVOMAX_S3003;
    } else if (currentPos < SERVOMIN_S3003){
      currentPos = SERVOMIN_S3003:
    }
  }

  
}
