/*! **********************************************************************************************
* 2016  ITESM Campus Guadalajara. Laboratorio de Microcontroladores 
*  
*
* @file:      ADC.c
* @author(s): Manuel Madrigal Valenzuela; Efra�n Duarte L�pez
*
* @brief (Theory of Operation)
*     This Driver lets the user initialize the ADC with  pre-defined parameters.
*     Nevertheless, the user can do it differently with the Macro functions defined in the header file
*     
*
**************************************************************************************************/


/*************************************************************************************************/
/*********************						Includes						**********************/
/*************************************************************************************************/
#include "ADC.h"
#include "types.h"
/*************************************************************************************************/
/*********************						Defines							**********************/
/*************************************************************************************************/

/*************************************************************************************************/
/*********************						Typedefs						**********************/
/*************************************************************************************************/

/*************************************************************************************************/
/*********************					Function Prototypes					**********************/
/*************************************************************************************************/

/*************************************************************************************************/
/*********************                  Static Variables                    **********************/
/*************************************************************************************************/
static u8 selected_channel;
/*************************************************************************************************/
/*********************					Global Variables					**********************/
/*************************************************************************************************/

/*************************************************************************************************/
/*********************                  Static Constants                    **********************/
/*************************************************************************************************/


/*************************************************************************************************/
/*********************                  Global Constants                    **********************/
/*************************************************************************************************/

/*************************************************************************************************/
/*********************				   Exported Functions					**********************/
/*************************************************************************************************/

void ADC_Init(void)
{
   ADC_EnablePinForADCv1(ADC_CHANNEL);
   ADC_EnablePinForADCv1(ADC_CHANNEL2);
   ADC_ConversionModeSelection(ADC_RESOLUTION);
   ADC_SelectChannel(ADC_CHANNEL);
   ADC_EnableContinuousConversion();
   selected_channel=ADC_CHANNEL;
}

void ADC_Toggle_channel(void)
{
   if(selected_channel==ADC_CHANNEL)
   {
      ADC_SelectChannel(ADC_CHANNEL2);
      selected_channel=ADC_CHANNEL2;
   }
   else
   {
      ADC_SelectChannel(ADC_CHANNEL);
      selected_channel=ADC_CHANNEL;
   }
}
//-------------------------------------------------------------------------------------------------


/*************************************************************************************************/
/*********************				    Private Functions					**********************/
/*************************************************************************************************/

