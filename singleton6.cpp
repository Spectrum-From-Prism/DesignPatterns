template<typename T>
class Singleton {
public:
	static T& GetInstance() {
		static T instance;
		//����Ҫ��ʼ��DesignPattern����Ҫ����DesignPattern���캯����ͬʱ����ø���
		return instance;
	}
protected:
	virtual ~Singleton() {}
	Singleton() {}//protected���ι��캯���������ñ��˼̳�
	//�����캯��Ϊprivate����Ҫ�ڸ�����friendÿһ������
	Singleton(const Singleton&) {}
	Singleton& operator=(const Singleton&) {}
};
class DesignPattern :public Singleton<DesignPattern> {
	friend class Singleton<DesignPattern>;//friend����Singleton<T>���ʵ�DesignPattern���캯��
private:
	DesignPattern() {}
	DesignPattern(const DesignPattern&) {}
	DesignPattern& operator=(const DesignPattern&) {}
};

///�������GetInstance���������๹�캯�������๹�캯������Ҫ
///����new�����뽫���캯������private or protected