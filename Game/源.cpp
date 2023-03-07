#include<iostream>
#include<Windows.h>
#include "conio.h"
#include<ctime>
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
using namespace std;

struct Player
{
	string PlayerName = "Player";	//玩家名字
	int PlayerH = 10;		//玩家血量
	int PlayerMaxH = 10;		//玩家最大血量
	int PlayerExp = 0;		//玩家经验值
	int PlayerLv = 1;		//玩家等级
	int PlayerStamina = 15;	//玩家耐力
	int PlayerMaxSta = 15;	//玩家最大耐力值
	int PlayerAtk = 2;		//玩家攻击力
	int PlayerDef = 0;		//玩家防御力
	int IfBattle = 0;		//玩家是否在战斗
	int DiceNum = 6;		//骰子数量
	int DiceEf = 1;			//骰子效果
	int DiceUse = 0;		//骰子使用次数
	int DicePoint = 0;		//骰子点数
	int ExDamage = 0;		//额外造成伤害
	int DeBuff = 0;			//负面效果（减少攻击力）
	int Buff = 0;
};

struct PlayerEq
{
	int hand = 0;
	int head = 0;
	int cheast = 0;
	int legging = 0;
	int boot = 0;
	int other = 0;
	string handS = "空";
	string headS = "空";
	string cheastS = "空";
	string leggingS = "空";
	string bootS = "空";
	string otherS = "空";
};

struct Monster
{
	string MonsterName;	//怪物名字
	int MonsterH;		//怪物血量
	int MonsterMaxH;	//怪物最大血量
	int MonsterAtk;		//怪物基础攻击力
	int MonsterSkill;	//怪物技能轴
	int MonLv;			//怪物等级
};

struct SkillList
{
	int ShowSkill;			//是否展示技能
	string SkillName;
	double SkillUse;			//技能使用数值
	int SkillType;			//技能计算类型（0为加算，1为乘算）
	int SkillCD;
	int SkillCDTime;			//冷却计时器
	int SkillCost;
	string SkillInfo;		//技能信息介绍
	
};

struct SkillUseList
{
	string SkillName = "Unnamed";
	double SkillUse = 0; 
	int SkillType = 0;
	int SkillCD = 0;
	int SkillCDTime = 0;
	int SkillCost = 0;
	string SkillInfo = "No Info";
};

struct Equipment
{
	int ShowEq = 0;					//是否显示装备
	string EqName = "Unnamed";
	int IfEq = 0;					//是否已装备
	int EqType = 0;					//装备类型（武器0，头盔1，胸甲2，护腿3，靴子4，护符5）
	string EqTypeName = "Unknow";	//装备类型名称
	int EqUse = 0;					//装备数值
	string EqInfo = "No Info";
};

struct Item
{
	int ShowItem = 0;
	string ItemName = "Unnamed";
	int ItemNum = 0;
	int ItemType = 0;			//物品类型:0为不可消耗的道具、1为血量消耗类物品、2为耐力消耗类物品、3为护甲消耗类物品、4为伤害消耗类物品
	int ItemUse = 0;
	string ItemInfo = "No Info";
};

struct Bag
{
	Item BagItem;
	Equipment Eq;
};

void PrintHealh(struct Player PlayerData[], struct Monster MonsterData[], int num)  //打印血量和基础信息
{
	if (MonsterData[num].MonsterMaxH <= 20)
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
		int PH = 20 * (H / MaxH);
		cout << MonsterData[num].MonsterName << endl
			<< "生命值: " << MonsterData[num].MonsterH
			<< "/" << MonsterData[num].MonsterMaxH << endl;
		for (int b = 0; b < 19; b++)
		{
			cout << "══";
		}
		cout << "═╬ ╲" << endl;
		for (int i = 0; i < PH; i++)
		{
			cout << "■";
		}
		for (int j = 0; j < 20 - PH; j++)
		{
			cout << "□";
		}
		cout << " ╬" << endl;
		for (int b = 0; b < 20; b++)
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
		<< "\t" << "耐力值:" << PlayerData[0].PlayerStamina << "/" << PlayerData[0].PlayerMaxSta << endl;

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
	//测试用代码             
	cout << "玩家攻击力:" << PlayerData[0].PlayerAtk << " * " << PlayerData[0].DiceEf
		<< " + " << PlayerData[0].ExDamage << endl
		<< "玩家防御力: " << PlayerData[0].PlayerDef << endl;
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
		if (MonsterData[num].MonsterMaxH <= 20)
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
			int PH = 20 * (H + Da) / MaxH;
			int PH2 = 20 - PH;
			cout << MonsterData[num].MonsterName << endl
				<< "生命值: " << MonsterData[num].MonsterH
				<< "/" << MonsterData[num].MonsterMaxH << endl;
			for (int b = 0; b < 19; b++)
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
			for (int b = 0; b < 20; b++)
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
			<< "\t" << "耐力值:" << PlayerData[0].PlayerStamina << "/" << PlayerData[0].PlayerMaxSta << endl;
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

int NumOfItem(Bag PlayerBag[], Item item[], int len4)		//统计展示的物品数量
{
	int BagItemNum = 0;
	for (int i = 0; i < len4; i++)					
	{
		if (item[i].ShowItem == 1 && item[i].ItemNum > 0)
		{
			BagItemNum++;
		}
	}
	return BagItemNum;
}

int NumOfEq(Bag PlayerBag[], Equipment Eq[], int len3)		//统计展示的装备数量
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

void CinBagItem(Bag PlayerBag[], Item item[],int BagItemNum)	//将物品写入背包
{
	int bag = 0;
	for (int i = 0; bag < BagItemNum; i++)					//将展示值为1的物品写入背包
	{
		if(item[i].ShowItem == 1 && item[i].ItemNum > 0)
		{
			PlayerBag[bag].BagItem.ItemName = item[i].ItemName;
			PlayerBag[bag].BagItem.ItemType = item[i].ItemType;
			PlayerBag[bag].BagItem.ItemNum = item[i].ItemNum;
			PlayerBag[bag].BagItem.ItemUse = item[i].ItemUse;
			PlayerBag[bag].BagItem.ItemInfo = item[i].ItemInfo;
			item[i].ItemNum = 0;
			item[i].ShowItem = 0;
			bag++;
		}
	}
}

int ShowBattleBagItem(Player PlayerData[],Bag PlayerBag[], Item item[],Monster MonsterData[], int BagItemNum, int MonNum)		//打印背包物品列表
{
	cout << endl << "              |输入“0”返回上个界面|" << endl
		         << "              |---------------------|" << endl << endl;
	if (BagItemNum > 0 )
	{
		for (int j = 0; j < BagItemNum; j++)		
		{
			cout << " |物品 " << j + 1 << ": " << PlayerBag[j].BagItem.ItemName;
			cout << "\t  类型: "<<((PlayerBag[j].BagItem.ItemType == 0) ? "道具":"消耗品" )<< "    "
					 <<"剩余: " << PlayerBag[j].BagItem.ItemNum << endl;
			cout << " |--------------------------------------------------|" << endl
			<<" |INFO: " << PlayerBag[j].BagItem.ItemInfo << endl << endl; 
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
		if (PlayerBag[ItemSelect - 49].BagItem.ItemType == 4 && ItemSelect - 49 < BagItemNum)
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
	else if(BagItemNum == 0)
	{
		cout << "无道具！" << endl<<endl;
		system("pause");
		return -1;
	}
	return BagItemNum;
}

void CinBagEq(Bag PlayerBag[],Equipment Eq[], int BagEqNum)		//将展示值为1的装备写入背包
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

void ShowBagEq(Bag PlayerBag[],int BagEqNum)
{
	int equse = 0;
	cout << endl;
	cout << "                       | -装备- |" << endl;
	cout << "                       |--------|" << endl<<endl;
	for (int i = 0; i < BagEqNum; i++)
	{
		cout << " |装备 " << i + 1 << ": " << PlayerBag[i].Eq.EqName;
		cout << "    类型: " << PlayerBag[i].Eq.EqTypeName << "  "
			<< "装备情况: " << (PlayerBag[i].Eq.IfEq == 0 ? "未装备" : " >已装备<") << endl;
		cout << " |---------------------------------------------------|" << endl;
		cout << " |INFO: " << PlayerBag[i].Eq.EqInfo << endl << endl << endl;
		equse++;
	}
	if (equse == 0)
	{
		cout << "可用装备为空！！！" << endl;
	}
}

void ShowBag(Bag PlayerBag[], int BagItemNum,int BagEqNum)
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
			cout << "类型: " << ((PlayerBag[j].BagItem.ItemType == 0)?"道具":"消耗品") << "    "
				<< "剩余: " << PlayerBag[j].BagItem.ItemNum << endl;
			cout << " |---------------------------------------------------|" << endl
				<< " |INFO: " << PlayerBag[j].BagItem.ItemInfo << endl << endl;
			use++;
		}
	}
	if (use == 0)
	{
		gotoxy(0, y);
		cout <<endl<< "    可用物品为空！！！" << endl;
	}
	y = 4;
	cout << endl;
	gotoxy(60, y);
	cout << "                       | -装备- |";
	gotoxy(60, y+1);
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
		cout << endl <<"    可用装备为空！！！"<<endl;
		gotoxy(60, y + 10);
	}
}

void ShowPlayerData(Player PlayerData[], Bag PlayerBag[], Equipment Eq[], PlayerEq PEq[],int BagEqNum)
{
	system("cls");
	int y = 6;
	int i = 1;
	while (1)
	{
		system("cls");
		cout << endl << "\t\t\t\t\t       |玩家信息|" << endl
			<< "\t\t\t\t\t       |--------|" << endl << endl;
		cout << "\t\t\t\t       |--按“I”键进入装备模式--|" << endl;
		cout << "                 |装备信息|" << endl
			<< "                 |--------|" << endl << endl;
		cout << "|头部: " << PEq[0].headS << endl << "|------------------|"
			<< "\t|武器: " << PEq[0].handS << endl << "\t\t\t|------------------|\n";
		cout << "|胸甲: " << PEq[0].cheastS << endl << "|------------------|"
			<< "\t|饰品: " << PEq[0].otherS << endl << "\t\t\t|------------------|\n";
		cout << "|腿部: " << PEq[0].leggingS << endl << "|------------------|\n" << endl;
		cout << "|靴子: " << PEq[0].bootS << endl << "|------------------|\n" << endl;

		//玩家属性输出
		{
			gotoxy(60, 5);
			cout << "                 |玩家属性|";
			gotoxy(60, 6);
			cout << "                 |--------|";
			gotoxy(60, 8);
			cout << "|玩家: " << PlayerData[0].PlayerName;
			gotoxy(60, 9);
			cout << "|------------------|";
			gotoxy(84, 8);
			cout << "|等级: " << PlayerData[0].PlayerLv;
			gotoxy(84, 9);
			cout << "|------------------|";
			gotoxy(60, 11);
			cout << "|生命值: " << PlayerData[0].PlayerH << "/" << PlayerData[0].PlayerMaxH;
			gotoxy(60, 12);
			cout << "|------------------|";
			gotoxy(84, 11);
			cout << "|经验值: " << PlayerData[0].PlayerExp << "/" << PlayerData[0].PlayerLv * (PlayerData[0].PlayerLv + 10) - 1;
			gotoxy(84, 12);
			cout << "|------------------|";
			gotoxy(60, 14);
			cout << "|攻击力: " << PlayerData[0].PlayerAtk;
			gotoxy(60, 15);
			cout << "|------------------|";
			gotoxy(84, 14);
			cout << "|命运骰子: " << PlayerData[0].DiceNum << " 个";
			gotoxy(84, 15);
			cout << "|------------------|";
			gotoxy(60, 17);
			cout << "|耐力: " << PlayerData[0].PlayerStamina << "/" << PlayerData[0].PlayerMaxSta;
			gotoxy(60, 18);
			cout << "|------------------|";
			gotoxy(84, 17);
			cout << "|耐力回复: " << (PlayerData[0].PlayerLv  / 2) + 1;
			gotoxy(84, 18);
			cout << "|------------------|";
		}

		char EqMode;
		EqMode = _getch();
		if (EqMode == 105 && PlayerData[0].IfBattle == 0)
		{
			system("cls");
			cout << endl << "\t\t   |-选择调整装备的位置-|" << endl;
			cout		 << "\t\t   |--------------------|\n"
						 << "\t\t   |---输入其他键退出---|" << endl << endl;
			cout <<  ">>1-武器 || 2-头部 || 3-胸甲 || 4-腿部 || 5-靴子 || 6-饰品<<\n";
			int EqSelect;
			EqSelect = _getch();
			switch (EqSelect)
			{
			case 49:
			{
				system("cls");
				cout << endl << "\t\t  |-选择要调整的装备-|\n" << endl;
				cout		 << "\t\t  |-------武器-------|\n\n"
							 << "\t\t   |-输入其他键退出-|" << endl;
				ShowBagEq(PlayerBag, BagEqNum);
				EqSelect = _getch();
				if (EqSelect > 48 && EqSelect < BagEqNum + 49)
				{
					if (PlayerBag[EqSelect - 49].Eq.IfEq == 1 && PlayerBag[EqSelect - 49].Eq.EqType == 0 && PEq[0].hand == 1)
					{
						PlayerBag[EqSelect - 49].Eq.IfEq = 0;
						PEq[0].hand = 0;
						PEq[0].handS = "空";
						system("cls");
						ShowBagEq(PlayerBag, BagEqNum);
						cout << "已卸下装备 " << PlayerBag[EqSelect - 49].Eq.EqName << endl << endl;
					}
					else if (PlayerBag[EqSelect - 49].Eq.IfEq == 0 && PlayerBag[EqSelect - 49].Eq.EqType == 0 && PEq[0].hand == 1)
					{
						system("cls");
						ShowBagEq(PlayerBag, BagEqNum);
						cout << "当前位置已有装备，请先卸下装备！\n\n";
					}
					else if (PlayerBag[EqSelect - 49].Eq.IfEq == 0 && PlayerBag[EqSelect - 49].Eq.EqType == 0 && PEq[0].hand == 0)
					{
						system("cls");
						PlayerBag[EqSelect - 49].Eq.IfEq = 1;
						PEq[0].hand = 1;
						PEq[0].handS = PlayerBag[EqSelect - 49].Eq.EqName;
						ShowBagEq(PlayerBag, BagEqNum);
						cout << "已装备 " << PlayerBag[EqSelect - 49].Eq.EqName << endl << endl;
					}
					else
					{
						system("cls");
						ShowBagEq(PlayerBag, BagEqNum);
						cout << "当前位置不可装备该物品!\n\n";
						break;
					}
					if (PEq[0].hand == 1)
					{
						PlayerData[0].PlayerAtk += PlayerBag[EqSelect - 49].Eq.EqUse;
					}
					else if (PEq[0].hand == 0)
					{
						PlayerData[0].PlayerAtk -= PlayerBag[EqSelect - 49].Eq.EqUse;
					}
					system("pause");
				}
			}
			break;
			case 50:
			{
				system("cls");
				cout << endl << "\t\t  |-选择要调整的装备-|\n" << endl;
				cout << "\t\t  |-------头部-------|\n\n"
					<< "\t\t   |-输入其他键退出-|" << endl;
				ShowBagEq(PlayerBag, BagEqNum);
				EqSelect = _getch();
				if (EqSelect > 48 && EqSelect < BagEqNum + 49)
				{
					if (PlayerBag[EqSelect - 49].Eq.IfEq == 1 && PlayerBag[EqSelect - 49].Eq.EqType == 1 && PEq[0].head == 1)
				{
					PlayerBag[EqSelect - 49].Eq.IfEq = 0;
					PEq[0].head = 0;
					PEq[0].headS = "空";
					system("cls");
					ShowBagEq(PlayerBag, BagEqNum);
					cout << "已卸下装备 " << PlayerBag[EqSelect - 49].Eq.EqName << endl << endl;
				}
					else if (PlayerBag[EqSelect - 49].Eq.IfEq == 0 && PlayerBag[EqSelect - 49].Eq.EqType == 1 && PEq[0].head == 1)
				{
					system("cls");
					ShowBagEq(PlayerBag, BagEqNum);
					cout << "当前位置已有装备，请先卸下装备！\n\n";
				}
					else if (PlayerBag[EqSelect - 49].Eq.IfEq == 0 && PlayerBag[EqSelect - 49].Eq.EqType == 1 && PEq[0].head == 0)
				{
					system("cls");
					PlayerBag[EqSelect - 49].Eq.IfEq = 1;
					PEq[0].head = 1;
					PEq[0].headS = PlayerBag[EqSelect - 49].Eq.EqName;
					ShowBagEq(PlayerBag, BagEqNum);
					cout << "已装备 " << PlayerBag[EqSelect - 49].Eq.EqName << endl << endl;
				}
					else
				{
					system("cls");
					ShowBagEq(PlayerBag, BagEqNum);
					cout << "当前位置不可装备该物品!\n\n";
					break;
				}
					if (PEq[0].head == 1)
				{
					PlayerData[0].PlayerMaxH += (PlayerBag[EqSelect - 49].Eq.EqUse / 3) + 1;
					PlayerData[0].PlayerMaxSta += PlayerBag[EqSelect - 49].Eq.EqUse;
				}
					else if (PEq[0].head == 0)
				{
					PlayerData[0].PlayerMaxH -= (PlayerBag[EqSelect - 49].Eq.EqUse / 3) + 1;
					PlayerData[0].PlayerMaxSta -= PlayerBag[EqSelect - 49].Eq.EqUse;
				}
					system("pause");
				}
			}
			break;
			case 51:
			{
				system("cls");
				cout << endl << "\t\t  |-选择要调整的装备-|\n" << endl;
				cout << "\t\t  |-------胸甲-------|\n\n"
					<< "\t\t   |-输入其他键退出-|" << endl;
				ShowBagEq(PlayerBag, BagEqNum);
				EqSelect = _getch();
				if (EqSelect > 48 && EqSelect < BagEqNum + 49)
				{
					if (PlayerBag[EqSelect - 49].Eq.IfEq == 1 && PlayerBag[EqSelect - 49].Eq.EqType == 2 && PEq[0].cheast == 1)
					{
						PlayerBag[EqSelect - 49].Eq.IfEq = 0;
						PEq[0].cheast = 0;
						PEq[0].cheastS = "空";
						system("cls");
						ShowBagEq(PlayerBag, BagEqNum);
						cout << "已卸下装备 " << PlayerBag[EqSelect - 49].Eq.EqName << endl << endl;
					}
					else if (PlayerBag[EqSelect - 49].Eq.IfEq == 0 && PlayerBag[EqSelect - 49].Eq.EqType == 2 && PEq[0].cheast == 1)
					{
						system("cls");
						ShowBagEq(PlayerBag, BagEqNum);
						cout << "当前位置已有装备，请先卸下装备！\n\n";
					}
					else if (PlayerBag[EqSelect - 49].Eq.IfEq == 0 && PlayerBag[EqSelect - 49].Eq.EqType == 2 && PEq[0].cheast == 0)
					{
						system("cls");
						PlayerBag[EqSelect - 49].Eq.IfEq = 1;
						PEq[0].cheast = 1;
						PEq[0].cheastS = PlayerBag[EqSelect - 49].Eq.EqName;
						ShowBagEq(PlayerBag, BagEqNum);
						cout << "已装备 " << PlayerBag[EqSelect - 49].Eq.EqName << endl << endl;
					}
					else
					{
						system("cls");
						ShowBagEq(PlayerBag, BagEqNum);
						cout << "当前位置不可装备该物品!\n\n";
						break;
					}
					if (PEq[0].cheast == 1)
					{
						PlayerData[0].PlayerMaxH += PlayerBag[EqSelect - 49].Eq.EqUse;
						PlayerData[0].PlayerMaxSta += PlayerBag[EqSelect - 49].Eq.EqUse;
					}
					else if (PEq[0].cheast == 0)
					{
						PlayerData[0].PlayerMaxH -= PlayerBag[EqSelect - 49].Eq.EqUse;
						PlayerData[0].PlayerMaxSta -= PlayerBag[EqSelect - 49].Eq.EqUse;
					}
					system("pause");
				}
			}
			break;
			case 52:
			{
				cout << endl << "\t\t  |-选择要调整的装备-|\n" << endl;
				cout << "\t\t  |-------腿部-------|\n\n"
					<< "\t\t   |-输入其他键退出-|" << endl;
				ShowBagEq(PlayerBag, BagEqNum);
				EqSelect = _getch();
				if (EqSelect > 48 && EqSelect < BagEqNum + 49)
				{
					if (PlayerBag[EqSelect - 49].Eq.IfEq == 1 && PlayerBag[EqSelect - 49].Eq.EqType == 3 && PEq[0].legging == 1)
					{
						PlayerBag[EqSelect - 49].Eq.IfEq = 0;
						PEq[0].legging = 0;
						PEq[0].leggingS = "空";
						system("cls");
						ShowBagEq(PlayerBag, BagEqNum);
						cout << "已卸下装备 " << PlayerBag[EqSelect - 49].Eq.EqName << endl << endl;
					}
					else if (PlayerBag[EqSelect - 49].Eq.IfEq == 0 && PlayerBag[EqSelect - 49].Eq.EqType == 3 && PEq[0].legging == 1)
					{
						system("cls");
						ShowBagEq(PlayerBag, BagEqNum);
						cout << "当前位置已有装备，请先卸下装备！\n\n";
					}
					else if (PlayerBag[EqSelect - 49].Eq.IfEq == 0 && PlayerBag[EqSelect - 49].Eq.EqType == 3 && PEq[0].legging == 0)
					{
						system("cls");
						PlayerBag[EqSelect - 49].Eq.IfEq = 1;
						PEq[0].legging = 1;
						PEq[0].leggingS = PlayerBag[EqSelect - 49].Eq.EqName;
						ShowBagEq(PlayerBag, BagEqNum);
						cout << "已装备 " << PlayerBag[EqSelect - 49].Eq.EqName << endl << endl;
					}
					else
					{
						system("cls");
						ShowBagEq(PlayerBag, BagEqNum);
						cout << "当前位置不可装备该物品!\n\n";
						break;
					}
					if (PEq[0].legging == 1)
					{
						PlayerData[0].PlayerMaxH += (PlayerBag[EqSelect - 49].Eq.EqUse / 2) + 1;
						PlayerData[0].PlayerMaxSta += PlayerBag[EqSelect - 49].Eq.EqUse;
					}
					else if (PEq[0].legging == 0)
					{
						PlayerData[0].PlayerMaxH -= (PlayerBag[EqSelect - 49].Eq.EqUse / 2) + 1;
						PlayerData[0].PlayerMaxSta -= PlayerBag[EqSelect - 49].Eq.EqUse;
					}
					system("pause");
				}
			}
			break;
			case 53:
			{
				system("cls");
				cout << endl << "\t\t  |-选择要调整的装备-|\n" << endl;
				cout		 << "\t\t  |-------靴子-------|\n\n"
					<< "\t\t   |-输入其他键退出-|" << endl;
				ShowBagEq(PlayerBag, BagEqNum);
				EqSelect = _getch();
				if (EqSelect > 48 && EqSelect < BagEqNum + 49)
				{
					if (PlayerBag[EqSelect - 49].Eq.IfEq == 1 && PlayerBag[EqSelect - 49].Eq.EqType == 4 && PEq[0].boot == 1)
					{
						PlayerBag[EqSelect - 49].Eq.IfEq = 0;
						PEq[0].boot = 0;
						PEq[0].bootS = "空";
						system("cls");
						ShowBagEq(PlayerBag, BagEqNum);
						cout << "已卸下装备 " << PlayerBag[EqSelect - 49].Eq.EqName << endl << endl;
					}
					else if (PlayerBag[EqSelect - 49].Eq.IfEq == 0 && PlayerBag[EqSelect - 49].Eq.EqType == 4 && PEq[0].boot == 1)
					{
						system("cls");
						ShowBagEq(PlayerBag, BagEqNum);
						cout << "当前位置已有装备，请先卸下装备！\n\n";
					}
					else if (PlayerBag[EqSelect - 49].Eq.IfEq == 0 && PlayerBag[EqSelect - 49].Eq.EqType == 4 && PEq[0].boot == 0)
					{
						system("cls");
						PlayerBag[EqSelect - 49].Eq.IfEq = 1;
						PEq[0].boot = 1;
						PEq[0].bootS = PlayerBag[EqSelect - 49].Eq.EqName;
						ShowBagEq(PlayerBag, BagEqNum);
						cout << "已装备 " << PlayerBag[EqSelect - 49].Eq.EqName << endl << endl;
					}
					else
					{
						system("cls");
						ShowBagEq(PlayerBag, BagEqNum);
						cout << "当前位置不可装备该物品!\n\n";
						break;
					}
					if (PEq[0].boot == 1)
					{
						PlayerData[0].PlayerMaxH += (PlayerBag[EqSelect - 49].Eq.EqUse / 3) + 1;
						PlayerData[0].PlayerMaxSta += PlayerBag[EqSelect - 49].Eq.EqUse;
					}
					else if (PEq[0].boot == 0)
					{
						PlayerData[0].PlayerMaxH -= (PlayerBag[EqSelect - 49].Eq.EqUse / 3) + 1;
						PlayerData[0].PlayerMaxSta -= PlayerBag[EqSelect - 49].Eq.EqUse;
					}
					system("pause");
				}
			}
			break;
			case 54:
			{
				system("cls");
				cout << endl << "\t\t  |-选择要调整的装备-|\n" << endl;
				cout		 << "\t\t  |-------护符-------|\n\n"
					<< "\t\t   |-输入其他键退出-|" << endl;
				ShowBagEq(PlayerBag, BagEqNum);
				EqSelect = _getch();
				if (EqSelect > 48 && EqSelect < BagEqNum + 49)
				{
					if (PlayerBag[EqSelect - 49].Eq.IfEq == 1 && PlayerBag[EqSelect - 49].Eq.EqType == 5 && PEq[0].other == 1)
					{
						PlayerBag[EqSelect - 49].Eq.IfEq = 0;
						PEq[0].other = 0;
						PEq[0].otherS = "空";
						system("cls");
						ShowBagEq(PlayerBag, BagEqNum);
						cout << "已卸下装备 " << PlayerBag[EqSelect - 49].Eq.EqName << endl << endl;
					}
					else if (PlayerBag[EqSelect - 49].Eq.IfEq == 0 && PlayerBag[EqSelect - 49].Eq.EqType == 5 && PEq[0].other == 1)
					{
						system("cls");
						ShowBagEq(PlayerBag, BagEqNum);
						cout << "当前位置已有装备，请先卸下装备！\n\n";
					}
					else if (PlayerBag[EqSelect - 49].Eq.IfEq == 0 && PlayerBag[EqSelect - 49].Eq.EqType == 5 && PEq[0].other == 0)
					{
						system("cls");
						PlayerBag[EqSelect - 49].Eq.IfEq = 1;
						PEq[0].other = 1;
						PEq[0].otherS = PlayerBag[EqSelect - 49].Eq.EqName;
						ShowBagEq(PlayerBag, BagEqNum);
						cout << "已装备 " << PlayerBag[EqSelect - 49].Eq.EqName << endl << endl;
					}
					else
					{
						system("cls");
						ShowBagEq(PlayerBag, BagEqNum);
						cout << "当前位置不可装备该物品!\n\n";
						break;
					}
					system("pause");
				}
			}
			break;
			default:
				break;
			}
		}
		else if(EqMode == 105 && PlayerData[0].IfBattle == 1)
		{
			system("cls");
			cout <<endl<< "\t战斗中无法切换装备！" << endl << endl;
			system("pause");
			break;
		}
		else
		{
			system("cls");
			break;
		}
	}
}

int Damage(struct Player PlayerData[],struct SkillUseList SkillUseData[],int num)		//玩家造成的伤害
{
	int damage;
	if (SkillUseData[num-1].SkillType == 0)
	{
		damage = PlayerData[0].PlayerAtk * PlayerData[0].DiceEf + SkillUseData[num - 1].SkillUse + PlayerData[0].ExDamage;
	}
	else if (SkillUseData[num-1].SkillType == 1)
	{
		damage = PlayerData[0].PlayerAtk * PlayerData[0].DiceEf * SkillUseData[num - 1].SkillUse + PlayerData[0].ExDamage;
	}
	else
	{
		return 0;
	}
	return damage;
}

int Death(struct Player PlayerData[],struct Monster MonsterData[])	//检测玩家和敌人死亡
{
	int a = 0;
	if (PlayerData->PlayerH <=0)
	{
		cout <<endl<< "你输了！" << endl;
		a = 1;
	}
	else if (MonsterData->MonsterH <=0)
	{
		cout <<endl<< "怪物已被击败！" << endl;
		a = 2;
	}
	return a;
}

int MonsterAI(struct Monster MonsterData[],int MonNum)	//怪物AI
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
	if (PlayerData->DiceNum> 0)
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

void DiceEffect(int D,struct Player PlayerData[], Monster MonsterData[], int MonNum)		//骰子效果
{
	switch (D)
	{
	case 1:
	{
		system("cls");
		cout << "你的回合<<" << endl << endl;
		PrintHealh(PlayerData, MonsterData, MonNum);
		cout << endl << "你投出了点数: " << D << endl<<endl;
		cout << "什么也没有发生 "<< endl << endl;
		system("pause");
	}
	
		break;
	case 2:
	{
		system("cls");
		PlayerData[0].PlayerH += 2; 
		HealthConrtol(PlayerData, MonsterData);
		cout << "你的回合<<" << endl << endl;
		PrintHealh(PlayerData, MonsterData, MonNum);
		cout << endl << "你投出了点数: " << D << endl<<endl;
		cout << "回复了2点生命值 " << endl << endl;
		system("pause");
	}
		break;
	case 3:
	{
		system("cls");
		PlayerData[0].PlayerStamina += 5;
		StaminaConrtol(PlayerData);
		cout << "你的回合<<" << endl << endl;
		PrintHealh(PlayerData, MonsterData, MonNum);
		cout << endl << "你投出了点数: " << D << endl<<endl;
		cout << "回复了5点耐力值 "<< endl << endl;
		system("pause");
	}
		break;
	case 4:
	{
		PlayerData[0].ExDamage += (PlayerData[0].PlayerAtk*10/2)/10;
		system("cls");
		cout << "你的回合<<" << endl << endl;
		PrintHealh(PlayerData, MonsterData, MonNum);
		cout << endl << "你投出了点数: " << D << endl<<endl;
		cout << "攻击额外造成相当于玩家攻击力一半的伤害\n持续一回合，不可叠加 "<< endl << endl;
		system("pause");
	}
		break;
	case 5:
	{
		PlayerData[0].PlayerH += 5; 
		HealthConrtol(PlayerData, MonsterData);
		system("cls");
		cout << "你的回合<<" << endl << endl;
		PrintHealh(PlayerData, MonsterData, MonNum);
		cout << endl << "你投出了点数: " << D << endl<<endl;
		cout << "回复了5点生命值 "<< endl<<endl;
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
		cout << "玩家的攻击力提升100%\n持续一回合，不可叠加" << endl << endl;
		system("pause");
	}
		break;
	default:
		cout << endl << "骰子已经用完！" << endl << endl;
		system("pause");
		break;
	}
}

int CinSkillUse(SkillList SkillData[], SkillUseList SkillUseData[], int len)   //写入使用表
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
			Sk2Num++;
		}
	}
	return Sk2Num;
}

int SkillSptSystem			
(SkillList SkillSptData[], SkillUseList SkillSptUseData[], Player PlayerData[],
	Monster MonsterData[], int MonNum, int len2, int Sk2Num,int FirstExDa)//支援技能系统
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
		cout<<"| 消耗: " << SkillSptUseData[i].SkillCost
			<< " | CD: " << SkillSptUseData[i].SkillCDTime << "/"
			<< SkillSptUseData[i].SkillCD<<" |    "<< r << endl
			<< " |----------------------------------------------------------------------------|" << endl
			<< " |INFO: " << SkillSptUseData[i].SkillInfo << endl << endl;
	}
	cout;
	int ef = 0;
	char select;
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
		(ef ==1)? (PlayerData[0].ExDamage = FirstExDa ,PlayerData[0].DiceEf = 1):0;
		
		DiceEffect(select, PlayerData, MonsterData, MonNum);
		system("cls");
		return 0;
	}
	else if(select > 49 && select <= Sk2Num + 49 )
	{
		if (SkillSptUseData[select - 50].SkillCDTime == 0)
		{
			if (PlayerData[0].PlayerStamina >= SkillSptUseData[select - 2].SkillCost)
			{
				SkillSptUseData[select - 50].SkillCDTime = SkillSptUseData[select - 50].SkillCD + 1;

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
				else if (SkillSptUseData[select - 50].SkillType == 2)
				{
					system("cls");

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
				else
				{
					return -1;
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
	cout << endl <<"                            |输入“0”返回上个界面|" <<endl
		         <<"                            |---------------------|" << endl<<endl;
	for (int i = 0; i < Sk1Num ; i++)
	{
		gotoxy(0, y + i*5);
		string r = SkillUseData[i].SkillCDTime == 0 ? "-->> READY <<--" : "";
		cout << endl
			<< " |战斗技能 " << i + 1 << ": <" << SkillUseData[i].SkillName << "> ";
		gotoxy(38,y+i*5+1);
		cout<<"| 消耗: " << SkillUseData[i].SkillCost
			<< " | CD: " << SkillUseData[i].SkillCDTime << "/"
			<< SkillUseData[i].SkillCD << " |    " << r << endl;
			cout <<" |----------------------------------------------------------------------------|" << endl
			<<" |INFO: " << SkillUseData[i].SkillInfo << endl<<endl;
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

				if(SkillUseData[select - 49].SkillType == 0 || SkillUseData[select - 49].SkillType == 1)
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
	SkillUseList SkillSptUseData[], Monster MonsterData[], Bag PlayerBag[], Item item[], Equipment Eq[],PlayerEq PEq[]
	,int MonNum, int len, int len2, int ItemNum, int BagEqNum)//战斗系统
{
	PlayerData[0].IfBattle = 0;
	int FirstExDa = PlayerData[0].ExDamage;
	int dth = 0;
	int SK2Sel = 0;
	int Sk1Num = CinSkillUse(SkillData, SkillUseData, len);
	int Sk2Num = CinSkillSptUse(SkillSptData,SkillSptUseData,len2);
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
				int DaNum = SkillSystem(SkillData, SkillUseData, PlayerData, MonsterData, MonNum, len ,Sk1Num);
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
				else if(DaNum == 2)
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
				if (SK2Sel == 2)
				{
					system("cls");
					cout << "你的回合<<" << endl << endl;
					PrintHealh(PlayerData, MonsterData, MonNum);
					cout << endl << "技能正在冷却！" << endl << endl;
					system("pause");
					system("cls");
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
				else if (SK2Sel == 0)
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
				system("cls");
			}
				break;
			case 51:
			{
				system("cls");
				cout << "你的回合<<" << endl << endl;
				PrintHealh(PlayerData, MonsterData, MonNum);

				int BIN = ShowBattleBagItem(PlayerData,PlayerBag,item, MonsterData ,ItemNum , MonNum);
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
				ShowPlayerData(PlayerData,PlayerBag, Eq, PEq,BagEqNum);
				system("cls");
			}
				break;
			case 53:
			{
				for (int j = 0; j < len; j++)
				{
					if (SkillUseData[j].SkillCDTime > 0)
					{
						SkillUseData[j].SkillCDTime--;
					}
				}
				cout << endl <<"已跳过回合" << endl << endl;
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
		}
		else if (i == 1 && dth == 0)
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
			if (SK2Sel == 0)		//判断怪物造成的伤害是否为正
			{
				MDa = MonsterAI(MonsterData, MonNum) - PlayerData[0].PlayerDef;
				if (MDa < 0)
				{
					MDa = 0;
				}
				PlayerData[0].PlayerH -= MDa;
			}
			else
			{
				MDa = MonsterAI(MonsterData, MonNum);
				PlayerData[0].PlayerH -= MDa;
			}
			HealthConrtol(PlayerData, MonsterData);

			cout << ">>敌方回合" << endl << endl;
			PrintHealh(PlayerData, MonsterData, MonNum);
			cout << endl << "敌人对你造成了 " << MDa << " 点伤害" << endl << endl;
			system("pause");
			system("cls");
			PlayerData[0].PlayerDef = 0;
			PlayerData[0].PlayerStamina += (PlayerData[0].PlayerLv / 2) + 1;
			StaminaConrtol(PlayerData);
			i--;
		}
		else if (dth == 1 || dth == 2)
		{
			cout << endl << "战斗结束" << endl << endl;
			PlayerData[0].IfBattle = 0;
			system("pause");
			system("cls");
			break;
		}
	}
}

void Shop()
{

}

int main()
{
	srand((unsigned int)time(NULL));
	struct Player PlayerData[1];
	struct PlayerEq PEq[1];
									//怪物名字、怪物血量、怪物最大血量、怪物基础攻击力、怪物技能轴、怪物等级
	struct Monster MonsterData[] = { {"测试怪物",20,20,1,0,0},
									{"怪物A",10,10,1,0,0} }; 

	              //分别为是否显示技能、技能名字、技能伤害计算数值、技能类型、技能CD、CDTime、技能消耗、技能介绍
	struct SkillList SkillData[] = { {1,"光剑劈砍★☆☆",1,1,0,0,1,"造成基础攻击100%伤害"},
									 {1,"MK2自卫手枪★☆☆",3,0,3,0,4,"基础攻击力+3"},
									 {1,"热能爆破★☆☆",2,1,3,1,3,"造成基础攻击200%的伤害"}
								    };
	int len = sizeof SkillData / sizeof SkillData[0];
	struct SkillUseList SkillUseData[20];

				 //分别为是否显示技能、技能名字、技能伤害计算数值、技能类型、技能CD、CDTime、技能消耗、技能介绍
	struct SkillList SkillSptData[] = { {1,"招架★☆☆",2,3,4,3,5,"防御，使受到的伤害降低2点"},
										{1,"紧急包扎★☆☆",3,2,7,4,6,"回复玩家3点生命值"} 
									   };
	int len2 = sizeof SkillSptData / sizeof SkillSptData[0];
	struct SkillUseList SkillSptUseData[20];

	//是否显示装备、装备名字、是否已装备、装备类型、装备类型名称、装备数值、装备介绍
	struct Equipment Eq[] = { {0,"剑",0,0,"武器",10,"No Info"},
							  {0,"安全帽",0,1,"头盔",10,"No Info"},
							  {1,"防弹衣",0,2,"胸甲",10,"No Info"},
							  {0,"护腿",0,3,"护腿",10,"No Info"},
							  {1,"长筒靴子",0,4,"靴子",10,"No Info"},
							  {1,"护身符",0,5,"护符",0,"No Info"}
							 };
	int len3 = sizeof Eq / sizeof Eq[0];

	//是否显示物品、物品名字、物品数量、物品类型、物品数值、物品介绍
	struct Item item[] = {	{0,"血瓶",3,1,5,"回复5点生命值"},
							{1,"耐力药水",3,2,6,"回复6点耐力值"},
							{0,"能量盾",3,3,2,"护盾值+2"},
							{1,"力量",3,4,2,"下回合额外伤害+2"}
						 };
	int len4 = sizeof item / sizeof item[0];

	struct Bag PlayerBag[30];

	//初始化玩家数据
	{
	PlayerData[0].PlayerExp = 0;
	PlayerData[0].PlayerLv = 6;
	PlayerData[0].PlayerMaxH = 10;
	PlayerData[0].PlayerH = 10;
	PlayerData[0].PlayerAtk = 3;
	PlayerData[0].PlayerName = "Player";
	PlayerData[0].DiceNum = 30;
	PlayerData[0].PlayerMaxSta = 15;
	PlayerData[0].PlayerStamina = 15;
	PlayerData[0].DiceEf = 1;
	PlayerData[0].ExDamage = 0;
	PlayerData[0].PlayerDef = 0; 
	}




	//统计物品装备数量
	int BagEqNum = NumOfEq(PlayerBag, Eq, len3);
	int BagItemNum = NumOfItem(PlayerBag, item, len4);
	cout << "装备数量: " << BagEqNum << endl;
	cout << "物品数量: " << BagItemNum << endl;
	system("pause");

	//往玩家背包写入物品装备
	CinBagEq(PlayerBag, Eq,BagEqNum);
	CinBagItem(PlayerBag, item,BagItemNum);

	ShowPlayerData(PlayerData, PlayerBag, Eq, PEq, BagEqNum);

	int MonNum = 0;
	BattleSystem(PlayerData, SkillData, SkillUseData, SkillSptData, SkillSptUseData, MonsterData,
		PlayerBag,item,Eq,PEq,MonNum, len ,len2, BagItemNum, BagEqNum);

	system("cls");

	ShowBag(PlayerBag, BagItemNum, BagEqNum);





	cout << "Game End" << endl;

	system("pause");

	return 0;
}