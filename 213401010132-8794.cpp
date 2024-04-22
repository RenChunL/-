#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
#define MAXSIZE 20//窗口最大数量
int a;//实际输入的窗口数
struct window* w[20];//窗口数组
int N;//要删除窗口的数量
int b[20];//存放要删除的窗口下表
int I = 1;//记录要关闭的窗口
typedef struct Node
{
	int buss;//当前窗口业务代号

	struct Node* next;
}node;
typedef struct window//定义窗口排队结点
{
	int n;//当前窗口里的人数
	int bu;//窗口业务代号
	struct Node* front;
	struct Node* rear;
}win;
//初始化一个空窗口
struct window* creat(int r) {

	struct window* ck = (struct window*)malloc(sizeof(struct window));
	ck->n = 0;
	ck->rear=ck->front = NULL;
	ck->bu = r;
	return ck;
}
struct Node* creat1(int c)//创建一个新的排队结点
{

	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->buss =c;
	node->next = NULL;
	return node;
}
//人来窗口排队插入
void push(struct window* ck, int r) {
	struct Node* newnode = creat1(r);
	if(ck->n==0){ ck->front=ck->rear = newnode; }
	else {
		ck->rear->next = newnode;
		ck->rear = newnode;
		newnode->next = NULL;	
	}
	ck->n++;
}
void pop(struct window* ck)//出队函数
{
	if (ck->n ==0) { cout << "该队已经没有人在排队"<< endl; return; }
	else {
		struct Node* nextnode = ck->front->next;
		free(ck->front);
		ck->front = nextnode;
		ck->n--;
	}
}
int Initialize()//初始化数据
{
	cout << "业务的代号，1表示手机业务、2表示宽带业务、3表示售后业务，4表示全部业务" << endl;
	printf("请输入联通服务窗口个数(1~20):");//服务窗口个数
	cin >> a;
	while (a<1 || a>MAXSIZE)
	{
		printf("你的输入有误，请输入1到%d之间的整数：", MAXSIZE);
		cin >> a;
	}
	for (int i = 1; i <= a; i++)//为每个窗口建立一个空队
	{
		
		w[i] = creat(0);
	}
	cout << "已创建" << a << "个窗口" << endl;
	cout << endl;
	return a;
}void shezhi(int n,int n1) //设置窗口业务
{
	w[n]->bu = n1;	
}

int Nu(int b[],int i,int n)//判断i是否为b数组中的元素，n为b数组的长度
{
	int n1 = 0;
	for (int j = 1; j <= n; j++) {
		if (i != b[j]) { n1++; }
	}
	if (n1 == n) { return 1; }
	return 0;
}

void guanbi(int n)//关闭窗口
{
		b[I] = n;//将要关闭窗口记录下来

		free(w[n]);
}
void paiduihao(int a1, int e)//输出排队号
{
	int min = 0;
	
	int z = 0;//记录可以办理你要的业务的窗口数量
	for (int i = 1; i <= a1; i++) {
		if (Nu(b, i, N) == 0) {
			//cout << Nu(b, i, x2) << endl;
		}
		else if (Nu(b, i, N) == 1) {
			if (w[i]->n - 1 < 0) { w[i]->n + 1; }
			if (e == w[i]->bu || w[i]->bu == 4) {
				cout << "能办理你的业务的窗口有：0" << i << "窗口" << "  并且现有排队人数为：" << w[i]->n << endl; min = w[i]->n; z++;
			}
			else {
				cout << "不能办理你的业务的窗口有：0" << i << "窗口" << "  并且现有排队人数为：" << w[i]->n << endl;
			}

			//cout << Nu(b, i, x2) << endl;
		}
	}
	cout << endl;
	
	//最后输出
	if (N == a1) {
		cout << "所有窗口都关闭，今天不营业" << endl;
	}
	else if (z == 0) { cout << "已开放的窗口中没有可以办理你的业务的" << endl; }
	else {
		//cout << "已为你选择排队人数最少的窗口：(当排队人数相同时优先选择窗口序号大的)      0" << min1 << "窗口" << endl;
		cout << "请输入你要去那个窗口排队" << endl;
		int m;
		cin >> m;
		cout << "你的排队号为：0" << m << "0" << w[m]->n + 1 << endl;
		cout << "有" << w[m]->n << "个人在和你一起等待" << endl;
		push(w[m], e);//用户并插入到对应窗口后面
	}
	cout << "当前各开启的窗口的排队人数为：" << endl;
	for (int i = 1; i <= a; i++) {
		if (Nu(b, i, N) == 0) {}
		else if (Nu(b, i, N) == 1) {
			if (w[i]->bu == 1) { cout << "0" << i << "窗口办理手机业务" <<" 当前排队人数为："<<w[i]->n<<endl; }
			else if (w[i]->bu == 2) { cout << "0" << i << "窗口办理宽带业务" << " 当前排队人数为：" << w[i]->n << endl; }
			else if (w[i]->bu == 3) { cout << "0" << i << "窗口办理售后业务" << " 当前排队人数为：" << w[i]->n << endl; }
			else if (w[i]->bu == 4) { cout << "0" << i << "窗口办理全部业务" << " 当前排队人数为：" << w[i]->n << endl; }
			else {}
		}
	}
}

void fun(int a1)//a1为窗口数
{
	int e;//存放输入的代号
	cout << "请输入你要查询业务的代号，1表示手机业务、2表示宽带业务、3表示售后业务，4表示全部业务"<<endl;
	cin >> e;
	cout << endl;
	//判断要关闭的窗口中是否有重复的有就只留一个
	int temp = 0;
	for (int i = 1; i <= N; i++)		//循环判断数组中每一个数
	{
		for (int j = i + 1; j <= N; j++)	//判断b[i]后边的数是否和b[i]相等
		{
			if (b[i] == b[j])
			{
				for (temp = j; temp <= N - 1; temp++)
					b[temp] = b[temp + 1];	//将b[j]后面的元素全往前移一个位置
				j--;	//b[j+1]取代a[j]位置，为使下次从b[j+1]开始查找,j减一(为使j保持不变)
				N--;	//数组长度减一
			}
		}
	}
	

	paiduihao(a1, e);
}
int main() {
	char c;
	int x,y;
	int n=Initialize();
	for (int i = 0; i < 200; i++) {
		cout << "请输入你要实现的功能:             并且按回车结束"<<endl;
		cout<<"a表示设置窗口业务" << endl;
		cout << "b表示关闭窗口" << endl;
		cout << "c表示取出办业务时的排队号" << endl;
		cout << "o表示退出" << endl;
		cout << "注意：c功能应该在a, b之后才能实现" << endl;
		cout << endl;
		cin >> c;
		if (c == 'a') {
			cout << "请输入你要设置的窗口的数量按回车后并依次输入窗口代号如01，02，输入要设置的业务代号如1, 2;最终输入结果如这样：01 1(没有设置业务窗口的默认关闭)并且按回车结束" << endl;
			int l;
			cin >> l;
			for (int i = 1; i <= l; i++) {
				cin >> x >> y;
				if (x <= a && x > 0) {
					shezhi(x, y);
					if (y == 1) { cout << "窗口设置成功，0" << x << "窗口办理手机业务" << endl; }
					else if (y == 2) { cout << "窗口设置成功，0" << x << "窗口办理宽带业务" << endl; }
					else if (y == 3) { cout << "窗口设置成功，0" << x << "窗口办理售后业务" << endl; }
					else if (y == 4) { cout << "窗口设置成功，0" << x << "窗口办理全部业务" << endl; }
					else { cout << "你的输入有误，窗口代号不能大于" << a << ",业务代号只能在1到4" << endl; }
				}
				else { cout << "你的输入有误，窗口代号不能大于" << a << ",业务代号只能在1到4" << endl; i--; }
			}
			for (int i = 1; i <= a; i++) {
				if (Nu(b, i, N) == 0) {}
				else if (Nu(b, i, N) == 1) {
					if (w[i]->bu == 1) { cout << "0" << i << "窗口办理手机业务" << endl; }
					else if (w[i]->bu == 2) { cout << "0" << i << "窗口办理宽带业务" << endl; }
					else if (w[i]->bu == 3) { cout << "0" << i << "窗口办理售后业务" << endl; }
					else if (w[i]->bu == 4) { cout << "0" << i << "窗口办理全部业务" << endl; }
					else{}
				}
			}
			cout << endl;
		}
		else if (c == 'b') {
			cout << "请输入你要关闭的窗口数量,窗口数量不能大于"<<a<<",并且按回车结束" << endl;
			cin >> N;
			int k = 1;
			if (N > 0 && N <= a) {
				for (int i = 1; i <= N; i++) {
					cout << "请一个个输入要关闭的窗口如01，并且按回车结束" << endl;
					cin >> x;
					if(Nu(b, x, N) == 1){
						guanbi(x);
						I++;
						cout << "0" << x << "窗口关闭成功" << endl; 
					}
					else { cout << "该窗口已经关闭完毕,请勿重复输入相同窗口,重新输入" << endl; i--; }

				}
				cout << "当前关闭的窗口有：" << endl;
				cout << endl;
				for (int i = 1; i <= N; i++) { cout << "0" << b[i] << "窗口" << endl; }
				cout << endl;
			}
			else { cout << "你的输入有误，窗口代号不能大于" << a << endl; }
			cout << endl;
		}
		else if (c == 'c') {
			fun(n);
			cout << endl;
		}
		else if (c == 'o') {
			break;
		}
		else { cout << "你的输入有误,请重新输入" << endl; }
	}
	return 0;
}

