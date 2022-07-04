//实现一个导出数据的接口，让客户选择数据的导出方式
#include<string>
//实现导出数据的接口，导出数据的格式包含xml，json，文本格式txt，后面可能扩展exe
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

//工厂类方法接口
class IExportFactory {
public:
	virtual IExport* NewExport(/*...*/) = 0;
};
class ExportXmlFactory :public IExportFactory {
public:
	IExport* NewExport(/*...*/) {
		//可能有其他操作，或者许多参数
		IExport* temp = new ExportXml(/*...*/);
		//可能之后有什么操作(如需要中间类进行创建)
		return temp;
	}
};
class ExportJsonFactory :public IExportFactory {
public:
	IExport* NewExport(/*...*/) {
		//可能有其他操作，或者许多参数
		IExport* temp = new ExportJson;
		//可能之后有什么操作
		return temp;
	}
};
class ExportTxtFactory :public IExportFactory {
public:
	IExport* NewExport(/*...*/) {
		//可能有其他操作，或者许多参数
		IExport* temp = new ExportTxt;
		//可能之后有什么操作
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
		//该流程可以抽象出来,到工厂基类中
	}
private:
	//
	IExportFactory* _factory;
	//
};
int main() {
	ExportData ed(new ExportTxtFactory);//有内存泄漏
	ed.Export("hello world");
	return 0;
}