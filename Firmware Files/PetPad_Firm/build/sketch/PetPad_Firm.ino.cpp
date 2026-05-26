#include <Arduino.h>
#line 1 "C:\\Users\\video\\OneDrive\\Documents\\GitHub\\PetPad\\Firmware Files\\PetPad_Firm\\PetPad_Firm.ino"
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

#line 50 "C:\\Users\\video\\OneDrive\\Documents\\GitHub\\PetPad\\Firmware Files\\PetPad_Firm\\PetPad_Firm.ino"
void setup();
#line 74 "C:\\Users\\video\\OneDrive\\Documents\\GitHub\\PetPad\\Firmware Files\\PetPad_Firm\\PetPad_Firm.ino"
void loop();
#line 50 "C:\\Users\\video\\OneDrive\\Documents\\GitHub\\PetPad\\Firmware Files\\PetPad_Firm\\PetPad_Firm.ino"
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

