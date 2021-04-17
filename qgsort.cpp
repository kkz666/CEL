#include"qgsort.h"
#include<iostream>
#include<ctime>
#include<cassert>
#include<cstdio>
using std::cout;
using std::cin;
using std::endl;
void insertSort(int* a, int n) {

    int i, j, tmp;
    for (i = 1; i < n; i++)
    {
        if (a[i] < a[i - 1])
        {
            tmp = a[i];
            j = i - 1;
            do//找到R[i]的插入位置
            {
                a[j + 1] = a[j];//将大于R[i]的元素后移
                j--;
            } while (j >= 0 && a[j] > tmp);
            a[j + 1] = tmp;
        }
    }
}

void MergeArray(int* a, int begin, int end, int* temp){
    //int* data, int start, int end, int* result
    
        int left_length = (end - begin + 1) / 2 + 1;
    int left_index = begin;
    int right_index = begin + left_length;
    int result_index = begin;
    while (left_index < begin + left_length && right_index < end + 1)  //store data into new array
    {
        if (a[left_index] <= a[right_index])
            temp[result_index++] = a[left_index++];
        else
            temp[result_index++] = a[right_index++];
    }
    while (left_index < begin + left_length)
        temp[result_index++] = a[left_index++];
    while (right_index < end + 1)
        temp[result_index++] = a[right_index++];
}
void MergeSort(int* a, int begin, int end, int* temp) {//int* data, int start, int end, int* result
    if (1 == end - begin)   //last only two elements
    {
        if (a[begin] > a[end])
        {
            int temp = a[begin];
            a[begin] = a[end];
            a[end] = temp;
        }
        return;
    }
    else if (end == begin)
        return; //last one element then there is no need to sort;
    else {
        //continue to divide the interval
        MergeSort(a, begin, (end - begin + 1) / 2 + begin, temp);
        MergeSort(a, (end - begin + 1) / 2 + begin + 1, end, temp);
        //start to merge sorted data
        MergeArray(a, begin, end, temp);
        for (int i = begin; i <= end; ++i)
        {
            a[i] = temp[i];
        }
    }


}
void QuickSort_Recursion(int* a, int begin, int end) {

}
int Indexjizhun(int* a, int left, int right)
{

    int Index = left;
    int ponit = a[Index];

    while (left < right)
    {
        while (left < right)
        {
            if (a[right] < ponit)
                break;
            else
                --right;
        }

        while (left < right)
        {
            if (a[left] > ponit)
                break;
            else
                ++left;
        }


        int temp = a[right];
        a[right] = a[left];
        a[left] = temp;
    }


    int num = a[left];
    a[left] = a[Index];
    a[Index] = num;
    return  left;
}
void QuickSort(int* a, int left,int right) {
    if (left >= right)
        return;

    int Index = Indexjizhun(a, left, right);

    //分开而治
    //左半部分
    QuickSort(a, left, Index - 1);

    //右半部分
    QuickSort(a, Index + 1, right);

}

void CountSort(int* a, int size) {
    assert(a);

    int minValue = a[0];
    int maxValue = a[0];
    for (int i = 0; i < size; ++i)
    {
        if (minValue > a[i])
        {
            minValue = a[i];
        }

        if (maxValue < a[i])
        {
            maxValue = a[i];
        }
    }
    int range = maxValue - minValue + 1;

    int* tmp = new int[range];
    memset(tmp, 0, sizeof(int) * range);

    int index = 0;
    while (index < size)
    {
        tmp[a[index] - minValue]++;
        ++index;
    }

    index = 0;
    for (int i = 0; i < range; ++i)
    {
        while (tmp[i]--)
        {
            a[index++] = i + minValue;
        }
    }

    delete[] tmp;

}
int maxbit(int *a, int n)
{
    int d = 1; //保存最大的位数
    int p = 10;
    for (int i = 0; i < n; ++i)
    {
        while (a[i] >= p)
        {
            p *= 10;
            ++d;
        }
    }
    return d;
}
void RadixCountSort(int* a, int size) {
    int d = maxbit(a, size);
    int tmp[200000];
    int count[10]; //计数器
    int i, j, k;
    int radix = 1;
    for (i = 1; i <= d; i++) //进行d次排序
    {
        for (j = 0; j < 10; j++)
            count[j] = 0; //每次分配前清空计数器
        for (j = 0; j < size; j++)
        {
            k = (a[j] / radix) % 10; //统计每个桶中的记录数
            count[k]++;
        }
        for (j = 1; j < 10; j++)
            count[j] = count[j - 1] + count[j]; //将tmp中的位置依次分配给每个桶
        for (j = size - 1; j >= 0; j--) //将所有桶中记录依次收集到tmp中
        {
            k = (a[j] / radix) % 10;
            tmp[count[k] - 1] = a[j];
            count[k]--;
        }
        for (j = 0; j < size; j++) //将临时数组的内容复制到data中
            a[j] = tmp[j];
        radix = radix * 10;
    }
}
void ColorSort(int* a, int size) {
    int l = 0;
    int r = size - 1;
    int index = 0;
    while (index <= r) {
        if (a[index] == 0) { //将当前指针==0的都移到左边
            a[index] = a[l];
            a[l++] = 0;
        }
        if (a[index] == 2) { //将当前指针==2的都移到右边
            a[index] = a[r];
            a[r--] = 2;
            continue;
            //因为从右边移过来的可能需要移到左边
            //如果index++那么就会错过，所以continue
            //上面的if不需要continue是因为其下面就有
            //往右移的，因此不需要额外加continue
        }
        index++;
    }
}
int Partition(int* a, int l,int r) {
    int i = l, j = r + 1;
    int x = a[l];
    while (true)
    {
        while (a[++i] < x && i <= r);
        while (a[--j] > x);
        if (i >= j)
            break;
        int m;
        m = a[i];
        a[i] = a[j];
        a[j] = m;
    }
    a[l] = a[j];
    a[j] = x;
    return j;

}
/*int findK(int* a, int left,int right,int k) {
    if (left == right)
        return a[left];
    int i = Partition(a, left, right);
    int j = i - left + 1;
    if (k <= j)
        return findK(a, left, i, k);
    else
        return findK(a, i + 1, right, k - j);

}*/


int inputCheck(int* val)  //检查输入
{
    char n[50] = { 0 };
    int i = 0, flag = 0, minus = 0;
    // 用户开始输入
    scanf("%s", n);
    getchar();
    for (int j = 0; n[j] != '\0'; j++)
    {
        // 检测是否正确输入符号位
        if (j == 0 && n[j] == '+')
        {
            continue;
        }
        if (n[j] < '0' || n[j] > '9')
            flag = 1;
    }
    if (flag == 1)
    {
        // flag==1 则说明用户的输入发生了错误
        return -1;
    }
    int temp = 0, simple = 1;
    for (int j = 0; n[j] != '\0'; j++)
    {
        if (n[j] == '+')
        {
            continue;
        }
        temp = temp * 10 + (n[j] - 48);
    }

    *val = temp;
    return 0;
}
int findK(int arrayNum[], int p, int r, int k) {
    /**
    *在数组arrayNum[p:r]中查找第k（k > 0)个元素（下标为p+k-1)
    * p <= r && 0 < k && k <= p - r +1 （合法输入说明）
    *渐进时间复杂度/平均时间复杂度 O(N)
    */
    int i = p, j = r, key = arrayNum[i];
    while (i < j) {
        while (i < j && arrayNum[j] >= key)
            --j;
        arrayNum[i] = arrayNum[j];
        while (i < j && arrayNum[i] <= key)
            ++i;
        arrayNum[j] = arrayNum[i];
    }//循环结束后 i = j,其实前面这些语句就是快排的一次划分
    arrayNum[i] = key;
    int lefts = i - p + 1;
    if (lefts == k)
        return arrayNum[i];//找到中位数了
    if (lefts > k) //比关键字小的数的个数大于k，则中位数在左边
        return findK(arrayNum, p, i - 1, k);
    else
        return findK(arrayNum, i + 1, r, k - lefts);
}


