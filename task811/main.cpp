#include "string_stack.h"
#include <iostream>

int main()

{

    stack_string myStack;
    stack_string myStack1;
    myStack.push( "The" );
    myStack1.push( "Brown" );
    myStack1.push( "Fox" );
    myStack1.push("element");
    myStack1 = myStack+myStack1;
    std::cout<<myStack1.find("element")<<std::endl;
    std::cout<<myStack1.find( "Fox" )<<std::endl;
    std::cout<<myStack1.find( "apple" )<<std::endl;

    myStack1.print();

 
    





    return 0;
}