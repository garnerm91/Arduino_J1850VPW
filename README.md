# Arduino_J1850VPW
This Arduino J1850VPW Project emulates (bit bangs) J1850 VPW 10.4Kb/s.  41.6 Kb/s PWM is not supported. It has been tested in Arduino IDE 2.2.4 on an atmega328P. Get started with the example "ino" file included in "src-j1850" folder. I don't take credit for the code; I only modified it to work how I wanted it to and to be compatible with the atmega328P.



## Credits
Inspiration was taken from the Macchina M2 hardware. https://github.com/macchina/m2-hardware?tab=readme-ov-file <br>
The code is from redheadedrod: https://github.com/redheadedrod/j1850/tree/master/M2_J1850_VPW I modified it to work on the atmega328 instead of due. (I think that is what they were using). I also changed the easy_send function to be memory-safe. I removed the "test" mode because it wasn't documented in the original API; I didn't want it to confuse users. I removed pin setting for J1850 PMW on the M2 since version of the module does not support that at a hardware level <br>

