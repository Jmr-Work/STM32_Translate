#include "lut.h"

LUT_Value lut[LUT_SIZE] = {													/* LUT values											*/
		{"Hello","Bonjour"},
		{"Goodbye","Au revoir"},
		{"Ok", "D'accord"}
};


/************************************************************************************************************************************/
/**	@fcn		char * translate_msg(char *message)
 *  @brief		translate inbound msg to specified response
 *  @details	string values
 *
 *  @param		[in] (char *) message - received message to use for lookup
 *  @return		(char *) pointer to response message, 0 for failure
 *
 *  @assum		no rx overflow
 *
 *  @section 	Opens
 *  	Code
 */
/************************************************************************************************************************************/
char * translate_msg(char *message) {

	//Find LUT value
//	for(each LUT value)
//		if found return LUT response value

	return (char*)0;														/* return 0 to indicate failure							*/
}

