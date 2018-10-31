#include<iostream>
using namespace std;
class linklist{
public:
	int pid;
	int reachtime;
	int servertime;
	int starttime;
	int finishtime;
	int transfortime;
	int weight;
	double averageWeightTime;
	double averageWithWeightTime
	bool state;
	
	linklist* next;
	linklist(){
		this->pid = 0;
		this->reachtime = 0;
		this->servertime = 0;
		this->starttime = 0;
		this->finishtime = 0;
		this->transfortime = 0;
		this->weight = 0;
		this->state=false;
		this->next = NULL;
	}
public:
	void finishOperated(linklist link){
		link->state=false;
	}
	booleanl getState(linklist link){
		return link->state;
	}
};
class listOperator{
public:
	linklist* headnode;
	linklist* tempnode;
	static int linkCount=0;
public:

	bool init_link(){
		this->headnode = new linklist();
		if (this->headnode == NULL){
			cout << "请求空间错误" << endl;
			return false;
		}
		else{
			this->headnode->next = NULL;
			return true;
		}
	}
	bool create_link(){
		linklist *pointer=new linklist();
		bool flag = true;
		this->init_link();
		pointer->next = (this->headnode)->next;

		while (flag){
			tempnode = new linklist();
			if (this->tempnode != NULL){
				cout << "进程pid：" << "到达时间 " << "服务时间 " << "开始执行时间 " << "完成时间 " << "周转时间 " << "带权周转时间"<<endl;
				cin >> tempnode->pid >> tempnode->reachtime >> tempnode->servertime >> tempnode->starttime >> tempnode->finishtime >> tempnode->transfortime >> tempnode->weight;
				this->tempnode = pointer->next;
				pointer->next = tempnode;
				pointer = tempnode;
				linkCount++;
				cout << "是否要继续" << endl;
				cin >> flag; //输入数字1为继续 
			}	
		}
		return true;
	}
	void finishOperated(linklist link){
		link->state=false;
	}
	booleanl isOerated(linklist link){
		return link->state;
	}
	int getlinkCount(){
		return this->linkCount;
	}
	int time=0;  //计时器
	double x=0.0;
	double y=0.0;
	void run_Fifo(linklist &link){

		int Count=link->getlinkCount();
		time=link->reachtime>time? link->reachtime:time;
		link->starttime=time;
		cout<<"时刻： "<<time<<"  当前正在运行作业  "<<link->pid<<endl;
		time+=link->servertime;
		link->state=true;
		link->finishtime=time;
		link->transfortime=link->finishtime-link->starttime;
		link->weight=link->transfortime/link->servertime;
		x+=link->transfortime;
		y+=link->weight;
		link->averageWeightTime=link->transfortime/Count;
		link->averageWithWeightTime=link->weight/Count;
		cout<<"到达时间"<<link->reachtime<<"开始时间"<<"服务时间 "<<link->servertime<<"
		"<<"完成时间"<<"周转时间"<<"带权周转时间"<<endl;
	}
public:
	void fifoal(linklist &link){
		this->create_link();
		linklist* temp = this->headnode->next;
		linklist assist=new linklist(); //辅助指针
		/*bool flag = true;
		int time=0;
		
		while (flag){
			
		}*/
		for(int i=0;i<this->getlinkCount();i++)
		{
			if(link->getState()==false){
			 assist=temp;
             this->run_Fifo(assist);			 
			}
			temp=temp->next;
		}
	}
	void shorttime(linklist* &link){
	}
	


};

int main(){
	listOperator a;
	a.create_link();
	return 0;
}
