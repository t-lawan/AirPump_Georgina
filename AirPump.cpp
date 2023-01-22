#include "AirPump.h"


AirPump::AirPump(int _motor_pin, int _speed_pin, int _brake_pin) {
        this->motor_pin = _motor_pin;
        this->speed_pin = _speed_pin;
        this->brake_pin = _speed_pin;

        this->previous_start_time = 0;
        this->previous_stop_time = 0;


        this->is_on = false;
}


void AirPump::init(){
      pinMode(motor_pin, OUTPUT);
      pinMode(brake_pin, OUTPUT);
}


void AirPump::on(){
      is_on= true;
      digitalWrite(motor_pin, HIGH); //Establishes forward direction of Channel A
      analogWrite(speed_pin, 255);

}

void AirPump::off(){
      is_on = false;
      digitalWrite(motor_pin, LOW); //Establishes forward direction of Channel A
//        digitalWrite(brake_pin, HIGH);   //Disengage the Brake for Channel A
        analogWrite(speed_pin, 0);
}
