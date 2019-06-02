from sys import argv, exit

if len(argv) == 3:
	open("%s:%s" % (argv[1], argv[2]), "wb").write(open(argv[2], "rb").read())
else:
	printf("[*] Usage: %s <target file> <file to hide>", argv[0]);