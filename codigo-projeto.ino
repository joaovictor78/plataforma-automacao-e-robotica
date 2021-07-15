#include "Menu.h"
#include "IMenu.h"
#define buttonUP 3
#define buttonConfirm  2
#define buttonDown 1
#include <glcd.h>
#include "fonts/SystemFont5x7.h"  
//--------------- VARIAVEIS GLOBAIS -----------------------------
String listTest[] = {"Analogicos", "Digitais", "Creditos", "Teste", "Teste1", "Teste2", "Teste3", "Teste4", "Teste5", "Teste6", "Teste7", "Teste8"};
Menu mainMenu;
void setup(){
   pinMode(buttonDown, INPUT_PULLUP);
   pinMode(buttonUP, INPUT_PULLUP);
   mainMenu.start(listTest, 12);
}

void  loop(){
   mainMenu.buttonPressioned(digitalRead(buttonUP), digitalRead(buttonDown), digitalRead(buttonConfirm));
}
