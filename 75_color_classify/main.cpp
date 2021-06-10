#include <vector>
#include <iostream>

using namespace std;


void sort(vector<int>& nums) {

    int p0 = 0;
    int p2 = nums.size() - 1;
    int i = 0;

    if (nums.size() < 2) 
        return ;

    while (i <= p2) {
        if (nums[i] == 0) {
            swap(nums[p0], nums[i]);
            ++p0;
            ++i;           
        }else if (nums[i] == 1) {
            ++i;
        }else { // nums[i] == 2
            swap(nums[i], nums[p2]);
            --p2; 
        }          
    }

}

int main() {
    vector<int> input = {2,1,0,2,1,2,1,2,0,0,0};
    //vector<int> input = {2,2,2,2,2,2};
    //vector<int> input = {0,0,0,0,0,0};
    sort(input);
    
    for (auto i : input) {
        cout << i << ",";
    }
    cout << endl;

    return 0;
}
