#include<string>
class Context {
public:
	std::string name;
	int day;
};

class IHandler {
public:
	IHandler() {}
	virtual ~IHandler() {}
	void SetNextHandler(IHandler *next) {
		next = next;
	}
	//?㷨?Ǽ?
	bool Handle(const Context &ctx) {
		if (CanHandle(ctx)) {
			return HandleRequest(ctx);
		}
		else if (GetNextHandler()) {
			return GetNextHandler()->HandleRequest(ctx);
		}
		else {
			//err
		}
		return false;
	}
protected:
	virtual bool HandleRequest(const Context &ctx) = 0;
	virtual bool CanHandle(const Context &ctx) = 0;
	IHandler* GetNextHandler() {
		return next;
	}
private:
	IHandler *next;
};

class HandleByMainProgram :public IHandler {
protected:
	virtual bool HandleRequest(const Context& ctx) {
		//
		return true;
	}
	virtual bool CanHandle(const Context& ctx) {
		//
		return true;
	}
};
class HandleByProjMgr :public IHandler {
protected:
	virtual bool HandleRequest(const Context& ctx) {
		//
		return true;
	}
	virtual bool CanHandle(const Context& ctx) {
		//
		return true;
	}
};
class HandleByBoss :public IHandler {
protected:
	virtual bool HandleRequest(const Context& ctx) {
		//
		return true;
	}
	virtual bool CanHandle(const Context& ctx) {
		//
		return true;
	}
};
int main() {
	IHandler* h1 = new HandleByMainProgram();
	IHandler* h2 = new HandleByProjMgr();
	IHandler* h3 = new HandleByBoss();
	h1->SetNextHandler(h2);
	h2->SetNextHandler(h3);
	Context ctx;
	h1->Handle(ctx);
}