#include <16f877a.h>
#fuses NOWDT, XT, NOPUT, NOPROTECT, NODEBUG, NOBROWNOUT, NOLVP, NOCPD, NOWRT 
#use delay (clock = 4M)
#use RS232(BAUD=9600, BITS=8, PARITY=N, XMIT=PIN_C6, RCV=PIN_C7)

char valor;
int open;
int close;

void main()
{
set_tris_a(0b000000);
set_tris_b(0b00000000);
set_tris_d(0b00000000);
set_tris_e(0b000);
output_a(0b0000000);
output_b(0b00000000);
output_d(0b00000000);
output_e(0b000);

output_low(pin_D3);
output_low(pin_D2);
output_low(pin_D1);
output_low(pin_D0);

while (true){

valor=getc();

switch(valor) 

{
case '1':
output_high(pin_D4);
output_low(pin_D3);
output_low(pin_D2);
output_low(pin_D1);
output_low(pin_D0);
break;

case '2':
output_high(pin_D3);
output_low(pin_D4);
output_low(pin_D2);
output_low(pin_D1);
output_low(pin_D0);
break;

case '3':
output_high(pin_D2);
output_low(pin_D3);
output_low(pin_D4);
output_low(pin_D1);
output_low(pin_D0);
break;

case '4':
output_high(pin_D1);
output_low(pin_D3);
output_low(pin_D4);
output_low(pin_D2);
output_low(pin_D0);
break;

case '5':
output_high(pin_D0);
output_low(pin_D3);
output_low(pin_D2);
output_low(pin_D1);
output_low(pin_D4);
break;

case '0':
output_low(pin_B0);
output_low(pin_B1);
output_low(pin_B2);
output_low(pin_B3);
output_low(pin_B4);
output_low(pin_B5);
output_low(pin_B6);
output_low(pin_B7);
output_low(pin_E2);
break;

case '6':
output_high(pin_B0);
break;

case '7':
output_low(pin_B0);
break;

case '8':
output_high(pin_B1);
break;

case '9':
output_low(pin_B1);
break;

case 'A':
output_high(pin_B2);
break;

case 'B':
output_low(pin_B2);
break;

case 'C':
output_high(pin_B3);
break;

case 'D':
output_low(pin_B3);
break;

case 'E':
output_high(pin_B4);
break;

case 'F':
output_low(pin_B4);
break;

case 'G':
output_high(pin_B5);
break;

case 'H':
output_low(pin_B5);
break;

case 'I':
output_high(pin_B6);
break;

case 'J':
output_low(pin_B6);
break;

case 'K':
output_high(pin_B7);
break;

case 'L':
output_low(pin_B7);
break;

case 'M':
for(open=0;open<=60;open++){
   output_high(pin_E1);
   delay_us(500);
   output_low(pin_E1);
   delay_us(19500);
}
break;

case 'N':
for(close=0;close<=60;close++){
   output_high(pin_E1);
   delay_us(1500);
   output_low(pin_E1);
   delay_us(18500);
}
break;

case 'O':
output_high(pin_A0);
output_low(pin_A1);
delay_ms(5000);
output_low(pin_A0);
output_low(pin_A1);
break;

case 'P':
output_high(pin_A1);
output_low(pin_A0);
delay_ms(4500);
output_low(pin_A0);
output_low(pin_A1);
break;

case 'Q':
output_high(pin_A2);
output_low(pin_A3);
delay_ms(300);
output_low(pin_A2);
output_low(pin_A3);
break;

case 'R':
output_high(pin_A3);
output_low(pin_A2);
delay_ms(300);
output_low(pin_A2);
output_low(pin_A3);
break;

case 'U':
output_high(pin_E0);
output_low(pin_A5);
break;

case 'V':
output_high(pin_A5);
output_low(pin_E0);
break;

case 'W':
output_high(pin_E2);
break;

case 'X':
output_low(pin_E2);
break;

case 'Y':
output_low(pin_A5);
output_low(pin_E0);
break;
}

}
}

