#include <iostream>
#include <cstdint>
#include <vector>

using namespace std;

bool PRINT_STEP(int step)
{
    cout << "[TEST OUTPUT] Step: " << step << endl;
    return true;
}

void solve()
{
    cout << "Input the count of numbers" << endl; // 1
    int inputCount = 0;                           // 1
    cin >> inputCount;                            // 1

    if (cin.fail() && PRINT_STEP(2)         // 2
        || PRINT_STEP(3) && inputCount < 0) // 3
    {
        PRINT_STEP(4);                                    // 4
        cin.clear();                                      // 4
        // cin.ignore();                                     // 4
        cout << "Invalid inputCount, exiting..." << endl; // 4
        return;
    }

    PRINT_STEP(5);       // 5
    int i = 0, number;   // 5
    vector<int> numbers; // 5

    while (PRINT_STEP(6) && i < inputCount) // 6
    {
        PRINT_STEP(7); // 7
        // cout << "Input integer from " << numeric_limits<int>::min() << " to " // 7
        //      << numeric_limits<int>::max()                                    // 7
        //      << ":" << endl;                                                  // 7
        cin >> number;                   // 7
        if (PRINT_STEP(8) && cin.fail()) // 8
        {
            PRINT_STEP(9);                         // 9
            cin.clear();                           // 9
            // cin.ignore();                          // 9
            cout << "Invalid input!" << std::endl; // 9
        }
        else
        {
            PRINT_STEP(10);
            numbers.push_back(number); // 10
        }
        PRINT_STEP(11); // 11
        i++;            // 11
    }

    PRINT_STEP(12);                    // 12
    i = 0;                             // 12
    int numbersCount = numbers.size(); // 12

    if (PRINT_STEP(13) && numbersCount < 2)
    {
        cout << "No numbers to compare" << endl; // 13
        return;                                  // 13
    }

    while (PRINT_STEP(14) && i < numbersCount - 1)
    {
        if (PRINT_STEP(15) && numbers[i] <= 5) // 15
        {
            if (PRINT_STEP(16) && numbers[i + 1] > 0) // 16
            {
                PRINT_STEP(17);                                                                                                        // 16
                cout << "Found pair: a_" << i << "=" << numbers[i] << " <= 5, a_" << i + 1 << "=" << numbers[i + 1] << " > 0" << endl; // 16
            }
        }
        PRINT_STEP(18); // 18
        i++;            // 18
    }
}

int main()
{
    freopen("lab1-tests.txt", "r", stdin);
    freopen("lab1-out.txt", "w", stdout);
    int testCount = 1;
    string exp_out;
    while (!cin.eof())
    {
        solve();
        PRINT_STEP(19); // 19
        getline(cin, exp_out);
        cout << "Test [" << testCount << "]"
             << ". Expected output: " << exp_out << endl;
        ++testCount;
    }
    return 0;
}