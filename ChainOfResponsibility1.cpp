//请假流程，1天内需要主程序批准，3天内需要项目经理批准，3天以上需要老板批准
#include<string>
class Context {
public:
	std::string name;
	int day;
};
class LeaveRequest {
public:
	//随着判断的增加，LeaveRequest类变得不稳定
	bool HandleRequest(const Context &ctx) {
		if (ctx.day <= 3) {
			HandleByMainProgram(ctx);
		}
		else if (ctx.day <= 10) {
			HandleByProjMgr(ctx);
		}
		else {
			HandleByBoss(ctx);
		}
	}
private:
	bool HandleByMainProgram(const Context &ctx) {}
	bool HandleByProjMgr(const Context &ctx) {}
	bool HandleByBoss(const Context &ctx) {}
};