#pragma once
#include<iostream>
#include<Windows.h>
#include "conio.h"
#include<ctime>

using namespace std;

extern struct Player
{
	string PlayerName = "Player";	//�������
	int gold = 0;			//����
	int SkillPoint = 0;		//���ܵ�
	int PlayerH = 10;		//���Ѫ��
	int PlayerMaxH = 10;		//������Ѫ��
	int PlayerExp = 0;		//��Ҿ���ֵ
	int PlayerLv = 1;		//��ҵȼ�
	int PlayerStamina = 10;	//�������
	int PlayerMaxSta = 10;	//����������ֵ
	int PlayerAtk = 2;		//��ҹ�����
	int PlayerDef = 0;		//��ҷ�����
	int IfBattle = 0;		//����Ƿ���ս��
	int DiceNum = 6;		//��������
	int DiceEf = 1;			//����Ч��
	int DiceUse = 0;		//����ʹ�ô���
	int DicePoint = 0;		//���ӵ���
	int ExDamage = 0;		//��������˺�
	int DeBuff = 0;			//����Ч��
	int Buff = 0;
	int IfFirstDead = 0;	//����Ƿ��״��ܵ������˺�
};

extern struct PlayerEq
{
	int hand = 0;
	int head = 0;
	int cheast = 0;
	int legging = 0;
	int boot = 0;
	int other = 0;
	string handS = "��";
	string headS = "��";
	string cheastS = "��";
	string leggingS = "��";
	string bootS = "��";
	string otherS = "��";
};

extern struct Monster
{
	string MonsterName;	//��������
	int MonsterH;		//����Ѫ��
	int MonsterMaxH;	//�������Ѫ��
	int MonsterAtk;		//�������������
	int MonsterSkill;	//���＼����
	int MonLv;			//����ȼ�
	int MonExp;			//���侭��ֵ
	int Debuff;
};

extern struct SkillList
{
	int ShowSkill;			//�Ƿ�չʾ����
	string SkillName;
	double SkillUse;			//����ʹ����ֵ
	int SkillType;
	int SkillCD;
	int SkillCDTime;			//��ȴ��ʱ��
	int SkillCost;
	int SkillLv;
	int SkillPC;				//������������
	string SkillInfo;		//������Ϣ����

};

extern struct SkillUseList
{
	string SkillName = "Unnamed";
	double SkillUse = 0;
	int SkillType = 0;			//�������ͣ�0Ϊ���㹥����1Ϊ���㹥��,2Ϊ���ӷ����࣬3Ϊ�ظ�Ѫ���༼�ܣ�4Ϊ�ظ������༼�ܣ�5Ϊ����ѣ���༼�ܣ�
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
	int ShowEq = 0;					//�Ƿ���ʾװ��
	string EqName = "Unnamed";
	int IfEq = 0;					//�Ƿ���װ��
	int EqType = 0;					//װ�����ͣ�����0��ͷ��1���ؼ�2������3��ѥ��4������5��
	string EqTypeName = "Unknow";	//װ����������
	int EqUse = 0;					//װ����ֵ
	string EqInfo = "No Info";
};

extern struct Item
{
	int ShowItem = 0;
	string ItemName = "Unnamed";
	int ItemNum = 0;
	int ItemType = 0;			//��Ʒ����:0Ϊ�������ĵĵ��ߡ�1ΪѪ����������Ʒ��2Ϊ������������Ʒ��3Ϊ������������Ʒ��4Ϊ�˺���������Ʒ
	int ItemUse = 0;
	int cost = 0;				//�۸�
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