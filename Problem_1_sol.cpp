#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main() {
	string temp;
	cout << "請輸入數字陣列：" << endl;
	getline(cin, temp); //因為有可能輸入空陣列，故使用getline 而不是cin
	cout << endl;

	int target; //要尋找的目標數字
	cout << "請輸入目標數字：" << endl;
	cin >> target;
	cout << endl;
	
	//字串轉換數字陣列
	vector<int> my_array; 
	stringstream ss(temp);
	string token;
	while (getline(ss, token, ',')) {
		my_array.push_back(stoi(token));
	}

	//找目標
	int ans1 = -1, ans2 = -1;
	if (my_array.size() != 0)
	{
		for (int j = 0; j < my_array.size(); j++)
		{
			if (ans1 == -1) //找第一個
			{
				if (my_array[j] == target)
					ans1 = j, ans2 = j; //有可能整串陣列只有一個目標數字
			}
			else //若第一個目標數字已經找到，就開始找第二個
			{
				if (my_array[j] == target)
					ans2 = j;
			}
		}
	}

	cout << "輸出：[" << ans1 << "," << ans2 << "]";

	return 0;
 }





