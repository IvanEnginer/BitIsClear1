#include <avr/io.h>
#include <avr/iom32.h>

int main(void)
{
	DDRB &= ~_BV(3);
	
	PORTB |= _BV(3);
	DDRB |= _BV(0);
	
	PORTB &= ~_BV(0);
	
    while(1)
    {
        if (bit_is_clear(PINB, 3))
        {
			PORTB |= _BV(0);
			loop_until_bit_is_set(PINB, 3);
			
			PORTB &= ~_BV(0);
        }
    }
}