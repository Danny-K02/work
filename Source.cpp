#include "List.h"
#include "windows.h"
int main()
{
	setlocale(LC_ALL, "Rus");
	std::ifstream fromf("tzones_base.txt");
	std::ofstream tof("tzones.txt",std::ios::app);
	std::string s;
	while (fromf >> s)
	{
		tof << " "+s;
	}
	tof.close();
	fromf.close();

	for (int i = 0; i < 5; i++)
	{
		AddList(false,0);
		Sleep(1000);
	}
	system("cls");
	unsigned short tmp;
	char x;
	do
	{
		std::cout << "1. �������� ��������� �������\n2. �������� ������� � ������� ��������� �����\n3. �������� ��������� ���������\n4. ������� �������\n5. ������� ������\n6. �������� ������ � ����\n7. �������� ����� 2-� �����(�� ������)\n0. �����\n����� �������� > ";
		std::cin >> x;
		if (x != '1' && x != '2' && x != '3' && x != '4' && x != '5' && x != '6' && x != '7')break;
		switch (x)
		{
		case '1':
			AddList(false,0); break;
		case '2':
			std::cout << "������� ����[-12;14] > "; std::cin >> tmp;
			if (tmp > 14 || tmp < -12)break;
			AddList(true, tmp); break;
		case '3':
			std::cout << "���������� > "; std::cin >> tmp;
			for (int i = 0; i < tmp; i++)
			{
				AddList(false,i);
				Sleep(1000);
			}
			 break;
		case '4':
			std::cout << "����� > "; std::cin >> tmp;
			DeleteList(tmp); break;
		case '5': PrintList(); break;
		case '6': PrintList_to_f(); break;
		case '7': 
			unsigned short n;
			std::cout << "����� 1-� ������ > "; std::cin >> tmp;
			std::cout << "����� 2-� ������ > "; std::cin >> n;
			Compare_country_time(tmp, n);
			break;
		}
	} while (x != '0');
	std::ofstream cl("tzones.txt");
	cl << "";
	cl.close();
	return 0;
}