#include<cstdlib>//#include<stdlib.h>
class Singleton {
public:
	//静态成员函数调用静态函数
	static Singleton* GetInstance() {
		if (_instance == nullptr) {
			_instance = new Singleton();
			atexit(Destructor);//C 库函数
			//当程序正常终止时，调用指定的函数。可以在任何地方注册终止函数，但它会在程序终止的时候被调用。
		}
		return _instance;
	}
	~Singleton() {}//程序退出的时候，正常调用析构函数，此时atexit（）执行调用到析构函数中去
private:
	static void Destructor() {
		if (nullptr != _instance) {
			delete _instance;
			_instance = nullptr;
		}
	}
	Singleton();//构造
	Singleton(const Singleton &cpy);//拷贝构造
	Singleton& operator=(const Singleton&) {}
	static Singleton* _instance;
};
///未解决多线程访问问题
///还可以使用 内部类、智能指针来解决；此时还有线程安全问题