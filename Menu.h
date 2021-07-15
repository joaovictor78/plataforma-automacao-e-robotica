#ifndef menu
#define menu
#include "Arduino.h"
#include <glcd.h>
#include "fonts/SystemFont5x7.h"  
class Menu{
  public: 
      Menu();
      void start(String list[], int size_list);
      void generateList();
      void countIndex();
      void buttonPressioned(int buttonUP, int buttonDown, int buttonConfirm);
  private: 
      int sizeList;
      void menuSelected(String title, int position);
      void gerarMenu(int count, int position);
      void menuNotSelected(String title, int position);
      String list_category_name[100];
      String bk_list[4];
      int indicatorCursor =  0;
      int indicatorCursor2 = 0;
      int pointer = 0;
      int count, x = 0;
      bool isActive = false;
      
};
#endif
