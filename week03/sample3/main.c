#if defined WIN32
   #include "hello_win.h"
#elif defined LINUX
   #include "hello_lnx.h"
#else
   #error only windows and linux supported
#endif

int main (void) {
   hello();
   return 0;
}
