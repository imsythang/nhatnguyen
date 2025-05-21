#include <iostream>
#include <string>
using namespace std;

int main()
{
    string S;
    int spacesCount = 0;
    int digitsCount = 0;
    int uppercaseCount = 0;

    cout << "Nhập vào chuỗi S: ";
    getline(cin, S);

    for (int i = 0; i < S.length(); i++)
    {
        if (S[i] == ' ') {
            spacesCount++;
        }
        else if (S[i] >= '0' && S[i] <= '9') {
            digitsCount++;
        }
        else if (S[i] >= 'A' && S[i] <= 'Z') {
            uppercaseCount++;
        }
    }

    cout << "Số kí tự khoảng trắng là: " << spacesCount << endl;
    cout << "Số kí tự số là: " << digitsCount << endl;
    cout << "Số kí tự chữ cái in hoa là: " << uppercaseCount << endl;
    return 0;
}
