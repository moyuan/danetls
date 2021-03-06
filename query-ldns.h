/*
 * query-ldns.h
 *
 */

#ifndef __QUERY_LDNS_H__
#define __QUERY_LDNS_H__

#include <ldns/ldns.h>
#include "tlsardata.h"

/*
 * Flags: dns bogus or indeterminate; authenticated responses 
 */

int dns_bogus_or_indeterminate;
int v4_authenticated;
int v6_authenticated;
int mx_authenticated;
int srv_authenticated;
int tlsa_authenticated;

/*
 * addresses: (head of) linked list of addrinfo structures
 */

size_t address_count;

struct addrinfo *
insert_addrinfo(struct addrinfo **headp,
		struct addrinfo *current, struct addrinfo *new);


/*
 * tlsa_count and response_rcode
 */

size_t tlsa_count;
ldns_pkt_rcode tlsa_response_rcode;

/*
 * get_addresses_type() and get_addresses()
 */

ldns_rr_list *get_addresses_type(ldns_resolver *resolver,
                                 ldns_rr_type rrtype,
                                 ldns_rdf *host_rdf);

struct addrinfo *get_addresses(ldns_resolver *resolver,
			       const char *hostname, uint16_t port);


/*
 * get_tlsa(): get TLSA records. 
 * Populates tlsa_rdata_list linked list with TLSA record rdata.
 */

tlsa_rdata *get_tlsa(ldns_resolver *resolver, 
		     const char *hostname, uint16_t port);

ldns_resolver *get_resolver(char *conffile);

#endif /* __QUERY_LDNS_H__ */
