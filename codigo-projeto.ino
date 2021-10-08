#include "Menu.h"
#include "ItemMenu.h"
#include <Servo.h>
#define buttonUP 3
#define buttonConfirm  2
#define buttonDown 1
#define backButton 0
//--------------- PINOS DIGITAIS DISPONIVEIS NA PLACA DE TESTAR COMPONENTES -----------------
#define dig1 53
#define dig2 51
#define dig4PWM 4
#define analog0 A0
//---------------------------------------------------------------------------------------------
#include <glcd.h>
#include <Ultrasonic.h>
#include "fonts/SystemFont5x7.h"
//----------- VARIAVEIS GLOBAIS -----------------
int leituraBottao = 0;
// ---------- PROTOTIPO DE FUNÇOES ------------------------------
void imprimirCreditos();
void limparTela();
void loadingAnimation();
void testarUltrassonico();
void testarServoMotor();
void testarSensorDeLuminosidade();
void testarSensorGas();
void testarSensorChama();
// ---------- DECLARACAO DE OBJETOS ------------------------------  
Menu mainMenu("Menu principal");
//  ---------- ARRAY DE OBJETOS --------------------------------
ItemMenu listSensoresAnalogicos[] = {
  ItemMenu("Ultrassonico",{}, 0, false, testarUltrassonico),
  ItemMenu("Luminosidade",{},0, false, testarSensorDeLuminosidade),
  ItemMenu("Servo motor",{},0, false, testarServoMotor),
  ItemMenu("Sensor de gas",{},0, false, testarSensorGas),
  ItemMenu("Sensor de chama",{},0, false, testarSensorGas),
  
};
ItemMenu listSensoresAnalogicosEDigitais[] = {
  ItemMenu("Analogicos", listSensoresAnalogicos, 2, true),
  ItemMenu("Digitais", {}, 2, true)
};
ItemMenu listAtuadoresAnalogicosEDigitais[] = {
  ItemMenu("Analogicos",{}, 2, true),
  ItemMenu("Digitais", {}, 2, true)
};
ItemMenu listMainMenu[] = {
  ItemMenu("Sensores", listSensoresAnalogicosEDigitais,0, true),
  ItemMenu("Atuadores", listAtuadoresAnalogicosEDigitais,0, true),
  ItemMenu("Creditos", {}, 0, false, imprimirCreditos),
  ItemMenu("Test1"),
  ItemMenu("Test2"),
  ItemMenu("Test3")
};
void imprimirCreditos(){
  GLCD.ClearScreen();
  GLCD.CursorTo(0.5, 0);
  GLCD.println(" *--- Creditos ---*");
  GLCD.CursorTo(0, 2);
  GLCD.println("Desenvolvido por: ");
  GLCD.CursorTo(0, 4);
  GLCD.println("Orientador: Silas Jader");
  GLCD.CursorTo(0, 5);
  GLCD.println("Aluno: João Victor B. da Silva");
}
void loadingAnimation(){
   int countLoading = 0;
  while(countLoading < 3){
    GLCD.ClearScreen();
    String loadingIndicator = ""; 
    for(int count = 0; count < 4; count++){
      GLCD.SetFontColor(BLACK);
      GLCD.CursorTo(0, 2);
      GLCD.print("*********************");
      GLCD.CursorTo(0, 6);
      GLCD.print("*********************");
      GLCD.CursorTo(6, 4);
      GLCD.SetFontColor(BLACK);
      GLCD.print("Loading" + loadingIndicator);
      loadingIndicator += ".";
      delay(300);
  }
  countLoading++;
  }
}
void testarUltrassonico(){
  Ultrasonic ultrasonic(dig1, dig2);
  GLCD.ClearScreen();
  GLCD.SetFontColor(WHITE);
  GLCD.CursorTo(3, 0);
  GLCD.print(" Ultrassonico ");
  GLCD.CursorTo(0, 2);
  GLCD.SetFontColor(BLACK);
  GLCD.print("Conecte o sensor:");
  GLCD.CursorTo(0, 4);
  GLCD.print("Trig: D53");
  GLCD.CursorTo(0, 5);
  GLCD.print("Echo: D51");
  GLCD.SetFontColor(BLACK);
  GLCD.CursorToXY(0, 50);
  GLCD.print("Press:Ok to continue");
  GLCD.CursorTo(0, 0);
  delay(400);
  if(leituraBottao == 0){
    GLCD.ClearScreen();
    loadingAnimation();  
    GLCD.ClearScreen();
    while(true){
    if(digitalRead(backButton) == 0){
      break;
    }
    float cmMsec, inMsec;
    long microsec = ultrasonic.timing();
    cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
    inMsec = ultrasonic.convert(microsec, Ultrasonic::IN);
    //Exibe informacoes no serial monitor
    GLCD.CursorTo(0, 0);
    GLCD.print("Distancia em cm: ");
    GLCD.CursorTo(0, 3);
    GLCD.print(cmMsec);
    delay(1000);
    }
  }
}
void testarSensorDeLuminosidade(){
  while(true){
   if(digitalRead(backButton) == 0){
      break;
   }
   int ldr = analogRead(analog0);
   GLCD.SetFontColor(BLACK);
   GLCD.CursorToXY(0, 10);
   GLCD.ClearScreen();
   GLCD.print("Luminosidade:");
   GLCD.println(ldr);
   delay(1000);
  }
}
void testarServoMotor(){
  Servo s; // Variável Servo
  int pos = 40; // Posição Servo
  s.attach(dig4PWM);
  Serial.begin(9600);
  s.write(0); // Inicia motor posição zero
   GLCD.ClearScreen();
   GLCD.print(" Servo Motor ");
   GLCD.SetFontColor(BLACK);
   GLCD.CursorTo(0, 2);
   GLCD.println("posicao: ");
  while(true){
  if(digitalRead(backButton) == 0){
      break;
   }
  GLCD.CursorTo(0, 4);
      for(pos = 0; pos < 90; pos++){
         GLCD.CursorTo(0, 6);
         GLCD.println(pos);
         s.write(pos);
         delay(15);
  }
  delay(1000);
  for(pos = 90; pos >= 0; pos--)
  {
    GLCD.CursorTo(0, 6);
    GLCD.println(pos);
    s.write(pos);
    delay(15);
  }
  }
}
void testarSensorGas(){
 int leitura_sensor = 300;//DEFININDO UM VALOR LIMITE (NÍVEL DE GÁS NORMAL)
   GLCD.ClearScreen();
   GLCD.print(" Sensor de Gas ");
   GLCD.SetFontColor(BLACK);
   GLCD.CursorTo(0, 3);
   GLCD.println("NIVEL NORMAL DO GAS: 300");
  while(true){
    int valorDoGas = analogRead(analog0);
    GLCD.CursorTo(0, 5);
    GLCD.println(valorDoGas);
  }
}
void testarSensorChama(){
  while(true){
  int valorSensor = digitalRead(dig1);
  if(valorSensor == 1){
    GLCD.println("Detectou chama!");
  } else{
    GLCD.println("Nenhuma chama detectada!");
  }
  }
}
void limparTela(){
  GLCD.ClearScreen();
}
// --------------------------------------------------------------------
void setup(){
   pinMode(buttonDown, INPUT_PULLUP);
   pinMode(buttonUP, INPUT_PULLUP);
   pinMode(buttonConfirm, INPUT_PULLUP);
   pinMode(backButton, INPUT_PULLUP);
   pinMode(analog0, INPUT);
   pinMode(dig1, INPUT);
   mainMenu.start(listMainMenu, 6);
}

void  loop(){
     leituraBottao = digitalRead(buttonConfirm);
     mainMenu.buttonPressioned(digitalRead(buttonUP), digitalRead(buttonDown), digitalRead(buttonConfirm), digitalRead(backButton));
}
