// -----Lazy Instantion ------- //


#define _CRT_SECURE_NO_WARNING
#include<cstdio>
#include<string>
#include<iostream>
#include<memory>
#include<mutex>
#include "BaseSingleton.h"
   // to prevent user to delete the logger pointer we can make the destructor private 
   // but we also need to help smart pointer to delete it so we need to make a deleter class to be passed on smart pointer
   // or instead of smart pointer we can use atexit(lambda function to delete the instance) inside the constructot of the class 
   
   // On a side note make sure that the logger instances are not used in Destructors of static or Global object as
   // order of destruction is unspecified in c++ so logger might get destroyed first and then it will 
   // give segmentation fault in other destructor accesing the logger
   
   // For thread safety we need to have a mutex inside the instace() function 
   // as the Instance func is static the mutx has to static
   
class Logger : public BaseSingleton<Logger>
{
	struct deleter{
		void operator()(Logger *p){
			delete p;
		}
	};
	
	inline static std::mutex m_Mtx; 
	FILE *m_pStream;   // stream class to write into the file
	std::string m_Tag;
	//inline static Logger* m_Instance;
	
	// deleter class for the smart pointer
	
	//inline static std::unique_ptr<Logger,deleter> m_Instance{}; 
	Logger();
	friend class BaseSingleton <Logger>; // to have basesingleton instantiate logger() constructor;
	~Logger();
	public:
		Logger(const Logger &) = delete;
		Logger& operator =(const Logger &) = delete;
		//static Logger &Instance();    // static methods can only access the static variables
		
		void WriteLog(const char* pMessage);   // write a log into the file , ie write the current state of application into the file
		void SetTag (const char* pTag);        // sets a tag that can be optianlly written along a msg that we long into the file
		 

};



// -------------__Eager Instantiation ---------------------//


/*
#define _CRT_SECURE_NO_WARNING
#include<cstdio>
#include<string>
    
class Logger
{
	FILE *m_pStream;   // stream class to write into the file
	
	std::string m_Tag;
	static Logger m_Instance; 
	Logger();
	public:
		Logger(const Logger &) = delete;
		Logger& operator =(const Logger &) = delete;
		static Logger &Instance();
		~Logger();
		void WriteLog(const char* pMessage);   // write a log into the file , ie write the current state of application into the file
		void SetTag (const char* pTag);        // sets a tag that can be optianlly written along a msg that we long into the file
		 

};

*/
