/*
  11/06/2018
  1.0 - Initial version of the routine testing system program
  Author: Eng. Luciano da Silva
*/

/*----------- (Important needed libraries) -----------*/
#include "Arduino.h"
#include "Wire.h"
#include "LiquidCrystal_I2C.h"

/*--------------- (Declare constants) ---------------*/
const uint16_t tbase = 400;      //Time for base control (Leakage current)
/*---------------- (Declare objects) ----------------*/

//Set the LCD address to 0x38 for a 20 chars 4 line display
//set the pins on the I2C chip used for LCD connections:
//             addr, en, rw, rs, d4, d5, d6, d7, bl, blpol 
LiquidCrystal_I2C lcd(0x38, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); //set the LCD I2C address

#define downKey 11         //Button to select screen up in digital 11
#define upKey   10         //Button to select screen down on digital 10
#define exitKey 9          //Exit button on digital 9
#define setKey  8          //Confirm button on digital 8
#define buttonStart  0     //Button to trigger test start
#define buttonStop   1     //Abort test button
#define procHipot 12       //Hi-Pot operation indicator signal
#define passHipot 13       //Hi-Pot approval indicator signal
#define failHipot A0       //Hi-Pot fault indicator signal
#define procPowerAc A1     //AC power supply operation signal
#define failPowerAc A2     //AC power supply failure signal
#define passPowerAc A3     //AC power supply approval signal
#define syncPowerAc 6      //AC power supply synchronism signal
#define setPoint1Na 2      //Set Point 1 ok in high (INT0)
#define setPoint1Nf 3      //Set Point 1 ok in low (INT1)
#define setPoint2Na 4      //Set Point 2 ok in high
#define setPoint2Nf 5      //Set Point 2 ok in low

/*-------------- (Declare variables) --------------*/
bool initFlag = true;
bool execFlag = false;
bool autoTestFlag = true;
bool homeFlag = true;
bool menu1 = true;
bool menu2 = true;
char classe = 0x01;
char range =  0x01;
char menu = 0x01;               //Variable to select menu
char subHomeMenu = 0x01;        //Variable to select subMenu from the start menu
bool flagDownKey = false;       //Clears down button flag
bool flagUpKey = false;         //Clears up button flag
bool flagExitKey = false;       //Clears exit button flag
bool flagSetKey = false;        //Clears set button flag
bool flagButtonStart = false;   //Clears start button flag
bool flagButtonStop = false;    //Clears stop button flag
bool flagHoldOn = false;        //System flag
bool flagRetestHipot = false;   //Prepares hi-pot retest
char setUp = 0x01;              //Setup counter
bool runFlag = true;            //To run leakage current test
bool hipotExecution = true;     //
bool powerAcExecution = true;   //
char data_0x020 = 0b11111111;   //Multiplexer data address 0x020
char data_0x021 = 0b11111111;   //Multiplexer data address 0x021
char data_0x022 = 0b11111111;   //Multiplexer data address 0x022
char data_0x023 = 0b11111111;   //Multiplexer data address 0x023
char data_0x0xx = 0b11111111;   //Multiplexer general purpose data address
char address = 0x020;           //Multiplexer address
int baseResult[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; //Measurement base
int multiplexOutput[10] = {0b11101111, 0b11011111, 0b10111111, 0b01111111, 0b11110111, 0b11111110, 0b11110111, 0b11111011, 0b11111110, 0b11111101};
int baseIndex = 0;              //Measurement base counter

/*-------------------------------------------------*/
void setup() /*-------- (Setup: Runs once) --------*/
{
  pinMode(buttonStart, INPUT_PULLUP); //Input for digital button 0 with internal pull-ups
  pinMode(buttonStop, INPUT_PULLUP);  //Input for digital button 1 with internal pull-ups
  pinMode(syncPowerAc, INPUT_PULLUP);
  pinMode(setKey, INPUT_PULLUP);
  pinMode(exitKey, INPUT_PULLUP);
  pinMode(upKey, INPUT_PULLUP);
  pinMode(downKey, INPUT_PULLUP);
  pinMode(procHipot, INPUT_PULLUP);   //Hi-Pot operation read input with internal pull-ups
  pinMode(passHipot, INPUT_PULLUP);   //Hi-Pot approval reading input with internal pull-ups
  pinMode(failHipot, INPUT_PULLUP);   //Input for disapproval reading by Hi-Pot with internal pull-ups
  pinMode(procPowerAc, INPUT_PULLUP); //Input for processing reading by AC power supply with internal pull-ups
  pinMode(failPowerAc, INPUT_PULLUP); //Input for failure reading by AC power supply with internal pull-ups
  pinMode(passPowerAc, INPUT_PULLUP); //Input for approval reading by AC power supply with internal Pull-ups
  pinMode(setPoint1Na,INPUT_PULLUP);  //Set point number 1 - NA
  pinMode(setPoint1Nf,INPUT_PULLUP);  //Set point number 1 - NF
  pinMode(setPoint2Na,INPUT_PULLUP);  //Set point number 2 - NA
  pinMode(setPoint2Nf,INPUT_PULLUP);  //Set point number 2 - NF

  lcd.begin(20,4);                    //Initialize the lcd for 20 chars 4 lines
  Wire.begin();                       //Initialize I2C communication

  initialization();
  autoTest();
} /*--(end setup)--*/

//=============================================================================

void loop() /*-------- (Loop: Runs constantly) -------*/
{
  if((menu1)|(menu2))
  {
    homeMenu();
  }

  if(execFlag)
  {
    execution();
  }
}/*--(end main loop)--*/
