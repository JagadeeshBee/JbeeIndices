#include <iostream>
#include <unordered_map>
#include <vector>
#include <limits>  
// For numeric limits

using namespace std;

// Function to find the indices of two numbers that add up to the target
vector<int> findTwoSum(const vector<int>& nums, int target) {
    unordered_map<int, int> numMap;  
    // Store the complement and corresponding index
    
    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];
        
        if (numMap.find(complement) != numMap.end()) {
            return {numMap[complement], i};  
            // Return indices of the two numbers
        }
        
        numMap[nums[i]] = i;  
        // Store the index of the current number
    }

    // As per problem constraints, we are guaranteed to find exactly one solution.
    return {}; 
     // Return an empty vector if no solution is found (this won't happen according to problem constraints)
}

// Function to get valid integer input from the user within the given range
int getValidIntegerInput(const string& prompt, int minValue, int maxValue) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail() || value < minValue || value > maxValue) {
            cin.clear();  // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore invalid input
            cout << "Invalid input. Please enter a value between " << minValue << " and " << maxValue << ".\n";
        } else {
            return value;
        }
    }
}

// Function to get the list of integers from the user
vector<int> getArrayInput(int size) {
    vector<int> nums;
    for (int i = 0; i < size; ++i) {
        int num = getValidIntegerInput("Enter element " + to_string(i + 1) + ": ", 
                                       numeric_limits<int>::min(), numeric_limits<int>::max());
        nums.push_back(num);
    }
    return nums;
}

int main() {
    // Input validation for the number of elements in the array
    int n = getValidIntegerInput("Enter the number of elements in the array (2 <= nums.length <= 10^4): ", 2, 10000);
    
    // Input array elements
    cout << "Enter the elements of the array:\n";
    vector<int> nums = getArrayInput(n);
    
    // Input validation for the target value
    int target = getValidIntegerInput("Enter the target value: ", numeric_limits<int>::min(), numeric_limits<int>::max());

    // Find the two indices that sum up to the target
    vector<int> result = findTwoSum(nums, target);
    
    if (!result.empty()) {
        cout << "Indices found: [" << result[0] << ", " << result[1] << "]\n";
    } else {
        cout << "No valid solution found.\n";  
        // This case won't occur due to problem constraints
    }

    return 0;
}
