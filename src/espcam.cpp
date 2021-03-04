#include "espcam.h"

bool setup_camera(framesize_t frameSize) {
    camera_config_t config;

    config.ledc_channel = LEDC_CHANNEL_0;
    config.ledc_timer = LEDC_TIMER_0;
    config.pin_d0 = Y2_GPIO_NUM;
    config.pin_d1 = Y3_GPIO_NUM;
    config.pin_d2 = Y4_GPIO_NUM;
    config.pin_d3 = Y5_GPIO_NUM;
    config.pin_d4 = Y6_GPIO_NUM;
    config.pin_d5 = Y7_GPIO_NUM;
    config.pin_d6 = Y8_GPIO_NUM;
    config.pin_d7 = Y9_GPIO_NUM;
    config.pin_xclk = XCLK_GPIO_NUM;
    config.pin_pclk = PCLK_GPIO_NUM;
    config.pin_vsync = VSYNC_GPIO_NUM;
    config.pin_href = HREF_GPIO_NUM;
    config.pin_sscb_sda = SIOD_GPIO_NUM;
    config.pin_sscb_scl = SIOC_GPIO_NUM;
    config.pin_pwdn = PWDN_GPIO_NUM;
    config.pin_reset = RESET_GPIO_NUM;
    config.xclk_freq_hz = 20000000;
    config.pixel_format = PIXFORMAT_GRAYSCALE;
    config.frame_size = frameSize;
    config.jpeg_quality = 12;
    config.fb_count = 1;

    bool ok = esp_camera_init(&config) == ESP_OK;

    sensor_t *sensor = esp_camera_sensor_get();
    sensor->set_framesize(sensor, frameSize);

    return ok;
}



bool capture_image() {

    camera_fb_t * frame = NULL;
    frame = esp_camera_fb_get();

    print_image_shape(frame);

    frame_to_array(frame);

    esp_camera_fb_return(frame);

    if (!frame)
        return false;

    return true;
}


void print_image_shape(camera_fb_t * frame){

    // print shape of image and total length (=heigth*width)
    Serial.print("Width: ");
    Serial.print(frame->width);
    Serial.print("\tHeigth: ");
    Serial.print(frame->height);
    Serial.print("\tLength: ");
    Serial.println(frame->len);
}

void frame_to_array(camera_fb_t * frame){

    int len = frame->len;
    char imgBuffer[frame->len];
    int counter = 0;

    uint16_t img_array [HEIGHT][WIDTH] = { 0 };

    // write values from buffer into 2D Array

    for (int h=0; h < HEIGHT; h++){
        //Serial.println(h);
        for (int w=0; w < WIDTH; w++){
            //Serial.println(w);
            int position = h*(len/HEIGHT)+w;

            //Serial.println(position);
            img_array[h][w] = {frame->buf[position]};

            // Serial.print(img_array[h][w]);
            // Serial.print(",");
            // delay(2);

        }
    }

    Serial.println("Current frame:");

    Serial.println("=====================");

}