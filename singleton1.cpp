class Singleton {
public:
	static Singleton * GetInstance() {//�ú���ָ��Ҳֻ��һ��
		if (_instance == nullptr) {
			_instance = new Singleton();///�����ڴ�й¶
			///�����ڴ�������ڳ���ر�ʱ����������ڴ���ܲ��ᱻ�ͷŵ�����linux�е�shmget����Ĺ����ڴ棬������̽����޹أ�
		}
		return _instance;
	}
private:
	Singleton() {}//����
	Singleton(const Singleton& clone) {}//��������
	Singleton& operator=(const Singleton&) {}
	static Singleton* _instance;//���ڸ�����˵Ψһ����̬��Ա��Ҫ��ʼ��
	///���ھ�̬ȫ�������ڳ���ر�ʱ����������ڴ�ᱻ�ͷŵ���
};