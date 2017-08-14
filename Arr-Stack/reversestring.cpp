#include "charstack.h"
#include "charstack.cpp"

int main(){
	charstack CharStack(20);
	char ReadChar;
	std::cout<< "Enter a string: ";
	std::cin.get(ReadChar);
	while (ReadChar != '\n'){
  		CharStack.Push(ReadChar);
		std::cin.get(ReadChar);
	}
	std::cout<<"Reversed string: ";
	while (!CharStack.Empty()){
		CharStack.Pop(ReadChar);
		std::cout<<ReadChar;
	}
	std::cout<<std::endl;
	return 0;
}
