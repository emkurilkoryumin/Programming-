#include <iostream>  
#include <cmath>     

using namespace std;

void sum(double a, double b);
void sub(double a, double b);
void mul(double a, double b);
void div(double a, double b);
void deg(double a, double b);
void fact(double a);


int choice;
int i;
int f = 1;
double a, b;
char s;
double result;

int main() {

    setlocale(LC_ALL, "Russian");

    ; cout << "Выбор режима:" << "1 - Факториалы" << "\n" << "2 - Обычные операции" << "\n";
    cin >> choice;

    switch (choice) {

    case 1:
        cout << "Введите число:" << "\n";
        cin >> a;
        fact(a);
        break;


    case 2:
        cout << "Введите пример:" << "\n";
        while (true) {
            cin >> a >> s >> b;
            switch (s) {
            case '+':
                sum(a, b);
                break;

            case '*':
                mul(a, b);
                break;

            case '-':
                sub(a, b);
                break;

            case '/':
                div(a, b);
                break;

            case '^':
                deg(a, b);
                break;

            default:
                return 0;
            }
        }
    default:
        return 0;
    }
}

void sum(double a, double b) {
    result = a + b;
    cout << "Result:" << result << "\n";
}

void sub(double a, double b) {
    result = a - b;
    cout << "Result:" << a - b << "\n";
}

void mul(double a, double b) {
    result = a * b;
    cout << "Result:" << result << "\n";
}

void div(double a, double b) {
    result = a / b;
    cout << "Result:" << result << "\n";
}

void deg(double a, double b) {
    result = pow(a, b);
    cout << "Result:" << result << "\n";
}

void fact(double a) {
    for (i = 1; i <= a; i++) {
        f = f * i;
    };
    cout << a << "!=" << f << "\n";
}
