void execution() //Routine where the tests are performed
{
  if((classe == 0x01)&&(range == 0x01))
  {
    lcd.setCursor(0,0);
    lcd.print("Pressione: Iniciar  ");
    
    if(!digitalRead(buttonStart)) flagButtonStart  = true;         //Start button pressed? set flag
    if(digitalRead(buttonStart) && flagButtonStart && digitalRead(procHipot)) //Start button released, flag set and not in processing?
      {
        flagButtonStart = false;                                   //Clear flag
        yellowLightOn();
        dielectricStrength();
        while(flagRetestHipot == true)
        {
          flagRetestHipot = false; //Reset retest
          dielectricStrength();    //If hi-pot fails, retest!
        }
        leakageCurrent();
        functionalTest();
        yellowLightOff();
      }
  }

  if((classe == 0x01)&&(range == 0x02))
  {
    lcd.setCursor(0,0);
    lcd.print("Pressione: Iniciar  ");
   
    if(!digitalRead(buttonStart)) flagButtonStart  = true;         //Start button pressed? set flag
    if(digitalRead(buttonStart) && flagButtonStart && digitalRead(procHipot)) //Start button released, flag set and not in processing?
      {
        flagButtonStart = false;                                   //Clear flag
        yellowLightOn();
        dielectricStrength();
        while(flagRetestHipot == true)
        {
          flagRetestHipot = false; //Reset retest
          dielectricStrength();    //If hi-pot fails, retest!
        }
        leakageCurrent();
        functionalTest();
        yellowLightOff();
      }
  }

  if((classe == 0x01)&&(range == 0x03))
  {
    lcd.setCursor(0,0);
    lcd.print("Pressione: Iniciar  ");
    
    if(!digitalRead(buttonStart)) flagButtonStart  = true;    //Start button pressed? set flag
    if(digitalRead(buttonStart) && flagButtonStart && digitalRead(procHipot)) //Start button released, flag set and not in processing?
      {
        flagButtonStart = false;                              //Clear flag
        yellowLightOn();
        dielectricStrength();
        while(flagRetestHipot == true)
        {
          flagRetestHipot = false; //Reset retest
          dielectricStrength();    //If hi-pot fails, retest!
        }
        leakageCurrent();
        functionalTest();
        yellowLightOff();
      }
  }
//*******************************************************************

  if((classe == 0x02)&&(range == 0x01))
  {
    lcd.setCursor(0,0);
    lcd.print("Pressione: Iniciar  ");
    
    if(!digitalRead(buttonStart)) flagButtonStart  = true;    //Start button pressed? set flag
    if(digitalRead(buttonStart) && flagButtonStart && digitalRead(procHipot)) //Start button released, flag set and not in processing?
      {
        flagButtonStart = false;                              //Clear flag
        yellowLightOn();
        dielectricStrength();
        while(flagRetestHipot == true)
        {
          flagRetestHipot = false; //Reset retest
          dielectricStrength();    //If hi-pot fails, retest!
        }
        functionalTest();
        yellowLightOff();
      }
  }

  if((classe == 0x02)&&(range == 0x02))
  {
    lcd.setCursor(0,0);
    lcd.print("Pressione: Iniciar  ");
    
    if(!digitalRead(buttonStart)) flagButtonStart  = true;    //Start button pressed? set flag
    if(digitalRead(buttonStart) && flagButtonStart && digitalRead(procHipot)) //Start button released, flag set and not in processing?
      {
        flagButtonStart = false;                              //Clear flag
        yellowLightOn();
        dielectricStrength();
        while(flagRetestHipot == true)
        {
          flagRetestHipot = false; //Reset retest
          dielectricStrength();    //If hi-pot fails, retest!
        }
        functionalTest();
        yellowLightOff();
      }
  }

  if((classe == 0x02)&&(range == 0x03))
  {
    lcd.setCursor(0,0);
    lcd.print("Pressione: Iniciar  ");
    
    if(!digitalRead(buttonStart)) flagButtonStart  = true;       //Start button pressed? set flag
    if(digitalRead(buttonStart) && flagButtonStart && digitalRead(procHipot)) //Start button released, flag set and not in processing?
      {
        flagButtonStart = false;                              //Clear flag
        yellowLightOn();
        dielectricStrength();
        while(flagRetestHipot == true)
        {
          flagRetestHipot = false; //Reset retest
          dielectricStrength();    //If hi-pot fails, retest!
        }
        functionalTest();
        yellowLightOff();
      }
  }
//*******************************************************************

  if((classe == 0x03)&&(range == 0x01))
  {
    lcd.setCursor(0,0);
    lcd.print("Pressione: Iniciar  ");
    
    if(!digitalRead(buttonStart)) flagButtonStart  = true;    //Start button pressed? set flag
    if(digitalRead(buttonStart) && flagButtonStart && digitalRead(procHipot)) //Start button released, flag set and not in processing?
      {
        flagButtonStart = false;                              //Clear flag
        yellowLightOn();
        functionalTest();
        yellowLightOff();
      }
  }

  if((classe == 0x03)&&(range == 0x02))
  {
    lcd.setCursor(0,0);
    lcd.print("Pressione: Iniciar  ");
    
    if(!digitalRead(buttonStart)) flagButtonStart  = true;     //Start button pressed? set flag
    if(digitalRead(buttonStart) && flagButtonStart && digitalRead(procHipot)) //Start button released, flag set and not in processing?
      {
        flagButtonStart = false;                              //Clear flag
        yellowLightOn();
        functionalTest();
        yellowLightOff();
      }
  }

  if((classe == 0x03)&&(range == 0x03))
  {
    lcd.setCursor(0,0);
    lcd.print("Pressione: Iniciar  ");
    
    if(!digitalRead(buttonStart)) flagButtonStart  = true;      //Start button pressed? set flag
    if(digitalRead(buttonStart) && flagButtonStart && digitalRead(procHipot)) //Start button released, flag set and not in processing?
      {
        flagButtonStart = false;                               //Clear flag
        yellowLightOn();
        functionalTest();
        yellowLightOff();
      }
  }
}
