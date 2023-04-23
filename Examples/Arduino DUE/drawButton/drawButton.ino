// #include <Arduino.h>
#include <SPI.h>                    // Arduino SPI library
#include <RA8875.h>                 // Display SPI library

#define baudRate 115200             // Define the baud rate
bool debugMode = false;             // Serial debug = true / false

// Define colors
#define BLACK           0x0000
#define WHITE           0xFFFF
#define BLUE            0x001F
#define RED             0xF800
#define GREEN           0x2685
#define CYAN            0x07FF
#define LIME            0x5FE0
#define MAGENTA         0xF81F
#define YELLOW          0xFFE0
#define TURQUOISE       0x0F1B
#define ORANGE          0xFBA0
#define PINK            0xF813
#define SKY             0x667F
#define GREY            0xE73C
#define DarkTURQUOISE   0x3491
#define DarkGREY        0x39C7
#define DarkRED         0x8986
#define DarkGREEN       0x3446
#define DarkMAGENTA     0x612F
#define DarkBLUE        0x298B
#define DarkYELLOW      0x83E5
#define DarkORANGE      0xA347
#define DarkPINK        0xA1EF
#define GOLD            0xF3FF00
#define SALMON          0xFB2C

// Display pins
#define RA8875_INT 4
#define RA8875_CS 10
#define RA8875_RESET 9

// Create display "tft" object
RA8875 tft = RA8875(RA8875_CS, RA8875_RESET);

void setup(void) {
  // Start serial port
  if (debugMode != false) {
    Serial.begin(baudRate);
    Serial.print(" - Serial Monitor started - ");
    Serial.println("");
  }
  // Display initialization
  tft.begin(RA8875_800x480);                  // Start the display
  tft.brightness(200);                        // Set display backlight to 0 <= MAX <= 255
  tft.clearScreen(BLACK);                     // Make the screen with black color
  tft.setExternalFontRom(ER3304_1, GB2312);   // Setup font ROM
  tft.setFont(EXT);                           // Enable external font ROM
  tft.setFontSize(X24);                       // Size of font (X16,X24,X32)
  tft.setFont(INT);                           // Enable internal font >> comment this line to go to EXT fonts
  
  // drawButton(button_shape, button_x, button_y, button_width, button_height, button_radius, button_col1, button_col2, button_textColor, button_fontSize, button_text);
  /*  case 0 - Filled rectangle button
      case 1 - Filled rectangle button with round corners
      case 2 - Rectangle button
      case 3 - Rectangle button with round corners
      case 4 - Round button
      case 5 - Filled round button
      case 6 - Elipse
      case 7 - Filled elipse
      case 8 - Triangle
      case 9 - Filled triangle
      // Parameters for the button function
      button_shape      // Button shape, can get values from 0 to 5
      button_x          // X coordinates of the button
      button_y          // Y coordinates of the button
      button_width      // Width of the button if rectangle / X axis size of the elipse
      button_height     // Height of the button if rectangle / Y axis size of the elipse
      button_radius     // Radius of the round rectangle button / Radius for the circle button
      button_col1       // Color of the filled buttons / Color of the perimeter for normal buttons
      button_col2       // Color for the backgroung of the normal buttons
      button_textColor  // Button text color
      button_fontSize   // Font size of the text inside the button
      button_textOffset // Offset text centering acording to used fonts and sizes
      button_text       // Displayed text inside the button   */

  tft.drawButton(0, 100, 30, 200, 60, 10, BLUE, 0, BLACK, 2, -10, "SETUP");  tft.drawButton(2, 500, 30, 200, 60, 10, CYAN, BLACK, RED, 1, -7, "SETUP");
  tft.drawButton(1, 100, 110, 200, 60, 10, BLUE, 0, BLACK, 2, -10, "SETUP"); tft.drawButton(3, 500, 110, 200, 60, 10, CYAN, BLACK, RED, 1, -7, "SETUP");
  tft.drawButton(5, 200, 270, 200, 60, 80, BLUE, 0, BLACK, 2, -10, "SETUP"); tft.drawButton(4, 600, 270, 200, 60, 80, CYAN, BLACK, RED, 1, -7, "SETUP");
  tft.drawButton(7, 200, 410, 100, 30, 0, BLUE, 0, BLACK, 2, -10, "SETUP"); tft.drawButton(6, 600, 410, 100, 30, 0, CYAN, BLACK, RED, 1, -7, "SETUP");
}

void loop(void) {
  // Waiting for input events from touchscreen
}