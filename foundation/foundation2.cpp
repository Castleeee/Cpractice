//
//  main.cpp
//  foundation2
//
//  Created by Owl on 2019/3/3.
//  Copyright © 2019 Owl. All rights reserved.
//

# include <stdio.h>
# include <string>
# include "x.h"
# include <iostream>
#include <vector>
using namespace std;
int main() {
//    int a,d;
//    char b;
//
//    int r=scanf("%d,%d",&a,&d);
//
//    printf("%d",r);
    int a[2][3]={1,2,3,4,5,6};
    int x=(a[0])[2];
    for (int i=0;i<5;i++){
        printf("%d",a[i]);
    }
    printf("%d\n", sizeof(int));
    string s="a         bc dddd d     d  ";
    cout<<s<<s.size()<<endl;
    vector<int>b(5);
    for(int i=0;i<5;i++){

    }

    return 0;
}
//int a=56;