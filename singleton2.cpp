#include<cstdlib>//#include<stdlib.h>
class Singleton {
public:
	//��̬��Ա�������þ�̬����
	static Singleton* GetInstance() {
		if (_instance == nullptr) {
			_instance = new Singleton();
			atexit(Destructor);//C �⺯��
			//������������ֹʱ������ָ���ĺ������������κεط�ע����ֹ�������������ڳ�����ֹ��ʱ�򱻵��á�
		}
		return _instance;
	}
	~Singleton() {}//�����˳���ʱ����������������������ʱatexit����ִ�е��õ�����������ȥ
private:
	static void Destructor() {
		if (nullptr != _instance) {
			delete _instance;
			_instance = nullptr;
		}
	}
	Singleton();//����
	Singleton(const Singleton &cpy);//��������
	Singleton& operator=(const Singleton&) {}
	static Singleton* _instance;
};
///δ������̷߳�������
///������ʹ�� �ڲ��ࡢ����ָ�����������ʱ�����̰߳�ȫ����