#include<sdtio.h>
#include<stdlib.h>
#include<mybank.h>
#define MAX 10

int re_n=0; //��Դ������
int pro_m=0; //������

int avaialable[MAX]={0};
int max[MAX][MAX]={0};
int allocation[MAX][MAX]={0};
int need[MAX][MAX]={0};
int request[MAX]={0};
int work[MAX][MAX]={0};
booL finish[MAX];

int tmp[MAX]={0};
char pro_name[MAX]=" ";  //������

void input(){
	int i=0;
	int j=0;
	puts("��������������̵ĸ����������Ϣ");
	puts("���������Ŀ");
	scanf("%d",&pro_m);
	puts("��������Դ������");
	scanf("%d",&re_n);
    //avaialable
    puts("������avaible����");
    for(i=0;i<re_n;i++){
    	scanf("%d",&avaialable[i]);
    }
    //������
    puts("���������")
    for(i=0;i<pro_m;i++){
    	scanf("%c",pro_name);
    }
    //max
    puts("��������Щ���̵�MAX����")
	for(i=0;i<pro_m;i++){
		for(j=0;j<re_n;j++){
          scanf("%d",&max[i][j]);
		}
		puts("\n");
	}
    //alloction
	puts("��������Щ���̵�allocation����");
	for(i=0;i<pro_m;i++){
		for(j=0;j<re_n;j++){
          scanf("%d",&alloction[i][j]);
		}
		puts("\n");
	}
   //need
	puts("��������Щ���̵�need����");
	for(i=0;i<pro_m;i++){
		for(j=0;j<re_n;j++){
          scanf("%d",&need[i][j]);
		}
		puts("\n");
	}
   //��ʼ����־λfinish
	for(i=0;i<pro_m;i++){
		finish[i]=F;
	}

}
void show(){
	int i=0;
	int j=0;
	//max
	puts("            max                   ");
	for(i=0;i<pro_m;i++){
		printf("%c  ",pro_name[i]);
		for(j=0;j<re_n;j++){
			printf("%3d",max[i][j]);
		}
		puts("\n");
	}
	//allocation
	puts("            alloction                   ");
	for(i=0;i<pro_m;i++){
		printf("%c  ",pro_name[i]);
		for(j=0;j<re_n;j++){
			printf("%3d",alloction[i][j]);
		}
		puts("\n");
	}
	puts("            need                  ");
	for(i=0;i<pro_m;i++){
		printf("%c  ",pro_name[i]);
		for(j=0;j<re_n;j++){
			printf("%3d",max[i][j]);
		}
		puts("\n");
	}
	//check need[i][j]=max[i][j]-alooction[i][j]
	for (i = 0; i < pro_m ; i++){
		for(j=0;j<re_n;j++){
			if(need[i][j]!=max[i][j]-alooction[i][j]){
				printf("%s\n","�����������������" );
					exit(0);
			}else{
				continue;
			}
		}
		finish=F;
	}
}
int init_state(){
	input();
	//��ȫ�Լ�� 
	if(check_safe()==F){
        printf("��ȫ���ʧ��,���ܷ�������\n");
		return 0;
	}else{
       
		printf("\n����˳��ִ��.\n\n");
		return 1;
	} 
}
int check_safe(){  //��ȫ�Լ���㷨
   int allcated=0;  //��¼�Ѿ���������Դ�Ľ��̸���
   int i=0;
   int j=0;
   int sequance[MAX];  //��ȫ������
   int b=0;
   //��ʼ��work
   for(i=0;i<re_n;i++){
   	work[i]=avaialable[i];  //work��ʼΪavaiable
   }
   //need[i][j]<work[i][j]?
   for(i=0;i<pro_m;i++){
   	for(j=0;j<re_n;j++){
   		if(need[i][j]>work[j]){
           break;
   		}
   	}
   	int k;
   	if(finish[i]=F && j==re_n){  //��ǰ���̲�δ��������Դ
   		finish[i]=T;
   		sequance[b++]=i;
   		for(k=0;k<re_n;k++){
   			work[k]=work[k]+alloction[i][k];
   		}
   		allcated++;
   		i=-1; //����i��Ϊ��Ѱ�Ұ�ȫ����
   	}
   	else{
   		continue;
   	}
   	if(allcated==pro_m){
   		printf("����ϵͳ��ȫ\n");
   		printf("��ȫ����Ϊ\n");
   			for(k=0;k<pro_m;k++){
   				printf("%c\n",p[k][k+1] );
   				if(k!=pro_m){
   					printf("--->");
   				}else{
                    printf("\n");
   				}
   			}
   			return 1;
   	}
   }
  puts("��ʱϵͳ����ȫ�������������Ҫ��\n");
  return 0��
}
booL  banker(int id){
   int i=0;
   int flah=0;
   for(i=0;i<pro_m;i++){
   	for(j=0;j<re_n;j++)
   	if(need[i][j]>=request[j]){
   		;
   	}else{
   		flag=1;   //��Ҫ����Դ�������ֵ
   		braek;
   	}
   	if(avaialable[i][j]>=request[j]){
   		;
   	}else{
   		flag=2;
   		break; //��Ҫ����Դ�����ȿ�����Դ��
   	}
   	if(j<n){
   		if(flag==1){
   			printf("����Ҫ����Դ��Ŀ���������������ֵ\n");
   		}
   		if(flag==2){
   			printf("������Դ�����ȿ�����Դ��Ŀ\n");
   		}
   		printf("�����������������request\n");
   		return F;
   	}
   	else{
   		printf("request��ȷ\n");
   		int s=0;
   		for(s=0;s<pro_m;s++){
   			tmp[s]=i;
   		}
   	}
   	alloc(id);
   	show();
   	return T;
   }
}
void alloc(int id){
	int j=0;
	for(j=0;j<re_n;j++){
		tmp_available[j]=avaialable[j];
	}
	for(j=0;j<re_n;j++){
		avaialable[j]-=request[j];
		alloction[id][j]=alloction[id][j]+request[j]
		need[id][j]=need[id][j]-request[j];
	}
}
int main(int argc, char const *argv[])
{
	/* code */
	system("color 3f");  //�����ɫ
	puts("                    ���м��㷨ʵ��            С���");
	int chose=0;
	int i=0;
	int j=0;
	int pro_id;
	while(1){
		chose=input();
		if(chose==1){
			break;
		}
	} 
	puts("\n");
	for(i=0;i<pro_m;i++){
		finish[i]=F;
	}
	int x=0;
	int flag=1;
	do{
		puts("�����뷢��request�Ľ��̱��(0-%d) ");
		scanf("%d",&pro_id);
		fllush(stdin);
		printf("�����뷢��request�����ĶԶ�Ӧֵ\n");
		for(i=0;i<re_n;i++){
			scanf("%d",&request[i]);
		}
	}while(banker(pro_id));
	int h=0;
	if(check_safe()==0){
		printf("��ȫ�Լ��ʧ�ܣ����ܻᷢ���������ý�����Ҫ�ȴ�\n");
        for(h=0;h<re_n;h++){
        	avaialable[h]=tmp_available[h];
        }
        int s;
      show();
	}
	 else{
      	printf("����˳��ִ��\n");
      	return 1;
      }
	return 0;
}




