/*
 ___ ___   _____ __    _  _ __  _ _____ _ _     __ ___  __  _  _____ __  _  
| __| \ \_/ | __| _\  | || |  \| |_   _| | |   |  | _ \/__\| |/ | __|  \| | 
| _|| |> , <| _|| v | | \/ | | ' | | | | | |_  | -| v | \/ |   <| _|| | ' | 
|_| |_/_/ \_|___|__/   \__/|_|\__| |_| |_|___| |__|_|_\\__/|_|\_|___|_|\__| 
2025
Example usage of J1850-VPW. This example only uses the easy_send and accept funtion. the API does have more functions. please refer to the API guide on github.
J1850-VPW.cpp and J1850-VPW.h need to be in the same folder as the .ino.
*/

// Define J1850 pins (default are 8/9 but you can change that)
#define J1850_VPW_RX 8
#define J1850P_TX 9

#include "J1850-VPW.h"


j1850 vpw; // Instantiate the J1850 object
byte rx_buf[MAX_MESSAGE_SIZE]; // frame buffer

void setup() {
    Serial.begin(115200);
    while (!Serial) {
        ;
    }
    Serial.println("Initializing J1850 VPW...");
    vpw.init(J1850_VPW_RX, J1850P_TX, true); // Initialize the J1850 VPW module and Enable monitoring (review mode)
    Serial.println("J1850 VPW initialized.");
    
    vpw.easy_send(6, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06); // sends 1 frame as an example at setup
}

void loop() {
   if (vpw.accept(rx_buf)) { 
    //Checks for Traffic, will print since monitor is on
        vpw.easy_send(4, 0x01, 0x01, 0x01, 0xFF); // sends a reply if it recieved any data
    //  Tx buffer is printed since monitor is on
   }
}
/*
       vpw.easy_send(msg length, H1, H2, H3, DD, DD, DD, DD, DD, DD, DD, DD)
       msg length is the number of bytes
       H1 = header byte 1 message priority
       H2 = header byte 2 destination
       H3 = header byte 3 source
       DD = message with maximum 8 bytes.
*/