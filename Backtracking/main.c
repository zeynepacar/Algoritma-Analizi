//
//  main.c
//  algoProje
//
//  Created by Zeynep Acar on 2.01.2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define MAX 100

int isValid(int n, int **matris);
int solve(int row, int n, int **matris, char **array, int detail);

int main(int argc, const char * argv[]) {
    setlocale(LC_ALL, "Turkish");
    int n,i,j,k;
    int sonuc;
    int str[MAX];
    char **renk;
    int choice=0;
    
    while (choice != 4) {
        printf("1-Renk Matrisi Olustur\n2-Normal Mod\n3-Detay Mod\n4-Cikis\nSecim: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                do{
                    printf("3<= N <= 8 olacak şekilde matris boyutunu giriniz: ");
                    scanf("%d", &n);
                }while(n > 8 || n < 3);
                
                //renk matrisini olusturma
                char ***renkler;
                renkler = (char***)malloc(n * sizeof(char**));
                for(i=0; i<n; i++){
                    renkler[i]=(char**)malloc(n * sizeof(char*));
                    for(j=0;j<n; j++){
                        renkler[i][j] = malloc(sizeof(str));
                    }
                }
                
                //renk matrisini kullanicidan alma
                for (i=0; i<n; i++){
                    for (j=0; j<n; j++){
                        printf("(%d, %d): ", i, j);
                        scanf("%s", renkler[i][j]);
                    }
                }
                
                //sayi matrisini olusturma
                int **sayilar;
                sayilar = (int**)malloc(n * sizeof(int*));
                for(i=0; i<n; i++){
                    sayilar[i]=(int*)malloc(n * sizeof(int));
                }
                
                //ilk satiri sayi degerlerine cevirme ve renklerin sayi degerini saklama
                renk=(char**)malloc(n *sizeof(char*));
                for(i=0; i<n; i++){
                    sayilar[0][i] = i;
                    renk[i]=malloc(sizeof(str));
                    strcpy(renk[i], renkler[0][i]);
                }
                
                //renk matrisine gore sayi matrisini olusturma
                for(i=1; i<n; i++){
                    for(j=0; j<n; j++){
                        k=0;
                        while (strcmp(renkler[i][j], renkler[0][k]) && k<n) {
                            k++;
                        }
                        sayilar[i][j] = sayilar[0][k];
                    }
                }
                
                printf("-------\n");
                // Matrisi ekrana yazdırın
                for (i=0; i<n; i++){
                    for (j=0; j<n; j++){
                        printf("%s\t", renkler[i][j]);
                    }
                    printf("\n");
                }
                printf("-------\n");
                
              break;
            case 2:
                sonuc = solve(0, n, sayilar, renk, 1);
                if(sonuc){
                    printf("-------\n");
                    for (i=0; i<n; i++){
                        for (j=0; j<n; j++){
                            printf("%s\t", renk[sayilar[i][j]]);
                        }
                        printf("\n");
                    }
                    printf("-------\n");
                } else {
                    printf("Bu matris icin cozum yok!\n");
                }
                break;
            case 3:
                sonuc = solve(0, n, sayilar, renk, 2);
                if(sonuc){
                    printf("-------\n");
                    for (i=0; i<n; i++){
                        for (j=0; j<n; j++){
                            printf("%s\t", renk[sayilar[i][j]]);
                        }
                        printf("\n");
                    }
                    printf("-------\n");
                } else {
                    printf("Bu matris icin cozum yok!\n");
                }
                break;
                
            default:
                printf("Gecerli bir secim girmediniz!\n");
                break;
        }
    }

    return 0;
}

//sutunlari kontrol etme eger istenen sart saglaniyorsa 1 saglanmiyorsa 0 dondurur
int isValid(int n, int **matris){
    int i,j,k;
    int *seen;
    seen=(int*)calloc(n, sizeof(int));
    for (i=0; i<n; i++){
        for(k=0; k<n; k++){
            seen[k]=0;
        }
        for (j=0; j<n; j++){
            if(seen[matris[j][i]]){
                return 0;
            }
            seen[matris[j][i]]=1;
        }
    }
    return 1;
}

//satirlari sirayla saga kaydirarak istenen cozumu elde etmeye calisma
int solve(int row, int n, int **matris, char **array, int detail){
    int shift;
    int tmp;
    int i,j;
    
    if(row == n){
        return isValid(n, matris);
    }
    for(shift=0; shift<n; shift++){
        tmp = matris[row][n-1];
        for(i=(n-1); i>0; i--){  //satiri saga kaydirma
            matris[row][i] = matris[row][i-1];
        }
        matris[row][0]=tmp;
        
        if(detail==2){ 
            printf("-------\n");
            for (i=0; i<n; i++){
                for (j=0; j<n; j++){
                    printf("%s\t", array[matris[i][j]]);
                }
                printf("\n");
            }
            printf("-------\n");
            
        }
        
        if(solve(row+1, n, matris, array, detail)){
            return 1;
        }
        
   
    }
    
 

    return 0;
    
}
