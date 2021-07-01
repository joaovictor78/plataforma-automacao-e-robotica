#ifndef imenu
#define imenu
class IMenu{
  private:
     char title;     
  public: 
     void setTitle(char title);
     char getTitle();
     void (*func_ptr);
};
#endif
