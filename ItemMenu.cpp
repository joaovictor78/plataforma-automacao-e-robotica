#include "ItemMenu.h"
#include "Arduino.h"
ItemMenu::ItemMenu(String title,  void (*f) ()){
  this->title = title;
  this->action = *f;
}
