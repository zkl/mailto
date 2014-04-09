#ifndef SMTP_H
#define SMTP_H

#include "module/network.h"

typedef struct smtp_t
{
	network_t * network;
	net_socket_t * netsockt;
}smtp_t;

smtp_t * smtp_create(network_t * network);
void smtp_free (smtp_t * smtp);
int  smtp_connect(smtp_t * smtp, const char * host, int port);
void smtp_login(smtp_t * smtp, const char * usr, const char * pwd);
void smtp_noop (smtp_t * smtp);
void smtp_send (smtp_t * smtp, const char * form, const char * to, const char * mail);
void smtp_eventctl();

#endif
