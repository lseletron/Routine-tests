/*------Set of checks for system validation------*/
void autoTest() //Set of checks for system validation
{
  if(autoTestFlag)
  {
    for(int i = 0; i<3; i++) 
    {
      allLightsOn();
      lcd.backlight();
      delay(300);
      allLightsOff();
      lcd.noBacklight();
      delay(300);
    }

    yellowLightOn();
    lcd.backlight();    
    lcd.setCursor(0,2);
    lcd.print("Auto-teste...       ");
    atFugaOn();
    atcControlOn();
    psMemory7();       //Set power supply to 264Vac
    psTest();          //Turn on the power supply output

    multiplexer();

    lcd.setCursor(0,3);
    lcd.print("                    ");
    psReset();         //Turn off the power supply output
    atcControlOff();
    atFugaOff();
    lcd.setCursor(0,2);
    lcd.print("Auto-teste       ok!");
    yellowLightOff();
    greenLightOn();
    delay(2000);
    greenLightOff();
    lcd.clear(); //clear the screen

    autoTestFlag = false;
  }
}
