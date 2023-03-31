#include<iostream>
using namespace std;


#define true 1
#define false 0
#pragma once

typedef int Rank;

#define DEFAULT_CAPACITY  3 //Ĭ�ϵĳ�ʼ������ʵ��Ӧ���п�����Ϊ����

template <typename T> class Vector { 
public:
   Rank _size; int _capacity;  T* _elem; 
   void copyFrom ( T const* A, Rank lo, Rank hi ) { //����������A[lo, hi)Ϊ������������
	_elem = new T[_capacity = max<Rank>(DEFAULT_CAPACITY, 2 * (hi - lo))]; //����ռ�
	for (_size = 0; lo < hi; _size++, lo++) //A[lo, hi)�ڵ�Ԫ����һ
	 _elem[_size] = A[lo]; //������_elem[0, hi - lo)
   }  
   void expand() { //�����ռ䲻��ʱ����
	   if (_size < _capacity) return; //��δ��Աʱ����������
	   if (_capacity < DEFAULT_CAPACITY) _capacity = DEFAULT_CAPACITY; //��������С����
	   T* oldElem = _elem;  _elem = new T[_capacity <<= 1]; //�����ӱ�
	   for (Rank i = 0; i < _size; i++)
		   _elem[i] = oldElem[i]; //����ԭ�������ݣ�TΪ�������ͣ��������ظ�ֵ������'='��
	   delete[] oldElem; //�ͷ�ԭ�ռ�
   }
   void shrink(); //װ�����ӹ�Сʱѹ��
   Rank maxItem(Rank lo, Rank hi); //ѡȡ���Ԫ��
   void selectionSort(Rank lo, Rank hi); //ѡ�������㷨
   void merge(Rank lo, Rank mi, Rank hi) { // lo < mi < hi
	   T* A = _elem + lo; //�ϲ������������A[0, hi - lo) = _elem[lo, hi)
	   int lb = mi - lo; T* B = new T[lb]; //ǰ������B[0, lb) <-- _elem[lo, mi)
	   for (Rank i = 0; i < lb; B[i] = A[i++]); //����ǰ������
	   int lc = hi - mi; T* C = _elem + mi; //��������C[0, lc) = _elem[mi, hi)
	   for (Rank i = 0, j = 0, k = 0; (j < lb) || (k < lc);) {//B[j]��C[k]�е�С������Aĩβ
		   if ((j < lb) && (!(k < lc) || (B[j] <= C[k]))) {
			   A[i++] = B[j++];
		   }
		   if ((k < lc) && (!(j < lb) || (C[k] < B[j]))) {
			   A[i++] = C[k++];
		   }
	   }
	   delete[] B; //�ͷ���ʱ�ռ�
   } //�鲢�㷨 //�鲢�㷨
   bool bubble(Rank lo, Rank hi) {
	   bool sorted = true;//���������־
	   while (++lo < hi)//�������ң���һ����������Ԫ��
		   if (_elem[lo - 1] > _elem[lo]) {//����������ζ����δ�������򣬲���Ҫͨ������ʹ�ֲ�����
			   sorted = false;
			   swap(_elem[lo - 1], _elem[lo]);
		   }
		   else if (_elem[lo - 1] == _elem[lo]) {
			   if (_elem[lo - 1].real1() > _elem[lo].real1()) {
				   sorted = false;
				   swap(_elem[lo - 1], _elem[lo]);
			   }
		   }
	   return sorted;//���������־
   } //ɨ�轻��
   void bubbleSort(Rank lo, Rank hi) {
	   while (!bubble(lo, hi--));
   } //���������㷨
   void mergeSort(Rank lo, Rank hi) { // 0 <= lo < hi <= size
	   if (hi - lo < 2) return; //��Ԫ��������Ȼ���򣬷���...
	   int mi = (lo + hi) / 2; //���е�Ϊ��
	   mergeSort(lo, mi); mergeSort(mi, hi); //ǰ׺����׺�ֱ�����
	   merge(lo, mi, hi); //�鲢
   } //�鲢�����㷨
   void heapSort(Rank lo, Rank hi); //�������Ժ�����ȫ�ѽ��⣩
   Rank partition(Rank lo, Rank hi); //��㹹���㷨
   void quickSort(Rank lo, Rank hi); //���������㷨
   void shellSort(Rank lo, Rank hi); //ϣ�������㷨
public:
	Vector(Rank c = DEFAULT_CAPACITY, Rank s = 0, T v = 0) //����Ϊc����ģΪs������Ԫ�س�ʼΪv
	{ _elem = new T[_capacity = c]; for (_size = 0; _size < s; _elem[_size++] = v); } //s<=c
	Vector(T const* A, Rank n) { copyFrom(A, 0, n); } //�������帴��
	Vector(T const* A, Rank lo, Rank hi) { copyFrom(A, lo, hi); } //����
	Vector(Vector<T> const& V) { copyFrom(V._elem, 0, V._size); } //�������帴��
	Vector(Vector<T> const& V, Rank lo, Rank hi) { copyFrom(V._elem, lo, hi); } //����
	// ��������
	~Vector() { delete[] _elem; } //�ͷ��ڲ��ռ�
	// ֻ�����ʽӿ�
	Rank size() const { return _size; } //��ģ
	bool empty() const { return !_size; } //�п�
	Rank find(T const& e) const { return find(e, 0, _size); } //���������������
	Rank find(T const& e, Rank lo, Rank hi) const
	{
	//0 <= lo < hi <= _size
	while ((lo < hi--) && (e != _elem[hi])); //�Ӻ���ǰ��˳�����
	return hi; //��hi < lo������ζ��ʧ�ܣ�����hi������Ԫ�ص���
	}//���������������
	Rank search(T const& e) const //���������������
	{ return (0 >= _size) ? -1 : search(e, 0, _size); }
	Rank search(T const& e, Rank lo, Rank hi) const; //���������������
	// ��д���ʽӿ�
	T& operator[] (Rank r) { return _elem[r]; } //�����±������������������������ʽ���ø�Ԫ��
	const T & operator[] (Rank r) const; //����������ֵ�����ذ汾
	Vector<T>& operator=(const Vector<T>& V)//���ظ�ֵ���������Ա�ֱ�ӿ�¡����

	{
		delete[] _elem;	//ɾ��ԭ�пռ�
		copyFrom(V._elem, 0, V._size);
		return *this; //����ֵΪ���ñ�����ʽ��ֵ
	}
	T remove(Rank r); //ɾ����Ϊr��Ԫ��
	void remove(Rank lo, Rank hi) { //0 <= lo <= hi <= n
		if (lo == hi) {}; //����Ч�ʿ��ǣ����������˻����
		while (hi < _size) _elem[lo++] = _elem[hi++]; //��׺[hi, _size)˳��ǰ��hi-loλ
		_size = lo; //���¹�ģ��lo=_size֮��������������㣻���Ҫ��������
		//���б�Ҫ��������
		//return hi - lo; //���ر�ɾ��Ԫ�ص���Ŀ
	}
	void insert(Rank r, T const& e) { //0 <= r <= size
		expand(); //���Ҫ��������
		for (Rank i = _size; r < i; i--) //�Ժ���ǰ�����Ԫ��
			_elem[i] = _elem[i - 1]; //˳�κ���һ����Ԫ
		_elem[r] = e; _size++; //������Ԫ�ز���������
	} //����Ԫ��
	Rank insert(T const& e) { return insert(_size, e); } //Ĭ����ΪĩԪ�ز���
	void sort(Rank lo, Rank hi); //��[lo, hi)����
	void sort() { sort(0, _size); } //��������

	void unsort(Rank lo, Rank hi)
	{
	T* V = _elem + lo; //��������_elem[lo, hi)������һ����V[0, hi - lo)
	for (Rank i = hi - lo; 1 < i; --i) //�Ժ���ǰ
	swap(V[i - 1], V[rand() % i]); //��V[i - 1]��V[0, i)��ĳһԪ���������
	}//��[lo, hi)����
	void unsort() { unsort(0, _size); } //��������
	int deduplicate() { //ɾ�������������ظ�Ԫ�أ���Ч�棩
		int oldSize = _size; //��¼ԭ�� //����ɾ��[i]��O(_size-i)
		Rank i = 0;
		while (i < _size - 1) {
			Rank j;
			j = i + 1;
			while (j < _size) {
				if ((_elem[i].real1() == _elem[j].real1()) && (_elem[i].image1() == _elem[j].image1())) {
					remove(j, j + 1);}
				else {j++;}}
			i++;
		}return oldSize - _size; //��ɾ��Ԫ������
}
	Rank uniquify(); //����ȥ��
	// ����
	void traverse(void (*) (T&)); //������ʹ�ú���ָ�룬ֻ����ֲ����޸ģ�
	template <typename VST> void traverse(VST&); //������ʹ�ú������󣬿�ȫ�����޸ģ�
	void findcomplex(Rank lo, Rank hi) {
		cout << "��";
	}
}; //Vector