#include<iostream> 
using namespace std;
// Function to calculate the sum of n natural numbers 
int sumOfNaturalNumbers(int n){
return (n * (n + 1)) / 2;}
// Function to check if a number is prime 
bool isPrime(int num){
    if (num <= 1)
        return false;
    for (int i = 2; i * i <= num; ++i){
        if (num % i == 0)
            return false;}
    return true;
}
// Function to calculate factorial 
int factorial(int n){
    if (n <= 1)
        return 1;
    return n * factorial(n - 1);}
// Function to generate multiplication table 
void generateMultiplicationTable(int num){
    for (int i = 1; i <= 10; ++i)
    {
        cout << num << " * " << i << " = " << num * i << endl;
    }
}
// Function to generate Fibonacci series
void generateFibonacci(int n)
{   int a = 0, b = 1;
    cout << "Fibonacci Series: ";
    for (int i = 1; i <= n; ++i)
    {cout << a << " ";
        int next = a + b;
        a = b;
        b = next;
    }
    cout << endl;
}
int main()
{
    char choice;
    cout << "Menu:\n";
    cout << "a. Add two Numbers\n";
    cout << "b. Subtract two Numbers\n";
    cout << "c. Multiply two Numbers\n";
    cout << "d. Divide two Numbers\n";
    cout << "e. Sum of n Natural Numbers\n";
    cout << "f. Check if the Number is even, odd, or prime\n";
    cout << "g. Factorial of a Number\n";
    cout << "h. Generate Multiplication Table\n";
    cout << "i. Generate Fibonacci Series\n";
    cout << "j. Quit\n";
    do
    {
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {case 'a':
        {double num1, num2;
            cout << "Enter two Numbers: ";
            cin >> num1 >> num2;
            cout << "Result: " << num1 + num2 << endl;
            break;
        }
        case 'b':
        {double num1, num2;
            cout << "Enter two Numbers: ";
            cin >> num1 >> num2;
            cout << "Result: " << num1 - num2 << endl;
            break;
        }
        case 'c':
        {
            double num1, num2;
            cout << "Enter two Numbers: ";
            cin >> num1 >> num2;
            cout << "Result: " << num1 * num2 << endl;
            break;
        }
        case 'd':
        {double num1, num2;
            cout << "Enter two Numbers: ";
            cin >> num1 >> num2;
            if (num2 != 0)
                cout << "Result: " << num1 / num2 << endl;
            else
                cout << "Cannot divide by zero!\n";
            break;
        }
        case 'e':
        {int n;
            cout << "Enter a number: ";
            cin >> n;
            cout << "Sum of " << n << " Natural Numbers: " << sumOfNaturalNumbers(n) << endl;
            break;
        }
        case 'f':
        {int num;
            cout << "Enter a number: ";
            cin >> num;
            if (num % 2 == 0)
                cout << num << " is even.\n";
            else
                cout << num << " is odd.\n";

            if (isPrime(num))
                cout << num << " is prime.\n";
            else
                cout << num << " is not prime.\n";
            break;
        }
        case 'g':
        {int num;
            cout << "Enter a number: ";
            cin >> num;
            cout << "Factorial of " << num << ": " << factorial(num) << endl;
            break;
        }
        case 'h':
        {int num;
            cout << "Enter a number: ";
            cin >> num;
            generateMultiplicationTable(num);
            break;
        }
        case 'i':
        {int n;
            cout << "Enter the number of terms: ";
            cin >> n;
            generateFibonacci(n);
            break;
        }
        case 'j':
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "Invalid choice. Please select a valid option.\n";
        }
    } while (choice != 'j');
    return 0;
}
