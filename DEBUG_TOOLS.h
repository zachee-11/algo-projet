#ifndef DEBUG_TOOLS_H

#define DEBUG_TOOLS_H



#ifdef DEBUG_MODE



#include "stdio.h"



#define logIntValue(value)  printf("value of %s in %s at line %i is: %lli\n",#value,__FILE__,__LINE__,(long long int)value)

#define logFloatValue(value)  printf("value of %s in %s at line %i is: %.10Lf\n",#value,__FILE__,__LINE__,(long double)(value))

#define logTabIntValue(tab,size)  {\

                                  int index=0;\

                                  printf("%s contains in %s at line %i:\n",#tab,__FILE__,__LINE__);\

                                  for(index=0;index<size;index++)\

                                    printf("%s[%i]=%i\t",#tab,index,tab[index]);\

                                  printf("\n");\

                                  }\



#else



#define logIntValue(value)  

#define logFloatValue(value)  

#define logTabIntValue(tab,size)



#endif



#endif
