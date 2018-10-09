#include <stack>
#include <iostream>
#include <string>
#include <sstream>


using namespace std;


int word(string exp)
{
	int words = 0;
	int f = 0;
	for(int i =0;i<exp.length();i++)
	{
		if((exp[i]>='a'&& exp[i] <= 'z')||(exp[i]>='A'&& exp[i] <= 'Z'))
		{
			if(f == 0)
			{
				f++;
				if(f = 1)
				{
					words++;
				}
			}
		}else{
			f = 0;
		}
		
			
	}
	
	return words;
}

int sentence(string exp)
{
	int sentences = 0;
	
	for(int i =0;i<exp.length();i++)
	{
		if(exp[i]=='.')
		{
			sentences++;
		}
	}
	return sentences;
}
int letter(string exp)
{
	int letters = 0;
	for(int i =0;i<exp.length();i++)
	{
		if((exp[i]>='a'&& exp[i] <= 'z')||(exp[i]>='A'&& exp[i] <= 'Z'))
		{
			letters++;
		}
	}
	return letters;
}
	
int sen(string exp)
{
	
	for(int i =0;i<exp.length();i++)
		if(exp[i]=='.')
			break;
		int words = 0;
		int f = 0;
		for(int i =0;i<exp.length();i++)
		{
			if((exp[i]>='a'&& exp[i] <= 'z')||(exp[i]>='A'&& exp[i] <= 'Z'))
			{
				if(f == 0)
				{
					f++;
					if(f = 1)
					{
						words++;
					}
				}
			}else{
				f = 0;
			}	
		}
	}
	if(words>)
	{
		
	}
}
int main()
{
	
	
	string s;
	int words = 0;
	int sentences = 0;
	int letters = 0;
	while(cin)
	{
		getline(cin, s);
		words = words + word(s);
		sentences = sentences + sentence(s);
		letters = letters + letter(s);
		if(s =="END")
		{
			break;
		}

	}	
	words--;
	letters = letters-3;
	cout << words/sentences << ' '<< letters/words << endl;
	
	return 0;
}




