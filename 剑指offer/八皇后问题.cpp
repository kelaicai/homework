#include<iostream>  
using namespace std;  
  
int g_number = 0;  
void Permutation(int * , int  , int );  
void Print(int * , int );  
  
void EightQueen( )  
{  
    const int queens = 8;  
    int ColumnIndex[queens];  
    for(int i = 0 ; i < queens ; ++i)  
        ColumnIndex[i] = i;    //初始化  
    Permutation(ColumnIndex , queens , 0);  
}  
  
bool Check(int ColumnIndex[] , int length)  
{  
    int i,j;  
    for(i = 0 ; i < length; ++i)  
    {  
        for(j = i + 1 ; j < length; ++j)  
        {  
            if( i - j == ColumnIndex[i] - ColumnIndex[j] || j - i == ColumnIndex[i] - ColumnIndex[j])   //在正、副对角线上  
                return false;  
        }  
    }  
    return true;  
}  
void Permutation(int ColumnIndex[] , int length , int index)  
{  
    if(index == length)  
    {  
        if( Check(ColumnIndex , length) )   //检测棋盘当前的状态是否合法  
        {  
            ++g_number;  
            Print(ColumnIndex , length);  
        }  
    }  
    else  
    {  
        for(int i = index ; i < length; ++i)   //全排列  
        {  
            swap(ColumnIndex[index] , ColumnIndex[i]);  
            Permutation(ColumnIndex , length , index + 1);  
            swap(ColumnIndex[index] , ColumnIndex[i]);  
        }  
    }  
}  
  
void Print(int ColumnIndex[] , int length)  
{  
    printf("%d\n",g_number);  
    for(int i = 0 ; i < length; ++i)  
        printf("%d ",ColumnIndex[i]);  
    printf("\n");  
}  
  
int main(void)  
{  
    EightQueen();  
    return 0;  
}  
