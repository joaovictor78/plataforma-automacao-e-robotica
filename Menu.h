#ifndef menu
#define menu
#include "Arduino.h"
#include <glcd.h>
#include "fonts/SystemFont5x7.h"  
#include "IMenu.h"
class Menu{
  public: 
      Menu(IMenu list[], int size_list);
      void start();
      void generateList();
      void buttonPressioned(int buttonUP, int buttonDown, int buttonConfirm);
  private: 
      int sizeList;
      void menuSelected(String title, int position);
      void menuNotSelected(String title, int position);
      IMenu list_category_name[0];
      int count, indicatorCursor = 0;
      
};
#endif
