# include <stdio.h>
#include <stdarg.h>
# include "x.h"
void f();


int a=4;

double f1(int,...);
int main() {
/*
//    char x='x';
//    printf("%d,%c",x,x);
//    char xx[4]={'x','y','z','\0'};
//    char yy[]="hello";
//    printf("%s,%s",xx,yy);
//int a=31;
//int b=28;
//int c=30;
//int res;
//for (int i=1;i<=8;i++){
//    switch(i)
//    {
//        case 1:
//            res+=a;
//            break;
//        case 2:
//            res+=b;
//            break;
//        case 3:
//
//            res+=a;
//            break;
//        case 4:
//            res+=c;
//            break;
//        case 5:
//            res+=a;
//            break;
//        case 6:
//            res+=c;
//            break;
//        case 7:
//            res+=a;
//            break;
//        case 8:
//            res+=a;
//            break;
//        default:
//            break;
//    }
//}
//res+=8;
//printf("%d",res);
//    int score=87;
//    switch(score){
//        case 10:
//            printf("%d",0);
//        case 87:
//            printf("%d",87);
//            break;
//        case 85:
//            printf("%d",87);
//            //不要使用continue;
//    }
//    int o = 4;
//    while (o) {
//        printf("%d", o);
//    }
//    do {
//        printf("%d", o);
//    }
//    while (o);
//    int j,k;
//    const int a=5;
//    int i=a;
//    i=10;
//    printf("%d,%d",a,i);
//    if (i==6){
//        printf("%d",i);
//    }else{
//        int i=5;
//            if (i==5){
//                printf("%d",i);
//            }
//
//        printf("%d",a);
//    }
//    int i =1;
//    for (;i<=10;i++) {
//        printf("start %d\n",i);
//    }
//    for ( i=0;i<=10;){
//        printf("%d",i);
//
//    }
//
//    int sun,moon;
//    sun=0;
//    for (moon =0;sun<10&&moon;moon++,++sun)
//        printf("sun:%d,moon%d",sun,moon);
 */
    f();
    double b=f1(2,22,55);
    printf("%f",b);
}
void f(){
    a=6;
    //printf("da sha bi%d",a);
}
double f1(int a,...){
    double res=0;
    va_list valist;
    va_start(valist,a);
    for (int i=0;i<a;i++){
        double temp=double(va_arg(valist,int));
        printf("%f\n",temp);
        res+=temp;
    }
    va_end(valist);
    return res/a;
}


int Fibonacci(int x){
return 0;
}