#!/usr/bin/env python
import os


name_of_db = raw_input('Name of file: ')


def create_database():
	global name_of_db
	data_structure = {}
	f = open("%s.py" % name_of_db, "w")
	f.write('library = %s' % data_structure)
	f.close()
	


def add_user():
	global name_of_db
	from name_of_db import library
	id = raw_input('Id: ')
	name = raw_input('Name: ')
	email = raw_input('Email: ')
	current_user = {id: (name, email)}
	library.update(current_user)
	os.remove('%s.py' % name_of_db)
	f = open('%s.py' % name_of_db, 'w')
	f.write('library = %s' % library)
	f.close()
	
	


def get_user():
	global name_of_db
	from name_of_db import library
	id = raw_input('User id: ')
	print id, library[id]


def delete_user(id):
	pass



def delete_database():
	pass


def main():
	operation = raw_input('<c = create database, a = add user, g = get-user, d = delete user>: ')
	if operation.lower() == 'c':
		create_database()

	elif operation.lower() == 'a':
		add_user()

	elif operation.lower() == 'g':
		get_user()

	elif operation.lower() == 'd':
		delete_user()
	
	elif operation.lower() == 'dd':
		delete_database()


if __name__ == '__main__':
	main()
