#ifndef DQLITE_TEST_CLIENT_H
#define DQLITE_TEST_CLIENT_H

#include <stdint.h>

struct test_client {
	int fd;
};

/*
 * Initialize a test client.
 *
 * @fd: The file descriptor for writing requests and reading responses.
 */
void test_client_init(struct test_client *c, int fd);

/*
 * Deallocate the memory used by the test client, if any.
 */
void test_client_close(struct test_client *c);

/*
 * Initialize the client, writing the protocol version.
 */
int test_client_handshake(struct test_client* c);

int test_client_open(struct test_client *c, const char *name, uint32_t *db_id);
int test_client_prepare(struct test_client *c, uint32_t db_id, const char *sql, uint32_t *stmt_id);
int test_client_exec(struct test_client *c, uint32_t db_id, uint32_t stmt_id);
int test_client_query(struct test_client *c, uint32_t db_id, uint32_t stmt_id);
int test_client_finalize(struct test_client *c, uint32_t db_id, uint32_t stmt_id);

/*
 * Send a Helo request.
 */
int test_client_helo(struct test_client *c, char **leader, uint8_t *heartbeat);

#endif /* DQLITE_TEST_CLIENT_H */