#include "Arduino.h"
#include "Menu.h"
#include <glcd.h>
#include "fonts/SystemFont5x7.h"  

//****************************************************************
Menu::Menu(){}
void Menu::start(ItemMenu list[], int size_list){
  sizeList = size_list;
  copyList = &list[0];
  GLCD.Init();
  GLCD.SelectFont(System5x7, BLACK); 
  GLCD.CursorToXY(GLCD.Width * 0.2, 3);
  GLCD.print("Menu Principal");
  GLCD.DrawRoundRect(17,0,95,12, 5);  // rounded rectangle around text area   
  GLCD.CursorToXY(5, 20);
  GLCD.SelectFont(SystemFont5x7, BLACK);// font for the default text area
  generateList();
}

void Menu::buttonPressioned( int buttonUP, int buttonDown, int buttonConfirm){
   isActive = true;
   if(buttonUP == 0){
         indicatorCursor--;
         pointer--;
         delay(400);
     if(indicatorCursor < 0) indicatorCursor = 0;
     if(pointer < 0) pointer = -1;
     generateList();

     
   }
   else if(buttonDown == 0){
     indicatorCursor++;
     indicatorCursor2++;
     pointer++;
     delay(400);
     if(indicatorCursor > 3) indicatorCursor = 3;
     if(pointer > sizeList -2) pointer = sizeList -2;
     generateList();
 
   }
   else if(buttonConfirm == 0){
         copyList[pointer].action();
   }
}

void Menu::generateList(){
    if(isActive == true){
          for(int count = 0; count < 4; count++){
              gerarMenu(count, NULL);
          }
          if(indicatorCursor == 3){
            bk_list[0] = copyList[pointer - 2].title;
            bk_list[1] = copyList[pointer - 1].title;
            bk_list[2] = copyList[pointer].title;
            bk_list[3] = copyList[pointer +1].title;
          } 
          if(indicatorCursor == 0) {
            bk_list[0] = copyList[pointer + 1].title;
            bk_list[1] = copyList[pointer +2].title;
            bk_list[2] = copyList[pointer +3].title;
            bk_list[3] = copyList[pointer  +4].title;
          }
    }
   else{
            bk_list[0] = copyList[0].title;
            bk_list[1] = copyList[1].title;
            bk_list[2] = copyList[2].title;
            bk_list[3] = copyList[3].title;
      for(int x = 0; x < 4; x++){
           if(x == indicatorCursor){
            menuSelected(bk_list[x], x);
            } else{
              menuNotSelected(bk_list[x], x);
           }
      }
   }   
}
void Menu::gerarMenu(int count, int position = NULL){
   position = (position == NULL) ? count : position;
   if(count == indicatorCursor){
            menuSelected(bk_list[position], count);
    } else{
            menuNotSelected(bk_list[position], count);
  }
}
void Menu::menuSelected(String title, int position){
    position +=3; 
    GLCD.SetTextMode(SCROLL_DOWN);
    GLCD.CursorTo(0, position);
    GLCD.SelectFont(System5x7);
    GLCD.SetFontColor(BLACK); 
    GLCD.print(">"); 
    GLCD.SetFontColor(WHITE); 
    GLCD.println(" " + title);
}
void Menu::menuNotSelected(String title, int position){
    position +=3;
    GLCD.SetTextMode(SCROLL_DOWN);
    GLCD.CursorTo(0, position);
    GLCD.SelectFont(System5x7);
    GLCD.SetFontColor(BLACK); 
    GLCD.println("  " + title); 
}
