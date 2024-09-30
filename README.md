# Arduino-GearShift-Indicator-with-16-Segment-LED-display
This is Arduino based gear shift indicator for manual transmission cars / H pattern gearshif 5 Speed N12345R

There are many people eager to know how to make GEAR POSITION INDICATOR / GEARSHIFT INDICATOR for REAL MANUAL TRANSMISSION CAR, so you landed here.

This GEARSHIFT POSITION INDICATOR based from GEAR LEVER movements, some people said this is H PATTERN GEAR POSITION.

WHY ARDUINO, it's cheap and easy to program,, and here the required to make GEARSHIFT POSITIONS.

The original design is from NIQRO3, and to suit my personal requirements i done many mods from original design version.

Original design is using 7 segment, anda i need my version is look DIFFER from original version, ENHANCED and SIMPLER so i adapted this to using 16 SEGMENT LED Display.


I Done searching to domestic online store, I CAN NOT FINDING FOR COMMON CHATODE type of the 16 segment display, so I MADE BIG MODS so program IS WORKING FOR COMMON ANODE.

Previous version i still using hex inverter IC to get working, now MORE SIMPLE GEAR POSITION INDICATOR ACHEIVED.

AS you can see from SCHEMATIC, this design is very simple, you CAN BUILD BY YOUR OWN.

NIQRO3 ARDUINO GEAR POSITION INDICATOR WORKING PRINCIPLE:
We have hall 7 magnets sensors, we have an Arduino as brain, and a 16 segment alphanumerical LED display Common Anode.
when we move gearshift lever, the movements will nearing magnets to trigger hall effect sensor according to its correct gear positions, and arduino will send the gear indicator to 16 segment display, as simple as that. 

We need an ARDUINO board, 7 pcs A3144 hall effect sensors, 7 pull-up 10k resistors, and an 16 Segment Alphanumeric LED display COMMON ANODE
ORIGINAL DESIGN IS 7 SEGMENT LED display COMMON CATHODE, so i done some tricks to get 14 SEGMENTS LED display derived from 16 Segment display

To transform 16 segments to 14 segments display is to joint: 
- digit a1+a2 to become digit a
- digit d1+d2 to become digit d
- digit g1+g2 to become digit 9

after that we need to 3 digits as adder to make 3 special characters for 1, N and R
so we need to activating digit k as 1 adder, digit n as R adder, and digit h as N adder.

original design is using 7 arrays as digit logics containers to created numbers and characters (only N, R and 1)
then we must convert to 14 arrays, more details please check it in Arduino sketch.

Arduino I/O addressing;
Input pins = 
A0 = gear N
A1 = gear 1
A2 = gear 2
A3 = gear 3
A4 = gear 4
A5 = gear 5
D12 = gear REVERSE
D13 = gear 5 BLINKING (optional usage, but i will prefer this as nice high speed indicator)

Output pins =
D3 = digit a
D4 = digit b
D5 = digit c
D3 = digit e
D4 = digit f
D5 = digit g
D3 = digit h / 1 adder
D4 = digit n / R adder
D5 = digit k / N adder

Instead using Arduino Board, i have to built this with Atmega8 with internal clock, which is cheaper and more eficient
on Atmega8c chip, the occupied program is only taken 17% dynamic memory.

everything is plain simple design, you can build by your own.







