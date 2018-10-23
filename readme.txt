@brief 		Generation Instructions for Code Review
@details 	For STM32L011 to illustrate jreina procedure & value
@url		https://github.com/Jmr-Work/STM32_Translate.git
@auth 		Justin Reina
@date 		10/23/18

@section 	Procedure
	Capture problem statement & specification gen
	Repo Establish
	Pick Proc for ref (STM32L0x1 fam)
		14-pin TSSOP min selected, STM32L011D3
	Project Procedure
	Project Generation
		TrueSTUDIO:STM32L0538_DISCO selected for clarity & time efficiency
	
@section 	Project Procedure
	This work illustrates my skill & capacity for zipcar firmware development
	
	- targeting solution architecture with description
	
	- not targeting runtime solution 
		*stm is additionally a high time investment in this


@section 	Problem Specification

	@goals
	1. coding style
	2. clarity of solution
	3. time efficiency

	@targ
	1. STM32L011
	2. power consumption
	3. concurrent with unrelated modules

	@req
	1. translates words sent over UART
	2a. "Hello<CR>"   returns   "Bonjour<CR>"
	2b. "Goodbye<CR>" returns=> "Au revoir<CR>", etc.

	@rules
	1. assumptions permitted with doc & descrip
	2. compile not needed, to get a sense for how you think

	@jreina
	1. show problem solving process
	2. show solution generation procedure
	3. show clarity of description
	4. share reliability of solution
	

@section 	Problem Statement	[1]
	Write code for a STM32L011 that translates words sent over UART. Sending "Hello<CR>" would send back "Bonjour<CR>", "Goodbye<CR>" => "Au revoir<CR>", etc. Power consumption is an important consideration, and the code must be able to run alongside other unrelated modules.
	
	You can make any assumption you need about items that are not documented in these specs (e.g. other hardware components, etc), as long as you clearly identify them and document them. If you have any questions or need any clarification, please don't hesitate to ask! The code doesn’t need to compile or run, it’s just for us to get a sense for how you think.

@section 	Opens
	x


@section 	References
	[1] Source Email - Code Assignment.pdf (10/22/18)

