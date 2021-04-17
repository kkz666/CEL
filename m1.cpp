#include<iostream>
#include<ctime>
#include"qgsort.h"
#include<cstdio>
#include<fstream>
#include<cstdlib>
#include<algorithm>
using std::ofstream;
using std::ifstream;
using std::fstream;
using std::cout;
using std::cin;
using std::endl;
int n;
int q;
int final;
int select;
int number;
int MAX = 999;//min max��ֵ�����Լ��������
int MIN = 0;
int ch[10] = { 1,7,5,6,1,64,13,4,5,2 };
int dh[10] = { 0,1,2,1,1,2,0,0,1,2 };
int ah[10];
int data3[200000];
int data1[10000];
int data2[50000];
int ah3[200000];
int ah1[10000];
int ah2[50000];
int color1[10000];
int color2[50000];
int color3[200000];
int K;
int main(int argc, char** argv) {
	cout << "1.����������� " << endl;
	cout << "2.�˳� " << endl;
	while (inputCheck(&q) == -1 || q > 2 || q < 1)
	{
		printf("�������!����������:");
	}
	ofstream out("data.txt");//���ļ�
	ofstream pout("color.txt");
	if (q == 2) {
		pout.close();
		out.close();
		return 0;
	}
	if (q == 1) {
		cout << "ѡ�����ݹ�ģ" << endl;
		cout << "1.10000 " << endl;
		cout << "2.50000 " << endl;
		cout << "3.200000 " << endl;
		cout << "4.�˳� " << endl;
		while (inputCheck(&select) == -1 || select > 4 || select < 1)
		{
			printf("�������!����������:");
		}
		if (select == 1) {
			number = 10000;
			srand((int)time(0));//������� 
			for (int i = 0; i < 10000; i++) {
				out << rand() % (MAX - MIN + 1) + MIN << endl;//������������min��max֮�� 
				pout << rand() % 3 << endl;
			}//������������min��max֮�� 
			out.close();
			pout.close();
		}
		if (select == 2) {
			number = 50000;
			srand((int)time(0));//������� 
			for (int i = 0; i < 50000; i++) {
				out << rand() % (MAX - MIN + 1) + MIN << endl;//������������min��max֮�� 
				pout << rand() % 3 << endl;
			}//������������min��max֮�� 
			out.close();
			pout.close();
		}
		if (select == 3) {
			number = 200000;
			srand((int)time(0));//������� 
			for (int i = 0; i < 200000; i++) {
				out << rand() % (MAX - MIN + 1) + MIN << endl;//������������min��max֮�� 
				pout << rand() % 3 << endl;
			}//������������min��max֮�� 
			out.close();
			pout.close();
		}
	}
	ifstream fin("data.txt");
	ifstream pin("color.txt");
	if (select == 1)
		for (int op = 0; op < number; op++) {
			fin >> data1[op];
			pin >> color1[op];
		}
	else if (select == 2)
		for (int op = 0; op < number; op++) {
			fin >> data2[op];
			pin >> color2[op];
		}
	else if (select == 3)
		for (int op = 0; op < number; op++) {
			fin >> data3[op];
			pin >> color3[op];
		}
	cout << endl;
	cout << "1.�������� " << endl;
	cout << "2.�鲢���� " << endl;
	cout << "3.�������� " << endl;
	cout << "4.�������� " << endl;
	cout << "5.������������ " << endl;
	cout << "6.��ɫ���� " << endl;
	cout << "7.��һ�������������ҵ���K��/С���� " << endl;
	cout << "����������ִ�еĲ���: ";
	while (inputCheck(&n) == -1||n>7||n<1)
	{
		printf("�������!����������: ");
	}
	if (select == 1) {
		switch (n) {
		case 1:insertSort(data1, 10000); break;//OK  ch
		case 2:MergeSort(data1, 0, 10000, ah1); break;//ah
		case 3:QuickSort(data1, 0, 10000); break;//OK ch
		case 4:CountSort(data1, 10000); break;//OK ch
		case 5:RadixCountSort(data1, 10000); break;//OK  
		case 6:ColorSort(color1, 10000); break;//OK  ��ɫ����û���޸ģ���������������������������������������������
		case 7:cout << "����K��ֵ:����KС������------K[1,10000]" << endl;
			while (inputCheck(&K) == -1 || K > 10000 || K < 1)
			{
				printf("�������!����������:");
			}
			cout << endl << "��" << K << "С����Ϊ��" << findK(data1, 0, 10000, K) << endl; break;//OK
		}
		/*for (int e = 0; e < 10000; e++)cout << " " << color1[e];
		return 0;*/
	}
	else if (select == 2) {
		switch (n) {
		case 1:insertSort(data2, 50000); break;//OK  ch
		case 2:MergeSort(data2, 0, 50000, ah2); break;//ah
		case 3:QuickSort(data2, 0, 50000); break;//OK ch
		case 4:CountSort(data2, 50000); break;//OK ch
		case 5:RadixCountSort(data2, 50000); break;//OK  
		case 6:ColorSort(color2, 50000); break;//OK  dh
		case 7:cout << "����K��ֵ:����KС������------K[1,50000]" << endl;
			while (inputCheck(&K) == -1 || K > 50000 || K < 0)
			{
				printf("�������!����������:");
			}
			cout << endl << "��"<<K<<"С����Ϊ��" << findK(data2, 0, 50000, K) << endl; break;
		}
	}
	else if (select == 3) {
		switch (n) {
		case 1:insertSort(data3, 200000); break;//OK  ch
		case 2:MergeSort(data3, 0, 200000, ah3); break;//ah
		case 3:QuickSort(data3, 0, 200000); break;//OK ch
		case 4:CountSort(data3, 200000); break;//OK ch
		case 5:RadixCountSort(data3, 200000); break;//OK  
		case 6:ColorSort(color3, 200000); break;//OK  dh
		case 7:cout << "����K��ֵ:����KС������------K[1,200000]" << endl;
			while (inputCheck(&K) == -1 || K > 200000 || K < 0)
			{
				printf("�������!����������:");
			}
			cout << endl << "��" << K << "С����Ϊ��" << findK(data3, 0, 200000, K) << endl; break;
		}
	}
	if (n == 7)return 0;
	cout << endl << "1.��ʾ����������" << endl;
	cout << "2.�˳�" << endl;
	while (inputCheck(&final) == -1 || final > 2 || final < 1)
	{
		printf("�������!����������:");
	}
	if (select == 1) {
		if (n == 6) {
			for (int te = 0; te < number; te++) {
				cout << color1[te] << " ";
			}
		}
		else for (int te = 0; te < number; te++) {
			cout << data1[te] << " ";
		}
	}
	if (select == 2) {
		if (n == 6) {
			for (int te = 0; te < number; te++) {
				cout << color2[te] << " ";
			}
		}
		else for (int te = 0; te < number; te++) {
			cout << data2[te] << " ";
		}
	}
	if (select == 3) {
		if (n == 6) {
			for (int te = 0; te < number; te++) {
				cout << color3[te] << " ";
			}
		}
		else for (int te = 0; te < number; te++) {
			cout << data3[te] << " ";
		}
	}
}
