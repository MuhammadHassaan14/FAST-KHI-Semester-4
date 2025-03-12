CC = gcc
CFLAGS = -Wall
OBJ = main.o add_student.o display_students.o search_student.o

flex: $(OBJ)
	$(CC) $(CFLAGS) -o flex $(OBJ)

main.o: main.c student.h
	$(CC) $(CFLAGS) -c main.c

add_student.o: add_student.c student.h
	$(CC) $(CFLAGS) -c add_student.c

display_students.o: display_students.c student.h
	$(CC) $(CFLAGS) -c display_students.c

search_student.o: search_student.c student.h
	$(CC) $(CFLAGS) -c search_student.c

clean:
	rm -f flex $(OBJ)

