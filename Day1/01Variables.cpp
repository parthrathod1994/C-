namespace nm1
{
	//a name given to a memory location is a variable
	int a = 100;//survives the life of the application and global scope
	static int b = 200;//survives the life of the application and file scope


	void main()
	{
		static int c = 300;//survives the life of the application and function scope
		int d = 400;//survives the life of the function and function scope


		int *e = new int(500);//life and scope custom managed


		delete e;
	}
}