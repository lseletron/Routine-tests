void homeMenu()                                       //Shows the sub menu current home
{
  lcd.setCursor(0,0);
  lcd.print("    Menu inicial    ");
  if(!digitalRead(upKey))     flagUpKey     = true;   //Up button pressed? set flag
  if(!digitalRead(downKey))   flagDownKey   = true;   //Down button pressed? set flag
   
   if(digitalRead(upKey) && flagUpKey)                //Up button released and flag set?
   {                                                  //yep...
      flagUpKey = false;                              //Clear flag
      
      subHomeMenu++;                                  //increment subHomeMenu
      
      if(subHomeMenu > 3) subHomeMenu = 0x01;         //if greater than 3, returns to 1
   
   } //end upKey
   
   if(digitalRead(downKey) && flagDownKey)            //Down button released and flag set?
   {                                                  //yep...
      flagDownKey = false;                            //Clear flag
      
      subHomeMenu--;                                  //decrements subHomeMenu
      
      if(subHomeMenu < 1) subHomeMenu = 0x03;         //if less than 1, it returns to 3

   } //end downKey

if(menu1){
  
    switch(subHomeMenu)                               //SubMenu variable control
    {
       case 0x01:                                     //Case 1
             lcd.setCursor(0,1);
             lcd.print("Selecione produto:  ");
             lcd.setCursor(0,3);
             lcd.print(">   Eletromedico   <");
             classe = 0x01;  

             break;
       case 0x02:                                     //Case 2
             lcd.setCursor(0,1);
             lcd.print("Selecione produto:  ");
             lcd.setCursor(0,3);
             lcd.print(">  Eletrodomestico <");
             classe = 0x02;    

             break;
       case 0x03:                                     //Case 2
             lcd.setCursor(0,1);
             lcd.print("Selecione produto:  ");;
             lcd.setCursor(0,3);
             lcd.print(">   Nao aplicavel  <");
             classe = 0x03;     
             
             break;
    
    } //end switch menu

  if(!digitalRead(setKey))     flagSetKey     = true; //set button pressed? set flag
  if(digitalRead(setKey) && flagSetKey)               //Set button released and flag set?
   {                                                  //yep...
      flagSetKey = false;                             //Clear flag
      menu1 = false;
      subHomeMenu = 0x01;
   }
}

if((!menu1)&&(menu2)){

    switch(subHomeMenu)                               //SubMenu variable control
    {
       case 0x01:                                     //Case 1
             lcd.setCursor(0,1);
             lcd.print("Selecione tensao:    ");
             lcd.setCursor(0,3);
             lcd.print(">>     90-230V    <<");
             range = 0x01;

             break;
       case 0x02:                                     //Case 2
             lcd.setCursor(0,1);
             lcd.print("Selecione tensao:    ");
             lcd.setCursor(0,3);
             lcd.print(">>    100-240V    <<");
             range = 0x02;
             
             break;
       case 0x03:                                     //Case 2
             lcd.setCursor(0,1);
             lcd.print("Selecione tensao:    ");
             lcd.setCursor(0,3);
             lcd.print(">>    127/220V    <<");
             range = 0x03;
             
             break;
    
    } //end switch menu

    if(!digitalRead(setKey))     flagSetKey     = true; //set button pressed? set flag
      if(digitalRead(setKey) && flagSetKey)             //Set button released and flag set?
      {                                                 //yep...
        flagSetKey = false;                             //Clear flag       
        menu2 = false;
        execFlag = true;
        lcd.clear(); //clear the screen
      }
  }
} //end homeMenu
