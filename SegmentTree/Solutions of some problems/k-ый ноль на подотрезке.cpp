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
    
    // Место для дополнительных деревьев 

    long long* zero_count;
    
public:

    void ForestMemoryAllocation()
    {
        tree = new long long[tree_length];
        cover_tree = new long long*[tree_length];
        zero_count = new long long[tree_length];
    }

    void UpdateNode(long long node)
    {
        long long left_child = 2 * node + 1;
        long long right_child = left_child + 1;

        tree[node] = tree[left_child] > tree[right_child] ? tree[left_child] : tree[right_child];
        zero_count[node] = zero_count[left_child] + zero_count[right_child];
    }

    void UpdateLeaf(long long node, long long value)
    {
        tree[node] = value;
        zero_count[node] = value == 0 ? 1 : 0;
    }

    long long* Query(long long l, long long r, long long k, long long node = 0, long long depth = 0)     // Меняем возвращаемый тип по своему усмотрению
    {
        long long left_child = 2 * node + 1;
        long long right_child = left_child + 1;
        
        if (l <= cover_tree[node][0] && cover_tree[node][1] <= r)
        {
            if (depth == tree_depth)
            {
                // cout << "RETURN " << node << ' ' << zero_count[node] << ' ' << node - n + 1 << endl;
                return new long long[2]{zero_count[node], node - n + 2};
            }
                
            if (k > zero_count[node])
            {
                // cout << "1" << " k " << k << " zeros " << zero_count[node] << endl;
                return new long long[2]{zero_count[node], -1};
            }
                
            
            if (k <= zero_count[left_child])
            {
                // cout << "2" << " k " << k << " zeros " << zero_count[node] << endl;
                return Query(l, r, k, left_child, depth + 1);
            }
                
            else
            {
                // cout << "3" << " k " << k << " zeros " << zero_count[node] << endl;
                long long left_zeros = Query(l, r, k, left_child, depth + 1)[0];
                return new long long[2]{k, Query(l, r, k - left_zeros, right_child, depth + 1)[1]};
            }
        }
        
        
        // cout << "Node " << node << " K " << k << " LR " << l << ' ' << r << endl;
            
        
        if (cover_tree[node][1] < l || r < cover_tree[node][0])
        {
            // cout << "Discard by borders" << endl;
            return new long long[2]{0, -1};
        }
        
        long long* left_answer = Query(l, r, k, left_child, depth + 1);
        
        // cout << "Calc left answer: " << left_answer[0] << endl;
        
        if (left_answer[0] >= k)
        {
            // cout << k << ' ' << left_answer[0] << endl;
            // cout << "Return left ans" << endl;
            return left_answer;
        }
        else
        {
            // cout << "Return right ans" << endl;
            long long* right_answer = Query(l, r, k - left_answer[0], right_child, depth + 1);
            return new long long[2]{left_answer[0] + right_answer[0], right_answer[1]};
        }
        
        return nullptr;
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

            if (cover_tree[left_child][0] <= index || index <= cover_tree[left_child][1])
                Update(index, value, left_child, depth + 1);
            else
                Update(index, value, right_child, depth + 1);

            UpdateNode(node);
        }
        else 
            UpdateLeaf(node, value);
    }

    void print()
    {
        for(int i = 0; i < n; ++i)
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
    // tree.print();

    // Ввод запросов

    long long q;
    cin >> q;
    
    for(int i = 0; i < q; ++i)
    {
        char t;
        cin >> t;

        if (t == 's')
        {
            long long l, r, k;
            cin >> l >> r >> k;
            long long* ans = tree.Query(l - 1, r - 1, k);
            // cout << "End" << endl;
            cout << ans[1] << ' ';
        }
        else
        {
            long long a, b;
            cin >> a >> b;
            tree.Update(a - 1, b);
        }
            
    }
    
    return 0;
}