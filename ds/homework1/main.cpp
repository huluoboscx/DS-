#include"..\..\ds\homework1\Complex.h"
#include"..\..\ds\vector\vector.h"
#include <iostream>
#include<time.h>
#include<windows.h>
using namespace std;
int main() {
    srand(time(0));
    Complex *a = new Complex[7];
    int i;
    Vector<Complex>n(a,7);
    cout << "生成"<<endl;
    for (i = 0; i < 6; i++) {
        n[i].show();
    }
    cout << endl;
    n.unsort(0, 6);
    cout << "置乱" << endl;
    for (i = 0; i < 6; i++) {
        n[i].show();
    }
    cout << endl;
    cout << "查找" << endl;
    n.findcomplex(0, 6);
    cout << endl;
    Complex z;
    cout << "在n[3]处插入";
    z.show();
    cout << endl;
    n.insert(3, z);
    for (i = 0; i < 7; i++) 
    {
        n[i].show();
    }
    cout << endl<<"删除n[0]到n[1]"<<endl;
    n.remove(0, 1);
    for (i = 1; i < 6; i++) 
    {
        n[i].show();
    }
    cout << endl << "唯一化" << endl;
    n.deduplicate();
    for (i = 0; i < 7; i++)
    {
        n[i].show();
    }
    cout << endl << "排序" << endl;
    Vector<Complex>m1(a, 7);
    Vector<Complex>m2(a, 7);
    Vector<Complex>m3(a, 7);
    LARGE_INTEGER nFreq;
    LARGE_INTEGER nBeginTime;
    LARGE_INTEGER nEndTime;
    double time = 0;
    double counts = 0;
    QueryPerformanceFrequency(&nFreq);
    QueryPerformanceCounter(&nBeginTime);//开始计时  
    m1.mergeSort(0, 6);//乱序时归并排序
    QueryPerformanceCounter(&nEndTime);//停止计时  
    time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;//计算程序执行时间单位为s  
    cout << "乱序时归并排序运行时间：" << time * 1000 << "ms" << endl;

    QueryPerformanceFrequency(&nFreq);
    QueryPerformanceCounter(&nBeginTime);//开始计时  
    m2.bubbleSort(0, 6);//乱序时起泡排序
    QueryPerformanceCounter(&nEndTime);//停止计时  
    time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;//计算程序执行时间单位为s  
    cout << "乱序时起泡排序运行时间：" << time * 1000 << "ms" << endl;

    QueryPerformanceFrequency(&nFreq);
    QueryPerformanceCounter(&nBeginTime);//开始计时  
    m1.mergeSort(0, 6);//顺序时归并排序
    QueryPerformanceCounter(&nEndTime);//停止计时  
    time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;//计算程序执行时间单位为s  
    cout << "顺序时归并排序运行时间：" << time * 1000 << "ms" << endl;

    QueryPerformanceFrequency(&nFreq);
    QueryPerformanceCounter(&nBeginTime);//开始计时  
    m2.bubbleSort(0, 6); //顺序时起泡排序
    QueryPerformanceCounter(&nEndTime);//停止计时  
    time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;//计算程序执行时间单位为s  
    cout << "顺序时起泡排序运行时间：" << time * 1000 << "ms" << endl;


    for (i = 0; i < 7; i++) {
        swap(m1[i], m1[6 - i]);
        swap(m2[i], m2[6 - i]);
    }//将复数向量逆序

    QueryPerformanceFrequency(&nFreq);
    QueryPerformanceCounter(&nBeginTime);//开始计时  
    m1.mergeSort(0, 6);//逆序时归并排序
    QueryPerformanceCounter(&nEndTime);//停止计时  
    time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;//计算程序执行时间单位为s  
    cout << "逆序时归并排序运行时间：" << time * 1000 << "ms" << endl;

    QueryPerformanceFrequency(&nFreq);
    QueryPerformanceCounter(&nBeginTime);//开始计时  
    m2.bubbleSort(0, 6);//逆序时起泡排序
    QueryPerformanceCounter(&nEndTime);//停止计时  
    time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;//计算程序执行时间单位为s  
    cout << "逆序时起泡排序运行时间：" << time * 1000 << "ms" << endl;
    Vector<Complex>m4(a, 7);
    for (i = 0; i < 7; i++)
    {
        m4[i].show();
    }
    cout <<endl;
    cout<<"查找模在区间[x, y)内的复数"<<endl<<"请输入x y"<<endl;
    double x, y;
    cin >> x >> y;
    cout << endl;
    int sum = 0;
    for (int i = 0; i < 7; i++)
    {
        if (m3[i].mo1() >= x || m3[i].mo1() < y)
        {
            m4[sum].real2(m3[i].real1());
            m4[sum].image2(m3[i].image1());
            sum++;
        }
    }
    for (i = 0; i < sum; i++)
    {
        m4[i].show();
    }
    getchar();
    return 0;
}
