Version for the first Prototype in Tonis office.
Replaces the Arduino UNO Leonardo with an Arduino MKR Zero and MKR RS485 Shield.

Base Version for future development.
Configuration:
1x Hour
1x Minutes
13x Alphabetic letter

Known Issues of initial Clock
* The Circuitry can't move all letters at the same time due to insufficient power supply. Therefore going one by one in cascading mode with a delay.
* The code was concieved for a simple clock and was latter extended to add Letters (copy'n'paste mode).
* Initial model was based on an Arduino UNO Leonardo, which had limited Memory.
* Clock Setting with daylight changes could not be done by the user and needed reprogramming

Other Improvements
* Rework of the entire code. Not beautiful but working and easy to refactor now.
* Added two buttons for Time Programming (Minute + 1 and Hour +1)
* Added a button to activate/deactivate the Alphabetic letters