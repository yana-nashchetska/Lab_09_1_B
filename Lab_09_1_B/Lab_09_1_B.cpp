#include <iostream>
#include <string>
#include <iomanip>
#include <Windows.h> // ������������ ����������� ��������
using namespace std;
enum SPC { COMPUTERSCIENCE, INFORMATICS, MATHANDECONOMY, PHISICANDINFORMATICS, HARDWORKING };
string spcstr[] = { "����'����� �����", "�����������", "���������� �� ��������", "������ �� �����������", "������� ���������" };
struct Student
{
    string prizv;
    SPC spc;
    int term;
    int math;
    int physics;
    union {
        int progrm;
        int nm;
        int pdg;
    };

};
double Maxscore(Student* p, const int N);
double LineSearch(Student* p, const int N);
void Create(Student* p, const int N);
void Print(Student* p, const int N);
int main()
{
    SetConsoleCP(1251); // ������������ ������� win-cp1251 � ���� �����
    SetConsoleOutputCP(1251); // ������������ ������� win-cp1251 � ���� ������

    int N;
    cout << "������ N (������� ��������): "; cin >> N;

    Student* p = new Student[N];
    Create(p, N);
    Print(p, N);

    double seek1 = LineSearch(p, N);
    cout << seek1 << endl;
    double seek2 = Maxscore(p, N);
    cout << seek2 << endl;
    return 0;
}

void Create(Student* p, const int N)
{
    int result;
    for (int i = 0; i < N; i++)
    {
        cout << "������� � " << i + 1 << ":" << endl;
        cin.get(); // ������� ����� ��������� � �� ����������� �������
        cin.sync(); // "����� �����", �� �� ����� ������ ��������� ������� �����

        cout << " �������: "; getline(cin, p[i].prizv);
        cout << " ����: "; cin >> p[i].term;
        cout << " ������������ (0 - ����'����� �����, 1 - �����������, 2 - ���������� �� ��������, 3 - ������ �� �����������, 4 - ������� ���������): ";
        cin >> result;
        p[i].spc = (SPC)result;
        cout << " ������ � ����������: "; cin >> p[i].math;
        cout << " ������ � ������: "; cin >> p[i].physics;
        switch (p[i].spc)
        {
        case COMPUTERSCIENCE:
            cout << " ������ � �������������: "; cin >> p[i].progrm;
            break;
        case INFORMATICS:
            cout << " ������ � ��������� ������: "; cin >> p[i].nm;
            break;
        case MATHANDECONOMY:
        case PHISICANDINFORMATICS:
        case HARDWORKING:
            cout << " ������ � ���������: "; cin >> p[i].pdg;
            break;
        }
        cout << endl;
    }
}

void Print(Student* p, const int N)
{
    cout << "============================================================================================================================================================"
        << endl;
    cout << "| � | ������� | ���� | ������������ | ������ � ���������� | ������ � ������ | ������ � ������������� | ������ � ��������� ������ | ������ � ��������� | "
        << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------"
        << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "| " << setw(2) << right << i + 1 << " ";
        cout << "| " << setw(8) << right << p[i].prizv
            << "| " << setw(1) << right << p[i].term << " "
            << "| " << setw(8) << right << spcstr[p[i].spc]
            << "| " << setw(6) << right << p[i].math << " "
            << "| " << setw(6) << right << p[i].physics << " "
            << "| " << setw(6) << right << p[i].progrm << " "
            << "| " << setw(6) << right << p[i].nm << " "
            << "| " << setw(6) << right << p[i].pdg << " ";
    }
    cout << "============================================================================================================================================================"
        << endl;
    cout << endl;
}
double LineSearch(Student* p, const int N)
{
    cout << "ʳ������ ��������, ��� ������� ��� � ������ �� 4,5:" << endl;
    int k = 0;
    for (int i = 0; i < N; i++)
    {
        switch (p[i].spc) {
        case COMPUTERSCIENCE:
            if ((p[i].math + p[i].physics + p[i].progrm) / 3 > 4.5)
            {
                k++;
            };
            break;
        case INFORMATICS:
            if ((p[i].math + p[i].physics + p[i].nm) / 3 > 4.5)
            {
                k++;
            };
            break;
        case MATHANDECONOMY:
        case PHISICANDINFORMATICS:
        case HARDWORKING:
            if ((p[i].math + p[i].physics + p[i].pdg) / 3 > 4.5)
            {
                k++;
            };
            break;
        }
    }
    return k;
}

double Maxscore(Student* p, const int N)
{
    cout << "������� � ��������� ������� �����:" << endl;
    double S1 = 0, S2 = 0, S3 = 0, S4 = 0, S5 = 0;

    for (int i = 0; i < N; i++)
    {
        S1 += p[i].math;
    }
    for (int i = 0; i < N; i++)
    {
        S2 += p[i].physics;
    }
    for (int i = 0; i < N; i++)
    {
        S3 += p[i].progrm;
    }
    for (int i = 0; i < N; i++)
    {
        S4 += p[i].nm;
    }for (int i = 0; i < N; i++)
    {
        S5 += p[i].pdg;
    }
    if (S1 > S2 && S1 > S3 && S1 > S4 && S1 > S5)
        cout << setw(3) << right << "����������" << endl;
    if (S2 > S1 && S2 > S3 && S2 > S4 && S2 > S5)
        cout << setw(3) << right << "������" << endl;
    if (S3 > S1 && S1 > S2 && S3 > S4 && S3 > S5)
        cout << setw(3) << right << "�������������" << right << endl;
    if (S4 > S1 && S4 > S2 && S4 > S3 && S4 > S5)
        cout << setw(3) << right << "������� ������" << right << endl;
    if (S5 > S1 && S5 > S2 && S5 > S3 && S5 > S4)
        cout << setw(3) << right << "���������" << right << endl;
    return 0;
}
