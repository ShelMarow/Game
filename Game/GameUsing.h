#pragma once
#include<iostream>
#include<Windows.h>
#include "conio.h"
#include<ctime>

using namespace std;

extern struct Player
{
	string PlayerName = "Player";	//玩家名字
	int gold = 0;			//货币
	int SkillPoint = 0;		//技能点
	int PlayerH = 10;		//玩家血量
	int PlayerMaxH = 10;		//玩家最大血量
	int PlayerExp = 0;		//玩家经验值
	int PlayerLv = 1;		//玩家等级
	int PlayerStamina = 10;	//玩家耐力
	int PlayerMaxSta = 10;	//玩家最大耐力值
	int PlayerAtk = 2;		//玩家攻击力
	int PlayerDef = 0;		//玩家防御力
	int IfBattle = 0;		//玩家是否在战斗
	int DiceNum = 6;		//骰子数量
	int DiceEf = 1;			//骰子效果
	int DiceUse = 0;		//骰子使用次数
	int DicePoint = 0;		//骰子点数
	int ExDamage = 0;		//额外造成伤害
	int DeBuff = 0;			//负面效果
	int Buff = 0;
	int IfFirstDead = 0;	//检测是否首次受到致命伤害
};

extern struct PlayerEq
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

extern struct Monster
{
	string MonsterName;	//怪物名字
	int MonsterH;		//怪物血量
	int MonsterMaxH;	//怪物最大血量
	int MonsterAtk;		//怪物基础攻击力
	int MonsterSkill;	//怪物技能轴
	int MonLv;			//怪物等级
	int MonExp;			//掉落经验值
	int Debuff;
};

extern struct SkillList
{
	int ShowSkill;			//是否展示技能
	string SkillName;
	double SkillUse;			//技能使用数值
	int SkillType;
	int SkillCD;
	int SkillCDTime;			//冷却计时器
	int SkillCost;
	int SkillLv;
	int SkillPC;				//技能升级消耗
	string SkillInfo;		//技能信息介绍

};

extern struct SkillUseList
{
	string SkillName = "Unnamed";
	double SkillUse = 0;
	int SkillType = 0;			//技能类型（0为加算攻击，1为乘算攻击,2为增加防御类，3为回复血量类技能，4为回复耐力类技能，5为概率眩晕类技能）
	int SkillCD = 0;
	int SkillCDTime = 0;
	int SkillCost = 0;
	int ShowSkill = 0;
	int SkillLv = 0;
	int SkillPC;
	string SkillInfo = "No Info";
};

extern struct Equipment
{
	int ShowEq = 0;					//是否显示装备
	string EqName = "Unnamed";
	int IfEq = 0;					//是否已装备
	int EqType = 0;					//装备类型（武器0，头盔1，胸甲2，护腿3，靴子4，护符5）
	string EqTypeName = "Unknow";	//装备类型名称
	int EqUse = 0;					//装备数值
	string EqInfo = "No Info";
};

extern struct Item
{
	int ShowItem = 0;
	string ItemName = "Unnamed";
	int ItemNum = 0;
	int ItemType = 0;			//物品类型:0为不可消耗的道具、1为血量消耗类物品、2为耐力消耗类物品、3为护甲消耗类物品、4为伤害消耗类物品
	int ItemUse = 0;
	int cost = 0;				//价格
	string ItemInfo = "No Info";
};

extern struct Bag
{
	Item BagItem;
	Equipment Eq;
};

void PlayerLvUp(Player PlayerData[]);

void PrintHealh(struct Player PlayerData[], struct Monster MonsterData[], int num);

void ShakeScM(struct Player PlayerData[], struct Monster MonsterData[], int num, int Da);

void HealthConrtol(struct Player PlayerData[], struct Monster MonsterData[]);

void StaminaConrtol(struct Player PlayerData[]);

void gotoxy(int x, int y);

int NumOfItem(Bag PlayerBag[], Item item[], int len4, int BagItemNum);

int NumOfEq(Bag PlayerBag[], Equipment Eq[], int len3);

void CinBagItem(Bag PlayerBag[], Item item[], int BagItemNum, int len4);

int ShowBattleBagItem(Player PlayerData[], Bag PlayerBag[], Item item[], Monster MonsterData[], int BagItemNum, int MonNum);

void CinBagEq(Bag PlayerBag[], Equipment Eq[], int BagEqNum);

void ShowBagEq(Bag PlayerBag[], int BagEqNum);

void ShowBag(Bag PlayerBag[], int BagItemNum, int BagEqNum);

void SelectEq(Player PlayerData[], Bag PlayerBag[], PlayerEq PEq[], Equipment Eq[], int BagEqNum);

int CinSkillUse(SkillList SkillData[], SkillUseList SkillUseData[], int len);

int CinSkillSptUse(SkillList SkillSptData[], SkillUseList SkillSptUseData[], int len2);

void SkillLv(Player PlayerData[], SkillList SkillData[], SkillList SkillSptData[],
	SkillUseList SkillLvUp[], SkillUseList SkillUseData[], SkillUseList SkillSptUseData[], int len, int len2);

void ShowPlayerData(Player PlayerData[], Bag PlayerBag[], Equipment Eq[], PlayerEq PEq[], SkillList SkillData[], SkillList SkillSptData[],
	SkillUseList SkillLvUp[], SkillUseList SkillUseData[], SkillUseList SkillSptUseData[], int len, int len2, int BagEqNum);

int Damage(Player PlayerData[], SkillUseList SkillUseData[], int num);

int Death(struct Player PlayerData[], struct Monster MonsterData[]);

int MonsterAI(struct Monster MonsterData[], int MonNum);

int Dice(struct Player PlayerData[]);

int RandomNum();

void DiceEffect(int D, struct Player PlayerData[], Monster MonsterData[], int MonNum);

int SkillSptSystem
(SkillList SkillSptData[], SkillUseList SkillSptUseData[], Player PlayerData[],
	Monster MonsterData[], int MonNum, int len2, int Sk2Num, int FirstExDa);

int SkillSystem(SkillList SkillData[], SkillUseList SkillUseData[],
	Player PlayerData[], Monster MonsterData[], int MonNum, int len, int Sk1Num);

void BattleSystem(Player PlayerData[], SkillList SkillData[], SkillUseList SkillUseData[], SkillList SkillSptData[],
	SkillUseList SkillSptUseData[], SkillUseList SkillLvUp[], Monster MonsterData[], Bag PlayerBag[], Item item[], Equipment Eq[], PlayerEq PEq[]
	, int MonNum, int len, int len2, int ItemNum, int BagEqNum);

int Shop(Player PlayerData[], Bag PlayerBag[], Item item[], int len4, int BagItemNum);