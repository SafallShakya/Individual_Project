
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);   // set the LCD address to 0x3F for a 16 chars and 2 line display

int inPin = 2;

unsigned long myTime;

const int buzzer = 7; void setup() {​​​​​

  pinMode(inPin, INPUT_PULLUP);

  pinMode(buzzer, OUTPUT);

  lcd.init();

  lcd.clear();

  lcd.backlight();      // Make sure backlight is on

  Serial.begin(9600);

}​​​​​

int normalBpm = 110;

long bpmTimer = 0;

long current = 0;

void loop() {​​​​​

  current = millis();

  // Read the value of the input. It can either be 1 or 0

  int buttonValue = digitalRead(inPin);

  if (buttonValue == LOW) {​​​​​

    lcd.clear();

    lcd.setCursor(0, 0);

    int high = random(120, 160);

    lcd.print((String)"BPM: " + high);

    Serial.print(high);

    lcd.setCursor(1, 1);  //Set cursor to character 2 on line 0

    lcd.print("Lie Detected");

    buzz();

    delay(1000);

    Serial.println(digitalRead(inPin));

  }​​​​​ else {​​​​​

    Serial.println(digitalRead(inPin));

    //    lcd.clear();

  }​​​​​

  lcd.setCursor(0, 0);

  if (current > bpmTimer + 1000) {​​​​​     normalBpm =  random(100, 120);

    bpmTimer = current;

  }​​​​​

  Serial.print(normalBpm);

  lcd.print((String)"BPM: " + normalBpm);

}​​​​​ 

void buzz() {​​​​​

  tone(buzzer, 5000); // Send 1KHz sound signal...

  delay(1000);        // ...for 1 sec

  noTone(buzzer);     // Stop sound...

  lcd.clear();

  lcd.setCursor(0, 0);

  lcd.print((String)"BPM: " + normalBpm);

  Serial.print(normalBpm);

  delay(1000);        // ...for 1sec

}​​​​​
