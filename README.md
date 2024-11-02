# Alpha: Wearable interface for Sunny Day
## 1. Description
<img src="https://portfolio-22.s3.ap-northeast-2.amazonaws.com/sunny-day/g9.jpg" width="50%" height="50%"></img>
<img src="https://videoapi-muybridge.vimeocdn.com/animated-thumbnails/image/cef793c1-7950-4966-b035-7af2e2b043bc.gif?ClientID=vimeo-core-prod&Date=1671889643&Signature=d84e1faf919617460a0c30617b19494490326d85" width="50%" height="50%"></img>
More capable version [hapgrab](https://github.com/chanulee/hapgrab)
## 2. Features
- Bluetooth Serial (Send and receive data) [[1]](#1)
- Get flex sensor angle value [[2]](#2)
- LCD display control [[3]](#3)
- Haptic feedback [[4]](#4)
## 3. Specimen
### 3-1. Hardware
Check out fritzing file for more information.
- ESP32 Dev Module (3.3V)
- ILI9341 TFT LCD Display
- Flex Sensor
- Lilypad Vide Board
- ~~Qwiic Haptic Driver DA7280~~
### 3-2. Power Module
- 18650 Li-ion Battery
- Li-ion power module
- DC/DC Stepup module
- Toggle switch
### 3-3. Software Requirements
- TFT_eSPI library (by bodmer) modified for ILI9341 and ESP32 (this project) [Go to repo](https://github.com/chanulee/TFT_eSPI)
## 4. References
1. Bluetooth Serial for ESP32 <a name="1" href="https://randomnerdtutorials.com/esp32-bluetooth-classic-arduino-ide/" target="_blank">Tutorial</a>
2. Flex sensor <a name="2" href="https://learn.sparkfun.com/tutorials/flex-sensor-hookup-guide?_ga=2.13438583.1502922294.1671452785-154993728.1671452785" target="_blank">Hookup Guide</a> 
3. TFT LCD Display <a name="3" href="https://www.youtube.com/watch?v=rq5yPJbX_uk" target="_blank">Tutorial Video</a>  
4. <a name="4">Haptic Feedback using LilyPad Vibe Board</a>
## 5. Memo / Trial & Error
- Set to ESP32 Dev Module in IDE.
- Button on right side of the microusb port should be pressed when uploading code. Press the other button to reboot after uploading.
- You should set COM port as "send" on the device when you connect to ESP32 (Windows).
- Quit openFrameworks app (ofApp) that gets serial data before uploading data to ESP32.
- Haptic feedback of LilyPad Vibe Board feels a little bit weak on wrist. But still stronger than Qwiic Haptic Driver DA7280.
- [Qwiic 6DoF Gyro/Acc LSM6DSO library](https://learn.sparkfun.com/tutorials/qwiic-6dof-lsm6dso-breakout-hookup-guide) and [Qwiic Haptic Driver DA7280 library](https://learn.sparkfun.com/tutorials/qwiic-haptic-driver-da7280-hookup-guide?_ga=2.22013947.1502922294.1671452785-154993728.1671452785) crashes on arduino ide
## Acknowledgement
The project [Sunny Day](https://ssk7808.github.io/sunnyday/) was funded by [National Research Foundation Korea](https://www.nrf.re.kr/eng/index) as University Innovation program, 2022
