#include <Arduino.h>
#include <Servo.h>
#include <Wire.h>
#include <ReflectaFramesSerial.h>
#include <ReflectaFunctions.h>
#include <ReflectaArduinoCore.h>

void setup()
{
  reflectaFrames::setup(9600);
  reflectaFunctions::setup();
  reflectaArduinoCore::setup();
  
  monsterMotoSetup();
}

void loop()
{
  reflectaFrames::loop();
}
