#include <LiquidCrystal.h>
#include <DallasTemperature.h>
#include <OneWire.h>
#include <pitches.h>

int humidityPin = A2;
int tempPin = 2;
int illuminancePin = A0;
int ledPin = 4;
int speakerPin = A3;
int pumpPin = 10; 

OneWire ourWire(tempPin);
DallasTemperature sensors(&ourWire);
LiquidCrystal lcd(44, 45, 46, 47, 48, 49);

void setup() {
  Serial.begin(9600);
  setting();
}

void loop() {
  autoHumidity();
  autoTemp();
  autoIlluminance();
  displayInfo();
  serialPrint();
  delay(1000);
}

void serialPrint(){
  Serial.print("습도(전압) : ");
  Serial.println(getHumidity());
  Serial.print("온도(섭씨) : ");
  Serial.println(getTemp());
  Serial.print("조도(전압) : ");
  Serial.println(getIlluminance());
  Serial.println();
}

void setting(){
  pinMode(humidityPin, INPUT);
  digitalWrite(humidityPin, HIGH);
  pinMode(tempPin, INPUT);
  digitalWrite(humidityPin, LOW);
  pinMode(illuminancePin, INPUT);
  digitalWrite(humidityPin, HIGH);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  pinMode(pumpPin, OUTPUT);
  digitalWrite(pumpPin, LOW);
  sensors.begin();
  lcd.begin(16,2);
  lcd.clear();
}

float getHumidity(){
  int reading = analogRead(humidityPin);
  float voltage = reading * 5.0 / 1024.0;
  return voltage;
}

float getTemp(){
  sensors.requestTemperatures();
  float temp_C = sensors.getTempCByIndex(0);
  return temp_C;
}

float getIlluminance(){
  int reading = analogRead(illuminancePin);
  float voltage = reading * 5.0 / 1024.0;
  return voltage;
}

void autoHumidity(){
  float voltage = getHumidity();
  
  if (voltage > 4){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("                ");
    lcd.setCursor(0,1);
    lcd.print("        Watering");
    delay(100);
    digitalWrite(pumpPin, HIGH);
    delay(2000);
    digitalWrite(pumpPin, LOW);
    lcd.clear();
  }
}

void autoTemp(){
  float temp_C = getTemp();
  boolean warning = false;
  float maxTemp = 40.0;
  float minTemp = 5.0;

  if(temp_C > maxTemp || temp_C < minTemp)
    warning = true;

  if(warning){
    tone(speakerPin, NOTE_A6, 1000);
    delay(1000);
    noTone(speakerPin);
  }
}

void autoIlluminance(){
  float voltage = getIlluminance();

  if(voltage > 4)
    digitalWrite(ledPin, LOW);
  else if(voltage < 2.5)
    digitalWrite(ledPin, HIGH);
  else
    analogWrite(ledPin, (1.0 - voltage/5.0)*1024);
}

void displayInfo(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("     Temp: ");
  lcd.print(getTemp());
  lcd.setCursor(0,1);
  lcd.print("      Hum: ");
  int humidity = map(analogRead(humidityPin),0,1024,100,0);
  lcd.print(humidity);
  lcd.write('%');
}
