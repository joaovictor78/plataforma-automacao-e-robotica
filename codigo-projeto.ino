#include "Menu.h"
#include "IMenu.cpp"
#define buttonUP 3
#define buttonConfirm  2
#define buttonDown 1
//--------------- VARIAVEIS GLOBAIS -----------------------------
//IMenu listTest[3] = {};
String list_menus[] = {"Analogicos", "Digitais", "Creditos",  "Creditos1",  "Creditos2"};
Menu mainMenu(list_menus);
void setup(){
   pinMode(buttonDown, INPUT_PULLUP);
   pinMode(buttonUP, INPUT_PULLUP);
   mainMenu.start();
   mainMenu.generateList();
}

void  loop(){
   mainMenu.buttonPressioned(digitalRead(buttonUP), digitalRead(buttonDown), digitalRead(buttonConfirm));
}
