//
// Created by YoungZorn on 2024/6/14.
//
#include <stdio.h>

int main(){
    int n;
    printf("enter number of array:");
    scanf("%d",&n);

    if (n <= 0){
        printf("err num\n");
    }

    int arr[n];
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        printf("enter array element: ");
        scanf("%d",&arr[i]);
        sum += arr[i];
    }

    double avg = sum/n;
    printf("sum = %d\taverage num = %d",sum,avg);

    return 0;
}