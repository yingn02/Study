file = getdir #maxroot + "maps/Backgrounds/Mountains.jpg"
ob = openbitmap file
format "\nclassof: %    width:%   height:%   \nfilename:%\n"  \
	(classof ob)  ob.width  ob.height  ob.filename
