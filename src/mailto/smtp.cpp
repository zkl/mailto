#include <stdio.h>
#include "smtp.h"

void smtp_recv(struct _network_ * network, 
		struct _net_socket_ * netsocket);

smtp_t * smtp_create(network_t * network)
{
	smtp_t * smtp = (smtp_t *)malloc(sizeof(smtp_t));
	memset(smtp, 0, sizeof(smtp_t));
	smtp->network = network;

	return smtp;
}

void smtp_free (smtp_t * smtp)
{
	free(smtp);
}

int smtp_connect(smtp_t * smtp, const char * host, int port)
{
	network_config(smtp->network, NET_SET_RECV_EVENT, (void *)&smtp_recv);
	smtp->netsockt = network_connect(smtp->network, host, port);
	net_socket_set_user_data(smtp->netsockt, smtp);
	return 0;
}

void smtp_login(smtp_t * smtp, const char * usr, const char * pwd);
void smtp_noop (smtp_t * smtp);
void smtp_send (smtp_t * smtp, const char * form, const char * to, 
			const char * mail);
void smtp_eventctl()
{
}

void smtp_recv(struct _network_ * network, struct _net_socket_ * netsocket)
{
	smtp_t * smtp = (smtp_t *)net_socket_get_user_data(netsocket);
	printf("%s\n", net_socket_data(netsocket));
}
