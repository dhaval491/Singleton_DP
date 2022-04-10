//  ----------Lazy Instiation ------------//


#include "Logger.h"

//;   // static so need to be declared outside the class // 
Logger::Logger(){
	std::cout << __FUNCTION__ << std::endl; /// git change 2 ..not imp
	m_pStream = fopen("/home/avii/Documents/Coding/Design Patterns/Creational/Singleton/appLog.txt","w") ;	
}

Logger::~Logger(){
	std::cout << __FUNCTION__ << std::endl;
	fclose(m_pStream) ;
}


std::once_flag flag;
/*Logger& Logger::Instance(){

	std::cout << __FUNCTION__ << std::endl;
	// applying DOUBLE CHECK LOCKING PATTERN --//
// even in the DCLP there are issues when the first conditions is getting checked and other threads try to acces the instance pointer and the assignment for
// new operator is not a single step process  during new operator there is a step when the memory address is assigned  but members of the onject are not 
//initialized... hence it will not be null pointer but the members us undefined . When other thread checks this it returns as it is not a null and without
// members initialized the access to this members will crash the program at run time;
// To overcome the issues with DCLP we can implement the Meyers Solutuion;
// Just create the static instance in the Instance() method and return it. It is thread safe. it is used when instance is to be created with the run time data
// if the instance does not require any runtime data then always prefer the eagger instance

    // Comment out DCLP and create the instance here statically // 
//	if(m_Instance == nullptr){
//		m_Mtx.lock();
//		if(m_Instance == nullptr)
//			{
//				//m_Instance = new Logger{};
//				m_Instance.reset(new Logger{});
//		
//			}
//		m_Mtx.unlock();
	}

	static Logger instance;	 // meyers singleton... thread safe
	// ---  using call_once --- //
	return instance;
}
*/

void Logger::WriteLog(const char*  pMessage) {

	fprintf(m_pStream,"[%s] %s\n", m_Tag.c_str(),pMessage);    // write the raw string of the tag and not the string object tag itself
	
	fflush(m_pStream);  // Message may be wriiten into the file buffer and if the application crashes it may not be written into the file so to prevent it from staying into the buffer and get lost we flush to make the buffer clear

}

void Logger::SetTag(const char* pTag){
	
	m_Tag = pTag;

}


// -------------__Eager Instantiation ---------------------//


/*

#include "Logger.h"

Logger Logger::m_Instance;
Logger::Logger(){

	m_pStream = fopen("/home/avii/Documents/Coding/Design Patterns/Creational/Singleton/appLog.txt","w") ;	
}

Logger::~Logger(){
	fclose(m_pStream) ;
}

Logger& Logger::Instance(){
	return m_Instance;
}


void Logger::WriteLog(const char*  pMessage) {

	fprintf(m_pStream,"[%s] %s\n", m_Tag.c_str(),pMessage);    // write the raw string of the tag and not the string object tag itself
	
	fflush(m_pStream);  // Message may be wriiten into the file buffer and if the application crashes it may not be written into the file so to prevent it from staying into the buffer and get lost we flush to make the buffer clear

}

void Logger::SetTag(const char* pTag){
	
	m_Tag = pTag;

}


*/
