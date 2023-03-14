#include<iostream>
#include"GameUsing.h"
#include<Windows.h>
#include "conio.h"
#include<ctime>
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

using namespace std;

//extern struct Player
//{
//	string PlayerName = "Player";	//�������
//	int gold = 0;			//����
//	int SkillPoint = 0;		//���ܵ�
//	int PlayerH = 10;		//���Ѫ��
//	int PlayerMaxH = 10;		//������Ѫ��
//	int PlayerExp = 0;		//��Ҿ���ֵ
//	int PlayerLv = 1;		//��ҵȼ�
//	int PlayerStamina = 10;	//�������
//	int PlayerMaxSta = 10;	//����������ֵ
//	int PlayerAtk = 2;		//��ҹ�����
//	int PlayerDef = 0;		//��ҷ�����
//	int IfBattle = 0;		//����Ƿ���ս��
//	int DiceNum = 6;		//��������
//	int DiceEf = 1;			//����Ч��
//	int DiceUse = 0;		//����ʹ�ô���
//	int DicePoint = 0;		//���ӵ���
//	int ExDamage = 0;		//��������˺�
//	int DeBuff = 0;			//����Ч��
//	int Buff = 0;
//	int IfFirstDead = 0;	//����Ƿ��״��ܵ������˺�
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
//	string handS = "��";
//	string headS = "��";
//	string cheastS = "��";
//	string leggingS = "��";
//	string bootS = "��";
//	string otherS = "��";
//};
//
//extern struct Monster
//{
//	string MonsterName;	//��������
//	int MonsterH;		//����Ѫ��
//	int MonsterMaxH;	//�������Ѫ��
//	int MonsterAtk;		//�������������
//	int MonsterSkill;	//���＼����
//	int MonLv;			//����ȼ�
//	int MonExp;			//���侭��ֵ
//	int Debuff;
//};
//
//extern struct SkillList
//{
//	int ShowSkill;			//�Ƿ�չʾ����
//	string SkillName;
//	double SkillUse;			//����ʹ����ֵ
//	int SkillType;
//	int SkillCD;
//	int SkillCDTime;			//��ȴ��ʱ��
//	int SkillCost;
//	int SkillLv;
//	int SkillPC;				//������������
//	string SkillInfo;		//������Ϣ����
//
//};
//
//extern struct SkillUseList
//{
//	string SkillName = "Unnamed";
//	double SkillUse = 0;
//	int SkillType = 0;			//�������ͣ�0Ϊ���㹥����1Ϊ���㹥��,2Ϊ���ӷ����࣬3Ϊ�ظ�Ѫ���༼�ܣ�4Ϊ�ظ������༼�ܣ�5Ϊ����ѣ���༼�ܣ�
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
//	int ShowEq = 0;					//�Ƿ���ʾװ��
//	string EqName = "Unnamed";
//	int IfEq = 0;					//�Ƿ���װ��
//	int EqType = 0;					//װ�����ͣ�����0��ͷ��1���ؼ�2������3��ѥ��4������5��
//	string EqTypeName = "Unknow";	//װ����������
//	int EqUse = 0;					//װ����ֵ
//	string EqInfo = "No Info";
//};
//
//extern struct Item
//{
//	int ShowItem = 0;
//	string ItemName = "Unnamed";
//	int ItemNum = 0;
//	int ItemType = 0;			//��Ʒ����:0Ϊ�������ĵĵ��ߡ�1ΪѪ����������Ʒ��2Ϊ������������Ʒ��3Ϊ������������Ʒ��4Ϊ�˺���������Ʒ
//	int ItemUse = 0;
//	int cost = 0;				//�۸�
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
			cout << endl << "��ҵȼ�����!!!\n\n�ȼ�: " << PlayerData[0].PlayerLv << endl << endl
				<< "�������ֵ������ " << PlayerData[0].PlayerMaxH
				<< "    ������������� " << PlayerData[0].PlayerMaxSta
				<< "    ������������ " << PlayerData[0].PlayerAtk << endl << endl;
			system("pause");
			system("cls");
		}
	}
}

void PrintHealh(struct Player PlayerData[], struct Monster MonsterData[], int num)  //��ӡѪ���ͻ�����Ϣ
{
	if (MonsterData[num].MonsterMaxH <= 50)
	{
		cout << MonsterData[num].MonsterName << endl
			<< "����ֵ: " << MonsterData[num].MonsterH
			<< "/" << MonsterData[num].MonsterMaxH << endl;
		for (int b = 0; b < MonsterData[num].MonsterMaxH - 1; b++)
		{
			cout << "�T�T";
		}
		cout << "�T�p �v" << endl;
		for (int i = 0; i < MonsterData[num].MonsterH; i++)
		{
			cout << "��";
		}
		for (int j = 0; j < MonsterData[num].MonsterMaxH - MonsterData[num].MonsterH; j++)
		{
			cout << "��";
		}
		cout << " �p" << endl;
		for (int b = 0; b < MonsterData[num].MonsterMaxH; b++)
		{
			cout << "�T�T";
		}
		cout << "�T�g" << endl;
	}
	else
	{
		double MaxH = MonsterData[num].MonsterMaxH;
		double H = MonsterData[num].MonsterH;
		int PH = 50 * (H / MaxH);
		cout << MonsterData[num].MonsterName << endl
			<< "����ֵ: " << MonsterData[num].MonsterH
			<< "/" << MonsterData[num].MonsterMaxH << endl;
		for (int b = 0; b < 49; b++)
		{
			cout << "�T�T";
		}
		cout << "�T�p �v" << endl;
		for (int i = 0; i < PH; i++)
		{
			cout << "��";
		}
		for (int j = 0; j < 50 - PH; j++)
		{
			cout << "��";
		}
		cout << " �p" << endl;
		for (int b = 0; b < 50; b++)
		{
			cout << "�T�T";
		}
		cout << "�T�g" << endl;
	}
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;

	cout << PlayerData->PlayerName << " �ȼ�" << PlayerData[0].PlayerLv << endl
		<< "����ֵ: " << PlayerData[0].PlayerH << "/" << PlayerData[0].PlayerMaxH
		<< "\t" << "����ֵ:" << PlayerData[0].PlayerStamina << "/" << PlayerData[0].PlayerMaxSta
		<< "   ��ҷ�����: " << PlayerData[0].PlayerDef << endl;

	for (int h = 0; h < PlayerData[0].PlayerMaxH - 1; h++)
	{
		cout << "�T�T";
	}
	cout << "�T�p �v" << endl;
	for (int i = 0; i < PlayerData[0].PlayerH; i++)
	{
		cout << "��";
	}
	for (int j = 0; j < PlayerData[0].PlayerMaxH - PlayerData[0].PlayerH; j++)
	{
		cout << "��";
	}
	cout << " �p" << endl;
	for (int b = 0; b < PlayerData[0].PlayerMaxH; b++)
	{
		cout << "�T�T";
	}
	cout << "�T�g" << endl;
	/*�����ô���  */
	/*cout << "��ҹ�����:" << PlayerData[0].PlayerAtk << " * " << PlayerData[0].DiceEf
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
		cout << "��Ļغ�<<" << endl << endl;
		if (MonsterData[num].MonsterMaxH <= 50)
		{
			cout << MonsterData[num].MonsterName << endl
				<< "����ֵ: " << MonsterData[num].MonsterH
				<< "/" << MonsterData[num].MonsterMaxH << endl;
			for (int b = 0; b < MonsterData[num].MonsterMaxH - 1; b++)
			{
				cout << "�T�T";
			}
			cout << "�T�p �v" << endl;
			for (int i = 0; i < MonsterData[num].MonsterH + Da; i++)
			{
				cout << "��";
			}
			for (int j = 0; j < MonsterData[num].MonsterMaxH - MonsterData[num].MonsterH - Da; j++)
			{
				cout << "��";
			}
			cout << " �p" << endl;
			for (int b = 0; b < MonsterData[num].MonsterMaxH; b++)
			{
				cout << "�T�T";
			}
			cout << "�T�g" << endl;
		}
		else
		{
			int MaxH = MonsterData[num].MonsterMaxH;
			int H = MonsterData[num].MonsterH;
			int PH = 50 * (H + Da) / MaxH;
			int PH2 = 50 - PH;
			cout << MonsterData[num].MonsterName << endl
				<< "����ֵ: " << MonsterData[num].MonsterH
				<< "/" << MonsterData[num].MonsterMaxH << endl;
			for (int b = 0; b < 49; b++)
			{
				cout << "�T�T";
			}
			cout << "�T�p �v" << endl;
			for (int i = 0; i < PH; i++)
			{
				cout << "��";
			}
			for (int j = 0; j < PH2; j++)
			{
				cout << "��";
			}
			cout << " �p" << endl;
			for (int b = 0; b < 50; b++)
			{
				cout << "�T�T";
			}
			cout << "�T�g" << endl;
		}
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;

		cout << PlayerData[0].PlayerName << " �ȼ�" << PlayerData[0].PlayerLv << endl
			<< "����ֵ: " << PlayerData[0].PlayerH << "/" << PlayerData[0].PlayerMaxH
			<< "\t" << "����ֵ:" << PlayerData[0].PlayerStamina << "/" << PlayerData[0].PlayerMaxSta
			<< "   ��ҷ�����: " << PlayerData[0].PlayerDef << endl;
		for (int h = 0; h < PlayerData[0].PlayerMaxH - 1; h++)
		{
			cout << "�T�T";
		}
		cout << "�T�p �v" << endl;
		for (int i = 0; i < PlayerData[0].PlayerH; i++)
		{
			cout << "��";
		}
		for (int j = 0; j < PlayerData[0].PlayerMaxH - PlayerData[0].PlayerH; j++)
		{
			cout << "��";
		}
		cout << " �p" << endl;
		for (int h = 0; h < PlayerData[0].PlayerMaxH; h++)
		{
			cout << "�T�T";
		}
		cout << "�T�g" << endl;

		Sleep(380);
		system("cls");
		cout << "��Ļغ�<<" << endl << endl;
		PrintHealh(PlayerData, MonsterData, num);
	}
}

void HealthConrtol(struct Player PlayerData[], struct Monster MonsterData[])				//Ѫ������
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

void StaminaConrtol(struct Player PlayerData[]) //�����������
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
	pos.X = x;             //������
	pos.Y = y;            //������
	SetConsoleCursorPosition(hOut, pos);
}

int NumOfItem(struct Bag PlayerBag[], struct Item item[], int len4, int BagItemNum)		//ͳ��չʾ����Ʒ����
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

int NumOfEq(Bag PlayerBag[], struct Equipment Eq[], int len3)		//ͳ��չʾ��װ������
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

void CinBagItem(Bag PlayerBag[], Item item[], int BagItemNum, int len4)	//����Ʒд�뱳��
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
	for (int i = 0; i < len4; i++)					//��չʾֵΪ1����Ʒд�뱳��
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

int ShowBattleBagItem(Player PlayerData[], Bag PlayerBag[], Item item[], Monster MonsterData[], int BagItemNum, int MonNum)		//��ӡ������Ʒ�б�
{
	cout << endl << "              |���롰0�������ϸ�����|" << endl
		<< "              |---------------------|" << endl << endl;
	if (BagItemNum > 0)
	{
		for (int j = 0; j < BagItemNum; j++)
		{
			cout << " |��Ʒ " << j + 1 << ": " << PlayerBag[j].BagItem.ItemName;
			cout << "\t  ����: " << ((PlayerBag[j].BagItem.ItemType == 0) ? "����" : "����Ʒ") << "    "
				<< "ʣ��: " << PlayerBag[j].BagItem.ItemNum << endl;
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
			cout << "��Ļغ�<<" << endl << endl;
			PrintHealh(PlayerData, MonsterData, MonNum);
			cout << endl << PlayerData[0].PlayerName << "ʹ���� " << PlayerBag[ItemSelect - 49].BagItem.ItemName
				<< " ����ֵ�ظ��� " << PlayerBag[ItemSelect - 49].BagItem.ItemUse << " ��" << endl << endl;

			system("pause");
		}
		else if (PlayerBag[ItemSelect - 49].BagItem.ItemType == 2 && ItemSelect - 49 < BagItemNum)
		{
			PlayerData[0].PlayerStamina += PlayerBag[ItemSelect - 49].BagItem.ItemUse;
			PlayerBag[ItemSelect - 49].BagItem.ItemNum--;
			StaminaConrtol(PlayerData);
			system("cls");
			cout << "��Ļغ�<<" << endl << endl;
			PrintHealh(PlayerData, MonsterData, MonNum);
			cout << endl << PlayerData[0].PlayerName << "ʹ���� " << PlayerBag[ItemSelect - 49].BagItem.ItemName
				<< " ����ֵ�ظ��� " << PlayerBag[ItemSelect - 49].BagItem.ItemUse << " ��" << endl << endl;

			system("pause");
		}
		else if (PlayerBag[ItemSelect - 49].BagItem.ItemType == 3 && ItemSelect - 49 < BagItemNum)
		{
			PlayerData[0].PlayerDef += PlayerBag[ItemSelect - 49].BagItem.ItemUse;
			PlayerBag[ItemSelect - 49].BagItem.ItemNum--;
			system("cls");
			cout << "��Ļغ�<<" << endl << endl;
			PrintHealh(PlayerData, MonsterData, MonNum);
			cout << endl << PlayerData[0].PlayerName << "ʹ���� " << PlayerBag[ItemSelect - 49].BagItem.ItemName
				<< " ����ֵ������ " << PlayerBag[ItemSelect - 49].BagItem.ItemUse << " ��" << endl << endl;

			system("pause");
		}
		else if (PlayerBag[ItemSelect - 49].BagItem.ItemType == 4 && ItemSelect - 49 < BagItemNum)
		{
			PlayerData[0].ExDamage += PlayerBag[ItemSelect - 49].BagItem.ItemUse;
			PlayerData[0].Buff++;
			PlayerBag[ItemSelect - 49].BagItem.ItemNum--;
			system("cls");
			cout << "��Ļغ�<<" << endl << endl;
			PrintHealh(PlayerData, MonsterData, MonNum);
			cout << endl << PlayerData[0].PlayerName << "ʹ���� " << PlayerBag[ItemSelect - 49].BagItem.ItemName
				<< " ��һ�غ϶������ " << PlayerBag[ItemSelect - 49].BagItem.ItemUse << " ���˺�" << endl << endl;

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
		cout << "�޵��ߣ�" << endl << endl;
		system("pause");
		return -1;
	}
	return BagItemNum;
}

void CinBagEq(Bag PlayerBag[], Equipment Eq[], int BagEqNum)		//��չʾֵΪ1��װ��д�뱳��
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
	cout << endl << "\t\t\t\t\t\t  <-ѡ��Ҫ������װ��->" << endl;
	cout << "\t\t\t\t\t\t  --------------------\n"
		<< "\t\t\t\t\t\t    >�����������˳�<" << endl;
	for (int i = 0; i < BagEqNum; i++)
	{
		if (i % 2 == 0)
		{
			gotoxy(0, 2.5 * i + 6);
			cout << " |װ�� " << i + 1 << ": " << PlayerBag[i].Eq.EqName;
			cout << "    ����: " << PlayerBag[i].Eq.EqTypeName << "  "
				<< "װ�����: " << (PlayerBag[i].Eq.IfEq == 0 ? "δװ��" : " >��װ��<") << endl;
			cout << " |-------------------------------------------------------|" << endl;
			cout << " |INFO: " << PlayerBag[i].Eq.EqInfo << endl << endl << endl;
			equse++;
		}
		else
		{
			gotoxy(61, (i - 1) * 2.5 + 6);
			cout << " |װ�� " << i + 1 << ": " << PlayerBag[i].Eq.EqName;
			cout << "    ����: " << PlayerBag[i].Eq.EqTypeName << "  "
				<< "װ�����: " << (PlayerBag[i].Eq.IfEq == 0 ? "δװ��" : " >��װ��<") << endl;
			gotoxy(61, (i - 1) * 2.5 + 7);
			cout << " |-------------------------------------------------------|" << endl;
			gotoxy(61, (i - 1) * 2.5 + 8);
			cout << " |INFO: " << PlayerBag[i].Eq.EqInfo << endl << endl << endl;
			equse++;
		}
	}
	if (equse == 0)
	{
		cout << "����װ��Ϊ�գ�����" << endl;
	}
}

void ShowBag(Bag PlayerBag[], int BagItemNum, int BagEqNum)
{
	int y = 6;
	int use = 0;
	int equse = 0;
	cout << endl << "                                               |���롰0�������ϸ�����|" << endl
		<< "                                               |---------------------|" << endl << endl;
	cout << "                    | -��Ʒ- |\n"
		<< "                    |--------|\n" << endl;
	for (int j = 0; j < BagItemNum; j++)
	{
		if (PlayerBag[j].BagItem.ItemNum > 0)
		{
			gotoxy(0, y + j * 5 + 1);
			cout << " |��Ʒ " << j + 1 << ": " << PlayerBag[j].BagItem.ItemName;
			gotoxy(28, y + j * 5 + 1);
			cout << "����: " << ((PlayerBag[j].BagItem.ItemType == 0) ? "����" : "����Ʒ") << "    "
				<< "ʣ��: " << PlayerBag[j].BagItem.ItemNum << endl;
			cout << " |---------------------------------------------------|" << endl
				<< " |INFO: " << PlayerBag[j].BagItem.ItemInfo << endl << endl;
			use++;
		}
	}
	if (use == 0)
	{
		gotoxy(0, y);
		cout << endl << "    ������ƷΪ�գ�����" << endl;
	}
	y = 4;
	cout << endl;
	gotoxy(60, y);
	cout << "                       | -װ��- |";
	gotoxy(60, y + 1);
	cout << "                       |--------|" << endl;
	for (int i = 0; i < BagEqNum; i++)
	{
		if (PlayerBag[i].Eq.ShowEq == 1)
		{
			gotoxy(60, y + i * 5 + 3);
			cout << " |װ�� " << i + 1 << ": " << PlayerBag[i].Eq.EqName;
			cout << "    ����: " << PlayerBag[i].Eq.EqTypeName << "  "
				<< "װ�����: " << (PlayerBag[i].Eq.IfEq == 0 ? "δװ��" : " >��װ��<") << endl;
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
		cout << endl << "    ����װ��Ϊ�գ�����" << endl;
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
					PEq[0].handS = "��";
					PlayerData[0].PlayerAtk -= PlayerBag[EqSelect - 49].Eq.EqUse;
				}
				else if (PlayerBag[EqSelect - 49].Eq.EqType == 1)
				{
					PEq[0].head = 0;
					PEq[0].headS = "��";
					PlayerData[0].PlayerMaxH -= (PlayerBag[EqSelect - 49].Eq.EqUse / 3) + 1;
					PlayerData[0].PlayerMaxSta -= PlayerBag[EqSelect - 49].Eq.EqUse;
				}
				else if (PlayerBag[EqSelect - 49].Eq.EqType == 2)
				{
					PEq[0].cheast = 0;
					PEq[0].cheastS = "��";
					PlayerData[0].PlayerMaxH -= PlayerBag[EqSelect - 49].Eq.EqUse;
					PlayerData[0].PlayerMaxSta -= PlayerBag[EqSelect - 49].Eq.EqUse;
				}
				else if (PlayerBag[EqSelect - 49].Eq.EqType == 3)
				{
					PEq[0].legging = 0;
					PEq[0].leggingS = "��";
					PlayerData[0].PlayerMaxH -= (PlayerBag[EqSelect - 49].Eq.EqUse / 2) + 1;
					PlayerData[0].PlayerMaxSta -= PlayerBag[EqSelect - 49].Eq.EqUse;

				}
				else if (PlayerBag[EqSelect - 49].Eq.EqType == 4)
				{
					PEq[0].boot = 0;
					PEq[0].bootS = "��";
					PlayerData[0].PlayerMaxH -= (PlayerBag[EqSelect - 49].Eq.EqUse / 3) + 1;
					PlayerData[0].PlayerMaxSta -= PlayerBag[EqSelect - 49].Eq.EqUse;
				}
				else if (PlayerBag[EqSelect - 49].Eq.EqType == 5)
				{
					PEq[0].other = 0;
					PEq[0].otherS = "��";
					if (PEq[0].other == 0 && PlayerBag[EqSelect - 49].Eq.EqUse == 0)
					{
						PlayerData[0].IfFirstDead--;
					}
				}
				PlayerBag[EqSelect - 49].Eq.IfEq = 0;
				system("cls");
				ShowBagEq(PlayerBag, BagEqNum);
				cout << "��ж��װ�� " << PlayerBag[EqSelect - 49].Eq.EqName << endl << endl;
			}
			else if (PlayerBag[EqSelect - 49].Eq.IfEq == 0)
			{
				if ((PEq[0].hand == 1 && PlayerBag[EqSelect - 49].Eq.EqType == 0) || (PEq[0].head == 1 && PlayerBag[EqSelect - 49].Eq.EqType == 1) ||
					(PEq[0].cheast == 1 && PlayerBag[EqSelect - 49].Eq.EqType == 2) || (PEq[0].legging == 1 && PlayerBag[EqSelect - 49].Eq.EqType == 3) ||
					(PEq[0].boot == 1 && PlayerBag[EqSelect - 49].Eq.EqType == 4) || (PEq[0].other == 1 && PlayerBag[EqSelect - 49].Eq.EqType == 5))
				{
					system("cls");
					ShowBagEq(PlayerBag, BagEqNum);
					cout << "��ǰλ������װ��������ж��װ����\n\n";
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
					cout << "��װ�� " << PlayerBag[EqSelect - 49].Eq.EqName << endl << endl;
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

int CinSkillUse(struct SkillList SkillData[], struct SkillUseList SkillUseData[], int len)   //д��ʹ�ñ�
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

int CinSkillSptUse(SkillList SkillSptData[], SkillUseList SkillSptUseData[], int len2)  //д��ʹ�ñ�
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
		cout << endl << "\t\t\t\t\t        |�����Ϣ|" << endl
			<< "\t\t\t\t\t        |--------|" << endl << endl;
		cout << "\t        |--����Y��������鿴���ܽ���--|";
		cout << "\t           |--����U���������������ܽ���--|" << endl;
		int Mode;
		Mode = _getch();
		system("cls");
		if (Mode == 117)
		{
			while (1)
			{
				cout << "\n\t\t\t\t\t>>��ѡ��Ҫ�����ļ�������<<\n\n\t\t\t\t  1.ս������\t2.֧Ԯ����\t0.�˳�����\n";
				int SkS = _getch();
				SkS -= 48;
				system("cls");
				if (SkS == 1)
				{
					while (1)
					{
						int a = 0;
						int b = 1;
						cout << "\n����������������������������������������������������������������������������������������������������������������������������������������������������������������������"
							<< endl << endl;
						for (int i = 1; i < len; i++)
						{
							if (SkillData[i - 1].ShowSkill == 1 && SkillData[i].SkillLv <= 3 && SkillData[i].SkillLv > SkillData[i - 1].SkillLv)
							{
								cout << " |ս������ " << b << ": <" << SkillData[i - 1].SkillName << "> ";
								cout << "   \t| ����: " << SkillData[i - 1].SkillCost
									<< " | CD: " << SkillData[i - 1].SkillCDTime << "/"
									<< SkillData[i - 1].SkillCD << " |" << endl;
								cout << " |------------------------------------------------------------|" << endl
									<< " |INFO: " << SkillData[i - 1].SkillInfo << endl;
								SkillLvUp[a].SkillName = SkillData[i - 1].SkillName;
								SkillLvUp[a].ShowSkill = SkillData[i - 1].ShowSkill;
								a++;


								cout << "\t\t\t\t\t\t\t\t   ������\n\n" << "\t\t\t\t\t\t\t\t������������\n\n";



								cout << " |ս������ " << b << ": <" << SkillData[i].SkillName << "> ";
								cout << "   \t| ����: " << SkillData[i].SkillCost
									<< " | CD: " << SkillData[i].SkillCDTime << "/"
									<< SkillData[i].SkillCD << " | \t  ����: " << SkillData[i].SkillPC << endl;
								cout << " |------------------------------------------------------------|" << endl
									<< " |INFO: " << SkillData[i].SkillInfo
									<< endl << endl
									<< "����������������������������������������������������������������������������������������������������������������������������������������������������������������������"
									<< endl << endl;
								SkillLvUp[a].SkillName = SkillData[i].SkillName;
								SkillLvUp[a].ShowSkill = SkillData[i].ShowSkill;
								a++;
								b++;
							}
							else if (SkillData[i-1].SkillLv == 1 && SkillData[i-1].ShowSkill == 0 && SkillData[i].ShowSkill == 0 && SkillData[i + 1].ShowSkill == 0)
							{
								cout << " |ս������ " << b << ": <" << SkillData[i-1].SkillName << "> ";
								cout << "   \t| ����: " << SkillData[i-1].SkillCost
									<< " | CD: " << SkillData[i-1].SkillCDTime << "/"
									<< SkillData[i-1].SkillCD << " | \t  ���򻨷�: " << SkillData[i-1].SkillPC << endl;
								cout << " |------------------------------------------------------------|" << endl
									<< " |INFO: " << SkillData[i-1].SkillInfo
									<< endl << endl
									<< "����������������������������������������������������������������������������������������������������������������������������������������������������������������������"
									<< endl << endl;
								SkillLvUp[a].SkillName = SkillData[i-1].SkillName;
								SkillLvUp[a].ShowSkill = SkillData[i-1].ShowSkill;
								a++;
								b++;
							}
						}
						if (a > 0)
						{
							cout << "����Ҫ�����ļ���(����0�˳�)" << "\t\t��Ҽ��ܵ���: " << PlayerData[0].SkillPoint << endl;
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
											cout << "\n���ܹ�����ϣ�\n" << endl;
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
											cout << "\n����������ϣ�\n" << endl;
										}
									}
									else
									{
										cout << "\n���ܵ���������\n" << endl;
									}
									system("pause");
								}
							}
							system("cls");
						}
						else
						{
							cout << "���м��ܾ����������\n\n\n" << endl;
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
						cout << "\n����������������������������������������������������������������������������������������������������������������������������������������������������������������������"
							<< endl << endl;
						for (int i = 1; i < len2; i++)
						{
							if (SkillSptData[i - 1].ShowSkill == 1 && SkillSptData[i].SkillLv <= 3 && SkillSptData[i].SkillLv > SkillSptData[i - 1].SkillLv)
							{
								cout << " |ս������ " << b << ": <" << SkillSptData[i - 1].SkillName << "> ";
								cout << "   \t| ����: " << SkillSptData[i - 1].SkillCost
									<< " | CD: " << SkillSptData[i - 1].SkillCDTime << "/"
									<< SkillSptData[i - 1].SkillCD << " |" << endl;
								cout << " |------------------------------------------------------------|" << endl
									<< " |INFO: " << SkillSptData[i - 1].SkillInfo << endl;
								SkillLvUp[a].SkillName = SkillSptData[i - 1].SkillName;
								SkillLvUp[a].ShowSkill = SkillSptData[i - 1].ShowSkill;
								a++;


								cout << "\t\t\t\t\t\t\t\t   ������\n\n" << "\t\t\t\t\t\t\t\t������������\n\n";



								cout << " |ս������ " << b << ": <" << SkillSptData[i].SkillName << "> ";
								cout << "   \t| ����: " << SkillSptData[i].SkillCost
									<< " | CD: " << SkillSptData[i].SkillCDTime << "/"
									<< SkillSptData[i].SkillCD << " | \t  ����: " << SkillSptData[i].SkillPC << endl;
								cout << " |------------------------------------------------------------|" << endl
									<< " |INFO: " << SkillSptData[i].SkillInfo
									<< endl << endl
									<< "����������������������������������������������������������������������������������������������������������������������������������������������������������������������"
									<< endl << endl;
								SkillLvUp[a].SkillName = SkillSptData[i].SkillName;
								SkillLvUp[a].ShowSkill = SkillSptData[i].ShowSkill;
								a++;
								b++;
							}
							else if (SkillSptData[i - 1].SkillLv == 1 && SkillSptData[i - 1].ShowSkill == 0 && SkillSptData[i].ShowSkill == 0 && SkillSptData[i + 1].ShowSkill == 0)
							{
								cout << " |ս������ " << b << ": <" << SkillSptData[i - 1].SkillName << "> ";
								cout << "   \t| ����: " << SkillSptData[i - 1].SkillCost
									<< " | CD: " << SkillSptData[i - 1].SkillCDTime << "/"
									<< SkillSptData[i - 1].SkillCD << " | \t  ���򻨷�: " << SkillSptData[i - 1].SkillPC << endl;
								cout << " |------------------------------------------------------------|" << endl
									<< " |INFO: " << SkillSptData[i - 1].SkillInfo
									<< endl << endl
									<< "����������������������������������������������������������������������������������������������������������������������������������������������������������������������"
									<< endl << endl;
								SkillLvUp[a].SkillName = SkillSptData[i - 1].SkillName;
								SkillLvUp[a].ShowSkill = SkillSptData[i - 1].ShowSkill;
								a++;
								b++;
							}
						}
						if (a > 0)
						{
							cout << "����Ҫ�����ļ���(����0�˳�)" << "\t\t��Ҽ��ܵ���: " << PlayerData[0].SkillPoint << endl;
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
											cout << "\n���ܹ�����ϣ�\n" << endl;
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
											cout << "\n����������ϣ�\n" << endl;
										}
									}
									else
									{
										cout << "\n���ܵ���������\n" << endl;
									}
									system("pause");
								}
							}
							system("cls");
						}
						else
						{
							cout << "���м��ܾ����������\n\n\n" << endl;
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
				cout << endl << "                            |��������������ϸ�����|" << endl
					<< "                            |----------------------|" << endl << endl;
				for (int i = 0; i < len; i++)
				{
					if (SkillUseData[i].ShowSkill == 1)
					{
						cout << endl
							<< " |ս������ " << i + 1 << ": <" << SkillUseData[i].SkillName << "> ";
						cout << "   \t| ����: " << SkillUseData[i].SkillCost
							<< " | CD: " << SkillUseData[i].SkillCDTime << "/"
							<< SkillUseData[i].SkillCD << " |    " << endl;
						cout << " |------------------------------------------------------------|" << endl
							<< " |INFO: " << SkillUseData[i].SkillInfo << endl << endl;
					}
				}
				cout << "\n����������������������������������������������������������������������������������������������������������������������������������������������������������������������" << endl;
				cout << endl << "\n |���⼼�� 1���������ӣ�ʣ��" << PlayerData->DiceNum << "����" << endl
					<< " |------------------------------------------------------------|" << endl
					<< " |INFO: Ͷ��һ�����ӣ����������Ч��" << endl << endl;
				for (int i = 0; i < len2; i++)
				{
					if (SkillSptUseData[i].ShowSkill == 1)
					{
						cout << endl
							<< " |֧Ԯ���� " << i + 2 << ": <" << SkillSptUseData[i].SkillName << ">";
						cout << "\t   | ����: " << SkillSptUseData[i].SkillCost
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
		cout << endl << "\t\t\t\t\t       |�����Ϣ|" << endl
			<< "\t\t\t\t\t       |--------|" << endl << endl;
		cout << "\t\t\t    |����I��������װ��ģʽ|" << "  |����U�������뼼�ܽ���|" << endl;
		cout << "\n                 |װ����Ϣ|" << endl
			<< "                 |--------|" << endl << endl;
		cout << "|ͷ��: " << PEq[0].headS << endl << "|------------------|"
			<< "\t|����: " << PEq[0].handS << endl << "\t\t\t|------------------|\n";
		cout << "|�ؼ�: " << PEq[0].cheastS << endl << "|------------------|"
			<< "\t|��Ʒ: " << PEq[0].otherS << endl << "\t\t\t|------------------|\n";
		cout << "|�Ȳ�: " << PEq[0].leggingS << endl << "|------------------|\n" << endl;
		cout << "|ѥ��: " << PEq[0].bootS << endl << "|------------------|\n" << endl;

		//����������
		{
			gotoxy(66, 6);
			cout << "           |�������|";
			gotoxy(66, 7);
			cout << "           |--------|";
			gotoxy(60, 9);
			cout << "|���: " << PlayerData[0].PlayerName;
			gotoxy(60, 10);
			cout << "|------------------|";
			gotoxy(84, 9);
			cout << "|�ȼ�: " << PlayerData[0].PlayerLv;
			gotoxy(84, 10);
			cout << "|------------------|";
			gotoxy(60, 12);
			cout << "|����ֵ: " << PlayerData[0].PlayerH << "/" << PlayerData[0].PlayerMaxH;
			gotoxy(60, 13);
			cout << "|------------------|";
			gotoxy(84, 12);
			cout << "|����ֵ: " << PlayerData[0].PlayerExp << "/" << PlayerData[0].PlayerLv * (PlayerData[0].PlayerLv + 10) - 1;
			gotoxy(84, 13);
			cout << "|------------------|";
			gotoxy(60, 15);
			cout << "|������: " << PlayerData[0].PlayerAtk;
			gotoxy(60, 16);
			cout << "|------------------|";
			gotoxy(84, 15);
			cout << "|��������: " << PlayerData[0].DiceNum << " ��";
			gotoxy(84, 16);
			cout << "|------------------|";
			gotoxy(60, 18);
			cout << "|����: " << PlayerData[0].PlayerStamina << "/" << PlayerData[0].PlayerMaxSta;
			gotoxy(60, 19);
			cout << "|------------------|";
			gotoxy(84, 18);
			cout << "|�����ظ�: " << (PlayerData[0].PlayerLv / 2) + 1;
			gotoxy(84, 19);
			cout << "|------------------|";
		}

		int EqMode;
		EqMode = _getch();
		if (EqMode == 117 && PlayerData[0].IfBattle == 1)
		{
			system("cls");
			cout << endl << "\tս�����޷�����ý��棡" << endl << endl;
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
			cout << endl << "\tս�����޷��л�װ����" << endl << endl;
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

int Damage(Player PlayerData[], SkillUseList SkillUseData[], int num)		//�����ɵ��˺�
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

int Death(struct Player PlayerData[], struct Monster MonsterData[])	//�����Һ͵�������
{
	int a = 0;
	if (PlayerData[0].PlayerH <= 0)
	{
		cout << endl << "�����ˣ�" << endl;
		a = 1;
	}
	else if (MonsterData[0].MonsterH <= 0)
	{
		cout << endl << "�����ѱ����ܣ�" << endl;
		a = 2;
	}
	return a;
}

int MonsterAI(struct Monster MonsterData[], int MonNum)	//����AI
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

int Dice(struct Player PlayerData[])  //����
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

int RandomNum()  //�����
{
	int Point = rand() % 100 + 1;
	return Point;
}

void DiceEffect(int D, struct Player PlayerData[], Monster MonsterData[], int MonNum)		//����Ч��
{
	switch (D)
	{
	case 1:
	{
		system("cls");
		cout << "��Ļغ�<<" << endl << endl;
		PrintHealh(PlayerData, MonsterData, MonNum);
		cout << endl << "��Ͷ���˵���: " << D << endl << endl;
		cout << "ʲôҲû�з��� " << endl << endl;
		system("pause");
	}

	break;
	case 2:
	{
		system("cls");
		PlayerData[0].PlayerH += (PlayerData[0].PlayerMaxH / 10);
		HealthConrtol(PlayerData, MonsterData);
		cout << "��Ļغ�<<" << endl << endl;
		PrintHealh(PlayerData, MonsterData, MonNum);
		cout << endl << "��Ͷ���˵���: " << D << endl << endl;
		cout << "�ظ���10%������ֵ " << endl << endl;
		system("pause");
	}
	break;
	case 3:
	{
		system("cls");
		PlayerData[0].PlayerStamina += (PlayerData[0].PlayerMaxSta * 3 / 10);
		StaminaConrtol(PlayerData);
		cout << "��Ļغ�<<" << endl << endl;
		PrintHealh(PlayerData, MonsterData, MonNum);
		cout << endl << "��Ͷ���˵���: " << D << endl << endl;
		cout << "�ظ���30%������ֵ " << endl << endl;
		system("pause");
	}
	break;
	case 4:
	{
		PlayerData[0].ExDamage += (PlayerData[0].PlayerAtk / 2);
		system("cls");
		cout << "��Ļغ�<<" << endl << endl;
		PrintHealh(PlayerData, MonsterData, MonNum);
		cout << endl << "��Ͷ���˵���: " << D << endl << endl;
		cout << "������������൱����ҹ�����һ����˺�\n����һ�غϣ����ɵ��� " << endl << endl;
		system("pause");
	}
	break;
	case 5:
	{
		PlayerData[0].PlayerH += (PlayerData[0].PlayerMaxH / 5);
		HealthConrtol(PlayerData, MonsterData);
		system("cls");
		cout << "��Ļغ�<<" << endl << endl;
		PrintHealh(PlayerData, MonsterData, MonNum);
		cout << endl << "��Ͷ���˵���: " << D << endl << endl;
		cout << "�ظ���20%������ֵ " << endl << endl;
		system("pause");
	}
	break;
	case 6:
	{
		PlayerData[0].DiceEf = 2;
		system("cls");
		cout << "��Ļغ�<<" << endl << endl;
		PrintHealh(PlayerData, MonsterData, MonNum);
		cout << endl << "��Ͷ���˵���: " << D << endl;
		cout << "��ҵĻ�������������100%\n����һ�غϣ����ɵ���" << endl << endl;
		system("pause");
	}
	break;
	default:
		cout << endl << "�����Ѿ����꣡" << endl << endl;
		system("pause");
		break;
	}
}

int SkillSptSystem
(SkillList SkillSptData[], SkillUseList SkillSptUseData[], Player PlayerData[],
	Monster MonsterData[], int MonNum, int len2, int Sk2Num, int FirstExDa)//֧Ԯ����ϵͳ
{
	int y = 28;
	system("cls");
	cout << "��Ļغ�<<" << endl << endl;
	PrintHealh(PlayerData, MonsterData, MonNum);
	cout << endl << "                            |���롰0�������ϸ�����|" << endl
		<< "                            |---------------------|" << endl << endl;
	cout << endl << " |���⼼�� 1���������ӣ�ʣ��" << PlayerData->DiceNum << "����" << endl
		<< " |----------------------------------------------------------------------------|" << endl
		<< " |INFO: Ͷ��һ�����ӣ����������Ч��" << endl << endl;
	for (int i = 0; i < Sk2Num; i++)
	{
		gotoxy(0, y + i * 5);
		string r = SkillSptUseData[i].SkillCDTime == 0 ? "-->> READY <<--" : "";
		cout << endl
			<< " |֧Ԯ���� " << i + 2 << ": <" << SkillSptUseData[i].SkillName << ">";
		gotoxy(38, y + i * 5 + 1);
		cout << "| ����: " << SkillSptUseData[i].SkillCost
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

					cout << "��Ļغ�<<" << endl << endl;
					PrintHealh(PlayerData, MonsterData, MonNum);
					cout << endl << PlayerData[0].PlayerName
						<< " ʹ���� " << SkillSptUseData[select - 50].SkillName
						<< " �ظ��� " << heal << " ������ֵ" << endl << endl;

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

					cout << "��Ļغ�<<" << endl << endl;
					PrintHealh(PlayerData, MonsterData, MonNum);
					cout << endl << PlayerData[0].PlayerName
						<< " ʹ���� " << SkillSptUseData[select - 50].SkillName
						<< " ����� " << SkillSptUseData[select - 50].SkillUse << " �㻤��" << endl << endl;

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

					cout << "��Ļغ�<<" << endl << endl;
					PrintHealh(PlayerData, MonsterData, MonNum);

					cout << endl << PlayerData[0].PlayerName
						<< " ʹ���� " << SkillSptUseData[select - 50].SkillName
						<< " �ظ��� " << SkillSptUseData[select - 50].SkillUse << " ������ֵ" << endl << endl;

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

					cout << "��Ļغ�<<" << endl << endl;
					PrintHealh(PlayerData, MonsterData, MonNum);
					cout << endl << PlayerData[0].PlayerName
						<< " ʹ���� " << SkillSptUseData[select - 50].SkillName
						<< " �Ե�������� " << dataken << " ���˺�" << endl << endl;

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
	Player PlayerData[], Monster MonsterData[], int MonNum, int len, int Sk1Num)  //ս������ϵͳ
{
	int y = 25;
	system("cls");
	cout << "��Ļغ�<<" << endl << endl;
	PrintHealh(PlayerData, MonsterData, MonNum);
	cout << endl << "                            |���롰0�������ϸ�����|" << endl
		<< "                            |---------------------|" << endl << endl;
	for (int i = 0; i < Sk1Num; i++)
	{
		gotoxy(0, y + i * 5);
		string r = SkillUseData[i].SkillCDTime == 0 ? "-->> READY <<--" : "";
		cout << endl
			<< " |ս������ " << i + 1 << ": <" << SkillUseData[i].SkillName << "> ";
		gotoxy(38, y + i * 5 + 1);
		cout << "| ����: " << SkillUseData[i].SkillCost
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
					cout << "��Ļغ�<<" << endl << endl;
					PrintHealh(PlayerData, MonsterData, MonNum);
					ShakeScM(PlayerData, MonsterData, MonNum, DaTaken);
					cout << endl << PlayerData[0].PlayerName << "�� " << MonsterData[MonNum].MonsterName
						<< " ʹ���� " << SkillUseData[select - 49].SkillName
						<< " ������� " << dataken << " ���˺�" << endl << endl;

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
	, int MonNum, int len, int len2, int ItemNum, int BagEqNum)//ս��ϵͳ
{
	PlayerData[0].IfBattle = 1;
	int FirstExDa = PlayerData[0].ExDamage;
	int dth = 0;
	int SK2Sel = 0;
	int Sk1Num = CinSkillUse(SkillData, SkillUseData, len);
	int Sk2Num = CinSkillSptUse(SkillSptData, SkillSptUseData, len2);
	int PDeBuffGive = 0;		//����Ƿ�Թ���ʩ����debuff
	for (int i = 0;; dth = Death(PlayerData, MonsterData))
	{
		if (i <= 0 && dth == 0)
		{
			cout << "��Ļغ�<<" << endl << endl;
			PrintHealh(PlayerData, MonsterData, MonNum);
			cout << endl;
			cout << "ս������:" << endl;
			cout << "1.��������    " << "2.ս��֧Ԯ    " << "3.��Ʒ����    " << "4.�����Ϣ    " << "5.�����غ�" << endl;

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
					cout << "��Ļغ�<<" << endl << endl;
					PrintHealh(PlayerData, MonsterData, MonNum);
					cout << endl << "����������ȴ��" << endl << endl;
					system("pause");
					system("cls");
				}
				else if (DaNum == 1)
				{
					cout << "��Ļغ�<<" << endl << endl;
					PrintHealh(PlayerData, MonsterData, MonNum);
					cout << endl << "����������" << endl << endl;
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
					for (int j = 0; j < len + len2; j++)  //������ȴ��ʱ
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
					cout << "��Ļغ�<<" << endl << endl;
					PrintHealh(PlayerData, MonsterData, MonNum);
					cout << endl << "����������" << endl << endl;
					system("pause");
					system("cls");
				}
				else if (SK2Sel == 2)
				{
					system("cls");
					cout << "��Ļغ�<<" << endl << endl;
					PrintHealh(PlayerData, MonsterData, MonNum);
					cout << endl << "����������ȴ��" << endl << endl;
					system("pause");
					system("cls");
				}
				else if (SK2Sel == 3)
				{
					PDeBuffGive = 1;
					for (int j = 0; j < len + len2; j++)  //������ȴ��ʱ
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
				cout << "��Ļغ�<<" << endl << endl;
				PrintHealh(PlayerData, MonsterData, MonNum);

				int BIN = ShowBattleBagItem(PlayerData, PlayerBag, item, MonsterData, ItemNum, MonNum);
				if (BIN != -1)
				{
					ItemNum = BIN;
					for (int j = 0; j < len + len2; j++)  //������ȴ��ʱ
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
				cout << endl << "�������غ�" << endl << endl;
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
			if (MonsterData[MonNum].Debuff == 1 && PDeBuffGive == 1)		//����DeBuffЧ��
			{
				system("cls");
				PDeBuffGive = 0;

				if (PlayerData[0].DiceUse == 0 && PlayerData[0].Buff == 0)		//�������Ӻ�BuffЧ��
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

				cout << ">>�з��غ�" << endl << endl;
				PrintHealh(PlayerData, MonsterData, MonNum);
				cout << endl << MonsterData[MonNum].MonsterName << " ��ѣ���ˣ���\n\n";
				system("pause");
				system("cls");
			}
			else if (MonsterData[MonNum].Debuff == 0 && PDeBuffGive == 0)
			{
				if (PlayerData[0].DiceUse == 0 && PlayerData[0].Buff == 0)		//�������Ӻ�BuffЧ��
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
				if (MDa < 0)				//�жϹ�����ɵ��˺��Ƿ�Ϊ��
				{
					MDa = 0;
				}
				if (PlayerData[0].IfFirstDead == 0)
				{
					PlayerData[0].PlayerH -= MDa;
					HealthConrtol(PlayerData, MonsterData);

					cout << ">>�з��غ�" << endl << endl;
					PrintHealh(PlayerData, MonsterData, MonNum);
					cout << endl << "���˶�������� " << MDa << " ���˺�" << endl << endl;
					system("pause");
					system("cls");
				}
				else if (PlayerData[0].IfFirstDead == 1)
				{
					PlayerData[0].PlayerH = 1;
					PlayerData[0].IfFirstDead = 0;

					HealthConrtol(PlayerData, MonsterData);
					cout << ">>�з��غ�" << endl << endl;
					PrintHealh(PlayerData, MonsterData, MonNum);
					cout << endl << "���˶�������� " << MDa << " ���˺�" << endl;
					cout << endl << PlayerData[0].PlayerName << " ������ " << PEq[0].otherS
						<< " ��Ч�����ֵ�����������������ֵ��Ϊ1" << endl << endl;
					for (int g = 0; g < BagEqNum; g++)
						if (PlayerBag[g].Eq.IfEq == 1 && PlayerBag[g].Eq.EqType == 5 && PEq[0].other == 1)
						{
							PlayerBag[g].Eq.IfEq = 0;
							PEq[0].other = 0;
							PEq[0].otherS = "��";
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
				cout << "\n����� " << MonsterData[MonNum].MonExp << " �㾭��ֵ" << endl;
				PlayerData[0].IfBattle = 0;
				Sleep(1350);
				system("cls");
				PlayerLvUp(PlayerData);
			}
			cout << endl << "ս������" << endl << endl;
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
		cout << "\n\t\t\t      |=�̵�=|" << endl
			<< "\t\t\t    |----------|" << endl
			<< " >>��һ�����: " << PlayerData[0].gold << endl << endl << endl;

		int p = 0;
		for (int i = 0; i < len4; i++)
		{
			cout << " |��Ʒ " << i + 1 << ": " << item[i].ItemName;
			cout << "  \t����: " << ((item[i].ItemType == 0) ? "����" : "����Ʒ") << "    "
				<< "  ����: ";
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
			cout << " \t�۸�: " << item[i].cost << endl;
			cout << " |--------------------------------------------------------------------|" << endl
				<< " |INFO: " << item[i].ItemInfo << endl << endl << endl;
		}

		cout << "��ѡ��Ҫ�������Ʒ(����ѡ������0�˳�)" << endl;
		int Select = _getch();
		Select -= 49;

		if (Select >= 0 && Select <= len4)
		{
			cout << "\n��������(������»س�):" << endl;
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

				cout << "\n������ " << Num << " ��" << item[Select].ItemName << "   ������: " << Num * item[Select].cost << endl << endl;

				system("pause");
				system("cls");
			}
			else
			{
				cout << "���Ҳ�����" << endl;
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
