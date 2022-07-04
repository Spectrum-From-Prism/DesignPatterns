#include<mutex>
//c++11
#include<atomic>
// jave ʹ�ùؼ���volatile���߱�������Ҫ����cpu reorder
class Singleton {
public:
	//����GetInstance()->new ����Żᱻ���� :����ģʽ��lazy load��
	static Singleton* GetInstance() {
		Singleton* tmp = _instance.load(std::memory_order_relaxed);
		std::atomic_thread_fence(std::memory_order_acquire);//��ȡ�ڴ�����
		if (tmp == nullptr) {
			std::lock_guard<std::mutex> lock(_mutex);
			tmp = _instance.load(std::memory_order_relaxed);
			if (tmp == nullptr) {
				tmp = new Singleton;
				std::atomic_thread_fence(std::memory_order_release);//�ͷ��ڴ����� �ڸ������ڶ��������cpu reorder
				_instance.store(tmp, std::memory_order_relaxed);//new��֮����ص�ԭ������ȥ
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
	static std::atomic<Singleton*> _instance;//ԭ��ģ����
	static std::mutex _mutex;
};
std::atomic<Singleton*> Singleton::_instance = nullptr;//��̬��Ա��Ҫ��ʼ��
std::mutex Singleton::_mutex;//��������ʼ��

///�����cpu reorder������ ��̫������