#include <iostream>
#include <sstream>
#include <string>

struct Usel
{
    int key; Usel* next;
};
struct UselF
{
    float key; UselF* next;
};
struct StackF
{
    UselF* head;
    StackF() { head = 0; };
    ~StackF() { Clear(); };
    void Push(float key1)
    {
        UselF* p = new UselF;
        p->key = key1;
        p->next = head;
        head = p;
    }
    float Pop()
    {
        if (head != 0) {
            float k = head->key;
            UselF* p = head;
            head = head->next;
            delete p;
            return k;
        }
        else return -1;
    }
    float Top()
    {
        if (head != 0)return  head->key;
        else return -1;


    }
    bool Empty()
    {
        if (head == 0) return true;
        else return false;
    }
    void Clear();
};
struct Stack
{
    Usel* head;
    Stack() { head = 0; };
    ~Stack() { Clear(); };
    void Push(int key1) 
    {
        Usel* p = new Usel;
        p->key = key1;
        p->next = head;
        head = p;
    }
    int Pop() 
    {
        if (head != 0) {
            int k = head->key;
            Usel* p = head;
            head = head->next;
            delete p;
            return k;
        }
        else return -1;
    }
    int Top() 
    {
        if (head != 0)return  head->key;
        else return -1;
        
        
    }
    bool Empty() 
    {
        if (head == 0) return true;
        else return false;
    }
    void Clear();
};
void Stack::Clear() 
{
    int k;
    while (head) k = Pop();
}
void StackF::Clear()
{
    int k;
    while (head) k = Pop();
}
bool Digit(char ch) // определяет число ли на входе
{
    if ((int)ch > 47 and (int)ch < 58) return true;
    else return false;
}
bool lesson(char ch)//определяет буква ли на входе
{
    if ((int)ch > 96 and (int)ch < 123) return true;
    else return false;
}
int prioritet(char s)//определяет приоритет знаков 
{
    if (s == '(' ) return 0;
    else if (s == '1') return 1;
    else if (s == '+' or s == '-') return 2;
    else return 3;
}
float move(float num1, float num2, char c) //определяет тип операции
{
    if (c == '/')return num1 / num2;
    else if (c == '*') return num1 * num2;
    else if (c == '+') return num1 + num2;
    else return num1 - num2;
}
int formirovanie(char* s, int i, char* p,  Stack prior, Stack znak)
{
    int f = 0;
    int n = 0;//счетчик для  полиза
    int k = 0;//счетчик для записанной строки
    while (k < i)
    {
        if (Digit(s[k]) or lesson(s[k])) //если встречается цифра, то записываем ее сразу в ПОЛИЗ
        {
            while (Digit(s[k]) or lesson(s[k])) 
            {
                p[n] = s[k];
                k++;
                n++;
            }    
            p[n] = ' ';
            n++;
        }
        else// иначе сравниваем приоритеты знаков
        {
            if (s[k] == '(') //если встречается открывающая скобка, сразу записываем ее в стек знаков и приоритетов
            {
                f++;
                znak.Push(s[k]);
                prior.Push(prioritet(s[k]));
                k++;
            }
            else if (s[k] == ')')//если встречается закрывающая скобка, то записываем все знаки до открывающей скобки
            {
                f--;
                if (f <0)//Проверка на WARNING
                {
                    std::cout << "WARNING : Пропущена скобка";
                    return -1;
                }
                while (znak.Top() != '(')
                {
                    p[n] = znak.Top();
                    znak.Pop();
                    prior.Pop();
                    n++;
                }
                znak.Pop();
                prior.Pop();
                k++;
            }
            else if (prioritet(s[k]) >= prior.Top())//если встретился знак операции, то сравниваем приоритеы нового знака и знака в стеке
            {
                znak.Push(s[k]);
                prior.Push(prioritet(s[k]));
                k++;
            }
            else //иначе записываем
            {
                while (prioritet(s[k]) < prior.Top())
                {
                    p[n] = znak.Top();
                    znak.Pop();
                    prior.Pop();
                    n++;
                }
                znak.Push(s[k]);
                prior.Push(prioritet(s[k]));
                k++;
            }
        }
    }
    while (znak.Top() != -1)//если в стеке остались знаки операций, то записываем поочередно в конец полиза
    {
        p[n] = znak.Top();
        znak.Pop();
        prior.Pop();
        n++;
    }
    if (f != 0)//Проверка на WARNING
    {
        std::cout << "WARNING : Пропущена скобка";
        return -1;
    }
    std::cout  <<"Сформированный ПОЛИЗ: "<<  p;
    return n;//воврат длины полиза
}
int vichislenie(char* s,  char* p,int n,StackF numbers ,Stack prior, Stack znak)
{
    std::cout << "\n";
    int i = 0;
    while (i<n)
    {

        if (Digit(p[i]))//если число, то считывание и перевод в тип int и занесение в стек чисел
        {
            int k = 0;
            int a = p[i] - '0';
            k = k * 10 + a;
            i++;
            while (Digit(p[i])) 
            {
                a = p[i] - '0';
                k = k * 10 + a;
                i++;
            }
            numbers.Push(k);
            i++;
        }
        else if (lesson(p[i])) 
        {
            int a;
            std::cout << "Введите переменную " << p[i] << ':';
            std::cin >> a;
            numbers.Push(a);
            i++;
            i++;
        }
        else //иначе выполняем последнюю операцию
        {
            char z = p[i];
            if (numbers.Top() == -1) //Проверка на WARNING
            {
                std::cout << "WARNING : Пропущен операнд"; 
                return -1;
            }
            float num2 = numbers.Top();
            numbers.Pop();
            if (numbers.Top() == -1)//Проверка на WARNING
            {
                std::cout << "WARNING : Пропущен операнд";
                return -1;
            }
            float num1 = numbers.Top();
            numbers.Pop();
            numbers.Push(move(num1, num2, z ));
            i++;
        }
    }
    if (numbers.Top() != -1 and znak.Top()!= -1) //Проверка на WARNING
    {
        std::cout << "WARNING : Пропущена операция";
        return -1;
    }
    std::cout <<'\n'<<"Ответ: " <<numbers.Top();//вывод
    return 0;
}
int main()
{
    int a = 0;
    setlocale(LC_ALL,"RU");
    char p[160]="";char ch;//массив для полиза
    char s[80];//массив под исходную строку
    Stack znak, prior;//объявление двух стеков для знаков и их приоритетов
    StackF numbers;//объявление стека для чисел
    std::cout << "Введите выражение: ";
    std::cin >> s;//ввод строки
    std::cout <<'\n';
    int i = strlen(s);//длинна строки
    int k = 0;
    int f = 0;
    int n =formirovanie(s, i, p, prior, znak );//формирование и вывод полиза
    if (n == -1)return -1;
    vichislenie(s, p, n, numbers, prior, znak);//вычисление по полизу и вывод ответа
}
