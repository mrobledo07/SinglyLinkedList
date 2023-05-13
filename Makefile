linked_list : src/main.c src/linked_list.c include/linked_list.h
	gcc -Wall src/main.c src/linked_list.c -o linked_list

clean: 
	rm linked_list
