class Context {
public:
	bool isMgr;
};
//试着从职责出发，将职责抽象出来
class CalcBonus {
public:
	CalcBonus(CalcBonus* c = nullptr) :cc(c) {}
	virtual double Calc(Context &ctx) {
		return 0.0;//基本工资
	}
	virtual ~CalcBonus() {}
protected:
	//组合自己
	CalcBonus* cc;
};
class CalcMonthBonus :public CalcBonus {
public:
	CalcMonthBonus(CalcBonus* c) :CalcBonus(c) {}
	virtual double Calc(Context &ctx) {
		double mbonus /*= 计算流程忽略*/;
		return mbonus + cc->Calc(ctx);
	}
};
class CalcSumBonus :public CalcBonus {
public:
	CalcSumBonus(CalcBonus* c) :CalcBonus(c) {}
	virtual double Calc(Context &ctx) {
		double sbonus/*= 计算流程忽略*/;
		return sbonus + cc->Calc(ctx);
	}
};
class CalcGroupBonus :public CalcBonus {
public:
	CalcGroupBonus(CalcBonus* c) :CalcBonus(c) {}
	virtual double Calc(Context &ctx) {
		double gbonus/*= 计算流程忽略*/;
		return gbonus + cc->Calc(ctx);
	}
};
class CalcCycleBonus :public CalcBonus {
public:
	CalcCycleBonus(CalcBonus* c) :CalcBonus(c) {}
	virtual double Calc(Context &ctx) {
		double cbonus/*= 计算流程忽略*/;
		return cbonus + cc->Calc(ctx);
	}
};
int main() {
	//1.普通员工
	Context ctx1;
	CalcBonus *base = new CalcBonus();
	//下面顺序无关
	CalcBonus *cb1 = new CalcMonthBonus(base);
	CalcBonus *cb2 = new CalcSumBonus(cb1);
	cb2->Calc(ctx1);//迭代实现
	//2.部门经理
	Context ctx2;
	CalcBonus *cb3 = new CalcGroupBonus(cb2);
	cb3->Calc(ctx2);
}