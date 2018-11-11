#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include <numeric>
using namespace std;

int cmpv(vector<int> a, vector<int> b, int i)
{
	if(i > a.size() && i > b.size())
		return 0;
	if(a[i] > b[i])
		return 1;
	if(a[i] < b[i])
		return -1;
	return cmpv(a, b, i+1);
}

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

int order(const void * a, const void * b) 
{	
	return ( *(int *)a > *(int *)b);
}
int norder(const void * a, const void * b) 
{	
	return ( *(int *)a < *(int *)b);
}
int main()
{
	vector<string> operate;
	vector<string> roperate;
	vector<string> addMulParser;
	vector<vector<string>> strings;
	vector<vector<int>> v;
	
	string current;
	strings.push_back(vector<string>());
	
	int iterate = -1;
	size_t n;
	string temp;
	string s;
	int num;
	string mode;
	
	while(1)
	{
		cout << "> ";
		getline(cin, s);
		if(s.back() == ' ')
			s.pop_back();
		if(s == "quit"){
			break;
		}
		{if(isdigit(s.at(0)))
			mode = "in";
		else
			mode = "out";}
		
		if(mode == "in"){
			size_t posend;
			string delimiter = "; ";
			s = s + ";";
			int j = 0;
			n = count(s.begin(), s.end(), ';');
			
			for(int k = 0; k < n; k++)
			{
				strings.push_back(vector<string>());
				
				posend = s.find(delimiter);
				current = s.substr(0, posend) + " ";
				
				strings[k] = parse(current, " ");
				
				
				for(auto i : strings[k])
				{
					v.push_back(vector<int>());
					v[j].push_back(stoi(i));
					//strings[k].pop_back();
					
				}
				j++;
				s.erase(0, posend + delimiter.length());
			}
		}
		if(mode == "out")
		{
			bool assigned = false;
			int last_iteration = 0;
			bool ordered;
			vector<vector<int>> vcopy = v;
			s = s + ".";
			vector<int> iterv;
			operate = parse(s, ".");
			for(auto it = operate.rbegin(); it != operate.rend(); ++it){
				roperate.push_back(*it);}
			while(!roperate.empty())
			{
				if(roperate.back()!="begin"
				&&!((roperate.back().find("add")!=string::npos) || (roperate.back().find("mul")!=string::npos))
				&&!(roperate.back().find("ordered")!=string::npos)
				&&!(roperate.back().find("at")!=string::npos)
				&& roperate.back() != "sizes"
				&& roperate.back() != "averages"
				&& roperate.back() != "sums"
				&& roperate.back() != "show"
				&& roperate.back() != "size"
				&& roperate.back() != "medians"
				&& roperate.back() != "next"
				&& roperate.back() != "average"
				&& roperate.back() != "median"
				&& roperate.back() != "sum"
				){
					cout << "ERROR: Unknown operation" << endl;
				}
				
				if(roperate.back()=="begin")
				{
					iterate = 0;
				}
				
				
				if(iterate == -1){
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
					if((roperate.back().find("ordered")!=string::npos))
					{
						temp = roperate.back();
						roperate.pop_back();
						roperate.push_back(temp+":");
						addMulParser = parse(roperate.back(),":");
						ordered = (addMulParser.back() == "true");
						roperate.pop_back();
						roperate.push_back(addMulParser.front());
					}
					if(roperate.back()=="ordered")
					{
						for(int i = 0; i < n; i++)
						{
							if(ordered)
								qsort(&vcopy[i][0], vcopy[i].size(),sizeof(int), order);
							else
								qsort(&vcopy[i][0], vcopy[i].size(),sizeof(int), norder);
						}
						for(int i = 0; i < n; i++){
							for(int k = 0; k < n-1; k++)
							{
								if(ordered==true)
								{
									if(cmpv(vcopy[k], vcopy[k+1], 0) == 1)
									{
										vector<int> temp = vcopy[k+1];
										vcopy[k+1] = vcopy[k];
										vcopy[k] = temp;
									}
								}
								else
								{
									if(cmpv(vcopy[k], vcopy[k+1], 0) == -1)
									{
										vector<int> temp = vcopy[k+1];
										vcopy[k+1] = vcopy[k];
										vcopy[k] = temp;
									}
								}
							}
						}
					}
					if(roperate.back()=="size"){
						cout << n;
						cout << "\n";
					}
					if(roperate.back()=="averages"||roperate.back()=="medians"){
						for(int i = 0; i < n; i++)
						{
							float sum = accumulate(v[i].begin(), v[i].end(), 0.0f);
							if(i!=0) cout << " ";
							cout << sum / v[i].size(); //(v[i].end()-v[i].begin())
						}
						cout << endl;
					}
					if(roperate.back()=="sums"){
						for(int i = 0; i < n; i++){
							if(i!=0) cout << " ";
							cout<< accumulate(v[i].begin(), v[i].end(), 0);
						}
						cout << "\n";
					}
					if(roperate.back()=="sizes"){
					{
						for(int i = 0; i < n; i++){
							if(i!=0) cout << " ";
							cout<< v[i].size();
						}
						cout << "\n";					
					}
					}
					if(roperate.back()=="show"){
						for(int i = 0; i < n; i++)
						{
							for(int k = 0; k < vcopy[i].size(); k++)
							{
								if(k!=0||i!=0) cout << " ";
								cout<< vcopy[i][k];
								//vcopy[i].pop_back();
							}
							if(i!=n-1)cout << ";";	
						}
						cout << "\n";
					}
					if(roperate.back()=="mul")
						for(int i = 0; i < n; i++)
						{
							for(int k = 0; k < vcopy[i].size(); k++)
							{
								vcopy[i][k] = vcopy[i][k] * num;
							}
						}
					if(roperate.back()=="add")
						for(int i = 0; i < n; i++)
						{
							for(int k = 0; k < vcopy[i].size(); k++)
							{
								vcopy[i][k] = vcopy[i][k] + num;
							}
						}
					roperate.pop_back();
				}
				
				
				
				else
				{	
					if(roperate.back()=="next")
					{
						iterate = iterate+1;
						if(iterate>=n)
						{
							cout << "ERROR: End of iteration" << endl;
							break;
						}
					}
					if((!assigned||last_iteration!=iterate)&&iterate!=-1)
					{
						while(!iterv.empty())
							iterv.pop_back();
						for(int i = 0; i < vcopy[iterate].size();i++){
							iterv.push_back(vcopy[iterate][i]);
					}
					assigned = true;
					}
					
					if((roperate.back().find("at")!=string::npos))
					{
						temp = roperate.back();
						roperate.pop_back();
						roperate.push_back(temp+":");
						addMulParser = parse(roperate.back(),":");
						num = stoi(addMulParser.back());
						roperate.pop_back();
						roperate.push_back(addMulParser.front());
					}
					if((roperate.back().find("ordered")!=string::npos))
					{
						temp = roperate.back();
						roperate.pop_back();
						roperate.push_back(temp+":");
						addMulParser = parse(roperate.back(),":");
						ordered = (addMulParser.back() == "true");
						roperate.pop_back();
						roperate.push_back(addMulParser.front());
					}
					if(roperate.back()=="ordered")
					{
						
						if(ordered)
							qsort(&iterv[0], iterv.size(),sizeof(int), order);
						else
							qsort(&iterv[0], iterv.size(),sizeof(int), norder);	
					}
					if(roperate.back()=="at")
					{
						if(num>=iterv.size()||num<0)
							cout << "ERROR: Index out of bounds";
						else
						{
							cout << iterv[num];
							
						}
						cout << endl;
					}
					if(roperate.back()=="size")
					{
						cout << iterv.size();
						cout << endl;
					}
					if(roperate.back()=="average"||roperate.back()=="median")
					{
						int sum = accumulate(iterv.begin(), iterv.end(), 0);
						cout << sum / iterv.size(); //(v[i].end()-v[i].begin())
						cout << endl;
					}
					if(roperate.back()=="sum")
					{
						int sum = accumulate(iterv.begin(), iterv.end(), 0);
						cout << sum; //(v[i].end()-v[i].begin())
						cout << endl;
					}
					if(roperate.back()=="show"){
						for(int k = 0; k < iterv.size(); k++)
						{
							if(k!=0) cout << " ";
							cout << iterv[k];
							//vcopy[i].pop_back();
						}
						cout << endl;
					}
					roperate.pop_back();
					last_iteration = iterate;
				}
			}
			//cout << endl;
		}
	}	
}//*/