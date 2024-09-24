#include <iostream>

using namespace std;

int main()
{
    int arr[] = { -3, -2, -1, 0, 1, 2, 3 };
    int arr2[7] = {};
    int sum = 0;
    //将数组中的元素平方
    for (int i = 0; i < 7; i++)
	{
        arr2[i] = arr[i] * arr[i];
        sum += arr2[i];
	}
    //输出平方后的数组
    cout << "平方后的数据为:";
    for (int i = 0; i < 7; i++)
    {
	    cout << arr2[i] << " ";
    }
    cout << endl << "数组和为:" << sum << endl;

    string str = "Hello C++ Program!";
    cout << str << endl;
    cout << "字符的长度为:" << str.size() << endl;

    return 0;
}
