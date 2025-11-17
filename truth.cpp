#include <iostream>
#include <vector>
using namespace std;

bool checkSorted(vector<int> numbers){

    bool goingUp = false;
    bool goingDown = false;

    for (int i = 0; i < numbers.size() - 1; i++)
    {
        if (numbers[i] < numbers[i + 1]){
            goingUp = true;
        }
        else if (numbers[i] > numbers[i + 1]){ 
            goingDown = true;
        }

        if (goingUp == true && goingDown == true){ 
            return false;
        }
    }

    return true;
}

bool targetSum(vector<int> nums, vector<int> indexes, int target){

    int total = 0;
   
    for (int i = 0; i < indexes.size(); i++){
    
        int index = indexes[i];

        if (index < 0 || index >= nums.size()){  
            cout << "Invalid Indx" << endl;
        }
        else{       
            total = total + nums[index];
        }
    }

    if (total == target){   
        return true;
    }
    else{  
        return false;
    }
}

bool prime(int n)
{
    if (n <= 1){    
        return false;
    }

    if (n == 2 || n == 3){
        return true;
    }

    if (n % 2 == 0 || n % 3 == 0){ 
        return false;
    }

    int i = 5;
    while (i * i <= n)
    {
        if (n % i == 0 || n % (i + 2) == 0)
        {
            return false;
        }
        i = i + 6;
    }

    return true;
}

bool checkPrimeFactorization(int number, const vector<int>& factors) {

    if (number == 1)
    {
        if (factors.empty()) {
            return true;
        }
        else {
            return false;
        }
    }

    if (number <= 0) {
        return false;
    }

    int product = 1;

    for (int i = 0; i < factors.size(); i++){
    
        int f = factors[i];

        if (f <= 1){  
            return false;
        }

        if (prime(f) == false) {
            return false;
        }

        product = product * f;
    }

    if (product == number) {    
        return true;
    }
    else {
        return false;
    }

}

int main()
{
    cout << "For Refreence --> 1 = True || 0 = False" << endl;

    vector<int> ascend = { 1, 2, 3, 4 };
    vector<int> descend = { 4, 3, 2, 1 };
    vector<int> mix = { 1, 2, 3, 6, 5, 4 };

    cout << checkSorted(ascend) << endl;
    cout << checkSorted(descend) << endl;
    cout << checkSorted(mix) << endl;

    vector<int> nums1 = { 10, 20, 30, 40, 50 };
    vector<int> indx1 = { 0, 2, 4 };
    cout << targetSum(nums1, indx1, 90) << endl;

    vector<int> nums2 = { 5, 10, 15 };
    vector<int> indx2 = { 0, 0, 0 };
    cout << targetSum(nums2, indx2, 15) << endl;

    vector<int> nums3 = { 1, 2, 3 };
    vector<int> indx3 = { 0, 1, 2, 3 };
    cout << targetSum(nums3, indx3, 6) << endl;

    cout << checkPrimeFactorization(60, { 2, 2, 3, 5 }) << endl;
    cout << checkPrimeFactorization(60, { 6, 10 }) << endl;
    cout << checkPrimeFactorization(60, { 2, 2, 3, 5, 2 }) << endl;
    cout << checkPrimeFactorization(12, { 1, 2, 2, 3 }) << endl;
    cout << checkPrimeFactorization(7, { 7 }) << endl;
    cout << checkPrimeFactorization(1, {}) << endl;

    return 0;
}
