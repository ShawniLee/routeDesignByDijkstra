/*
  Fade

  This example shows how to fade an LED on pin 9 using the analogWrite()
  function.

  The analogWrite() function uses PWM, so if you want to change the pin you're
  using, be sure to use another PWM capable pin. On most Arduino, the PWM pins
  are identified with a "~" sign, like ~3, ~5, ~6, ~9, ~10 and ~11.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Fade
*/
int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by


#include "Fade.h"
void fade(int count){
  int i=0;
  if(count==1){
      for(i=0;i<200;i++)
  {
  analogWrite(9, brightness);

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  // wait for 30 milliseconds to see the dimming effect
  delay(30);
  }
  analogWrite(9,0);
  }
  else if(count==2){
      for(i=0;i<200;i++)
  {
  analogWrite(9, brightness);
  analogWrite(10, brightness);

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  // wait for 30 milliseconds to see the dimming effect
  delay(30);
  }
  analogWrite(9,0);
  analogWrite(10,0);
  }
else if(count==3){
        for(i=0;i<200;i++)
  {
  analogWrite(9, brightness);
  analogWrite(10, brightness);
  analogWrite(11, brightness);

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  // wait for 30 milliseconds to see the dimming effect
  delay(30);
  }
  analogWrite(9, 0);
  analogWrite(10, 0);
  analogWrite(11, 0);
  }
}
