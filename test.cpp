#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<string> parse(string s, string delimiter)
{
	string token;
	size_t pos;
	vector<string> vs;
	while((pos = s.find(delimiter)) != std::string::npos)
	{
		token = s.substr(0, pos);
		vs.push_back(token);
		s.erase(0, pos + delimiter.length());
	}
	return vs;
}

int main()
{
	vector<string> strings;
	vector<string> operate;
	vector<string> roperate;
	vector<string> addMulParser;
	string temp;
	string s;
	int num;
	vector<int> v;
	string mode;
	while(1)
	{
		getline(cin, s);
		if(s == "quit"){
			break;
		}
		{if(isdigit(s.at(0)))
			mode = "in";
		else
			mode = "out";}
		
		if(mode == "in"){			
			s = s + " ";
			strings = parse(s, " ");
			for(auto i : strings)
			{
				v.push_back(stoi(i));
				strings.pop_back();
			}
		}
		if(mode == "out")
		{
			vector<int> vcopy = v;
			s = s + ".";
			operate = parse(s, ".");
			for(auto it = operate.rbegin(); it != operate.rend(); ++it){
				roperate.push_back(*it);}
			while(!roperate.empty()){
				int k = 0;
				if((roperate.back().find("add")!=string::npos) || (roperate.back().find("mul")!=string::npos))	
				{
					temp = roperate.back();
					roperate.pop_back();
					roperate.push_back(temp+":");
					addMulParser = parse(roperate.back(),":");
					num = stoi(addMulParser.back());
					roperate.pop_back();
					roperate.push_back(addMulParser.front());
				}
				if(roperate.back()=="size")
					cout << vcopy.size() << endl;
				if(roperate.back()=="show")
					for(auto i : vcopy){
						cout << i << " ";
						vcopy.pop_back();
					}
				if(roperate.back()=="mul")
					for(auto i : vcopy)
					{
						vcopy[k] = i + num;
						k++;
					}
				if(roperate.back()=="add")
					for(auto i : vcopy)
					{
						vcopy[k] = i + num;
						k++;
					}
				roperate.pop_back();
			}
			cout << endl;
		}
	}
}//*/

























