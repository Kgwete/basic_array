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
        //  Functions to deal with the contents class member
        const size_t Size(){ return Size_; }

        /*
            Just to try to simplify things, insertion can be made by simply
            passing values/data through a call to this function and give it
            arguments to insert into contents.
        */
        void Insert(const T& data, const int& pos){
            Contents[pos] = data;
        }

        // Function to print the contents of 'Contents' to console
        void Display(){
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

int main()
{
    mArray <std::string, 5> Names;

    Names.Insert("Thabo",0);
    Names.Insert("Tshepo",1);
    Names.Insert("Jinet",2);
    Names.Insert("Mavis",3);
    Names.Insert("Petros",4);

    Names.Display();

    return 0;
}
