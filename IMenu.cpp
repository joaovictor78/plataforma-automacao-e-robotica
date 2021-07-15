#include "IMenu.h"
#include "Arduino.h"
IMenu::IMenu(String title,  void (* f) ()){
  this->title = title;
  this->func_ptr = *f;
}
