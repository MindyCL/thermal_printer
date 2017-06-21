/*------------------------------------------------------------------------
  This is based off the example sketch for Adafruit Thermal Printer library for Arduino.
  Demonstrates a few text styles & layouts, bitmap printing, etc.

  IMPORTANT: DECLARATIONS DIFFER FROM PRIOR VERSIONS OF THIS LIBRARY.
  This is to support newer & more board types, especially ones that don't
  support SoftwareSerial (e.g. Arduino Due).  You can pass any Stream
  (e.g. Serial1) to the printer constructor.  See notes below.

  You may need to edit the PRINTER_FIRMWARE value in Adafruit_Thermal.h
  to match your printer (hold feed button on powerup for test page).
  ------------------------------------------------------------------------*/

/*All .h files are the images that are being included*/

#include "Adafruit_Thermal.h"
#include "pig.h"
#include "pay.h"
#include "duck.h"
#include "cinnamon.h"

int randomizer = 0;
int buttonState = 0;

const int buttonPin = 2;

// Here's the new syntax when using SoftwareSerial (e.g. Arduino Uno) ----
// If using hardware serial instead, comment out or remove these lines:

#include "SoftwareSerial.h"
#define TX_PIN 6 // Arduino transmit  YELLOW WIRE  labeled RX on printer
#define RX_PIN 5 // Arduino receive   GREEN WIRE   labeled TX on printer

SoftwareSerial mySerial(RX_PIN, TX_PIN); // Declare SoftwareSerial obj first
Adafruit_Thermal printer(&mySerial);     // Pass addr to printer constructor
// Then see setup() function regarding serial & printer begin() calls.

// Here's the syntax for hardware serial (e.g. Arduino Due) --------------
// Un-comment the following line if using hardware serial:

//Adafruit_Thermal printer(&Serial1);      // Or Serial2, Serial3, etc.

// -----------------------------------------------------------------------

void setup() {

  // This line is for compatibility with the Adafruit IotP project pack,
  // which uses pin 7 as a spare grounding point.  You only need this if
  // wired up the same way (w/3-pin header into pins 5/6/7):
  pinMode(7, OUTPUT); digitalWrite(7, LOW);
  pinMode(buttonPin, INPUT);

  // NOTE: SOME PRINTERS NEED 9600 BAUD instead of 19200, check test page.
  mySerial.begin(19200);  // Initialize SoftwareSerial
  //Serial1.begin(19200); // Use this instead if using hardware serial
  printer.begin();        // Init printer (same regardless of serial type)

  // The following calls are in setup(), but don't *need* to be.  Use them
  // anywhere!  They're just here so they run one time and are not printed
  // over and over (which would happen if they were in loop() instead).
  // Some functions will feed a line when called, this is normal.

  Serial.begin(9600);

}

void loop() {
  // read the state of the pushbutton


  buttonState = digitalRead(buttonPin);
  Serial.println(buttonState);

  if (buttonState == HIGH) {
    Serial.println("Printing Definition");
    randomizer = random(0, 4);
    Serial.println(randomizer);
    if (randomizer == 0) {
      printer.begin();  
      duck();
      Serial.println("duck");
      printer.sleep();      // Tell printer to sleep
      printer.wake();       // MUST call wake() before printing again, even if reset
      printer.setDefault();
    } else if (randomizer == 1) {
      printer.begin();  
      pig();
      Serial.println("pig");
      printer.sleep();      // Tell printer to sleep
      printer.wake();       // MUST call wake() before printing again, even if reset
      printer.setDefault();
    } else if (randomizer == 2) {
      printer.begin();  
      pay();
      Serial.println("pay");
      printer.sleep();      // Tell printer to sleep
      printer.wake();       // MUST call wake() before printing again, even if reset
      printer.setDefault();
    } else if (randomizer == 3) {
      printer.begin();  
      cinnamon();
      Serial.println("cinnamon");
      printer.sleep();      // Tell printer to sleep
      printer.wake();       // MUST call wake() before printing again, even if reset
      printer.setDefault();
    }
  } else {
    Serial.println("Nothing");
  }
}

void pig() {
  Serial.println("pork");
  printer.justify('C');
  printer.doubleHeightOn();
  printer.boldOn();
  printer.setSize('L');
  printer.println(F("svinekød"));
  printer.feed(1);

  printer.doubleHeightOff();
  printer.setSize('M');
  printer.println(F("Definition:"));

  printer.boldOff();
  printer.justify('L');
  printer.println(F("Pork."));
  printer.feed(1);

  printer.boldOff();
  printer.setSize('S');
  printer.justify('L');

  printer.printBitmap(pig_width, pig_height, pig_data);

  printer.setSize('M');
  printer.boldOn();
  printer.println(F("Example:"));
  printer.boldOff();
  printer.println(F("Mere svinekød venligst!"));
  printer.feed(1);
  printer.boldOff();
  printer.println(F("More pork please!"));
  printer.feed(1);

  printer.setSize('S');
  printer.boldOn();
  printer.println(F("Fact:"));
  printer.boldOff();
  printer.setSize('S');
  printer.println(F("Denmark is the largest exporter of pork in the WORLD."));
  printer.feed(4);
}

void duck() {
  Serial.println("duck");
  printer.justify('C');
  printer.doubleHeightOn();
  printer.boldOn();
  printer.setSize('L');
  printer.println(F("ænderne"));
  printer.feed(1);

  printer.doubleHeightOff();
  printer.setSize('M');
  printer.println(F("Definition:"));

  printer.boldOff();
  printer.justify('L');
  printer.println(F("Ducks."));
  printer.feed(1);

  printer.boldOff();
  printer.setSize('S');
  printer.justify('L');

  printer.printBitmap(duck_width, duck_height, duck_data);

  printer.setSize('M');
  printer.boldOn();
  printer.println(F("Example:"));
  printer.boldOff();
  printer.println(F("Der er ænder i mit værelse"));
  printer.feed(1);
  printer.boldOff();
  printer.println(F("There are ducks in my room."));
  printer.feed(1);

  printer.setSize('S');
  printer.boldOn();
  printer.println(F("Fact:"));
  printer.boldOff();
  printer.setSize('S');
  printer.println(F("Many Danes eat roast duck on Martinmas Eve on Nov 10."));
  printer.feed(4);
}

void pay() {
  Serial.println("pay");
  printer.justify('C');
  printer.doubleHeightOn();
  printer.boldOn();
  printer.setSize('L');
  printer.println(F("betaler"));
  printer.feed(1);

  printer.doubleHeightOff();
  printer.setSize('M');
  printer.println(F("Definition:"));

  printer.boldOff();
  printer.justify('L');
  printer.println(F("To pay"));
  printer.feed(1);

  printer.boldOff();
  printer.setSize('S');
  printer.justify('L');

  printer.printBitmap(pay_width, pay_height, pay_data);

  printer.setSize('M');
  printer.boldOn();
  printer.println(F("Example:"));
  printer.boldOff();
  printer.println(F("Jeg ville betale for Pokemon."));
  printer.feed(1);
  printer.boldOff();
  printer.println(F("I would pay for Pokemon."));
  printer.feed(1);

  printer.setSize('S');
  printer.boldOn();
  printer.println(F("Fact:"));
  printer.boldOff();
  printer.setSize('S');
  printer.println(F("The Danske Bank Group is the largest bank in Denmark."));
  printer.feed(4);
}

void cinnamon()
{
  printer.justify('C');
  printer.doubleHeightOn();
  printer.boldOn();
  printer.setSize('L');
  printer.println(F("onsdagssnegle"));
  printer.feed(1);

  printer.doubleHeightOff();
  printer.setSize('M');
  printer.println(F("Definition:"));

  printer.boldOff();
  printer.justify('L');
  printer.println(F("Literally translated as 'Wednesday snail' but commonly refers to a cinnamon roll."));
  printer.feed(1);

  printer.boldOff();
  printer.setSize('S');
  printer.justify('L');
  printer.printBitmap(cinnamon_width, cinnamon_height, cinnamon_data);

  printer.setSize('M');
  printer.boldOn();
  printer.println(F("Example:"));
  printer.boldOff();
  printer.println(F("En onsdasgsnegle, venligst."));
  printer.feed(1);
  printer.boldOff();
  printer.println(F("One cinnamon roll, please."));
  printer.feed(1);

  printer.setSize('S');
  printer.boldOn();
  printer.println(F("Fact:"));
  printer.boldOff();
  printer.setSize('S');
  printer.println(F("EU regulations limiting cinnamon use almost eliminated the cinnamon roll in Denmark in 2013."));
  printer.feed(4);
}


