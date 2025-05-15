#include <iostream>
#include <cmath>
using namespace std;


class SegmentTree
{
private:

    long long n;                              // Длина массива дополненная до ближайшей степени двойки 
    long long tree_length;                    // Массива, который хранит дерево отрезков   
    long long plug;                           // Число, являющееся "нейтральным" по отношению к применяемой операции
    long long tree_depth;                     // Число от 0 и больше, которое указывает на глубину дерева. При 0 - есть ровно одна вершина
    
    long long* tree;                          // Дерево отрезков в виде массива
    long long** cover_tree;                   // Дерево покрытия
    
    // ###  Место для дополнительных деревьев  ###
    
public:

    void Update(long long node)
    {
        // ###  Место вычисления узлов всех деревьев при условии, что потомки уже вычислены  ###
    }

    void Build(long long* array, long long node, long long start, long long end, long long length)
    {
        if (start == end)
        {
            tree[node] = start < length ? array[start] : plug;
            
            // ###  Место для доопределения дополнительных деревьев  ###
        }
        else 
        {
            long long mid = (start + end) / 2;
            
            Build(array, 2 * node + 1, start,   mid, length);
            Build(array, 2 * node + 2, mid + 1, end, length);
            
            Update(node)
        }
        
        cover_tree[node] = new long long[2]{start, end};
    }

    SegmentTree(long long* array, long long length, long long neutral_element)
    {
        tree_depth = ceil(log2(length));
        n = pow(2, tree_depth);
        tree_length = 2 * n - 1;
        plug = neutral_element;
        
        tree = new long long[tree_length];
        cover_tree = new long long*[tree_length];
        
        // ###  Место выделения памяти под дополнительные деревья  ###
        
        Build(array, 0, 0, n - 1, length);
    }
    
    
    void Query(long long l, long long r, long long node = 0)     // Меняем возвращаемый тип по своему усмотрению
    {
        // Что-то возвращаем, если узел был покрыт полностью
        if (l <= cover_tree[node][0] and cover_tree[node][1] <= r)      
            return;
        
        // Что-то возвращаем, если узел не был даже задет
        if (r < cover_tree[node][0] || cover_tree[node][1] < l)
            return;
        
        // Если узел был перекрыт частично, то мы делегируем расчёт своим потомкам
        long long* left_ans = Query(l, r, 2 * node + 1);
        long long* right_ans = Query(l, r, 2 * node + 2);
        
        // ###  Определяем логику расчёта при неполном перекрытии  ###
    }

    
    void Update(long long index, long long value, long long node = 0, long long depth = 0)
    {
        if (index < cover_tree[node][0] || index > cover_tree[node][1])
            return;

        if (depth != tree_depth)
        {
            if (index <= cover_tree[2 * node + 1][1])
                Update(index, value, 2 * node + 1, depth + 1);
            else // if (index >= cover_tree[2 * node + 2][0])
                Update(index, value, 2 * node + 2, depth + 1);
        }
        
        Update(node);
    }

    
};
