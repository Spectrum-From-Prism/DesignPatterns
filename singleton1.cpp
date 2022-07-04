class Singleton {
public:
	static Singleton * GetInstance() {//该函数指针也只有一个
		if (_instance == nullptr) {
			_instance = new Singleton();///存在内存泄露
			///处于内存堆区（在程序关闭时，该区域的内存可能不会被释放掉，如linux中的shmget申请的共享内存，就与进程结束无关）
		}
		return _instance;
	}
private:
	Singleton() {}//构造
	Singleton(const Singleton& clone) {}//拷贝构造
	Singleton& operator=(const Singleton&) {}
	static Singleton* _instance;//对于该类来说唯一，静态成员需要初始化
	///处于静态全局区（在程序关闭时，该区域的内存会被释放掉）
};