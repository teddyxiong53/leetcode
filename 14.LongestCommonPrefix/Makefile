.PHONY : c cpp java py js clean


all:
	@echo "make c/cpp/java/py/js"
c:
	@echo "==============compile============="
	gcc -g Solution.c
	@echo "==============run============="
	./a.out

cpp:
	@echo "==============compile============="
	g++ -std=c++11 Solution.cpp
	@echo "==============run============="
	./a.out

java:
	@echo "==============compile============="
	javac Solution.java
	@echo "==============run============="
	java Solution

py:
	python Solution.py

js:
	node Solution.js

clean:
	rm -f a.out Solution.class Solution *.pyc
