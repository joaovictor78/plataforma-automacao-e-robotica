#include "Menu.h"
#include "ItemMenu.h"
#define buttonUP 3
#define buttonConfirm  2
#define buttonDown 1
#define backButton 0
#include <glcd.h>
#include "fonts/SystemFont5x7.h"
// ---------- PROTOTIPO DE FUNÇOES ------------------------------
void imprimirCreditos();
void limparTela();
// ---------- DECLARACAO DE OBJETOS ------------------------------  
Menu mainMenu("Menu principal");
//  ---------- ARRAY DE OBJETOS --------------------------------
ItemMenu listSensoresAnalogicos[] = {
  ItemMenu("Ultrassonico",{}, 1),
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
  ItemMenu("Creditos", {}, 0, false, imprimirCreditos)
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
void limparTela(){
  GLCD.ClearScreen();
}
// --------------------------------------------------------------------
void setup(){
   pinMode(buttonDown, INPUT_PULLUP);
   pinMode(buttonUP, INPUT_PULLUP);
   pinMode(buttonConfirm, INPUT_PULLUP);
   pinMode(backButton, INPUT_PULLUP);
   mainMenu.start(listMainMenu, 3);
}

void  loop(){
     mainMenu.buttonPressioned(digitalRead(buttonUP), digitalRead(buttonDown), digitalRead(buttonConfirm), digitalRead(backButton));
}
