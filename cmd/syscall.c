#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <syslog.h>
#include <fcntl.h>
int main(void)
{
        int fd = open("/etc/lsb-release", O_RDWR);
        if (fd == -1) {
            return 0;
        }
        char buf[256] = {0};
        memset(buf, 0, sizeof(buf));
        read(fd, buf, sizeof(buf));

        if (strstr(buf, " 16.04.5") != NULL) {
            memset(buf, 0, sizeof(buf));
            snprintf(buf, sizeof(buf), "route add -host %s gw %s", "172.16.13.0", "172.16.13.1");
            system(buf);
            syslog(LOG_INFO, "route add -host %s %s\n", "172.16.13.0", "172.16.13.1");
        }
}