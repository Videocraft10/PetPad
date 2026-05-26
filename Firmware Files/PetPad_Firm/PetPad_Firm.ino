// Buttons
#define BTN1 0 // SW1 -> MCU Pin 1 -> GPIO0
#define BTN2 1 // SW2 -> MCU Pin 2 -> GPIO1
#define BTN3 2 // SW3 -> MCU Pin 3 -> GPIO2

// I2C OLED
#define SDA_PIN 22 // OLED SDA -> MCU Pin -> GPIO22
#define SCL_PIN 23 // OLED SCL -> MCU Pin -> GPIO23

// Buzzer
#define BUZZER 18 // Buzzer Signal -> MCU Pin 11 -> GPIO18

// Includes and Hardware Config
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define BTN_LEFT D0
#define BTN_MIDDLE D1
#define BTN_RIGHT D2
#define BUZZER_PIN D10

struct Pet {
  int hunger; // 0 to 200 (0 = starving, 100 = full, 200 = overfed)
  int love; // 0 to 100 (0 = depressed, 25 = sad, 50 = nutrual, 75 = happy, 100 = best day ever!)
  int energy; // 0 to 200 (0 = exhausted, 100 = full, 200 = hyper)
  int life; // -100 to 100 (-100 = undead, 0 = death imminet, 100 = healthy)
  unsigned long age; // total seconds Pet has lived

};

Pet pet;

enum Screen {
  SCREEN_MAIN,
  SCREEN_FEED,
  SCREEN_PLAY,
  SCREEN_SLEEP,

};

Screen currentScreen = SCREEN_MAIN;

void setup() {
  // put your setup code here, to run once:
  pinMode (BTN_LEFT, INPUT_PULLUP);
  pinMode (BTN_MIDDLE, INPUT_PULLUP);
  pinMode (BTN_RIGHT, INPUT_PULLUP);
  pinMode (BUZZER_PIN, OUTPUT);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("PetPad is loading...");
  display.display();
  delay(1000);

  pet.hunger = 80;
  pet.love = 50;
  pet.energy = 80;
  pet.life = 100;
  pet.age = 0;
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
}

unsigned long lastUpdate = 0;

void updatePet() {
  if (millis() - lastUpdate > 5000) { //every 5 sec
    pet.hunger --;
    pet.energy --;
    pet.love --;
  
    if (pet.hunger < 0) pet.hunger = 0;
    if (pet.energy < 0) pet.energy = 0;
    if (pet.love < 0) pet.love = 0;
  
    pet.age += 5;
    lastUpdate = millis();
  }
 
}

unsigned long lastButtonPress = 0;

void checkButtons() {
  if (millis() - lastButtonPress < 200) return; // debounce: ignore button presses within 200ms of each other
  if (digitalRead(BTN_LEFT) == LOW) {
    currentScreen = SCREEN_FEED;
    tone(BUZZER_PIN, 1000, 50);
    lastButtonPress = millis();
  } 
  else if (digitalRead(BTN_MIDDLE) == LOW) {
    currentScreen = SCREEN_PLAY;
    tone(BUZZER_PIN, 1500, 50);
    lastButtonPress = millis();
  } 
  else if (digitalRead(BTN_RIGHT) == LOW) {
    currentScreen = SCREEN_SLEEP;
    tone(BUZZER_PIN, 500, 50);
    lastButtonPress = millis();
  }
}

void handleScreenLogic() {
  switch (currentScreen) {

    case SCREEN_FEED:
      pet.hunger += 10;
      if (pet.hunger > 200) pet.hunger = 200;
      currentScreen = SCREEN_MAIN;
      break;

    case SCREEN_PLAY:
      pet.love += 10;
      pet.energy -= 5;
      if (pet.love > 100) pet.love = 100;
      if (pet.energy < 0) pet.energy = 0;
      currentScreen = SCREEN_MAIN;
      break;

    case SCREEN_SLEEP:
      pet.energy += 15;
      if (pet.energy > 200) pet.energy = 200;
      currentScreen = SCREEN_MAIN;
      break;

    case SCREEN_MAIN:
      // No logic needed
      break;
  }
}


// 'Kona_Neutral', 32x32px
const unsigned char PROGMEM Kona_Neutral[] = {
  0b00000000, 0b00000000, 0b00000000, 0b00000000,
  0b00000000, 0b00000000, 0b00000000, 0b00000000,
  0b00000000, 0b00000000, 0b00000000, 0b00000000,
  0b00000000, 0b00000000, 0b00000000, 0b00000000,
  0b00000000, 0b11100000, 0b00000000, 0b00000000,
  0b00000111, 0b11110000, 0b00000000, 0b00000000,
  0b00000111, 0b11110000, 0b00000000, 0b00000000,
  0b00011000, 0b00001100, 0b00000000, 0b00000000,
  0b00111010, 0b00101110, 0b00000000, 0b00000000,
  0b00111010, 0b00101110, 0b00000000, 0b00000000,
  0b00111000, 0b00001110, 0b00000000, 0b00000000,
  0b00111001, 0b10001110, 0b00000000, 0b00000000,
  0b00001000, 0b00001000, 0b00000000, 0b00000000,
  0b00000111, 0b11111111, 0b11111111, 0b00000000,
  0b00000000, 0b00100000, 0b00000000, 0b11100000,
  0b00000000, 0b01100000, 0b00000000, 0b10111000,
  0b00000000, 0b01100000, 0b00000000, 0b10001100,
  0b00000000, 0b01100000, 0b00000000, 0b10000000,
  0b00000000, 0b00100000, 0b00000000, 0b10000000,
  0b00000000, 0b00100000, 0b00000000, 0b10000000,
  0b00000000, 0b00011111, 0b11111111, 0b10000000,
  0b00000000, 0b00011011, 0b00001101, 0b10000000,
  0b00000000, 0b00011011, 0b00001101, 0b10000000,
  0b00000000, 0b00010010, 0b00001101, 0b10000000,
  0b00000000, 0b00010010, 0b00001101, 0b00000000,
  0b00000000, 0b00010010, 0b00001001, 0b00000000,
  0b00000000, 0b00010010, 0b00001001, 0b00000000,
  0b00000000, 0b00010010, 0b00001001, 0b00000000,
  0b00000000, 0b00000000, 0b00000000, 0b00000000,
  0b00000000, 0b00000000, 0b00000000, 0b00000000,
  0b00000000, 0b00000000, 0b00000000, 0b00000000,
  0b00000000, 0b00000000, 0b00000000, 0b00000000
};

// Array of all bitmaps. (Total bytes used to store images in PROGMEM = 144)
const int epd_bitmap_allArray_LEN = 1;
const unsigned char* epd_bitmap_allArray[1] = {
  Kona_Neutral
};