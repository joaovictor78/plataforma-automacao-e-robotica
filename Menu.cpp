#include "Arduino.h"
#include "Menu.h"
#include "IMenu.h"
#include <glcd.h>
#include "fonts/SystemFont5x7.h"  

//****************************************************************
Menu::Menu(IMenu list[], int size_list){
  for(int count = 0; count < size_list; count++){
    list_category_name[count] =  list[count];
  }
};
void Menu::start(){
  GLCD.Init();
  GLCD.SelectFont(System5x7, BLACK); 
  GLCD.CursorToXY(GLCD.Width * 0.2, 3);
  GLCD.print("Menu Principal");
  GLCD.DrawRoundRect(17,0,95,12, 5);  // rounded rectangle around text area   
  GLCD.CursorToXY(5, 20);
  GLCD.SelectFont(SystemFont5x7, BLACK);// font for the default text area
}
void Menu::buttonPressioned( int buttonUP, int buttonDown, int buttonConfirm){
   if(buttonUP == 0){
         indicatorCursor--;
         delay(200);
     if(indicatorCursor < 0) indicatorCursor = 0;
   
     generateList();
     
   }
   else if(buttonDown == 0){
     indicatorCursor++;
     delay(200);
     if(indicatorCursor > 2) indicatorCursor = 2;
     generateList();
   }
   else if(buttonConfirm == 0){
    
   }
}
void countIndicator(){
  int firstIndex = 0;
  
}
void Menu::generateList(){
   
 
   int size_list = 5;
   for(int count = 0; count < size_list; count ++){
    if(count == indicatorCursor){
          menuSelected(String(list_category_name[count].getTitle()), count);
    } else{
          menuNotSelected(String(list_category_name[count].getTitle()), count);
    }
   }
}
void Menu::menuSelected(String title, int position){
    position +=3; 
    GLCD.CursorTo(0, position);
    GLCD.SelectFont(System5x7);
    GLCD.SetFontColor(BLACK); 
    GLCD.print(">"); 
    GLCD.SetFontColor(WHITE); 
    GLCD.println(" " + title);
}
void Menu::menuNotSelected(String title, int position){
    position +=3;
    GLCD.CursorTo(0, position);
    GLCD.SelectFont(System5x7);
    GLCD.SetFontColor(BLACK); 
    GLCD.println("  " + title); 
}
