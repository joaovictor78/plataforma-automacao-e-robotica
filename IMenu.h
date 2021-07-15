#ifndef imenu
#define imenu
#include "Arduino.h"
class IMenu
{   public:
        String title;
        void (*func_ptr)();
        IMenu(String title, void (* f) ());
        
        
};
#endif
