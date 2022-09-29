#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
struct name
{
	int number;
	string frist;
	string last;
	bool operator <(name a) {
		if (number == a.number) return a.number;
		return number < a.number;
        
	}
};
int main() {
	ifstream fin("test.inp");
	ofstream fout("test.out");

	int n, len = -1;

	fin >> n;
	vector<string> la; //문자열 벡터
	vector<name> arr(n); //내가 정의한 자료형으로 만든 벡터
	for (int i = 0; i < n; i++) {
		fin >> arr[i].number >> arr[i].frist >> arr[i].last; //자료 삽입 과정
		
		string fl = arr[i].frist;
		la.push_back(arr[i].last);
		int tmp = fl.length();
		if (tmp > len) len = tmp;
	}
	sort(arr.begin(),arr.end());
	sort(la.begin(), la.end());
	la.erase(unique(la.begin(), la.end()), la.end());
	int* lacnt = new int[la.size()]();

	for (int i = 0; i < n; i++) {
		cout.width(5); cout.fill('0');
		cout << std::right << arr[i].number << " ";
		cout.width(len + 1); cout.fill(' ');
		cout << std::left << arr[i].frist << std::left << arr[i].last << endl;
		for (int j = 0; j < la.size(); j++) {
			if (arr[i].last == la[j])
				lacnt[j]++;
		}
	}
	cout << endl;
	for (int i = 0; i < la.size(); i++) {
		if (lacnt[i] > 1)
			cout << la[i] << " " << lacnt[i] << endl;
	}
	delete[]lacnt;
	fin.close();
	fout.close();
}