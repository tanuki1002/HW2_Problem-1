#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Manacher’s Algorithm
string LPS(string str)
{
	// 輸入空字串的情況
	if (str.length() == 0)
		return "";

	//初始化  string
	//為了避免處理時的邊界判斷，在頭尾又分別加上 $ 與 ＠
	string temp = "$#";
	for (int i = 0; i < str.length(); i++)
	{
		temp += str[i];
		temp += "#";
		if (i == str.length() - 1)
			temp += "@";
	}
	

	int m = temp.length();
	vector<int> max_extend( m, 0);
	max_extend[1] = 1; //因為關注點從位置2開始(ex. $#a... => 012...)
	int j = 1; //$#a => ( j )
	int n = str.length();
	for (int i = 2; i <= 2 * n; i++) // 以 i 為中心的回文
	{
		int cur_max_extend; //求 max_extend 的 i
		if (j + max_extend[j] > i)
		{
			//處理 csae 2 (三種邊界：>, =, <)
			cur_max_extend = min(max_extend[j * 2 - i], j + max_extend[j] - i);
		}			
		else
		{
			//處理 case 1 (暴力擴展 與下面while有關)
			//如果 i 超過右邊界，要從頭開始計算
			cur_max_extend = 1; 
		}

		//從中心向兩邊擴展 (暴力擴展)
		while (temp[i - cur_max_extend] == temp[i + cur_max_extend])
		{
			cur_max_extend++;
		}
		//嘗試更新暴力擴展完的值
		if (i + cur_max_extend > j + max_extend[j])
			j = i;
		max_extend[i] = cur_max_extend;
	}


	//求最長迴文子串
	int mx = 0, p = -1;
	for (int i = 2; i <= 2 * n; i++)
	{
		if (max_extend[i] - 1 > mx)
		{
			mx = max_extend[i] - 1; //原串中的迴文長度 (#數量比字符多一)
			p = (i - max_extend[i]) / 2;
		}
	}

	//取範圍 p(開始位置), mx(串長) 作為輸出答案
	return str.substr(p, mx);
}

int main() {
	//輸入
	string input;
	cout << "請輸入字串：" << endl;
	getline(cin, input);
	cout << endl;

	//輸出
	cout << "輸出答案為：" << endl;
	cout << LPS(input);

	return 0;
}



