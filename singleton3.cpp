#include<cstdlib>
#include<mutex>

class Singleton {
public:
	static Singleton* GetInstance() {//该接口访问一个对象，为读操作
		//std::lock_guard<std::mutex> lock(_mutex);//1、该处，锁的粒度太大，多个线程访问时
		if (_instance == nullptr) {
			std::lock_guard<std::mutex> lock(_mutex);//2、该处后面若没有if判断，则两线程访问时会重复new
			if (_instance == nullptr) {///双检测
				_instance = new Singleton();//1.分配内存 2.调用构造函数 3.赋值指针_instance
				///当在多线程环境下，cup指令reorder：1->3->2 ==> 存在野指针问题
				//此时_instance！=nullptr，为野指针(类未对成员变量进行初始化，此时调用函数（方法）可能会访问到不存在的地址，随时可能会导致程序的崩溃)
				atexit(Destructor);
			}
		}
		return _instance;
	}
private:
	static void Destructor() {
		if (nullptr != _instance) {
			delete _instance;
			_instance = nullptr;
		}
	}
	Singleton() {}//构造
	Singleton(const Singleton& cpy) {}//拷贝构造
	Singleton& operator=(const Singleton&) {}
	static Singleton* _instance;
	static std::mutex _mutex;
};
Singleton* Singleton::_instance = nullptr;//静态成员需要初始化
std::mutex Singleton::_mutex;//互斥锁初始化