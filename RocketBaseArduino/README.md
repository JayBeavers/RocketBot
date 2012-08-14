# Rocket Base Arduino #

Rocket Base Arduino exposes commands to allow a host to control the RocketBot's launch plate over the Arduino's USB or UART (Serial) port by using the Reflecta protocol via the RBOT1 interface.

The commands exposed are:

- Animation (id): Display a visual and audible animation sequence
    - 0: Idle
    - 1: Moving
    - 2: Arming
    - 3: Armed
    - 4: Firing
    - 5: Fired
    - 6: Moving Disabled
- Fire(): Fire the rocket!
- Light(val): Manually set the warning light LED bitmask (1:Red, 2:Green, 4: Blue)
- Pan(angle)
- Tilt(angle)
- Compressor(on): '1' on, '0' off
- Valve(val): '0' both off, '2' valve 2 open, '4' valve 4 open

In addition, pin A0 is hooked to the pressure sensor which can be accessed via ARDU1.gpio.readAnalog.

To install this library, upload sketch RocketBaseArduino to your Arduino.  Note that you must first [install the Reflecta Arduino libraries](https://github.com/JayBeavers/Reflecta#getting-started).

To call this library, use the [Reflecta Node Client](https://github.com/JayBeavers/Reflecta/tree/master/NodeClient) library.  A simple example is:

    var devicePath = "/dev/ttyACM0"; // or "COM4" in Windows
    var Reflecta = require('reflecta.js');
    var reflecta = new Reflecta(devicePath, function(err) {
      reflecta.RBOT1.animation(4);
      reflecta.RBOT1.fire();
      reflecta.RBOT1.animation(5);
    });

### Future Work ###

- Create an integrated nodejs sample that maps an XBox GamePad to these methods like was used at Maker Faire.
- To be reworked for Rocket Bot v2.