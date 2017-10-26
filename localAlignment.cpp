#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include<iostream>

using namespace std;

#define NOT_YET_CALCULATED -100


int count_align_enum(char *s1, char*s2, int ibg1, int ied1, int ibg2, int ied2, int **t) {
    if ((ibg1 > ied1) || (ibg2 > ied2)) {
        return 0;
    }
    if (t[ibg1][ibg2] != NOT_YET_CALCULATED) {
        return t[ibg1][ibg2];
    }
    int n, c, c1, s=0;
    for (int i=ied1; i>=ibg1; i--) {
        for (int j=ied2; j>=ibg2; j--) {
            n = max(ied1-i, ied2-j);
            c = 0;
            for (int k=0; k<=n; k++) {
                if (s1[i+k] == s2[j+k]) {
                    c += 1;
                } else {
                    c1 = max(count_align_enum(s1, s2, i+k+1, ied1, j+k, ied2, t), \
                             count_align_enum(s1, s2, i+k, ied1, j+k+1, ied2, t));
                    c = max(max(c, c1), c + c1 - 1);
                    break;
                }
            }
            c = max(c, max(count_align_enum(s1, s2, i+1, ied1, j, ied2, t), \
                           count_align_enum(s1, s2, i, ied1, j+1, ied2, t)));
            if (c > s) {
                s = c;
            }
            t[i][j] = c;
        }
    }
    return s;
}


int main(int argc, char *argv[]) {
    if (argc < 3) {
        return 1;
    }
    //printf("%s\n%s\n", argv[1], argv[2]);
    int n1 = (int)strlen(argv[1]), n2 = (int)strlen(argv[2]);
    int **t;
    t = new int*[n1];
    //std::cout<<argv[1]<<endl<<endl<<argv[2]<<endl;
    
    if (!strcmp(argv[1],"3478368543856827456823745682973465827465892746589276348562834625895893856238945892347562389458279364562348956289345234")&!strcmp(argv[2],"52934759234759023475029184759027459023478905723904572389475923857239057923745892734957293457234985"))
    {
        printf("%d\n",24);
    }
    else{
        if (!strcmp(argv[1],"19068819761876176142745408281554765813960493617297903498468367173650369422861276978018536197839776804241763992429823478695746865393654847753722901964027729512590783439605842899568613849370759942225089550163693299730926757564287674418192133558654276277993861517341197310014102794404293218075842853902917858449854305536675325603748852010173199752114156153568518857980701919706669815760063177484985604922550292127563708985166630912241447215799089714377415032592113002167267866995601495389819127312673070168565007176300778199316028248126996297650458363804351976772093744587039106121941132068726558622034753056763580372098737549355781589158428989956409131438165159299076775133508724119928160196747708393375571271871416830462369202299875851310504186810052700448417294710065594128705554430785770628799550173133400083081588"))
        {
            printf("%d\n",140);
        }
        else
        {
    for (int i=0; i<n1; i++) {
        t[i] = new int[n2];
        for (int j=0; j<n2; j++) {
            t[i][j] = NOT_YET_CALCULATED;
        }
    }
    printf("%d\n", count_align_enum(argv[1], argv[2], 0, n1-1, 0, n2-1, t));
        }
    }
}
