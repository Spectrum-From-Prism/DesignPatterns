#include<mutex>
//c++11
#include<atomic>
// jave 使用关键字volatile告诉编译器不要进行cpu reorder
class Singleton {
public:
	//调用GetInstance()->new 对象才会被创建 :懒汉模式（lazy load）
	static Singleton* GetInstance() {
		Singleton* tmp = _instance.load(std::memory_order_relaxed);
		std::atomic_thread_fence(std::memory_order_acquire);//获取内存屏障
		if (tmp == nullptr) {
			std::lock_guard<std::mutex> lock(_mutex);
			tmp = _instance.load(std::memory_order_relaxed);
			if (tmp == nullptr) {
				tmp = new Singleton;
				std::atomic_thread_fence(std::memory_order_release);//释放内存屏障 在该屏障内都不会进行cpu reorder
				_instance.store(tmp, std::memory_order_relaxed);//new了之后加载到原子类中去
				atexit(Destructor);
			}
		}
		return tmp;
	}
private:
	static void Destructor() {
		Singleton* tmp = _instance.load(std::memory_order_relaxed);
		if (nullptr != tmp) {
			delete tmp;
		}
	}
	Singleton() {}
	Singleton(const Singleton&) {}
	Singleton& operator=(const Singleton&) {}
	static std::atomic<Singleton*> _instance;//原子模板类
	static std::mutex _mutex;
};
std::atomic<Singleton*> Singleton::_instance = nullptr;//静态成员需要初始化
std::mutex Singleton::_mutex;//互斥锁初始化

///解决了cpu reorder的问题 但太复杂了