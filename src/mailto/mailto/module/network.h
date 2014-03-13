/*******************************************************************************
**                                                  
** ��    ��:  v 1.1.0                                                  
** ��    ��:  �����������ӣ���Ҫ��������ͻ���
** ��    ��:  Wed. 26 Feb 2014   �޸��� Thur 3 Mar 2014 
** ��    Ȩ:  
** ��    ��:  ������ 
** ��    ע:          
** ��    ��:  3 Mar 2014 : �����¼��������                
*******************************************************************************/
#ifndef NETWORK_H
#define NETWORK_H

#include <windows.h>
#include "dns.h"
#include "queue.h"
#include "list.h"

struct _network_;
struct _net_socket_;

typedef struct _network_
{
	int dsp;
	dns_t * dns;
	linked_list_t * net_sockets;
	void * arrived_callback;
	void * writeed_callback;
}network_t;

typedef struct _net_socket_
{
	int dsp;
	int statu;
	network_t * network;
	queue_t rdque;
	queue_t wtque;
	linked_list_node_t * linked_node;
	void * user_data;
}net_socket_t;

void           network_create (network_t ** network); /* ��ʼ�� ����ģ�� */
void           network_delete  (network_t * network);
net_socket_t * network_connect (network_t * network, const char * host, int port);
int            network_procmsg (network_t * network); /* ����������Ϣ */

// cmd 1 - parm void callback(network_t * network, net_socket_t * netsocket); �����ݿɶ�
// cmd 2 - parm void callback(network_t * network, net_socket_t * netsocket); �����ݿ�д
void           network_eventctl(network_t * network, int cmd, void * parm); // ʹ���¼��ķ�ʽ����


int    net_socket_size (net_socket_t * socket);    // �ɶ����ݴ�С
char * net_socket_data (net_socket_t * socket);    // ���ݵ�ַָ��
char * net_socket_pop  (net_socket_t * socket, int bytes); // ���ݳ���
int    net_socket_write(net_socket_t * socket, const char * buf, int size);
int    net_socket_statu(net_socket_t * socket);
void   net_socket_close(net_socket_t * socket);
void   net_socket_set_user_data(net_socket_t * socket, void * d); // �����û�����
void * net_socket_get_user_data(net_socket_t * socket);           // ��ȡ�û�����

#endif