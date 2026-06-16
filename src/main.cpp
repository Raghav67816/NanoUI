#include <Wire.h>
#include <Adafruit_SH110X.h>

#include "esp_timer.h"
#include "esp_bt_main.h"

#include "core/Stack.h"
#include "core/Graphics.h"
#include "widgets/Screen.h"
#include "core/OLEDisplayX.h"
#include "layouts/Column.h"
#include "layouts/Row.h"
#include "widgets/Label.h"
#include "core/Color.h"

#define DISPLAY_WIDTH 128
#define DISPLAY_HEIGHT 64

#define SDA 8
#define SCK 4

#define BTN_RIGHT 1
#define BTN_OK 0
#define BTN_LEFT 10

Color white = {255, 255, 255};

Adafruit_SH1106G oled = Adafruit_SH1106G(
  DISPLAY_WIDTH, 
  DISPLAY_HEIGHT,
  &Wire,
  -1
);

OLEDisplayX display(
  DISPLAY_WIDTH,
  DISPLAY_HEIGHT,
  &oled
);

Graphics gfx(&display);

Stack app(display, gfx);
Screen home_screen(
  &display,
  "SYSTEM STATUS"
);
Column root_layout(0, 0, DISPLAY_WIDTH, DISPLAY_HEIGHT - 10);
Row temp_container(0, 0, DISPLAY_WIDTH, 20);
Row ble_container(40, 0, DISPLAY_WIDTH, 20);

Label itemp_label(20, 10, "Temp: ", white);
Label temp_val(10, 10, "0", white);

Label ble_label(10, 10, "BLE Status: ", white);
Label ble_stat(10, 10, "X", white);

Screen error_screen(
  &display,
  "Error"
);
Label error_val(DISPLAY_WIDTH - 10, 10, "ERROR", white);

Screen menu_screen(
    &display,
    "MENU"
);

char temp_buff[5];
char analog_buff[5];

void update_temp(void* arg){
  float temp = temperatureRead();
  temp_val.setText(dtostrf(temp, 1, 2, temp_buff));
}

const esp_timer_create_args_t tpt_config = {
  .callback = update_temp,
  .arg = nullptr,
  .dispatch_method = ESP_TIMER_TASK,
  .name = "temp_proc_timer",
  .skip_unhandled_events = true
};

esp_timer_handle_t temp_timer = NULL;

void setup(){
  Serial.begin(115200);
  Wire.begin(SDA, SCK);
  Wire.setClock(400000);

  pinMode(BTN_OK, INPUT_PULLUP);
  pinMode(BTN_RIGHT, INPUT_PULLUP);
  pinMode(BTN_LEFT, INPUT_PULLUP);

  temp_container.addChild(&itemp_label);
  temp_container.addChild(&temp_val);

  ble_container.addChild(&ble_label);
  ble_container.addChild(&ble_stat);

  root_layout.addChild(&ble_container);
  root_layout.addChild(&temp_container);
  home_screen.addChild(&root_layout);

  app.addScreen(home_screen);
  app.addScreen(error_screen);
  app.addScreen(menu_screen);

  esp_err_t _ttemp = esp_timer_create(&tpt_config, &temp_timer);
  esp_timer_start_periodic(temp_timer, 1000000);
  
  if(!oled.begin(0x3C, true)){
    while(1);
  }

  if(!esp_timer_init() == ESP_OK){
    app.goTo(display, error_screen, gfx);
    error_val.setText("ESP Timer Failed");
  }

  oled.setTextSize(2);

  display.clear();
  app.goTo(display, home_screen, gfx);
  display.flush();
}


void loop(){
  app.renderApp(gfx);

  if(digitalRead(BTN_OK) == LOW){
    ble_stat.setText("pressed");
    if(app.getActiveScreen() == &home_screen){
        app.goTo(display, menu_screen, gfx);
    }
  }

  display.flush();
}