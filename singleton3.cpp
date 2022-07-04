#include<cstdlib>
#include<mutex>

class Singleton {
public:
	static Singleton* GetInstance() {//�ýӿڷ���һ������Ϊ������
		//std::lock_guard<std::mutex> lock(_mutex);//1���ô�����������̫�󣬶���̷߳���ʱ
		if (_instance == nullptr) {
			std::lock_guard<std::mutex> lock(_mutex);//2���ô�������û��if�жϣ������̷߳���ʱ���ظ�new
			if (_instance == nullptr) {///˫���
				_instance = new Singleton();//1.�����ڴ� 2.���ù��캯�� 3.��ֵָ��_instance
				///���ڶ��̻߳����£�cupָ��reorder��1->3->2 ==> ����Ұָ������
				//��ʱ_instance��=nullptr��ΪҰָ��(��δ�Գ�Ա�������г�ʼ������ʱ���ú��������������ܻ���ʵ������ڵĵ�ַ����ʱ���ܻᵼ�³���ı���)
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
	Singleton() {}//����
	Singleton(const Singleton& cpy) {}//��������
	Singleton& operator=(const Singleton&) {}
	static Singleton* _instance;
	static std::mutex _mutex;
};
Singleton* Singleton::_instance = nullptr;//��̬��Ա��Ҫ��ʼ��
std::mutex Singleton::_mutex;//��������ʼ��