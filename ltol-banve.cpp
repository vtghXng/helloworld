#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main()
{

int n;
scanf("%d", &n);

long long a;
long long tien25 = 0;
long long tien50 ;
while(n--){
    scanf("%lld", &a);
    if(a == 25){
        tien25++;
    }
    else if(a == 50){
        if (tien25 <= 0) {
                printf("NO");
                return 0;
        }
        tien25--;
        tien50++;
    }
    else{
            if(tien50 > 0 && tien25 > 0){
                tien25--;
                tien50--;
            }
        else if(tien25 >= 3){
            tien25-=3;
        }

        else{
            printf("NO");
            return 0 ;
        }
    }
}
printf("YES");
return 0;
}
