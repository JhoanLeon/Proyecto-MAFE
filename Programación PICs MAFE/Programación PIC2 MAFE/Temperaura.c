#include <16f877a.h>
#fuses NOWDT, XT, NOPUT, NOPROTECT, NODEBUG, NOBROWNOUT, NOLVP, NOCPD, NOWRT
#device adc=10
#use delay(clock=4M)
#include <lcd.c>
#define  portb=0x06;

#define LCD_ENABLE_PIN  PIN_D0
#define LCD_RS_PIN      PIN_D1                         
#define LCD_RW_PIN      PIN_D2                             
#define LCD_DATA4       PIN_D4                                
#define LCD_DATA5       PIN_D5                                   
#define LCD_DATA6       PIN_D6                                    
#define LCD_DATA7       PIN_D7 

float Temperatura;

void main(void)
{
  set_tris_b(0b11111000);
  set_tris_c(0b11111111);
  set_tris_d(0b00000000);
  set_tris_e(0b000);
  setup_adc_ports (RA0_ANALOG);
  setup_adc (ADC_CLOCK_INTERNAL);
  setup_COUNTERS (RTCC_internal.rtcc_div_1);
  set_adc_channel(0);
  
lcd_init();
lcd_gotoxy(3,1);
printf(lcd_putc,"HOLA USUARIO");
delay_ms(1000);
lcd_gotoxy(4,2);
printf(lcd_putc,"BIENVENIDO");
delay_ms(1000);
lcd_init();
lcd_gotoxy(2,1);
printf(lcd_putc,"PROYECTO MAFE");
delay_ms(1000);
lcd_init();

output_high(pin_E0);
delay_ms(100);
output_low(pin_E0);
delay_ms(500);
  
  while (true)
  {
  output_c(1);
  Temperatura=read_adc()/2;
  Temperatura = Temperatura - 1;
  lcd_gotoxy(1,2);
  printf(lcd_putc,"%f",Temperatura);
  lcd_gotoxy(5,2);
  printf(lcd_putc," CENTIGRADOS");

      if(temperatura>=40)
      {
         output_high(pin_E0);
         delay_ms(250);
         output_low(pin_E0);
         delay_ms(150);
         output_high(pin_E0);
         delay_ms(250);
         output_low(pin_E0);
         delay_ms(150);
         output_high(pin_E0);
         delay_ms(250);
         output_low(pin_E0);
         delay_ms(150);
      }
      
      if(temperatura>=36)
      {
         lcd_gotoxy(1,1);
         printf(lcd_putc,"TEMPERATURA ALTA");
         delay_ms (1000);
         lcd_init();
         delay_ms(100);
      }
      
     if(Temperatura<=23)
      {
         lcd_gotoxy(1,1);
         printf(lcd_putc,"TEMPERATURA BAJA");         
         delay_ms (1000);
         lcd_init();
         delay_ms(100);
      }
         
     if(Temperatura<=35 && Temperatura>=24)
      {
         lcd_gotoxy(1,1);
         printf(lcd_putc,"TEMPERTA. NORMAL");         
         delay_ms (1000);
         lcd_init();
         delay_ms(100);
      }
     output_c(0);
     
if(input(pin_B7)==1){
output_low(pin_B0);
lcd_init();
lcd_gotoxy(3,1);
printf(lcd_putc,"MODO CONTROL");
lcd_gotoxy(5,2);
printf(lcd_putc,"ACTIVADO");
delay_ms(1000);
lcd_init();
}
if(input(pin_B6)==1){
output_low(pin_B0);
lcd_init();
lcd_gotoxy(5,1);
printf(lcd_putc,"MODO VOZ");
lcd_gotoxy(5,2);
printf(lcd_putc,"ACTIVADO");
delay_ms(1000);
lcd_init();
}
if(input(pin_B5)==1){
output_low(pin_B0);
lcd_init();
lcd_gotoxy(1,1);
printf(lcd_putc,"MODO INTELIGENTE");
lcd_gotoxy(5,2);
printf(lcd_putc,"ACTIVADO");
delay_ms(1000);
lcd_init();
}
if(input(pin_B4)==1){
output_high(pin_B0);
lcd_init();
lcd_gotoxy(3,1);
printf(lcd_putc,"MODO SEGURO");
lcd_gotoxy(5,2);
printf(lcd_putc,"ACTIVADO");
delay_ms(1000);
lcd_init();
}
if(input(pin_B3)==1){
output_low(pin_B0);
lcd_init();
lcd_gotoxy(3,1);
printf(lcd_putc,"MODO MANUAL");
lcd_gotoxy(5,2);
printf(lcd_putc,"ACTIVADO");
delay_ms(1000);
lcd_init();
}

if(input(pin_C3)==1){
output_high(pin_E0);
delay_ms(1000);
output_low(pin_E0);
delay_ms(500);
output_high(pin_E0);
delay_ms(1000);
output_low(pin_E0);
delay_ms(500);
}
if(input(pin_C2)==1){
output_high(pin_E0);
delay_ms(1000);
output_low(pin_E0);
delay_ms(500);
output_high(pin_E0);
delay_ms(1000);
output_low(pin_E0);
delay_ms(500);
}
if(input(pin_C1)==1){
output_high(pin_E0);
delay_ms(1000);
output_low(pin_E0);
delay_ms(500);
output_high(pin_E0);
delay_ms(1000);
output_low(pin_E0);
delay_ms(500);
}
if(input(pin_C0)==1){
output_high(pin_E0);
delay_ms(1000);
output_low(pin_E0);
delay_ms(500);
output_high(pin_E0);
delay_ms(1000);
output_low(pin_E0);
delay_ms(500);
}

}  
}


