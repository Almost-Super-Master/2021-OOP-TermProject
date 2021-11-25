#include "헤더.h"

int inputLength = 0;
int countArr = 0;
string inputArr[ArrSize];
int result = 0;

struct operstack
{
    int p;
    string s;
};
stack<int> intstack;
stack<operstack> op;

int swap2To10(string s)
{
    string str = s;
    string sbinary;
    int binary = 0;
    int result = 0;

    if (str[1] == 'b') {
        sbinary = str.substr(2, -2);
        binary = stoi(sbinary);
    }

    for (int j = 0; binary >= 1; ++j) {
        result += (binary % 10) * pow(2, j);
        binary /= 10;
    }

    return result;
}

int swap16To10(string s)
{
    string str = s;
    string shexa;
    int a = shexa.length();
    char* arr = (char*)malloc(sizeof(char) * shexa.length());


    int result = 0;

    if (str[1] == 'x') {
        shexa = str.substr(2, -2);
    }

    strcpy(arr, shexa.c_str());

    result = strtol(arr, NULL, 16);

    return result;

}

void splitInputArr(string s) {
    string getString = s;
    string splitString;
    string operationString;
    int setint = 1;
    int count = 0;
    int continuenum = 0;

    int temp = 0;
    int snum = 0;

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
                splitString = to_string(swap16To10(splitString));
                setint = 1;
            }
            else if (splitString == "0b") {
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
                splitString = to_string(swap2To10(splitString));
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
            while (true)
            {
                if (splitString == "" || splitString == "+" || splitString == "-" || splitString == "*" || splitString == "/" || splitString == "(" || splitString == ")")
                {
                    break;
                }
                operationString = getString.substr(i + temp + 1, setint);
                if (operationString == "1" || operationString == "2" || operationString == "3" || operationString == "4" || operationString == "5" ||
                    operationString == "6" || operationString == "7" || operationString == "8" || operationString == "9" || operationString == "0")
                {
                    temp++;
                }
                else if (temp == 0 && (operationString == "" || operationString == "+" || operationString == "-" || operationString == "*" || operationString == "/"))
                {
                    break;
                }
                else
                {
                    splitString = getString.substr(i, setint + temp);
                    temp = 0;
                    count++;
                    break;
                }
            }
        }
        inputArr[i - continuenum] = splitString;  
        inputLength++;
    }
}

void catchException (int a) {
    try {
        if (a != 1) {
            throw(a);
        }
    }
    catch (int ab) {
        cout << "올바르지 않은 입력값입니다.";
    }
}

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

    if (atcheck < 0 && 9 < atcheck) {
        catchException(2);
        cout << "\n가";
    }


    for (int i = 0; i < Arrlength; ++i)
    {
        atfir = atoi(s[i].c_str());
        atSec = atoi(s[i + 1].c_str());
        if ((s[i] == "(") && (atfir != (atSec < 0 || 99999999 < atSec))) {
            catchException(2);
            cout << "\n나";
        }
    }

    for (int i = 0; i < Arrlength; ++i)
    {
        if ((s[i] == "+" || s[i] == "-" || s[i] == "*" || s[i] == "/") && (s[i + 1] == "+" || s[i + 1] == "-" || s[i + 1] == "*" || s[i + 1] == "/")) {
            catchException(2);
            cout << "\n다";
        }
    }

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
        catchException(2);
        cout << "\n라";
    }

    for (int i = 0; i < Arrlength; ++i) {
        atfir = atoi(s[i].c_str());
        atSec = atoi(s[i + 1].c_str());
        if (s[i] == "(" || s[i] == ")") {
            continue;
        }
        else if (s[i] == "+" || s[i] == "-" || s[i] == "*" || s[i] == "/" || s[i] == "b" || s[i] == "x") {
            continue;
        }
        else if (atfir >= 0 && 99999999 >= atSec) {
            continue;
        }
        else {
            catchException(2);
            cout << "\n마";
            
        }
    }
}

bool Checkbracket()
{
    bool check = false;
    for (int i = 0; i < inputLength; ++i)
    {
        if (inputArr[i] == "(" || inputArr[i] == ")")
            check = true;
    }
    return check;
}

class OperationClass
{
public:
    virtual void operation(int a, int b) = 0;
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

class Add : public OperationClass
{
public:
    virtual void operation(int a, int b)
    {
        result = a + b;
        intstack.push(result);
        result = 0;
    }
};
class Sub : public OperationClass
{
public:
    virtual void operation(int a, int b)
    {
        result = a - b;
        intstack.push(result);
        result = 0;
    }
};
class Mul : public OperationClass
{
public:
    virtual void operation(int a, int b)
    {
        result = a * b;
        intstack.push(result);
        result = 0;
    }
};
class Div : public OperationClass
{
public:
    virtual void operation(int a, int b)
    {
        result = a / b;
        intstack.push(result);
        result = 0;
    }
};

class StrategySetOper
{
private:
    OperationClass* oper;
public:
    void pointOper(OperationClass* oper) {
        this->oper = oper;
    }
    void setOper(int a, int b) {
        oper->operation(a, b);
    }
};

void calc() {
    StrategySetOper* ssoper = new StrategySetOper();

    int first, second = 0;
    second = intstack.top();
    intstack.pop();
    first = intstack.top();
    intstack.pop();
    string operstack = op.top().s;
    op.pop();

    if (operstack == "*")
    {
        OperationClass* operMul = new Mul();
        ssoper->pointOper(operMul);
        ssoper->setOper(first, second);
    }
    else if (operstack == "/")
    {
        OperationClass* operDiv = new Div();
        ssoper->pointOper(operDiv);
        ssoper->setOper(first, second);
    }
    else if (operstack == "+")
    {
        OperationClass* operAdd = new Add();
        ssoper->pointOper(operAdd);
        ssoper->setOper(first, second);
    }
    else if (operstack == "-")
    {
        OperationClass* operSub = new Sub();
        ssoper->pointOper(operSub);
        ssoper->setOper(first, second);
    }
}

int main()
{
    string input;
    string otherinput;

    bool notMulandDiv = false;

    while (true)
    {
        cout << "수식을 입력하세요 : ";
        cin >> input;
        splitInputArr(input);
        exceptionString(inputLength);
        break;
    }

    for (int i = 0; i < inputLength; ++i)
    {
        otherinput += inputArr[i];
    }

    for (int i = 0; i < inputLength; ++i) {
        if (inputArr[i] == "(")
        {
            op.push({ 0, inputArr[i] });
        }
        else if (inputArr[i] == ")")
        {
            while (op.top().s != "(")
            {
                calc();
            }
            op.pop();
        }
        else if (inputArr[i] == "*" || inputArr[i] == "/" || inputArr[i] == "+" || inputArr[i] == "-") {
            int operint;
            if (inputArr[i] == "*")
                operint = 2;
            else if (inputArr[i] == "/")
                operint = 2;
            else if (inputArr[i] == "+")
                operint = 1;
            else  if (inputArr[i] == "-")
                operint = 1;

            while (!op.empty() && operint <= op.top().p)
            {
                calc();
            }
            op.push({ operint, inputArr[i] });
        }
        else
        {
            intstack.push(stoi(inputArr[i]));
        }
    }

    while (!op.empty())
    {
        calc();
    }
    cout << intstack.top();
    return 0;
}