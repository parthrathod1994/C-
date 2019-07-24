
namespace nm02
{
	void main()
	{
		int x = 10;
		int y = 20;

		//int *ptr = &x;//l1 & l2 works
		//const int *ptr = &x;//l1 (pointer to a constant) works & l2 does not work
		 //int const *ptr = &x;//l1 (pointer to a constant) works & l2 does not work
		//int  * const ptr = &x;//l1 not work and l2 works (constant pointer) 

		int const * const  ptr = &x;//constant pointer to a constant l1 & l2 does not work
		//ptr = &y;//l1;will
		//*ptr = 999;//l2 not
	}
}