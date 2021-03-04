#include <Arduino.h>
#include "esp_camera.h"
#include "camera_pins.h"

#define FRAME_SIZE FRAMESIZE_QQVGA
#define WIDTH 160
#define HEIGHT 120 

bool setup_camera(framesize_t);
void frame_to_array(camera_fb_t * frame);
void print_image_shape(camera_fb_t * frame);
bool capture_image();