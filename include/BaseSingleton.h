#include<string>
template<typename T>
class BaseSingleton{
	
	protected:
	BaseSingleton() = default;
	BaseSingleton(const BaseSingleton&) = delete;
	BaseSingleton& operator = (const BaseSingleton&) = delete;
	
	public:
		static T& Instance(){
			std::cout << __FUNCTION__ << std::endl;
			static T _crtp_instance;
			return _crtp_instance;
		}


};
