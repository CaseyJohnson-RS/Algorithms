#include <iostream>
#include <cmath>
using namespace std;


class SegmentTree
{
private:

    int n;                              // Длина массива дополненная до ближайшей степени двойки 
    int tree_length;                    // Массива, который хранит дерево отрезков   
    int plug;                           // Число, являющееся "нейтральным" по отношению к применяемой операции
    
    int* tree;                          // Дерево отрезков в виде массива
    int** cover_tree;                   // Дерево покрытия
    
    // ...
    
public:

    void build(int* array, int node, int start, int end, int length)
    {
        if (start == end)
        {
            tree[node] = start < length ? array[start] : plug;
            
            // ...
        }
        else 
        {
            int mid = (start + end) / 2;
            
            build(array, 2 * node + 1, start,   mid, length);
            build(array, 2 * node + 2, mid + 1, end, length);
            
            // ...
        }
        
        cover_tree[node] = new int[2]{start, end};
    }

    SegmentTree(int* array, int length, int neutral_element)
    {
        n = pow(2, ceil(log2(length)));
        tree_length = 2 * pow(2, ceil(log2(length))) - 1;
        plug = neutral_element;
        
        tree = new int[tree_length];
        cover_tree = new int*[tree_length];
        
        // ...
        
        build(array, 0, 0, n - 1, length);
    }
    
    
    void Query(int l, int r, int node = 0)     // Меняем возвращаемый тип по своему усмотрению
    {
        // Что-то возвращаем, если узел был покрыт полностью
        if (l <= cover_tree[node][0] and cover_tree[node][1] <= r)      
            return new int[2] {tree[node], additional_tree[node]};
        
        // Что-то возвращаем, если узел не был даже задет
        if (r < cover_tree[node][0] or cover_tree[node][1] < l)
            return new int[2] {0,0};
        
        // Если узел был перекрыт частично, то мы делегируем расчёт своим потомкам
        int* left_ans = Query(l, r, 2 * node + 1);
        int* right_ans = Query(l, r, 2 * node + 2);
        
        // ...
    }
};
