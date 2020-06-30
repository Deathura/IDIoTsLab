/***********************************
   Includes
 ***********************************/
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
// #include <time.h>

/***********************************
   DEFINE
 ***********************************/
#define SCREEN_I2C_ADDRESS 0x3F
#define SCREEN_LENGTH 16
#define SCREEN_HEIGHT 2

// #define P_SENSOR_1 1
// #define P_SENSOR_2 1
// #define P_SENSOR_3 1
// #define P_SENSOR_4 1
// #define P_SENSOR_5 1

#define READING_RATE 2000 // Temperature reading frequency (must be greater than 2 seconds (2000))


/***********************************
   Function declaration
 ***********************************/
void readAllTemperature();
void displayTemperature();
void initDisplay();


/***********************************
   Variable declaration
 ***********************************/
int nbSensor = 4;
int temperatures[4] = {-1, -1, -1, -1};

/***********************************
   Class initializatiion
 ***********************************/
LiquidCrystal_I2C lcd(SCREEN_I2C_ADDRESS, SCREEN_LENGTH, SCREEN_HEIGHT); // set the LCD address to 0x27 for a 16 chars and 2 line display


/***********************************
   Code
 ***********************************/
void setup(){
  Serial.begin(9600);
  Serial.println("Enter password: ");
  lcd.init();
  lcd.backlight();
  
  // lcd.setCursor(0, 0);
  // lcd.print("Hello IDIoTs !");
  // lcd.setCursor(0, 1);
  // lcd.print("Ready to beer ?");
  // delay(4000);

  initDisplay();
  delay(1000);
  displayTemperature();
}
  
void loop()
{
  // readAllTemperature();
  // displayTemperature();
  delay(READING_RATE); // DO NOT REMOVE
}

/***********************************
   Functions
 ***********************************/

void readAllTemperature()
{
  int temperature = -1;


  return temperature;
}

void displayTemperature()
{
  if (nbSensor == 0)
  {
    lcd.setCursor(0, 0);
    lcd.print("No sensor");
  }
  else
  {
    if (nbSensor > 4)
    {
      lcd.setCursor(0, 0);
      lcd.print("Too much sensor");
      lcd.setCursor(3, 1);
      lcd.print("Limit is 4...");
    }
    else
    {
      if (nbSensor >= 1)
      {
        lcd.setCursor(4, 0);
        lcd.print("   ");
        lcd.setCursor(4, 0);
        lcd.print(temperatures[0]);
      }
      if (nbSensor >= 2)
      {
        lcd.setCursor(12, 0);
        lcd.print("   ");
        lcd.setCursor(12, 0);
        lcd.print(temperatures[1]);
      }
      if (nbSensor >= 3)
      {
        lcd.setCursor(4, 1);
        lcd.print("   ");
        lcd.setCursor(4, 1);
        lcd.print(temperatures[2]);
      }
      if (nbSensor == 4)
      {
        lcd.setCursor(12, 1);
        lcd.print("   ");
        lcd.setCursor(12, 1);
        lcd.print(temperatures[3]);
      }
    }
  }
}

void initDisplay()
{
  lcd.clear();

  if (nbSensor == 0)
  {
    lcd.setCursor(0, 0);
    lcd.print("No sensor");
  }
  else
  {
    if (nbSensor > 4)
    {
      lcd.setCursor(0, 0);
      lcd.print("Too much sensor");
      lcd.setCursor(3, 1);
      lcd.print("Limit is 4...");
    }
    else
    {
      if (nbSensor >= 1)
      {
        lcd.setCursor(0, 0);
        lcd.print("T1: ---");
      }
      if (nbSensor >= 2)
      {
        lcd.setCursor(8, 0);
        lcd.print("T2: ---");
      }
      if (nbSensor >= 3)
      {
        lcd.setCursor(0, 1);
        lcd.print("T3: ---");
      }
      if (nbSensor == 4)
      {
        lcd.setCursor(8, 1);
        lcd.print("T4: ---");
      }
    }
  }
}