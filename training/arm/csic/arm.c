#include <stdio.h>

main()
{
	int count = 20;

	/*
	 * objdump:
	 ldr     r3, [fp, #-16]
	 mov     r4, r3
	 add     r4, r4, #80     ; 0x50
	 str     r4, [fp, #-16]
	 */
    asm(
        "add %0, %0,  $80\n"
        : "+r"(count) : :);

	printf("%d\n", count);
}
