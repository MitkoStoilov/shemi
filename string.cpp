#include <iostream>

using namespace std;

class String{
	int size_;
	char * buffer_;

public:
	
	String():
		size_(0),
		buffer_(new char)
		{}
	~String()
	{
		while(!empty())
		{
			snibbety_snab();	
		}
	}
	int size()
	{
		return size_;
	}
	bool empty() const
	{
		return !size_;
	}
	void snibbety_snab()
	{
		cout << *(buffer_+size_-1);
		delete (buffer_ + size_-1);
		size_ = size_ - 1;
	}
	void operator+=(const String& other)
	{
		for(int i = 0; i < other.size_; i++)
		{
			add_char(other.buffer_+	i);
		}
	}
	
	void operator=(const String& other)
	{
		while(!empty())
		{
			snibbety_snab();	
		}
		for(int i = 0; i < other.size_; i++)
		{
			add_char(other.buffer_+	i);
		}
	}
	
	void add_char(char * val)
	{
		*(buffer_ + size_) = * val;
		size_ = size_ + 1;
	}
	void add_char(char val)
	{
		*(buffer_ + size_) = val;
		size_ = size_ + 1;
	}
	friend ostream& operator<<(ostream& os, const String& str);
};
ostream& operator<<(ostream& os, const String& str)
{
	for(int i = 0; i < str.size_; i++)
	{
		os << *(str.buffer_ + i);
	}
	return os;
}
int main()
{
	String s;
	String s2;
	String s3;
	cout << "s1 empty: " << s.empty() << endl;
	for(int i = 0; i < 5; i++)
	{
		s.add_char('a');
	}
	for(int i = 0; i < 5; i++)
	{
		s2.add_char('b');
	}
	for(int i = 0; i < 5; i++)
	{
		s3.add_char('c');
	}
	cout << s.size() << endl;
	s.~String();
	s2.~String();
	s3.~String();
	cout << endl;
	cout << endl;
	cout << endl;
}