
#ifndef DYIRDaikinDef_h
#define DYIRDaikinDef_h

#define DYIRDAIKIN_DEBUG
#define DYIRDAIKIN_DEBUG_SERIAL Serial

#ifdef DYIRDAIKIN_DEBUG
  #define DYIRDAIKIN_DEBUG_PRINT(...) { DYIRDAIKIN_DEBUG_SERIAL.print(__VA_ARGS__); }
  #define DYIRDAIKIN_DEBUG_PRINTLN(...) { DYIRDAIKIN_DEBUG_SERIAL.println(__VA_ARGS__); }
#else
  #define DYIRDAIKIN_DEBUG_PRINT(...) {}
  #define DYIRDAIKIN_DEBUG_PRINTLN(...) {}
#endif

//#define DY_IRDAIKIN_SOFTIR

#define AVR_HARDWARE_PWM \
		(defined(__AVR_ATmega1280__) | defined(__AVR_ATmega2560__) | \
		defined(__AVR_AT90USB162__) | defined(__AVR_ATmega32U4__) | \
		defined(__AVR_AT90USB646__) | defined(__AVR_AT90USB1286__) | \
		defined(__AVR_ATmega644P__) | defined(__AVR_ATmega644__) | \
		defined(__AVR_ATmega8P__) | defined(__AVR_ATmega8__) | defined(__AVR_ATmega328P__))

#if defined(ARDUINO) && ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

#if AVR_HARDWARE_PWM
#include <DYIRDaikinPWM.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#warning "Use PWM IR to Send!"
#define SOFTIR_PIN 3
#else
#define _delay_us delayMicroseconds
#define TIMER_ENABLE_PWM
#define TIMER_DISABLE_PWM
#define TIMER_CONFIG_KHZ
#define TIMER_PWM_PIN 3
#define SOFTIR_PIN 3
#warning "Use soft IR to Simulate!"
#endif
//
#define DYIRDAIKIN_FREQUENCY	38

//DAIKIN
#define DYIRDAIKIN_HDR_MARK	    3600 //DAIKIN_ZERO_MARK*8
#define DYIRDAIKIN_HDR_SPACE	1600 //DAIKIN_ZERO_MARK*4
#define DYIRDAIKIN_ONE_SPACE	1300
#define DYIRDAIKIN_ONE_MARK	    400
#define DYIRDAIKIN_ZERO_MARK	400
#define DYIRDAIKIN_ZERO_SPACE   428


// IR detector output is active low
#define MARK  0
#define SPACE 1


#endif
