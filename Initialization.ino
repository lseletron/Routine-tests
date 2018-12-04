/*------Set all outputs for a safe condition------*/
void initialization() //Set all outputs for a safe condition
{
  allLightsOn();
  lcd.backlight();
  homeScreen();
  if(initFlag)
  {
    lcd.setCursor(0,0);
    lcd.print("Ensaios de rotina   ");
    lcd.setCursor(0,1);
    lcd.print("Inicializando...    ");
    delay(500);
    
    //Initializes U2
    Wire.beginTransmission(0x020);
    //Set outputs state: B1, B2, B3, B4, B5 e B6.
    Wire.write(0b11111111);
    Wire.endTransmission();
    
    //Initializes U3
    Wire.beginTransmission(0x022);
    //Set outputs state: M1, M2, M3, M4, M5, M6, M7 e Test_Fonte.
    Wire.write(0b11111111);
    Wire.endTransmission();

    //Initializes U5
    Wire.beginTransmission(0x021);
    //Set outputs state: B7, B8, B9, B10, Verde, Amarelo, Vermelho e Reset_Fonte.
    Wire.write(0b11111111);
    Wire.endTransmission();

    //Initializes U6
    Wire.beginTransmission(0x023);
    //Set outputs state: MODO, ISO, RESET-Hi-Pot, TEST-Hi-Pot, CN-CASF, Reversivel, AT-Fuga e ATC-Control.
    Wire.write(0b11111111);
    Wire.endTransmission();

    lcd.setCursor(0,1);
    lcd.print("Inicializando    ok!");
    delay(1000);
    initFlag = false;
  }
}
