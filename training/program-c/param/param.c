static void func1(int arg0, int arg1, int arg2, int arg3)
{
	printf("%d\n", arg3);
}

static void func2(int arg0, int arg1, int arg2, int arg3, int arg4)
{

	printf("%d\n", arg4);
}

main()
{
	int a,b,c,d;
	func1(a,b,c,d);
	func2(a,b,c,d,0x66);
}
