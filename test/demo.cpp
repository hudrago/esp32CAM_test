// #include <Arduino.h>
// #include "esp32cam.h"

// static camera_config_t camera_config = {
//     .pin_pwdn = CAM_PIN_PWDN,
//     .pin_reset = CAM_PIN_RESET,
//     .pin_xclk = CAM_PIN_XCLK,
//     .pin_sscb_sda = CAM_PIN_SIOD,
//     .pin_sscb_scl = CAM_PIN_SIOC,

//     .pin_d7 = CAM_PIN_D7,
//     .pin_d6 = CAM_PIN_D6,
//     .pin_d5 = CAM_PIN_D5,
//     .pin_d4 = CAM_PIN_D4,
//     .pin_d3 = CAM_PIN_D3,
//     .pin_d2 = CAM_PIN_D2,
//     .pin_d1 = CAM_PIN_D1,
//     .pin_d0 = CAM_PIN_D0,
//     .pin_vsync = CAM_PIN_VSYNC,
//     .pin_href = CAM_PIN_HREF,
//     .pin_pclk = CAM_PIN_PCLK,

//     //XCLK 20MHz or 10MHz for OV2640 double FPS (Experimental)
//     .xclk_freq_hz = 20000000,
//     .ledc_timer = LEDC_TIMER_0,
//     .ledc_channel = LEDC_CHANNEL_0,

//     .pixel_format = PIXFORMAT_JPEG, //YUV422,GRAYSCALE,RGB565,JPEG
//     .frame_size = FRAMESIZE_VGA,    //QQVGA-UXGA Do not use sizes above QVGA when not JPEG

//     .jpeg_quality = 12, //0-63 lower number means higher quality
//     .fb_count = 1       //if more than one, i2s runs in continuous mode. Use only with JPEG
// };

// uint8_t *imgMatrix;

// void setup() {
//   Serial.begin(115200);
//   esp_err_t err = esp_camera_init(&camera_config);
// }

// void loop() {

//   sensor_t * s = esp_camera_sensor_get();
//   s->pixformat = PIXFORMAT_RGB565;
//   s->set_framesize(s, FRAMESIZE_VGA);
//   camera_fb_t * pic = esp_camera_fb_get();

//   Serial.println(pic->format);
//   Serial.println(pic->height);
//   Serial.println(pic->width);

//   // for (int i=0; i < pic->len; i++) {
//   //   Serial.println(pic->buf[i], HEX);
//   // }

//   // bool success = fmt2rgb888(pic->buf, pic->len, pic->format, imgMatrix);
//   // if(success) Serial.println("---------GOOD CONVERSION----------");

//   // for (int i=0; i < imgMatrix; i++) {
//   int i=0;
//   // while(imgMatrix) {
//   //   Serial.println(imgMatrix[i], HEX);
//   //   i++;
//   // }

//   // int n = 0;
//   // uint8_t *data = pic->buf;

//   // int r = 0;
//   // int c = 0;

//   // for (int n = 0; n < pic->len; n++) {
//   //   imgMatrix[r][c] = data[n];
//   //   if (c == 640) {
//   //     c = 0;
//   //     r++;
//   //   }
//   //   c++;
//   //   if (r == 480) {
//   //     break;
//   //   }
//   // }

//   // for (int r = 0; r < 480; r++) {
//   //   for (int c = 0; c < 640; c++) {
//   //     imgMatrix[c][r] = data[n];
//   //     n++;
//   //   }
//   // }  

//   // delay(5000);

//   Serial.println("--------");

// }