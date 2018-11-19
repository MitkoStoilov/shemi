/// testingqqqwqwqwqwqwqw

#include<iostream>
#include<vector>
#include<string>

using namespace std;

class ListOfArrays {

    class ArrayNode {

        public:

        
        int size_;
        int* data_;
        ArrayNode* prev_;
        ArrayNode* next_;

        ArrayNode(int* data, int size)
            : data_(data), size_(size), next_(0), prev_(0) {
                data_=new int[1000];
            }

        ~ArrayNode() {
            delete [] data_;
        }
        void push_a(int val){
            data_++;
            *data_ = val;
            
        }

    };

    ArrayNode* head_;
    int size_;

    public:

    class Iterator {

        friend class ListOfArrays;

        ListOfArrays& list_;
        ArrayNode* current_;

        public:

        Iterator(ListOfArrays& list, ArrayNode* current)
            : list_(list), current_(current) {}

        bool operator==(const Iterator& other){
            return current_ == other.current_;
        }

        bool operator!=(const Iterator& other){
            return ! operator == (other);
        }

        Iterator& operator++(){
            current_ = current_ -> next_;
            return *this;
        }

        Iterator operator++(int){
            Iterator res(list_, current_);
            current_ = current_ -> next_;
            return res;
        }

        int& operator[](const int& index){
            int& a = current_->data_[index-current_->size_+1];
            return a;
        }

        int size(){
            return current_->size_;
        }

        void show(){
            for(int i = 0;i<this->size();i++){
                cout << current_->data_[i-current_->size_+1] << ' ';
            }
            cout << endl;
        }
        
        double average(){
            double a=0;
            for(int i = 0;i<this->size();i++){
                a += current_->data_[i-current_->size_+1];
            }
            if(a==0){
                return a;
            }else{
                a = a/this->size();
                return a;
            }
            //cout << a << endl;
            
        }
        
        double median(){
            double m = 0;
            int v;
            int c;
            if(this->size()%2==0){
                v = this->size()/2;
                c = v--;
                m = current_->data_[v-current_->size_+1] + current_->data_[c-current_->size_+1];
                m=m/2;
            }else{
               v = this->size()/2;
               m = current_->data_[v-current_->size_+1]; 
            }
            //cout << m<<endl;
            return m;
        }
        
        int sum(){
            int sum=0;
            for(int i = 0;i<this->size();i++){
                sum += current_->data_[i-current_->size_+1];
            }
            //cout << sum <<endl;;
            return sum;
        }
        
        Iterator& ordered(bool ascending = true){
            int i, j, c; 
            bool swapped;
            if(ascending){
                for (i = 0; i < this->size()-1; i++) 
                { 
                    swapped = false; 
                    for (j = 0; j < this->size()-i-1; j++) 
                    { 
                        if (current_->data_[j-current_->size_+1] > current_->data_[j-current_->size_+1+1]) 
                        { 
                            c = current_->data_[j-current_->size_+1];
                            current_->data_[j-current_->size_+1] = current_->data_[j-current_->size_+1+1];
                            current_->data_[j-current_->size_+1+1] = c;
                            swapped = true; 
                        } 
                    } 
                    if (swapped == false) 
                        break; 
                }
            }else{
                for (i = 0; i < this->size()-1; i++) 
                { 
                    swapped = false; 
                    for (j = 0; j < this->size()-i-1; j++) 
                    { 
                        if (current_->data_[j-current_->size_+1] < current_->data_[j-current_->size_+1+1]) 
                        { 
                            c = current_->data_[j-current_->size_+1];
                            current_->data_[j-current_->size_+1] = current_->data_[j-current_->size_+1+1];
                            current_->data_[j-current_->size_+1+1] = c;
                            swapped = true; 
                        } 
                    } 
                    if (swapped == false) 
                        break; 
                }
            }       
            return *this;
        }
    };

    ListOfArrays()
            : size_(0), head_(new ArrayNode(0, 0)) {
        head_->next_ = head_;
        head_->prev_ = head_;
    }

    ~ListOfArrays(){
        while(head_->next_!=head_){
            ArrayNode* elm = head_->next_;
            head_->next_ = elm->next_;
            elm->next_->prev_ = head_;
            elm->data_ = 0;
            delete [] elm->data_;
            delete elm;
            size_--;
        }
        delete head_;

       // cout << "hi" << endl;
    }

    ListOfArrays(const ListOfArrays& other)
            : size_(0), head_(new ArrayNode(0, 0)) {

        head_->next_ = head_;
        head_->prev_ = head_;
        ArrayNode* node = other.head_->next_;

        while (node != other.head_){
            //cout << "hi";
            push(node->data_, 1-node->size_, node->size_);
            node = node->next_;
        }
            
    }

    ListOfArrays& operator=(const ListOfArrays& other){
        if (this != &other) {
            //to_empty(); //this->to_empty();

            while(head_->next_!=head_){
                ArrayNode* elm = head_->next_;
                head_->next_ = elm->next_;
                elm->next_->prev_ = head_;
                elm->data_ = 0;
                delete [] elm->data_;
                delete elm;
                size_--;
            }    

            ArrayNode* node = other.head_ -> next_;
            while (node != other.head_) {
                push(node->data_, 1-node->size_, node->size_);
                node = node -> next_;
            }
        }
        return *this;
    }

    int size(){
        return size_;
    }

    void push(int array[], int position, int length){
        int size = position + length;
        int data[length]; 
        int z =0;

        ArrayNode* element = new ArrayNode(data, length);

        for(int i = position; i<size; i++){

            data[z] = array[i];
            element->push_a(data[z]);
            z++;
            //cout << element->data_[0];
        }
        
        ArrayNode* last_element = head_->prev_;

        last_element->next_ = element;
        element->prev_ = last_element;

        element->next_ = head_;
        head_->prev_ = element;

        size_++;
        //cout << element->data_[2]<<endl;;
    }

    void averages(double averages[]){
        int size = size_;
        int i = 0;
        for(ListOfArrays::Iterator it = this->begin();it != this->end(); it++){
            double s = it.average();
            averages[i] = s;
            i++;
        }
        for(int i = 0; i<size; i++){
            cout << averages[i] << " ";
        }
        cout << endl;
    }

    void medians(double medians[]){
        int size = size_;
        int i = 0;
        for(ListOfArrays::Iterator it = this->begin();it != this->end(); it++){
            double s = it.median();
            medians[i] = s;
            i++;
        }
        for(int i = 0; i<size; i++){
            cout << medians[i] << " ";
        }
        cout << endl;
    }
    
    void sizes(int sizes[]){
        int size = size_;
        //int a[size];
        int i = 0;
        for(ListOfArrays::Iterator it = this->begin();it != this->end(); it++){
            int s = it.size();
            sizes[i] = s;
            i++;
        }
        for(int i = 0; i<size; i++){
            cout << sizes[i] << " ";
        }
        cout << endl;
    }
    
    void sums(int sums[]){
        int size = size_;
        //int a[size];
        int i = 0;
        for(ListOfArrays::Iterator it = this->begin();it != this->end(); it++){
            int s = it.sum();
            sums[i] = s;
            i++;
        }
        for(int i = 0; i<size; i++){
            cout << sums[i] << " ";
        }
        cout << endl;
    }
    

    Iterator begin(){
        return Iterator(*this, head_->next_);
    }

    Iterator end(){
        return Iterator(*this, head_);
    }

    ListOfArrays& ordered(bool ascending = true){
        //bool asc = ascending;
        int count = 0;
        bool swapped;

        for(ListOfArrays::Iterator it = this->begin();it != this->end(); it++){
            it.ordered(ascending);
        }
        ListOfArrays::Iterator it1 = this->begin();

        while(true){
            swapped = false;
            count++;
            for(ListOfArrays::Iterator it = this->begin();it != this->end(); it++){
                it1.current_ = it.current_;
                it1++;
                if(it1==this->end()){
                    break;
                }
                //it.show();
                   //it1.show();
                   if(ascending == false){
                       if(it.sum() < it1.sum()){

                               ListOfArrays::Iterator it2 = this->begin();

                               it.current_-> prev_-> next_ = it1.current_;
                            it1.current_-> next_-> prev_ = it.current_;

                               it.current_->next_ = it1.current_->next_;
                            it1.current_->prev_ = it.current_->prev_;

                            it.current_->prev_ = it1.current_;
                            it1.current_->next_ = it.current_;

                            it2.current_ = it1.current_;
                            it1.current_ = it.current_;
                            it.current_ = it2.current_;

                            swapped = true;    
                    }
                }else{
                    if(it.sum() > it1.sum()){

                               ListOfArrays::Iterator it2 = this->begin();

                               it.current_-> prev_-> next_ = it1.current_;
                            it1.current_-> next_-> prev_ = it.current_;

                               it.current_->next_ = it1.current_->next_;
                            it1.current_->prev_ = it.current_->prev_;

                            it.current_->prev_ = it1.current_;
                            it1.current_->next_ = it.current_;

                            it2.current_ = it1.current_;
                            it1.current_ = it.current_;
                            it.current_ = it2.current_;

                            swapped = true;    
                    }
                }
                //cout << swapped<<endl;;
            }
            if(swapped == false){
                break;
            }
        }
        //cout << count << endl;
        return *this;
    }

    ListOfArrays& operator*=(const int& coef){
        for(ListOfArrays::Iterator it = this->begin();it != this->end(); it++){
            int a = it.size();
            a -= 1;
            bool flag = 0;
            for(int i = 0; i<it.size();i++){
                
                it[i] *= coef;
            }
        }
        return *this;
    }

    ListOfArrays& operator+=(const int& value){
        for(ListOfArrays::Iterator it = this->begin();it != this->end(); it++){
            int a = it.size();
            a -= 1;
            bool flag = 0;
            for(int i = 0; i<it.size();i++){
                
                it[i] += value;
            }
        }
        return *this;
    }

    void show(){
        int i = 0;
        for(ListOfArrays::Iterator it = this->begin();it != this->end(); it++){
            int a = it.size();
            a -= 1;
            bool flag = 0;
            i++;
            if(i == this->size()){
                flag = 1;
            }
            for(int i = 0; i<it.size();i++){
                
                if(i == a && flag == 0){
                    cout << it[i] << "; ";
                }else{
                    cout << it[i] << ' ';
                }
            }
        }
        cout << endl;
    }
};

int main(){

    ListOfArrays l;
    string s;
    int count_arr = 1;
    int count_nums = 1;
    int num;

    vector<string> v;
    vector<int> v1;
    vector<int> v2;

    vector<int> n;
    int a1 = 0;
    while(true){
        getline(cin,s);
        if(s.find('\n')){
            break;
        }
    }
    cout << "> ";
    const string sc = s;
    for(int i = 0; i<sc.length();i++){
        int a = 0;
        
        if(sc[i]==';' ||sc[i]=='\n'){
            count_arr++;
        }
        if(sc[i]==' '){
            count_nums++;
        }
    }
    size_t pos = 0;
    string token;
    string delimiter = "; ";
    while ((pos = s.find(delimiter)) != string::npos) {
        token = s.substr(0, pos);
        v.push_back(token);
        s.erase(0, pos + delimiter.length());
    }
    v.push_back(s);
    
    for(int i = 0; i<v.size(); i++){
        string& num = v[i];
        //cout << v[i] << endl;
        int l = 1;
        for(int k = 0; k<num.length(); k++){
            
            if(num[k]==' '){
                l++;
            }
        }
        n.push_back(l);
        
        size_t pos = 0;
        string token;
        string delimiter = " ";
        while ((pos = num.find(delimiter)) != string::npos) {
            token = num.substr(0, pos);
            int c = stoi(token);
            //n.push_back(l);
            v1.push_back(c);
            num.erase(0, pos + delimiter.length());
        }

        int b = stoi(num);
        //n.push_back(l);
        v1.push_back(b);
    }

    /*cout << sc << endl;
    cout << count_arr << endl;
    cout << count_nums << endl;

    cout << endl;*/
    int arr_size = count_nums;
    int arr[arr_size];
    for(int z = 0;z<v1.size();z++){
        arr[z]=v1[z];
        //cout << arr[z] << ' ';
    }
    /*cout << endl;
    for(int z = 0;z<n.size();z++){

        //stoi(v1[z]);
        cout << n[z]<<endl;
    }*/
    
    int position = 0;
    for(int i = 0; i<count_arr; i++){

        l.push(arr, position, n[i]);
        position += n[i];
    }
    const ListOfArrays cl = l;
    //cout << endl;
    //l.ordered(false);
    //l.show();
    
    //cl.show();

    string f;
    bool a = 0;
    vector<string> functions;
    bool cs = 0;
    bool error = 1;
    while(true){
        cout << "> ";
        getline(cin,f);
        size_t pos1 = 0;
        string token1;
        string delimiter1 = ".";
        while ((pos1 = f.find(delimiter1)) != string::npos) {
            token1 = f.substr(0, pos1);
            functions.push_back(token1);
            f.erase(0, pos1 + delimiter1.length());
        }
        functions.push_back(f);

        if(functions[0] == "begin"){
            cs = 1;
            ListOfArrays::Iterator it = l.begin();
            //cout << "> > ";
            for(int i = 1; i<functions.size();i++){
               //cout << functions[i] << endl;
                error = 1;
                if(functions[i]=="ordered:true"){
                    //cout << "> > ";
                    it.ordered(true);
                    cs = 1;
                    error = 0;
                }
                if(functions[i]=="ordered:false"){
                    //cout << "> > ";
                    it.ordered(false);
                    cs = 1;
                    error = 0;
                }
                if(functions[i]=="show"){
            
                        it.show();
                        cs = 1;
                        error = 0;
                    //cout << "> > ";

                    //cout << "> ";
                }
                if(functions[i].find("at:") != string::npos){
                    //cout << "> > ";
                    functions[i].erase(0, 3);
                    int a = stoi(functions[i]);
                    if(a>=it.size()){
                        cout << "ERROR: Index out of bounds" << endl;
                        break;
                    }
                    int c = it[a];
                    cout << c << endl;;
                    cs = 1;
                    error = 0;
                    //it = l.begin();

                }
                if(functions[i]=="next"){
                    //cout << "> > ";
                    if(it!=l.end()){
                        it++;
                    }if(it==l.end()){
                        cout << "ERROR: End of iteration" << endl;
                        break;
                    }
                    //it = l.begin();
                    error = 0;
                }
                if(functions[i]=="size"){
                    //cout << "> > ";
                    int a = it.size();
                    cout << a <<endl;
                    cs = 1;
                    error = 0;
                   // cout << "> ";
                }
                if(functions[i]=="average"){
                    //cout << "> > ";
                    int a = it.average();
                    cout << a;
                    cs = 1;
                    error = 0;
                    //cout << "> ";
                }
                if(functions[i]=="median"){
                    //cout << "> > ";
                    int m = it.median();
                    cout << m;
                    cs = 1;
                    error = 0;
                    //cout << "> ";
                }
                if(functions[i]=="sum"){
                    //cout << "> > ";
                    int s = it.sum();
                    cout << s;
                    cs = 1;
                    error = 0;
                    //cout << "> ";
                }
                if(error == 1){
                    cout << "ERROR: Unknown operation" << endl;
                    cs = 1;
                    break;
                }

            }
            l=cl;
        }else{
            int flag = 0;
            if(f=="quit"){
            //cout << a;
                break;
            }

            //cout << "> > ";
            for(int i = 0; i<functions.size();i++){
                //cout << functions[i] << endl;
                error = 1;
                if(functions[i]=="quit"){
                    error = 0;
                }
                if(functions[i]=="ordered:true"){
                    //cout << "> > ";
                    l.ordered(true);
                    cs = 1;
                    error = 0;
                }
                if(functions[i]=="ordered:false"){
                    //cout << "> > ";
                    l.ordered(false);
                    cs = 1;
                    error = 0;
                }
                if(functions[i]=="show" || functions[i]=="show "){
                    //cout << "> > ";

                    l.show();
                    cs = 1;
                    error = 0;
                    //cout << "> ";
                }
                if(functions[i].find("mul:") != string::npos){
                    //cout << "> > ";
                    functions[i].erase(0, 4);
                    int a = stoi(functions[i]);
                    l*=a;
                    cs = 1;
                    error = 0;

                }
                if(functions[i].find("add:") != string::npos){
                    //cout << "> > ";
                    functions[i].erase(0, 4);
                    int a = stoi(functions[i]);
                    l+=a;
                    cs = 1;
                    error = 0;
                }
                if(functions[i]=="size"){
                    //cout << "> > ";
                    int a = l.size();
                    cout << a <<endl;
                    cs = 1;
                    error = 0;
                   // cout << "> ";
                }
                if(functions[i]=="averages"){
                    //cout << "> > ";
                    int a = l.size();
                    double avr[a];
                    l.averages(avr);
                    cs = 1;
                    error = 0;
                    //cout << "> ";
                }
                if(functions[i]=="medians"){
                    //cout << "> > ";
                    int m = l.size();
                    double med[m];
                    l.medians(med);
                    cs = 1;
                    error = 0;
                    //cout << "> ";
                }
                if(functions[i]=="sums"){
                    //cout << "> > ";
                    int s = l.size();
                    int sums[s];
                    l.sums(sums);
                    cs = 1;
                    error = 0;
                    //cout << "> ";
                }
                if(functions[i]=="sizes"){
                    //cout << "> > ";
                    int s = l.size();
                    int sizes[s];
                    l.sizes(sizes);
                    cs = 1;
                    error = 0;
                    //cout << "> ";
                }
                if(error == 1){
                    if(flag == 0){
                        cout << "ERROR: Unknown operation" << endl;
                    }else{
                         cout<< "ERROR: Unknown operation" << endl;
                    }
                    //cout<<"> ";
                    flag = 1; 
                    cs =1;
                    //break;
                }
            
            }
            /*if(error == 1){
                    cout << "ERROR: Unknown operation" << endl;
                    cs = 1;
                    flag = 1;
                    break;
            }*/
            l=cl;
        }

        functions.clear();


    }
    return 0;
}