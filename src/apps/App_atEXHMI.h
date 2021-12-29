/**
@file
Application for communicating with OP320A&S SNM over RS232/485 (via RTU protocol).
*/
/*
  Application_SNM.h - Arduino library for communicating with OP320A&S SNM
  over RS232/485 (via RTU protocol).

  Library:: chickyPig_OP320_V1

  This version is

  Copyright:: 2021 nguyentrinhtuan1996@gmail.com
*/

#ifndef _Application_atEXHMI_
#define _Application_atEXHMI_
/* _____PROJECT INCLUDES____________________________________________________ */
#include "App.h"
#include "../services/Service_atXYZ.h"
/* _____DEFINETIONS__________________________________________________________ */

/* _____GLOBAL VARIABLES_____________________________________________________ */

///////////////////////////////////////////////Testing part//
/* _____GLOBAL FUNCTION______________________________________________________ */

/* _____CLASS DEFINETION_____________________________________________________ */
/**
 * This Application class is the application to manage the 
 */
class App_EXHMI : public Application
{
public:
  	App_EXHMI();
 	~App_EXHMI();
  	static void  App_EXHMI_Pend();
	static void  App_EXHMI_Start();
	static void  App_EXHMI_Restart();
	static void  App_EXHMI_Execute();
	static void  App_EXHMI_Suspend();
	static void  App_EXHMI_Resume();	  
	static void  App_EXHMI_End();
protected:
private:
} atEXHMI ;
/**
 * This function will be automatical called when a object is created by this class
 */
App_EXHMI::App_EXHMI(/* args */)
{
  	_Pend_User 	     = *App_EXHMI_Pend;
	_Start_User 	 = *App_EXHMI_Start;
	_Restart_User 	 = *App_EXHMI_Restart;
	_Execute_User 	 = *App_EXHMI_Execute;
	_Suspend_User	 = *App_EXHMI_Suspend;
	_Resume_User	 = *App_EXHMI_Resume;
	_End_User	     = *App_EXHMI_End;

	// change the ID of application
	ID_Application = 1;
	// change the application name
	Name_Application = (char*)"EXHMI Application";
	// change the ID of SNM
}
/**
 * This function will be automatical called when the object of class is delete
 */
App_EXHMI::~App_EXHMI()
{
	
}
/**
 * Pend to start is the fisrt task of this application it will do prerequisite condition. In the debig mode, task will send information of application to terminal to start the application.
 */
void  App_EXHMI::App_EXHMI_Pend()
{
    // atXYZ.Debug();
}
/**
 * This start function will init some critical function 
 */
void  App_EXHMI::App_EXHMI_Start()
{
	// init atXYZ Service in the fist running time
	// atXYZ.Run_Service();
}  
/**
 * Restart function of SNM  app
 */
void  App_EXHMI::App_EXHMI_Restart()
{

}
/**
 * Execute fuction of SNM app
 */
void  App_EXHMI::App_EXHMI_Execute()
{	
	// atXYZ.Run_Service();
    if(atEXHMI.User_Mode == APP_USER_MODE_DEBUG)
    {
		
    }   
}
void  App_EXHMI::App_EXHMI_Suspend(){}
void  App_EXHMI::App_EXHMI_Resume(){}	  
void  App_EXHMI::App_EXHMI_End(){}

#endif