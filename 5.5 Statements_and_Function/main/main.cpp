#include <iostream>

// Statement & Function


int addNums(int first_num, int second_num){
    int sum = first_num + second_num;
    return sum;
}

// int main(){
    

//     return 0;
// }

int main(int args, char **argv){

    
    int first_number = 12;
    int second_number = 9;
    
    int sum = first_number + second_number;
    sum = addNums(first_number, second_number);
    sum = addNums(30, 42);
    
    std::cout << "Hello World!" << std::endl;
    std::cout << "The sum of 8 and 7 = " << addNums(8,7) << std::endl;
    std::cout << "The sums of the first and second numbers : " << sum << std::endl;
    std::cout << "The sums of the first and second numbers : " << addNums(6, 34) << std::endl;
    
    return 0;
}

 