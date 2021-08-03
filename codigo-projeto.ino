#include "Menu.h"
#include "ItemMenu.h"
#define buttonUP 3
#define buttonConfirm  2
#define buttonDown 1
#include <glcd.h>
#include "fonts/SystemFont5x7.h"
//--------------- VARIAVEIS GLOBAIS -----------------------------
enum TYPES_MENU {
  MENU_PRINCIPAL,
  MENU_ANALOGICOS,
  MENU_DIGITAIS
};
TYPES_MENU menus_selected = MENU_PRINCIPAL;
// ---------- PROTOTIPO DE FUNÇOES ------------------------------
void printAnalogico();
void printDigital();
void printCreditos();
void limparTela();
// ---------- DECLARACAO DE OBJETOS ------------------------------  
Menu mainMenu("Menu principal");
Menu menuAnalogicos("Analogicos");
Menu menuDigitais("Digitais");

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
  ItemMenu("Motor de passo", limparTela),
  ItemMenu("Motor", printDigital),
  ItemMenu("Motor1", printCreditos),
  ItemMenu("Motor2", limparTela),
  ItemMenu("Motor3", limparTela),
  ItemMenu("Motor4", limparTela)
};
ItemMenu listDigitaisMenu[] = {
  ItemMenu("S. ultrassonico", limparTela),
  ItemMenu("S. temperatura", printDigital),
  ItemMenu("S. gas", printCreditos),
  ItemMenu("S. cores", limparTela),
  ItemMenu("S. proximidade", limparTela),
  ItemMenu("S. umidade", limparTela)
};
//----------- FUNCOES ----------------------------------------
void printAnalogico(){
  GLCD.ClearScreen();
  menuAnalogicos.start(listAnalogicosMenu, 6);
  menus_selected = MENU_ANALOGICOS;
}
void printDigital(){
  GLCD.ClearScreen();
  menuDigitais.start(listDigitaisMenu, 6);
  menus_selected = MENU_DIGITAIS;
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
  switch(menus_selected){
  case MENU_PRINCIPAL
  :
     mainMenu.buttonPressioned(digitalRead(buttonUP), digitalRead(buttonDown), digitalRead(buttonConfirm));
    break;
  case MENU_ANALOGICOS:
    menuAnalogicos.buttonPressioned(digitalRead(buttonUP), digitalRead(buttonDown), digitalRead(buttonConfirm));
    break;
  case MENU_DIGITAIS:
    menuDigitais.buttonPressioned(digitalRead(buttonUP), digitalRead(buttonDown), digitalRead(buttonConfirm));
    break;
  }
 
}
