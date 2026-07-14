#include <LovyanGFX.hpp>

#include "core/Color.h"
#include "core/Stack.h"
#include "core/Theme.h"
#include "core/Graphics.h"
#include "core/TFTDisplay.h"

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

            cfg.pin_sclk = 4;
            cfg.pin_mosi = 6;
            cfg.pin_miso = 5;
            cfg.pin_dc = 2;

            _bus.config(cfg);
            _panel.setBus(&_bus);
        }

        {
            auto cfg = _panel.config();

            cfg.pin_cs = 0;
            cfg.pin_rst = 10;
            cfg.pin_busy = -1;

            cfg.memory_width = 320;
            cfg.memory_height = 480;

            cfg.panel_width = 320;
            cfg.panel_height = 480;

            cfg.offset_x = 0;
            cfg.offset_y = 0;

            cfg.invert = false;
            cfg.rgb_order = false;

            _panel.config(cfg);
        }

        setPanel(&_panel);
    }
};

Color white = {255, 255, 255};
Color black = {0, 0, 0};

Theme appTheme = {
    .background = black,
    .foreground = white,
    .primary = white,
    .secondary = black,
    .accent = white,
    .selection = white,
    .selectionText = black,
    .disabled = black
};

LGFX tft;
TFTDisplay tft_display(480, 320, &tft);

Graphics gfx(&tft_display);
Stack app(tft_display, gfx, &appTheme);

Screen home_screen(
    &tft_display,
    "SYSTEM STATUS"
);

void setup()
{
    tft.init();
    tft.setRotation(1);
    
    app.addScreen(home_screen);

    tft_display.clear();
    app.goTo(tft_display, home_screen, gfx);
    tft_display.flush();
}

void loop()
{
    app.renderApp(gfx);
    tft_display.flush();
}