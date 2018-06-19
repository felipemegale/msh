msh: out/crtslf.o out/readslf.o out/rmslf.o out/printhelp.o out/crtfile.o out/crttmpf.o out/rmfile.o out/shwfctt.o out/chgdir.o out/crtdir.o out/list.o
	 cc -c -o msh out/crtslf.o out/readslf.o out/rmslf.o out/printhelp.o out/crtfile.o out/crttmpf.o out/rmfile.o out/shwfctt.o out/chgdir.o out/crtdir.o out/list.o

out/crtslf.o: sl/crtslf.c sl/sl.h
			  cc -c sl/crtslf.c

out/readslf.o: sl/readslf.c sl/sl.h
			  cc -c sl/readslf.c

out/rmslf.o: sl/rmslf.c sl/sl.h
			  cc -c sl/rmslf.c

out/printhelp.o: help/printhelp.c help/help.h
			  cc -c help/printhelp.c

out/crtfile.o: files/crtfile.c files/files.h
			  cc -c files/crtfile.c

out/crttmpf.o: files/crttmpf.c files/files.h
			  cc -c files/crttmpf.c

out/rmfile.o: files/rmfile.c files/files.h
			  cc -c files/rmfile.c

out/shwfctt.o: files/shwfctt.c files/files.h
			  cc -c files/shwfctt.c

out/chgdir.o: dirs/chgdir.c dirs/dirs.h
			  cc -c dirs/chgdir.c

out/crtdir.o: dirs/crtdir.c dirs/dirs.h
			  cc -c dirs/crtdir.c

out/list.o: dirs/list.c dirs/dirs.h
			 cc -c dirs/list.c

clean:
	rm out/*