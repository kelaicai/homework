#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
#include<assert.h>   
#include"processBank.h"

int input(){
	int i=0;
	int j=0;
	puts("������ϵͳ���ṩ����Դ�������Ŀ");
	scanf("%d",&re_n);
	fflush(stdin); //�ÿ����뻺����
	puts("avaible������Դ�ĸ���");
	fun();
	for(i=0;i<re_n;i++){
		scanf("%d",&avaible[i]);
	}
	puts("��������̸�����");
	scanf("%d",&pro_m);
	fflush(stdin);
	for(i=0;i<pro_m;i++){
		printf("������� %d �����̵�����",i);
	    scanf("%s",p[i].nam); 
		fflush(stdin);
		//����max 
		puts("������ý��̵ĸ�����Դ��max");
		fun();
		for(j=0;j<re_n;j++){
			scanf("%d",&p[i].max[j]);
		}
		 //����alloction 
		puts("�����뱾���̸�����Դ�ѷ�����Դ���");
		fun();
		for(j=0;j<re_n;j++) {
			scanf("%d",&p[i].alloction[j]);
		}
		//����need 
	/*	puts("�����뱾���̶Ը�����Դ��������"); 
		for(j=0;j<re_n;j++){
			scanf("%d",&p[i].need[j]);
		}*/
		for(j=0;j<re_n;j++){
	  p[i].need[j]= p[i].max[j]-p[i].alloction[j]; 
		}
		p[i].finish=F; //���밲ȫ���㷨��־λ 
	}
	show();
	if(check()==0){
		puts("��ȫ�Լ��ʧ�ܣ��п��ܽ�������");
		return 0; 
	} 
	else{
		puts("������������");
		return 1; 
	}
} 
void fun(){ //�����Դ��� 
	int i=0;
	for(i=0;i<re_n;i++){
		printf(" %-2c  ",65+i); //�������ԴΪ��ĸ 
	} 
	puts("\n"); 
}
void show(){
	int i=0;
	int j=0;
	puts("  ��ǰ��������  ");
	puts("       MAX      ");
	fun(); 
	for(i=0;i<pro_m;i++){
		for(j=0;j<re_n;j++){
		 printf("%-2d",p[i].max[j]);
	}
	puts("\n");
	} 
	
		puts("       alloction      ");
	fun(); 
	for(i=0;i<pro_m;i++){
		for(j=0;j<re_n;j++){
		 printf("%-2d",p[i].alloction[j]);
	}
	puts("\n");
   }
   
   	puts("       need      ");
	fun(); 
	for(i=0;i<pro_m;i++){
		for(j=0;j<re_n;j++){
		 printf("%-2d",p[i].need[j]);
	}
	puts("\n");
   }
   
   puts("avaible");
   for(i=0;i<re_n;i++){
   	printf("%-4d",avaible[i]);
   }
}

booL bank(int i){
	int j=0;
	int flag=0;

	for(j=0;j<re_n;j++){
		if(p[i].need[j]>=rqe.num[j]){
			;
		}else{
			flag=1;
			break;
		}
		if(avaible[j]>=rqe.num[j]){
			;
		}else{
		flag=2; 
		break;
	}
  }
  if(j<re_n){
  	if(flag==1){
  		printf("������Դ��Ŀ������������Ҫ�������Դ��Ŀ");
	  }
	  if(flag==2){
	  	puts("����û���㹻��Դ���ý�����ʱ����ȴ�����"); 
	  }
	  printf("�����������ϴ������������request\n");
	  return F;
  }
  else{
  	puts("���������Ϸ�");
  	int k=0;
  	for(k=0;k<pro_m;k++){
  		protmp[k]=p[k];
	  }
	  tryalloc(i);
	  show();
	  return T; 
  }
}

void tryalloc(int i){ //���ŷ�����Դ
 int j=0;
  for(j=0;j<re_n;j++){
  	avaibletmp[j]=avaible[j];
  }
  for(j=0;j<re_n;j++){
  	avaible[j]=avaible[j]-rqe.num[j];
  	p[i].alloction[j]=p[i].alloction[j]+rqe.num[j];
  	p[i].need[j]=p[i].need[j]-rqe.num[j];
  }
	
} 

int check(){  //��ȫ�Լ���㷨 
	int i=0;
	int j=0;
	int alpro=0;  
	int already[MAX];
    int add=0; //     ?
    int k=0;
    int temp_pro_m=pro_m;
    
	for(j=0;j<re_n;j++){
		work[j]=avaible[j];  //work������ʼ����avaible 
	} 
	for(i=0;i<pro_m;i++){
		for(j=0;j<re_n;j++){
			if(p[i].need[j]>work[j]){
				break;//������һ������ i+1������ 
			}
		}
		if(p[i].finish==F && j==re_n) //need<work �����δ��ɵĲ����Ѿ�ɨ�赽���һ����Դ 
		{
			p[i].finish=T;
			already[add++]=i;
			for(k=0;k<re_n;k++){
				work[k]=work[k]+p[i].alloction[k];
			}
		if(p[i].recived==F){
	    	alpro++;  //�ѷ������Դ�Ľ��̸��� 
	    }else{
	    	temp_pro_m=temp_pro_m-1;
		}
		i=-1;  //����i��Ϊ��Ѱ�Ұ�ȫ����		
		}
		else{
			continue; 
		}
		if(alpro==temp_pro_m) //�����ҳ���ȫ���У������������ÿ�����̵ı�־λfinish����false
		{
			puts("          ���ڵ�ϵͳ�ǰ�ȫ��   ");
			puts("             ��ȫ����Ϊ��      ");
			for(k=0;k<pro_m;k++){
				if(p[k].recived==F)
			    	printf("���̣� %s",p[already[k]].nam);  //already�������ǽ���˳������ 
	            if(k!=pro_m-1){
	            	printf("------>");
				}else{
					puts("\n");
				}	
			}
			return 1; 
		} 
	}
	puts("����ϵͳ�ǲ���ȫ�ģ����������������");
	return 0; 
}
void recive(int k){
	int i=0;
	int j=0;
		for(j=0;j<re_n;j++){
		   avaible[j]+=p[k].alloction[j];  //������Դ	
		   p[k].alloction[j]=0;
		}
}

int main(){
	system("color 5f"); //���ñ�����ɫΪ��ɫ������Ϊ��ɫ
	puts("   *****************���м��㷨����ƺ�ʵ��**************");
	int chose=0;
	int i=0;
	int j=0;
	int flags=1;

	
	while(1){
		chose=input();  //����1��ʾ��ȫ�Լ��ɹ� 
		if(chose==1){
			break;
		}
	} 
	puts("                                                       ");
	for(i=0;i<pro_m;i++){
		p[i].finish=F;
		p[i].recived=F;
	}
	int k=0;
	int sign=1;
	int sign_recive=1;  //��Դ������ 
    while(flags){
    	
	do{
		puts("�����request������");
		//rqe.name=gets();
		 scanf("%s",rqe.name);
		 fflush(stdin);
		 puts("������requst�Ը���Դ����������");
		 fun();
		 for(j=0;j<re_n;j++){
		   scanf("%d",&rqe.num[j]);
		 }
		 for(k=0;k<pro_m;k++){
		 	if(strcmp(rqe.name,p[k].nam)==0){
		 		break;
			 }
		 }
		 if(p[k].recived==T){
		 	puts("�ó������н����������ٲ�������");
		 	goto label;
		 }
	}while(!bank(k));
	int L=0;
	if(check()==0){
		puts("��ȫ�Լ��ʧ�ܣ��п��ܲ����������ý�����Ҫ�ȴ�"); 
		for(L=0;L<re_n;L++){
			avaible[L]=avaibletmp[L];
		}
		int m=0;
		for(m=0;m<re_n;m++){
			p[m]=protmp[m];
		}
		show();
	}else{
		puts("����˳��ִ��");
		for(i=0;i<pro_m;i++){
			sign_recive=0; 
			for(j=0;j<re_n ;j++){
				
				if(p[i].max[j]==p[i].alloction[j]){
					
					sign_recive++;

			    printf("sign_recive= %d ",sign_recive);  //������� 
			    if(sign_recive==re_n){
				puts("��ǰ�������н�����ϵͳ������Դ"); 
				recive(i); 
				p[i].recived=T;
				sign_recive=0; 
				show();
				}
			}else{
					break;
				}
				
			}
		}
		
	//	return 1; 
    }
    
label:puts("�Ƿ��������"); 
    scanf("%d",&flags);
    if(flags==1){   //�������˵�����ν�������ɹ���������һ������Ǽ����Ļ���Ҫ��finishλ��F 
    	for(i=0;i<pro_m;i++){
		p[i].finish=F;
	}
	}else{
		;
	} 	
  }
	return 0;
	
}
	

