#include "Menu.h"
#include "ItemMenu.h"
#define buttonUP 3
#define buttonConfirm  2
#define buttonDown 1
#include <glcd.h>
#include "fonts/SystemFont5x7.h"
// ---------- PROTOTIPO DE FUNÇOES ------------------------------
void printAnalogico();
void printDigital();
void printCreditos();
void limparTela();
// ---------- DECLARACAO DE OBJETOS ------------------------------  
Menu mainMenu;
Menu menuAnalogicos;
Menu menuDigitais;

//  ---------- ARRAY DE OBJETOS --------------------------------
ItemMenu listMainMenu[] = {
  ItemMenu("Analogicos", printAnalogico),
  ItemMenu("Digitais", printDigital),
  ItemMenu("Creditos", printCreditos),
  ItemMenu("Test1", limparTela),
  ItemMenu("Test2", limparTela),
  ItemMenu("Test3", limparTela)
};

ItemMenu listAnalogicosMenu[] = {
  ItemMenu("Motor de passo", printAnalogico),
  ItemMenu("Motor", printDigital),
  ItemMenu("Motor1", printCreditos),
  ItemMenu("Motor2", limparTela),
  ItemMenu("Motor3", limparTela),
  ItemMenu("Motor4", limparTela)
};
ItemMenu listDigitaisMenu[] = {
  ItemMenu("Sensor ultrassonico", printAnalogico),
  ItemMenu("Sensor de temperatura", printDigital),
  ItemMenu("Sensor de gás", printCreditos),
  ItemMenu("Sensor de cores", limparTela),
  ItemMenu("Sensor de proximidade", limparTela),
  ItemMenu("Sensor de umidade", limparTela)
};
//----------- FUNCOES ----------------------------------------
void printAnalogico(){
  GLCD.ClearScreen();
  menuAnalogicos.start(listAnalogicosMenu, 6);
  while(true){
    menuAnalogicos.buttonPressioned(digitalRead(buttonUP), digitalRead(buttonDown), digitalRead(buttonConfirm));
  }
}
void printDigital(){
  GLCD.ClearScreen();
  menuDigitais.start(listDigitaisMenu, 6);
  while(true){
    menuDigitais.buttonPressioned(digitalRead(buttonUP), digitalRead(buttonDown), digitalRead(buttonConfirm));
  }
}
void printCreditos(){
  GLCD.ClearScreen();
  GLCD.CursorTo(0, 0);
  GLCD.println("*--- Creditos ---*");
  GLCD.CursorTo(0, 2);
  GLCD.println("Desenvolvido por: ");
  GLCD.CursorTo(0, 4);
  GLCD.println("Orientador: Silas Jader");
  GLCD.CursorTo(0, 5);
  GLCD.println("Aluno: João Victor B. da Silva");
}
void limparTela(){
  GLCD.ClearScreen();
}
//--------------- VARIAVEIS GLOBAIS -----------------------------

ItemMenu list[] = {
  ItemMenu("Analogicos", printAnalogico),
  ItemMenu("Digitais", printDigital),
  ItemMenu("Creditos", printCreditos),
  ItemMenu("Test1", limparTela),
  ItemMenu("Test2", limparTela),
  ItemMenu("Test3", limparTela)
  };
// --------------------------------------------------------------------
void setup(){
   pinMode(buttonDown, INPUT_PULLUP);
   pinMode(buttonUP, INPUT_PULLUP);
   pinMode(buttonConfirm, INPUT_PULLUP);
   mainMenu.start(listMainMenu, 6);
}

void  loop(){
  mainMenu.buttonPressioned(digitalRead(buttonUP), digitalRead(buttonDown), digitalRead(buttonConfirm));
}
