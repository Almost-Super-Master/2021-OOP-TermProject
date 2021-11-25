#include "헤더.h"

int inputLength = 0;
string inputArr[ArrSize];

void splitInputArr(string s) {
    // 문자를 하나하나 잘라준다
    string getString = s;
    string splitString;
    string operationString;
    int setint = 1;
    int count = 0;
    int continuenum = 0;
    for (int i = 0; i < getString.length(); ++i)
    {
        if (i < count)
        {
            continuenum++;
            continue;
        }
        splitString = getString.substr(i, setint);
        if (splitString == "0")
        {
            setint++;
            splitString = getString.substr(i, setint);
            if (splitString == "0x") {
                // 얘는 16 진수 
                setint = 1;
                while (true)
                {
                    operationString = getString.substr(i + setint, 1);
                    if (operationString == "+" || operationString == "-" || operationString == "*" || operationString == "/" || operationString == "")
                    {
                        break;
                    }
                    else
                    {
                        setint++;
                    }
                }
                splitString = getString.substr(i, setint);
                count += splitString.length();
                setint = 1;
            }
            else if (splitString == "0b") {
                // 얘는 2 진수
                setint = 1;
                while (true)
                {
                    operationString = getString.substr(i + setint, 1);
                    if (operationString == "+" || operationString == "-" || operationString == "*" || operationString == "/" || operationString == "")
                    {
                        break;
                    }
                    else
                    {
                        setint++;
                    }
                }
                splitString = getString.substr(i, setint);
                count += splitString.length();
                setint = 1;
            }
            else
            {
                setint = 1;
            }
        }
        else
        {
            count++;

        }
        inputArr[i - continuenum] = splitString;
        // 한번 자를 때마다 카운터가 올라가며 Length를 ++해준다.   
        inputLength++;
    }
}

void swap2To10(string s)
{
    string str = s;
    string sbinary;
    int binary = 0;
    int result = 0;

    if (str[1] == 'b') {
        sbinary = str.substr(2, inputLength - 2);
        binary = stoi(sbinary);
    }
   
    for (int j = 0; binary >= 1; ++j) {
        result += (binary % 10) * pow(2, j);
        binary /= 10;
    }

    cout << result;
    //    임의의 배열 수정 ( 2진수 10진수 16진수)
}

//void swap16To10(string s)
//{
//    string str = s;
//    string shexa;
//    char hexa[];
//    int result = 0;
//
//    if (str[1] == 'x') {
//        shexa = str.substr(2, inputLength - 2);       
//    }
//    for (int i = 0; i < shexa.length; ++i) {
//        
//    }
//
//    result = strtol(shexa, NULL, 16);
//
//    cout << result;
//    //    임의의 배열 수정 ( 2진수 10진수 16진수)
//}

void exceptionString(int localLength) {
    int Arrlength = localLength;
    int atfir = 0;
    int atSec = 0;
    int atcheck = 0;
    string s[ArrSize];

    for (int i = 0; i < inputLength; ++i)
    {
        s[i] = inputArr[i];
    }
    atcheck = atoi(s[0].c_str());
    // 5-2-1
    if (atcheck < '0' && '9' < atcheck) {
        cout << "올바르지 않은 입력입니다.5-2-1";
    }

    // 5-2-2
    for (int i = 0; i < Arrlength; ++i)
    {
        atfir = atoi(s[i].c_str());
        atSec = atoi(s[i + 1].c_str());
        if ((s[i] == "(") && (atfir != (atSec < '0' || '9' < atSec))) {
            cout << "올바르지 않은 입력입니다.5-2-2";
            break;
        }


    }
    //5-3
    for (int i = 0; i < Arrlength; ++i)
    {
        if ((s[i] == "+" || s[i] == "-" || s[i] == "*" || s[i] == "/") && (s[i + 1] == "+" || s[i + 1] == "-" || s[i + 1] == "*" || s[i + 1] == "/")) {
            cout << "올바르지 않은 입력입니다.5-3";
            break;
        }
    }
    //5-1
    int count = 0;
    for (int i = 0; i < Arrlength; ++i)
    {
        if (s[i] == "(") {
            count++;
        }
        if (s[i] == ")") {
            count--;
        }
    }
    if (count != 0) {
        cout << "올바르지 않은 입력입니다.5-1";
    }
    //5-5
    for (int i = 0; i < Arrlength; ++i) {
        atfir = atoi(s[i].c_str());
        atSec = atoi(s[i + 1].c_str());
        if (s[i] == "(" || s[i] == ")") {
            continue;
        }
        else if (s[i] == "+" || s[i] == "-" || s[i] == "*" || s[i] == "/" || s[i] == "b" || s[i] == "x") {
            continue;
        }
        // atfir와 atSec가 인트형이라 ''삭제 & 올바른 값이 입력되어야 continue되므로 부등호 방향 수정 ( < 를 >= 로)
        else if (atfir >= 0 && 9 >= atSec) {
            continue;
        }
        else {
            cout << "올바르지 않은 입력입니다.5-5";
            break;
        }
    }
}

class OperationClass
{
public:
    OperationClass();
    ~OperationClass();

private:

};

OperationClass::OperationClass()
{
}

OperationClass::~OperationClass()
{
}

class Add : OperationClass {};
class Sub : OperationClass {};
class Mul : OperationClass {};
class Div : OperationClass {};

int main()
{
    string input;
    string test;

    while (true)
    {
        cout << "수식을 입력하세요 : ";
        cin >> input;
        splitInputArr(input);
        exceptionString(inputLength);
      //swap2To10(input);
        break;
    }
    //printInputArr();
}
