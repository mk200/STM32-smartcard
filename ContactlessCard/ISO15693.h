
#ifndef _ISO15693_H
#define _ISO15693_H


/*
文件用途:			ISO15693协议
作者:					张栋培
创建时间:			2018/10/22
更新时间:			2018/10/22
版本:					V1.1

*/



#include "stm32f10x.h"
#include "THM3070.h"


/*函数返回值含义对照表

	//所有函数0x00代表成功,非0x00代表失败
	0x00	执行成功
	0x04	接收数据超时

	//卡响应的错误码,由ISO15693定义
	0x01	不支持命令,即请求码不能被识别
	0x02	命令不能被识别,如:发生一次格式错误
	0x03	不支持命令选项
	0x0F	错误码不支持该错误
	0x10	规定块不可用
	0x11	规定块被锁,因此不能再锁
	0x12	规定块被锁,内容不能被改变
	0x13	规定块没有被成功编程
	0x14	规定块没有被成功锁定


*/



uint8_t FINDV(uint16_t ENAndAFI,uint8_t* DAT_UID);															//查找

uint8_t Inventory(uint16_t ENAndAFI,uint8_t* DAT_UID);													//清查
uint8_t Stayquiet(void);																												//静默
uint8_t Select(void);																														//选择
uint8_t ResetToReady(void);																											//准备

uint8_t ReadBlocks(uint8_t BlockNum,uint8_t* BlockData,uint16_t* BlockDataLen);	//读块
uint8_t WriteBlocks(uint8_t BlockNum,uint8_t* BlockData,uint16_t BlockDataLen);	//写块
uint8_t ReadMultipleBlocks(uint8_t BlockNum,uint8_t BlockLen,uint8_t* BlockData,uint16_t* BlockDataLen);	//读多个块
uint8_t WriteMultipleBlocks(uint8_t BlockNum,uint8_t BlockLen,uint8_t* BlockData,uint16_t BlockDataLen);	//写多个块

uint8_t WriteAFI(uint8_t AFI);																									//写AFI
uint8_t WriteDSFID(uint8_t DSFID);																							//写DSFID

uint8_t ReadSysInfo(uint8_t* InfoData,uint16_t* InfoDataLen);										//获取系统信息
uint8_t ReadMultipleStatus(uint8_t BlockNum,uint8_t BlockLen,uint8_t* Status,uint16_t* StatusLen);				//读多个块状态

uint8_t SendRFUCMD(uint8_t* SendData,uint16_t SendDataLen,uint8_t* RecvData,uint16_t* RecvDataLen);				//透传数据

uint8_t TESTV(void);																														//测试卡片是否仍在天线场内



uint8_t LockBlocks(uint8_t BlockNum);																						//永久锁定块,慎用
uint8_t LockAFI(void);																													//永久锁定AFI,慎用
uint8_t LockDSFID(void);																												//永久锁定DSFID,慎用

#endif

