/*
Date: 5/2021
Author: Elias Santistevan @ SparkFun Electronics
Writing vibration values via I2C to vibrate the motor. 

This vibrates *extremely* vigurously, adhere the motor to something or it will
produce a fault and stop functioning. 

*/

#include "BluetoothSerial.h"
// #include <Wire.h>
// #include "Haptic_Driver.h"

//1123 freefontdemo
#include "SPI.h"
#include "TFT_eSPI.h"
#include "Free_Fonts.h" // Include the header file attached to this sketch

//hardware setup
TFT_eSPI tft = TFT_eSPI();

unsigned long drawTime = 0;
int xpos = 20;
int ypos = 10;


//end

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

#if !defined(CONFIG_BT_SPP_ENABLED)
#error Serial Bluetooth not available or not enabled. It is only available for the ESP32 chip.
#endif

BluetoothSerial SerialBT;
// Haptic_Driver hapDrive;



// int event = 0; 

int scene;
int sceneNo;

const int FLEX_PIN = 34; // Pin connected to voltage divider output
const int TAP_PIN = 32;
// GPIOs 34, 35, 36, 39 can only be used as inputs

// 5V and 47k resistor
const float VCC = 5;
const float R_DIV = 47500.0;

// Upload the code, then try to adjust these values to more
// accurately calculate bend degree.
const float STRAIGHT_RESISTANCE = 14500.0; // resistance when straight
const float BEND_RESISTANCE = 21000.0; // resistance at 90 deg

void setup(){

  //TFT
  tft.begin();
  tft.setRotation(0);
  tft.fillScreen(TFT_BLACK);

  //PINS
  pinMode(FLEX_PIN, INPUT);
  pinMode(TAP_PIN, OUTPUT); //taptic

  //SERIAL


  // Wire.begin();
  Serial.begin(115200);
  // SerialBT.begin("sunnyAlpha"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");

  // Serial.setTimeout(200);
  SerialBT.setTimeout(200);


  // if( !hapDrive.begin())
  //   Serial.println("Could not communicate with Haptic Driver.");
  // else
  //   Serial.println("Qwiic Haptic Driver DA7280 found!");

  // if( !hapDrive.defaultMotor() ) 
  //   Serial.println("Could not set default settings.");

  // Frequency tracking is done by the IC to ensure that the motor is hitting
  // its resonant frequency. I found that restricting the PCB (squeezing)
  // raises an error which stops operation because it can not reach resonance.
  // I disable here to avoid this error. 
  // hapDrive.enableFreqTrack(false);

  // Serial.println("Setting I2C Operation.");
  // hapDrive.setOperationMode(DRO_MODE);
  // Serial.println("Ready.");

  // delay(1000);

}

void loop(){

  //read flex data
  int flexADC = analogRead(FLEX_PIN);
  
  //calculate angle
  float flexV = flexADC * VCC / 1023.0;
  int flexR = R_DIV * (VCC / flexV);
  int angle = map(flexR, STRAIGHT_RESISTANCE, BEND_RESISTANCE, 0, 180);  // bend angle
  //BT

  // SerialBT.println(angle);
  // scene = SerialBT.read();

  Serial.println(angle);
  scene = Serial.read();

  // if(anglePlus < 215){
  //   display(glider);
  //   tap(200);

  // }

  switch(scene) {

    //scene 1
    case 'a': //door
      door();
      tap(400);
      break;

    case 'b'://pipe
      pipe("Cable for power delivery");
      tap(400);
      break;

    case 'c'://cubeL
      cubeL("Battery Pack to provide initial power");
      tap(400);
      break;

    case 'd'://cubeS
      cubeS("Key to start up");
      tap(400);
      break;

    //scene 2
    case 'e': //glider
      glider();
      tap(400);
      break;

    case 'f': //pg
      pg();
      tap(400);
      break;
    case 'g': //pipe
      pipe("Glider altitude modifier");
      tap(400);
      break;
    case 'h': //cubeL
      cubeL("Broken Energy Storage System to Recyle");
      tap(400);
      break;
    case 'i': //cubeS
      cubeS("New Energy Storage System");
      tap(400);
      break;

    //scene 3
    case 'j': //uam
      uam();
      tap(400);
      break;
    case 'k': //pv
      pv();
      tap(400);
      break;
    case 'l': //pipe
      pipe("Fuel Pipe");
      tap(400);
      break;
    case 'm': //cubeL
      cubeL("Data Storage System");
      tap(400);
      break;
    case 'n': //cubeS
      cubeS("Triggers the fuel");
      tap(400);
      break;

    //scene 4
    case 'o': //pipe
      pipe("Water Pipe - already installed");
      tap(400);
      break;
    case 'p': //cubeL
      cubeL("Data Storage System");
      tap(400);
      break;
    case 'q': //cubeS
      cubeS("DNA Bioengineering System - already installed");
      tap(400);
      break;
    case 'r'://pump
      pump();
      tap(400);
      break;

    case 's'://reset
      disReset();
      break;
  }
  delay(150);
}


// Print the header for a display screen
void glider(){
    tft.fillScreen(TFT_MAGENTA);
    tft.setTextColor(TFT_WHITE);
    tft.setCursor(xpos, ypos);    // Set cursor near top left corner of screen

    tft.setFreeFont(FSB18);       // Select Free Serif 12 point font
    tft.println();                // Move cursor down a line
    tft.print("Energy"); // Print the font name onto the TFT screen
        tft.println();                // Move cursor down a line
    tft.print("Glider"); // Print the font name onto the TFT screen

    tft.setCursor(xpos, 140);    // Set cursor near top left corner of screen
    tft.setTextColor(TFT_LIGHTGREY);
    tft.setFreeFont(FSB9);       // Select Free Serif 12 point font
    tft.println();                // Move cursor down a line
    tft.print("MISSION"); // Print the font name onto the TFT screen

    tft.setTextColor(TFT_WHITE);
    tft.setFreeFont(FSB12);       // Select Free Serif 12 point font
    tft.println();                // Move cursor down a line
    tft.print("Fly the glider to harvest energy"); // Print the font name onto the TFT screen
}    

void pg(){
  tft.fillScreen(TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setCursor(xpos, ypos);    // Set cursor near top left corner of screen

  tft.setFreeFont(FSB18);       // Select Free Serif 12 point font
  tft.println();                // Move cursor down a line
  tft.print("Power"); // Print the font name onto the TFT screen
  tft.println();                // Move cursor down a line
  tft.print("Generator"); // Print the font name onto the TFT screen

    tft.setCursor(xpos, 140);    // Set cursor near top left corner of screen
  tft.setTextColor(TFT_LIGHTGREY);
  tft.setFreeFont(FSB9);       // Select Free Serif 12 point font
  tft.println();                // Move cursor down a line
  tft.print("MISSION"); // Print the font name onto the TFT screen

  tft.setTextColor(TFT_WHITE);
  tft.setFreeFont(FSB12);       // Select Free Serif 12 point font
  tft.println();                // Move cursor down a line
  tft.print("Replace the used battery"); // Print the font name onto the TFT screen 
}

void uam(){
    tft.fillScreen(TFT_GREEN);
  tft.setTextColor(TFT_BLACK);
  tft.setCursor(xpos, ypos);    // Set cursor near top left corner of screen

    tft.setFreeFont(FSB18);       // Select Free Serif 12 point font
    tft.println();                // Move cursor down a line
    tft.print("Urban"); // Print the font name onto the TFT screen
        tft.println();                // Move cursor down a line
    tft.print("Air"); // Print the font name onto the TFT screen
    tft.println();                // Move cursor down a line
    tft.print("Mobility"); // Print the font name onto the TFT screen

    tft.setCursor(xpos, 140);    // Set cursor near top left corner of screen
  tft.setTextColor(TFT_LIGHTGREY);
  tft.setFreeFont(FSB9);       // Select Free Serif 12 point font
  tft.println();                // Move cursor down a line
  tft.print("MISSION"); // Print the font name onto the TFT screen

    tft.setTextColor(TFT_BLACK);
    tft.setFreeFont(FSB12);       // Select Free Serif 12 point font
    tft.println();                // Move cursor down a line
    tft.print("Fuel the UAM"); // Print the font name onto the TFT screen
}

void pv(){
    tft.fillScreen(TFT_YELLOW);
  tft.setTextColor(TFT_BLACK);
  tft.setCursor(xpos, ypos);    // Set cursor near top left corner of screen

    tft.setFreeFont(FSB18);       // Select Free Serif 12 point font
    tft.println();                // Move cursor down a line
    tft.print("Photovoltaic");
        tft.println();                // Move cursor down a line
    tft.print("Power"); // Print the font name onto the TFT screen
        tft.println();                // Move cursor down a line
    tft.print("Generation"); // Print the font name onto the TFT screen
}

void door(){
    tft.fillScreen(TFT_WHITE);
  tft.setTextColor(TFT_BLACK);
  tft.setCursor(xpos, ypos);    // Set cursor near top left corner of screen

    tft.setFreeFont(FSB18);   // Select Free Serif 9 point font
    tft.println();          // Free fonts plot with the baseline (imaginary line the letter A would sit on)
    tft.print("Door");  // Print the font name onto the TFT screen

    tft.setCursor(xpos, 140);    // Set cursor near top left corner of screen
    tft.setTextColor(TFT_LIGHTGREY);
    tft.setFreeFont(FSB9);       // Select Free Serif 12 point font
    tft.println();                // Move cursor down a line
    tft.print("MISSION"); // Print the font name onto the TFT screen

    tft.setFreeFont(FSB12);       // Select Free Serif 12 point font
    tft.println();                // Move cursor down a line
    tft.print("Open the door"); // Print the font name onto the TFT screen

}

void pump() {
  tft.fillScreen(TFT_LIGHTGREY);

  // For comaptibility with Adafruit_GFX library the text background is not plotted when using the print class
  // even if we specify it.
  tft.setTextColor(TFT_BLACK);
  tft.setCursor(xpos, ypos);    // Set cursor near top left corner of s

    tft.setFreeFont(FSB18);       // Select Free Serif 12 point font
    tft.println();                // Move cursor down a line
    tft.print("TURN the"); // Print the font name onto the TFT screen
    tft.println();                // Move cursor down a line
    tft.print("KNOB"); // Print the font name onto the TFT screen

    tft.setFreeFont(FSB12);       // Select Free Serif 12 point font
    tft.println();                // Move cursor down a line
    tft.print("CLOCKWISE"); // Print the font name onto the TFT screen

}

void cubeL(const char *string){
  tft.fillScreen(TFT_BLACK); 
    tft.setTextColor(TFT_LIGHTGREY);
    tft.setCursor(xpos, ypos);    // Set cursor near top left corner of screen

    tft.setFreeFont(FSB9);       // Select Free Serif 12 point font
    tft.println();   
    tft.print("NEEDED");

    tft.setTextColor(TFT_GREEN);
    tft.setFreeFont(FSB18);       // Select Free Serif 12 point font
    tft.println();
    tft.print(string);

    tft.setCursor(xpos, 290-ypos);
    tft.setFreeFont(FSB12);       // Select Free Serif 12 point font
    tft.println();                // Move cursor down a line
    tft.print("Type: LARGE CUBE");
}

void cubeS(const char *string){
  tft.fillScreen(TFT_BLACK); 
    tft.setTextColor(TFT_LIGHTGREY);
    tft.setCursor(xpos, ypos);    // Set cursor near top left corner of screen

    tft.setFreeFont(FSB9);       // Select Free Serif 12 point font
    tft.println();   
    tft.print("NEEDED");

    tft.setTextColor(TFT_MAGENTA);
    tft.setFreeFont(FSB18);       // Select Free Serif 12 point font
    tft.println();
    tft.print(string);

    tft.setCursor(xpos, 290-ypos);
    tft.setFreeFont(FSB12);       // Select Free Serif 12 point font
    tft.println();                // Move cursor down a line
    tft.print("Type: SMALL CUBE");


}

void pipe(const char *string){
    tft.fillScreen(TFT_BLACK); 
    tft.setTextColor(TFT_LIGHTGREY);
    tft.setCursor(xpos, ypos);    // Set cursor near top left corner of screen

    tft.setFreeFont(FSB9);       // Select Free Serif 12 point font
    tft.println();   
    tft.print("NEEDED");

    tft.setTextColor(TFT_YELLOW);
    tft.setFreeFont(FSB18);       // Select Free Serif 12 point font
    tft.println();
    tft.print(string);

    tft.setCursor(xpos, 290-ypos);
    tft.setFreeFont(FSB9);       // Select Free Serif 12 point font
    tft.println();                // Move cursor down a line
    tft.print("Type: PIPE");
}

void disReset() {
    tft.fillScreen(TFT_BLACK);
    tft.setTextColor(TFT_WHITE);
    tft.setCursor(xpos, 130);    // Set cursor near top left corner of screen

    tft.setFreeFont(FSB18);       // Select Free Serif 12 point font
    tft.println();                // Move cursor down a line
    tft.print("Hello");

}
  
void tap(int time){
    digitalWrite(TAP_PIN, HIGH);
    delay(time);
    digitalWrite(TAP_PIN, LOW);
}