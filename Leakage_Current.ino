void leakageCurrent() //Leakage current
{
  lcd.setCursor(0,0);
  lcd.print("Teste em execucao!  ");
  lcd.setCursor(0,1);
  lcd.print("Corrente de fuga    ");
  runFlag = true;

    switch(range)                   //SubMenu variable control
    {
       case 0x01:                   //Case 1
            psMemory6();            //Active Power Supply Memory 6 = 253 VAC
            break;

       case 0x02:                   //Case 2
            psMemory7();            //Active Power Supply Memory 7 = 264 VAC
            break;

       case 0x03:                   //Case 3
            psMemory5();            //Active Power Supply Memory 5 = 242 VAC      
            break;
    
    } //end switch menu 

  psTest();                         //Active Power Supply
  while(runFlag)
  {
    switch(setUp)
    {
       case 0x01:                   //Case 1
             lcd.setCursor(0,2);
             lcd.print("Cond. Falha-Direto  ");
             casf();
             reverseOff();
             multiplexer();
             setUp++;               //increment setUp
             
             break;
       case 0x02:                   //Case 2
             lcd.setCursor(0,2);
             lcd.print("Cond. Falha-Reverso ");
             casf();
             reverseOn();
             multiplexer();
             setUp++;               //increment setUp             

             break;
       case 0x03:                   //Case 3
             lcd.setCursor(0,2);
             lcd.print("Cond. Normal-Reverso");
             cn();
             reverseOn();
             multiplexer();
             setUp++;               //increment setUp             
             
             break;
       case 0x04:                   //Case 4
             lcd.setCursor(0,2);
             lcd.print("Cond. Normal-Direto ");
             cn();
             reverseOff();
             multiplexer();
             setUp++;               //increment setUp

             runFlag = false;

             break;             
    } //end switch setUp
  }
psReset();        //Reset Power Supply
lcd.clear();      //clear the screen
setUp = 0x01;
}
