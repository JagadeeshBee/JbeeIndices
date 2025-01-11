#include <iostream>
#include <unordered_map>
#include <vector>
#include <limits>
#include <stdexcept>

const int MIN_ARRAY_SIZE = 2;
const int MAX_ARRAY_SIZE = 10000;

std::vector<int> findTwoSum(const std::vector<int>& nums, int target) {
    std::unordered_map<int, int> numMap;

    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];

        if (numMap.find(complement) != numMap.end()) {
            return {numMap[complement], i};
        }

        numMap[nums[i]] = i;
    }

    throw std::runtime_error("No solution found, but this should not happen according to problem constraints.");
}

int getValidIntegerInput(const std::string& prompt, int minValue, int maxValue) {
    int value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;
        if (std::cin.fail() || value < minValue || value > maxValue) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a value between " << minValue << " and " << maxValue << ".\n";
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the buffer after valid input
            return value;
        }
    }
}

std::vector<int> getArrayInput(int size) {
    std::vector<int> nums;
    nums.reserve(size); // Reserve space in advance
    for (int i = 0; i < size; ++i) {
        int num = getValidIntegerInput("Enter element " + std::to_string(i + 1) + ": ", 
                                       std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
        nums.push_back(num);
    }
    return nums;
}

int main() {
    int n = getValidIntegerInput("Enter the number of elements in the array (2 <= nums.length <= 10^4): ", MIN_ARRAY_SIZE, MAX_ARRAY_SIZE);
    
    std::cout << "Enter the elements of the array:\n";
    std::vector<int> nums = getArrayInput(n);
    
    int target = getValidIntegerInput("Enter the target value: ", std::numeric_limits<int>::min(), std::numeric_limits<int>::max());

    try {
        std::vector<int> result = findTwoSum(nums, target);
        std::cout << "Indices found: [" << result[0] << ", " << result[1] << "]\n";
    } catch (const std::runtime_error& e) {
        std::cout << e.what() << "\n";  
    }

    return 0;
}
