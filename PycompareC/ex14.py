#!usr/bin/env python

def print_arguments(arg):
	for i in arg:
		print "%s: %s\n" % (i, ord(i))



def main():
	arg = raw_input("Program arguments: ")
	print print_arguments(arg)


if __name__ == '__main__':
	main()	
