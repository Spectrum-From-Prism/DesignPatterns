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
	IExportFactory() {
		_export = nullptr;
	}
	virtual ~IExportFactory() {
		if (_export) {
			delete _export;
			_export = nullptr;
		}
	}
	bool Export(const std::string& data) {
		if (_export == nullptr) {
			_export = NewExport();
		}
		return _export->Export(data);
	}
protected:
	//�����ิд��������Ĺ���
	virtual IExport* NewExport(/*...*/) = 0;
private:
	IExport* _export;
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
int main() {
	IExportFactory* factory = new ExportTxtFactory();
	factory->Export("hello world");
	return 0;
}