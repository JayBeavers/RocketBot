#include <Arduino.h>
#include <Servo.h>
#include <ReflectaFramesSerial.h>
#include <ReflectaFunctions.h>

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

  pan.write(90);
  tilt.write(120);
  
  reflectaFrames::setup(9600);
  reflectaFunctions::setup();
  
  reflectaFunctions::bind("RBOT1", AnimationCommand);
  reflectaFunctions::bind("RBOT1", FireCommand);
  reflectaFunctions::bind("RBOT1", LightCommand);
  reflectaFunctions::bind("RBOT1", PanCommand);
  reflectaFunctions::bind("RBOT1", TiltCommand);
  reflectaFunctions::bind("RBOT1", CompressorCommand);
  reflectaFunctions::bind("RBOT1", ValveCommand);
}

void loop(){

  reflectaFrames::loop();
  sendHeartbeat();
  animationLoop();  
  delay(5); // Delay needed for animation loop timing
}
