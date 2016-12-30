#ifndef   FILENAME
#define   FILENAME
#include "common/type.h"
#endif

#include <arpa/inet.h>
#include <netinet/in.h>

#include <pthread.h>
#include <stdlib.h>
#include <math.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#include <fcntl.h>
#include <malloc.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <sys/resource.h>


#include "neroDateShow.h"
/*
#include "NeuralNetwork/NeuralNetwork.h"
#include "common/Neuron.h"
#include "neroMain.h"
#include "common/fileOperating.h"
#include "tools/readUTF8File.h"
#include "tools/createDot.h"
#include "tools/Nero_IO.h"
#include "NeuralNetwork/NeuralOperating.h"
#include "tools/Nero_IO.h"
#include "tools/Nero_Task.h"
#include "neroMain.h"
*/
struct  NeuronObjectMsg_
{ 
long MsgId; 
nero_8int fucId;
void    *  Obi; 
} ;
struct  NeuronObjectMsgWithStr_
{ 
long MsgId; 
nero_8int fucId;
NeuronObject * Obi; 
nero_8int str[100];
} ;
struct  IODataMsg_
{ 
long MsgId; 
nero_8int fucId;
nero_s32int operateKind; 
nero_8int str[300];
} ;




void sendMsgToLogSys(int argc, char* argv[]);
static struct  NeuronObjectMsgWithStr_    neroObjMsgWithStr_st;
nero_s32int Log_mq_id;
#define IPCKEY 0x111
static nero_8int  file_path_getcwd[FILEPATH_MAX]="/tmp";/*保存当前目录*/
int main(int argc, char* argv[])
{


	// int i=0;
	// char **p=argv;
	// printf("argc=%d \n",argc);
	// while(  i  <=  argc)
	// {

	// 	printf("srring  %d :%s\n",i,p[i]);
	// 	i++;
	// }
	char * Log_ipckey="/tmp/Log_ipckey2";


	// nero_s32int x=0;
	// long MsgId;
	// struct { long MsgId; char text[100]; } LogMsg;
	// struct  NeuronObjectMsg_  * NeroArgMsg_st;
	// struct  NeuronObjectMsgWithStr_  * NeroWithStrArgMsg_st;
	key_t ipckey;
	
	// nero_s32int fucId;
	// nero_s32int received;
	// nero_s32int i = 0;

	// const nero_s32int size_message_map = 
	//       sizeof(nero_msg_print_map) / sizeof(struct one_arg_message_entry );   //求得表长
	// const nero_s32int size_message_map2 = 
	//       sizeof(nero_msg_WithStr_map) / sizeof(struct two_arg_message_entry );   //求得表长
	
    // printf("i=%d.\n",size_message_map);
    // printf("i=%d.\n",size_message_map2);
	 
	 getcwd(file_path_getcwd,FILEPATH_MAX);
	 /*设置日志目录*/
	 // sprintf(logFile,"%s/log/log.txt",file_path_getcwd);
	 // printf("file_path_getcwd: %s  and logFile=%s",file_path_getcwd,logFile);
	 // createFile(logFile);
	 
	 // sprintf(AllKindOfFile,"%s/log/AllKindOfFile.txt",file_path_getcwd);
	 // createFile(AllKindOfFile);
	

	/* Generate the ipc key */

	ipckey = ftok(Log_ipckey , IPCKEY);
	printf("strerror: %s\n", strerror(errno)); //转换错误码为对应的错误信息
	printf("Log_ipckey key is %d\n", ipckey);
/*	*/
	/* Set up the message queue */
	Log_mq_id = msgget(ipckey,0);// IPC_CREAT
	printf("strerror: %s\n", strerror(errno)); //转换错误码为对应的错误信息

	sendMsgToLogSys( argc,argv);
	return 0;
}





void sendMsgToLogSys(int argc, char* argv[])
{

	int res,kind;


	#ifdef Nero_DeBuging16_12_30_
		// printf  msg  by  obj
		neroObjMsgWithStr_st.MsgId = MsgId_Log_PrintObjMsgWithStr;
		neroObjMsgWithStr_st.fucId = 1;//打印某个具体obj得信息  Log_printSomeMsgForObj
		neroObjMsgWithStr_st.Obi = NULL;
		sprintf(neroObjMsgWithStr_st.str,"sendMsgToLogSys  msg:%x",neroObjMsgWithStr_st.Obi);
		res=msgsnd( Log_mq_id, &neroObjMsgWithStr_st, sizeof(neroObjMsgWithStr_st), 0);			
	#endif





	#ifdef Nero_DeBuging16_12_30
		{
		kind=2013;
	// print  all  of  the  kind  obj
		neroObjMsgWithStr_st.MsgId = MsgId_Log_PrintObjMsgWithStr;
		neroObjMsgWithStr_st.fucId =2;/*打印某个类别下面的所有的衍生类    Log_printAllKindOf*/
		neroObjMsgWithStr_st.Obi =NULL;
		 int xxxxxx=kind;
		memcpy(neroObjMsgWithStr_st.str,&xxxxxx,sizeof(nero_s32int));
		res=msgsnd( Log_mq_id, &neroObjMsgWithStr_st, sizeof(neroObjMsgWithStr_st), 0);			
		}
 	#endif





		printf("strerror: %s\n", strerror(errno)); //转换错误码为对应的错误信息
		printf("res is %d\n", res);
}



















