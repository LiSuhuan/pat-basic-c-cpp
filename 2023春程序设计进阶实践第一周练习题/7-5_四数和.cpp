//
// Created by lenovo on 2023/6/13.
//
//

#include <iostream>
#include <algorithm>
#include<vector>

using namespace std;

int fourSum(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());
    int sum = 0;

    int a, b, c, d, _size = nums.size();
    for (a = 0; a <= _size - 4; a++) {
        for (b = a + 1; b <= _size - 3; b++) {
            c = b + 1, d = _size - 1;
            while (c < d) {
                if (nums[a] + nums[b] - target <
                    -(nums[c] +
                      nums[d]))//nums[a] + nums[b] - target < -(nums[c] + nums[d])，说明nums[c] + nums[d]太大了，需要减小，所以d--
                    c++;
                else if (nums[a] + nums[b] - target > -(nums[c] + nums[d]))//同上
                    d--;
                else {
                    sum++;
                    c++;
                    d--;
                }
            }
        }
    }
    return sum;
}

int main() {
    int N, T;
    cin >> N >> T;
    int *array = new int[4 * N + 5];
    for (int i = 0; i < 4 * N; i += 4) {
        cin >> array[i];
        array[i + 1] = array[i];
        array[i + 2] = array[i];
        array[i + 3] = array[i];
    }

    vector<int> nums(array, array + 4 * N);

    int res = fourSum(nums, T);
    cout << res << endl;

}