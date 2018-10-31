#include<iostream>

using namespace std;
/*复数类*/
class Complex
{
	public:
		Complex(int r=10,int i=10):mreal(r),mimage(i)
		{
			
		}
		
		Complex& operator=(const Complex &src)
		{
			if(this==&src)
			{
				return *this;
			}
			mreal=src.mreal;
			mimage=src.mimage;
			return *this;
		}
		
		Complex operator+(const Complex &src)
		{
			/*
			Complex tmp;
			tmp.mreal=this->mreal+src.mreal;
			tmp.mreal=this->mimage+src.mimage;
			return Complex(tmp);//直接构造临时对象 
			*/
			return Complex(this->mreal+src.mreal,this->mimage+src.mimage);   //妙哉 
		}
		
		Complex operator-(const Complex &src)
		{
			/*
			Complex tmp;
			tmp.mreal=this->mreal+src.mreal;
			tmp.mreal=this->mimage+src.mimage;
			return Complex(tmp);//直接构造临时对象 
			*/
			return Complex(this->mreal-src.mreal,this->mimage-src.mimage);   //妙哉 
		}
		
		void show()
		{
			cout<<"mreal"<<"  "<<mreal<<"   "<<this->mimage<<endl;
		}
		
		void operator+=(const Complex &src)
		{
			this->mreal+=src.mreal;
			this->mimage+=src.mimage; 
		}
		
		Complex operator++()  //前置 
		{
			return Complex(this->mreal+=1,this->mimage+=1);
			//return  Complex(this->meal++,this->mimage++)	
		} 
		
		Complex operator++(int)  //后置 
		{
		
			Complex tmp=*this;
			this->mreal++;
			this->mimage++;
			return Complex(tmp);
		}
		
		/**编译器给对象寻址运算符重载函数的规则
			1，优先找成员方法， 
		*/
		private:
			int mreal;
			int mimage;
		friend ostream& operator<<(ostream &cout,const Complex &src);
	    friend istream& operator>>(istream &in,Complex &src);
	  //  friend Complex operator+(const Complex lhs,const Complex &lrs);
 } ;

ostream& operator<<(ostream &out,const Complex &src)
{
	out<<"mreal= "<<src.mreal<<"mimage "<<src.mimage<<endl;
	return out;
} 

istream& operator>>(istream &in,Complex &src)
{
	cout<<"请输入实部和虚部"<<endl; 
    in>>src.mreal>>src.mimage;
	return in;
}
/*

//全局的加法类型 
Complex operator+(const Complex lhs,const Complex &lrs)
{
	cout<<"globle"<<endl;
	return Complex(lhs.mreal+lrs.mreal,lhs.mimage+lrs.mimage);
}
*/
//后置++是临时量 所以不能复制 
int main()
{
	
	Complex cmp1(10,20);
	Complex cmp2(cmp1);
	cmp2=cmp1;
    Complex cmp3=Complex(20,20);	
	
	cmp3=cmp1+cmp2;
	
	cmp3.show();
	
	Complex cmp4=cmp2-cmp1;
	cmp4.show(); 
	
	cmp4+=cmp3;
	cmp4.show();
	cmp1++;
	cmp1.show();
	++cmp1;
	cmp1.show();
	
	cout<<cmp1<<endl;
	/*a+++++b a++ + ++b从右往左   ++a+++b= ++(a++)++*/  
	Complex cmp6;
	 cin>>cmp6;
	// cout<<cmp6;
	return 0;
} 
