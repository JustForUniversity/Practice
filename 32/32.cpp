#include <iostream>
#include <stack>
#include <string>

// 1 + 2 - 5
// 3 + 4 * 2 / ( 1 - 5 ) ^ 2
// -3 - 2 + 4 - 1
// 2 ^ 2 ^ 2
// 2 * 2 * 2
// 2 / 2 / 2


using namespace std;

bool is_num(char c) {
	if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' ||
		c == '5' || c == '6' || c == '7' || c == '8' || c == '9') {
		return 1;
	}
	else return 0;
}

int prioritizer(char sign) {
	if (sign == '^') return 3;
	if (sign == '/' || sign == '*') return 2;
	if (sign == '+' || sign == '-') return 1;
	if (sign == '(' || sign == ')') return 0;
	return 666;
}

string convert(string str) {
	char c = ' '; int i = 0;
	string answ; stack <char> sign;
	while (i < str.size()) {
		c = str[i];
		i++;
		if (c == ' ') {
			if (answ[answ.size() - 1] != ' ') {
				answ.push_back(c);
			}
			continue;
		}
		if (c == '-' && (i - 1) < (str.size()) - 1 && is_num(str[i])) {
			answ.push_back(c);
			continue;
		}
		if (is_num(c) || c == '.') {
			answ.push_back(c);
			continue;
		}
		if (c == '(') {
			sign.push(c);
			continue;
		}
		if (c == ')') {
			while (sign.top() != '(') {
				answ.push_back(sign.top());
				sign.pop();
			}
			sign.pop();
			continue;
		}
		if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
			while (true) {
				if (!sign.empty()) {
					if (prioritizer(sign.top()) > prioritizer(c)) {
						if (str[i - 1] != ' ') answ.push_back(' ');
						answ.push_back(sign.top());
						sign.pop();
						continue;
					}
					if (c == '^' && sign.top() == '^') {
						//sign.push(c);
						break;
					}
					if (prioritizer(sign.top()) == prioritizer(c)/* and (sign.top() == '/' || sign.top() == '-')*/) {
						if (str[i - 1] != ' ') answ.push_back(' ');
						answ.push_back(sign.top());
						sign.pop();
						continue;
					}

				}
				break;
			}
			sign.push(c);
			continue;
		}
	}
	while (!sign.empty()) {
		if (answ[answ.size() - 1] != ' ') {
			answ.push_back(' ');
		}
		answ.push_back(sign.top());
		sign.pop();
	}
	if (answ[answ.size() - 1] != ' ') {
		answ.push_back(' ');
	}
	return answ;
}

double process(string str) {

	string num = "";
	stack<double> temp;
	int i = 0; double a;

	while (i < str.size()) {

		if (is_num(str[i]) || str[i] == '.') {
			num += str[i];
		}
		if (str[i] == '-' && is_num(str[i + 1])) {
			num += str[i];
			i++;
			continue;
		}
		if (str[i] == ' ' && is_num(str[i - 1])) {
			temp.push(stod(num));
			num = "";
		}
		switch (str[i]) {
		case '+':
			a = temp.top(); temp.pop();
			a = temp.top() + a;
			temp.pop();
			temp.push(a);
			break;
		case '-':
			a = temp.top(); temp.pop();
			a = temp.top() - a;
			temp.pop();
			temp.push(a);
			break;
		case '*':
			a = temp.top(); temp.pop();
			a = temp.top() * a;
			temp.pop();
			temp.push(a);
			break;
		case '/':
			a = temp.top(); temp.pop();
			a = temp.top() / a;
			temp.pop();
			temp.push(a);
			break;
		case '^':
			a = temp.top(); temp.pop();
			a = pow(temp.top(), a);
			temp.pop();
			temp.push(a);
			break;
		}
		i++;
	}

	return temp.top();
}


int main()
{

	string str;
	stack <char> num;

	getline(cin, str);

	cout << convert(str) << endl;

	cout << process(convert(str)) << endl;

	system("pause");
	return 1;
}
