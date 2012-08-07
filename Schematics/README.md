# Hardware Schematics for RocketBot #

These are the design diagrams used to build the RocketBot prototype.

The base plate designs were created in Visio to be used on a laser cutter which had been tuned to work well with these settings (0 width lines, coloration for cut vs. raster).  These settings are different than what Ponoko wants so if you want to use that service to cut your plates some significant editing will be needed.

I loaded a few of these into AutoCAD 2013 (imports well) and InkScape (imports mostly intact).  I found Inkscape to do better with the SVG import than the dxf import so I've exported both formats.

The electronics design (.dsn file) was done using TinyCAD.  I didn't find an 'export to' in TinyCAD that was more portable so you'll need to use that app to read the file.

## Rocket Drive Base 4 ##

Base plate for the drive train for RocketBot.  I attached a Parallax drive train and two Parallax casters from an Eddie kit.  The empty front area held a Dell Mini-9 netbook running Windows 8, during the show we hotglued some straws to act as 'inside bumpers' to keep the netbook from sliding off the robot.  We added some zip ties and zip tie mounts to secure the battery.  We also found out the hard way that if you don't protect the Arduino's USB connector, hard use will strain and break the USB connection.

## Rocket Base 3 ##

Base plate for the rocket layer of RocketBot.  This was connected on top of Rocket Drive Base using the Eddie chassis spacers.  For the RTM release, we shifted the transistors down next to the air tank in order to shorten cable lengths.

We also found out the hard way that an Arduino mounted on the outside of the plate where the USB connector sticks out slightly is very bad -- at the end of the first day when I was quite tired I drove the robot into a pole on the left side and ripped off the USB connector, resulting in a hurried replacement of the Arduino from the Maker Shed.  RocketBot v2 has a laser cut 'cable holder' that takes all strain off the usb connectors.  I've also moved the Arduino (and all fragile components) inside the plate to get better crash protection.

## Rocket Electronics ##

This is a very simple diagram of the early circuits.  Much out of spec of what was finally produced.  Will rediagram for RocketBot v2.

## Pneumatic Prototype 1 ##

Layout of the pneumatic components.  In the final release I moved the analog pressure sensor to valve port 2 and removed the associated tee, otherwise pretty much unchanged.

## MARK 2 Drive Base v3 ##

A somewhat related project -- using most of the same components as RocketBot, add a centermount for an 8020 rod to make a 'human height' prototyping platform.  I did this work after seeing so many Parallax Eddies chopped up to remove their second platter and replace it with some type of height extension system.