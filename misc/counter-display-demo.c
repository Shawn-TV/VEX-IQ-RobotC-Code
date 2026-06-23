task main()
{
	int a = 100;
	int b = 0;

	while(b < 100)
	{
		displayTextLine(1, "%d", b);
		sleep(500);
		b = b + 1;

		displayTextLine(3, "%d", a);
		sleep(500);
		a = a - 1;
	}
}
