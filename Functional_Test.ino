void functionalTest() //Functional test
{
  lcd.clear(); //clear the screen
  lcd.setCursor(0,0);
  lcd.print("Teste em execucao!  ");
  lcd.setCursor(0,1);
  lcd.print("Funcional           ");

    switch(range)                     //SubMenu variable control
    {
       case 0x01:                     //Case 1
            lcd.setCursor(0,2);
            lcd.print("Alimentacao:   90Vac");            
            psMemory1();              //Active Power Supply Memory 1 = 90 VAC
            psTest();                 //Active Power Supply             
            while(!flagHoldOn)
            {
              lcd.setCursor(0,3);
              lcd.print("Pressione: Continuar");
              if(!digitalRead(buttonStart))     flagButtonStart     = true;   //Start button pressed? set flag
              if(digitalRead(buttonStart) && flagButtonStart)                 //Up button released and flag set?
                {                                                             //yep...
                   flagButtonStart = false;
                   flagHoldOn = true;
                 }
            }
            flagHoldOn = false;
            lcd.setCursor(0,2);
            lcd.print("Alimentacao:  253Vac"); 
            psMemory6();              //Active Power Supply Memory 6 = 253 VAC
            while(!flagHoldOn)
            {
              lcd.setCursor(0,3);
              lcd.print("Pressione: Continuar");
              if(!digitalRead(buttonStart))     flagButtonStart     = true;   //Start button pressed? set flag
              if(digitalRead(buttonStart) && flagButtonStart)                 //Up button released and flag set?
                {                                                             //yep...
                   flagButtonStart = false;
                   flagHoldOn = true;
                 }
                
            }
            flagHoldOn = false;
            psReset();                //Reset Power Supply
            break;

       case 0x02:                     //Case 2
            lcd.setCursor(0,2);
            lcd.print("Alimentacao:   90Vac");            
            psMemory1();              //Active Power Supply Memory 1 = 90 VAC            
            psTest();                 //Active Power Supply             
            while(!flagHoldOn)
            {
              lcd.setCursor(0,3);
              lcd.print("Pressione: Continuar");
              if(!digitalRead(buttonStart))     flagButtonStart     = true;   //Start button pressed? set flag
              if(digitalRead(buttonStart) && flagButtonStart)                 //Up button released and flag set?
                {                                                             //yep...
                   flagButtonStart = false;
                   flagHoldOn = true;
                 }
            }
            flagHoldOn = false;
            lcd.setCursor(0,2);
            lcd.print("Alimentacao:  264Vac"); 
            psMemory7();             //Active Power Supply Memory 7 = 264 VAC
            while(!flagHoldOn)
            {
              lcd.setCursor(0,3);
              lcd.print("Pressione: Continuar");
              if(!digitalRead(buttonStart))     flagButtonStart     = true;   //Start button pressed? set flag
              if(digitalRead(buttonStart) && flagButtonStart)                 //Up button released and flag set?
                {                                                             //yep...
                   flagButtonStart = false;
                   flagHoldOn = true;
                 }
            }
            flagHoldOn = false;
            psReset();               //Reset Power Supply
            break;
       
       case 0x03:                     //Case 3
            lcd.setCursor(0,2);
            lcd.print("Alimentacao:  220Vac");          
            psMemory4();             //Active Power Supply Memory 4 = 220 VAC
            psTest();                //Active Power Supply             
            while(!flagHoldOn)
            {
              lcd.setCursor(0,3);
              lcd.print("Pressione: Continuar");
              if(!digitalRead(buttonStart))     flagButtonStart     = true;   //Start button pressed? set flag
              if(digitalRead(buttonStart) && flagButtonStart)                 //Up button released and flag set?
                {                                                             //yep...
                   flagButtonStart = false;
                   flagHoldOn = true;
                 }
            }
            flagHoldOn = false;
            lcd.setCursor(0,2);
            lcd.print("Alimentacao:  127Vac"); 
            psMemory2();             //Active Power Supply Memory 2 = 127 VAC
            while(!flagHoldOn)
            {
              lcd.setCursor(0,3);
              lcd.print("Pressione: Continuar");
              if(!digitalRead(buttonStart))     flagButtonStart     = true;   //Start button pressed? set flag
              if(digitalRead(buttonStart) && flagButtonStart)                 //Up button released and flag set?
                {                                                             //yep...
                   flagButtonStart = false;
                   flagHoldOn = true;
                 }
            }
            flagHoldOn = false;
            psReset();               //Reset Power Supply
            break;
    
    } //end switch menu 
 
  lcd.clear(); //clear the screen
  casf();
}
