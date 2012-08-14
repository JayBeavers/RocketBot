# Drive Base Teensy #

Drive Base Teensy exposes commands to allow a host to control a [Sparkfun Monster Moto Shield](https://www.sparkfun.com/products/10182) over the Arduino's USB or UART (Serial) port.

The commands exposed are:

- Drive (power0, power1): Turn on the motors using power levels from -255 to 255
- BrakeGround: Coast to a stop
- BrakeVcc: Hard brake using battery power to halt the drive shafts
- ReadCurrent: Read the current consumed by the motors

To install this library, upload sketch DriveBaseTeensy to your Arduino.  Note that you must first [install the Reflecta Arduino libraries](https://github.com/JayBeavers/Reflecta#getting-started).

To call this library, use the [Reflecta Node Client](https://github.com/JayBeavers/Reflecta/tree/master/NodeClient) library.  A simple example is:

    var devicePath = "/dev/ttyACM0"; // or "COM4" in Windows
    var Reflecta = require('reflecta.js');
    var reflecta = new Reflecta(devicePath, function(err) {
      reflecta.MOTO1.drive(75, 75);
      reflecta.MOTO1.brakeGround();
    });

### Future Work ###

- Add error checking for power levels
- Change Arduino PWM frequency -- default frequency is audible and annoying
- Add support for acceleration curves
- Add nodejs sample program that translatest joystick -> drive commands
- Add functions to allow dynamic pin configuration (e.g. you don't have to modify and recompile DriveBaseTeensy sketch to change which pins are used)
