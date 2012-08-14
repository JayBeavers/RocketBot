// Pins remapped to work with a Teensy

#define MOTOR_0_A 2 // 7
#define MOTOR_0_B 1 // 8
#define MOTOR_0_PWM 10 // 5
#define MOTOR_0_CURRENT 0 // 2
#define MOTOR_0_ENABLED 7 // 0

#define MOTOR_1_A 3 // 4
#define MOTOR_1_B 0 // 9
#define MOTOR_1_PWM 9 // 6
#define MOTOR_1_CURRENT 1 // 3
#define MOTOR_1_ENABLED 8 // 1

#define LED 11

void monsterMotoSetup()
{
  pinMode(MOTOR_0_A, OUTPUT);
  pinMode(MOTOR_0_B, OUTPUT);
  pinMode(MOTOR_0_PWM, OUTPUT);
  pinMode(MOTOR_0_ENABLED, OUTPUT);
  pinMode(MOTOR_1_A, OUTPUT);
  pinMode(MOTOR_1_B, OUTPUT);
  pinMode(MOTOR_1_PWM, OUTPUT);
  pinMode(MOTOR_1_ENABLED, OUTPUT);
  
  digitalWrite(MOTOR_0_A, LOW);
  digitalWrite(MOTOR_0_B, LOW);
  digitalWrite(MOTOR_1_A, LOW);
  digitalWrite(MOTOR_1_B, LOW);
  
  digitalWrite(MOTOR_0_ENABLED, HIGH);
  digitalWrite(MOTOR_1_ENABLED, HIGH);
  
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
  int16_t power0 = reflectaFunctions::pop16();
  int16_t power1 = reflectaFunctions::pop16();
  
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
  analogWrite(MOTOR_0_PWM, (uint8_t)abs(power0));
  
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
  analogWrite(MOTOR_1_PWM, (uint8_t)abs(power1));    
}

void ReadCurrent()
{
  reflectaFunctions::push16(analogRead(MOTOR_0_CURRENT));
  reflectaFunctions::push16(analogRead(MOTOR_1_CURRENT));
}