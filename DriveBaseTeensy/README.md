# Drive Base Teensy #

Drive Base Teensy exposes commands to allow a host to control a [Sparkfun Monster Moto Shield](https://www.sparkfun.com/products/10182) over the Arduino's USB or UART (Serial) port.

The commands exposed are:

- BrakeGround: Coast to a stop
- BrakeVcc: Hard brake using battery power to halt the drive shafts
- Drive (power0, power1): Turn on the motors using power levels from 0-255
- ReadCurrent: Read the current consumed by the motors

To call this library, use [Reflecta Functions](https://github.com/JayBeavers/Reflecta/tree/master/ReflectaFunctions) from the [Node Client](https://github.com/JayBeavers/Reflecta/tree/master/NodeClient) library.


