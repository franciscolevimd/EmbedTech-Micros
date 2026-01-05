#---Run unit testing with code coverage using ceedling---------------------------------------------
test : build
	ceedling clobber
	ceedling gcov:all
