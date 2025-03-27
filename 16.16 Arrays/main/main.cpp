#include <iostream>

// ARRAYS
int main(){
    // Declaretion
    // int scores[10];

    // std::cout << "Score : " << scores[0] << std::endl;
    
    // Declaretion
    int scores [10] ;

    // It allow user to modify data.
    int score[10] {2, 3, 0, 4, 5, 6, 7, 8, 9, 1};

    // scores[1] = 21;
    // scores[2] = 22;


    // for (int i{0}; i < 10; i++){
    //     score[i] = scores[i] * 10;
    // }

    for (int i{0}; i < 10; i++){
        std::cout << "Score : " << score[i] << std::endl;
    }


    std::cout << std::endl;
    

    // Omiting the SIZE and not putting the number of iteration when using FOR loops
    // it doesn't allow user to modify data.
    int players [] {2, 3, 12, 43, 5, 4, 4, 5, 51, 23};

    for (auto value : players){
        std::cout << "number : " << value << std::endl;
    }
    

    std::cout << std::endl;


    int nums [] {2, 3, 12, 43, 5, 4, 4, 5, 51, 23};
    int sums {1};

    for (int add_up_nums : nums){
        sums *= add_up_nums;
    }


    std::cout << "Total Sum = " << sums << std::endl;
    


    // GETTING THE SIZE OF AN ARRAY
    std::cout << std::endl;
    
    
    int nums1 [] {2, 3, 120, 40, 5, 4, 4, 58, 51, 39};
    
    std::cout << std::size(nums1) << std::endl;
    std::cout << std::endl;

    for (size_t l{0}; l < std::size(nums1); l++){
        std::cout << nums1[l] << std::endl;
    }


    std::cout << "Total Sum = " << sizeof(nums1) << std::endl;

    size_t counts{sizeof(nums1) / sizeof(nums1[0])};

    std::cout << counts << std::endl;


    // ARRAY OF CHARACTERS
    std::cout << std::endl;
    char word [] {'s','h','a','b','s', '\0'};

    std::cout << word << std::endl;
    std::cout << std::size(word) << std::endl;


    // Direct PrintOut
    std::cout << std::endl;
    char word2 [] {'s','h','a','b','s'};

    std::cout << word2 << std::endl;

    

    // Auto fill
    std::cout << std::endl;
    char word1 [6] {'s','h','a','b','s',};

    std::cout << word1 << std::endl;
    std::cout << std::size(word1) << std::endl;



    std::cout << std::endl;

    

    // Literal C-strings
    std::cout << std::endl;
    char name [] {"Hello"};

    std::cout << name << std::endl;
    std::cout << std::size(name) << std::endl;
    
    std::cout << std::endl;
    char f_name [] {"Hello World!"};

    std::cout << f_name << std::endl;
    std::cout << std::size(f_name) << std::endl;



    std::cout << std::endl;

    

    // Bounds of an Array
    /*
    std::cout << std::endl;
    char name [] {"Hello"};

    std::cout << name << std::endl;
    std::cout << std::size(name) << std::endl;
    
    std::cout << std::endl;
    char f_name [] {"Hello World!"};

    std::cout << f_name << std::endl;
    std::cout << std::size(f_name) << std::endl;


    */
    std::cout << std::endl;

    return 0;
}
 