#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> nums(n);
	vector<int>::iterator it;
	for (int i = 0; i < n; i++)
		cin >> nums[i];
	sort(nums.begin(), nums.end());
	it = nums.begin();
	while(it != nums.end()-1) {
		if (*it == *(it + 1)) {
			it = nums.erase(it);
		}
		else
			it++;
	}
	cout << nums.size() << ": ";
	for (int num : nums)
		cout << num << " ";
	cout << endl;
	return 0;
}