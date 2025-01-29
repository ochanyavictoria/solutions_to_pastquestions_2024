#include <iostream>
#include <string>

class Questions {
public:
    // Question 2a: Check if a number is prime
    bool isPrime(int* num) {
        if (*num <= 1) return false;
        for (int i = 2; i * i <= *num; i++) {
            if (*num % i == 0) return false;
        }
        return true;
    }

    // Question 2b: Compute the sum of all elements in an array
    int sumOfArray(int* arr, int size) {
        int sum = 0;
        for (int i = 0; i < size; i++) {
            sum += arr[i];
        }
        return sum;
    }

    // Question 3a: Implement bubble sort
    void bubbleSort(int* arr, int size) {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    // Swap elements
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    // Question 3b: Read 10 numbers, compute sum and average
    void sumAndAverage(int* arr, int size, int* sum, float* avg) {
        *sum = 0;
        for (int i = 0; i < size; i++) {
            *sum += arr[i];
        }
        *avg = static_cast<float>(*sum) / size;
    }

    // Question 4a: Compute the length of a string
    int stringLength(const char* str) {
        int length = 0;
        while (str[length] != '\0') {
            length++;
        }
        return length;
    }

    // Question 4b: Linear search to find the position of a target value
    int linearSearch(int* arr, int size, int target) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == target) {
                return i;
            }
        }
        return -1; // Not found
    }

    // Question 5a: Add two numbers using pointers
    int addNumbers(int* a, int* b) {
        return *a + *b;
    }

    // Question 5b: Check if a number is a palindrome
    bool isPalindrome(int* num) {
        int original = *num;
        int reversed = 0;
        while (original != 0) {
            reversed = reversed * 10 + original % 10;
            original /= 10;
        }
        return *num == reversed;
    }

    // Question 6a: Student structure and average marks
    struct Student {
        std::string name;
        int age;
        float totalMarks;
    };

    void displayStudentInfo(Student* students, int size) {
        float totalMarks = 0;
        for (int i = 0; i < size; i++) {
            std::cout << "Student " << i + 1 << ":\n";
            std::cout << "Name: " << students[i].name << "\n";
            std::cout << "Age: " << students[i].age << "\n";
            std::cout << "Total Marks: " << students[i].totalMarks << "\n";
            totalMarks += students[i].totalMarks;
        }
        std::cout << "Average Marks: " << totalMarks / size << "\n";
    }

    // Question 6b: Check if a number is odd, even, positive, or negative
    void checkNumber(int* num) {
        if (*num % 2 == 0) {
            std::cout << *num << " is even.\n";
        } else {
            std::cout << *num << " is odd.\n";
        }
        if (*num > 0) {
            std::cout << *num << " is positive.\n";
        } else if (*num < 0) {
            std::cout << *num << " is negative.\n";
        } else {
            std::cout << *num << " is zero.\n";
        }
    }
};

int main() {
    Questions q;

    // Example usage of the functions
    int num = 29;
    std::cout << "Is " << num << " prime? " << (q.isPrime(&num) ? "Yes" : "No") << "\n";

    int arr[] = {5, 2, 9, 1, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    std::cout << "Sum of array: " << q.sumOfArray(arr, size) << "\n";

    q.bubbleSort(arr, size);
    std::cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    int sum;
    float avg;
    q.sumAndAverage(arr, size, &sum, &avg);
    std::cout << "Sum: " << sum << ", Average: " << avg << "\n";

    const char* str = "Hello, World!";
    std::cout << "Length of string: " << q.stringLength(str) << "\n";

    int target = 9;
    int pos = q.linearSearch(arr, size, target);
    std::cout << "Position of " << target << " in array: " << pos << "\n";

    int a = 5, b = 10;
    std::cout << "Sum of " << a << " and " << b << " is " << q.addNumbers(&a, &b) << "\n";

    int palindromeNum = 121;
    std::cout << "Is " << palindromeNum << " a palindrome? " << (q.isPalindrome(&palindromeNum) ? "Yes" : "No") << "\n";

    Questions::Student students[2] = {{"Alice", 20, 95.5}, {"Bob", 21, 89.0}};
    q.displayStudentInfo(students, 2);

    int checkNum = -7;
    q.checkNumber(&checkNum);

    return 0;
}