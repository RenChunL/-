#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
#define MAXSIZE 20//�����������
int a;//ʵ������Ĵ�����
struct window* w[20];//��������
int N;//Ҫɾ�����ڵ�����
int b[20];//���Ҫɾ���Ĵ����±�
int I = 1;//��¼Ҫ�رյĴ���
typedef struct Node
{
	int buss;//��ǰ����ҵ�����

	struct Node* next;
}node;
typedef struct window//���崰���Ŷӽ��
{
	int n;//��ǰ�����������
	int bu;//����ҵ�����
	struct Node* front;
	struct Node* rear;
}win;
//��ʼ��һ���մ���
struct window* creat(int r) {

	struct window* ck = (struct window*)malloc(sizeof(struct window));
	ck->n = 0;
	ck->rear=ck->front = NULL;
	ck->bu = r;
	return ck;
}
struct Node* creat1(int c)//����һ���µ��Ŷӽ��
{

	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->buss =c;
	node->next = NULL;
	return node;
}
//���������ŶӲ���
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
void pop(struct window* ck)//���Ӻ���
{
	if (ck->n ==0) { cout << "�ö��Ѿ�û�������Ŷ�"<< endl; return; }
	else {
		struct Node* nextnode = ck->front->next;
		free(ck->front);
		ck->front = nextnode;
		ck->n--;
	}
}
int Initialize()//��ʼ������
{
	cout << "ҵ��Ĵ��ţ�1��ʾ�ֻ�ҵ��2��ʾ���ҵ��3��ʾ�ۺ�ҵ��4��ʾȫ��ҵ��" << endl;
	printf("��������ͨ���񴰿ڸ���(1~20):");//���񴰿ڸ���
	cin >> a;
	while (a<1 || a>MAXSIZE)
	{
		printf("�����������������1��%d֮���������", MAXSIZE);
		cin >> a;
	}
	for (int i = 1; i <= a; i++)//Ϊÿ�����ڽ���һ���ն�
	{
		
		w[i] = creat(0);
	}
	cout << "�Ѵ���" << a << "������" << endl;
	cout << endl;
	return a;
}void shezhi(int n,int n1) //���ô���ҵ��
{
	w[n]->bu = n1;	
}

int Nu(int b[],int i,int n)//�ж�i�Ƿ�Ϊb�����е�Ԫ�أ�nΪb����ĳ���
{
	int n1 = 0;
	for (int j = 1; j <= n; j++) {
		if (i != b[j]) { n1++; }
	}
	if (n1 == n) { return 1; }
	return 0;
}

void guanbi(int n)//�رմ���
{
		b[I] = n;//��Ҫ�رմ��ڼ�¼����

		free(w[n]);
}
void paiduihao(int a1, int e)//����ŶӺ�
{
	int min = 0;
	
	int z = 0;//��¼���԰�����Ҫ��ҵ��Ĵ�������
	for (int i = 1; i <= a1; i++) {
		if (Nu(b, i, N) == 0) {
			//cout << Nu(b, i, x2) << endl;
		}
		else if (Nu(b, i, N) == 1) {
			if (w[i]->n - 1 < 0) { w[i]->n + 1; }
			if (e == w[i]->bu || w[i]->bu == 4) {
				cout << "�ܰ������ҵ��Ĵ����У�0" << i << "����" << "  ���������Ŷ�����Ϊ��" << w[i]->n << endl; min = w[i]->n; z++;
			}
			else {
				cout << "���ܰ������ҵ��Ĵ����У�0" << i << "����" << "  ���������Ŷ�����Ϊ��" << w[i]->n << endl;
			}

			//cout << Nu(b, i, x2) << endl;
		}
	}
	cout << endl;
	
	//������
	if (N == a1) {
		cout << "���д��ڶ��رգ����첻Ӫҵ" << endl;
	}
	else if (z == 0) { cout << "�ѿ��ŵĴ�����û�п��԰������ҵ���" << endl; }
	else {
		//cout << "��Ϊ��ѡ���Ŷ��������ٵĴ��ڣ�(���Ŷ�������ͬʱ����ѡ�񴰿���Ŵ��)      0" << min1 << "����" << endl;
		cout << "��������Ҫȥ�Ǹ������Ŷ�" << endl;
		int m;
		cin >> m;
		cout << "����ŶӺ�Ϊ��0" << m << "0" << w[m]->n + 1 << endl;
		cout << "��" << w[m]->n << "�����ں���һ��ȴ�" << endl;
		push(w[m], e);//�û������뵽��Ӧ���ں���
	}
	cout << "��ǰ�������Ĵ��ڵ��Ŷ�����Ϊ��" << endl;
	for (int i = 1; i <= a; i++) {
		if (Nu(b, i, N) == 0) {}
		else if (Nu(b, i, N) == 1) {
			if (w[i]->bu == 1) { cout << "0" << i << "���ڰ����ֻ�ҵ��" <<" ��ǰ�Ŷ�����Ϊ��"<<w[i]->n<<endl; }
			else if (w[i]->bu == 2) { cout << "0" << i << "���ڰ�����ҵ��" << " ��ǰ�Ŷ�����Ϊ��" << w[i]->n << endl; }
			else if (w[i]->bu == 3) { cout << "0" << i << "���ڰ����ۺ�ҵ��" << " ��ǰ�Ŷ�����Ϊ��" << w[i]->n << endl; }
			else if (w[i]->bu == 4) { cout << "0" << i << "���ڰ���ȫ��ҵ��" << " ��ǰ�Ŷ�����Ϊ��" << w[i]->n << endl; }
			else {}
		}
	}
}

void fun(int a1)//a1Ϊ������
{
	int e;//�������Ĵ���
	cout << "��������Ҫ��ѯҵ��Ĵ��ţ�1��ʾ�ֻ�ҵ��2��ʾ���ҵ��3��ʾ�ۺ�ҵ��4��ʾȫ��ҵ��"<<endl;
	cin >> e;
	cout << endl;
	//�ж�Ҫ�رյĴ������Ƿ����ظ����о�ֻ��һ��
	int temp = 0;
	for (int i = 1; i <= N; i++)		//ѭ���ж�������ÿһ����
	{
		for (int j = i + 1; j <= N; j++)	//�ж�b[i]��ߵ����Ƿ��b[i]���
		{
			if (b[i] == b[j])
			{
				for (temp = j; temp <= N - 1; temp++)
					b[temp] = b[temp + 1];	//��b[j]�����Ԫ��ȫ��ǰ��һ��λ��
				j--;	//b[j+1]ȡ��a[j]λ�ã�Ϊʹ�´δ�b[j+1]��ʼ����,j��һ(Ϊʹj���ֲ���)
				N--;	//���鳤�ȼ�һ
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
		cout << "��������Ҫʵ�ֵĹ���:             ���Ұ��س�����"<<endl;
		cout<<"a��ʾ���ô���ҵ��" << endl;
		cout << "b��ʾ�رմ���" << endl;
		cout << "c��ʾȡ����ҵ��ʱ���ŶӺ�" << endl;
		cout << "o��ʾ�˳�" << endl;
		cout << "ע�⣺c����Ӧ����a, b֮�����ʵ��" << endl;
		cout << endl;
		cin >> c;
		if (c == 'a') {
			cout << "��������Ҫ���õĴ��ڵ��������س����������봰�ڴ�����01��02������Ҫ���õ�ҵ�������1, 2;������������������01 1(û������ҵ�񴰿ڵ�Ĭ�Ϲر�)���Ұ��س�����" << endl;
			int l;
			cin >> l;
			for (int i = 1; i <= l; i++) {
				cin >> x >> y;
				if (x <= a && x > 0) {
					shezhi(x, y);
					if (y == 1) { cout << "�������óɹ���0" << x << "���ڰ����ֻ�ҵ��" << endl; }
					else if (y == 2) { cout << "�������óɹ���0" << x << "���ڰ�����ҵ��" << endl; }
					else if (y == 3) { cout << "�������óɹ���0" << x << "���ڰ����ۺ�ҵ��" << endl; }
					else if (y == 4) { cout << "�������óɹ���0" << x << "���ڰ���ȫ��ҵ��" << endl; }
					else { cout << "����������󣬴��ڴ��Ų��ܴ���" << a << ",ҵ�����ֻ����1��4" << endl; }
				}
				else { cout << "����������󣬴��ڴ��Ų��ܴ���" << a << ",ҵ�����ֻ����1��4" << endl; i--; }
			}
			for (int i = 1; i <= a; i++) {
				if (Nu(b, i, N) == 0) {}
				else if (Nu(b, i, N) == 1) {
					if (w[i]->bu == 1) { cout << "0" << i << "���ڰ����ֻ�ҵ��" << endl; }
					else if (w[i]->bu == 2) { cout << "0" << i << "���ڰ�����ҵ��" << endl; }
					else if (w[i]->bu == 3) { cout << "0" << i << "���ڰ����ۺ�ҵ��" << endl; }
					else if (w[i]->bu == 4) { cout << "0" << i << "���ڰ���ȫ��ҵ��" << endl; }
					else{}
				}
			}
			cout << endl;
		}
		else if (c == 'b') {
			cout << "��������Ҫ�رյĴ�������,�����������ܴ���"<<a<<",���Ұ��س�����" << endl;
			cin >> N;
			int k = 1;
			if (N > 0 && N <= a) {
				for (int i = 1; i <= N; i++) {
					cout << "��һ��������Ҫ�رյĴ�����01�����Ұ��س�����" << endl;
					cin >> x;
					if(Nu(b, x, N) == 1){
						guanbi(x);
						I++;
						cout << "0" << x << "���ڹرճɹ�" << endl; 
					}
					else { cout << "�ô����Ѿ��ر����,�����ظ�������ͬ����,��������" << endl; i--; }

				}
				cout << "��ǰ�رյĴ����У�" << endl;
				cout << endl;
				for (int i = 1; i <= N; i++) { cout << "0" << b[i] << "����" << endl; }
				cout << endl;
			}
			else { cout << "����������󣬴��ڴ��Ų��ܴ���" << a << endl; }
			cout << endl;
		}
		else if (c == 'c') {
			fun(n);
			cout << endl;
		}
		else if (c == 'o') {
			break;
		}
		else { cout << "�����������,����������" << endl; }
	}
	return 0;
}

