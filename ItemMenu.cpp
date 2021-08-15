#include "ItemMenu.h"
#include "Arduino.h"
ItemMenu::ItemMenu(String title,  ItemMenu list[] = {}, int size_list = 0, bool isMenu = false, void (* f) () = NULL){
  this->title = title;
  this->size_list = size_list;
  this->list = &list[0];
  this->isMenu = isMenu;
  this->action = *f;
}
