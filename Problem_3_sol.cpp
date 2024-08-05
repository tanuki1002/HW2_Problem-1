#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm> // 用於 max 和 min 函數
#include <limits>    // 用於 numeric_limits
using namespace std;

double find_median(vector<int>& nums1, vector<int>& nums2) {
    // 確保 nums1 比 nums2 短
    if (nums1.size() > nums2.size()) 
    {
        swap(nums1, nums2);
    }

    int m = nums1.size();
    int n = nums2.size();
    int left_size = (m + n + 1) / 2; //固定左側長度，確保 median 在左側
    int left = 0, right = m;
 
    //當 left == right 時代表找到分割點，結束搜尋
    while (left < right)
    { 
        int ptr1 = left + (right - left + 1) / 2;
        int ptr2 = left_size - ptr1;
        if (nums1[ptr1 - 1] > nums2[ptr2]) 
        {
            right = ptr1 - 1;
        }
        else 
        {
            left = ptr1;
        }
    }

    // 設置最終分割點
    int ptr1 = left;
    int ptr2 = left_size - left;

    // 處理邊界情況
    int nums1_left_max = (ptr1 == 0) ? numeric_limits<int>::min() : nums1[ptr1 - 1];
    int nums1_right_min = (ptr1 == m) ? numeric_limits<int>::max() : nums1[ptr1];
    int nums2_left_max = (ptr2 == 0) ? numeric_limits<int>::min() : nums2[ptr2 - 1];
    int nums2_right_min = (ptr2 == n) ? numeric_limits<int>::max() : nums2[ptr2];

    // 根據奇偶性計算 median
    if ((m + n) % 2 == 1) {
        return max(nums1_left_max, nums2_left_max);
    }
    return (max(nums1_left_max, nums2_left_max) + min(nums1_right_min, nums2_right_min)) / 2.0;
}

int main() {
    //輸入
    string input_1, input_2;
    cout << "請輸入第一個陣列：" << endl;
    getline(cin, input_1);
    cout << endl;

    cout << "請輸入第二個陣列：" << endl;
    getline(cin, input_2);
    cout << endl;

    //字串轉換數字陣列
    vector<int> nums1;
    vector<int> nums2;
    stringstream ss_1(input_1);
    stringstream ss_2(input_2);
    string token;
    while (getline(ss_1, token, ',')) {
        nums1.push_back(stoi(token));
    }
    while (getline(ss_2, token, ',')) {
        nums2.push_back(stoi(token));
    }

    double median = find_median(nums1, nums2);
    cout << "輸出答案為：" << endl;
    cout  << median;

    return 0;
}

