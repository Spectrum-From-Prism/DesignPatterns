#include<iostream>
class ZooShow {
public:
	//��װ�̶�����
	void Show() {
		Show0();
		Show1();
		Show2();
		Show3();
	}
protected:
	//������ʹ��protected���������������ͻ����õ�����������չ
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