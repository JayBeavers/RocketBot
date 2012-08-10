#include <Arduino.h>
#include <ReflectaFramesSerial.h>
#include <ReflectaFunctions.h>

void setup()
{
  reflectaFrames::setup(9600);
  reflectaFunctions::setup();
  
  monsterMotoSetup();
}

void loop()
{
  reflectaFrames::loop();
}