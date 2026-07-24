#include <LovyanGFX.hpp>
#include <SPI.h>

#include "core/Color.h"
#include "core/App.h"
#include "core/Theme.h"
#include "core/Graphics.h"
#include "core/TFTDisplay.h"
#include "core/FileManager.h"

#include "widgets/Screen.h"
#include "widgets/Button.h"
#include "widgets/Label.h"

#include "layouts/Column.h"

#define TFT_SCK 4
#define TFT_MOSI 6
#define TFT_MISO 5
#define TFT_CS 0

class LGFX : public lgfx::LGFX_Device
{
    lgfx::Panel_ILI9488 _panel;
    lgfx::Bus_SPI _bus;

public:
    LGFX()
    {
        {
            auto cfg = _bus.config();

            cfg.spi_host = SPI2_HOST;
            cfg.spi_mode = 0;

            cfg.freq_write = 40000000;
            cfg.freq_read = 16000000;

            cfg.pin_sclk = TFT_SCK;
            cfg.pin_mosi = TFT_MOSI;

            // TFT does not use MISO
            cfg.pin_miso = TFT_MISO;

            cfg.pin_dc = 2;

            _bus.config(cfg);
            _panel.setBus(&_bus);
        }

        {
            auto cfg = _panel.config();

            cfg.pin_cs = TFT_CS;
            cfg.pin_rst = 10;
            cfg.pin_busy = -1;

            cfg.memory_width = 320;
            cfg.memory_height = 480;

            cfg.panel_width = 320;
            cfg.panel_height = 480;

            cfg.offset_x = 0;
            cfg.offset_y = 0;

            cfg.invert = false;
            cfg.rgb_order = true;

            _panel.config(cfg);
        }

        setPanel(&_panel);
    }
};

Color white = {255, 255, 255};
Color black = {0, 0, 0};

Color bg = {30, 30, 30};
Color surface = {45, 45, 48};
Color blue = {0, 120, 215};
Color cyan = {0, 170, 255};
Color grey = {120, 120, 120};

SizeMetrics size_policy = {
    .button_height = 60,
    .title_bar_height = 48,
    .font_scale_factor = 2,
};

Theme appTheme = {
    .background = bg,
    .foreground = white,
    .primary = blue,
    .secondary = surface,
    .accent = cyan,
    .selection = {70, 110, 180},
    .selectionText = white,
    .disabled = grey};

FileManager file_manager;

LGFX tft;
TFTDisplay tft_display(
    480,
    320,
    &tft);

Graphics gfx(&tft_display, &size_policy);

App app(
    tft_display,
    gfx,
    &appTheme,
    &size_policy);

Screen home_screen(
    &tft_display,
    "# SYSTEM STATUS #");

Column root(
    0, size_policy.title_bar_height,
    tft_display.getWidth(),
    tft_display.getHeight() - size_policy.title_bar_height);

Button btn(120, 40, "Click Me", cyan, appTheme.selectionText);
Label label(120, 40, "Waiting for data", white);

int x = 0;

void setup()
{
    Serial.begin(115200);

    delay(500);

    file_manager.begin();

    Serial.println("BOOT");
    Serial.println(btn.y);
    Serial.println(root.y);
    Serial.println(size_policy.title_bar_height);

    // TFT
    tft.init();
    tft.setRotation(1);

    btn.setSizeMetrics(&size_policy);

    app.addScreen(home_screen);

    root.setSpacing(10);
    root.setContentSpacing(10);

    root.addChild(&label);
    root.addChild(&btn);
    home_screen.addChild(&root);

    app.goTo(
        tft_display,
        home_screen,
        gfx);

    Serial.println("READY");
}

void loop()
{
    if (Serial.available())
    {
        uint8_t cmd = Serial.read();

        Serial.println("got something");
        static char text[5];
        snprintf(text, sizeof(text), "%02X", cmd);
        label.setText("hello babe");
    }
    app.renderApp(gfx);
}