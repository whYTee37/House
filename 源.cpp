#include"Stack.h"
int main()
{
	Stack<char> S(10);
	S.push('A');
	S.push('B');
	S.push('C');
	while (!S.empty())
	{
		char c;
		S.top(c);
		cout << c << endl;
		S.pop();
	}
	return 0;
}