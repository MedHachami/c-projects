run: compile
	@./main

compile: main
	@gcc  -o   main *.o -lsqlite3 

main: library
	@gcc -c -g  main.c main.h 

library:
	@gcc -c -g   initDB/*.c initDB/*.h task/*.c task/*.h task/showTasks/*.c task/showTasks/*.h task/stats/*.c task/stats/*.h task/findTask/*.c task/findTask/*.h  collaborator/*.c collaborator/*.h collaborator.h task.h

clean:
	@rm main .*.swp .*/*.swp *.h.gch */*h.gch *.o .*.c.swp .*/*.c.swp

push: commit
	git push

commit: add
	git commit -m "$(M)"

add: pull
	git add .

pull: fetch
	git pull

fetch:
	git fetch