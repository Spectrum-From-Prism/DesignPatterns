//effective c++ ���߰汾
//c++11 magic static ����:����������ڳ�ʼ����ʱ�򣬲���ͬʱ����������䣬�����߳̽��������ȴ���ʼ������
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
/*�ŵ㣺
1�����þ�̬�ֲ��������ԣ��ӳټ��أ�
2�����þ�̬�ֲ��������ԣ�ϵͳ�Զ������ڴ棬�Զ���������������
3����̬�ֲ�������ʼ��ʱ��û��new����������cpuָ��reorder����(�����ڵ����д���û�й�����ʱ��CPU���ܻ����ָ�������򣬶Գ�������Ż�ִ�С�)��
4��c++11��̬�ֲ�������ʼ��ʱ���߱��̰߳�ȫ
*/