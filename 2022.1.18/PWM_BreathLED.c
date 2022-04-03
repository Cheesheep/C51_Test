#include<PWM_BreathLED.h>

void PWM_delay(unsigned int t){
    while(t--);
}


void BreathLEd(){
    u8 i,j;
    for (i = 0; i < 100; i++)
        for (j = 0; j < 40; j++)
        {
            P2_0 = 0;
            PWM_delay(i);
            P2_0 = 1;
            PWM_delay(100-i);
        }
    for (i = 0; i < 100; i++)
        for (j = 0; j < 40; j++)
        {
            P2_0 = 0;
            PWM_delay(100-i);
            P2_0 = 1;
            PWM_delay(i);
        }        
    
}