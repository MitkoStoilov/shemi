#include <iostream>

using namespace std;

class Vector
{
	int capacity_;
	int size_;
	int* buffer_;
	
	friend class iterator;
	friend class const_iterator;
	public:
	
	Vector():
		capacity_(10),
		size_(0),
		buffer_(new int(capacity_))
	{
		
	}
	Vector(int capacity):
		capacity_(capacity),
		size_(0),
		buffer_(new int(capacity_))
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
	int* get_last()
	{
		return buffer_ + size_ - 1;
	}
	int* get_first()
	{
		return buffer_;
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
	
	
	int& operator[](int index)
	{
		return *(this->buffer_+index);
	}
	const int& operator[](int index) const
	{
		return *(this->buffer_+index);
	}
	
	//------------------------------------------------------------------------------------
	
	class riterator
	{
		int * current_;
		friend class Vector;
		
	public:
		riterator(): current_(nullptr){}
		riterator(int* ptr): current_(ptr){}
		
		
		int operator*()
		{
			return *current_;
		}
		
		int* get()
		{
			return current_;
		}
		
		riterator& operator++()
		{
			current_ = current_ - 1;
			return *this;
		}
		
		riterator operator++(int) {
			riterator res(current_);
			current_ = current_ - 1;
			return res;
		}
		
		bool operator==(const riterator other) const
		{
			return this->current_ == other.current_;
		}
		
		bool operator!=(const riterator other) const
		{
			return this->current_ != other.current_;
		}
		
	};
	//----------------------------------------------------------
	class iterator
	{
		int * current_;
		friend class Vector;
		
	public:
		iterator(): current_(nullptr){}
		iterator(int* ptr): current_(ptr){}
		
		
		int operator*()
		{
			return *current_;
		}
		
		int* get()
		{
			return current_;
		}
		
		iterator& operator++()
		{
			current_ = current_ + 1;
			return *this;
		}
		
		iterator operator++(int) {
			iterator res(current_);
			current_ = current_ + 1;
			return res;
		}
		
		bool operator==(const iterator other) const
		{
			return this->current_ == other.current_;
		}
		
		bool operator!=(const iterator other) const
		{
			return this->current_ != other.current_;
		}
		
	};
	//----------------------------------------------------------
	
	class const_iterator
	{
		const int * current_;
		friend class Vector;
		
	public:
		const_iterator(): current_(nullptr){}
		const_iterator(const int* ptr): current_(ptr){}
		
		
		const int operator*()
		{
			return *current_;
		}
		
		const int* get()
		{
			return current_;
		}
		
		bool operator==(const iterator other) const
		{
			return this->current_ == other.current_;
		}
		
		bool operator!=(const iterator other) const
		{
			return this->current_ != other.current_;
		}
		
	};
	iterator begin()
	{
		return iterator(buffer_);
	}
	
	iterator end()
	{
		return iterator(buffer_+size_);
	}
	
	riterator rbegin()
	{
		return riterator(buffer_+size_-1);
	}
	
	riterator rend()
	{
		return riterator(buffer_-1);
	}
	
	const_iterator cbegin() 
	{
		const_iterator iter(buffer_);
		return iter;
	}
	
	const_iterator cend() 
	{
		const_iterator iter(buffer_+size_-1);
		return iter;
	}
};

int main()
{
	Vector v;
	v.push_back(5);
	v.push_back(10);
	v.push_back(15);
	
	Vector::iterator current = v.begin();
	Vector::iterator last = v.end();
	Vector::riterator rcurrent = v.rbegin();
	Vector::riterator rlast = v.rend();
	
	Vector::const_iterator const_iterator;
	
	cout << *current << endl;
	current++;
	
	for(; current!=last; current++)
	{
		cout << *current << endl;
	}
	
	for(; rcurrent!=rlast; rcurrent++)
	{
		cout<< "reverse:" << *rcurrent << endl;
	}
	
	Vector& asdf = v;
	
}







































