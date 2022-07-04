//普通员工有销售奖金，累计奖金，部门经理除此之外还有团队奖金；
//后面可能会添加环比增长奖金，同时可能针对不同的职位产生不同的奖金组合
//销售奖金=当月销售额*4%
//累计奖金=总得回款额*0.2%
//部门奖金=（当月销售额-上月销售额）*1%
//销售后面的参数可能会调整
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
	//设置ctx
	Bonus* bonus = new Bonus;
	bonus->CalcBonus(ctx);
}