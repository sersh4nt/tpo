#include <iostream>
#include <cstdint>

using namespace std;

bool PRINT_STEP(int step)
{
    cout << "[TEST OUTPUT] Step: " << step << endl;
    return true;
}

int main(int argc, char *argv[])
{
    freopen(argv[1], "r", stdin);

    cout << "Input the count of numbers, up to " << numeric_limits<int>::max() << ":" << endl; // 1
    int32_t inputCount = 0;                                                                    // 1
    cin >> inputCount;                                                                         // 1

    while ((PRINT_STEP(2) && cin.fail())         // 2
           || (PRINT_STEP(3) && inputCount < 0)) // 5
    {
        PRINT_STEP(4);
        cin.clear();
        cin.ignore();                                                            // 3
        cout << "Invalid input, please input the amount of numbers > 0" << endl; // 3
        cin >> inputCount;                                                       // 3
        PRINT_STEP(5);
    } // 4

    PRINT_STEP(6);        // 6
    uint32_t i = 0;       // 6
    int32_t prev, number; // 6

    while (PRINT_STEP(7) && i < inputCount) // 7
    {
        PRINT_STEP(8);                                                        // 8
        cout << "Input integer from " << numeric_limits<int>::min() << " to " // 8
             << numeric_limits<int>::max()                                    // 8
             << ":" << endl;                                                  // 8
        cin >> number;                                                        // 8
        if (PRINT_STEP(9) && cin.fail())                                      // 9
        {
            PRINT_STEP(10);                        // 10
            cin.clear();                           // 10
            cin.ignore();                          // 10
            cout << "Invalid input!" << std::endl; // 10
        }
        else
        {
            if (PRINT_STEP(11) && i > 0) // 11
            {
                if (PRINT_STEP(12) && number > 0) // 12
                {
                    if (PRINT_STEP(13) && prev <= 5) // 13
                    {
                        PRINT_STEP(14);                                                                                          // 14
                        cout << "Found pair: a_" << i << "=" << prev << " <= 5, a_" << i + 1 << "=" << number << " > 0" << endl; // 14
                    }
                }
            }
            PRINT_STEP(15); // 15
            i++;            // 15
            prev = number;  // 15
        }
    }

    PRINT_STEP(16); // 16
    return 0;
}