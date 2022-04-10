#include "Singleton.h"

Singleton Singleton::m_Instance;

Singleton& Singleton::Instance(){

	return m_Instance;

}

void Singleton::MethodA(){
	std::cout << " MethodA() " << std::endl;

}

void Singleton::MethodB(){
	std::cout << " MethodB() " << std::endl;
}

