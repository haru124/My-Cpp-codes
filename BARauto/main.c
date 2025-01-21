#include <stdio.h>
#include <stdlib.h>
 #define BAR 5
int main()
{
    auto a=15;
    switch(a*2, a*3)
    {
    case BAR:
        printf("ABC");
        break;
    case BAR*2:
        printf("XYZ");
        break;
    case BAR*3:
        printf("PQR");
        break;
    default:
        printf("MNO");
    case BAR*4:
        printf("AAA");
        break;
    }
    return 0;
}
