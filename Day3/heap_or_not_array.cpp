/*
Author: Parthkumar, Rakshit, Mahesh
Phone no: 9979237440, 8283002058, 9480722476
*/

#include <bits/stdc++.h>

using namespace std;
static int flag=0;
static int s;
class CA
{
    public:
        bool is_on_heap = false;
        void* operator new(size_t size)
        {
            flag = 1;
            return malloc(size);
        }
        void* operator new[](size_t size)
        {
            cout << "New[]\n";
            flag = 2;
            s = size/sizeof(CA);
            cout << "size=" << s << endl;
            return malloc(size);
        }
        CA()
        {
            if(flag==1)
            {
                is_on_heap = true;
                flag = 0;
            }
            else if(flag == 2)
            {
                is_on_heap = true;
                flag = 2;
                s--;
                cout << "S=" << s << endl;
                if(s==0)
                {
                    flag = 0;
                }
            }
            else
            {
                is_on_heap = false;
                flag = 0;
            }
        }
        void location()
        {
            if(this->is_on_heap == true)
            {
                cout << "in Heap\n";
            }
            else if(this->is_on_heap == false)
            {
                cout << "not in Heap\n";
            }
        }
};
int main()
{
    CA *ptr = new CA();
    CA *ptr2 = new CA[5];
    CA obj;
    obj.location();
    ptr->location();
    
    for(int i=0;i<5;i++)
    {
        (ptr2+i)->location();
    }
    delete ptr;
    return 0;
}