#include <iostream>

using namespace std;

class Vector{

	int capacity_;
	int size_;
	int* buffer_;

	void resize(){
	}

public:
	Vector() : 
		capacity_(0),
		size_(0),
		buffer_(new int){}

	Vector(int capacity) : 
		capacity_(capacity),
		size_(0),
		buffer_(new int){}

	~Vector(){
		while(!empty()){
			pop_back();
		}
	}

	void push_back(int val){
		if(capacity_<= size_){
			resize();
		}
		*buffer_ = val;
		size_++;
		*buffer_++;
	}
	void pop_back(){
		int& a = back();
		a = 0;
		size_--;
		*buffer_--;
	}
	int& front(){
		
		return *(this->buffer_-size_);
	}
	int& back(){

		return *(this->buffer_-1);
	}
	const int& front() const{
		return *(this->buffer_-size_);
	}
	const int& back() const{
		return *(this->buffer_-1);
	}

	bool empty() const{
		if(size_==0){
			return true;
		}else{
			return false;
		}
	}
	int size() const{
		return size_;
	}
	int capacity()const{
		return capacity_;
	}

	Vector(const Vector& other){

	}
	Vector& operator=(const Vector& other);

	int& operator[](int index){
		index = size_ - index;
		return *(this->buffer_-index);
	}
	const int& operator[](int index) const{
		index = size_ - index;
		return *(this->buffer_-index);
	}


};

int main(){
	Vector v(10);

	cout << "empty()= "<< v.empty() << endl;
	cout << "size= " << v.size() << endl;

	v.push_back(4);
	v.push_back(10);
	v.push_back(8);

	int a = v.front();
	cout << "front()= " << a << endl;

	int b = v.back();
	cout << "back()= " << b << endl;



	cout << "empty()= "<< v.empty() << endl;
	cout << "size()= " << v.size() << endl;

	v.pop_back();

	cout << "empty()= "<< v.empty() << endl;
	cout << "size()= " << v.size() << endl;
	
	
	a = v.front();
	cout << "front()= " << a << endl;

	b = v.back();
	cout << "back()= " << b << endl;

	v.push_back(7);

	cout <<"v[2]= "<< v[2] << endl;


	v.~Vector();
	cout <<"v[2]= "<< v[2] << endl;

	Vector n;
	n.push_back(9);
	
	cout << n[0] << endl;

	return 0;
}