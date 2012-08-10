// Pins remapped to work with a Teensy

#define MOTOR_0_A 8 // 7
#define MOTOR_0_B 6 // 8
#define MOTOR_0_PWM 9 // 5
#define MOTOR_0_CURRENT 2 // 2
#define MOTOR_0_ENABLED 0 // 0

#define MOTOR_1_A 7 // 4
#define MOTOR_1_B 5 // 9
#define MOTOR_1_PWM 10 // 6
#define MOTOR_1_CURRENT 3 // 3
#define MOTOR_1_ENABLED 1 // 1

#define LED 11

void monsterMotoSetup()
{
  pinMode(MOTOR_0_A, OUTPUT);
  pinMode(MOTOR_0_B, OUTPUT);
  pinMode(MOTOR_0_PWM, OUTPUT);
  pinMode(MOTOR_1_A, OUTPUT);
  pinMode(MOTOR_1_B, OUTPUT);
  pinMode(MOTOR_1_PWM, OUTPUT);
  
  digitalWrite(MOTOR_0_A, LOW);
  digitalWrite(MOTOR_0_B, LOW);
  digitalWrite(MOTOR_1_A, LOW);
  digitalWrite(MOTOR_1_B, LOW);
  
  reflectaFunctions::bind("MOTO1", BrakeGround);
  reflectaFunctions::bind("MOTO1", BrakeVcc);
  reflectaFunctions::bind("MOTO1", Drive);
  reflectaFunctions::bind("MOTO1", ReadCurrent);
}

void BrakeVcc()
{
  digitalWrite(MOTOR_0_A, HIGH);
  digitalWrite(MOTOR_0_B, HIGH);
  digitalWrite(MOTOR_1_A, HIGH);
  digitalWrite(MOTOR_1_B, HIGH);
  analogWrite(MOTOR_0_PWM, 0);
  analogWrite(MOTOR_1_PWM, 0);
}

void BrakeGround()
{
  digitalWrite(MOTOR_0_A, LOW);
  digitalWrite(MOTOR_0_B, LOW);
  digitalWrite(MOTOR_1_A, LOW);
  digitalWrite(MOTOR_1_B, LOW);
  analogWrite(MOTOR_0_PWM, 0);
  analogWrite(MOTOR_1_PWM, 0);
}

void Drive()
{
  int16_t power0 = reflectaFunctions::pop();
  int16_t power1 = reflectaFunctions::pop();
  
  if (power0 < 0)
  {
    digitalWrite(MOTOR_0_A, LOW);
    digitalWrite(MOTOR_0_B, HIGH);
  }
  else
  {
    digitalWrite(MOTOR_0_A, HIGH);
    digitalWrite(MOTOR_0_B, LOW);
  }
  analogWrite(MOTOR_0_PWM, abs(power0));
  
  if (power1 < 0)
  {
    digitalWrite(MOTOR_1_A, LOW);
    digitalWrite(MOTOR_1_B, HIGH);
  }
  else
  {
    digitalWrite(MOTOR_1_A, HIGH);
    digitalWrite(MOTOR_1_B, LOW);
  }
  analogWrite(MOTOR_1_PWM, abs(power1));    
}

void ReadCurrent()
{
  reflectaFunctions::push16(analogRead(MOTOR_0_CURRENT));
  reflectaFunctions::push16(analogRead(MOTOR_1_CURRENT));
}
