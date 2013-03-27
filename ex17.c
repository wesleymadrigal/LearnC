#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_DATA 512
#define MAX_ROWS 100

struct Address	{
	int id;
	int set;
	char name[MAX_DATA];
	char email[MAX_DATA];
};
/*
typedef struct	{
	.....
} Address;
*/
struct Database	{
	struct Address rows[MAX_ROWS];
};
struct Connection	{
	FILE *file;
	struct Database *db;
};
// constant string to a modifiable pointer
void die(const char *message)
{
	if(errno){
		perror(message);
	} else {
		printf("ERROR: %s\n", message);
	}
	exit(1);
}

void Address_print(struct Address *addr)
{
	printf("%d %s %s\n",
		addr->id, addr->name, addr->email);
}
// taking as parameters Connection struct with comprises
// a FILE and Database struct --> comprises an Address struct with 100 rows

void Database_load(struct Connection *conn)
{
	// fread(void *ptr, size_of_elements, number_of_elements, FILE *a_file);
	int rc = fread(conn->db, sizeof(struct Database), 1, conn->file);
	if(rc != 1) die("Failed to load database.");
}

struct Connection *Database_open(const char *filename, char mode)
{
	// allocate the necessary space in memory for the Connection struct
	struct Connection *conn = malloc(sizeof(struct Connection));
	if(!conn) die("Memory error");
	// allocate the necessary space in memory for the Database struct
	conn->db = malloc(sizeof(struct Database));
	if(!conn->db) die("Memory error");
	
	if(mode == 'c')	{
		conn->file = fopen(filename, "w");
	} else {
		conn->file = fopen(filename, "r+");
	
		if(conn->file)	{
			Database_load(conn);
		}
	}
	if(!conn->file) die("Failed to open the file");
	
	return conn;
}

// close the Database by closing the file, and free u the memory used for the database
// by deallocating the memory with free(pointer_to_memory_used)
void Database_close(struct Connection *conn)
{
	if(conn) {
		if(conn->file) fclose(conn->file);
		if(conn->db) free(conn->db);
		free(conn);
	}
}

void Database_write(struct Connection *conn)
{
	rewind(conn->file);
	
	int rc = fwrite(conn->db, sizeof(struct Database), 1, conn->file);
	if(rc != 1) die("Failed to write database.");

	rc = fflush(conn->file);
	if(rc == -1) die("Cannot flush database.");
}

void Database_create(struct Connection *conn)
{
	int i = 0;

	for(i = 0; i < MAX_ROWS; i++)	{
		// make a prototype to initialize it
		
		struct Address addr = {.id = i, .set = 0};
		// then jsut assign it
		// array of struct Address in the array of Database which contains Address arrays of the Array of Connection
		// which contains them all as one large multi dimensional array
		// conn = { 'Database': { 'Address': { 'id': 1, 'set': 2, 'name': 'wes', 'email': 'wesley7879@gmail.com' } } }
		conn->db->rows[i] = addr;
	}
}

void Database_set(struct Connection *conn, int id, const char *name, const char *email)
{
	struct Address *addr = &conn->db->rows[id];
	if(addr->set) die("Already set, delete it first");

	addr->set = 0;
	// WARNING: bug, read the "How to break it" and fix this

	char *res = strncpy(addr->name, name, MAX_DATA);
	res[MAX_DATA-1] = '\0';
	// demonstrate the strncpy bug
	if(!res) die("Name copy failed");

	res = strncpy(addr->email, email, MAX_DATA);
	if(!res) die("Email copy failed");
}

void Database_get(struct Connection *conn, int id)
{
	struct Address *addr = &conn->db->rows[id];

	if(addr->set)	{
		Address_print(addr);
	} else {
		die("ID is not set");
	}
}

void Database_delete(struct Connection *conn, int id)
{
	struct Address addr = {.id=id, .set=0};
	conn->db->rows[id] = addr;
}

void Database_list(struct Connection *conn)
{
	int i = 0;
	//pointer to database
	struct Database *db = conn->db;
	// iterate through the rows in database and
	// get at each iteration the Address array
	
	for(i = 0; i < MAX_ROWS; i++) {
		struct Address *cur = &db->rows[i];
		// at each address print it
		if(cur->set) {
			Address_print(cur);
		}
	}
}

int main(int argc, char *argv[])
{
	if(argc < 3) die("USAGE: ex17 <dbfile> <action> [action params]");
	
	char *filename = argv[1];
	char action = argv[2][0];
	struct Connection *conn = Database_open(filename, action);
	int id = 0;

	if(argc > 3) id = atoi(argv[3]);
	if(id >= MAX_ROWS) die("There's not that many records.");

	switch(action)	{
		case 'c':
			Database_create(conn);
			Database_write(conn);
			break;
		case 'g':
			if(argc != 4) die("Need an id to get");
	
			Database_get(conn, id);
			break;
	
		// ./ex17 file s id name email
		// this will add the above id name and email to the database
		case 's':
			if(argc != 6) die("Need id, name, email to set");

			Database_set(conn, id, argv[6], argv[7]);
			Database_write(conn);
			break;

		case 'd':
			if(argc != 4) die("Need id to delete");

			Database_delete(conn, id);
			Database_write(conn);
			break;

		case 'l':
			Database_list(conn);
			break;
		default:
			die("Invalid action, only: c=create, g=get, s=set, d=del, l=list");
	}

	Database_close(conn);

	return 0;
}
