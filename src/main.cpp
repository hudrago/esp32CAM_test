#include "espcam.h"

uint16_t img_array [HEIGHT][WIDTH] = { 0 };

void setup() {
    Serial.begin(115200);
    Serial.println(setup_camera(FRAME_SIZE) ? "OK" : "ERR INIT");
}

void loop() {
    if (!capture_image()) {
        Serial.println("Failed capture");
        delay(2000);

        return;
    }

    //print_features();
    delay(3000);
}