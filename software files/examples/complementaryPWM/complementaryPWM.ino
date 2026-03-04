#include <Arduino.h>
#include "driver/mcpwm.h"

// MCPWM Pins for Motor B
#define MOTOR_1_PWM   21   // M1A (PWM_B)
#define MOTOR_1_COMP  22   // M1B (Complementary PWM_B)

// MCPWM Pins for Motor A
#define MOTOR_2_PWM   18   // M2A (PWM_A)
#define MOTOR_2_COMP  19   // M2B (Complementary PWM_A)

// Dead Time (in nanoseconds)
#define DEAD_TIME_NS  1    // 10 = 1µs

// PWM Frequency
#define PWM_FREQ      200000  // 20kHz

/**
 * Sets the motor speed by updating the duty cycle.
 * duty_cycle: Range 0-255 (mapped to %0-%100)
 */
void set_motor_speed(mcpwm_unit_t unit, mcpwm_timer_t timer, float duty_cycle) {
  duty_cycle = constrain(duty_cycle, 0, 255);  
  mcpwm_set_duty(unit, timer, MCPWM_OPR_A, duty_cycle);
  mcpwm_set_duty_type(unit, timer, MCPWM_OPR_A, MCPWM_DUTY_MODE_0); // Complementary is automatically handled
}

void setup_mcpwm() {
  // MCPWM Configuration
  mcpwm_config_t pwm_config;
  pwm_config.frequency = PWM_FREQ;             // PWM Frequency
  pwm_config.cmpr_a = 50;                      // Initial duty cycle (%0)
  pwm_config.cmpr_b = 20;
  pwm_config.counter_mode = MCPWM_UP_COUNTER;  // Up-counter mode
  pwm_config.duty_mode = MCPWM_DUTY_MODE_1;    // Active HIGH duty cycle

  // MCPWM0 for Motor A
  mcpwm_init(MCPWM_UNIT_0, MCPWM_TIMER_0, &pwm_config);
  mcpwm_gpio_init(MCPWM_UNIT_0, MCPWM0A, MOTOR_2_PWM);    // PWM_A
  mcpwm_gpio_init(MCPWM_UNIT_0, MCPWM0B, MOTOR_2_COMP);   // Complementary PWM_A

  // MCPWM1 for Motor B
  mcpwm_init(MCPWM_UNIT_1, MCPWM_TIMER_1, &pwm_config);
  mcpwm_gpio_init(MCPWM_UNIT_1, MCPWM1A, MOTOR_1_PWM);    // PWM_B
  mcpwm_gpio_init(MCPWM_UNIT_1, MCPWM1B, MOTOR_1_COMP);   // Complementary PWM_B

  // Enable Dead Time (for both A and B channels)
  mcpwm_deadtime_enable(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_ACTIVE_HIGH_COMPLIMENT_MODE, DEAD_TIME_NS, DEAD_TIME_NS);
  mcpwm_deadtime_enable(MCPWM_UNIT_1, MCPWM_TIMER_1, MCPWM_ACTIVE_HIGH_COMPLIMENT_MODE, DEAD_TIME_NS, DEAD_TIME_NS);

  // Drive Motor A initial
  set_motor_speed(MCPWM_UNIT_0, MCPWM_TIMER_0, 50);
  
  // Drive Motor B initial
  set_motor_speed(MCPWM_UNIT_1, MCPWM_TIMER_1, 80);
}

void setup() {
  Serial.begin(115200);
  setup_mcpwm();
  Serial.println("Complementary PWM with ESP32 MCPWM Initialized");
}

uint8_t mot_speed = 50;
uint8_t direction = 0;

void loop() {
  // Check for Serial input for manual control
  if (Serial.available() >= 2) {
    int speedA = Serial.parseInt();  // Expected range: 0-100
    int speedB = Serial.parseInt();
    
    Serial.print("Motor A: %"); Serial.print(speedA);
    Serial.print(" | Motor B: %"); Serial.println(speedB);
  }

  delay(10);
  
  // Apply speed to both motors
  set_motor_speed(MCPWM_UNIT_0, MCPWM_TIMER_0, mot_speed);
  set_motor_speed(MCPWM_UNIT_1, MCPWM_TIMER_1, mot_speed);

  // Automatic Speed Ramping (Sweep) Logic
  if (!direction && mot_speed < 100) {
    mot_speed++; 
  } else {
    direction = 1;  
  }

  if (direction && mot_speed > 0) {
    mot_speed--;  
  } else {
    direction = 0;  
  }        
}