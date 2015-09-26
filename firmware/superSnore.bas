




$regfile = "m88adef.dat"
$crystal = 1000000
$hwstack=40
$swstack=16
$framesize=32



Config Portb.1 = Output
Config Portb.2 = Output

Config Timer1 = Pwm , Pwm = 10 , Prescale = 8 , Compare A Pwm = Clear Up

Dim Adc_input As Word

Config Adc = Single , Prescaler = Auto , Reference = Avcc


Do

   Adc_input = Getadc(1)
   Pwm1a = Adc_input
   Waitms 100

Loop
