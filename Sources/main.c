/*! **********************************************************************************************
* 2016  ITESM Campus Guadalajara. Laboratorio de Microcontroladores 
*  
*
* @file:      main.c
* @author(s): Manuel Madrigal Valenzuela
*
* @brief (Theory of Operation)
*     
*      
**************************************************************************************************/

/*************************************************************************************************/
/*********************                 Includes                **********************/
/*************************************************************************************************/
#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include "types.h"
#include "ADC.h"
#include "GPIO.h"
#include "TimersManager.h"

/*************************************************************************************************/
/*********************                 Defines                    **********************/
/*************************************************************************************************/
#define CIEN_MS 100000
#define ALTURA_IN 10
#define Q_IN   209   //*10
#define SENSOR_RESOLUTION  58 //mV for each mm
#define K1  72
#define K2  301

/*************************************************************************************************/
/*********************                 Typedefs                **********************/
/*************************************************************************************************/

/*************************************************************************************************/
/*********************              Function Prototypes              **********************/
/*************************************************************************************************/

/*************************************************************************************************/
/*********************              Global Variables              **********************/
/*************************************************************************************************/

/*************************************************************************************************/
/*********************                  Static Constants                    **********************/
/*************************************************************************************************/


/*************************************************************************************************/
/*********************                  Global Constants                    **********************/
/*************************************************************************************************/
volatile u8 dutyCycle;
u8 controlTimerID;

u32   altura1;
u32   altura2;
i32   error1;
i32   error2;

i32 Q;
/*************************************************************************************************/
/*********************                  MAIN                   **********************/
/*************************************************************************************************/
void main(void) {
  EnableInterrupts;
  TimersMngr_Init();
  ADC_Init();
  
  dutyCycle=50;
  PTBDD_PTBDD5=1; //configurar el pin como salida, inicia en 0
  TPMSC=0b00001111;  //configurar clock
  TPMC1SC=0b01011100;
  TPMC1V=(100-(unsigned int)dutyCycle)*10;
  
  
  
  controlTimerID=TimersMngr_CreateTimer(D_NULL);
  TimersMngr_StartTimer(controlTimerID,CIEN_MS);
  
    
  for(;;) {
     if(TimersMngr_TimerHasElapsed(controlTimerID))
     {
        TimersMngr_StartTimer(controlTimerID,CIEN_MS);
        altura1=((u32)ADC_getResultOfConversion()*57)/(ADC_MODE_MASK);
        ADC_Toggle_channel();
        altura2=((u32)ADC_getResultOfConversion()*57)/(ADC_MODE_MASK);
        ADC_Toggle_channel();
        
        error1=altura1-ALTURA_IN;//*10
        error2=altura2-ALTURA_IN;//*10
        
        Q=Q_IN;
        Q-=K1*error1;
        Q-=K2*error2;
        Q/=10;
        
        if(Q<1)
        {
           Q=1;
        }
        else if(Q>24)
        {
           Q=24;
        }
        
        dutyCycle=4*Q+3;
        if(dutyCycle>99)
        {
           dutyCycle=99;
        }
        
     }
     
     
     TimersMngr_PeriodicTask();//Refresh timers
     
    __RESET_WATCHDOG(); /* feeds the dog */
  } /* loop forever */
  
}
/*************************************************************************************************/
/*********************               Private Functions               **********************/
/*************************************************************************************************/
interrupt VectorNumber_Vtpmch1 void CH1_ISR(void)
{
   (void) TPMC1SC;
   TPMC1SC_CH1F=0;
   
   if(TPMC1SC_ELS1A==1)
   {
      TPMC1SC=0b01011000; //CLEAR
      TPMC1V+=((unsigned int)dutyCycle)*10;   
   }
   else
   {
      TPMC1SC=0b01011100; //CLEAR
      TPMC1V+=(100-(unsigned int)dutyCycle)*10;   
   }
   
   
   
}
