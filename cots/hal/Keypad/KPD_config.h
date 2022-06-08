/*
 * kpd_config.h
 *
 *  Created on: Sep 13, 2021
 *      Author: Sa3eed
 */

#ifndef COTS_HAL_KEYPAD_KPD_CONFIG_H_
#define COTS_HAL_KEYPAD_KPD_CONFIG_H_

#define KPD_PORT Dio_PortB

#define KPD_NO_PRESSED_KEY 0xff

#define KPD_ARR_VAL { {'7','8','9','/'}, {'4','5','6','x'}, {'1','2','3','-'}, {'C','0','=','+'}}

#define KPD_Column0_PIN Dio_Pin0
#define KPD_Column1_PIN Dio_Pin1
#define KPD_Column2_PIN Dio_Pin2
#define KPD_Column3_PIN Dio_Pin3

#define KPD_Row0_PIN Dio_Pin4
#define KPD_Row1_PIN Dio_Pin5
#define KPD_Row2_PIN Dio_Pin6
#define KPD_Row3_PIN Dio_Pin7


#endif /* COTS_HAL_KEYPAD_KPD_CONFIG_H_ */
