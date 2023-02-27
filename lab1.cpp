#include <iostream>
#include <cstdint>

using namespace std;

bool PRINT_STEP(int step)
{
    cout << "[TEST OUTPUT] Step: " << step << endl;
    return true;
}

int main()
{
    cout << "Input the count of numbers, up to " << numeric_limits<int>::max() << ":" << endl; // 1
    int32_t inputCount = 0;                                                                    // 1
    cin >> inputCount;                                                                         // 1

    while ((PRINT_STEP(2) && cin.fail())         // 2
           || (PRINT_STEP(3) && inputCount < 1)) // 3
    {
        PRINT_STEP(4);
        cin.clear();
        cin.ignore();                                                             // 4
        cout << "Invalid input, please input the amount of numbers > 2 " << endl; // 4
        cin >> inputCount;                                                        // 4
        PRINT_STEP(5);
    } // 5

    PRINT_STEP(6);        // 6
    uint32_t i = 0;       // 6
    int32_t prev, number; // 6

    while (PRINT_STEP(7) && i < inputCount) // 7
    {
        PRINT_STEP(8);
        cout << "Input integer from " << numeric_limits<int>::min() << " to "
             << numeric_limits<int>::max()
             << ":" << endl; // 8
        cin >> number;
        if (PRINT_STEP(9) && cin.fail())
        {
            PRINT_STEP(10);
            cin.clear();
            cin.ignore();
            cout << "Invalid input!" << std::endl;
        }
        else
        {
            if (i > 0) {
                if (number > 0)  {
                    if (prev <= 5) {
                        cout << "Found pair: a_" << i << "=" << prev << " <= 5, a_" << i + 1 << "=" << number << " > 0" << endl;
                    }
                }
            }
            i++;
            prev = number;
        }
    }

    return 0;
}