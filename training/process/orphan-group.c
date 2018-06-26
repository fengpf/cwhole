#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>

#define errexit(msg) do{ perror(msg); exit(EXIT_FAILURE); } while(0)

static void sig_hup(int signo)
{
        printf("SIGHUP received, pid = %d\n", getpid());
}

static void sig_cont(int signo)
{
        printf("SIGCONT received, pid = %d\n", getpid());
}

static void sig_ttin(int signo)
{
        printf("SIGTTIN received, pid = %d\n", getpid());
}

static void pr_ids(char *name)
{
	printf("%s: pid = %d, ppid = %d, pgrp = %d, tpgrp = %d\n",
			name, getpid(), getppid(), getpgrp(), tcgetpgrp(STDIN_FILENO));
}

int main(int argc, char *argv[])
{
	char c;
	pid_t pid;

	setbuf(stdout, NULL);

	pr_ids("parent");
	if ((pid = fork()) < 0) {
		errexit("fork error");
	} else if (pid > 0) { /* parent */
		sleep(5);
		printf("parent exit\n");
		exit(0);
	} else { /* child */
		pr_ids("child...1");

		signal(SIGCONT, sig_cont);
		signal(SIGHUP, sig_hup);
		signal(SIGTTIN, sig_ttin);

		kill(getpid(), SIGTSTP);
		//sleep(10);

		pr_ids("child...2");

		if (read(STDIN_FILENO, &c, 1) != 1) {
			printf("read error from controlling TTY, errno = %d\n", errno);
		}
		printf("child exit\n");
	}

	exit(0);
}
