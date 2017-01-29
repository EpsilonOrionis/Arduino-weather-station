// Including the dht library used by the humidity/temperature sensor
#include <dht.h> 

// Including the LiquidCrystal library used by the LCD display
#include <LiquidCrystal.h>

// Defining the analog in used by the DHT sensor
#define dht_dpin A0

// Creating a DHT instance
dht DHT;

// Creating a LiquidCrystal instance
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  
  // Initialize the serial virtual output display
  Serial.begin(9600);
  
  // Inizialize the lcd instance
  lcd.begin(16, 2);
  
  // Let system settle
  delay(300);

  // Print in Serial display
  Serial.println("Humidity and temperature\n\n");
  
  // Wait rest of 1000ms recommended delay before accessing the sensor
  delay(700);
}

void loop() {
  
  //This is the "heart" of the sketch
  DHT.read11(dht_dpin);

  // Print the data received from the DHT sensor in the serial display
  Serial.print("Current humidity = ");
  Serial.print(DHT.humidity);
  Serial.print("%  ");
  Serial.print("temperature = ");
  Serial.print(DHT.temperature);
  Serial.println("C  ");
  // End

  // Now do the same thing for the LCD display
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(DHT.temperature);
  lcd.print(" ");
  lcd.print(char(223));
  lcd.print("C");
  lcd.setCursor(0, 1);
  lcd.print("Hum: ");
  lcd.print(DHT.humidity);
  lcd.print(" %");
  // End

  // Don't try to access too frequently.
  // Theoretically should be once per two seconds
  delay(2000);
}
