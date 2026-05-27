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

// 'Kona_Happy', 32x32px
const unsigned char PROGMEM Kona_Happy[] = {
  0b00000000, 0b00000000, 0b00000000, 0b00000000,
  0b00000000, 0b00000000, 0b00000000, 0b00000000,
  0b00000000, 0b00000000, 0b00000000, 0b00000000,
  0b00000000, 0b00000000, 0b00000000, 0b00000000,
  0b00000000, 0b11100000, 0b00000000, 0b00000000,
  0b00000111, 0b11110000, 0b00000000, 0b00000000,
  0b00000111, 0b11110000, 0b00000000, 0b00000000,
  0b00011000, 0b00001100, 0b00000000, 0b00000000,
  0b00111010, 0b00101110, 0b00000000, 0b00000000,
  0b00111010, 0b00101110, 0b00000000, 0b10000000,
  0b00111000, 0b00001110, 0b00000000, 0b00101000,
  0b00111000, 0b01001110, 0b00000000, 0b01001000,
  0b00001001, 0b10001000, 0b00000000, 0b00011000,
  0b00000111, 0b11111111, 0b11111111, 0b00110000,
  0b00000000, 0b00100000, 0b00000000, 0b11100100,
  0b00000000, 0b01100000, 0b00000000, 0b10001000,
  0b00000000, 0b01100000, 0b00000000, 0b10000010,
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

// 'Kona_Sad', 32x32px
const unsigned char PROGMEM Kona_Sad[] = {
  0b00000000, 0b00000000, 0b00000000, 0b00000000,
  0b00000000, 0b00000000, 0b00000000, 0b00000000,
  0b00000000, 0b00000000, 0b00000000, 0b00000000,
  0b00000000, 0b00000000, 0b00000000, 0b00000000,
  0b00000000, 0b11100000, 0b00000000, 0b00000000,
  0b00000111, 0b11110000, 0b00000000, 0b00000000,
  0b00000111, 0b11110000, 0b00000000, 0b00000000,
  0b00011000, 0b00001100, 0b00000000, 0b00000000,
  0b00111111, 0b01111110, 0b00000000, 0b00000000,
  0b00111010, 0b00101110, 0b00000000, 0b00000000,
  0b00111000, 0b00001110, 0b00000000, 0b00000000,
  0b00111001, 0b10001110, 0b00000000, 0b00000000,
  0b00001000, 0b01001000, 0b00000000, 0b00000000,
  0b00000111, 0b11111111, 0b11111111, 0b00000000,
  0b00000000, 0b00100000, 0b00000000, 0b11100000,
  0b00000000, 0b01100000, 0b00000000, 0b10110000,
  0b00000000, 0b01100000, 0b00000000, 0b10110000,
  0b00000000, 0b01100000, 0b00000000, 0b10010000,
  0b00000000, 0b00100000, 0b00000000, 0b10010000,
  0b00000000, 0b00100000, 0b00000000, 0b10010000,
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

// 'Kona_Sleep', 32x32px
const unsigned char PROGMEM Kona_Sleep[] = {
  0b00000000, 0b00000000, 0b00000000, 0b00000000,
  0b00000000, 0b00000000, 0b00000000, 0b00000000,
  0b00000000, 0b00000000, 0b00000000, 0b00000000,
  0b00000000, 0b00000000, 0b00000000, 0b00000000,
  0b00000000, 0b00000000, 0b00000000, 0b00000000,
  0b00000000, 0b00000000, 0b00000000, 0b00000000,
  0b00000001, 0b11111111, 0b11111111, 0b10000000,
  0b00000010, 0b00000000, 0b00000000, 0b01000000,
  0b00000100, 0b00011111, 0b11111100, 0b00100000,
  0b00001000, 0b11100000, 0b00000010, 0b00010000,
  0b00010001, 0b10100000, 0b00000001, 0b00001000,
  0b00010001, 0b00010000, 0b00000000, 0b10001000,
  0b00010001, 0b01111110, 0b00000000, 0b01001000,
  0b00010001, 0b10000001, 0b11000000, 0b01001000,
  0b00010000, 0b10000111, 0b01100000, 0b01001000,
  0b00010000, 0b10010001, 0b00111111, 0b10001000,
  0b00010001, 0b10100101, 0b00000001, 0b10001000,
  0b00010010, 0b01111110, 0b01110011, 0b00001000,
  0b00010010, 0b01000000, 0b00011110, 0b00001000,
  0b00010010, 0b11000000, 0b00000000, 0b00001000,
  0b00011011, 0b10000000, 0b00000000, 0b00011000,
  0b00011101, 0b00000000, 0b00000000, 0b00111000,
  0b00001110, 0b00000000, 0b00000000, 0b01110000,
  0b00000111, 0b11111111, 0b11111111, 0b11100000,
  0b00000011, 0b11111111, 0b11111111, 0b11000000,
  0b00000001, 0b11111111, 0b11111111, 0b10000000,
  0b00000000, 0b00000000, 0b00000000, 0b00000000,
  0b00000000, 0b00000000, 0b00000000, 0b00000000,
  0b00000000, 0b00000000, 0b00000000, 0b00000000,
  0b00000000, 0b00000000, 0b00000000, 0b00000000,
  0b00000000, 0b00000000, 0b00000000, 0b00000000,
  0b00000000, 0b00000000, 0b00000000, 0b00000000
};

// Array of all bitmaps Kona. (Total bytes used to store images in PROGMEM = 576)
const int allArray_LEN = 4;
const unsigned char* allArray[4] = {
    Kona_Happy,
    Kona_Neutral,
    Kona_Sad,
    Kona_Sleep
};

void render () {
  display.clearDisplay();

  // Chose sprite based on stats
  const unsigned char* sprite;
  if (pet.hunger < 30 || pet.energy < 30 || pet.love < 30 || pet.life < 20) {
    sprite = Kona_Sad;
  } else if (pet.hunger > 70 && pet.energy > 70 && pet.love > 70) {
    sprite = Kona_Happy;
  } else {
    sprite = Kona_Neutral;
  }

  // Draw sprite (32x32 and centered near top of screen)
  display.drawBitmap((SCREEN_WIDTH - 32) / 2, 5, sprite, 32, 32, SSD1306_WHITE);

  // Draw stats bars
  display.setTextSize(1);

  display.setCursor(0, 24);
  display.print("HUN");
  drawBar(30, 24, pet.hunger, 200);

  display.setCursor(0, 34);
  display.print("LOV");
  drawBar(30, 34, pet.love, 100);

  display.setCursor(0, 44);
  display.print("ENE");
  drawBar(30, 44, pet.energy, 200);

  // Button Labels
  display.setCursor(0, 56);
  display.println("[Feed]   [Play]   [Sleep]");

  display.display();
}

// Draws a stat bar
void drawBar(int x, int y, int value, int maxValue) {
  int barWidth = 100;
  int barHeight = 6;
  int safeMax = max(1, maxValue);
  int safeValue = constrain(value, 0, safeMax);
  int filledWidth = map(safeValue, 0, safeMax, 0, barWidth);

  display.fillRect(x, y, filledWidth, barHeight, SSD1306_WHITE);  //Filled part
  display.drawRect(x, y, barWidth, barHeight, SSD1306_WHITE);     //Outline
}