#include <iostream>
#include <cstdint>
using namespace std;


bool PRINT_STEP(int step) {
    cout << "[TEST OUTPUT] Step: " << step << endl;
    return true;
}

int main() {
//    freopen("input.txt", "r", stdin);
    PRINT_STEP(1);
    cout << "Input the count of numbers, up to " << std::numeric_limits<int>::max() << ":" << endl; // 1
    int32_t inputCount = 0; // 1
    cin >> inputCount; // 1

    while ((PRINT_STEP(2) && cin.fail()) // 2
                             || (PRINT_STEP(3) && inputCount < 0)) { // 3
        PRINT_STEP(4);
        cin.clear(); // 4
        cin.ignore(); // 4
        cout << "Invalid input, please input the amount of numbers " << endl; // 4
        cin >> inputCount; // 4
        PRINT_STEP(5);
    } // 5

    PRINT_STEP(6);
    uint32_t i = 0; // 6
    uint32_t answerCount = 0; // 6
    int64_t answerSum = 0; // 6

    while (PRINT_STEP(7) && i < inputCount) { // 7
        PRINT_STEP(8);
        std::cout << "Input integer from " << std::numeric_limits<int>::min() << " to "
                  << std::numeric_limits<int>::max()
                  << ":" << std::endl; // 8
        int32_t number;
        cin >> number; // 8
        if (PRINT_STEP(9) && cin.fail()) { // 9
            PRINT_STEP(10);
            cin.clear(); // 10
            cin.ignore(); // 10
            cout << "Invalid input!" << std::endl; // 10
        } else {
            PRINT_STEP(11);
            i++; // 11
            if (PRINT_STEP(12) && number % 5 == 0) { // 12
                if (PRINT_STEP(13) && number % 7 != 0) { // 13
                    PRINT_STEP(14);
                    answerCount++; // 14
                    answerSum += number; // 14
                } // 15
                PRINT_STEP(15);
            } // 16
            PRINT_STEP(16);
        } // 17
        PRINT_STEP(17);
        PRINT_STEP(18);
    } // 18
    PRINT_STEP(19);
    std::cout << "Count is " << answerCount <<
              std::endl; // 19
    std::cout << "Sum is " << answerSum <<
              std::endl; // 19
    return 0;
}
