OBJDIR = out

objects = $(addprefix $(OBJDIR)/, \
    crtslf.o readslf.o rmslf.o \
    printhelp.o crtfile.o crttmpf.o \
    rmfile.o shwfctt.o chgdir.o \
    crtdir.o list.o main.o)

msh: $(objects)
	cc -o msh $(objects)
	 
$(OBJDIR)/main.o: main/main.c
	cc -c main/main.c -o $(OBJDIR)/main.o

$(OBJDIR)/crtslf.o: sl/crtslf.c sl/sl.h
	cc -c sl/crtslf.c -o $(OBJDIR)/crtslf.o

$(OBJDIR)/readslf.o: sl/readslf.c sl/sl.h
	cc -c sl/readslf.c -o $(OBJDIR)/readslf.o

$(OBJDIR)/rmslf.o: sl/rmslf.c sl/sl.h
	cc -c sl/rmslf.c -o $(OBJDIR)/rmslf.o

$(OBJDIR)/printhelp.o: help/printhelp.c help/help.h
	cc -c help/printhelp.c -o $(OBJDIR)/printhelp.o

$(OBJDIR)/crtfile.o: files/crtfile.c files/files.h
	cc -c files/crtfile.c -o $(OBJDIR)/crtfile.o

$(OBJDIR)/crttmpf.o: files/crttmpf.c files/files.h
	cc -c files/crttmpf.c -o $(OBJDIR)/crttmpf.o

$(OBJDIR)/rmfile.o: files/rmfile.c files/files.h
	cc -c files/rmfile.c -o $(OBJDIR)/rmfile.o

$(OBJDIR)/shwfctt.o: files/shwfctt.c files/files.h
	cc -c files/shwfctt.c -o $(OBJDIR)/shwfctt.o

$(OBJDIR)/chgdir.o: dirs/chgdir.c dirs/dirs.h
	cc -c dirs/chgdir.c -o $(OBJDIR)/chgdir.o

$(OBJDIR)/crtdir.o: dirs/crtdir.c dirs/dirs.h
	cc -c dirs/crtdir.c -o $(OBJDIR)/crtdir.o

$(OBJDIR)/list.o: dirs/list.c dirs/dirs.h
	cc -c dirs/list.c -o $(OBJDIR)/list.o

clean:
	rm msh $(objects)