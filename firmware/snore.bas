





$regfile = "m88adef.dat"
$crystal = 1000000
$hwstack = 40
$swstack = 16
$framesize = 32




Config Portb.1 = Output

Config Timer1 = Pwm , Pwm = 8 , Prescale = 8 , Compare A Pwm = Clear up

Dim A As Byte

Pwm1a = 20
                                            ' light
Wait 2
Pwm1a = 250

Wait 2
Do
   For A = 255 To 1 Step -10
      Pwm1a = A
      Waitms 100
   Next A

   For A = 1 To 255 Step 10
      Pwm1a = A
      Waitms 100
   Next A
Loop
End