//ʵ��һ���������ݵĽӿڣ��ÿͻ�ѡ�����ݵĵ�����ʽ
#include<string>
//ʵ�ֵ������ݵĽӿڣ��������ݵĸ�ʽ����xml��json���ı���ʽtxt�����������չexe
class IExport {
public:
	virtual bool Export(const std::string &data) = 0;
	virtual ~IExport() {}
};
class ExportXml :public IExport {
public:
	virtual bool Export(const std::string &data) {
		//...xml
		return true;
	}
};
class ExportJson :public IExport {
public:
	virtual bool Export(const std::string &data) {
		//...json
		return true;
	}
};
class ExportTxt :public IExport {
public:
	virtual bool Export(const std::string &data) {
		//...txt
		return true;
	}
};

//�����෽���ӿ�
class IExportFactory {
public:
	virtual IExport* NewExport(/*...*/) = 0;
};
class ExportXmlFactory :public IExportFactory {
public:
	IExport* NewExport(/*...*/) {
		//��������������������������
		IExport* temp = new ExportXml(/*...*/);
		//����֮����ʲô����(����Ҫ�м�����д���)
		return temp;
	}
};
class ExportJsonFactory :public IExportFactory {
public:
	IExport* NewExport(/*...*/) {
		//��������������������������
		IExport* temp = new ExportJson;
		//����֮����ʲô����
		return temp;
	}
};
class ExportTxtFactory :public IExportFactory {
public:
	IExport* NewExport(/*...*/) {
		//��������������������������
		IExport* temp = new ExportTxt;
		//����֮����ʲô����
		return temp;
	}
};
class ExportData {
public:
	ExportData(IExportFactory* factory) :_factory(factory) {}
	~ExportData() {
		if (_factory) {
			delete _factory;
			_factory = nullptr;
		}
	}
	bool Export(const std::string& data) {
		//
		IExport* e = _factory->NewExport();
		e->Export(data);
		//�����̿��Գ������,������������
	}
private:
	//
	IExportFactory* _factory;
	//
};
int main() {
	ExportData ed(new ExportTxtFactory);//���ڴ�й©
	ed.Export("hello world");
	return 0;
}