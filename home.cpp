#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Exception {
	string message_;

public:

	Exception(string message){
		message_ = message;
	}
	
	string get_message(){
		return message_;
	}

};

void Open(string file){
	float average;
	float sum = 0;
   	float x;
	int i = 0;
	ifstream inFile;
    
    inFile.open(file);
    if (!inFile) {
        throw Exception("OOOPS");
    }

	while (inFile >> x) {
        	sum = sum + x;
		i++;		
    }
  
    inFile.close();
	average = sum/i;
	cout << "Average = " << average << endl;
}

void min_and_max(string file){
        float x;
	float min = 0;
	float max;
	ifstream inFile;
    
    inFile.open(file);
    if (!inFile) {
        throw Exception("OOOPS");
    }

	inFile >> x;
	min = x;
	max = x;
	while (inFile >> x) {
		
		if(x < min){
			min = x;
		}
		if(x > max){
			max = x;
		}
	
    }
   
    inFile.close();
	cout << "Min = " << min << endl;
	cout << "Max = " << max << endl;

}



int main(int argc, char* argv[]) {
  
   
	try {
		Open("text.txt");
		min_and_max("text.txt");
		strict("text.txt", argv[argc]);
	} catch (Exception e) {
		cout << e.get_message() << endl;

	}
    

    return 0;
}

