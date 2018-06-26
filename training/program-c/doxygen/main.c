/**
 * @file
 * @author  宋宝华 <xxx@example.com>
 * @version 1.0
 *
 * @section LICENSE
 *
 * GPLv2 自由软件
 *
 * @section DESCRIPTION
 *
 * 一个最简单的例子
 */


/**
 * Constructor that sets the time to a given value.
 * 
 * @param timemillis Number of milliseconds 
 *        passed since Jan 1, 1970.
 */
Time (int timemillis) {
    // the code
}

/**
 * say hi
 * 
 * @param str what you are saying
 */
void sayhi(char *str) __attribute__((weak))
{
	printf("%s\n", str);
}

main()
{
	sayhi();
}
