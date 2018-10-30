/*
 * lut.h
 *
 * @note 	case sensitive string format (EOS='\0')
 * @open 	consider using heap to allocate variable string lengths
 */
#ifndef LUT_H_
#define LUT_H_

//Library
#include <string.h>

//Definitions
#define 	MAX_STR_SIZE (100)												/* Max string length supported @temp					*/
#define 	LUT_SIZE     (100)												/* Max count of LUT values @temp						*/

//Typedefs
typedef struct lut_value {													/* lookup table value for rx->tx response				*/
	char rx[MAX_STR_SIZE];
	char tx[MAX_STR_SIZE];
} LUT_Value;

//Global Variables
extern LUT_Value lut[LUT_SIZE];												/* LUT values											*/

//Global Functions
extern char * translate_msg(char *message);									/* Lookup specified tx response to rx message			*/

#endif /* LUT_H_ */
