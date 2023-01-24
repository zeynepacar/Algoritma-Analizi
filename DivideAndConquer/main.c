//
//  main.c
//  AlgoOdev2
//
//  Created by Zeynep Acar on 4.11.2022.
//

#include <stdio.h>
#include <stdlib.h>

int findLeftMax(int arr[], int mid, int low, int max);
int findRightMax(int arr[], int mid, int high, int max);
int findMax(int num1, int num2);
int findMaxSumWithDAC(int arr[], int low, int high);
int findMaxSumWithBruteF(int arr[], int n);

int main(int argc, const char * argv[]){
    
    int choice;
    int i,n;
    int *array;
    int maxSum;
    
    while(choice != 4){
        printf("1-Dizi ekle\n2-Brute force yontemi\n3-Divide and conquer yontemi\n4-Cikis\nSecimi giriniz: ");
        scanf("%d", &choice);
        if(choice == 1){
           
            printf("Dizinin eleman sayisini giriniz: ");
            scanf("%d", &n);
            
            array=(int*)malloc(n*sizeof(int));
            if(array == NULL){
                printf("Memory not allocated!");
                return -1;
            } else {
                for(i=0;i<n;i++){
                    printf("%d. eleman: ",i);
                    scanf("%d", &array[i]);
                    
                }
            }
            
            
            
        } else if(choice == 2){
            maxSum=findMaxSumWithBruteF(array, n);
            printf("Max sum = %d\n", maxSum );
            
        }else if(choice == 3){
          
            maxSum=findMaxSumWithDAC(array, 0, n-1);
            printf("Max sum = %d\n", maxSum );
            
        } else {
            free(array);
        }
    }
    
  
    return 0;
}

int findMaxSumWithBruteF(int arr[], int n){
    int maxSum=0;
    int i,j;
    int sum;
    
    for(i=0;i<n;i++){
        sum=0;
        for(j=i;j<n;j++){
           sum+= arr[j];
           if(sum > maxSum){
                maxSum=sum;
           }
        }
    }
    return maxSum;
}

int findMaxSumWithDAC(int arr[], int low, int high){
    int middle;
    int leftMax=0,rightMax=0;
    int maxOfLeftRight;
    
    if(low >= high){
        return arr[low];
    } else {
        middle=(low+high) / 2;
        leftMax=findLeftMax(arr, middle, low, leftMax);
        rightMax=findRightMax(arr, middle, high, rightMax);
        maxOfLeftRight=findMax(findMaxSumWithDAC(arr, low, middle), findMaxSumWithDAC(arr, middle+1, high));
        return findMax(maxOfLeftRight, leftMax+rightMax);
    }
}

int findLeftMax(int arr[], int mid, int low, int max){
    int sum=0;
    int i;
    for(i=mid; i>= low; i--){
        sum+= arr[i];
        if(sum > max){
            max = sum;
        }
    }
    return max;
}

int findRightMax(int arr[], int mid, int high, int max){
    int sum=0;
    int i;
    for(i=mid+1; i <= high; i++){
        sum+= arr[i];
        if(sum > max){
            max = sum;
        }
    }
    return max;
}

int findMax(int num1, int num2){
    if(num1 > num2){
        return num1;
    } else {
        return num2;
    }
}


