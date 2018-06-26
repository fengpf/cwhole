#include <stdio.h>
#include <stdlib.h>
#include <sys/inotify.h>

#define MAXCOUNT 500

static int process_inotifyevent(int fd)
{
	int count = 0;
	struct inotify_event *event;
	struct inotify_event *cur;
	char buf[MAXCOUNT];

	count = read(fd, buf, MAXCOUNT);

	if (count < sizeof(*event)) {
		printf("error event\n");
		return -1;
	}

	cur = (struct inotify_event *)buf;

	while (count >= sizeof(*event)) {
		if (cur->len > 0) {
			if (cur->mask & IN_CREATE)
				printf("create file,file name = %s\n",
				       cur->name);

			if (cur->mask & IN_DELETE)
				printf("delete file,file name = %s\n",
				       cur->name);
		}

		count -= sizeof(*event);
		cur += 1;
	}

	return 0;
}

int main(int argc, char **argv)
{
	int mINotifyFd = 0;

	mINotifyFd = inotify_init();
	inotify_add_watch(mINotifyFd, "/tmp", IN_DELETE | IN_CREATE);

	while (1) {
		process_inotifyevent(mINotifyFd);
	}

	return 0;
}
