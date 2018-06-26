#include <stdio.h>

main()
{
	int count = 20;

	/*
	 * objdump:
	 * movl   $0x14,0x1c(%esp)
	 * addl   $0x50,0x1c(%esp)
	 */
	asm("addl $80, %0 \n"
		: : "m" (count) :);

	printf("%d\n", count);
}
