  //实现一个导出数据的接口，让客户选择数据的导出方式
#include<string>
//实现导出数据的接口，导出数据的格式包含xml，json，文本格式txt，后面可能扩展exe
class IExport {
public:
	virtual bool Export(const std::string &data) = 0;
	virtual ~IExport() {}
};
class ExportXml :public IExport{
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
int main() {
	std::string choose/* = */;
	//凡是要调用该功能都得调用如下代码，导致重复代码多（复用！=复制）
	//若只选择一个输出，容易把代码写死（如只new txt），会工程中散布各种不同版本导出方式
	if (choose == "txt") {
		IExport* e = new ExportTxt();
		e->Export("hello world");
	}
	else if (choose == "json") {
		IExport* e = new ExportJson();
		e->Export("hello world");
	}
	else if (choose == "xml") {
		IExport* e = new ExportXml();
		e->Export("hello world");
	}
}