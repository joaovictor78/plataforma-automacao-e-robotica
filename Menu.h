#ifndef menu
#define menu
#include "Arduino.h"
#include <glcd.h>
#include "fonts/SystemFont5x7.h"  
class Menu{
  public: 
      Menu(String list[]);
      void start();
      void generateList();
      void buttonPressioned(int buttonUP, int buttonDown, int buttonConfirm);
  private: 
      int sizeList;
      void menuSelected(String title, int position);
      void menuNotSelected(String title, int position);
      String list_category_name[100];
      int count, indicatorCursor = 0;
      
};
#endif
