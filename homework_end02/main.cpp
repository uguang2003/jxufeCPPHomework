#include <iostream>

using namespace std;

// 用选择法对数组进行排序
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

// 在已排序数组中插入一个数
void insertIntoSortedArray(int arr[], int arr2[], int size, int num) {
    //将num按arr的顺序插入到arr2中，大的元素往后移
    int i = 0, j = 0;
    while (i < size - 1 && arr[i] < num) {
		arr2[j++] = arr[i++];
	}
    arr2[j++] = num;
    while (i < size) {
		arr2[j++] = arr[i++];
	}
}

// 将数组中的值按逆序重新存放
void reverseArray(int arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        swap(arr[i], arr[size - 1 - i]);
    }
}

// 使用折半查找法找出数在数组中的位置
int binarySearch(int arr[], int n, int target) {
    int low = 0;
    int high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target) {
            return mid + 1;
        }
        else if (arr[mid] < target) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return -1;
}

int main() {
    // 1. 用选择法对10个整数排序
    int arr1[] = { 9, 4, 2, 7, 5, 1, 8, 3, 6, 10 };
    selectionSort(arr1, 10);
    cout << "排序后的数组: ";
    for (int i = 0; i < 10; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;

    // 2. 有一个已排好序的数组，在原来排序的规律插入一个数
    int inputNum;
    cout << "请输入要插入的数据: ";
    cin >> inputNum;
    int arr2[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int arrResult[11] = {};
    int size = 11;
    insertIntoSortedArray(arr2, arrResult, size, inputNum);
    cout << "插入后的数组: ";
    for (int i = 0; i < 11; i++) {
        cout << arrResult[i] << " ";
    }
    cout << endl;

    // 3. 将数组中的值按逆序重新存放
    int arr3[] = { 9, 8, 7, 6, 5 };
    reverseArray(arr3, 5);
    cout << "逆转数组: ";
    for (int i = 0; i < 5; i++) {
        cout << arr3[i] << " ";
    }
    cout << endl;

    // 4. 在一个大到小排序的数组中使用折半查找法找出一个数的位置
    int arr4[] = { 15, 13, 11, 9, 7, 5, 3, 1, -1, -3, -5, -7, -9, -11, -13 };
    int searchNum;
    cout << "请输入要查找的数据: ";
    cin >> searchNum;
    int index = binarySearch(arr4, 15, searchNum);
    if (index != -1) {
        cout << "所在的位置为: " << index << endl;
    }
    else {
        cout << "无此数" << endl;
    }

    return 0;
}
