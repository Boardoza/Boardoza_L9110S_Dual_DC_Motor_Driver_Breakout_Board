#include "Arduino.h"

// PWM Parameters
#define PWM_FREQ         1000      // PWM frequency: 1 kHz
#define PWM_RESOLUTION   8         // 8-bit resolution (range 0-255)

// LEDC channels for ESP32 (separate channel for each pin)
const int pwmChannel18 = 0; // Channel for Pin 18
const int pwmChannel21 = 1; // Channel for Pin 21
const int pwmChannel19 = 2; // Channel for Pin 19
const int pwmChannel22 = 3; // Channel for Pin 22

uint8_t mot_speed = 0;       // Motor speed (0-255)
uint8_t motor_direction = 0; // 0: Reverse, 1: Forward
bool rampUp = true;          // Is speed increasing?

void setup() {
  // PWM Configurations
  ledcSetup(pwmChannel18, PWM_FREQ, PWM_RESOLUTION);
  ledcAttachPin(18, pwmChannel18);
  
  ledcSetup(pwmChannel21, PWM_FREQ, PWM_RESOLUTION);
  ledcAttachPin(21, pwmChannel21);
  
  ledcSetup(pwmChannel19, PWM_FREQ, PWM_RESOLUTION);
  ledcAttachPin(19, pwmChannel19);
  
  ledcSetup(pwmChannel22, PWM_FREQ, PWM_RESOLUTION);
  ledcAttachPin(22, pwmChannel22);
}

void loop() {
  /* * Single motor control via pins 21 and 22.
   * According to the datasheet:
   * Forward (clockwise): IA HIGH, IB LOW
   * Reverse (counter-clockwise): IA LOW, IB HIGH
   * Logic: If motor_direction == 1, forward signal is applied.
   */
  if (motor_direction) { 
    // Forward direction: PWM active on Pin 18 and 21, Pin 19 and 22 are LOW
    ledcWrite(pwmChannel19, 0);
    ledcWrite(pwmChannel22, 0);
    ledcWrite(pwmChannel18, mot_speed);
    ledcWrite(pwmChannel21, mot_speed);
  } else { 
    // Reverse direction: PWM active on Pin 19 and 22, Pin 18 and 21 are LOW
    ledcWrite(pwmChannel18, 0);
    ledcWrite(pwmChannel21, 0);
    ledcWrite(pwmChannel19, mot_speed);
    ledcWrite(pwmChannel22, mot_speed);
  }

  /*
   * Speed Ramping Mechanism:
   * To prevent unwanted counter-rotation caused by motor inertia during 
   * direction changes, a short "dead time" (braking period) is added 
   * when the speed reaches zero.
   */
  if (rampUp) {
    if (mot_speed < 255) {
      mot_speed++;
    } else {
      // Switch to ramp down once maximum speed is reached
      rampUp = false;
    }
  } else { // Ramp down
    if (mot_speed > 0) {
      mot_speed--;
    } else {
      // Motor fully stopped: add dead time (braking duration)
      delay(100);  // Wait for 100 ms
      // Change direction after dead time
      motor_direction = (motor_direction == 1) ? 0 : 1;
      rampUp = true;
    }
  }
  
  delay(10);
}