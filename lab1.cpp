#include <iostream>
#include <cstdint>
#include <vector>
#include <sstream>
#include <string>
#include <limits>

using namespace std;

vector<string> split(string base, char delimeter)
{
    vector<string> result;
    stringstream ss(base);
    string item;
    while (getline(ss, item, delimeter))
        result.push_back(item);
    return result;
}

struct TestStats
{
    int test, set;
    string path, initialData, expectedOutput, output, result;

    TestStats(string in, string out)
    {
        auto input = split(in, ',');
        auto output = split(out, ',');

        path = "";
        result = "";
        test = stoi(input[1]), set = stoi(input[2]);
        expectedOutput = output[0];
        initialData = input[0];
    }

    bool addGraphNode(int node)
    {
        return addGraphNode(to_string(node));
    }

    bool addGraphNode(string node)
    {
        if (path == "")
        {
            path += node;
        }
        else
        {
            path += "-" + node;
        }
        return true;
    }

    void addResult(string s)
    {
        if (!result.empty())
        {
            result += ';';
        }

        result += s;
    }
};

void solve(TestStats &test)
{
    stringstream ss(test.initialData);

    test.addGraphNode(1);
    int number;
    vector<int> numbers;

    while (test.addGraphNode(2))
    {
        if (ss.rdbuf()->in_avail() == 0 || ss.eof())
        { // checks wether string is empty
            break;
        }
        test.addGraphNode(3);
        ss >> number;
        test.addGraphNode(4);
        if (ss.fail())
        {
            test.addGraphNode(5);
            ss.clear();
            ss.ignore(1, ' ');
            test.addResult("Invalid number");
        }
        else
        {
            test.addGraphNode(6);
            numbers.push_back(number);
        }
    }

    test.addGraphNode(7);
    int numbersCount = numbers.size(), i = 0;

    test.addGraphNode(8);
    if (numbersCount < 2)
    {
        test.addGraphNode(9);
        test.addResult("No numbers to compare");
        test.addGraphNode(15);
        return;
    }

    while (true)
    {
        test.addGraphNode(10);
        if (i >= numbersCount - 1)
        {
            break;
        }

        test.addGraphNode(11);
        if (numbers[i] <= 5)
        {
            test.addGraphNode(12);
            if (numbers[i + 1] > 0)
            {
                test.addGraphNode(13);
                auto res = "(" + to_string(numbers[i]) + "; " + to_string(numbers[i + 1]) + ")";
                test.addResult(res);
            }
        }
        test.addGraphNode(14);
        i++;
    };

    test.addGraphNode(15);
    return;
}

void printResult(TestStats test)
{
    cout << "1. Test #" << test.test << endl;
    cout << "2. Set #" << test.set << endl;
    cout << "3. Path: " << test.path << endl;
    cout << "4. Initial data: " << test.initialData << endl;
    cout << "5. Expected output: " << test.expectedOutput << endl;
    cout << "6. Test output: " << test.result << endl;
    cout << "7. Result: " << (test.expectedOutput == test.result ? "PASSED" : "NOT PASSED") << endl;
    cout << "---------------------------------------------------------------" << endl;
}

int main()
{
    freopen("lab1-tests.txt", "r", stdin);
    freopen("lab1-out.txt", "w", stdout);

    string t, s;
    while (getline(cin, t))
    {
        if (t.empty())
            break;
        getline(cin, s);
        auto test = TestStats(t, s);
        solve(test);
        printResult(test);
    }

    return 0;
}