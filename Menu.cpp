#include "Arduino.h"
#include "Menu.h"
#include <glcd.h>
#include "fonts/SystemFont5x7.h"  

//****************************************************************
Menu::Menu(){}
void Menu::start(String list[], int size_list){
  sizeList = size_list;
  for (auto i = 0; i < size_list; i++) list_category_name[i] = list[i];
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
         
   }
}
void Menu::generateList(){
    if(isActive == true){
          for(int count = 0; count < 4; count++){
              gerarMenu(count, NULL);
          }
          if(indicatorCursor == 3){
            bk_list[0] = list_category_name[pointer - 2];
            bk_list[1] = list_category_name[pointer - 1];
            bk_list[2] = list_category_name[pointer];
            bk_list[3] = list_category_name[pointer +1];
          } 
          if(indicatorCursor == 0) {
            bk_list[0] = list_category_name[pointer + 1];
            bk_list[1] = list_category_name[pointer + 2];
            bk_list[2] = list_category_name[pointer + 3];
            bk_list[3] = list_category_name[pointer + 4];
          }
    }
   else{
            bk_list[0] = list_category_name[0];
            bk_list[1] = list_category_name[1];
            bk_list[2] = list_category_name[2];
            bk_list[3] = list_category_name[3];
      for(int x = 0; x < 4; x++){
           if(x == indicatorCursor){
            menuSelected(list_category_name[x], x);
            } else{
              menuNotSelected(list_category_name[x], x);
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
