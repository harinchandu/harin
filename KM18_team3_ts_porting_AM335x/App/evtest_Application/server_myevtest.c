#include<stdio.h>
#include<sys/time.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include <linux/input.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#define _GNU_SOURCE         /* See feature_test_macros(7) */
       #include <stdio.h>

#define NAME "TOUCH_SCREEN_REPORT"
#define TYPE "EV_SYB" 
int main()
{
    int server_sockfd, client_sockfd;
    int server_len, client_len,ret;
    struct sockaddr_in server_address;
    struct sockaddr_in client_address;
server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
server_address.sin_family = AF_INET;
server_address.sin_addr.s_addr = inet_addr("192.168.1.37");
server_address.sin_port = htons(80);
server_len = sizeof(server_address);
ret=bind(server_sockfd, (struct sockaddr *)&server_address, server_len);
printf("ret value %d",ret);
perror("bind");
listen(server_sockfd, 5);
	char buffer_1 [4095];
	int i,rd,fd1,retfd;
	char buf[4096];
	int val;
	char name[256] = "Unknown";
	struct input_event ev[64];
	fd1=open("/dev/input/event0",O_RDONLY);
	if(fd1<0)
		printf("error while open the file event1\n");
        ioctl(fd1, EVIOCGNAME(sizeof(name)), name);
        printf("Input device name: \"%s\"\n", name);
	printf("***********************************server waiting***************************************************\n");
        client_len = sizeof(client_address);
        client_sockfd = accept(server_sockfd,
        (struct sockaddr *)&client_address, &client_len);
		write(client_sockfd,"<!DOCTYPE html>\n",15 );
		write(client_sockfd,"<html>\n",6 );
		write(client_sockfd,"<body>\n",6);
//		write(client_sockfd,"<style>",7);
//		write(client_sockfd,"body{background-color:lightblue;}\n",33);
//		write(client_sockfd,"h1{color:black;text-align:center;}\n",34);
//		write(client_sockfd,"</style>",7);
//		write(client_sockfd,"</head>",7);
//		write(client_sockfd,"<body>",6);			
//		write(client_sockfd,"<h1>IoT_HMI</h1>",7);
//		write(client_sockfd,"<p1>",4);
while(1)
{
	rd=read(fd1, ev, sizeof(struct input_event) * 64);
        if (rd < (int) sizeof(struct input_event)) {
                        printf("yyy\n");
                        perror("\nevtest: error reading");
                        return 1;
         }
        for (i = 0; i < rd / sizeof(struct input_event); i++)
		{
		if(ev[i].type == EV_SYN)
			{
				sprintf(buffer_1,"Event: time %ld.%06ld--------------%s------------\n",ev[i].time.tv_sec, ev[i].time.tv_usec,NAME);
				write(client_sockfd,buffer_1,1024);
				write(client_sockfd,"\n\n",2);
			}
		else
			{	
				if(ev[i].code==47){
				sprintf(buffer_1,"Event: time %ld.%06ld, type %d (EV_ABS), code %d (ABS_MT_SLOT), value %d\n",ev[i].time.tv_sec, ev[i].time.tv_usec, ev[i].type,ev[i].code, ev[i].value);
				write(client_sockfd,buffer_1,1024);
				write(client_sockfd,"\n\n",2);
		
}
				if(ev[i].code==53){
				sprintf(buffer_1,"Event: time %ld.%06ld, type %d (EV_ABS), code %d (ABS_MT_POSITION_X), value %d\n",ev[i].time.tv_sec, ev[i].time.tv_usec, ev[i].type,ev[i].code, ev[i].value);
				write(client_sockfd,buffer_1,1024);
				write(client_sockfd,"\n\n",2);
}

				if(ev[i].code==54){
				sprintf(buffer_1,"Event: time %ld.%06ld, type %d (EV_ABS), code %d (ABS_MT_POSITION_Y), value %d\n",ev[i].time.tv_sec, ev[i].time.tv_usec, ev[i].type,ev[i].code, ev[i].value);
				write(client_sockfd,buffer_1,1024);
				write(client_sockfd,"\n\n",2);
}
				if(ev[i].code==57){
				sprintf(buffer_1,"Event: time %ld.%06ld, type %d (EV_ABS), code %d (ABS_MT_TRACKING_ID), value %d\n",ev[i].time.tv_sec, ev[i].time.tv_usec, ev[i].type,ev[i].code, ev[i].value);
				write(client_sockfd,buffer_1,1024);
				write(client_sockfd,"\n\n",2);
}
				if(ev[i].code==0){
				sprintf(buffer_1,"Event: time %ld.%06ld, type %d (EV_ABS), code %d (ABS_X), value %d\n",ev[i].time.tv_sec, ev[i].time.tv_usec, ev[i].type,ev[i].code, ev[i].value);
				write(client_sockfd,buffer_1,1024);
				write(client_sockfd,"\n\n",2);
}
				if(ev[i].code==1){
				sprintf(buffer_1,"Event: time %ld.%06ld, type %d (EV_ABS), code %d (ABS_Y), value %d\n",ev[i].time.tv_sec, ev[i].time.tv_usec, ev[i].type,ev[i].code, ev[i].value);
				write(client_sockfd,buffer_1,1024);
				write(client_sockfd,"\n\n",2);
}
				if(ev[i].type==1){
				sprintf(buffer_1,"Event: time %ld.%06ld, type %d (EV_KEY), code %d (BTN_TOUCH), value %d\n",ev[i].time.tv_sec, ev[i].time.tv_usec, ev[i].type,ev[i].code, ev[i].value);
				write(client_sockfd,buffer_1,1024);
				write(client_sockfd,"\n\n",2);
}
}
//write(client_sockfd,"<!DOCTYPE html>",15 );
//write(client_sockfd,"<html>",6 );
//write(client_sockfd,"<body>",6);
//close(client_sockfd);
}
}
}
