#include <Arduino_MKRIoTCarrier.h>
MKRIoTCarrier carrier;

float temperature = 0;
float humidity = 0;

void setup()
{
  Serial.begin(9600);
  // Wait to open the Serial monitor to start the program and see details on errors
  while (!Serial)
    ;

  // Initialize the MKR IoT Carrier and output any errors in the serial monitor
  CARRIER_CASE = false;
  carrier.begin();
  carrier.display.setRotation(0);
}

void loop()
{
  // Read the sensor values
  temperature = carrier.Env.readTemperature();
  humidity = carrier.Env.readHumidity();

  // Update the touch buttons
  carrier.Buttons.update();

  // Print each of the sensor values
  Serial.print("Temperature = ");
  Serial.print(temperature);
  Serial.println(" C");

  Serial.print("Humidity = ");
  Serial.print(humidity);
  Serial.println(" %");

  // Function to print out the values
  if (carrier.Button0.onTouchDown())
  {
    printTemperature();
  }

  if (carrier.Button1.onTouchDown())
  {
    printHumidity();
  }
}

void printTemperature()
{
  //configuring display, setting background color, text size and text color
  carrier.display.fillScreen(ST77XX_RED);     //red background
  carrier.display.setTextColor(ST77XX_WHITE); //white text
  carrier.display.setTextSize(2);             //medium sized text

  carrier.display.setCursor(30, 110); //sets position for printing (x and y)
  carrier.display.print("Temp: ");
  carrier.display.print(temperature);
  carrier.display.println(" C");
}

void printHumidity()
{
  //configuring display, setting background color, text size and text color
  carrier.display.fillScreen(ST77XX_BLUE);    //red background
  carrier.display.setTextColor(ST77XX_WHITE); //white text
  carrier.display.setTextSize(2);             //medium sized text

  carrier.display.setCursor(30, 110); //sets new position for printing (x and y)
  carrier.display.print("Humi: ");
  carrier.display.print(humidity);
  carrier.display.println(" %");
}
