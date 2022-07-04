  //ʵ��һ���������ݵĽӿڣ��ÿͻ�ѡ�����ݵĵ�����ʽ
#include<string>
//ʵ�ֵ������ݵĽӿڣ��������ݵĸ�ʽ����xml��json���ı���ʽtxt�����������չexe
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
	//����Ҫ���øù��ܶ��õ������´��룬�����ظ�����ࣨ���ã�=���ƣ�
	//��ֻѡ��һ����������װѴ���д������ֻnew txt�����Ṥ����ɢ�����ֲ�ͬ�汾������ʽ
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