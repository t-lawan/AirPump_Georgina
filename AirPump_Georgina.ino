#include "AirPump.h"


AirPump pump_in(12,3,9);
AirPump pump_out(13,11,9);

unsigned long breathe_in_delay = 10000;
unsigned long breathe_out_delay = 10000;
unsigned long break_delay = 5000;

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pump_in.init();
  pump_out.init();
}

void loop() {

  breatheIn();

  stopPumps();
  
  delay(break_delay);

  breatheOut();

  stopPumps();
  
  delay(break_delay);
}

void breatheIn(){
    pump_in.on();
  pump_out.off();
  delay(breathe_in_delay);
}

void breatheOut(){
  pump_in.off();
  pump_out.on();
  delay(breathe_out_delay);
}

void stopPumps(){
  pump_in.off();
  pump_out.off();
}
