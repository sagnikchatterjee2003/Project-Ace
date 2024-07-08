#include <Wire.h>            // I2C Library

#include <BH1750.h>      // BH1750 (Light Sensor) Library

 

BH1750 lightMeter;          // Initialize the Sensor

const int led0 = 2;            // Initialize the Arduino Digital Pin 2 for LED 0

const int led1 = 3;            // Initialize the Arduino Digital Pin 3 for LED 1

const int led2 = 4;            // Initialize the Arduino Digital Pin 4 for LED 2

const int led3 = 5;            // Initialize the Arduino Digital Pin 5 for LED 3

 

/* The setup() function is called when a sketch starts. It is used to initialize variables, pin modes, start using libraries, etc. This function will only run once, after each power up or reset of the Arduino board */

 

void setup()

{

 

  Serial.begin(9600);       // Init Baud/Serial Rate

 

  // Initialize the I2C bus (BH1750 library doesn't do this automatically)

  Wire.begin();

  // On esp8266 you can select SCL and SDA pins using Wire.begin(D4, D3);

 

  lightMeter.begin(BH1750::ONE_TIME_HIGH_RES_MODE); // Select the working            


  Serial.println(F("BH1750 One-Time Test")); // Print the value of Sensor One-Time

  pinMode(led0, OUTPUT);       // Arduino Digital Pin 2 (LED 0) acts as Output Pin

  pinMode(led1, OUTPUT);       // Arduino Digital Pin 3 (LED 1) acts as Output Pin

  pinMode(led2, OUTPUT);       // Arduino Digital Pin 4 (LED 2) acts as Output Pin

  pinMode(led3, OUTPUT);       // Arduino Digital Pin 5 (LED 3) acts as Output Pin

}

 

/* This Particular Function is used for Repeated Execution of the Circuit until Specified. */

void loop()

{

  uint16_t lux = lightMeter.readLightLevel();           // Get the Lux Value from LED 0

  uint16_t lux1 = lightMeter.readLightLevel();         // Get the Lux Value from LED 1

  uint16_t lux2 = lightMeter.readLightLevel();         // Get the Lux Value from LED 2

  uint16_t lux3 = lightMeter.readLightLevel();         // Get the Lux Value from LED 3

 

  Serial.print("Light: ");                                           // Print Light:

  Serial.print(lux);                            // Print lux Value

  Serial.println(" lx");                        // Print lx in Next Line

  delay(100);                                   // Hold the program by 100 ms

 

  if (lux < 70)                                   // LED 0 will be High when Lux Value exceed 70 Luxens

    digitalWrite(led0, HIGH);           

  else                                              // LED 0 will be Low if Lux Value is less than 70 Luxens

    digitalWrite(led0, LOW);

 

 

  if (lux1 < 50)                                 // LED 1 will be High when Lux Value exceed 50 Luxens

    digitalWrite(led1, HIGH);

  else                                              // LED 1 will be Low when Lux Value is less than 50 Luxens

    digitalWrite(led1, LOW);

 

  if (lux2 < 25)                                 // LED 2 will be High when Lux Value exceed 25 Luxens

    digitalWrite(led2, HIGH);

  else                                              // LED 2 will be Low when Lux Value is less than 25 Luxens

    digitalWrite(led2, LOW); 

 

  if (lux3 < 10)                                 // LED 3 will be High when Lux Value exceed 10 Luxens

    digitalWrite(led3, HIGH);

  else                                              // LED 3 will be Low when Lux Value is less than 10 Luxens

    digitalWrite(led3, LOW);

}


