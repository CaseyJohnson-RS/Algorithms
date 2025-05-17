#include <iostream>
#include <cmath>
using namespace std;


class SegmentTree
{
private:

    long long* data;                            // Оригинальный массив 
    long long data_length;                      // Длина оригинального массива

    long long n;                                // Длина массива дополненная до ближайшей степени двойки 
    long long tree_length;                      // Массива, который хранит дерево отрезков   
    long long plug = -1;                        // Число, являющееся "нейтральным" по отношению к применяемой операции
    long long tree_depth;                       // Число от 0 и больше, которое указывает на глубину дерева. При 0 - есть ровно одна вершина
    
    long long* tree;                            // Дерево отрезков в виде массива
    long long** cover_tree;                     // Дерево покрытия
    
public:

    void ForestMemoryAllocation()
    {
        tree = new long long[tree_length];
        cover_tree = new long long*[tree_length];

        // ...
    }

    void UpdateNode(long long node)
    {
        long long left_child = 2 * node + 1;
        long long right_child = left_child + 1;

        // ...
    }

    void UpdateLeaf(long long node, long long value)
    {
        // ...
    }

    long long Query(long long l, long long r, long long k, long long node = 0, long long depth = 0)     // Меняем возвращаемый тип по своему усмотрению
    {
        // ...
            
    }

    // ### Код дальше не требует изменений ###

    void Build(long long start, long long end, long long node = 0)
    {
        cover_tree[node] = new long long[2]{start, end};

        if (start == end)
        {
            UpdateLeaf(node, start < data_length ? data[start] : plug);
            return;
        }

        long long mid = (start + end) / 2;
        
        Build(start, mid, 2 * node + 1);
        Build(mid + 1, end, 2 * node + 2);

        UpdateNode(node);
    }

    SegmentTree(long long* array, long long length)
    {
        tree_depth = ceil(log2(length));
        n = pow(2, tree_depth);
        tree_length = 2 * n - 1;

        data = array;
        data_length = length;
        
        ForestMemoryAllocation();
        
        Build(0, n - 1);
    }
    
    void Update(long long index, long long value, long long node = 0, long long depth = 0)
    {
        if (depth < tree_depth)
        {
            long long left_child = 2 * node + 1;
            long long right_child = left_child + 1;

            if (cover_tree[left_child][0] <= index && index <= cover_tree[left_child][1])
                Update(index, value, left_child, depth + 1);
            else
                Update(index, value, right_child, depth + 1);

            UpdateNode(node);
        }
        else 
            UpdateLeaf(node, value);
    }

    void print_tree()
    {
        for(int i = 0; i < tree_length; ++i)
            cout << tree[i] << ' ';
        cout << endl;
    }

};


int main() 
{   

    // Ввод массива

    size_t length;
    cin >> length;

    long long* array = new long long[length];
    
    for(long long i = 0; i < length; ++i)
        cin >> array[i];
    
    // Создание дерева
    
    auto tree = SegmentTree(array, length);

    // Ввод запросов

    long long q;
    cin >> q;
    
    for(int i = 0; i < q; ++i)
    {
        // ...            
    }
    
    return 0;
}