#include<iostream>
#include"GameUsing.h"
#include<Windows.h>
#include "conio.h"
#include<ctime>

using namespace std;

int main()
{
	/***********************************************************************************************************************************/
																//初始化
	srand((unsigned int)time(NULL));

	struct Player PlayerData[1];
	struct PlayerEq PEq[1];

	//怪物名字、怪物血量、怪物最大血量、怪物基础攻击力、怪物技能轴、怪物等级、掉落经验值
	struct Monster MonsterData[] = { {"测试怪物",150,150,3,0,0,10},
									{"怪物A",10,10,1,0,0,1} };

	//分别为是否显示技能、技能名字、技能伤害计算数值、技能类型、技能CD、CDTime、技能消耗、技能等级、技能升级消耗、技能介绍
	struct SkillList SkillData[] = {
									 {1,"光剑劈砍★☆☆"	,1,   1, 0, 0, 1, 1, 0,"造成基础攻击100%伤害"},
									 {0,"突进斩击★★☆"	,1.2, 1, 0, 0, 2, 2, 40,"造成基础攻击120%伤害"},
									 {0,"混沌审判★★★"		,1.5, 1, 0, 0, 3, 3, 70,"造成基础攻击150%伤害"},

									 {0,"MK2自卫手枪★☆☆" ,3  , 0, 3, 0, 4 , 1, 10,"基础攻击力+3"},
									 {0,"MK4步枪★★☆"		,7  , 0, 4, 0, 8 , 2, 20,"基础攻击力+7"},
									 {0,"MK6轨道炮★★★"	,12 , 0, 6, 1, 15, 3, 50,"基础攻击力+12"},

									 {0,"热能爆破★☆☆"    ,2  , 1, 6, 1, 7,  1, 10,"造成基础攻击200%的伤害"},
									 {0,"核心溶解★★☆"    ,2.6, 1, 7, 0, 13,  2, 30,"造成基础攻击260%的伤害"},
									 {0,"等离子风暴★★★"	,3.5, 1, 8, 0, 20,  3, 60,"造成基础攻击350%的伤害"}
	};
	int len = sizeof SkillData / sizeof SkillData[0];

	struct SkillUseList SkillUseData[30];
	struct SkillUseList SkillLvUp[30];

	//分别为是否显示技能、技能名字、技能伤害计算数值、技能类型、技能CD、CDTime、技能消耗、技能等级、技能升级消耗、技能介绍
	struct SkillList SkillSptData[] = { {0,"紧急包扎★☆☆"		,3 , 2, 7, 4, 6, 1, 8,"回复玩家3点生命值"},
										{0,"创伤修复★★☆"		,6 , 2, 8, 3, 10, 2, 18,"回复玩家6点生命值"},
										{0,"医疗机器人★★★"	,10, 2, 8, 2, 15,3, 40,"回复玩家10点生命值"},

										{0,"招架★☆☆"			,2 , 3 ,4, 2, 5, 1, 0,"防御，使受到的伤害降低2点"},
										{0,"能量盾★★☆"		,5 , 3 ,5, 2, 8, 2, 15,"防御，使受到的伤害降低5点"},
										{0,"防御立场★★★"		,8 , 3 ,5, 1, 10,3, 30,"防御，使受到的伤害降低8点"},

										{0,"分神★☆☆"				,8 ,4,6 ,3,0,1,0,"回复玩家8点耐力值"},
										{0,"伺机而动★★☆"			,14,4,8 ,2,0,2,10,"回复玩家14点耐力值"},
										{0,"运筹帷幄★★★"			,22,4,10,1,0,3,25,"回复玩家22点耐力值"},

										{0,"电击枪★☆☆"			,4,5,5,3,6 ,1,0 ,"造成基础攻击力40%的伤害，50%的概率眩晕敌人"},
										{0,"闪光弹★★☆"			,6,5,6,2,10,2,20,"造成基础攻击力60%的伤害，60%的概率眩晕敌人"},
										{0,"能量干扰★★★"			,9,5,6,0,14,3,45,"造成基础攻击力90%的伤害，75%的概率眩晕敌人"},
	};
	int len2 = sizeof SkillSptData / sizeof SkillSptData[0];
	struct SkillUseList SkillSptUseData[30];

	//是否显示装备、装备名字、是否已装备、装备类型、装备类型名称、装备数值、装备介绍
	struct Equipment Eq[] = { {1,"剑",0,0,"武器",5,"攻击力+5"},
							  {1,"安全帽",0,1,"头盔",10,"最大生命值+4，耐力+10"},
							  {1,"防弹衣",0,2,"胸甲",10,"最大生命值+10，耐力+10"},
							  {1,"护腿",0,3,"护腿",10,"最大生命值+6，耐力+10"},
							  {1,"长筒靴子",0,4,"靴子",10,"最大生命值+4，耐力+10"},
							  {1,"应急起搏器",0,5,"护符",0,"获得一次重生机会，效果触发后消失"}
	};
	int len3 = sizeof Eq / sizeof Eq[0];

	//是否显示物品、物品名字、物品数量、物品类型、物品数值、物品介绍
	struct Item item[] = { {1,"血瓶",1,1,5,8,"回复5点生命值"},
							{0,"耐力药水",0,2,6,4,"回复6点耐力值"},
							{0,"能量盾",0,3,3,6,"护盾值+3"},
							{0,"力量",0,4,4,6,"下回合额外伤害+4"}
	};
	int len4 = sizeof item / sizeof item[0];

	struct Bag PlayerBag[60];

	//初始化玩家数据
	{
		PlayerData[0].PlayerExp = 190;
		PlayerData[0].gold = 80;
		PlayerData[0].PlayerLv = 1;
		PlayerData[0].PlayerMaxH = 10;
		PlayerData[0].PlayerH = 10;
		PlayerData[0].PlayerAtk = 2;
		PlayerData[0].PlayerName = "Player";
		PlayerData[0].DiceNum = 10;
		PlayerData[0].PlayerMaxSta = 10;
		PlayerData[0].PlayerStamina = 10;
		PlayerData[0].DiceEf = 1;
		PlayerData[0].ExDamage = 0;
		PlayerData[0].PlayerDef = 0;
		PlayerData[0].IfFirstDead = 0;
		PlayerData[0].SkillPoint = 150;
	}

	//统计物品装备数量
	int BagEqNum = NumOfEq(PlayerBag, Eq, len3);
	int BagItemNum = 0;
	BagItemNum = NumOfItem(PlayerBag, item, len4, BagItemNum);

	//往玩家背包写入物品装备
	CinBagEq(PlayerBag, Eq, BagEqNum);
	CinBagItem(PlayerBag, item, BagItemNum, len4);

	//写入技能
	CinSkillUse(SkillData, SkillUseData, len);
	CinSkillSptUse(SkillSptData, SkillSptUseData, len2);
	
	/****************************************************************************************************************************************/
																/*此处为分割线*/
																 /*开始游戏*/
	PlayerLvUp(PlayerData);

	BagItemNum = Shop(PlayerData,PlayerBag, item, len4, BagItemNum);

	ShowPlayerData(PlayerData, PlayerBag, Eq, PEq, SkillData,SkillSptData,SkillUseData, SkillSptUseData,SkillLvUp,len, len2, BagEqNum);

	cout << "\n遭遇了怪物！\n\n" << endl;
	system("pause");
	system("cls");

	int MonNum = 0;
	BattleSystem(PlayerData, SkillData, SkillUseData, SkillSptData, SkillSptUseData, SkillLvUp, MonsterData,
		PlayerBag,item,Eq,PEq,MonNum, len ,len2, BagItemNum, BagEqNum);

	cout << "Game End" << endl;

	system("pause");

	return 0;
}