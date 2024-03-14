#include <iostream>

#define app_error(err_text){\
    std::cerr << err_text << std::endl;\
}
#define app_info(info_text){\
    std::cout << info_text << std::endl;\
}

template<typename T, size_t Size_>
class mArray
{
    public:
        // Iterator class
        class Iterator {
            public:
                using iterator_category = std::forward_iterator_tag;
                using value_type = T;
                using difference_type = std::ptrdiff_t;
                using pointer = T*;
                using reference = T&;
        
                Iterator(pointer ptr) : currentPtr(ptr) {}
        
                reference operator*() const {
                    return *currentPtr;
                }
    
            Iterator& operator++() { 
                ++currentPtr;
                return *this;        
            }
    
            Iterator operator++(int) {            
                Iterator temp = *this;           
                ++(*this);            
                return temp;        
            }
    
            bool operator==(const Iterator& other) const { return currentPtr == other.currentPtr; }
            bool operator!=(const Iterator& other) const { return !(*this == other); }
    
            private:
            pointer currentPtr;
        };

         // Functions to obtain iterators
        Iterator begin() {
            return Iterator(Contents);
        }
    
        Iterator end() {
            return Iterator(Contents + Size_);
        }
    
        // Functions to obtain iterators
        Iterator begin() {
            return Iterator(Contents);
        }
    
        Iterator end() {
            return Iterator(Contents + Size_);
        }

        mArray() : Contents{}{}
        //  Functions to deal with the 'Contents' class member variable
        const size_t Size(){ return Size_; }

        /*
            Just to try to simplify things, insertion can be made by simply
            passing values/data through a call to this function and give it
            arguments to insert into contents.
        */
        void Insert(const T& data, const int& pos){
            if(pos < 0 || pos >= static_cast<int>(Size_)){
                app_error("Invalid position for insertion");
            }
            Contents[pos] = data;
        }

        // Function to print the contents of 'Contents' to console
        void Display(){
            //    Could be helpful to check if the contents is empty or not
            if(Size_ == 0){
                app_info("Contents is not populated with data");
                return;
            }
            for(size_t i{0}; i<Size_; i++){
                app_info(Contents[i]);
            }
        }

        //  The functions below can be used to access data at specific position
        T& operator[](const int& pos){ return Contents[pos]; }
        const T& operator[](const int& pos) const { return Contents[pos]; }

    private:
        //  Upon object creation, this container will be initialized with values
        T Contents[Size_];
};

//    Example usage
int main()
{
    mArray<std::string, 5> Names;

    Names.Insert("Thabo", 0);
    Names.Insert("Tshepo", 1);
    Names.Insert("Jinet", 2);
    Names.Insert("Mavis", 3);
    Names.Insert("Petros", 4);

    // Iterate through the array using the iterator
    for (const auto& name : Names) {
        app_info(name);
    }

    return 0;
}
