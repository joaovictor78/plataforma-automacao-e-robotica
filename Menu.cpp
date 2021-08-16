#include "Arduino.h"
#include "Menu.h"
#include <glcd.h>
#include "fonts/SystemFont5x7.h"  
#include "LinkedList.h"
//****************************************************************
Menu::Menu(String tag){
  this->tag = tag;
}
void bannerMenu(String tag){
   GLCD.SelectFont(System5x7, BLACK); 
   GLCD.CursorToXY(GLCD.Width * 0.2, 3);
   GLCD.print(tag);
   GLCD.DrawRoundRect(17,0,95,12, 5);  // rounded rectangle around text area   
   GLCD.CursorToXY(5, 20);
   GLCD.SelectFont(SystemFont5x7, BLACK);// font for the default text area
}
void Menu::start(ItemMenu list[], int size_list){
   copyList = &list[0];
   routes = LinkedList<ItemMenu*>();
   sizeList = size_list;
   first_menu_list_size = size_list;
   routes.add(&copyList[0]);
   GLCD.Init();
   bannerMenu(tag);
   generateList();
}

void Menu::buttonPressioned(int buttonUP, int buttonDown, int buttonConfirm, int backButton){
   isActive = true;
   if(buttonUP == 0){
         indicatorCursor--;
         indicatorCursor2--;
         pointer--;
         delay(400);
     if(indicatorCursor < 0) indicatorCursor = 0;
     if(indicatorCursor2 < 0) indicatorCursor2 = 0;
     if(pointer < 0) pointer = 0;
     if(indicatorCursor == 0) {
            bk_list[0] = copyList[pointer].title;
            bk_list[1] = copyList[pointer + 1].title;
            bk_list[2] = copyList[pointer + 2].title;
            bk_list[3] = copyList[pointer  + 3].title;
     }
     generateList();

     
   }
   else if(buttonDown == 0){
     indicatorCursor++;
     indicatorCursor2++;
     pointer++;
     delay(400);
     if(indicatorCursor > 3 && sizeList > 4) indicatorCursor = 3;
     if(indicatorCursor > sizeList && sizeList < 4) indicatorCursor = sizeList;
     if(indicatorCursor2 > 4) indicatorCursor2 = 4;
     if(pointer > sizeList -1) pointer = sizeList -1;
     if(indicatorCursor2 == 4){
            bk_list[0] = copyList[pointer - 3].title;
            bk_list[1] = copyList[pointer - 2].title;
            bk_list[2] = copyList[pointer - 1].title;
            bk_list[3] = copyList[pointer].title;
     }
     generateList();
 
   }
   else if(buttonConfirm == 0){
         if(copyList[pointer].isMenu == true){
           sizeList =  copyList[pointer].list[0].size_list;
           GLCD.ClearScreen();
           bannerMenu(copyList[pointer].title);
           routes.add(copyList);
           copyList = &copyList[pointer].list[pointer];
           generateList();
           indicatorCursor = 0;
           indicatorCursor2 = 0;
           pointer = 0;
           delay(400);
         } else if(copyList[pointer].isMenu == false){
           copyList[pointer].action();
   } 
}
else if(backButton == 0){
      GLCD.ClearScreen();
      copyList =  routes.get(routes.size() - 1);
      if((routes.get(routes.size() - 1)) == routes.get(0)){
        bannerMenu(this->tag);
        sizeList = first_menu_list_size;
      } else{
        sizeList =  copyList->size_list;
        bannerMenu(copyList->title);
      }
      generateList();
      routes.pop();
      delay(400);
      
      
}
}

void Menu::generateList(){
    if(isActive == true && sizeList > 4){
           for(int count = 0; count < 4; count++){
              gerarMenu(count, NULL);
          }
    }
   else if(sizeList > 4){
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
   } else{
    if(indicatorCursor < sizeList){
         for(int x = 0; x < sizeList; x++){
           if(x == indicatorCursor){
            menuSelected(copyList[x].title, x);
            } else{
              menuNotSelected(copyList[x].title, x);
           }
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
