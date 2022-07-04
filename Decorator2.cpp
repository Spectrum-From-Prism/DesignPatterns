class Context {
public:
	bool isMgr;
};
//���Ŵ�ְ���������ְ��������
class CalcBonus {
public:
	CalcBonus(CalcBonus* c = nullptr) :cc(c) {}
	virtual double Calc(Context &ctx) {
		return 0.0;//��������
	}
	virtual ~CalcBonus() {}
protected:
	//����Լ�
	CalcBonus* cc;
};
class CalcMonthBonus :public CalcBonus {
public:
	CalcMonthBonus(CalcBonus* c) :CalcBonus(c) {}
	virtual double Calc(Context &ctx) {
		double mbonus /*= �������̺���*/;
		return mbonus + cc->Calc(ctx);
	}
};
class CalcSumBonus :public CalcBonus {
public:
	CalcSumBonus(CalcBonus* c) :CalcBonus(c) {}
	virtual double Calc(Context &ctx) {
		double sbonus/*= �������̺���*/;
		return sbonus + cc->Calc(ctx);
	}
};
class CalcGroupBonus :public CalcBonus {
public:
	CalcGroupBonus(CalcBonus* c) :CalcBonus(c) {}
	virtual double Calc(Context &ctx) {
		double gbonus/*= �������̺���*/;
		return gbonus + cc->Calc(ctx);
	}
};
class CalcCycleBonus :public CalcBonus {
public:
	CalcCycleBonus(CalcBonus* c) :CalcBonus(c) {}
	virtual double Calc(Context &ctx) {
		double cbonus/*= �������̺���*/;
		return cbonus + cc->Calc(ctx);
	}
};
int main() {
	//1.��ͨԱ��
	Context ctx1;
	CalcBonus *base = new CalcBonus();
	//����˳���޹�
	CalcBonus *cb1 = new CalcMonthBonus(base);
	CalcBonus *cb2 = new CalcSumBonus(cb1);
	cb2->Calc(ctx1);//����ʵ��
	//2.���ž���
	Context ctx2;
	CalcBonus *cb3 = new CalcGroupBonus(cb2);
	cb3->Calc(ctx2);
}