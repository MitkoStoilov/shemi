#include <iostream>

using namespace std;

class Vector
{
	int capacity_;
	int size_;
	int* buffer_;
	
	public:
	
	Vector():
		capacity_(10),
		size_(0),
		buffer_(new int)
	{
		
	}
	Vector(int capacity):
		capacity_(capacity),
		size_(0),
		buffer_(new int)
	{
		
	}
	
	~Vector()
	{
		while(!empty())
			pop();
	}
	
	void pop()
	{
		size_ = size_-1;
		delete (buffer_+size_);
	}
	
	void push_back(int val)
	{
		*(buffer_+size_) = val;
		size_++;
	}
	void pop_back()
	{
		size_ = size_ - 1;
		cout << *(buffer_+size_) << endl;
		delete (buffer_+size_);
	}
	int& front()
	{
		return *(buffer_ + size_);
	}
	int& back()
	{
		return *buffer_;
	}
	
	const int& front() const
	{
		return *(buffer_ + size_);
	}
	const int& back() const
	{
		return *buffer_;
	}
	
	bool empty() const
	{
		return !size_;
	}
	int size() const
	{
		return size_;
	}
	int capacity() const
	{
		return capacity_;
	}
	
	Vector(const Vector& other)
	{
		size_ = other.size_;
		capacity_ = other.capacity_;
		for(int i = 0; i < size_; i++)
		{
			*(buffer_ + i) = *(other.buffer_+i);
		}
	}
	
	Vector& operator=(const Vector& other)
	{
		
		 
	}
	
	int& operator[](int index)
	{
		return *(this->buffer_+index);
	}
	const int& operator[](int index) const
	{
		return *(this->buffer_+index);
	}
};

int main()
{
	Vector v;
	v.push_back(6);
	v.push_back(10);
	Vector& asdf(v);
	asdf.pop_back();
}



































