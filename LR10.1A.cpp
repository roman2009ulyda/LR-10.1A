#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>
using namespace std;
enum Specialnist { KOMP_NAUKY, INFORMATYKA, MAT_EKON, FIZ_INF, TRUD_NAVCH };
string specStr[] = {
    "Комп'ютерні науки",
    "Інформатика",
    "Математика та екон. ",
    "Фізика та інформ.",
    "Трудове навчання"
};
struct Student
{
    string prizv;
    unsigned kurs;
    Specialnist spec;
    int fizyka;
    int matematyka;
    int informatyka;
};
void Create(Student* p, const int N);
void Print(const Student* p, const int N);
void PrintAverageMarks(const Student* p, const int N);
double PercentGoodPhysics(const Student* p, const int N);
int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    int N;
    cout << "Введіть кількість студентів N: ";
    cin >> N;
    Student* p = new Student[N];
    Create(p, N);
    Print(p, N);
    PrintAverageMarks(p, N);

    double proc = PercentGoodPhysics(p, N);
    cout << fixed << setprecision(2);
    cout << "\nПроцент студентів, які отримали з фізики оцінки \"5\" або \"4\": "
        << proc << "%" << endl;
    delete[] p;
    return 0;
}
void Create(Student* p, const int N)
{
    int spec;
    for (int i = 0; i < N; i++)
    {
        cout << "Студент № " << i + 1 << ":" << endl;
        cin.get();
        cin.sync();
        cout << " прізвище: ";
        getline(cin, p[i].prizv);
        cout << " курс: ";
        cin >> p[i].kurs;
        cout << " спеціальність (0 - Комп'ютерні науки, 1 - Інформатика, "
            << "2 - Математика та економіка, 3 - Фізика та інформатика, 4 - Трудове навчання): ";
        cin >> spec;
        p[i].spec = (Specialnist)spec;
        cout << " оцінка з фізики: ";
        cin >> p[i].fizyka;
        cout << " оцінка з математики: ";
        cin >> p[i].matematyka;
        cout << " оцінка з інформатики: ";
        cin >> p[i].informatyka;
        cout << endl;
    }
}
void Print(const Student* p, const int N)
{
    cout << "========================================================================================" << endl;
    cout << "| №  |   Прізвище   | Курс |     Спеціальність     | Фізика | Математика | Інформатика |" << endl;
    cout << "----------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < N; i++)
    {
        int prizvWidth = 13 + p[i].prizv.length() / 2;
        int specWidth = 22;
        if (p[i].spec == KOMP_NAUKY)  specWidth = 22 + 16; 
        if (p[i].spec == INFORMATYKA) specWidth = 22 + 11;
        if (p[i].spec == MAT_EKON)    specWidth = 22 + 15;
        if (p[i].spec == FIZ_INF)     specWidth = 22 + 15;
        if (p[i].spec == TRUD_NAVCH)  specWidth = 22 + 15;
        cout << "| " << setw(2) << right << i + 1 << " ";
        cout << "| " << setw(prizvWidth) << left << p[i].prizv;
        cout << "| " << setw(4) << right << p[i].kurs << " ";
        cout << "| " << setw(specWidth) << left << specStr[p[i].spec];
        cout << "| " << setw(6) << right << p[i].fizyka << " ";
        cout << "| " << setw(10) << right << p[i].matematyka << " ";
        cout << "| " << setw(11) << right << p[i].informatyka << " |" << endl;
    }
    cout << "========================================================================================" << endl;
    cout << endl;
}
void PrintAverageMarks(const Student* p, const int N)
{
    cout << "Середній бал кожного студента:" << endl;
    cout << "---------------------------------" << endl;
    cout << "|   Прізвище   |  Середній бал  |" << endl;
    cout << "---------------------------------" << endl;
    cout << fixed << setprecision(2);
    for (int i = 0; i < N; i++)
    {
        int prizvWidth = 13 + p[i].prizv.length() / 2;
        double avg = (p[i].fizyka + p[i].matematyka + p[i].informatyka) / 3.0;
        cout << "| " << setw(prizvWidth) << left << p[i].prizv
            << "| " << setw(14) << right << avg << " |" << endl;
    }
    cout << "---------------------------------" << endl;
}
double PercentGoodPhysics(const Student* p, const int N)
{
    if (N <= 0)
        return 0.0;
    int k = 0;
    for (int i = 0; i < N; i++)
    {
        if (p[i].fizyka == 5 || p[i].fizyka == 4)
        {
            k++;
        }
    }
    return 100.0 * k / N;
}