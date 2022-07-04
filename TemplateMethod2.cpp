#include<iostream>
class ZooShow {
public:
	//封装固定流程
	void Show() {
		Show0();
		Show1();
		Show2();
		Show3();
	}
protected:
	//子流程使用protected保护起来，不被客户调用但允许子类扩展
	virtual void Show0() {
		std::cout << "show0" << std::endl;
	}
	virtual void Show2() {
		std::cout << "show2" << std::endl;
	}
	virtual void Show1() {}
	virtual void Show3() {}
};
class ZooShowEx :public ZooShow {
protected:
	virtual void Show1() {
		std::cout << "show1" << std::endl;
	}
	virtual void Show3() {
		std::cout << "show3" << std::endl;
	}
	virtual void Show4() {
		//
	}
};
class ZooShowEx1 :public ZooShow {
protected:
	virtual void Show0() {
		std::cout << "show0" << std::endl;
	}
	virtual void Show2() {
		std::cout << "show2" << std::endl;
	}
};
class ZooShowEx2 :public ZooShow {
protected:
	virtual void Show1() {
		std::cout << "show1" << std::endl;
	}
	virtual void Show2() {
		std::cout << "show2" << std::endl;
	}
};
int main() {
	ZooShow* zs = new ZooShowEx;
	ZooShow* zs1 = new ZooShowEx1;
	ZooShow* zs2 = new ZooShowEx2;
	zs->Show();
	return 0;
}