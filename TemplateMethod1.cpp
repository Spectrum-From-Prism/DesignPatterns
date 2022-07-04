//有一套固定的表演流程，但是其中有若干个表演子流程受欢迎程度比较低，可进行这几个表演流程的表演创新
#include<iostream>
#if 1
class ZooShow {
public:
	void Show0(){
		std::cout << "show0" << std::endl;
	}
	void Show2() {
		std::cout << "show2" << std::endl;
	}
};
class ZooShowEx {
public:
	void Show1() {
		std::cout << "show1" << std::endl;
	}
	void Show3() {
		std::cout << "show3" << std::endl;
	}

};
#else if 2
class ZooShow {
public:
	ZooShow(int type = 1) :_type(type) {}
public:
	void Show() {
		show0();
		show1();
		show2();
		show3();
	}
private:
	void show0() {
		std::cout << _type << "show0" << std::endl;
	}
	void show1() {
		if (_type == 1) {
			std::cout << _type << "Show1" << std::endl;
		}
		else if (_type == 2) {
			std::cout << _type << "Show1" << std::endl;
		}
	}
	void Show2() {
		std::cout << "base Show2" << std::endl;
	}
	void show3() {
		if (_type == 1) {
			std::cout << _type << "Show3" << std::endl;
		}
		else if (_type == 2) {
			std::cout << _type << "Show3" << std::endl;
		}
	}
private:
	int _type;
};
#endif

int main() {
#if 1
	ZooShow *zs = new ZooShow;
	ZooShowEx *zs1 = new ZooShowEx;
	zs->Show0();
	zs1->Show1();
	zs->Show2();
	zs1->Show3();
#else if 2
	ZooShow* zs = new ZooShow(1);
	zs->show();
#endif
	return 0;
}