   #include<iostream>  
    using namespace std;   
    int main()  {  
        int a=10;  
        int *i=&a;  
        long pc=reinterpret_cast<long>(i);//把一个指针转换为一个整数，即取出地址值  
        char *str=reinterpret_cast<char *>(i);//把int*转换为char *（比int型小），无输出  
        long *l=reinterpret_cast<long *>(i);//把int *转换为long *（比int型大），取出地址值（即i值）输出  

        cout<<*i<<endl;  
        cout<<hex<<pc<<endl;  
        cout<<i<<endl;  
        cout<<"char:"<<str<<endl;  
        cout<<l<<endl;  

        return 0;  
    }
