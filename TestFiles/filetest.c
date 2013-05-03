#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <errno.h>

#define MAX_ROWS = 100
#define MAX_DATA = 512

void die(const char *message)
{
	if(errno) {
		perror(message);
	} else {
		printf("ERROR: %s\n", message);
	}
}


struct PhoneBook {
	int id;
	char name;
	char number;
};


struct Database {
	struct PhoneBook rows[MAX_ROWS];
};

struct Connection {
	FILE *file;
	struct Database *db;
};


struct Conn *Database_open(const char *filename, char mode)
{

	Connection *conn = malloc(sizeof(struct Connection));
	if(!conn) die("Bad connection");

	conn->db = malloc(sizeof(struct Database));

	if(!conn->db) die("Bad database memory.");

	if(mode == 'c')
	{
		conn->file = fopen(filename, "w");
	} else {
		conn->file = fopen(filename, "r+");
	}

	if(!conn->file) die("Failed to open file %s.", filename);

	return conn;
}


void Database_create(Connection *conn)
{

	int i = 0;
	for(i = 0; i < MAX_ROWS; i++)
	{
		struct PhoneBook *pb = {.id = i}

		conn->db->rows[i] = pb;
	}
}

void Database_close(Connection *conn)
{
	if(conn->file) fclose(conn->file);
	if(conn->db) free(conn->db);
	free(conn);
}

void Database_write(Connection *conn)
{
	rewind(conn->file);

	int rc = fwrite(conn->db, sizeof(struct Database), 1, conn->file);
	if(rc != 1) die("Wrong size.");

	rc = fflush(file);
}

void Database_enter(Connection *conn, int id, char name, char number)
{
		struct PhoneBook *pb = conn->db->rows[id];
	
		pb->id = id;
		//strncpy(pb->name, name, sizeof(char));
		//strncpy(pb->number, number, sizeof(char));
		pb->name = name;
		pb->number = number;
}


void Database_find(Connection *conn, int id)
{
	int i = 0;
	for(i=0; i<MAX_ROWS; i++)
	{
		if(i == id)
		{
			struct Phonebook *the_pb = conn->db->rows[i];
			printf("%d\n", the_pb->id);
			printf("%s\n", the_pb->name);
			printf("%s\n", the_pb->number);
		} else {
			return NULL;
		}
	}
}


int main(int argc, char *argv[])
{

	if(argc < 3) die("Not enough arguments.");

	char *filename = argv[1];
	char action = argv[2][0];
	struct Connection *conn = Database_open(filename, action);
	int id=0;

	if(argc > 3) id = atoi(argv[3]);
	if(id > MAX_ROWS) die("There aren't that many records.");

	switch(action) {
		
		case 'c':
			Database_create(conn);
			break;
		
		case 'e':
			if(argc != 6) die("Not enough arguments");

			Database_enter(conn, id, argv[5], argv[6]);
			Database_write(conn);
			break;

		case 'f':
			if(argc != 4) die("Need an action and id");

			Database_find(conn, id);
			break;
		
		default:
			die("Invalid action.");
	}

	Database_close(conn);

	return 0;
}




		


