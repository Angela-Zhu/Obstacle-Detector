#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>
#include <MeOrion.h>

double angle_rad = PI/180.0;
double angle_deg = 180.0/PI;
MeUltrasonicSensor ultrasonic_6(6);
MeRGBLed rgbled_7(7, 4);



void setup(){
    
}

void loop(){
    
    if((ultrasonic_6.distanceCm()) < ( 10 )){
        rgbled_7.setColor(0,255,0,0);
        rgbled_7.show();
        buzzerOn ();
        buzzerOff ();
    }
    else
        buzzerOff ();
    if(((ultrasonic_6.distanceCm()) > ( 10 )) && ((ultrasonic_6.distanceCm()) < ( 30 ))){
        rgbled_7.setColor(0,0,0,255);
        rgbled_7.show();
        buzzerOn ();
        buzzerOff ();
    }
    if(((ultrasonic_6.distanceCm()) > (30)) && ((ultrasonic_6.distanceCm()) < (50))){
        rgbled_7.setColor(0,0,255,0);
        rgbled_7.show();
        buzzerOn ();
        buzzerOff ();
    }
    if((ultrasonic_6.distanceCm()) > ( 80 )){
        rgbled_7.setColor(0,0,0,0);
        rgbled_7.show();
    }
    
    _loop();
}

void _delay(float seconds){
    long endTime = millis() + seconds * 1000;
    while(millis() < endTime)_loop();
}

void _loop(){

}

