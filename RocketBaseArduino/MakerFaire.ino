#include <Servo.h>

#define RedLight 9
#define GreenLight 10
#define BlueLight 11
#define ValveClosed 12
#define ValveOpen 13
#define Compressor 7
#define Speaker 8
#define PanServo 3
#define TiltServo 4
#define PressureSensor 0

Servo pan;
Servo tilt;

void setup() {

  pinMode(RedLight, OUTPUT);
  pinMode(GreenLight, OUTPUT);
  pinMode(BlueLight, OUTPUT);
  pinMode(ValveClosed, OUTPUT);
  pinMode(ValveOpen, OUTPUT);
  pinMode(Compressor, OUTPUT);
  pinMode(Speaker, OUTPUT);

  digitalWrite(RedLight, LOW);
  digitalWrite(GreenLight, LOW);
  digitalWrite(BlueLight, LOW);

  digitalWrite(ValveClosed, HIGH);
  digitalWrite(ValveOpen, LOW);
  digitalWrite(Compressor, LOW);

  delay(10);
  digitalWrite(ValveClosed, LOW);
 
  pan.attach(PanServo);
  tilt.attach(TiltServo);

  Serial.begin(9600);

  pan.write(90);
  tilt.write(120);
}

void loop(){

  checkForCommand();
  sendHeartbeat();

  animationLoop();  
  
  delay(5);
}

void checkForCommand()
{
  // Our commands consist of four bytes in the form of a SLIP message
  //   192 -- END marker
  //   ### -- Command Id
  //   ### -- Command Parameter
  //   192 -- END marker
  
  // We do not currently handle ESCape logic per SLIP as we use ASCII codes for our data and we never
  // Send a data byte with a value of 192
  
  if (Serial.available() >= 4) // Allow for a 2nd command coming in as this one is being processed
  {
    int start = Serial.read();
    while (start != 192 && Serial.available())
    {
      // We started with a corrupt or partial packet, clear out the buffer
      start = Serial.read();
    }
    
    if (!Serial.available())
    {
      // No valid packet was found
      return;
    }
    
    int commandId = Serial.read();
    while (commandId == 192 && Serial.available()) 
    {
      // We picked up the end character of a previous packet, so read until we find the first
      // data byte of the new packet
      commandId = Serial.read();
    }

    if (!Serial.available())
    {
      // No valid packet was found, just corrupt data
      return;
    }
    
    int parameter = Serial.read();
    int endMarker = Serial.read();
    if (endMarker != 192)
    {
      // Malformed packet, throw away the result
      return;
    }
    
    switch (commandId)
    {
      case 'a':
        AnimationCommand(parameter);
        break;
      case 'f':
        FireCommand(parameter);
        break;
      case 'l':
        LightCommand(parameter);
        break;
      case 'p':
        PanCommand(parameter);
        break;
      case 't':
        TiltCommand(parameter);
        break;
      case 'c':
        CompressorCommand(parameter);
        break;
      case 'v':
        ValveCommand(parameter);
        break;
    }
  }
}
