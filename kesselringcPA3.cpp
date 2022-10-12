#include <iostream> // input/output(io)
#include <string>

using namespace std; // allows us to type the following instead of line 5
// cout << "content";
// std::cout << "content";

int main()
{
    string enter;
    int n;
    int factorial = 1;
    int factorialTwo = 1;
    cout << "Enter an integer you want the fractal of." << endl;
    cin >> n;
    int m = n;
    while (n > 0)
    {
        factorial = factorial * n;
        n--;
    }
    for (int i = m; i > 0; i--)
    {
        factorialTwo *= i;
    }

    cout << "While loop: " << factorial << "\nFor loop: " << factorialTwo << endl;

    cout << "Press enter to continue:";
    cin.ignore();
    getline(cin, enter);

    int paychecks;
    int paycheckAmount;
    int paycheckSum = 0;
    cout << "Enter how many paychecks." << endl;
    cin >> paychecks;
    cout << "How much was this paycheck?" << endl;
    while (paychecks > 0)
    {
        cin >> paycheckAmount;
        paycheckSum += paycheckAmount;
        paychecks--;
    }
    if (paycheckSum < 15000)
    {
        cout << "You are low income." << endl;
    }
    else if (paycheckSum >= 15000 && paycheckSum < 200000)
    {
        cout << "You are medium income." << endl;
    }
    else
    {
        cout << "You are high income." << endl;
    }
    cout << "Your total pay is $" << paycheckSum << endl;

    cout << "Press enter to continue:";
    cin.ignore();
    getline(cin, enter);

    int digits = 0;
    int sum = 0;
    cout << "Enter an integer to sum the digits of: ";
    cin >> digits;

    while (digits > 0)
    {
        sum += digits % 10;
        digits = digits / 10;
    }
    cout << sum << endl;

    cout << "Press enter to continue:";
    cin.ignore();
    getline(cin, enter);

    cout << "Please enter the number of terms to approximate pi: ";
    double pi = 4;
    int denom = 1;
    int reps;
    int num1 = 2;

    cin >> reps;
    while (reps > 0)
    {
        if (num1 % 2 == 1)
        {
            denom = denom + 2;
            pi += 4.0 / denom;
            // cout << num1 << " and " << denom << endl;
            num1 = num1 + 1;
        }
        else
        {
            denom = denom + 2;
            pi -= 4.0 / denom;
            num1 = num1 + 1;
        }
        reps--;
    }
    cout << pi << endl;

    cout << "Press enter to continue:";
    cin.ignore();
    getline(cin, enter);

    int row;
    cout << "Please enter an integer: ";
    cin >> row;
    int rowSum = 0;
    for (int i = 1; i <= row; i++)
    {
        rowSum = 0;
        for (int j = i; j > 0; j--)
        {
            cout << i;
            rowSum += i;
        }
        cout << " " << rowSum << endl;
    }

    return 0;
}