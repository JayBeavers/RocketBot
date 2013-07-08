# Rocket Base Arduino #

Rocket Base Arduino exposes commands to allow a host to control the RocketBot's launch plate over the Arduino's USB or UART (Serial) port by using the Reflecta protocol via the rbot1 interface.

The commands exposed are:

- animation (id): Display a visual and audible animation sequence
    - 0: Idle
    - 1: Moving
    - 2: Arming
    - 3: Armed
    - 4: Firing
    - 5: Fired
    - 6: Moving Disabled
- fire(): Fire the rocket!
- light(val): Manually set the warning light LED bitmask (1:Red, 2:Green, 4: Blue)
- pan(angle)
- tilt(angle)
- compressor(on): '1' on, '0' off
- valve(val): '0' both off, '2' valve 2 open, '4' valve 4 open

In addition, pin A0 is hooked to the pressure sensor which can be accessed via ardu1.analogRead.

To install this library, upload sketch RocketBaseArduino to your Arduino.  Note that you must first [install the Reflecta Arduino libraries](https://github.com/JayBeavers/Reflecta#getting-started).

To call this library, use the [Reflecta Node Client](https://github.com/JayBeavers/Reflecta/tree/master/NodeClient) library.  A simple example is:

    var devicePath = "/dev/ttyACM0"; // or "COM4" et al in Windows
    var Reflecta = require('reflecta');
    var reflecta = new reflecta.Board(devicePath, function(err) {
      reflecta.rbot1.animation(4);
      reflecta.rbot1.fire();
      reflecta.rbot1.animation(5);
    });

## Release History

- 0.1.0: Initial release
- 0.1.1: Updated with changes to Reflecta and ardu1

### Future Work ###

- Convert custom heartbeat code over to Reflecta's new hart1 approach like in BasicIMU.ino
- Create an integrated nodejs sample that maps an XBox GamePad to these methods like was used at Maker Faire.
- To be reworked for Rocket Bot v2.