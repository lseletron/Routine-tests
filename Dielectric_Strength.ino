void dielectricStrength()           //Dielectric strength test
{
  hipotModeOn();
  nonInsulated();
  if(digitalRead(procHipot))
  {
    lcd.setCursor(0,0);
    lcd.print("Teste em execucao!  ");
    lcd.setCursor(0,1);
    lcd.print("Rigidez Dieletrica  ");    
    lcd.setCursor(0,2);
    lcd.print("Resultado:          ");
    testHipot();
    delay(50);
    while(digitalRead(procHipot))
    {
      lcd.setCursor(0,0);
      lcd.print("Erro: 001           ");
      lcd.setCursor(0,1);
      lcd.print("Verificar Hi-Pot!   ");    
      lcd.setCursor(0,2);
      lcd.print("Desligado / Avariado");
      yellowLightOff();
      redLightOn();
    }
    redLightOff();
    delay(200);
    if(digitalRead(procHipot) && (hipotExecution) && (digitalRead(failHipot)))
    {    
      lcd.setCursor(0,0);
      lcd.print("Teste em execucao!  ");
      lcd.setCursor(0,1);
      lcd.print("Rigidez Dieletrica  ");    
      lcd.setCursor(0,2);
      lcd.print("Resultado:          ");
      yellowLightOn();
      delay(5000);
      testHipot();
    }
  }
  
  while(!digitalRead(procHipot))
  {
    lcd.setCursor(0,1);
    lcd.print("Rigidez Dieletrica  ");    
    lcd.setCursor(0,2);
    lcd.print("Resultado:          ");
  }
  delay(100);                       //Time to stabilize result reading //was 100
  
//************************************* APPROVED! *************************************
  if(!digitalRead(passHipot))
  {
    lcd.setCursor(0,2);
    lcd.print("Resultado: Aprovado!");
    greenLightOn();
    delay(1000);                    //Time to display approval message
    greenLightOff();
    resetHipot();
    lcd.clear();                    //clear the screen
  }

//*********************************** DISAPPROVED! ************************************
  if(!digitalRead(failHipot))
  {
    lcd.setCursor(0,2);
    lcd.print("Resultado: Reprovado");
    redLightOn();
    lcd.setCursor(0,3);
    lcd.print("Pressione: Iniciar  ");
    while(flagRetestHipot == false)
      {
       if(!digitalRead(buttonStart)) flagButtonStart  = true;    //Start button pressed? set flag
       if(digitalRead(buttonStart) && flagButtonStart) //Start button released, flag set and not in processing?
        {
          flagRetestHipot = true;   //Prepare retest
          flagButtonStart = false;
        }
      }
    redLightOff();
    resetHipot();                  //First pulse turns off alarm
    delay(1000);
    resetHipot();                  //Second pulse clears the test result
    lcd.clear();                   //clear the screen
  }
insulated();
hipotModeOff();
}
