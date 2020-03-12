#include <stdio.h>  
#include <stdlib.h>  
#include <unistd.h>  
#include <string.h>  
#include <errno.h>
#include <sys/ioctl.h>
#include <netinet/in.h>  
#include <net/route.h>  
#include <net/if.h> 
#include <sys/socket.h>  
#include <sys/types.h>  
#include <arpa/inet.h> 

int network_set_getway(int sock_id, char *interface_name, char *gateway)
{
    struct rtentry rt;
    u_int32_t dstaddr, gwaddr;

    dstaddr = inet_addr("0.0.0.0");
    gwaddr = inet_addr(gateway);
    
    memset (&rt, 0, sizeof (rt));
    
    /*set Destination addr*/
    memset ((char *) &(rt.rt_dst),0, sizeof(rt.rt_dst)); 
    rt.rt_dst.sa_family = AF_INET;
    ((struct sockaddr_in *)&(rt.rt_dst))->sin_addr.s_addr= dstaddr;
    
    /*set gw addr*/
    memset ((char *) &(rt.rt_gateway),0, sizeof(rt.rt_gateway)); 
    rt.rt_gateway.sa_family = AF_INET;
    ((struct sockaddr_in *)&(rt.rt_gateway))->sin_addr.s_addr= gwaddr;

    
    /*set genmask addr*/
    memset ((char *) &(rt.rt_genmask),0, sizeof(rt.rt_genmask)); 
    rt.rt_genmask.sa_family = AF_INET;
    ((struct sockaddr_in *)&(rt.rt_genmask))->sin_addr.s_addr= 0L;
    
    
    rt.rt_dev = interface_name;
    rt.rt_flags = RTF_GATEWAY;
    
    if (ioctl(sock_id, SIOCADDRT, &rt) < 0)
    {
        printf("SIOCADDRT failed: %s %d\n", strerror(errno),RTF_GATEWAY);
        return -1;
    }
    
    return 0;
}

int network_get_gatway(int sock_id,char *interface_name, char *gateway)
{
    FILE *fp;    
    char buf[256]; // 128 is enough for linux    
    char iface[16];    
    unsigned long dest_addr,net_addr,gate_addr;   
    struct in_addr addr;
    unsigned long *p;

    fp = fopen("/proc/net/route", "r");    
    if (fp == NULL)    
    return -1;    
    /* Skip title line */    
    fgets(buf, sizeof(buf), fp);    
    while (fgets(buf, sizeof(buf), fp))
    {    
        if (sscanf(buf, "%s\t%lX\t%lX", iface, &dest_addr, &gate_addr)!= 3||dest_addr != 0||!strcpy(iface,interface_name))    
        continue;    
        break;    
    }    
    
    fclose(fp);  
    printf("gate_addr:%lx\n", gate_addr);
    memcpy(&addr,&gate_addr,4);
    strcpy( gateway,inet_ntoa(addr));
    printf("gateway=%s\n",gateway);
    return 0;   
}



int main() {  
    int sock_id;  
    char ifname[]="enp0s8";  
    char getway[16]="10.0.2.2";  
    char getway1[16];    
    sock_id=socket(AF_INET,SOCK_DGRAM,0);  
    if (sock_id < 0)  
    {   
        printf("socket failed: %s\n", strerror(errno));  
        return -1;  
    }   
    network_set_getway(sock_id,ifname, getway);  
    network_get_gatway(sock_id,ifname, getway1);      
    return 0; 
}
