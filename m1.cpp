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
int MAX = 999;//min max的值可以自己随便设置
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
int ah4[100];
int color1[10000];
int color2[50000];
int color3[200000];
int color4[100];
int K;
int cnum[100];
double startTime1;
double endTime1;
double startTime2;
double endTime2;
int main(int argc, char** argv) {
	cout << "1.随机生成数据 " << endl;
	cout << "2.退出 " << endl;
	while (inputCheck(&q) == -1 || q > 2 || q < 1)
	{
		printf("输入错误!请重新输入:");
	}
	ofstream out("data.txt");//打开文件
	ofstream pout("color.txt");
	ofstream qout("cnum.txt");
	if (q == 2) {
		pout.close();
		out.close();
		return 0;
	}
	if (q == 1) {
		cout << "选择数据规模" << endl;
		cout << "1.10000 " << endl;
		cout << "2.50000 " << endl;
		cout << "3.200000 " << endl;
		cout << "4.多个小数组计算时间" << endl;
		cout << "5.退出 " << endl;
		while (inputCheck(&select) == -1 || select > 5 || select < 1)
		{
			printf("输入错误!请重新输入:");
		}
		if (select == 1) {
			number = 10000;
			srand((int)time(0));//随机种子 
			for (int i = 0; i < 10000; i++) {
				out << rand() % (MAX - MIN + 1) + MIN << endl;//产生的数据在min到max之间 
				pout << rand() % 3 << endl;
			}//产生的数据在min到max之间 
			out.close();
			pout.close();
		}
		if (select == 2) {
			number = 50000;
			srand((int)time(0));//随机种子 
			for (int i = 0; i < 50000; i++) {
				out << rand() % (MAX - MIN + 1) + MIN << endl;//产生的数据在min到max之间 
				pout << rand() % 3 << endl;
			}//产生的数据在min到max之间 
			out.close();
			pout.close();
		}
		if (select == 3) {
			number = 200000;
			srand((int)time(0));//随机种子 
			for (int i = 0; i < 200000; i++) {
				out << rand() % (MAX - MIN + 1) + MIN << endl;//产生的数据在min到max之间 
				pout << rand() % 3 << endl;
			}//产生的数据在min到max之间 
			out.close();
			pout.close();
		}
		if (select == 4) {
			number = 100;
			srand((int)time(0));
			for (int i = 0; i < 100; i++) {
				qout << rand() % (MAX - MIN + 1) + MIN << endl;//产生的数据在min到max之间 
				pout << rand() % 3 << endl;
			}
			pout.close();
			qout.close();
		}
		if (select == 5)return 0;
	}
	ifstream fin("data.txt");
	ifstream pin("color.txt");
	ifstream qin("cnum.txt");
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
	else if (select == 4) {
		for (int op = 0; op < 100; op++) {
			qin >> cnum[op];
		}
	}
	cout << endl;
	cout << "1.插入排序 " << endl;
	cout << "2.归并排序 " << endl;
	cout << "3.快速排序 " << endl;
	cout << "4.计数排序 " << endl;
	cout << "5.基数计数排序 " << endl;
	cout << "6.颜色排序 " << endl;
	cout << "7.在一个无序序列中找到第K大/小的数 " << endl;
	cout << "请输入您想执行的操作: ";
	while (inputCheck(&n) == -1||n>7||n<1)
	{
		printf("输入错误!请重新输入: ");
	}
	if (select == 1) {
		switch (n) {
		case 1:insertSort(data1, 10000); break;//OK  ch
		case 2:MergeSort(data1, 0, 10000, ah1); break;//ah
		case 3:QuickSort(data1, 0, 10000); break;//OK ch
		case 4:CountSort(data1, 10000); break;//OK ch
		case 5:RadixCountSort(data1, 10000); break;//OK  
		case 6:ColorSort(color1, 10000); break;//OK  颜色排序没有修改！！！！！！！！！！！！！！！！！！！！！！！
		case 7:cout << "输入K的值:（第K小个数）------K[1,10000]" << endl;
			while (inputCheck(&K) == -1 || K > 10000 || K < 1)
			{
				printf("输入错误!请重新输入:");
			}
			cout << endl << "第" << K << "小的数为：" << findK(data1, 0, 10000, K) << endl; break;//OK
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
		case 7:cout << "输入K的值:（第K小个数）------K[1,50000]" << endl;
			while (inputCheck(&K) == -1 || K > 50000 || K < 0)
			{
				printf("输入错误!请重新输入:");
			}
			cout << endl << "第"<<K<<"小的数为：" << findK(data2, 0, 50000, K) << endl; break;
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
		case 7:cout << "输入K的值:（第K小个数）------K[1,200000]" << endl;
			while (inputCheck(&K) == -1 || K > 200000 || K < 0)
			{
				printf("输入错误!请重新输入:");
			}
			cout << endl << "第" << K << "小的数为：" << findK(data3, 0, 200000, K) << endl; break;
		}
	}
	else if (select == 4) {
		startTime1 = clock();
		
		//cout <<endl<< startTime1 << endl;
		switch (n) {
		case 1: insertSort(cnum, 100);break;//OK  ch
		case 2:MergeSort(cnum, 0, 100, ah4); break;//ah
		case 3:QuickSort(cnum, 0, 100); break;//OK ch
		case 4:CountSort(cnum, 100); break;//OK ch
		case 5:RadixCountSort(cnum, 100); break;//OK  
		case 6:ColorSort(color4, 100); break;//OK  dh
		case 7:cout << "输入K的值:（第K小个数）------K[1,100]" << endl;
			while (inputCheck(&K) == -1 || K > 100 || K < 0)
			{
				printf("输入错误!请重新输入:");
			}
			findK(cnum, 0, 100, K);
			//cout << endl << "第" << K << "小的数为：" << findK(data3, 0, 100, K) << endl; break;
		}
		double endTime1 = clock();
		//cout << endl << endTime1 << endl;
		cout<<"进行一次元素为100的数组排序需要的时间为"<<abs((double)(endTime1 - startTime1)/ CLOCKS_PER_SEC) << "s" << endl;
		startTime2 = clock();
		for (int ui = 0; ui < 100000; ui++) {
			for (int ai = 0; ai < 100; ai++) {
					cnum[ai]=rand() % (MAX - MIN + 1) + MIN;
			}
			switch (n) {
			case 1: insertSort(cnum, 100); break;//OK  ch
			case 2:MergeSort(cnum, 0, 100, ah4); break;//ah
			case 3:QuickSort(cnum, 0, 100); break;//OK ch
			case 4:CountSort(cnum, 100); break;//OK ch
			case 5:RadixCountSort(cnum, 100); break;//OK  
			case 6:ColorSort(color4, 100); break;//OK  dh
			case 7:
				findK(cnum, 0, 100, K);
				 break;
			}
		}double endTime2 = clock();
		cout<<"进行100k次元素为100的数组排序需要的时间为"<< (double)(endTime2 - startTime2) / CLOCKS_PER_SEC << "s" << std::endl;
		return 0;
	}
	if (n == 7)return 0;
	cout << endl << "1.显示排序后的数组" << endl;
	cout << "2.退出" << endl;
	while (inputCheck(&final) == -1 || final > 2 || final < 1)
	{
		printf("输入错误!请重新输入:");
	}
	if (final == 2)return 0;
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
