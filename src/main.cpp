//------------------Lazy Instantiation-----------------//


#include "Logger.h"
using  namespace std;

void OpenConnection(){
	
	Logger &lg = Logger::Instance();
	lg.WriteLog("Attempting to open a connection");

}


// Here the instance of logger object that is not destroyed ... and the destructor is not invoked ... if destructor has to release some other resources t
// the other applications are depending on then this will cause the trouble...
// Use the smart pointer...make the instance variable smart and use inline static to declare it in the header file itself
// now after the instance is created multiple threads will lock the mutex one by one and program slows down ..as once the instance is created 
// it is always checkd for nullptr.. .. so we need to check the nullpter condition also before locking the mutex...
// this is called double check locking pattern, 



int main(){

	Logger &lg = Logger::Instance();  // if we dont do &lg that is by reference we can have a dangling pointer to the FILE object which will be destroyed by 
									 // Openconnection call after its scope ends .. Core gets dumped... crash
									 // Solution? Delete the copy constructor and delete the assignment operator
	lg.SetTag("198.162.1.1");
	lg.WriteLog("Application has Started");
	OpenConnection();  // will have unknown string written to the file as 
				       // there are two instances of the logger created and both will attempt to write into the same file. Now we can also make lg as global but still it wont prevent the user from creating multiple instances ofthe Logger.
		// so we need to have Logger as Singleton
	lg.WriteLog("Application is Shutting Down");



return 0;
}








// -------------__Eager Instantiation ---------------------//


/*

#include "Logger.h"
using  namespace std;

void OpenConnection(){
	
	Logger &lg = Logger::Instance();
	lg.WriteLog("Attempting to open a connection");

}


//calling openconnection without singleto writes this:
//[] Attempting to open a connection
//\00\00\00[198.162.1.1] Application is Shutting Down



//           After implenting the singleton

//[198.162.1.1] Application has Started
//[198.162.1.1] Attempting to open a connection
//[198.162.1.1] Application is Shutting Down



int main(){

	Logger &lg = Logger::Instance();  // if we dont do &lg that is by reference we can have a dangling pointer to the FILE object which will be destroyed by 
									 // Openconnection call after its scope ends .. Core gets dumped... crash
									 // Solution? Delete the copy constructor and delete the assignment operator
	lg.SetTag("198.162.1.1");
	lg.WriteLog("Application has Started");
	OpenConnection();  // will have unknown string written to the file as 
				       // there are two instances of the logger created and both will attempt to write into the same file. Now we can also make lg as global but still it wont prevent the user from creating multiple instances ofthe Logger.
		// so we need to have Logger as Singleton
	lg.WriteLog("Application is Shutting Down");



return 0;
}

*/
