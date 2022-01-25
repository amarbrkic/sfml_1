all: build run clean

build:
	@g++ hello.cpp -o hello
run:
	@echo Output:
	@echo
	@./hello
	@echo -------
	@git add .
	@git commit -m "."
	@git push
clean:
	@rm hello
