# RocketBot #

RocketBot is a project to create a robot that uses an air compressor to launch straw rockets that was demonstrated at the 2012 Maker Faires in San Mateo CA and Seattle WA.  Its journey is chronicalled at http://jaybeavers.org.

----------

## RocketBaseArduino ##

RocketBaseArduino is the source code for the Arduino that controls the robot platform that runs the rocket launcher which includes an air compressor, a pan/tilt servo for the launcher, an industrial LED warning light, and a warning speaker.

RocketBaseArduino is controlled using a custom serial remoting protocol which sends down commands and receives a heartbeat of the current state every 200 ms.