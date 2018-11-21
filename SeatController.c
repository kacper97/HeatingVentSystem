/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  SeatController.c
 *        Config:  0
 *     SW-C Type:  SeatController
 *  Generated at:  Wed Nov 21 14:19:15 2018
 *
 *     Generator:  MICROSAR RTE ContractPhase Generator Version 3.13.5
 *                 RTE Core Version 1.18.0
 *       License:  
 *
 *   Description:  C-Code implementation template for SW-C <SeatController>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_5.1_777, MD_MSR_5.1_779 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_SeatController.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * boolean: Boolean (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 *********************************************************************************************************************/


#define SeatController_START_SEC_CODE
#include "SeatController_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: run
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <boolean> of PortPrototype <SeatsOnOff>
 *   - triggered on DataReceivedEvent for DataElementPrototype <speed> of PortPrototype <speedIn>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_SeatsOnOff_boolean(boolean *data)
 *   Std_ReturnType Rte_Read_speedIn_speed(sint16 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_heatedSeatsOnOff_boolean(boolean data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: run_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SeatController_CODE) run(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: run
 *********************************************************************************************************************/
sint16 speed;
boolean SeatController;
Std_ReturnType retVal;
(void) Rte_Read_PpSpeed_SeatController(self, &speed);
(void) Rte_Call_PpGetSpeedStatusIoHwAb_IoHwAb_Get_SeatController(self, &SeatController);

// if speed is less than 10, don't heat seats
if (speed < 10 )
{
	        Rte_Call_PpSpeed_SeatController_SetEventStatus(self, DEM_EVENT_STATUS_FAILED);
            retVal = Rte_Call_PpSetSpeedStatusIoHwAb_IoHwAb_Set_Pwm_Signals(self, 0);
}
else
{
        Rte_Call_PpSpeed_SeatController_SetEventStatus(self, DEM_EVENT_STATUS_PASSED);
        retVal = Rte_Call_PpSetSpeedStatusIoHwAb_IoHwAb_Set_Pwm_Signals(self, (sin16)speed);
}
    (void)self;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define SeatController_STOP_SEC_CODE
#include "SeatController_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
