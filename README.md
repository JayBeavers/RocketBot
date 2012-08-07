# RocketBot #

RocketBot is a project to create a robot that uses an air compressor to launch straw rockets that was demonstrated at the 2012 Maker Faires in San Mateo CA and Seattle WA.  Its journey is chronicalled at [http://jaybeavers.org](http://jaybeavers.org).

----------

## [RocketBaseArduino](https://github.com/JayBeavers/RocketBot/tree/master/RocketBaseArduino) ##

RocketBaseArduino is the source code for the Arduino that controls the robot platform that runs the rocket launcher which includes an air compressor, a pan/tilt servo for the launcher, an industrial LED warning light, and a warning speaker.

RocketBaseArduino is controlled using the [Reflecta](https://github.com/JayBeavers/Reflecta) remoting protocol.  RocketBaseArduino implements the 'RBOT1' interface which controls animations (lights and sounds), pan/tilt servos of the rocket launcher, and compressor and valves of the pneumatic system.  The PC receives a heartbeat of the current state of the robot every 200 ms.

The PC-side source code has not been published.  I've switched from a C#/XNA application to a [nodejs client](https://github.com/JayBeavers/Reflecta/tree/master/NodeClient) but the port is not yet complete.  The previous application used XBox Wireless Controller buttons to switch between animations and initiate launch and the thumb stick to drive the servos.

## [DriveBaseTeensy](https://github.com/JayBeavers/RocketBot/tree/master/DriveBaseTeensy) ##

DriveBaseTeensy is the source code for the [Teensy (Arduino-compatible board)](http://www.pjrc.com/teensy/) and [SparkFun Monster Moto Shield](https://www.sparkfun.com/products/10182) system that runs the RocketBot drive train.

Like RocketBaseArduino, the PC-side source code has not been published due to a switch from C#/XNA over to nodejs.  The previous application used an XBox Wireless Controller thumbstick to control the drive train.  The logic behind this control was subject to much hacking over the course of Maker Faire as I adjusted the acceleration curve, turn rate, etc. to make the robot deftly controllable through the heavy crowds.

## [Schematics](https://github.com/JayBeavers/RocketBot/tree/master/Schematics) ##

I've uploaded the diagrams I used with a lasercutter to make the RocketBot plates.  There's also a layout of the pneumatic parts and an early draft of the power system used to enable the Arduino to control high current 12v components such as the compressor, industrial warning light, and pneumatic valves.

## [Parts List](PartsList.md) ##

List of parts used to create RocketBot