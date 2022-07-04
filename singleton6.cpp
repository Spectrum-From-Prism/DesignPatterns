template<typename T>
class Singleton {
public:
	static T& GetInstance() {
		static T instance;
		//这里要初始化DesignPattern，需要调用DesignPattern构造函数，同时会调用父类
		return instance;
	}
protected:
	virtual ~Singleton() {}
	Singleton() {}//protected修饰构造函数，才能让别人继承
	//若构造函数为private，需要在该类中friend每一个子类
	Singleton(const Singleton&) {}
	Singleton& operator=(const Singleton&) {}
};
class DesignPattern :public Singleton<DesignPattern> {
	friend class Singleton<DesignPattern>;//friend能让Singleton<T>访问到DesignPattern构造函数
private:
	DesignPattern() {}
	DesignPattern(const DesignPattern&) {}
	DesignPattern& operator=(const DesignPattern&) {}
};

///子类调用GetInstance（）：子类构造函数，父类构造函数都需要
///避免new，必须将构造函数放在private or protected