#include <stack>
#include <iostream>
#include <string>
#include <sstream>


using namespace std;

/*/class Exception {
	string message_;
	
public:
	
	Exception(string message) {
		message_ = message;
	}
	
	string get_message() {
		return message_;
	}
};/*/

bool ArePair(char opening,char closing)
{
	if(opening == '(' && closing == ')') return true;
	return false;
}
bool AreParanthesesBalanced(string exp)
{
	stack<char>  S;
	for(int i =0;i<exp.length();i++)
	{
		if(exp[i] == '(')
			S.push(exp[i]);
		else if(exp[i] == ')')
		{
			if(S.empty() || !ArePair(S.top(),exp[i]))
				return false;
			else
				S.pop();
		}
		
		
		
	}
	return S.empty() ? true:false;
}
int sen(string exp,int x)
{
	int words = 0;
	for(int i =0;i<exp.length();i++)
	{
		if(exp[i]=='.')
			break;
		if((exp[i]==' ')&&((exp[i+1]>='a'&& exp[i+1] <= 'z')||(exp[i+1]>='A'&& exp[i+1] <= 'Z')))
		{
			words++;
		}
	}
	if(words>x)
	{
		return 0;
	}
	return 1;
}

int rio(string exp)
{
	int asdf;
	for(int i =0;i<exp.length();i++)
	{
		if(exp[i]==':')
			{
				asdf = exp[i+1]-48;
				return asdf;
			}
	}
}
int main() {
	
	int i=1;
	string s;
	int count = 0;
	int z = 0;
	int asdf=0;
	int x;
	while(cin)
	{
		getline(cin, s);

		if (s.find("sent") != string::npos) {
			x=rio(s);
			count--;
		}
		if(s == "strict")
		{
			asdf=1;
			count--;
		}
		if(asdf==1);
			{
				
				if(!AreParanthesesBalanced(s))
				{	
					i = 0;
				}
			}
		if(x!=0){
			count += sen(s, x);
		}	
		if(s =="END")
		{
			if(asdf == 1)
				cout << i << endl;
			count--;
			break;
		}

	}
	
	cout << "PU6KI" << count << endl;
	
	
	return 0;
}




