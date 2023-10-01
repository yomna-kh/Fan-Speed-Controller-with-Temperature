 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: header file for the ATmega16 ADC driver
 *
 * Author: Yomna Khalid
 *
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56

/*******************************************************************************
 *                      ENUMS & STRUCTURES                                     *
 *******************************************************************************/
typedef enum
{
	AREF,AVCC,RESERVES,INTERNAL
}ADC_ReferenceVoltage;
typedef enum
{
	FCPU , F_CPU2 , FCPU_4, F_CPU8,F_CPU16,F_CPU32,F_CPU64,F_CPU128
}ADC_Prescaler;

typedef struct{
 ADC_ReferenceVoltage ref_volt;
 ADC_Prescaler prescaler;
}ADC_ConfigType;
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void ADC_init(const ADC_ConfigType * Config_Ptr);
/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */

uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
