/*
 * Ultrasonic Simple
 * Prints the distance read by an ultrasonic sensor in
 * centimeters. They are supported to four pins ultrasound
 * sensors (liek HC-SC04) and three pins (like PING)))
 * and Seeed Studio sensors).
 *
 * The circuit:
 * * Module HR-SC04 (four pins) or PING))) (and other with
 *   three pins), attached to digital pins as follows:
 * ---------------------    --------------------
 * | HC-SC04 | Arduino |    | 3 pins | Arduino |
 * ---------------------    --------------------
 * |   Vcc   |   5V    |    |   Vcc  |   5V    |
 * |   Trig  |   12    | OR |   SIG  |   13    |
 * |   Echo  |   13    |    |   Gnd  |   GND   |
 * |   Gnd   |   GND   |    --------------------
 * ---------------------


/*
 * Pass as a parameter the trigger and echo pin, respectively,
 * or only the signal pin (for sensors 3 pins), like:
 * Ultrasonic ultrasonic(13);
 */

#include <Ultrasonic.h>

Ultrasonic ultrasonic(12, 13);
int distance;
int LED_verm = 9;
int LED_VERD = 8;

void setup() {
  Serial.begin(9600);
  pinMode(LED_verm, OUTPUT);
  pinMode(LED_VERD, OUTPUT);
  
}

void loop() {
  // Pass INC as a parameter to get the distance in inches
  distance = ultrasonic.read();
    
    if (distance >= 15)
    {
      digitalWrite(LED_verm, LOW);
      digitalWrite(LED_VERD, HIGH);
    }

    else if (distance < 15)
    {
      digitalWrite(LED_verm, HIGH);
      digitalWrite(LED_VERD, LOW);
    }
  
  Serial.print("Distance in CM: ");
  Serial.println(distance);
  delay(1000);
}
