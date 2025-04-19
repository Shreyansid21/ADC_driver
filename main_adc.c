#include "header.h"

int main()
{
	u32 adcval1, adcval2;
	f32 Vout1, Vout2, tempr1, tempr2;

	uart1_init(9600);
	adc_init();
	lcd_init();
	
	while(1)
	{
		adcval1=adc_read(1);						//adc_read(1)				MCP9700	temperature sensor
		Vout1=(adcval1*3.3)/1023;
		tempr1=(Vout1-0.5)/0.01;
		delay_s(1);
		
		lcd_string("TEMP : ");
		lcd_cmd(0x87);
		lcd_float(tempr1,2);
		lcd_data(223);
		lcd_data('C');
		delay_s(1);
		
		adcval2=adc_read(2);						//adc_read(2)				Potentiometer
		Vout2=(adcval2*3.3)/1023;
		tempr2=(Vout2-0.5)/0.01;
		
		lcd_cmd(0xC0);
		lcd_string("POT  : ");
		lcd_cmd(0xC7);
		lcd_float(Vout2,2);
		lcd_data('V');
		delay_s(3);
		lcd_cmd(0x01);
	}
}

