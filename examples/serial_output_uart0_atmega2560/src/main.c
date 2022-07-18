#include "library/hal_sources.h"

#define WELCOME_TXT "Hello avr hal\n"
#define CHANGE_LED_STATUS "change led status\n"

int main(void)
{
  // config UART 0
  hal_serial_UART0_init();
  // Send data via UART 0
  hal_serial_UART0_send((uint8_t *)&WELCOME_TXT,sizeof(WELCOME_TXT));

    // make the LED pin an output for PORTB5
    DDRB = 1 << 7;

    while (1)
    {
      // wait 1s
      _delay_ms(1000);
      // change LED status
      PORTB ^= 1 << 7;
      // Send data via UART 0
      hal_serial_UART0_send((uint8_t *)&CHANGE_LED_STATUS,sizeof(CHANGE_LED_STATUS));

    }

    return 0;
}