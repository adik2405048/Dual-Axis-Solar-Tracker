# Dual-Axis-Solar-Tracker
This system uses Light Dependent Resistors (LDRs) as inputs. The Arduino compares the light intensity from different angles and rotates two Servo Motors to keep the "Solar Panel" facing the sun directly.
Key Components Needed:
Arduino Uno R3
2 Servo Motors (One for horizontal/Azimuth, one for vertical/Elevation)
4 LDRs (Photoresistors)
4 10kΩ Resistors (For voltage divider circuits)
LCD 16 x 2 (I2C) (To display light intensity and coordinates)
Small Solar Panel (Optional, for demonstration)
1. The Logic (The "Brain")The system divides the 4 LDRs into Top, Bottom, Left, and Right pairs.
- Vertical Movement: If (Top Light > Bottom Light), move the vertical servo up.
- Horizontal Movement: If (Left Light > Right Light), move the horizontal servo left.
- Real-Time Feedback: The LCD displays the average "Lux" or brightness and the current angles of the servos.
2. Wiring Guide: Component- Arduino Pin Note- LDRs (4x) A0, A1, A2, A3 Connected via voltage dividers to detect light levels. Servo 1 (Horizontal) Digital Pin 9 Controls left/right rotation. Servo 2 (Vertical) Digital Pin 10 Controls up/down tilt. LCD (SDA/SCL)A4 / A5Standard I2C communication.
