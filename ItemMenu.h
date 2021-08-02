#ifndef imenu
#define imenu
#include "Arduino.h"
class ItemMenu
{   public:
        String title;
        void (*action)();
        ItemMenu(String title, void (* f) ());
        
        
};
#endif
