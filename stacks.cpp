#include <iostream>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

enum TokenType {
    OPERATOR,
    OPERAND,
};

set<string> VALID_OPS{"+", "-", "*", "/"};

TokenType tokenType(string s) {
    if ((VALID_OPS.count(s.substr(0, 1)) != 0)) {
        return OPERATOR;
    } else {
        return OPERAND;
    }
}

double apply(string op, double v1, double v2) {
    if (op == "+")
        return (v1 + v2);
    if (op == "-")
        return (v1 - v2);
    if (op == "*")
        return (v1 * v2);
    if (op == "/")
        return (v1 / v2);
    return 0.0; // Just to avoid no-return warning
}

vector<string> tokenize(string expression) {
    vector<string> result;
    int tokenStart = 0;
    int i = 0;
    while (i < expression.size()) {
        if (expression.substr(i, 1) == " ") {
            result.push_back(expression.substr(tokenStart, i - tokenStart));
            tokenStart = i + 1;
        }
        i++;
    }
    return result;
}

double eval(string expression) {

    vector<string> tokens = tokenize(expression);

    stack<double> s;

    for (string token : tokens) {

        switch (tokenType(token))
        {
        case OPERAND:
            s.push(stod(token));
            break;
        case OPERATOR:
            double op2 = s.top();
            s.pop();
            double op1 = s.top();
            s.pop();
            double temp = apply(token, op1, op2);
            s.push(temp);
            break;
        }
    }
    double result = s.top();
    return result;

}

int main() {

    string expression = "5.0 3.0 + 2.0 * 2.0 * 7 - ";
    vector<string> tokens = tokenize(expression);

    cout << "5.0 3.0 + 2.0 * 2.0 * 7 -   ->" << eval(expression) << endl;
}