//��ͨԱ�������۽����ۼƽ��𣬲��ž������֮�⻹���Ŷӽ���
//������ܻ���ӻ�����������ͬʱ������Բ�ͬ��ְλ������ͬ�Ľ������
//���۽���=�������۶�*4%
//�ۼƽ���=�ܵûؿ��*0.2%
//���Ž���=���������۶�-�������۶*1%
//���ۺ���Ĳ������ܻ����
class Context {
public:
	bool isMgr;
};
class Bonus {
public:
	double CalcBonus(Context &ctx) {
		double bonus = 0.0;
		bonus += CalcMonthBonus(ctx);
		bonus += CalcSumBonus(ctx);
		if (ctx.isMgr) {
			bonus += CalcGroupBonus(ctx);
		}
		return bonus;
	}
private:
	double CalcMonthBonus(Context &ctx) {
		double bonus/* = */;
		return bonus;
	}
	double CalcSumBonus(Context &ctx) {
		double bonus/* = */;
		return bonus;
	}
	double CalcGroupBonus(Context &ctx) {
		double bonus/* = */;
		return bonus;
	}
};
int main() {
	Context ctx;
	//����ctx
	Bonus* bonus = new Bonus;
	bonus->CalcBonus(ctx);
}