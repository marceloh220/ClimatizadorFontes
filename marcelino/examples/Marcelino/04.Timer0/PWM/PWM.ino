/*
   Marcelo H Moraes
   marceloh220@hotmail.com

   A simple sketch Arduino using Marcelino cores.

   Using pwm mode in pin OC0A (Digital pin 6) and pin OC0B (Digital pin 5)

   For detail of this modules read the manual.

*/

Digital digital;                //Module Digital instantiate
Delay   delay;                  //Module Delay instantiate
Timer0  timer;                  //Module Timer0 instantiate

void setup() {

  digital.mode(6, OUTPUT);     //Pin digital 6(OC0A) as output
  digital.mode(5, OUTPUT);     //Pin digital 5(OC0B) as output

  timer.config(FAST);          //The timer start in NORMAL mode, now he's is change to FAST mode
                               //In this mode the timer will generate a fast pwm wave
                               //The fast pwm mode is a basic  mode to use this feature, it can control various device
                               //But for more accurate control of induction devices, such as motors, the correct phase mode can be selected with the CORRECT mode
                               
  //In a prescale 1/64 the fixed frequency of pwm can be calculate with
  //  fpwm = 16MHz / ( prescale * 255 ) => fpwm = 16MHz / ( 64 * 255 ) = 980Hz
  //The frequency can be changed modifying the prescale

  //The range of pwm for this timer are of 0 at 255

}

void loop() {

  //Here the pulse width will vary from 0 to 255
  for(int aux=0; aux<255; aux++) {
    timer.pwmA(aux);                  //Generate pwm in digital pin 6
    timer.pwmB(aux, INVERT);          //Generate pwm in digital pin 5, but inverted
    delay.us(200);                    //Wait a time of variation
  }

}