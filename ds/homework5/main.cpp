#include <iostream>
#include <chrono>
#include <random>
using namespace std;

// 定义排序算法函数
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}
void merge(int arr[], int* L, int n1, int* R, int n2) {
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int n) {
    if (n < 2) {
        return;
    }
    int mid = n / 2;
    int* left = new int[mid];
    int* right = new int[n - mid];
    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }
    for (int i = mid; i < n; i++) {
        right[i - mid] = arr[i];
    }
    mergeSort(left, mid);
    mergeSort(right, n - mid);
    merge(arr, left, mid, right, n - mid);
    delete[] left;
    delete[] right;
}


int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}
void quickSort(int arr[], int n) {
    if (n < 2) {
        return;
    }
    int pivot = arr[0];
    int i = 1, j = n - 1;
    while (i <= j) {
        while (i <= j && arr[i] < pivot) {
            i++;
        }
        while (i <= j && arr[j] >= pivot) {
            j--;
        }
        if (i < j) {
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[0], arr[j]);
    quickSort(arr, j);
    quickSort(arr + j + 1, n - j - 1);
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }
    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// 定义测试函数
void testSort(void (*sortFunc)(int[], int), string sortName, int arr[], int n) {
    chrono::steady_clock::time_point start = chrono::steady_clock::now();
    sortFunc(arr, n);
    chrono::steady_clock::time_point end = chrono::steady_clock::now();
    chrono::microseconds time = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << sortName << "排序用时：" << time.count() << " 微秒" << endl;
}

// 定义生成随机数函数
void generateRandomArray(int arr[], int n) {
    default_random_engine e;
    uniform_int_distribution<int> u(1, n);
    for (int i = 0; i < n; i++) {
        arr[i] = u(e);
    }
}

// 定义生成逆序数列函数
void generateReverseArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = n - i;
    }
}

// 定义输出数组函数
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    const int n = 1000;
    int arr[n];
    generateRandomArray(arr, n);
    cout << "随机序列：" << endl;
    //printArray(arr, n);
    testSort(bubbleSort, "冒泡", arr, n);
    testSort(insertionSort, "插入", arr, n);
    testSort(selectionSort, "选择", arr, n);
    testSort(mergeSort, "归并", arr, n);
    testSort(quickSort, "快速", arr, n);
    testSort(heapSort, "堆", arr, n);

    generateReverseArray(arr, n);
    cout << "逆序序列：" << endl;
    //printArray(arr, n);
    testSort(bubbleSort, "冒泡", arr, n);
    testSort(insertionSort, "插入", arr, n);
    testSort(selectionSort, "选择", arr, n);
    testSort(mergeSort, "归并", arr, n);
    testSort(quickSort, "快速", arr, n);
    testSort(heapSort, "堆", arr, n);

    generateRandomArray(arr, n);
    cout << "顺序序列：" << endl;
    //printArray(arr, n);
    testSort(bubbleSort, "冒泡", arr, n);
    testSort(insertionSort, "插入", arr, n);
    testSort(selectionSort, "选择", arr, n);
    testSort(mergeSort, "归并", arr, n);
    testSort(quickSort, "快速", arr, n);
    testSort(heapSort, "堆", arr, n);

    return 0;
}
