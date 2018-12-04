/*---Auxiliary Functions for Program Operation---*/
void homeScreen() //Home screen
{
  if(homeFlag)
  {
    lcd.clear(); //clear the screen
    lcd.setCursor(0,1);
    lcd.print("www.soniclear.com.br");    
    lcd.setCursor(0,2);
    lcd.print("Software versao: 1.0");
    delay(3000);
    lcd.clear(); //clear the screen
    homeFlag = false;
  }
}

void psMemory1() //Active Power Supply Memory 1 = 90 VAC
{
//******** Active M1 memory ********
  data_0x022 = data_0x022 & 0b01111111;
  Wire.beginTransmission(0x022);
  Wire.write(data_0x022);
  Wire.endTransmission();
  delay(120);
  data_0x022 = data_0x022 | 0b10000000;
  Wire.beginTransmission(0x022);
  Wire.write(data_0x022);
  Wire.endTransmission();
//********************************
}

void psMemory2() //Active Power Supply Memory 2 = 127 VAC
{
//******** Active M2 memory ********
  data_0x022 = data_0x022 & 0b10111111;
  Wire.beginTransmission(0x022);
  Wire.write(data_0x022);
  Wire.endTransmission();
  delay(120);
  data_0x022 = data_0x022 | 0b01000000;  
  Wire.beginTransmission(0x022);
  Wire.write(data_0x022);
  Wire.endTransmission();
//********************************
}

void psMemory3() //Active Power Supply Memory 3 = 210 VAC
{
//******** Active M3 memory ********
  data_0x022 = data_0x022 & 0b11011111;
  Wire.beginTransmission(0x022);
  Wire.write(data_0x022);
  Wire.endTransmission();
  delay(120);
  data_0x022 = data_0x022 | 0b00100000;  
  Wire.beginTransmission(0x022);
  Wire.write(data_0x022);
  Wire.endTransmission();
//********************************
}

void psMemory4() //Active Power Supply Memory 4 = 220 VAC
{
//******** Active M4 memory ********
  data_0x022 = data_0x022 & 0b11101111;
  Wire.beginTransmission(0x022);
  Wire.write(data_0x022);
  Wire.endTransmission();
  delay(120);
  data_0x022 = data_0x022 | 0b00010000;
  Wire.beginTransmission(0x022);
  Wire.write(data_0x022);
  Wire.endTransmission();
//********************************
}

void psMemory5() //Active Power Supply Memory 5 = 242 VAC
{
//******** Active M5 memory ********
  data_0x022 = data_0x022 & 0b11110111;
  Wire.beginTransmission(0x022);
  Wire.write(data_0x022);
  Wire.endTransmission();
  delay(120);
  data_0x022 = data_0x022 | 0b00001000;  
  Wire.beginTransmission(0x022);
  Wire.write(data_0x022);
  Wire.endTransmission();
//********************************
}

void psMemory6() //Active Power Supply Memory 6 = 253 VAC
{
//******** Active M6 memory ********
  data_0x022 = data_0x022 & 0b11111011;
  Wire.beginTransmission(0x022);
  Wire.write(data_0x022);
  Wire.endTransmission();
  delay(120);
  data_0x022 = data_0x022 | 0b00000100;  
  Wire.beginTransmission(0x022);
  Wire.write(data_0x022);
  Wire.endTransmission();
//********************************
}

void psMemory7() //Active Power Supply Memory 7 = 264 VAC
{
//******** Active M7 memory ********
  data_0x022 = data_0x022 & 0b11111101;
  Wire.beginTransmission(0x022);
  Wire.write(data_0x022);
  Wire.endTransmission();
  delay(120);
  data_0x022 = data_0x022 | 0b00000010;  
  Wire.beginTransmission(0x022);
  Wire.write(data_0x022);
  Wire.endTransmission();
//********************************
}

void psTest() //Active Power Supply
{
//***** Active power supply  *****
  powerAcExecution = true;
  data_0x022 = data_0x022 & 0b11111110;
  Wire.beginTransmission(0x022);
  Wire.write(data_0x022);
  Wire.endTransmission();
  delay(120);
  data_0x022 = data_0x022 | 0b00000001;
  Wire.beginTransmission(0x022);
  Wire.write(data_0x022);
  Wire.endTransmission();
  delay(50);
  while((digitalRead(procPowerAc)) && (autoTestFlag == true)) //There are cases where the pulse in "procPowerAc" is not detected.
  {
    lcd.setCursor(0,0);
    lcd.print("Erro: 002           ");
    lcd.setCursor(0,1);
    lcd.print("Verificar fonte AC! ");    
    lcd.setCursor(0,2);
    lcd.print("Desligado / Avariado");
    yellowLightOff();
    redLightOn();
    powerAcExecution = false;
  }
  
  while(powerAcExecution == false)
  {
    yellowLightOn();
    redLightOff();
    lcd.setCursor(0,0);
    lcd.print("Ensaios de rotina   ");
    lcd.setCursor(0,1);
    lcd.print("Inicializando    ok!");   
    lcd.setCursor(0,2);
    lcd.print("Auto-teste...       ");
    delay(4000);
    data_0x022 = data_0x022 & 0b11111110;
    Wire.beginTransmission(0x022);
    Wire.write(data_0x022);
    Wire.endTransmission();
    delay(200);
    data_0x022 = data_0x022 | 0b00000001;
    Wire.beginTransmission(0x022);
    Wire.write(data_0x022);
    Wire.endTransmission();
    
    powerAcExecution = true; 
  }
//********************************
}

void psReset() //Reset Power Supply
{
//***** Disable power supply *****
  data_0x021 = data_0x021 & 0b01111111;
  Wire.beginTransmission(0x021);
  Wire.write(data_0x021);
  Wire.endTransmission();
  delay(120);
  data_0x021 = data_0x021 | 0b10000000;  
  Wire.beginTransmission(0x021);
  Wire.write(data_0x021);
  Wire.endTransmission();
//********************************
}

void cn() //Normal condition
{
//******* Normal condition *******
  data_0x023 = data_0x023 & 0b11101111;
  Wire.beginTransmission(0x023);
  Wire.write(data_0x023);
  Wire.endTransmission();
//********************************
}

void casf() //Fault condition
{
//******* Fault condition ********
  data_0x023 = data_0x023 | 0b00010000;
  Wire.beginTransmission(0x023);
  Wire.write(data_0x023);
  Wire.endTransmission();
//********************************
}

void reverseOn() //Phase inversion
{
//****** Phase inversion on ******
  data_0x023 = data_0x023 & 0b11011111;
  Wire.beginTransmission(0x023);
  Wire.write(data_0x023);
  Wire.endTransmission();
//********************************
}

void reverseOff() //Normal position phases
{
//***** Phase inversion off ******
  data_0x023 = data_0x023 | 0b00100000;
  Wire.beginTransmission(0x023);
  Wire.write(data_0x023);
  Wire.endTransmission();
//********************************
}

void atFugaOn() //Self test leakage current on
{
//********************************
  data_0x023 = data_0x023 & 0b10111111;
  Wire.beginTransmission(0x023);
  Wire.write(data_0x023);
  Wire.endTransmission();
//********************************
}

void atFugaOff() //Self test leakage current off
{
//********************************
  data_0x023 = data_0x023 | 0b01000000;
  Wire.beginTransmission(0x023);
  Wire.write(data_0x023);
  Wire.endTransmission();
//********************************  
}

void atcControlOn() //Self test leakage current control on
{
//********************************
  data_0x023 = data_0x023 & 0b01111111;
  Wire.beginTransmission(0x023);
  Wire.write(data_0x023);
  Wire.endTransmission();
//********************************  
}

void nonInsulated() //Drives insulation relay
{
//********************************
  data_0x023 = data_0x023 & 0b11111101;
  Wire.beginTransmission(0x023);
  Wire.write(data_0x023);
  Wire.endTransmission();
//********************************  
}

void insulated() //Establishes insulation during HI-Pot test
{
//********************************
  data_0x023 = data_0x023 | 0b00000010;
  Wire.beginTransmission(0x023);
  Wire.write(data_0x023);
  Wire.endTransmission();
//********************************  
}

void hipotModeOn() //Hi-pot mode on
{
//********************************
  data_0x023 = data_0x023 & 0b11111110;
  Wire.beginTransmission(0x023);
  Wire.write(data_0x023);
  Wire.endTransmission();
//********************************  
}

void hipotModeOff() //Hi-pot mode off
{
//********************************
  data_0x023 = data_0x023 | 0b00000001;
  Wire.beginTransmission(0x023);
  Wire.write(data_0x023);
  Wire.endTransmission();
//********************************  
}

void testHipot() //Run hi-pot test
{
  data_0x023 = data_0x023 & 0b11110111;
  Wire.beginTransmission(0x023);
  Wire.write(data_0x023);
  Wire.endTransmission();
  delay(50);
  data_0x023 = data_0x023 | 0b00001000;
  Wire.beginTransmission(0x023); 
  Wire.write(data_0x023);
  Wire.endTransmission();
  hipotExecution = true;
}

void resetHipot() //Reset Hi-pot or abort the test
{
//********************************
  data_0x023 = data_0x023 & 0b11111011;
  Wire.beginTransmission(0x023);
  Wire.write(data_0x023);
  Wire.endTransmission();
  delay(50);
  data_0x023 = data_0x023 | 0b00000100;
  Wire.beginTransmission(0x023); 
  Wire.write(data_0x023);
  Wire.endTransmission();
  hipotExecution = false;
//******************************** 
}

void atcControlOff() //Self test leakage current control off
{
//********************************
  data_0x023 = data_0x023 | 0b10000000;
  Wire.beginTransmission(0x023);
  Wire.write(data_0x023);
  Wire.endTransmission();
//********************************  
}

void greenLightOn()
{
//********************************
  data_0x021 = data_0x021 & 0b11101111;
  Wire.beginTransmission(0x021);
  Wire.write(data_0x021);
  Wire.endTransmission();
//********************************
}

void greenLightOff()
{
//********************************
  data_0x021 = data_0x021 | 0b00010000;
  Wire.beginTransmission(0x021);
  Wire.write(data_0x021);
  Wire.endTransmission();
//********************************
}

void yellowLightOn()
{
//********************************
  data_0x021 = data_0x021 & 0b11011111;
  Wire.beginTransmission(0x021);
  Wire.write(data_0x021);
  Wire.endTransmission();
//********************************
}

void yellowLightOff()
{
//********************************
  data_0x021 = data_0x021 | 0b00100000;
  Wire.beginTransmission(0x021);
  Wire.write(data_0x021);
  Wire.endTransmission();
//********************************
}

void redLightOn()
{
//********************************
  data_0x021 = data_0x021 & 0b10111111;
  Wire.beginTransmission(0x021);
  Wire.write(data_0x021);
  Wire.endTransmission();
//********************************
}

void redLightOff()
{
//********************************
  data_0x021 = data_0x021 | 0b01000000;
  Wire.beginTransmission(0x021);
  Wire.write(data_0x021);
  Wire.endTransmission();
//********************************
}

void allLightsOn()
{
//********************************
  data_0x021 = data_0x021 & 0b10001111;
  Wire.beginTransmission(0x021);
  Wire.write(data_0x021);
  Wire.endTransmission();
//********************************
}

void allLightsOff()
{
//********************************
  data_0x021 = data_0x021 | 0b01110000;
  Wire.beginTransmission(0x021);
  Wire.write(data_0x021);
  Wire.endTransmission();
//********************************
}

void multiplexer()
{
  int k;
  for (int baseIndex = 0; baseIndex <= 9; baseIndex++)
    {
      if (baseIndex <= 5) 
      {
       address = 0x020;
       data_0x0xx = data_0x020;
       }else{
       address = 0x021;
       data_0x0xx = data_0x021;
      }
    k = baseControl(baseIndex);
  }
}

int baseControl(int xBase)
{
    int result;
    lcd.setCursor(0,3);
    lcd.print("Base de teste:      ");
    lcd.setCursor(15,3);
    lcd.print(xBase+1);

    //Bx on
    data_0x0xx = data_0x0xx & (multiplexOutput[xBase]);
    Wire.beginTransmission(address);
    Wire.write(data_0x0xx);
    Wire.endTransmission();
    
    delay(tbase);

    if(digitalRead(setPoint1Na))
    {
     baseResult[xBase] = 1;
      while(digitalRead(buttonStop))
      {
        redLightOn();
      }
    redLightOff();
    yellowLightOn();
    }
    if (!digitalRead(setPoint1Na))
    {
     baseResult[xBase] = 0;
    }
    
    //Bx off
    data_0x0xx = data_0x0xx | ~(multiplexOutput[xBase]);
    Wire.beginTransmission(address);
    Wire.write(data_0x0xx);
    Wire.endTransmission();  
    
    return result;
}
