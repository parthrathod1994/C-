/*
Author: Parthkumar, Rakshit, Mahesh
Phone no: 9979237440, 8283002058, 9480722476
*/
#include <bits/stdc++.h>

using namespace std;
static int flag;
class CA
{
    public:
        
        bool is_on_heap = false;
        void* operator new(size_t size)
        {
            flag = 1;
            return malloc(size);
        }
        CA()
        {
            if(flag==1)
            {
                this->is_on_heap = true;
            }
            else
            {
                this->is_on_heap = false;
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
    CA obj;
    CA *ptr = new CA();
    obj.location();
    ptr->location();
    delete ptr;
    return 0;
}