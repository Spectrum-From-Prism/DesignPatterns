//������̣�1������Ҫ��������׼��3������Ҫ��Ŀ������׼��3��������Ҫ�ϰ���׼
#include<string>
class Context {
public:
	std::string name;
	int day;
};
class LeaveRequest {
public:
	//�����жϵ����ӣ�LeaveRequest���ò��ȶ�
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