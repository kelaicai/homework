   #include<iostream>  
    using namespace std;   
    int main()  {  
        int a=10;  
        int *i=&a;  
        long pc=reinterpret_cast<long>(i);//��һ��ָ��ת��Ϊһ����������ȡ����ֵַ  
        char *str=reinterpret_cast<char *>(i);//��int*ת��Ϊchar *����int��С���������  
        long *l=reinterpret_cast<long *>(i);//��int *ת��Ϊlong *����int�ʹ󣩣�ȡ����ֵַ����iֵ�����  

        cout<<*i<<endl;  
        cout<<hex<<pc<<endl;  
        cout<<i<<endl;  
        cout<<"char:"<<str<<endl;  
        cout<<l<<endl;  

        return 0;  
    }
