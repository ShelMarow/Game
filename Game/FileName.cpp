#include<iostream>
#include"GameUsing.h"
#include<Windows.h>
#include "conio.h"
#include<ctime>
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

using namespace std;

//extern struct Player
//{
//	string PlayerName = "Player";	//玩家名字
//	int gold = 0;			//货币
//	int SkillPoint = 0;		//技能点
//	int PlayerH = 10;		//玩家血量
//	int PlayerMaxH = 10;		//玩家最大血量
//	int PlayerExp = 0;		//玩家经验值
//	int PlayerLv = 1;		//玩家等级
//	int PlayerStamina = 10;	//玩家耐力
//	int PlayerMaxSta = 10;	//玩家最大耐力值
//	int PlayerAtk = 2;		//玩家攻击力
//	int PlayerDef = 0;		//玩家防御力
//	int IfBattle = 0;		//玩家是否在战斗
//	int DiceNum = 6;		//骰子数量
//	int DiceEf = 1;			//骰子效果
//	int DiceUse = 0;		//骰子使用次数
//	int DicePoint = 0;		//骰子点数
//	int ExDamage = 0;		//额外造成伤害
//	int DeBuff = 0;			//负面效果
//	int Buff = 0;
//	int IfFirstDead = 0;	//检测是否首次受到致命伤害
//};
//
//extern struct PlayerEq
//{
//	int hand = 0;
//	int head = 0;
//	int cheast = 0;
//	int legging = 0;
//	int boot = 0;
//	int other = 0;
//	string handS = "空";
//	string headS = "空";
//	string cheastS = "空";
//	string leggingS = "空";
//	string bootS = "空";
//	string otherS = "空";
//};
//
//extern struct Monster
//{
//	string MonsterName;	//怪物名字
//	int MonsterH;		//怪物血量
//	int MonsterMaxH;	//怪物最大血量
//	int MonsterAtk;		//怪物基础攻击力
//	int MonsterSkill;	//怪物技能轴
//	int MonLv;			//怪物等级
//	int MonExp;			//掉落经验值
//	int Debuff;
//};
//
//extern struct SkillList
//{
//	int ShowSkill;			//是否展示技能
//	string SkillName;
//	double SkillUse;			//技能使用数值
//	int SkillType;
//	int SkillCD;
//	int SkillCDTime;			//冷却计时器
//	int SkillCost;
//	int SkillLv;
//	int SkillPC;				//技能升级消耗
//	string SkillInfo;		//技能信息介绍
//
//};
//
//extern struct SkillUseList
//{
//	string SkillName = "Unnamed";
//	double SkillUse = 0;
//	int SkillType = 0;			//技能类型（0为加算攻击，1为乘算攻击,2为增加防御类，3为回复血量类技能，4为回复耐力类技能，5为概率眩晕类技能）
//	int SkillCD = 0;
//	int SkillCDTime = 0;
//	int SkillCost = 0;
//	int ShowSkill = 0;
//	int SkillLv = 0;
//	int SkillPC;
//	string SkillInfo = "No Info";
//};
//
//extern struct Equipment
//{
//	int ShowEq = 0;					//是否显示装备
//	string EqName = "Unnamed";
//	int IfEq = 0;					//是否已装备
//	int EqType = 0;					//装备类型（武器0，头盔1，胸甲2，护腿3，靴子4，护符5）
//	string EqTypeName = "Unknow";	//装备类型名称
//	int EqUse = 0;					//装备数值
//	string EqInfo = "No Info";
//};
//
//extern struct Item
//{
//	int ShowItem = 0;
//	string ItemName = "Unnamed";
//	int ItemNum = 0;
//	int ItemType = 0;			//物品类型:0为不可消耗的道具、1为血量消耗类物品、2为耐力消耗类物品、3为护甲消耗类物品、4为伤害消耗类物品
//	int ItemUse = 0;
//	int cost = 0;				//价格
//	string ItemInfo = "No Info";
//};
//
//extern struct Bag
//{
//	Item BagItem;
//	Equipment Eq;
//};

void PlayerLvUp(Player PlayerData[])
{
	int a;
	int b = PlayerData[0].PlayerLv;
	if (PlayerData[0].PlayerLv < 6)
	{
		for (int i = 0; i < 5; i++)
		{
			if (PlayerData[0].PlayerExp >= (PlayerData[0].PlayerLv * (PlayerData[0].PlayerLv + 10) - 1))
			{
				a = PlayerData[0].PlayerExp - (PlayerData[0].PlayerLv * (PlayerData[0].PlayerLv + 10) - 1);
				PlayerData[0].PlayerLv++;
				PlayerData[0].PlayerExp = a;
				PlayerData[0].PlayerMaxH += 2;
				PlayerData[0].PlayerMaxSta += 4;
				if (PlayerData[0].PlayerLv == 2 || PlayerData[0].PlayerLv == 4 || PlayerData[0].PlayerLv == 6)
				{
					PlayerData[0].PlayerAtk++;
				}
			}
		}
		if (PlayerData[0].PlayerLv > b)
		{
			cout << endl << "玩家等级提升!!!\n\n等级: " << PlayerData[0].PlayerLv << endl << endl
				<< "最大生命值提升至 " << PlayerData[0].PlayerMaxH
				<< "    最大耐力提升至 " << PlayerData[0].PlayerMaxSta
				<< "    攻击力提升至 " << PlayerData[0].PlayerAtk << endl << endl;
			system("pause");
			system("cls");
		}
	}
}

void PrintHealh(struct Player PlayerData[], struct Monster MonsterData[], int num)  //打印血量和基础信息
{
	if (MonsterData[num].MonsterMaxH <= 50)
	{
		cout << MonsterData[num].MonsterName << endl
			<< "生命值: " << MonsterData[num].MonsterH
			<< "/" << MonsterData[num].MonsterMaxH << endl;
		for (int b = 0; b < MonsterData[num].MonsterMaxH - 1; b++)
		{
			cout << "══";
		}
		cout << "═╬ ╲" << endl;
		for (int i = 0; i < MonsterData[num].MonsterH; i++)
		{
			cout << "■";
		}
		for (int j = 0; j < MonsterData[num].MonsterMaxH - MonsterData[num].MonsterH; j++)
		{
			cout << "□";
		}
		cout << " ╬" << endl;
		for (int b = 0; b < MonsterData[num].MonsterMaxH; b++)
		{
			cout << "══";
		}
		cout << "═╣" << endl;
	}
	else
	{
		double MaxH = MonsterData[num].MonsterMaxH;
		double H = MonsterData[num].MonsterH;
		int PH = 50 * (H / MaxH);
		cout << MonsterData[num].MonsterName << endl
			<< "生命值: " << MonsterData[num].MonsterH
			<< "/" << MonsterData[num].MonsterMaxH << endl;
		for (int b = 0; b < 49; b++)
		{
			cout << "══";
		}
		cout << "═╬ ╲" << endl;
		for (int i = 0; i < PH; i++)
		{
			cout << "■";
		}
		for (int j = 0; j < 50 - PH; j++)
		{
			cout << "□";
		}
		cout << " ╬" << endl;
		for (int b = 0; b < 50; b++)
		{
			cout << "══";
		}
		cout << "═╣" << endl;
	}
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;

	cout << PlayerData->PlayerName << " 等级" << PlayerData[0].PlayerLv << endl
		<< "生命值: " << PlayerData[0].PlayerH << "/" << PlayerData[0].PlayerMaxH
		<< "\t" << "耐力值:" << PlayerData[0].PlayerStamina << "/" << PlayerData[0].PlayerMaxSta
		<< "   玩家防御力: " << PlayerData[0].PlayerDef << endl;

	for (int h = 0; h < PlayerData[0].PlayerMaxH - 1; h++)
	{
		cout << "══";
	}
	cout << "═╬ ╲" << endl;
	for (int i = 0; i < PlayerData[0].PlayerH; i++)
	{
		cout << "■";
	}
	for (int j = 0; j < PlayerData[0].PlayerMaxH - PlayerData[0].PlayerH; j++)
	{
		cout << "□";
	}
	cout << " ╬" << endl;
	for (int b = 0; b < PlayerData[0].PlayerMaxH; b++)
	{
		cout << "══";
	}
	cout << "═╣" << endl;
	/*测试用代码  */
	/*cout << "玩家攻击力:" << PlayerData[0].PlayerAtk << " * " << PlayerData[0].DiceEf
		<< " + " << PlayerData[0].ExDamage << endl;*/
}

void ShakeScM(struct Player PlayerData[], struct Monster MonsterData[], int num, int Da)
{
	for (int i = 0; i < 2; i++)
	{
		if (MonsterData[num].MonsterMaxH < Da)
		{
			Da = MonsterData[num].MonsterMaxH;
		}
		Sleep(380);
		system("cls");
		cout << "你的回合<<" << endl << endl;
		if (MonsterData[num].MonsterMaxH <= 50)
		{
			cout << MonsterData[num].MonsterName << endl
				<< "生命值: " << MonsterData[num].MonsterH
				<< "/" << MonsterData[num].MonsterMaxH << endl;
			for (int b = 0; b < MonsterData[num].MonsterMaxH - 1; b++)
			{
				cout << "══";
			}
			cout << "═╬ ╲" << endl;
			for (int i = 0; i < MonsterData[num].MonsterH + Da; i++)
			{
				cout << "■";
			}
			for (int j = 0; j < MonsterData[num].MonsterMaxH - MonsterData[num].MonsterH - Da; j++)
			{
				cout << "□";
			}
			cout << " ╬" << endl;
			for (int b = 0; b < MonsterData[num].MonsterMaxH; b++)
			{
				cout << "══";
			}
			cout << "═╣" << endl;
		}
		else
		{
			int MaxH = MonsterData[num].MonsterMaxH;
			int H = MonsterData[num].MonsterH;
			int PH = 50 * (H + Da) / MaxH;
			int PH2 = 50 - PH;
			cout << MonsterData[num].MonsterName << endl
				<< "生命值: " << MonsterData[num].MonsterH
				<< "/" << MonsterData[num].MonsterMaxH << endl;
			for (int b = 0; b < 49; b++)
			{
				cout << "══";
			}
			cout << "═╬ ╲" << endl;
			for (int i = 0; i < PH; i++)
			{
				cout << "■";
			}
			for (int j = 0; j < PH2; j++)
			{
				cout << "□";
			}
			cout << " ╬" << endl;
			for (int b = 0; b < 50; b++)
			{
				cout << "══";
			}
			cout << "═╣" << endl;
		}
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;

		cout << PlayerData[0].PlayerName << " 等级" << PlayerData[0].PlayerLv << endl
			<< "生命值: " << PlayerData[0].PlayerH << "/" << PlayerData[0].PlayerMaxH
			<< "\t" << "耐力值:" << PlayerData[0].PlayerStamina << "/" << PlayerData[0].PlayerMaxSta
			<< "   玩家防御力: " << PlayerData[0].PlayerDef << endl;
		for (int h = 0; h < PlayerData[0].PlayerMaxH - 1; h++)
		{
			cout << "══";
		}
		cout << "═╬ ╲" << endl;
		for (int i = 0; i < PlayerData[0].PlayerH; i++)
		{
			cout << "■";
		}
		for (int j = 0; j < PlayerData[0].PlayerMaxH - PlayerData[0].PlayerH; j++)
		{
			cout << "□";
		}
		cout << " ╬" << endl;
		for (int h = 0; h < PlayerData[0].PlayerMaxH; h++)
		{
			cout << "══";
		}
		cout << "═╣" << endl;

		Sleep(380);
		system("cls");
		cout << "你的回合<<" << endl << endl;
		PrintHealh(PlayerData, MonsterData, num);
	}
}

void HealthConrtol(struct Player PlayerData[], struct Monster MonsterData[])				//血量控制
{
	if (PlayerData[0].PlayerH > PlayerData[0].PlayerMaxH)
	{
		PlayerData[0].PlayerH = PlayerData[0].PlayerMaxH;
	}
	else if (PlayerData[0].PlayerH < 0)
	{
		PlayerData[0].PlayerH = 0;
	}
	if (MonsterData[0].MonsterH > MonsterData[0].MonsterMaxH)
	{
		MonsterData[0].MonsterH = MonsterData[0].MonsterMaxH;
	}
	else if (MonsterData[0].MonsterH < 0)
	{
		MonsterData[0].MonsterH = 0;
	}
}

void StaminaConrtol(struct Player PlayerData[]) //玩家耐力控制
{
	if (PlayerData[0].PlayerStamina >= PlayerData[0].PlayerMaxSta)
	{
		PlayerData[0].PlayerStamina = PlayerData[0].PlayerMaxSta;
	}
	else if (PlayerData[0].PlayerStamina <= 0)
	{
		PlayerData[0].PlayerStamina = 0;
	}
}

void gotoxy(int x, int y)
{
	COORD pos;
	pos.X = x;             //横坐标
	pos.Y = y;            //纵坐标
	SetConsoleCursorPosition(hOut, pos);
}

int NumOfItem(struct Bag PlayerBag[], struct Item item[], int len4, int BagItemNum)		//统计展示的物品数量
{
	int ShowItemNum = 0;
	for (int i = 0; i < len4; i++)
	{
		if (item[i].ShowItem == 1)
		{
			ShowItemNum++;
		}
	}
	BagItemNum += ShowItemNum;
	return BagItemNum;
}

int NumOfEq(Bag PlayerBag[], struct Equipment Eq[], int len3)		//统计展示的装备数量
{
	int EqNum = 0;
	for (int i = 0; i < len3; i++)
	{
		if (Eq[i].ShowEq == 1)
		{
			EqNum++;
		}
	}
	return EqNum;
}

void CinBagItem(Bag PlayerBag[], Item item[], int BagItemNum, int len4)	//将物品写入背包
{
	int PBItemNum = 0;
	for (int i = 0; i < BagItemNum; i++)
	{
		if (PlayerBag[i].BagItem.ShowItem == 1)
		{
			PBItemNum++;
		}
	}
	int j = 0;
	for (int i = 0; i < len4; i++)					//将展示值为1的物品写入背包
	{
		if (item[i].ShowItem == 1)
		{
			PlayerBag[PBItemNum + j].BagItem.ItemName = item[i].ItemName;
			PlayerBag[PBItemNum + j].BagItem.ItemType = item[i].ItemType;
			PlayerBag[PBItemNum + j].BagItem.ItemNum = item[i].ItemNum;
			PlayerBag[PBItemNum + j].BagItem.ItemUse = item[i].ItemUse;
			PlayerBag[PBItemNum + j].BagItem.ItemInfo = item[i].ItemInfo;
			PlayerBag[PBItemNum + j].BagItem.ShowItem = item[i].ShowItem;
			PlayerBag[PBItemNum + j].BagItem.cost = item[i].cost;
			item[i].ItemNum = 0;
			item[i].ShowItem = 0;
			j++;
		}
	}
}

int ShowBattleBagItem(Player PlayerData[], Bag PlayerBag[], Item item[], Monster MonsterData[], int BagItemNum, int MonNum)		//打印背包物品列表
{
	cout << endl << "              |输入“0”返回上个界面|" << endl
		<< "              |---------------------|" << endl << endl;
	if (BagItemNum > 0)
	{
		for (int j = 0; j < BagItemNum; j++)
		{
			cout << " |物品 " << j + 1 << ": " << PlayerBag[j].BagItem.ItemName;
			cout << "\t  类型: " << ((PlayerBag[j].BagItem.ItemType == 0) ? "道具" : "消耗品") << "    "
				<< "剩余: " << PlayerBag[j].BagItem.ItemNum << endl;
			cout << " |--------------------------------------------------|" << endl
				<< " |INFO: " << PlayerBag[j].BagItem.ItemInfo << endl << endl << endl;
		}

		int ItemSelect;
		ItemSelect = _getch();

		if (PlayerBag[ItemSelect - 49].BagItem.ItemType == 1 && ItemSelect - 49 < BagItemNum)
		{
			PlayerData[0].PlayerH += PlayerBag[ItemSelect - 49].BagItem.ItemUse;
			PlayerBag[ItemSelect - 49].BagItem.ItemNum--;
			HealthConrtol(PlayerData, MonsterData);
			system("cls");
			cout << "你的回合<<" << endl << endl;
			PrintHealh(PlayerData, MonsterData, MonNum);
			cout << endl << PlayerData[0].PlayerName << "使用了 " << PlayerBag[ItemSelect - 49].BagItem.ItemName
				<< " 生命值回复了 " << PlayerBag[ItemSelect - 49].BagItem.ItemUse << " 点" << endl << endl;

			system("pause");
		}
		else if (PlayerBag[ItemSelect - 49].BagItem.ItemType == 2 && ItemSelect - 49 < BagItemNum)
		{
			PlayerData[0].PlayerStamina += PlayerBag[ItemSelect - 49].BagItem.ItemUse;
			PlayerBag[ItemSelect - 49].BagItem.ItemNum--;
			StaminaConrtol(PlayerData);
			system("cls");
			cout << "你的回合<<" << endl << endl;
			PrintHealh(PlayerData, MonsterData, MonNum);
			cout << endl << PlayerData[0].PlayerName << "使用了 " << PlayerBag[ItemSelect - 49].BagItem.ItemName
				<< " 耐力值回复了 " << PlayerBag[ItemSelect - 49].BagItem.ItemUse << " 点" << endl << endl;

			system("pause");
		}
		else if (PlayerBag[ItemSelect - 49].BagItem.ItemType == 3 && ItemSelect - 49 < BagItemNum)
		{
			PlayerData[0].PlayerDef += PlayerBag[ItemSelect - 49].BagItem.ItemUse;
			PlayerBag[ItemSelect - 49].BagItem.ItemNum--;
			system("cls");
			cout << "你的回合<<" << endl << endl;
			PrintHealh(PlayerData, MonsterData, MonNum);
			cout << endl << PlayerData[0].PlayerName << "使用了 " << PlayerBag[ItemSelect - 49].BagItem.ItemName
				<< " 护盾值上升了 " << PlayerBag[ItemSelect - 49].BagItem.ItemUse << " 点" << endl << endl;

			system("pause");
		}
		else if (PlayerBag[ItemSelect - 49].BagItem.ItemType == 4 && ItemSelect - 49 < BagItemNum)
		{
			PlayerData[0].ExDamage += PlayerBag[ItemSelect - 49].BagItem.ItemUse;
			PlayerData[0].Buff++;
			PlayerBag[ItemSelect - 49].BagItem.ItemNum--;
			system("cls");
			cout << "你的回合<<" << endl << endl;
			PrintHealh(PlayerData, MonsterData, MonNum);
			cout << endl << PlayerData[0].PlayerName << "使用了 " << PlayerBag[ItemSelect - 49].BagItem.ItemName
				<< " 下一回合额外造成 " << PlayerBag[ItemSelect - 49].BagItem.ItemUse << " 点伤害" << endl << endl;

			system("pause");
		}
		else
		{
			return -1;
		}
		if (PlayerBag[ItemSelect - 49].BagItem.ItemNum == 0)
		{
			for (int i = (ItemSelect - 49); i < BagItemNum; i++)
			{
				PlayerBag[i].BagItem.ItemName = PlayerBag[i + 1].BagItem.ItemName;
				PlayerBag[i].BagItem.ItemType = PlayerBag[i + 1].BagItem.ItemType;
				PlayerBag[i].BagItem.ItemNum = PlayerBag[i + 1].BagItem.ItemNum;
				PlayerBag[i].BagItem.ItemUse = PlayerBag[i + 1].BagItem.ItemUse;
				PlayerBag[i].BagItem.ItemInfo = PlayerBag[i + 1].BagItem.ItemInfo;
			}
			BagItemNum--;
		}
	}
	else if (BagItemNum == 0)
	{
		cout << "无道具！" << endl << endl;
		system("pause");
		return -1;
	}
	return BagItemNum;
}

void CinBagEq(Bag PlayerBag[], Equipment Eq[], int BagEqNum)		//将展示值为1的装备写入背包
{
	int bag = 0;
	for (int i = 0; bag < BagEqNum; i++)
	{
		if (Eq[i].ShowEq == 1)
		{
			PlayerBag[bag].Eq.EqName = Eq[i].EqName;
			PlayerBag[bag].Eq.EqType = Eq[i].EqType;
			PlayerBag[bag].Eq.IfEq = Eq[i].IfEq;
			PlayerBag[bag].Eq.EqUse = Eq[i].EqUse;
			PlayerBag[bag].Eq.EqInfo = Eq[i].EqInfo;
			PlayerBag[bag].Eq.EqTypeName = Eq[i].EqTypeName;
			PlayerBag[bag].Eq.ShowEq = 1;
			Eq[i].ShowEq = 0;
			bag++;
		}
	}
}

void ShowBagEq(Bag PlayerBag[], int BagEqNum)
{
	int equse = 0;
	cout << endl << "\t\t\t\t\t\t  <-选择要调整的装备->" << endl;
	cout << "\t\t\t\t\t\t  --------------------\n"
		<< "\t\t\t\t\t\t    >输入其他键退出<" << endl;
	for (int i = 0; i < BagEqNum; i++)
	{
		if (i % 2 == 0)
		{
			gotoxy(0, 2.5 * i + 6);
			cout << " |装备 " << i + 1 << ": " << PlayerBag[i].Eq.EqName;
			cout << "    类型: " << PlayerBag[i].Eq.EqTypeName << "  "
				<< "装备情况: " << (PlayerBag[i].Eq.IfEq == 0 ? "未装备" : " >已装备<") << endl;
			cout << " |-------------------------------------------------------|" << endl;
			cout << " |INFO: " << PlayerBag[i].Eq.EqInfo << endl << endl << endl;
			equse++;
		}
		else
		{
			gotoxy(61, (i - 1) * 2.5 + 6);
			cout << " |装备 " << i + 1 << ": " << PlayerBag[i].Eq.EqName;
			cout << "    类型: " << PlayerBag[i].Eq.EqTypeName << "  "
				<< "装备情况: " << (PlayerBag[i].Eq.IfEq == 0 ? "未装备" : " >已装备<") << endl;
			gotoxy(61, (i - 1) * 2.5 + 7);
			cout << " |-------------------------------------------------------|" << endl;
			gotoxy(61, (i - 1) * 2.5 + 8);
			cout << " |INFO: " << PlayerBag[i].Eq.EqInfo << endl << endl << endl;
			equse++;
		}
	}
	if (equse == 0)
	{
		cout << "可用装备为空！！！" << endl;
	}
}

void ShowBag(Bag PlayerBag[], int BagItemNum, int BagEqNum)
{
	int y = 6;
	int use = 0;
	int equse = 0;
	cout << endl << "                                               |输入“0”返回上个界面|" << endl
		<< "                                               |---------------------|" << endl << endl;
	cout << "                    | -物品- |\n"
		<< "                    |--------|\n" << endl;
	for (int j = 0; j < BagItemNum; j++)
	{
		if (PlayerBag[j].BagItem.ItemNum > 0)
		{
			gotoxy(0, y + j * 5 + 1);
			cout << " |物品 " << j + 1 << ": " << PlayerBag[j].BagItem.ItemName;
			gotoxy(28, y + j * 5 + 1);
			cout << "类型: " << ((PlayerBag[j].BagItem.ItemType == 0) ? "道具" : "消耗品") << "    "
				<< "剩余: " << PlayerBag[j].BagItem.ItemNum << endl;
			cout << " |---------------------------------------------------|" << endl
				<< " |INFO: " << PlayerBag[j].BagItem.ItemInfo << endl << endl;
			use++;
		}
	}
	if (use == 0)
	{
		gotoxy(0, y);
		cout << endl << "    可用物品为空！！！" << endl;
	}
	y = 4;
	cout << endl;
	gotoxy(60, y);
	cout << "                       | -装备- |";
	gotoxy(60, y + 1);
	cout << "                       |--------|" << endl;
	for (int i = 0; i < BagEqNum; i++)
	{
		if (PlayerBag[i].Eq.ShowEq == 1)
		{
			gotoxy(60, y + i * 5 + 3);
			cout << " |装备 " << i + 1 << ": " << PlayerBag[i].Eq.EqName;
			cout << "    类型: " << PlayerBag[i].Eq.EqTypeName << "  "
				<< "装备情况: " << (PlayerBag[i].Eq.IfEq == 0 ? "未装备" : " >已装备<") << endl;
			gotoxy(60, y + i * 5 + 4);
			cout << " |---------------------------------------------------|" << endl;
			gotoxy(60, y + i * 5 + 5);
			cout << " |INFO: " << PlayerBag[i].Eq.EqInfo << endl << endl;
			equse++;
			gotoxy(61, y + i * 5 + 8);
		}
	}
	if (equse == 0)
	{
		gotoxy(60, y + 2);
		cout << endl << "    可用装备为空！！！" << endl;
		gotoxy(60, y + 10);
	}
}

void SelectEq(Player PlayerData[], struct Bag PlayerBag[], struct PlayerEq PEq[], Equipment Eq[], int BagEqNum)
{
	while (true)
	{
		system("cls");
		ShowBagEq(PlayerBag, BagEqNum);
		int EqSelect = _getch();
		if (EqSelect > 48 && EqSelect < BagEqNum + 49)
		{
			if (PlayerBag[EqSelect - 49].Eq.IfEq == 1)
			{
				if (PlayerBag[EqSelect - 49].Eq.EqType == 0)
				{
					PEq[0].hand = 0;
					PEq[0].handS = "空";
					PlayerData[0].PlayerAtk -= PlayerBag[EqSelect - 49].Eq.EqUse;
				}
				else if (PlayerBag[EqSelect - 49].Eq.EqType == 1)
				{
					PEq[0].head = 0;
					PEq[0].headS = "空";
					PlayerData[0].PlayerMaxH -= (PlayerBag[EqSelect - 49].Eq.EqUse / 3) + 1;
					PlayerData[0].PlayerMaxSta -= PlayerBag[EqSelect - 49].Eq.EqUse;
				}
				else if (PlayerBag[EqSelect - 49].Eq.EqType == 2)
				{
					PEq[0].cheast = 0;
					PEq[0].cheastS = "空";
					PlayerData[0].PlayerMaxH -= PlayerBag[EqSelect - 49].Eq.EqUse;
					PlayerData[0].PlayerMaxSta -= PlayerBag[EqSelect - 49].Eq.EqUse;
				}
				else if (PlayerBag[EqSelect - 49].Eq.EqType == 3)
				{
					PEq[0].legging = 0;
					PEq[0].leggingS = "空";
					PlayerData[0].PlayerMaxH -= (PlayerBag[EqSelect - 49].Eq.EqUse / 2) + 1;
					PlayerData[0].PlayerMaxSta -= PlayerBag[EqSelect - 49].Eq.EqUse;

				}
				else if (PlayerBag[EqSelect - 49].Eq.EqType == 4)
				{
					PEq[0].boot = 0;
					PEq[0].bootS = "空";
					PlayerData[0].PlayerMaxH -= (PlayerBag[EqSelect - 49].Eq.EqUse / 3) + 1;
					PlayerData[0].PlayerMaxSta -= PlayerBag[EqSelect - 49].Eq.EqUse;
				}
				else if (PlayerBag[EqSelect - 49].Eq.EqType == 5)
				{
					PEq[0].other = 0;
					PEq[0].otherS = "空";
					if (PEq[0].other == 0 && PlayerBag[EqSelect - 49].Eq.EqUse == 0)
					{
						PlayerData[0].IfFirstDead--;
					}
				}
				PlayerBag[EqSelect - 49].Eq.IfEq = 0;
				system("cls");
				ShowBagEq(PlayerBag, BagEqNum);
				cout << "已卸下装备 " << PlayerBag[EqSelect - 49].Eq.EqName << endl << endl;
			}
			else if (PlayerBag[EqSelect - 49].Eq.IfEq == 0)
			{
				if ((PEq[0].hand == 1 && PlayerBag[EqSelect - 49].Eq.EqType == 0) || (PEq[0].head == 1 && PlayerBag[EqSelect - 49].Eq.EqType == 1) ||
					(PEq[0].cheast == 1 && PlayerBag[EqSelect - 49].Eq.EqType == 2) || (PEq[0].legging == 1 && PlayerBag[EqSelect - 49].Eq.EqType == 3) ||
					(PEq[0].boot == 1 && PlayerBag[EqSelect - 49].Eq.EqType == 4) || (PEq[0].other == 1 && PlayerBag[EqSelect - 49].Eq.EqType == 5))
				{
					system("cls");
					ShowBagEq(PlayerBag, BagEqNum);
					cout << "当前位置已有装备，请先卸下装备！\n\n";
				}

				else if ((PEq[0].hand == 0 && PlayerBag[EqSelect - 49].Eq.EqType == 0) || (PEq[0].head == 0 && PlayerBag[EqSelect - 49].Eq.EqType == 1) ||
					(PEq[0].cheast == 0 && PlayerBag[EqSelect - 49].Eq.EqType == 2) || (PEq[0].legging == 0 && PlayerBag[EqSelect - 49].Eq.EqType == 3) ||
					(PEq[0].boot == 0 && PlayerBag[EqSelect - 49].Eq.EqType == 4) || (PEq[0].other == 0 && PlayerBag[EqSelect - 49].Eq.EqType == 5))
				{
					system("cls");
					PlayerBag[EqSelect - 49].Eq.IfEq = 1;
					if (PlayerBag[EqSelect - 49].Eq.EqType == 0)
					{
						PEq[0].hand = 1;
						PEq[0].handS = PlayerBag[EqSelect - 49].Eq.EqName;
						PlayerData[0].PlayerAtk += PlayerBag[EqSelect - 49].Eq.EqUse;
					}
					if (PlayerBag[EqSelect - 49].Eq.EqType == 1)
					{
						PEq[0].head = 1;
						PEq[0].headS = PlayerBag[EqSelect - 49].Eq.EqName;
						PlayerData[0].PlayerMaxH += (PlayerBag[EqSelect - 49].Eq.EqUse / 3) + 1;
						PlayerData[0].PlayerMaxSta += PlayerBag[EqSelect - 49].Eq.EqUse;
					}
					if (PlayerBag[EqSelect - 49].Eq.EqType == 2)
					{
						PEq[0].cheast = 1;
						PEq[0].cheastS = PlayerBag[EqSelect - 49].Eq.EqName;
						PlayerData[0].PlayerMaxH += PlayerBag[EqSelect - 49].Eq.EqUse;
						PlayerData[0].PlayerMaxSta += PlayerBag[EqSelect - 49].Eq.EqUse;
					}
					if (PlayerBag[EqSelect - 49].Eq.EqType == 3)
					{
						PEq[0].legging = 1;
						PEq[0].leggingS = PlayerBag[EqSelect - 49].Eq.EqName;
						PlayerData[0].PlayerMaxH += (PlayerBag[EqSelect - 49].Eq.EqUse / 2) + 1;
						PlayerData[0].PlayerMaxSta += PlayerBag[EqSelect - 49].Eq.EqUse;
					}
					if (PlayerBag[EqSelect - 49].Eq.EqType == 4)
					{
						PEq[0].boot = 1;
						PEq[0].bootS = PlayerBag[EqSelect - 49].Eq.EqName;
						PlayerData[0].PlayerMaxH += (PlayerBag[EqSelect - 49].Eq.EqUse / 3) + 1;
						PlayerData[0].PlayerMaxSta += PlayerBag[EqSelect - 49].Eq.EqUse;
					}
					if (PlayerBag[EqSelect - 49].Eq.EqType == 5)
					{
						PEq[0].other = 1;
						PEq[0].otherS = PlayerBag[EqSelect - 49].Eq.EqName;
						if (PEq[0].other == 1 && PlayerBag[EqSelect - 49].Eq.EqUse == 0)
						{
							PlayerData[0].IfFirstDead++;
						}
					}
					ShowBagEq(PlayerBag, BagEqNum);
					cout << "已装备 " << PlayerBag[EqSelect - 49].Eq.EqName << endl << endl;
				}
			}
			system("pause");
		}
		else
		{
			break;
		}
	}
}

int CinSkillUse(struct SkillList SkillData[], struct SkillUseList SkillUseData[], int len)   //写入使用表
{
	int Sk1Num = 0;
	for (int j = 0; j < len; j++)
	{
		if (SkillData[j].ShowSkill == 1)
		{
			SkillUseData[Sk1Num].SkillName = SkillData[j].SkillName;
			SkillUseData[Sk1Num].SkillType = SkillData[j].SkillType;
			SkillUseData[Sk1Num].SkillCost = SkillData[j].SkillCost;
			SkillUseData[Sk1Num].SkillCD = SkillData[j].SkillCD;
			SkillUseData[Sk1Num].SkillCDTime = SkillData[j].SkillCDTime;
			SkillUseData[Sk1Num].SkillUse = SkillData[j].SkillUse;
			SkillUseData[Sk1Num].SkillInfo = SkillData[j].SkillInfo;
			SkillUseData[Sk1Num].ShowSkill = SkillData[j].ShowSkill;
			Sk1Num++;
		}
	}
	return Sk1Num;
}

int CinSkillSptUse(SkillList SkillSptData[], SkillUseList SkillSptUseData[], int len2)  //写入使用表
{
	int Sk2Num = 0;
	for (int j = 0; j < len2; j++)
	{
		if (SkillSptData[j].ShowSkill == 1)
		{
			SkillSptUseData[Sk2Num].SkillName = SkillSptData[j].SkillName;
			SkillSptUseData[Sk2Num].SkillType = SkillSptData[j].SkillType;
			SkillSptUseData[Sk2Num].SkillCost = SkillSptData[j].SkillCost;
			SkillSptUseData[Sk2Num].SkillCD = SkillSptData[j].SkillCD;
			SkillSptUseData[Sk2Num].SkillCDTime = SkillSptData[j].SkillCDTime;
			SkillSptUseData[Sk2Num].SkillUse = SkillSptData[j].SkillUse;
			SkillSptUseData[Sk2Num].SkillInfo = SkillSptData[j].SkillInfo;
			SkillSptUseData[Sk2Num].ShowSkill = 1;
			Sk2Num++;
		}
	}
	return Sk2Num;
}

void SkillLv(Player PlayerData[], SkillList SkillData[], SkillList SkillSptData[],
	SkillUseList SkillLvUp[], SkillUseList SkillUseData[], SkillUseList SkillSptUseData[], int len, int len2)
{
	while (1)
	{
		system("cls");
		cout << endl << "\t\t\t\t\t        |玩家信息|" << endl
			<< "\t\t\t\t\t        |--------|" << endl << endl;
		cout << "\t        |--按“Y”键进入查看技能界面--|";
		cout << "\t           |--按“U”键进入升级技能界面--|" << endl;
		int Mode;
		Mode = _getch();
		system("cls");
		if (Mode == 117)
		{
			while (1)
			{
				cout << "\n\t\t\t\t\t>>请选择要升级的技能类型<<\n\n\t\t\t\t  1.战斗技能\t2.支援技能\t0.退出界面\n";
				int SkS = _getch();
				SkS -= 48;
				system("cls");
				if (SkS == 1)
				{
					while (1)
					{
						int a = 0;
						int b = 1;
						cout << "\n███████████████████████████████████████████████████████████████████████████████████"
							<< endl << endl;
						for (int i = 1; i < len; i++)
						{
							if (SkillData[i - 1].ShowSkill == 1 && SkillData[i].SkillLv <= 3 && SkillData[i].SkillLv > SkillData[i - 1].SkillLv)
							{
								cout << " |战斗技能 " << b << ": <" << SkillData[i - 1].SkillName << "> ";
								cout << "   \t| 消耗: " << SkillData[i - 1].SkillCost
									<< " | CD: " << SkillData[i - 1].SkillCDTime << "/"
									<< SkillData[i - 1].SkillCD << " |" << endl;
								cout << " |------------------------------------------------------------|" << endl
									<< " |INFO: " << SkillData[i - 1].SkillInfo << endl;
								SkillLvUp[a].SkillName = SkillData[i - 1].SkillName;
								SkillLvUp[a].ShowSkill = SkillData[i - 1].ShowSkill;
								a++;


								cout << "\t\t\t\t\t\t\t\t   升级至\n\n" << "\t\t\t\t\t\t\t\t↓↓↓↓↓↓\n\n";



								cout << " |战斗技能 " << b << ": <" << SkillData[i].SkillName << "> ";
								cout << "   \t| 消耗: " << SkillData[i].SkillCost
									<< " | CD: " << SkillData[i].SkillCDTime << "/"
									<< SkillData[i].SkillCD << " | \t  花费: " << SkillData[i].SkillPC << endl;
								cout << " |------------------------------------------------------------|" << endl
									<< " |INFO: " << SkillData[i].SkillInfo
									<< endl << endl
									<< "███████████████████████████████████████████████████████████████████████████████████"
									<< endl << endl;
								SkillLvUp[a].SkillName = SkillData[i].SkillName;
								SkillLvUp[a].ShowSkill = SkillData[i].ShowSkill;
								a++;
								b++;
							}
							else if (SkillData[i-1].SkillLv == 1 && SkillData[i-1].ShowSkill == 0 && SkillData[i].ShowSkill == 0 && SkillData[i + 1].ShowSkill == 0)
							{
								cout << " |战斗技能 " << b << ": <" << SkillData[i-1].SkillName << "> ";
								cout << "   \t| 消耗: " << SkillData[i-1].SkillCost
									<< " | CD: " << SkillData[i-1].SkillCDTime << "/"
									<< SkillData[i-1].SkillCD << " | \t  购买花费: " << SkillData[i-1].SkillPC << endl;
								cout << " |------------------------------------------------------------|" << endl
									<< " |INFO: " << SkillData[i-1].SkillInfo
									<< endl << endl
									<< "███████████████████████████████████████████████████████████████████████████████████"
									<< endl << endl;
								SkillLvUp[a].SkillName = SkillData[i-1].SkillName;
								SkillLvUp[a].ShowSkill = SkillData[i-1].ShowSkill;
								a++;
								b++;
							}
						}
						if (a > 0)
						{
							cout << "输入要升级的技能(输入0退出)" << "\t\t玩家技能点数: " << PlayerData[0].SkillPoint << endl;
							int Select = _getch();
							Select -= 49;

							if (Select == -1)
							{
								system("cls");
								break;
							}
							Select *= 2;

							for (int k = 0; k <= len; k++)
							{
								if (SkillLvUp[Select].SkillName == SkillData[k].SkillName)
								{
									if (SkillData[k + 1].SkillPC <= PlayerData[0].SkillPoint)
									{
										if (SkillData[k].SkillLv == 1 && SkillData[k].ShowSkill == 0 && SkillData[k+1].ShowSkill == 0 && SkillData[k + 2].ShowSkill == 0)
										{
											PlayerData[0].SkillPoint -= SkillData[k].SkillPC;
											SkillLvUp[Select + 1].ShowSkill = 1;
											SkillData[k].ShowSkill = SkillLvUp[Select + 1].ShowSkill;
											a -= 1;
											CinSkillUse(SkillData, SkillUseData, len);
											cout << "\n技能购买完毕！\n" << endl;
										}
										else
										{
											PlayerData[0].SkillPoint -= SkillData[k + 1].SkillPC;
											SkillLvUp[Select].ShowSkill = 0;
											SkillData[k].ShowSkill = SkillLvUp[Select].ShowSkill;
											SkillLvUp[Select + 1].ShowSkill = 1;
											SkillData[k + 1].ShowSkill = SkillLvUp[Select + 1].ShowSkill;
											a -= 2;
											CinSkillUse(SkillData, SkillUseData, len);
											cout << "\n技能升级完毕！\n" << endl;
										}
									}
									else
									{
										cout << "\n技能点数不够！\n" << endl;
									}
									system("pause");
								}
							}
							system("cls");
						}
						else
						{
							cout << "所有技能均已升级完毕\n\n\n" << endl;
							system("pause");
							system("cls");
							break;
						}

					}
				}
				else if (SkS == 2)
				{
					while (1)
					{
						int a = 0;
						int b = 1;
						cout << "\n███████████████████████████████████████████████████████████████████████████████████"
							<< endl << endl;
						for (int i = 1; i < len2; i++)
						{
							if (SkillSptData[i - 1].ShowSkill == 1 && SkillSptData[i].SkillLv <= 3 && SkillSptData[i].SkillLv > SkillSptData[i - 1].SkillLv)
							{
								cout << " |战斗技能 " << b << ": <" << SkillSptData[i - 1].SkillName << "> ";
								cout << "   \t| 消耗: " << SkillSptData[i - 1].SkillCost
									<< " | CD: " << SkillSptData[i - 1].SkillCDTime << "/"
									<< SkillSptData[i - 1].SkillCD << " |" << endl;
								cout << " |------------------------------------------------------------|" << endl
									<< " |INFO: " << SkillSptData[i - 1].SkillInfo << endl;
								SkillLvUp[a].SkillName = SkillSptData[i - 1].SkillName;
								SkillLvUp[a].ShowSkill = SkillSptData[i - 1].ShowSkill;
								a++;


								cout << "\t\t\t\t\t\t\t\t   升级至\n\n" << "\t\t\t\t\t\t\t\t↓↓↓↓↓↓\n\n";



								cout << " |战斗技能 " << b << ": <" << SkillSptData[i].SkillName << "> ";
								cout << "   \t| 消耗: " << SkillSptData[i].SkillCost
									<< " | CD: " << SkillSptData[i].SkillCDTime << "/"
									<< SkillSptData[i].SkillCD << " | \t  花费: " << SkillSptData[i].SkillPC << endl;
								cout << " |------------------------------------------------------------|" << endl
									<< " |INFO: " << SkillSptData[i].SkillInfo
									<< endl << endl
									<< "███████████████████████████████████████████████████████████████████████████████████"
									<< endl << endl;
								SkillLvUp[a].SkillName = SkillSptData[i].SkillName;
								SkillLvUp[a].ShowSkill = SkillSptData[i].ShowSkill;
								a++;
								b++;
							}
							else if (SkillSptData[i - 1].SkillLv == 1 && SkillSptData[i - 1].ShowSkill == 0 && SkillSptData[i].ShowSkill == 0 && SkillSptData[i + 1].ShowSkill == 0)
							{
								cout << " |战斗技能 " << b << ": <" << SkillSptData[i - 1].SkillName << "> ";
								cout << "   \t| 消耗: " << SkillSptData[i - 1].SkillCost
									<< " | CD: " << SkillSptData[i - 1].SkillCDTime << "/"
									<< SkillSptData[i - 1].SkillCD << " | \t  购买花费: " << SkillSptData[i - 1].SkillPC << endl;
								cout << " |------------------------------------------------------------|" << endl
									<< " |INFO: " << SkillSptData[i - 1].SkillInfo
									<< endl << endl
									<< "███████████████████████████████████████████████████████████████████████████████████"
									<< endl << endl;
								SkillLvUp[a].SkillName = SkillSptData[i - 1].SkillName;
								SkillLvUp[a].ShowSkill = SkillSptData[i - 1].ShowSkill;
								a++;
								b++;
							}
						}
						if (a > 0)
						{
							cout << "输入要升级的技能(输入0退出)" << "\t\t玩家技能点数: " << PlayerData[0].SkillPoint << endl;
							int Select = _getch();
							Select -= 49;

							if (Select == -1)
							{
								system("cls");
								break;
							}
							Select *= 2;

							for (int k = 0; k <= len2; k++)
							{
								if (SkillLvUp[Select].SkillName == SkillSptData[k].SkillName)
								{
									if (SkillSptData[k + 1].SkillPC <= PlayerData[0].SkillPoint)
									{
										if (SkillSptData[k].SkillLv == 1 && SkillSptData[k].ShowSkill == 0 && SkillSptData[k + 1].ShowSkill == 0 && SkillSptData[k + 2].ShowSkill == 0)
										{
											PlayerData[0].SkillPoint -= SkillSptData[k].SkillPC;
											SkillLvUp[Select + 1].ShowSkill = 1;
											SkillSptData[k].ShowSkill = SkillLvUp[Select + 1].ShowSkill;
											a -= 1;
											CinSkillSptUse(SkillSptData, SkillSptUseData, len2);
											cout << "\n技能购买完毕！\n" << endl;
										}
										else
										{
											PlayerData[0].SkillPoint -= SkillSptData[k + 1].SkillPC;
											SkillLvUp[Select].ShowSkill = 0;
											SkillSptData[k].ShowSkill = SkillLvUp[Select].ShowSkill;
											SkillLvUp[Select + 1].ShowSkill = 1;
											SkillSptData[k + 1].ShowSkill = SkillLvUp[Select + 1].ShowSkill;
											a -= 2;
											CinSkillSptUse(SkillSptData, SkillSptUseData, len2);
											cout << "\n技能升级完毕！\n" << endl;
										}
									}
									else
									{
										cout << "\n技能点数不够！\n" << endl;
									}
									system("pause");
								}
							}
							system("cls");
						}
						else
						{
							cout << "所有技能均已升级完毕\n\n\n" << endl;
							system("pause");
							system("cls");
							break;
						}

					}
				}
				else
				{
					system("cls");
					break;
				}
			}
		}
		else if (Mode == 121)
		{
			while (1)
			{
				cout << endl << "                            |输入任意键返回上个界面|" << endl
					<< "                            |----------------------|" << endl << endl;
				for (int i = 0; i < len; i++)
				{
					if (SkillUseData[i].ShowSkill == 1)
					{
						cout << endl
							<< " |战斗技能 " << i + 1 << ": <" << SkillUseData[i].SkillName << "> ";
						cout << "   \t| 消耗: " << SkillUseData[i].SkillCost
							<< " | CD: " << SkillUseData[i].SkillCDTime << "/"
							<< SkillUseData[i].SkillCD << " |    " << endl;
						cout << " |------------------------------------------------------------|" << endl
							<< " |INFO: " << SkillUseData[i].SkillInfo << endl << endl;
					}
				}
				cout << "\n███████████████████████████████████████████████████████████████████████████████████" << endl;
				cout << endl << "\n |特殊技能 1：命运骰子（剩余" << PlayerData->DiceNum << "个）" << endl
					<< " |------------------------------------------------------------|" << endl
					<< " |INFO: 投出一个骰子，会有特殊的效果" << endl << endl;
				for (int i = 0; i < len2; i++)
				{
					if (SkillSptUseData[i].ShowSkill == 1)
					{
						cout << endl
							<< " |支援技能 " << i + 2 << ": <" << SkillSptUseData[i].SkillName << ">";
						cout << "\t   | 消耗: " << SkillSptUseData[i].SkillCost
							<< " | CD: " << SkillSptUseData[i].SkillCDTime << "/"
							<< SkillSptUseData[i].SkillCD << " |    " << endl
							<< " |------------------------------------------------------------|" << endl
							<< " |INFO: " << SkillSptUseData[i].SkillInfo << endl << endl;
					}
				}
				system("pause");
				break;
			}
		}
		else
		{
			break;
		}
	}
}

void ShowPlayerData(Player PlayerData[], Bag PlayerBag[], Equipment Eq[], PlayerEq PEq[], SkillList SkillData[], SkillList SkillSptData[],
	SkillUseList SkillLvUp[], SkillUseList SkillUseData[], SkillUseList SkillSptUseData[], int len, int len2, int BagEqNum)
{
	system("cls");
	int y = 6;
	int i = 1;
	while (1)
	{
		system("cls");
		cout << endl << "\t\t\t\t\t       |玩家信息|" << endl
			<< "\t\t\t\t\t       |--------|" << endl << endl;
		cout << "\t\t\t    |按“I”键进入装备模式|" << "  |按“U”键进入技能界面|" << endl;
		cout << "\n                 |装备信息|" << endl
			<< "                 |--------|" << endl << endl;
		cout << "|头部: " << PEq[0].headS << endl << "|------------------|"
			<< "\t|武器: " << PEq[0].handS << endl << "\t\t\t|------------------|\n";
		cout << "|胸甲: " << PEq[0].cheastS << endl << "|------------------|"
			<< "\t|饰品: " << PEq[0].otherS << endl << "\t\t\t|------------------|\n";
		cout << "|腿部: " << PEq[0].leggingS << endl << "|------------------|\n" << endl;
		cout << "|靴子: " << PEq[0].bootS << endl << "|------------------|\n" << endl;

		//玩家属性输出
		{
			gotoxy(66, 6);
			cout << "           |玩家属性|";
			gotoxy(66, 7);
			cout << "           |--------|";
			gotoxy(60, 9);
			cout << "|玩家: " << PlayerData[0].PlayerName;
			gotoxy(60, 10);
			cout << "|------------------|";
			gotoxy(84, 9);
			cout << "|等级: " << PlayerData[0].PlayerLv;
			gotoxy(84, 10);
			cout << "|------------------|";
			gotoxy(60, 12);
			cout << "|生命值: " << PlayerData[0].PlayerH << "/" << PlayerData[0].PlayerMaxH;
			gotoxy(60, 13);
			cout << "|------------------|";
			gotoxy(84, 12);
			cout << "|经验值: " << PlayerData[0].PlayerExp << "/" << PlayerData[0].PlayerLv * (PlayerData[0].PlayerLv + 10) - 1;
			gotoxy(84, 13);
			cout << "|------------------|";
			gotoxy(60, 15);
			cout << "|攻击力: " << PlayerData[0].PlayerAtk;
			gotoxy(60, 16);
			cout << "|------------------|";
			gotoxy(84, 15);
			cout << "|命运骰子: " << PlayerData[0].DiceNum << " 个";
			gotoxy(84, 16);
			cout << "|------------------|";
			gotoxy(60, 18);
			cout << "|耐力: " << PlayerData[0].PlayerStamina << "/" << PlayerData[0].PlayerMaxSta;
			gotoxy(60, 19);
			cout << "|------------------|";
			gotoxy(84, 18);
			cout << "|耐力回复: " << (PlayerData[0].PlayerLv / 2) + 1;
			gotoxy(84, 19);
			cout << "|------------------|";
		}

		int EqMode;
		EqMode = _getch();
		if (EqMode == 117 && PlayerData[0].IfBattle == 1)
		{
			system("cls");
			cout << endl << "\t战斗中无法进入该界面！" << endl << endl;
			system("pause");
			break;
		}
		else if (EqMode == 117 && PlayerData[0].IfBattle == 0)
		{
			SkillLv(PlayerData, SkillData, SkillSptData, SkillUseData, SkillLvUp, SkillSptUseData, len, len2);
		}
		else if (EqMode == 105 && PlayerData[0].IfBattle == 1)
		{
			system("cls");
			cout << endl << "\t战斗中无法切换装备！" << endl << endl;
			system("pause");
			break;
		}
		else if (EqMode == 105 && PlayerData[0].IfBattle == 0)
		{
			SelectEq(PlayerData, PlayerBag, PEq, Eq, BagEqNum);
		}
		else
		{
			system("cls");
			break;
		}
	}
	system("cls");
}

int Damage(Player PlayerData[], SkillUseList SkillUseData[], int num)		//玩家造成的伤害
{
	int damage;
	if (SkillUseData[num - 1].SkillType == 0)
	{
		damage = PlayerData[0].PlayerAtk * PlayerData[0].DiceEf + SkillUseData[num - 1].SkillUse + PlayerData[0].ExDamage;
	}
	else if (SkillUseData[num - 1].SkillType == 1)
	{
		damage = PlayerData[0].PlayerAtk * PlayerData[0].DiceEf * SkillUseData[num - 1].SkillUse + PlayerData[0].ExDamage;
	}
	else
	{
		return 0;
	}
	return damage;
}

int Death(struct Player PlayerData[], struct Monster MonsterData[])	//检测玩家和敌人死亡
{
	int a = 0;
	if (PlayerData[0].PlayerH <= 0)
	{
		cout << endl << "你输了！" << endl;
		a = 1;
	}
	else if (MonsterData[0].MonsterH <= 0)
	{
		cout << endl << "怪物已被击败！" << endl;
		a = 2;
	}
	return a;
}

int MonsterAI(struct Monster MonsterData[], int MonNum)	//怪物AI
{
	int MonsterDamage = 0;
	if (MonsterData[MonNum].MonsterSkill == 4)
	{
		MonsterData[MonNum].MonsterSkill = 0;
		return MonsterDamage;
	}
	else if (MonsterData[MonNum].MonsterSkill == 3)
	{
		MonsterDamage = MonsterData[MonNum].MonsterAtk + 2;
		MonsterData[MonNum].MonsterSkill++;
		return MonsterDamage;
	}
	else
	{
		MonsterDamage = MonsterData[MonNum].MonsterAtk;
		MonsterData[MonNum].MonsterSkill++;
		return MonsterDamage;
	}
}

int Dice(struct Player PlayerData[])  //骰子
{
	if (PlayerData->DiceNum > 0)
	{
		int Point = rand() % 6 + 1;
		PlayerData->DiceNum--;
		return Point;
	}
	else
	{
		return 0;
	}
}

int RandomNum()  //随机数
{
	int Point = rand() % 100 + 1;
	return Point;
}

void DiceEffect(int D, struct Player PlayerData[], Monster MonsterData[], int MonNum)		//骰子效果
{
	switch (D)
	{
	case 1:
	{
		system("cls");
		cout << "你的回合<<" << endl << endl;
		PrintHealh(PlayerData, MonsterData, MonNum);
		cout << endl << "你投出了点数: " << D << endl << endl;
		cout << "什么也没有发生 " << endl << endl;
		system("pause");
	}

	break;
	case 2:
	{
		system("cls");
		PlayerData[0].PlayerH += (PlayerData[0].PlayerMaxH / 10);
		HealthConrtol(PlayerData, MonsterData);
		cout << "你的回合<<" << endl << endl;
		PrintHealh(PlayerData, MonsterData, MonNum);
		cout << endl << "你投出了点数: " << D << endl << endl;
		cout << "回复了10%的生命值 " << endl << endl;
		system("pause");
	}
	break;
	case 3:
	{
		system("cls");
		PlayerData[0].PlayerStamina += (PlayerData[0].PlayerMaxSta * 3 / 10);
		StaminaConrtol(PlayerData);
		cout << "你的回合<<" << endl << endl;
		PrintHealh(PlayerData, MonsterData, MonNum);
		cout << endl << "你投出了点数: " << D << endl << endl;
		cout << "回复了30%的耐力值 " << endl << endl;
		system("pause");
	}
	break;
	case 4:
	{
		PlayerData[0].ExDamage += (PlayerData[0].PlayerAtk / 2);
		system("cls");
		cout << "你的回合<<" << endl << endl;
		PrintHealh(PlayerData, MonsterData, MonNum);
		cout << endl << "你投出了点数: " << D << endl << endl;
		cout << "攻击额外造成相当于玩家攻击力一半的伤害\n持续一回合，不可叠加 " << endl << endl;
		system("pause");
	}
	break;
	case 5:
	{
		PlayerData[0].PlayerH += (PlayerData[0].PlayerMaxH / 5);
		HealthConrtol(PlayerData, MonsterData);
		system("cls");
		cout << "你的回合<<" << endl << endl;
		PrintHealh(PlayerData, MonsterData, MonNum);
		cout << endl << "你投出了点数: " << D << endl << endl;
		cout << "回复了20%的生命值 " << endl << endl;
		system("pause");
	}
	break;
	case 6:
	{
		PlayerData[0].DiceEf = 2;
		system("cls");
		cout << "你的回合<<" << endl << endl;
		PrintHealh(PlayerData, MonsterData, MonNum);
		cout << endl << "你投出了点数: " << D << endl;
		cout << "玩家的基础攻击力提升100%\n持续一回合，不可叠加" << endl << endl;
		system("pause");
	}
	break;
	default:
		cout << endl << "骰子已经用完！" << endl << endl;
		system("pause");
		break;
	}
}

int SkillSptSystem
(SkillList SkillSptData[], SkillUseList SkillSptUseData[], Player PlayerData[],
	Monster MonsterData[], int MonNum, int len2, int Sk2Num, int FirstExDa)//支援技能系统
{
	int y = 28;
	system("cls");
	cout << "你的回合<<" << endl << endl;
	PrintHealh(PlayerData, MonsterData, MonNum);
	cout << endl << "                            |输入“0”返回上个界面|" << endl
		<< "                            |---------------------|" << endl << endl;
	cout << endl << " |特殊技能 1：命运骰子（剩余" << PlayerData->DiceNum << "个）" << endl
		<< " |----------------------------------------------------------------------------|" << endl
		<< " |INFO: 投出一个骰子，会有特殊的效果" << endl << endl;
	for (int i = 0; i < Sk2Num; i++)
	{
		gotoxy(0, y + i * 5);
		string r = SkillSptUseData[i].SkillCDTime == 0 ? "-->> READY <<--" : "";
		cout << endl
			<< " |支援技能 " << i + 2 << ": <" << SkillSptUseData[i].SkillName << ">";
		gotoxy(38, y + i * 5 + 1);
		cout << "| 消耗: " << SkillSptUseData[i].SkillCost
			<< " | CD: " << SkillSptUseData[i].SkillCDTime << "/"
			<< SkillSptUseData[i].SkillCD << " |    " << r << endl
			<< " |----------------------------------------------------------------------------|" << endl
			<< " |INFO: " << SkillSptUseData[i].SkillInfo << endl << endl;
	}
	int ef = 0;
	int select;
	select = _getch();

	if (select == 49)
	{
		select = Dice(PlayerData);
		PlayerData[0].DicePoint = select;
		if (PlayerData[0].DiceUse < 1)
		{
			PlayerData[0].DiceUse++;
		}
		(ef == 0) ? ef++ : 0;
		(ef == 1) ? (PlayerData[0].ExDamage = FirstExDa, PlayerData[0].DiceEf = 1) : 0;

		DiceEffect(select, PlayerData, MonsterData, MonNum);
		system("cls");
		return 0;
	}
	if (select > 49 && select <= Sk2Num + 49)
	{
		if (SkillSptUseData[select - 50].SkillCDTime == 0)
		{
			if (PlayerData[0].PlayerStamina >= SkillSptUseData[select - 50].SkillCost)
			{
				SkillSptUseData[select - 50].SkillCDTime = SkillSptUseData[select - 50].SkillCD + 1;

				if (SkillSptUseData[select - 50].SkillType == 2)
				{
					system("cls");

					(ef == 1) ? ef-- : 0;

					int heal = SkillSptUseData[select - 50].SkillUse;
					PlayerData[0].PlayerH += heal;
					HealthConrtol(PlayerData, MonsterData);

					cout << "你的回合<<" << endl << endl;
					PrintHealh(PlayerData, MonsterData, MonNum);
					cout << endl << PlayerData[0].PlayerName
						<< " 使用了 " << SkillSptUseData[select - 50].SkillName
						<< " 回复了 " << heal << " 点生命值" << endl << endl;

					system("pause");
					system("cls");
					return 0;
				}
				if (SkillSptUseData[select - 50].SkillType == 3)
				{
					system("cls");

					(ef == 1) ? ef-- : 0;

					PlayerData[0].PlayerStamina -= SkillSptUseData[select - 50].SkillCost;
					PlayerData[0].PlayerDef += SkillSptUseData[select - 50].SkillUse;
					StaminaConrtol(PlayerData);

					cout << "你的回合<<" << endl << endl;
					PrintHealh(PlayerData, MonsterData, MonNum);
					cout << endl << PlayerData[0].PlayerName
						<< " 使用了 " << SkillSptUseData[select - 50].SkillName
						<< " 获得了 " << SkillSptUseData[select - 50].SkillUse << " 点护盾" << endl << endl;

					system("pause");
					system("cls");
					return 0;
				}
				if (SkillSptUseData[select - 50].SkillType == 4)
				{
					system("cls");

					(ef == 1) ? ef-- : 0;

					PlayerData[0].PlayerStamina -= SkillSptUseData[select - 50].SkillCost;
					PlayerData[0].PlayerStamina += SkillSptUseData[select - 50].SkillUse;
					StaminaConrtol(PlayerData);

					cout << "你的回合<<" << endl << endl;
					PrintHealh(PlayerData, MonsterData, MonNum);

					cout << endl << PlayerData[0].PlayerName
						<< " 使用了 " << SkillSptUseData[select - 50].SkillName
						<< " 回复了 " << SkillSptUseData[select - 50].SkillUse << " 点耐力值" << endl << endl;

					system("pause");
					system("cls");
					return 0;
				}
				if (SkillSptUseData[select - 50].SkillType == 5)
				{
					system("cls");

					(ef == 1) ? ef-- : 0;

					PlayerData[0].PlayerStamina -= SkillSptUseData[select - 50].SkillCost;
					int DaTaken = PlayerData[0].PlayerAtk * PlayerData[0].DiceEf * (SkillSptUseData[select - 50].SkillUse / 10) + PlayerData[0].ExDamage;
					int dataken = DaTaken;
					if (MonsterData[MonNum].MonsterH < DaTaken)
					{
						DaTaken = MonsterData[MonNum].MonsterH;
					}
					MonsterData[MonNum].MonsterH -= DaTaken;
					HealthConrtol(PlayerData, MonsterData);
					StaminaConrtol(PlayerData);

					int r = RandomNum();
					if (r > (SkillSptUseData[select - 50].SkillUse * 10 / 2) + 30)
					{
						MonsterData[MonNum].Debuff = 1;
					}
					else
					{
						MonsterData[MonNum].Debuff = 0;
					}

					cout << "你的回合<<" << endl << endl;
					PrintHealh(PlayerData, MonsterData, MonNum);
					cout << endl << PlayerData[0].PlayerName
						<< " 使用了 " << SkillSptUseData[select - 50].SkillName
						<< " 对敌人造成了 " << dataken << " 点伤害" << endl << endl;

					system("pause");
					system("cls");
					return 3;
				}
			}
			else if (PlayerData[0].PlayerStamina < SkillSptUseData[select - 50].SkillCost)
			{
				return 1;
			}
		}
		else if (SkillSptUseData[select - 50].SkillCDTime > 0)
		{
			return 2;
		}
	}
	else
	{
		system("cls");
		return -1;
	}
	return -1;
}

int SkillSystem(SkillList SkillData[], SkillUseList SkillUseData[],
	Player PlayerData[], Monster MonsterData[], int MonNum, int len, int Sk1Num)  //战斗技能系统
{
	int y = 25;
	system("cls");
	cout << "你的回合<<" << endl << endl;
	PrintHealh(PlayerData, MonsterData, MonNum);
	cout << endl << "                            |输入“0”返回上个界面|" << endl
		<< "                            |---------------------|" << endl << endl;
	for (int i = 0; i < Sk1Num; i++)
	{
		gotoxy(0, y + i * 5);
		string r = SkillUseData[i].SkillCDTime == 0 ? "-->> READY <<--" : "";
		cout << endl
			<< " |战斗技能 " << i + 1 << ": <" << SkillUseData[i].SkillName << "> ";
		gotoxy(38, y + i * 5 + 1);
		cout << "| 消耗: " << SkillUseData[i].SkillCost
			<< " | CD: " << SkillUseData[i].SkillCDTime << "/"
			<< SkillUseData[i].SkillCD << " |    " << r << endl;
		cout << " |----------------------------------------------------------------------------|" << endl
			<< " |INFO: " << SkillUseData[i].SkillInfo << endl << endl;
	}
	int select;
	select = _getch();
	if (select < Sk1Num + 49 && select > 48)
	{
		if (SkillUseData[select - 49].SkillCDTime == 0)
		{
			if (PlayerData[0].PlayerStamina >= SkillUseData[select - 49].SkillCost)
			{
				SkillUseData[select - 49].SkillCDTime = SkillUseData[select - 49].SkillCD + 1;

				if (SkillUseData[select - 49].SkillType == 0 || SkillUseData[select - 49].SkillType == 1)
				{
					PlayerData[0].PlayerStamina -= SkillUseData[select - 49].SkillCost;
					int DaTaken = Damage(PlayerData, SkillUseData, (select - 48));
					int dataken = DaTaken;
					if (MonsterData[MonNum].MonsterH < DaTaken)
					{
						DaTaken = MonsterData[MonNum].MonsterH;
					}
					MonsterData[MonNum].MonsterH -= DaTaken;
					HealthConrtol(PlayerData, MonsterData);
					StaminaConrtol(PlayerData);

					system("cls");
					cout << "你的回合<<" << endl << endl;
					PrintHealh(PlayerData, MonsterData, MonNum);
					ShakeScM(PlayerData, MonsterData, MonNum, DaTaken);
					cout << endl << PlayerData[0].PlayerName << "对 " << MonsterData[MonNum].MonsterName
						<< " 使用了 " << SkillUseData[select - 49].SkillName
						<< " 并造成了 " << dataken << " 点伤害" << endl << endl;

					system("pause");
					system("cls");

					return 2;
				}
				else
				{
					return -1;
				}
			}
			else if (PlayerData[0].PlayerStamina < SkillUseData[select - 49].SkillCost)
			{
				return 1;
			}
		}
		else if (SkillUseData[select - 49].SkillCDTime > 0)
		{
			return 0;
		}
	}
	else
	{
		return -1;
	}
	return -1;
}

void BattleSystem(Player PlayerData[], SkillList SkillData[], SkillUseList SkillUseData[], SkillList SkillSptData[],
	SkillUseList SkillSptUseData[], SkillUseList SkillLvUp[], Monster MonsterData[], Bag PlayerBag[], Item item[], Equipment Eq[], PlayerEq PEq[]
	, int MonNum, int len, int len2, int ItemNum, int BagEqNum)//战斗系统
{
	PlayerData[0].IfBattle = 1;
	int FirstExDa = PlayerData[0].ExDamage;
	int dth = 0;
	int SK2Sel = 0;
	int Sk1Num = CinSkillUse(SkillData, SkillUseData, len);
	int Sk2Num = CinSkillSptUse(SkillSptData, SkillSptUseData, len2);
	int PDeBuffGive = 0;		//玩家是否对怪物施加了debuff
	for (int i = 0;; dth = Death(PlayerData, MonsterData))
	{
		if (i <= 0 && dth == 0)
		{
			cout << "你的回合<<" << endl << endl;
			PrintHealh(PlayerData, MonsterData, MonNum);
			cout << endl;
			cout << "战斗界面:" << endl;
			cout << "1.攻击技能    " << "2.战斗支援    " << "3.物品道具    " << "4.玩家信息    " << "5.跳过回合" << endl;

			char Select;
			Select = _getch();

			switch (Select)
			{
			case 49:
			{
				int DaNum = SkillSystem(SkillData, SkillUseData, PlayerData, MonsterData, MonNum, len, Sk1Num);
				system("cls");
				if (DaNum == 0)
				{
					cout << "你的回合<<" << endl << endl;
					PrintHealh(PlayerData, MonsterData, MonNum);
					cout << endl << "技能正在冷却！" << endl << endl;
					system("pause");
					system("cls");
				}
				else if (DaNum == 1)
				{
					cout << "你的回合<<" << endl << endl;
					PrintHealh(PlayerData, MonsterData, MonNum);
					cout << endl << "耐力不够！" << endl << endl;
					system("pause");
					system("cls");
				}
				else if (DaNum == 2)
				{
					for (int j = 0; j < len + len2; j++)
					{
						if (SkillUseData[j].SkillCDTime > 0)
						{
							SkillUseData[j].SkillCDTime--;
						}
						if (SkillSptUseData[j].SkillCDTime > 0)
						{
							SkillSptUseData[j].SkillCDTime--;
						}
					}
					i++;
				}
				system("cls");
			}
			break;
			case 50:
			{
				SK2Sel = SkillSptSystem(SkillSptData, SkillSptUseData, PlayerData, MonsterData, MonNum, len2, Sk2Num, FirstExDa);
				system("cls");
				if (SK2Sel == 0)
				{
					for (int j = 0; j < len + len2; j++)  //技能冷却计时
					{
						if (SkillUseData[j].SkillCDTime > 0)
						{
							SkillUseData[j].SkillCDTime--;
						}
						if (SkillSptUseData[j].SkillCDTime > 0)
						{
							SkillSptUseData[j].SkillCDTime--;
						}
					}
					i++;
				}
				else if (SK2Sel == 1)
				{
					system("cls");
					cout << "你的回合<<" << endl << endl;
					PrintHealh(PlayerData, MonsterData, MonNum);
					cout << endl << "耐力不够！" << endl << endl;
					system("pause");
					system("cls");
				}
				else if (SK2Sel == 2)
				{
					system("cls");
					cout << "你的回合<<" << endl << endl;
					PrintHealh(PlayerData, MonsterData, MonNum);
					cout << endl << "技能正在冷却！" << endl << endl;
					system("pause");
					system("cls");
				}
				else if (SK2Sel == 3)
				{
					PDeBuffGive = 1;
					for (int j = 0; j < len + len2; j++)  //技能冷却计时
					{
						if (SkillUseData[j].SkillCDTime > 0)
						{
							SkillUseData[j].SkillCDTime--;
						}
						if (SkillSptUseData[j].SkillCDTime > 0)
						{
							SkillSptUseData[j].SkillCDTime--;
						}
					}
					i++;
				}
				system("cls");
			}
			break;
			case 51:
			{
				system("cls");
				cout << "你的回合<<" << endl << endl;
				PrintHealh(PlayerData, MonsterData, MonNum);

				int BIN = ShowBattleBagItem(PlayerData, PlayerBag, item, MonsterData, ItemNum, MonNum);
				if (BIN != -1)
				{
					ItemNum = BIN;
					for (int j = 0; j < len + len2; j++)  //技能冷却计时
					{
						if (SkillUseData[j].SkillCDTime > 0)
						{
							SkillUseData[j].SkillCDTime--;
						}
						if (SkillSptUseData[j].SkillCDTime > 0)
						{
							SkillSptUseData[j].SkillCDTime--;
						}
					}
					i++;
				}

				system("cls");
			}
			break;
			case 52:
			{
				ShowPlayerData(PlayerData, PlayerBag, Eq, PEq, SkillData, SkillSptData, SkillUseData, SkillSptUseData, SkillLvUp, len, len2, BagEqNum);
				system("cls");
			}
			break;
			case 53:
			{
				for (int j = 0; j < len + len2; j++)
				{
					if (SkillUseData[j].SkillCDTime > 0)
					{
						SkillUseData[j].SkillCDTime--;
					}
					if (SkillSptUseData[j].SkillCDTime > 0)
					{
						SkillSptUseData[j].SkillCDTime--;
					}
				}
				cout << endl << "已跳过回合" << endl << endl;
				system("pause");
				system("cls");
				i++;
			}
			break;
			break;
			default:
				system("cls");
				break;
			}
			if (MonsterData[MonNum].Debuff == 1 && PDeBuffGive == 0)
			{
				MonsterData[MonNum].Debuff = 0;
			}
			else if (MonsterData[MonNum].Debuff == 0 && PDeBuffGive == 1)
			{
				PDeBuffGive = 0;
			}
		}
		else if (i == 1 && dth == 0)
		{
			if (MonsterData[MonNum].Debuff == 1 && PDeBuffGive == 1)		//重置DeBuff效果
			{
				system("cls");
				PDeBuffGive = 0;

				if (PlayerData[0].DiceUse == 0 && PlayerData[0].Buff == 0)		//重置骰子和Buff效果
				{
					if (PlayerData[0].ExDamage - FirstExDa > 0 || PlayerData[0].DiceEf > 1)
					{
						PlayerData[0].ExDamage = FirstExDa;
						PlayerData[0].DiceEf = 1;
					}
				}
				else
				{
					PlayerData[0].DiceUse = 0;
					PlayerData[0].Buff = 0;
				}

				cout << ">>敌方回合" << endl << endl;
				PrintHealh(PlayerData, MonsterData, MonNum);
				cout << endl << MonsterData[MonNum].MonsterName << " 被眩晕了！！\n\n";
				system("pause");
				system("cls");
			}
			else if (MonsterData[MonNum].Debuff == 0 && PDeBuffGive == 0)
			{
				if (PlayerData[0].DiceUse == 0 && PlayerData[0].Buff == 0)		//重置骰子和Buff效果
				{
					if (PlayerData[0].ExDamage - FirstExDa > 0 || PlayerData[0].DiceEf > 1)
					{
						PlayerData[0].ExDamage = FirstExDa;
						PlayerData[0].DiceEf = 1;
					}
				}
				else
				{
					PlayerData[0].DiceUse = 0;
					PlayerData[0].Buff = 0;
				}
				int MDa;
				MDa = MonsterAI(MonsterData, MonNum) - PlayerData[0].PlayerDef;
				if (MDa < 0)				//判断怪物造成的伤害是否为正
				{
					MDa = 0;
				}
				if (PlayerData[0].IfFirstDead == 0)
				{
					PlayerData[0].PlayerH -= MDa;
					HealthConrtol(PlayerData, MonsterData);

					cout << ">>敌方回合" << endl << endl;
					PrintHealh(PlayerData, MonsterData, MonNum);
					cout << endl << "敌人对你造成了 " << MDa << " 点伤害" << endl << endl;
					system("pause");
					system("cls");
				}
				else if (PlayerData[0].IfFirstDead == 1)
				{
					PlayerData[0].PlayerH = 1;
					PlayerData[0].IfFirstDead = 0;

					HealthConrtol(PlayerData, MonsterData);
					cout << ">>敌方回合" << endl << endl;
					PrintHealh(PlayerData, MonsterData, MonNum);
					cout << endl << "敌人对你造成了 " << MDa << " 点伤害" << endl;
					cout << endl << PlayerData[0].PlayerName << " 触发了 " << PEq[0].otherS
						<< " 的效果，抵挡了致命攻击，生命值变为1" << endl << endl;
					for (int g = 0; g < BagEqNum; g++)
						if (PlayerBag[g].Eq.IfEq == 1 && PlayerBag[g].Eq.EqType == 5 && PEq[0].other == 1)
						{
							PlayerBag[g].Eq.IfEq = 0;
							PEq[0].other = 0;
							PEq[0].otherS = "空";
						}
					system("pause");
					system("cls");
				}
			}
			else
			{
				MonsterData[MonNum].Debuff = 0;
				PDeBuffGive = 0;
			}
			PlayerData[0].PlayerDef = 0;
			PlayerData[0].PlayerStamina += (PlayerData[0].PlayerLv / 2) + 1;
			StaminaConrtol(PlayerData);
			i--;
		}
		else if (dth == 1 || dth == 2)
		{
			if (dth == 2)
			{
				PlayerData[0].PlayerExp += MonsterData[MonNum].MonExp;
				cout << "\n获得了 " << MonsterData[MonNum].MonExp << " 点经验值" << endl;
				PlayerData[0].IfBattle = 0;
				Sleep(1350);
				system("cls");
				PlayerLvUp(PlayerData);
			}
			cout << endl << "战斗结束" << endl << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}

int Shop(Player PlayerData[], Bag PlayerBag[], Item item[], int len4, int BagItemNum)
{
	while (1)
	{
		cout << "\n\t\t\t      |=商店=|" << endl
			<< "\t\t\t    |----------|" << endl
			<< " >>玩家货币数: " << PlayerData[0].gold << endl << endl << endl;

		int p = 0;
		for (int i = 0; i < len4; i++)
		{
			cout << " |物品 " << i + 1 << ": " << item[i].ItemName;
			cout << "  \t类型: " << ((item[i].ItemType == 0) ? "道具" : "消耗品") << "    "
				<< "  已有: ";
			for (int s = 0; s < BagItemNum; s++)
			{
				if (PlayerBag[s].BagItem.ItemName == item[i].ItemName)
				{
					cout << PlayerBag[s].BagItem.ItemNum;
					p = 1;
				}
			}
			if (p == 1)
			{
				p = 0;
			}
			else
			{
				cout << 0;
			}
			cout << " \t价格: " << item[i].cost << endl;
			cout << " |--------------------------------------------------------------------|" << endl
				<< " |INFO: " << item[i].ItemInfo << endl << endl << endl;
		}

		cout << "请选择要购买的物品(单击选择，输入0退出)" << endl;
		int Select = _getch();
		Select -= 49;

		if (Select >= 0 && Select <= len4)
		{
			cout << "\n购买数量(输入后按下回车):" << endl;
			int Num = 0;
			cin >> Num;

			if (Num * item[Select].cost <= PlayerData[0].gold)
			{
				PlayerData[0].gold -= Num * item[Select].cost;
				item[Select].ShowItem = 1;
				item[Select].ItemNum = Num;

				for (int j = 0; j < len4; j++)
				{
					if (item[Select].ItemName == PlayerBag[j].BagItem.ItemName)
					{
						PlayerBag[j].BagItem.ItemNum += item[Select].ItemNum;
						item[Select].ShowItem = 0;
						item[Select].ItemNum = 0;
					}
				}

				BagItemNum = NumOfItem(PlayerBag, item, len4, BagItemNum);
				CinBagItem(PlayerBag, item, BagItemNum, len4);

				cout << "\n购买了 " << Num << " 个" << item[Select].ItemName << "   花费了: " << Num * item[Select].cost << endl << endl;

				system("pause");
				system("cls");
			}
			else
			{
				cout << "货币不够！" << endl;
				system("pause");
				system("cls");
			}
		}
		else
		{
			return BagItemNum;
			break;
		}
	}
	return BagItemNum;
}
