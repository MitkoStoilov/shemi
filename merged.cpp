#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<numeric>


using namespace std;

class ListOfArrays {
	class ArrayNode {
	public:
	int* data_;
	int size_;
	ArrayNode* prev_;
	ArrayNode* next_;

	ArrayNode(int* data, int size)
		:data_(data), size_(size), next_(0), prev_(0) 
		{
		}

	ArrayNode():
		data_(new int(100)),
		size_(0),
		next_(0),
		prev_(0) {}
		
	~ArrayNode() {
		delete [] data_;
	}
	
	ArrayNode& operator=(const ArrayNode& other)
	{
		//delete [] data_;
		data_ = new int(100);
		size_ = other.size_;
		prev_ = other.prev_;
		next_ = other.next_;
		for(int i = 0; i < other.size_; i++)
		{
			*(data_+i) = *(other.data_+i);
		}
		return *this;
	}
	
	ArrayNode& assign(int arr[], int size)
	{
		for(int i = 0; i < size; i++)
			*(data_+i) = arr[i];
		return *this;
	}
	
	int operator[](int arg)
	{
		return *(data_+arg);
	}
	
	int size()
	{
		return size_;
	}
	
	ArrayNode& push_back(int var)
	{
		*(data_+size_) = var;
		size_++;
		return *this;
	}
	
	int pop_back()
	{
		size_--;
		int temp = *(data_ + size_);
		delete (data_+size_);
		return temp;
	}
	
	int sum()
	{
		return accumulate(data_, data_+size_, 0);
	}
	
	ArrayNode& add(int arg)
	{
		for(int i = 0; i < size_; i++)
			*(data_+i) += arg;
		return *this;
	}
	
	ArrayNode& mul(int arg)
	{
		for(int i = 0; i < size_; i++)
			*(data_+i) *= arg;
		return *this;
	}
	
	friend ostream& operator<<(ostream& os, const ListOfArrays::ArrayNode& node);
	
	void show()
	{
		for(int i = 0; i < size_; i++)
		{
			cout << *(data_+i);
			if(i + 1!=size_)
				cout << " ";
		}
	}
	
	void at(int arg)
	{
		if(arg < size_ && arg >= 0)
			cout << *(data_+arg);
		else 
			cout << "ERROR: Index out of bounds";
	}
	
	float average(){
		float avg = accumulate(data_, data_+size_, 0);
		avg = avg / size_;
		//cout << this[0] << endl;
		//cout << avg << endl;
		return avg;
	}
	
	
	float median(){
		return average();
	}
	
	ArrayNode& ordered(bool arg){
		if(arg){
			qsort(data_, size_,sizeof(int), order);
		}
		else{
			qsort(data_, size_,sizeof(int), norder);
		}
		return *this;
	}
	static int order(const void* a, const void * b) {	
		return ( *(int *)a > *(int *)b);
	}
	static int norder(const void * a, const void * b) {	
		return ( *(int *)a < *(int *)b);
	}
	
};
private:
	ArrayNode* head_;
	int size_;
private:
	ArrayNode* at(int i, ArrayNode* current)
	{
		if(i == 0)
			return current->next_;
		return at(i-1,current->next_);
	}
	void pop_back()
	{
		ArrayNode& ref = *at(size_-1, head_);
		ref.prev_->next_ = head_;
	}
	
public:

	class Iterator {

		friend class ListOfArrays;

		ListOfArrays& list_;
		ArrayNode* current_;

		public:

		Iterator(ListOfArrays& list, ArrayNode* current)
			: list_(list), current_(current) {}

		bool operator==(const Iterator& other)
		{
			return current_ == other.current_;
		}
		
		Iterator& operator=(const Iterator& other)
		{
			list_ = other.list_;
			current_ = other.current_;
			return *this;
		}
		
		bool operator!=(const Iterator& other)
		{
			return current_ != other.current_;
		}

		Iterator& operator++()
		{
			current_ = current_->next_;
			return *this;
		}

		Iterator operator++(int)
		{
			current_ = current_->next_;
			return *this;
		}

		int& operator[](const int& index)
		{
			int& ref = *(current_->data_ + index);
			return ref;
		}

		int size()
		{
			return current_->size_;
		}
		void show()
		{
			current_->show();
		}
		
		double average()
		{
			return current_->average();
		}
		
		double median()
		{
			return current_->median();
		}
		
		int sum()
		{
			return current_->sum();
		}
		
		Iterator& ordered(bool ascending)
		{
			current_ = &current_->ordered(ascending);
			return *this;
		}
	};

	ListOfArrays()
			: size_(0), head_(new ArrayNode(0, 0)) {
		head_->next_ = head_;
		head_->prev_ = head_;
	}

	~ListOfArrays()
	{
		delete head_;
		size_ = 0;
	}

	ListOfArrays(const ListOfArrays& other):
		head_(new ArrayNode(other.head_->data_, other.head_->size_))
	{
		head_->next_ = head_;
		head_->prev_ = head_;
		ArrayNode* node = other.head_->next_;
		while (node != other.head_)
		{
			push(node->data_, 0 ,node->size_);
			node = node->next_;
		}
		push(node->data_, 0 , node->size_);
	}

	ListOfArrays& operator=(const ListOfArrays& other)
	{	
		ArrayNode* node = other.head_ -> next_;
		for(int i = 0; i < size_; i++)
		{
			head_ = head_->next_;
			delete head_->prev_;
		}
		size_ = 0;
		while (node != other.head_) 
		{
			push(node -> data_, 0, node->size_);
			node = node -> next_;
		}
		push(node->data_, 0 , node->size_);
		return *this;
	}

	int size()
	{
		return size_-1;
	}

	void push(int array[], int position, int length)
	{
			ArrayNode* element = new ArrayNode(array, length);
			ArrayNode* last_element = head_->prev_;
			
			last_element->next_ = element;
			element->prev_ = last_element;
			element->next_ = head_;
			head_->prev_ = element;
			size_++;
	}
	
	void averages(double averages[])
	{
		Iterator it = begin();
		double array[100];
		for(int i = 0; i < size(); i++)
		{
			array[i] = it.current_->average();
			it++;
		}
		for(int i = 0; i < size(); i++)
		{
			cout << array[i];
			if(i+1!=size_) cout << " ";
		}
	}

	void medians(double medians[]){
		Iterator it = begin();
		double array[100];
		for(int i = 0; i < size(); i++)
		{
			array[i] = it.current_->median();
			it++;
		}
		for(int i = 0; i < size(); i++)
			cout << array[i] << " ";
	}
	
	void sizes(int sizes[]){
		Iterator it = begin();
		int array[100];
		for(int i = 0; i < size(); i++)
		{
			array[i] = it.current_->size_;
			it++;
		}
		for(int i = 0; i < size(); i++)
			cout << array[i] << " ";
	}
	
	void sums(int sums[])
	{
		Iterator it = begin();
		int array[100];
		for(int i = 0; i < size(); i++)
		{
			array[i] = it.current_->sum();
			it++;
		}
		for(int i = 0; i < size_; i++)
			cout << array[i] << " ";
	}

	Iterator begin()
	{
		Iterator it(*this, head_);
		it++;
		return it;
	}

	Iterator end()
	{
		Iterator it(*this, head_->prev_);
		return it;
	}	
	
	ListOfArrays& ordered(bool ascending)
	{
		Iterator it = begin();
		for(int i = 0; i < size_; i++)
		{
			it.current_->ordered(ascending);
			it++;
		}
		ListOfArrays sorted;
		int maxpos = 0;
		int minpos = 0;
		if(ascending){
		for(int i = 0; i < size_; i++)
		{
			if(cmpv(*at(minpos, head_), *at(i, head_), 0)==-1||cmpv(*at(minpos, head_), *at(i, head_), 0)==0)
				minpos = i;
		}		
		}
		if(!ascending){
		for(int i = 0; i < size_; i++)
		{
			if(cmpv(*at(minpos, head_), *at(i, head_), 0)==1||cmpv(*at(minpos, head_), *at(i, head_), 0)==0)
				minpos = i;
		}		
		}
		maxpos = minpos;
		vector<int> used;
		bool changed = true;
		//goto a;
		used.push_back(-1);
		if(ascending)
		{
			for(int j = 0; j < size_; j++)
			{
				for(int i = 0; i < size_; i++)
				{
					bool asdf = find(used.begin(), used.end(), i) != used.end();
					if((cmpv(*at(maxpos, head_), *at(i, head_), 0)==1 || cmpv(*at(maxpos, head_), *at(i, head_), 0)==0) && !asdf)
					{
						maxpos = i;
						changed = true;
					}
				}
				if(changed)
				{
					used.push_back(maxpos);
					sorted.push(at(maxpos, head_)->data_, 0, at(maxpos, head_)->size_);
				}
				changed = false;
				maxpos = minpos;
			}		
		}
		if(!ascending)
		{
			for(int j = 0; j < size_; j++)
			{
				for(int i = 0; i < size_; i++)
				{
					bool asdf = find(used.begin(), used.end(), i) != used.end();
					if((cmpv(*at(maxpos, head_), *at(i, head_), 0)==-1 || cmpv(*at(maxpos, head_), *at(i, head_), 0)==0) && !asdf)
					{
						maxpos = i;
						changed = true;
					}
				}
				if(changed)
				{
					used.push_back(maxpos);
					sorted.push(at(maxpos, head_)->data_, 0, at(maxpos, head_)->size_);
				}
				changed = false;
				maxpos = minpos;
			}	
		}
		*this = sorted;
		return *this;
	}

	ListOfArrays& operator*=(const int& coef)
	{
		Iterator it = begin();
		for(int i = 0; i < size_; i++)
		{
			it.current_->mul(coef);
			it++;
		}
		return *this;
	}

	ListOfArrays& operator+=(const int& value)
	{
		Iterator it = begin();
		for(int i = 0; i < size_; i++)
		{
			it.current_->add(value);
			it++;
		}
		return *this;
	}

	void show()
	{
		int i = 0;
		Iterator it = begin();
		for(int i = 0; i < size_; i++)
		{
			it.current_->show();
			if(i+2!=size_&&i+1!=size_)
				cout << "; ";
			it++;
		}
		cout << endl;
	}
private:
	friend int cmpv(ArrayNode a, ArrayNode b, int i);
};

/*ostream& operator<<(ostream& os, const ListOfArrays::ArrayNode& node){
	for(int i = 0; i < node.size_; i++)
	{
		os << *(node.data_+i) << " ";
	}
	return os;
}*/

vector<string> parse(string s, string delimiter){
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
int cmpv(ListOfArrays::ArrayNode a, ListOfArrays::ArrayNode b, int i){
	if(i > a.size() && i > b.size())
		return 0;
	if(a[i] > b[i])
		return 1;
	if(a[i] < b[i])
		return -1;
	return cmpv(a, b, i+1);
}
int main()
{
	vector<string> operate;
	vector<string> roperate;
	vector<string> addMulParser;
	vector<vector<string>> strings;
	vector<vector<int>> v;
	vector<vector<int>> vcopy;
	double *faked;
	int *fake;
	ListOfArrays listm;
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
		if(mode == "in")
		{
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
				
				int p = 0;
				for(auto i : strings[k])
				{
					v.push_back(vector<int>());
					vcopy.push_back(vector<int>());
					v[j].push_back(stoi(i));
					p++;
					//strings[k].pop_back();
					
				}
				vcopy = v;
				listm.push(&vcopy[j][0], 0, vcopy[j].size());
				j++;
				s.erase(0, posend + delimiter.length());
			}
		}
		if(mode == "out")
		{
			bool assigned = false;
			int last_iteration = 0;
			bool ordered;
			ListOfArrays list;
			list = listm;
			vcopy = v;
			s = s + ".";
			vector<int> iterv;
			operate = parse(s, ".");
			for(auto it = operate.rbegin(); it != operate.rend(); ++it){
				roperate.push_back(*it);}
			ListOfArrays::Iterator it = list.begin();
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
				)
				{
					cout << "ERROR: Unknown operation" << endl;
				}
				if(roperate.back()=="begin")
				{
					iterate = 0;
				}
				if(iterate == -1)
				{
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
							list.ordered(ordered);
						}
					if(roperate.back()=="size"){
							cout << list.size() << endl;
						}
					if(roperate.back()=="averages"||roperate.back()=="medians"){
							list.averages(faked);
							cout << endl;
						}
					if(roperate.back()=="sums"){
							list.sums(fake);
							cout << endl;
						}
					if(roperate.back()=="sizes")
						{
							list.sizes(fake);
							cout << endl;					
						}
					if(roperate.back()=="show")
						{
							list.show();
							//cout << endl;					
						}
					if(roperate.back()=="mul")
						list*=num;
					if(roperate.back()=="add")
						list+=num;
					roperate.pop_back();
				}
				else
				{
					if(roperate.back()=="next")
					{
						it++;
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
					if(roperate.back()=="at")
					{
						cout << it[num];
						cout << endl;
					}
					if(roperate.back()=="ordered")
					{
						it.ordered(ordered);
					}
					if(roperate.back()=="size")
					{
						cout << it.size();
						cout << endl;
					}
					if(roperate.back()=="average"||roperate.back()=="median")
					{
						cout << it.average();
						cout << endl;
					}
					if(roperate.back()=="sum")
					{
						cout << it.sum();
						cout << endl;
					}
					if(roperate.back()=="show"){
						it.show();
						cout << endl;
					}
					roperate.pop_back();
					last_iteration = iterate;
				}
			}
		}
	}
	/*while(1){
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
	}*/
}