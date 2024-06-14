# Arduino Moisture and Temperature Logger

This project logs data from Arduino-connected moisture and temperature sensors. It also controls an LED based on moisture levels and includes a Python script to save the logged data.
It was built to be energy-efficient and relatively scalable.

<p align="center">
  <img src="https://github.com/malasiaa/arduino_temp-moist_sensing/assets/144847430/dac9f37d-082f-4541-9053-d377375ca0bf" width="400" height="200">
</p>

## Overview

The Arduino board reads data from a moisture sensor connected to analog pin A2 and a DS18B20 temperature sensor connected to digital pin 2. It logs this data periodically and controls an LED connected to digital pin 7 based on the moisture level. 

A Python script (import_serial.py) is used to log data received from the Arduino over serial communication. This script saves the data to a text file (serial_log_XXXXX.txt) in the project directory for further analysis.

The sketch was done on VS Code IDE with PlatformIO extension, with the config file [platformio.ini](https://github.com/malasiaa/arduino_temp-moist_sensing/blob/main/platformio.ini).

#### Components Used:

- Arduino Uno
- [Moisture sensor](https://pt.aliexpress.com/item/1005005850226701.html?src=google&src=google&albch=shopping&acnt=631-313-3945&slnk=&plac=&mtctp=&albbt=Google_7_shopping&gclsrc=aw.ds&albagn=888888&isSmbAutoCall=false&needSmbHouyi=false&src=google&albch=shopping&acnt=631-313-3945&slnk=&plac=&mtctp=&albbt=Google_7_shopping&gclsrc=aw.ds&albagn=888888&ds_e_adid=&ds_e_matchtype=&ds_e_device=c&ds_e_network=x&ds_e_product_group_id=&ds_e_product_id=pt1005005850226701&ds_e_product_merchant_id=714077654&ds_e_product_country=PT&ds_e_product_language=pt&ds_e_product_channel=online&ds_e_product_store_id=&ds_url_v=2&albcp=19821743728&albag=&isSmbAutoCall=false&needSmbHouyi=false&gad_source=1&gclid=Cj0KCQjwsaqzBhDdARIsAK2gqnel73fjUh3SDu0RLmFOSAa4asHcbVaHX0Ow_upGJQZjeLhLqr3grxMaAoQJEALw_wcB&aff_fcid=fc06bc6397a8436999ff669084a5dd21-1718322073508-03996-UneMJZVf&aff_fsk=UneMJZVf&aff_platform=aaf&sk=UneMJZVf&aff_trace_key=fc06bc6397a8436999ff669084a5dd21-1718322073508-03996-UneMJZVf&terminal_id=bec40578c234405895a1646236025a60&afSmartRedirect=y)
- [DS18B20 temperature sensor](https://pt.aliexpress.com/item/1005006033037308.html?src=google&src=google&albch=shopping&acnt=708-803-3821&slnk=&plac=&mtctp=&albbt=Google_7_shopping&gclsrc=aw.ds&albagn=888888&isSmbAutoCall=false&needSmbHouyi=false&src=google&albch=shopping&acnt=708-803-3821&slnk=&plac=&mtctp=&albbt=Google_7_shopping&gclsrc=aw.ds&albagn=888888&ds_e_adid=&ds_e_matchtype=&ds_e_device=c&ds_e_network=x&ds_e_product_group_id=&ds_e_product_id=pt1005006033037308&ds_e_product_merchant_id=462057946&ds_e_product_country=PT&ds_e_product_language=pt&ds_e_product_channel=online&ds_e_product_store_id=&ds_url_v=2&albcp=19373920468&albag=&isSmbAutoCall=false&needSmbHouyi=false&gad_source=1&gclid=Cj0KCQjwsaqzBhDdARIsAK2gqnfa4gNt-UW1cTm-RV5VMjyzDqmsu_7eQUtRoAG980UtEPRyHU4o-ncaApymEALw_wcB&aff_fcid=44528f397d644ebbb91f3ead20c17dab-1718321434231-05686-UneMJZVf&aff_fsk=UneMJZVf&aff_platform=aaf&sk=UneMJZVf&aff_trace_key=44528f397d644ebbb91f3ead20c17dab-1718321434231-05686-UneMJZVf&terminal_id=bec40578c234405895a1646236025a60&afSmartRedirect=y)
- Red LED

#### Circuit Design:
(Approximation, the actual design can be found in the [images](https://github.com/malasiaa/arduino_temp-moist_sensing/tree/main/images) folder)
<p align="center">
  <img src="https://github.com/malasiaa/arduino_temp-moist_sensing/assets/144847430/e03636df-7743-466f-9e67-a7184479d100" width="400" height="400">
</p>

#### Arduino Setup:

1. Connect the AO port from the moisture sensor to analog pin A2, respective GND, and VCC.
2. Connect the DS18B20 temperature sensor to GND and VCC, before connecting the signal output wire (yellow) to the digital pin 2, connect a resistor from VCC to the signal output - digital pin connection. 
3. Connect a red LED cathode to GND via a resistor and anode to digital pin 7.
4. Upload the ketch ([main.cpp](https://github.com/malasiaa/arduino_temp-moist_sensing/blob/main/main.cpp)) to the Arduino board.

## Setup Instructions

1. **Clone the repository:**

   ```bash
   git clone https://github.com/malasiaa/arduino_temp-moist_sensing
   ```
2. **Create a virtual environment:**
   
   ```bash
   python -m venv venv
   source venv/bin/activate
   ```
3. **Install the required dependencies:**
   ```bash
   pip install -r requirements.txt
   ```

4. **Run the script:**
  Assuming you have done everything before, and you have the board plug to your computer.
   ```bash
   python import_serial.py
   ```

