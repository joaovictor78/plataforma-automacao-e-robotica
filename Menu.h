#ifndef menu
#define menu
#include "Arduino.h"
#include <glcd.h>
#include "ItemMenu.h"
#include "fonts/SystemFont5x7.h"  
class Menu{
  public: 
      Menu();
      void start(ItemMenu list[], int size_list);
      ItemMenu *copyList;
      void generateList();
      void countIndex();
      void buttonPressioned(int buttonUP, int buttonDown, int buttonConfirm);
  private: 
      int sizeList;
      void menuSelected(String title, int position);
      void menuNotSelected(String title, int position);
      void gerarMenu(int count, int position);
      int indicatorCursor =  0;
      String bk_list[4];
      bool isActive = false;
      int pointer = 0;
      int indicatorCursor2 = 0;
      int count, x = 0;
};
#endif
