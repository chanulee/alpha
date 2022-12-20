# Alpha: Wearable interface for Sunny Day
## Spec
### Hardware
Check out fritzing file for more information.
- ESP32 Dev Module (3.3V)
- ILI9341 TFT LCD Display
- Flex Sensor
- Lilypad Vide Board
- ~~Qwiic Haptic Driver DA7280~~
### Power Module
- 18650 Li-ion Battery
- Li-ion power module
- DC/DC Stepup module
- Toggle switch
### Software Requirements
- Modified TFT_eSPI library 
- Library for Qwiic 6DoF Gyro/Acc LSM6DSO
## Features
- Bluetooth Serial (Send and receive data) [[1]](#1)
- Get flex sensor angle value [[2]](#2)
- LCD display control [[3]](#3)
- Haptic feedback [[4]](#4)
## References
1. <a name="1" href="https://randomnerdtutorials.com/esp32-bluetooth-classic-arduino-ide/" target="_blank">Bluetooth Serial for ESP32</a>
2. <a name="2" href="https://learn.sparkfun.com/tutorials/flex-sensor-hookup-guide?_ga=2.13438583.1502922294.1671452785-154993728.1671452785" target="_blank">Flex sensor hookup guide</a> 
3. <a name="3" href="https://www.youtube.com/watch?v=rq5yPJbX_uk" target="_blank">TFT LCD Display</a>
3-1. TFT_eSPI library (by bodmer) modified for ILI9341 and ESP32 (this project) [Go to repo](https://github.com/chanulee/TFT_eSPI)
4. <a name="4">Haptic Feedback using LilyPad Vibe Board</a>
## Memo / Trial & Error
- Set to ESP32 Dev Module in IDE.
- Button on right side of the microusb port should be pressed when uploading code. Press the other button to reboot after uploading.
- You should set COM port as "send" on the device when you connect to ESP32 (Windows).
- Quit openFrameworks app (ofApp) that gets serial data before uploading data to ESP32.
- Haptic feedback of LilyPad Vibe Board feels a little bit weak on wrist. But still stronger than Qwiic Haptic Driver DA7280.
- [Qwiic 6DoF Gyro/Acc LSM6DSO library](https://learn.sparkfun.com/tutorials/qwiic-6dof-lsm6dso-breakout-hookup-guide) and [Qwiic Haptic Driver DA7280 library](https://learn.sparkfun.com/tutorials/qwiic-haptic-driver-da7280-hookup-guide?_ga=2.22013947.1502922294.1671452785-154993728.1671452785) crashes on arduino ide
## Acknowledgement
The project [Sunny Day](https://ssk7808.github.io/sunnyday/) was funded by [National Research Foundation Korea](https://www.nrf.re.kr/eng/index) as University Innovation program, 2022
