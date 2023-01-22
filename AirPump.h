#ifndef AirPump_h
#define AirPump_h
#include "Arduino.h" 
class AirPump {

  public:
    AirPump(int _motor_pin, int _speed_pin, int _brake_pin);
    bool is_on = false;
    int motor_pin;
    int speed_pin;
    int brake_pin;
    unsigned long previous_stop_time = 0;
    unsigned long previous_start_time = 0;
    unsigned long max_time_to_run = 500; //microseconds 
    unsigned long start_delay = 2000;
    
    void init() ;
    void on();
    void off();
};

#endif
