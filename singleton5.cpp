//effective c++ 作者版本
//c++11 magic static 特性:如果当变量在初始化的时候，并发同时进入声明语句，并发线程将会阻塞等待初始化结束
class Singleton {
public:
	~Singleton(){}
	static Singleton& GetInstance() {
		static Singleton instance;
		return instance;
	}
private:
	Singleton() {}
	Singleton(const Singleton&) {}
	Singleton& operator=(const Singleton&) {}
};
/*优点：
1、利用静态局部变量特性，延迟加载；
2、利用静态局部变量特性，系统自动回收内存，自动调用析构函数；
3、静态局部变量初始化时，没有new操作带来的cpu指令reorder操作(当相邻的两行代码没有关联的时候，CPU可能会进行指令重排序，对程序进行优化执行。)；
4、c++11静态局部变量初始化时，具备线程安全
*/