#include <LovyanGFX.hpp>

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
            cfg.freq_read  = 16000000;

            cfg.pin_sclk = 4;
            cfg.pin_mosi = 6;
            cfg.pin_miso = 5;
            cfg.pin_dc   = 2;

            _bus.config(cfg);
            _panel.setBus(&_bus);
        }

        {
            auto cfg = _panel.config();

            cfg.pin_cs  = 0;
            cfg.pin_rst = 10;
            cfg.pin_busy = -1;

            cfg.memory_width  = 320;
            cfg.memory_height = 480;

            cfg.panel_width  = 320;
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

LGFX tft;

void setup()
{
    tft.init();
    tft.setRotation(1);

    tft.fillScreen(TFT_BLACK);

    tft.drawPixel(100, 100, TFT_RED);
    tft.drawLine(50, 50, 200, 200, TFT_GREEN);

    tft.setCursor(10, 10);
    tft.setTextColor(TFT_WHITE);
    tft.println("Hello NanoUI");
}

void loop()
{
}