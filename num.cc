#include <iostream>

using namespace std;

class RationalException{};

class Rational{
	long num_;
	long den_;
	
	long gcd(long a, long b){
		if(a<0){
			a = -a;
		}
		long r = a%b;
		while(r != 0){
		a = b;
		b = r;
		r = a% b;

		}
		return b;

	}
	void reduce() {
		long r = gcd(num_, den_);
		num_ /= r;
		den_ /= r;
	}	

	void standardize(){
		if(den_ < 0){
			num_ = - num_;
			den_ = - den_;

		}
		if(num_ == 0){
			den_ = 1;

		}else{
			reduce();
		}
}

public:

	Rational(long num, long den){
		if(den == 0){
			throw RationalException();
			
		}
		num_ = num;
		den_ = den;

		standardize();
	}
	void dump(){
		reduce();
		cout << "("<<num_ << "/" << den_ << ")"<< endl; 

	}
	void add(Rational other){
		num_ = num_*other.den_+other.num_*den_;
		den_ = den_*other.den_;
	}
	void sub(Rational other)
	{
		num_ = num_*other.den_-other.num_*den_;
		den_ = den_*other.den_;
	}
	void set(long den, long num)
		{
			den_=den;
			num_=num;
		}

};
Rational add(Rational r1, Rational r2)
{
	Rational r3;
	r3.num = r1.num_*r2.den_+r1.num_*r2.den_;
	r3.den_ = r1.den_*r2.den_;
	return r3;
}
Rational sub(Rational r1, Rational r2)
{
	Rational r3;
	r3.num_ = r1.num_*r2.den_-r1.num_*r2.den_;
	r3.den_ = r1.den_*r2.den_;
	return r3;
}


int main()
{
	Rational r1(1, 2), r2(2, 4), r3(3, -6);
	r1.dump();
	//r2.dump();
	//r3.dump();
	r1.add(r2);
	r1.dump();
	r1.set(r1.den, r1.num);
	r2.set(r1.den, r1.set);
	r3 = add(r1, r2);
	r3.dump();
	return 0;
}

