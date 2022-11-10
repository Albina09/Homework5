.PHONY := clean
bin := Project
sources := Project.c
headers := Project.h

$(bin): $(sources) $(headers) 
	gcc $(sources) -o $(bin) -g

clean:
	rm -rf $(bin)

