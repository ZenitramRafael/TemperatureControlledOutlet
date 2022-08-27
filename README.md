# TemperatureControlledOutlet
ESP32 code for temperature controlled relay. An outlet controlled by the relay will have my window unit plugged in.

## Setup
There may be issues finding the headers for including libraries. The following steps helped me get things working in vscode.
1. Add the path of the library folder in c_cpp_properties include path.
'"includePath": [
                "${workspaceFolder}/**",
                "C:/Users/zenit/Documents/Arduino/libraries/DHT-sensor-library-master/"
            ]'
2. Go to File > Preferences > Settings > Extentions
    * In the Arduino settings add C:\Program Files (x86)\Arduino to Arduino: Path
    * In the C/C++ settings change the C_Cpp: Intelli Sense Enggine to Tag Parser

There are other projects in this repo used for development and testing individual parts.

## Other Projects
### DHT.ino
This is just for reading from the DHT11 sensor.

