#ifndef imenu
#define imenu
#include "Arduino.h"
class ItemMenu
{   public:
        String title;
        ItemMenu *list;
        int size_list;
        bool isMenu;
        void (*action)();
        ItemMenu(String title, ItemMenu list[] = {}, int size_list = 0, bool isMenu = false, void (* f) () = NULL);
        
        
};
#endif
