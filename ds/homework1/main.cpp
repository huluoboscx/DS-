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
    cout << "����"<<endl;
    for (i = 0; i < 6; i++) {
        n[i].show();
    }
    cout << endl;
    n.unsort(0, 6);
    cout << "����" << endl;
    for (i = 0; i < 6; i++) {
        n[i].show();
    }
    cout << endl;
    cout << "����" << endl;
    n.findcomplex(0, 6);
    cout << endl;
    Complex z;
    cout << "��n[3]������";
    z.show();
    cout << endl;
    n.insert(3, z);
    for (i = 0; i < 7; i++) 
    {
        n[i].show();
    }
    cout << endl<<"ɾ��n[0]��n[1]"<<endl;
    n.remove(0, 1);
    for (i = 1; i < 6; i++) 
    {
        n[i].show();
    }
    cout << endl << "Ψһ��" << endl;
    n.deduplicate();
    for (i = 0; i < 7; i++)
    {
        n[i].show();
    }
    cout << endl << "����" << endl;
    Vector<Complex>m1(a, 7);
    Vector<Complex>m2(a, 7);
    Vector<Complex>m3(a, 7);
    LARGE_INTEGER nFreq;
    LARGE_INTEGER nBeginTime;
    LARGE_INTEGER nEndTime;
    double time = 0;
    double counts = 0;
    QueryPerformanceFrequency(&nFreq);
    QueryPerformanceCounter(&nBeginTime);//��ʼ��ʱ  
    m1.mergeSort(0, 6);//����ʱ�鲢����
    QueryPerformanceCounter(&nEndTime);//ֹͣ��ʱ  
    time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;//�������ִ��ʱ�䵥λΪs  
    cout << "����ʱ�鲢��������ʱ�䣺" << time * 1000 << "ms" << endl;

    QueryPerformanceFrequency(&nFreq);
    QueryPerformanceCounter(&nBeginTime);//��ʼ��ʱ  
    m2.bubbleSort(0, 6);//����ʱ��������
    QueryPerformanceCounter(&nEndTime);//ֹͣ��ʱ  
    time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;//�������ִ��ʱ�䵥λΪs  
    cout << "����ʱ������������ʱ�䣺" << time * 1000 << "ms" << endl;

    QueryPerformanceFrequency(&nFreq);
    QueryPerformanceCounter(&nBeginTime);//��ʼ��ʱ  
    m1.mergeSort(0, 6);//˳��ʱ�鲢����
    QueryPerformanceCounter(&nEndTime);//ֹͣ��ʱ  
    time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;//�������ִ��ʱ�䵥λΪs  
    cout << "˳��ʱ�鲢��������ʱ�䣺" << time * 1000 << "ms" << endl;

    QueryPerformanceFrequency(&nFreq);
    QueryPerformanceCounter(&nBeginTime);//��ʼ��ʱ  
    m2.bubbleSort(0, 6); //˳��ʱ��������
    QueryPerformanceCounter(&nEndTime);//ֹͣ��ʱ  
    time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;//�������ִ��ʱ�䵥λΪs  
    cout << "˳��ʱ������������ʱ�䣺" << time * 1000 << "ms" << endl;


    for (i = 0; i < 7; i++) {
        swap(m1[i], m1[6 - i]);
        swap(m2[i], m2[6 - i]);
    }//��������������

    QueryPerformanceFrequency(&nFreq);
    QueryPerformanceCounter(&nBeginTime);//��ʼ��ʱ  
    m1.mergeSort(0, 6);//����ʱ�鲢����
    QueryPerformanceCounter(&nEndTime);//ֹͣ��ʱ  
    time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;//�������ִ��ʱ�䵥λΪs  
    cout << "����ʱ�鲢��������ʱ�䣺" << time * 1000 << "ms" << endl;

    QueryPerformanceFrequency(&nFreq);
    QueryPerformanceCounter(&nBeginTime);//��ʼ��ʱ  
    m2.bubbleSort(0, 6);//����ʱ��������
    QueryPerformanceCounter(&nEndTime);//ֹͣ��ʱ  
    time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;//�������ִ��ʱ�䵥λΪs  
    cout << "����ʱ������������ʱ�䣺" << time * 1000 << "ms" << endl;
    Vector<Complex>m4(a, 7);
    for (i = 0; i < 7; i++)
    {
        m4[i].show();
    }
    cout <<endl;
    cout<<"����ģ������[x, y)�ڵĸ���"<<endl<<"������x y"<<endl;
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
