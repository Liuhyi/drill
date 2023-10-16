//
// Created by Administrator on 2023/8/4.
//
#include <cstdio>
using namespace std;

int main(){
    int rows = 0;
    int cols= 0;
    printf("请输入矩阵行数和列数");
    scanf("%d%d", &rows, &cols);
    int arr[rows][cols];
    printf("输入矩阵元素");
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    for(int i = 0; i < cols; i++){
        for(int j = 0; j < rows; j++){
            printf("%d ", arr[j][i]);
        }
        if(i < cols-1)
        printf("\n");
    }
    return 0;
}