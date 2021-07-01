#include "Menu.h"
#include "IMenu.h"
#define buttonUP 3
#define buttonConfirm  2
#define buttonDown 1
//--------------- VARIAVEIS GLOBAIS -----------------------------
IMenu menu1;
menu1.setTitle("test");
IMenu listTest[3] = {menu1};
String list_menus[] = {"Analogicos", "Digitais", "Creditos",  "Creditos1",  "Creditos2"};
Menu mainMenu(listTest, 5);
void setup(){
   pinMode(buttonDown, INPUT_PULLUP);
   pinMode(buttonUP, INPUT_PULLUP);
   mainMenu.start();
   mainMenu.generateList();
}

void  loop(){
   mainMenu.buttonPressioned(digitalRead(buttonUP), digitalRead(buttonDown), digitalRead(buttonConfirm));
}
