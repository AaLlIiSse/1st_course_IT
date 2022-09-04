#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <codecvt> // для std::locale() и std::codecvt_utf8
using namespace std;
#define vvi vector<vector<int>>


vector<int> raskraska(vvi Matr_Svz)
{
    //Посчитаем количество связей
    int Num_Svz = 0;
    for (int i = 0; i < Matr_Svz.size(); i++)
        Num_Svz += Matr_Svz[i].size();
    Num_Svz /= 2;

    //Если граф полносвязный то красим каждую вершину в свой цвет
    if (Num_Svz == (Matr_Svz.size()-1 + 0)*Matr_Svz.size()/2)
    {
        vector<int> colors(Matr_Svz.size());
        for (int i = 0; i < Matr_Svz.size(); i++)
            colors[i] = i + 1;
        return colors;
    }

    //Возможны 2 случая для 2 несвязных вершин
    //Либо они разных цветов, тогда можно добавить между ними ребро
    //Либо они одного цвета, тогда их можно "сжать" в 1 вершину

    int F_Node = 0, S_Node = 0, F = 1;

    //Нахожу 2 несвязанные вершины
    for (int i = 0; i < Matr_Svz.size() - 1; i++)
    {
        for (int j = i + 1; j < Matr_Svz.size(); j++)
        {
            F = 0;
            for (int z = 0; z < Matr_Svz[i].size(); z++)
                if (Matr_Svz[i][z] == j)
                    F = 1;
            if (!F)
            {
                S_Node = j;
                break;
            }
        }
        if (S_Node != 0)
        {
            F_Node = i;
            break;
        }
    }

    vvi Graph1(Matr_Svz), Graph2(Matr_Svz);
    //Перебираю каждую вершину с которой связана S_Node
    for (int i = 0; i < Matr_Svz[S_Node].size(); i++)
    {
        F = 0;
        //Смотрю связана ли она с F_Node
        for (int j = 0; j < Matr_Svz[F_Node].size(); j++)
            if (Matr_Svz[S_Node][i] == Matr_Svz[F_Node][j])
                F = 1;
        //Если нет, то связываю F_Node с ней
        if (!F)
        {
            Graph1[F_Node].push_back(Matr_Svz[S_Node][i]);
            Graph1[Matr_Svz[S_Node][i]].push_back(F_Node);
        }
    }
    //Удаляю вершину S_Node в матрице связности у остальных вершин
    //Все вершины с номером больше S_Node поменяют номер на единицу меньше
    for (int i = 0; i < Graph1.size(); i++)
        for (int j = 0; j < Graph1[i].size(); j++)
        {
            if (Graph1[i][j] > S_Node)
                Graph1[i][j]--;
            else if (Graph1[i][j] == S_Node)
            {
                Graph1[i].erase(j + Graph1[i].begin());
                j--;
            }
        }
    Graph1.erase(S_Node + Graph1.begin());

    //Во втором графе связываю F_Node и S_Node
    Graph2[S_Node].push_back(F_Node);
    Graph2[F_Node].push_back(S_Node);
    
    //Запускаем рекурсивно раскраску 1 и 2 графа
    vector<int> otv1(raskraska(Graph1));    
    vector<int> otv2(raskraska(Graph2));

    //Лучший вариант тот в котором цветов меньше, т.е. номер самого большого цвета меньше
    int Max1 = 0, Max2 = 0;
    for (int i = 0; i < otv1.size(); i++)
        Max1 = Max1 < i ? i : Max1;
    for (int i = 0; i < otv2.size(); i++)
        Max2 = Max2 < i ? i : Max2;
    if (Max2 < Max1)
        return otv2;
    else
    {
        otv1.insert(S_Node + otv1.begin(), otv1[F_Node]);
        return otv1;
    }   
}

int main(int argc, char* argv[])
{
    ifstream in(argv[1]);
    int size = 0, a; //Sv - количество связей
    in >> size;
    
    //cin >> size;
    vvi save(size); //Матрица связности
    vvi Graph(size); //Граф
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
        {
           // cin >> a;
            in >> a;
            save[i].push_back(a);
            if (a && i != j)
                Graph[i].push_back(j);
        }
    
    in.close();
   
    // Тут запускаем рекурсивное нахождение раскраски
    vector<int> otv(raskraska(Graph));
    wstring text = L"<Text>\nПравильная вершинная раскраска графа\n", colors = L"<Vertex_Colors>\n";
    for (int i = 0; i < otv.size(); i++)
    {
        colors += to_wstring(i);
        switch (otv[i])
        {
        case 1: colors += L" Белый\n";
            break;
        case 2: colors += L" Красный\n";
            break;
        case 3: colors += L" Зелёный\n";
            break;
        case 4: colors += L" Синий\n";
            break;
        case 5: colors += L" Жёлтый\n";
            break;
        case 6: colors += L" Голубой\n";
            break;
        case 7: colors += L" Розовый\n";
            break;
        case 8: colors += L" Чёрный\n";
            break;
        case 9: colors += L" Белый\n";
            break;
        case 10: colors += L" Тёмно-зелёный\n";
            break;
        case 11: colors += L" Тёмно-красный\n";
            break;
        } 
    }
    
    std::wofstream out;
    out.imbue(std::locale(std::locale(), new std::codecvt_utf8<wchar_t, 0x10ffff, std::generate_header>));
    out.open(argv[1]);
    out << size << '\n';
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            out << to_wstring(save[i][j]);
            if (j != size - 1)
                out << ' ';
        }
        out << '\n';
    }
    out << text << colors;
    out.close();
}