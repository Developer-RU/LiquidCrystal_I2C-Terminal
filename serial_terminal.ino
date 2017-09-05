#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

String val = "";
int ch = 0;

void setup()
{
    Serial.begin(9600);
    
    lcd.init();                     
    lcd.backlight();// Включаем подсветку дисплея
    lcd.print("SHOP-AVR.RU");
    lcd.setCursor(0, 1);
    lcd.print("p.masyukov@gmail.com");
}

void loop()
{
    
    if(Serial.available())
    {    
        delay(10);
           
        while(Serial.available())
        {
            val += (char)Serial.read();
        }

        lcd.clear();
        
        lcd.setCursor(0, 0);
        lcd.print("Data recive:");
        lcd.setCursor(0, 1);
        lcd.print(val);

        val = "";
    }
}
