files = main
filesInCoverageReport = TestingMain
filesToCompile = *.cpp
DemoMain = DemoMain.cpp
TestingMain = TestingMain.cpp
TestingMainFiles = $(filter-out ${DemoMain}, ${filesToCompile})
DemoMainFiles = $(filter-out ${TestingMain}, ${filesToCompile})

Test:
	make clean
	g++ -g -std=c++11 -w ${TestingMainFiles} -o main
	./main
	
Demo:
	make clean
	g++ -g -std=c++11 -w ${DemoMainFiles} -o main
	./main

gdb:
	make
	gdb ./main

valgrind:
	make
	valgrind --track-origins=yes --leak-check=full --keep-stacktraces=alloc-and-free --error-exitcode=1 --log-file=valgrind.txt ./main > output.txt

coverage:
	g++ -g --coverage -dumpbase '' ${TestingMainFiles} -o main
	./main > output.txt
	gcov -f -m -r -j ${filesInCoverageReport} > coverage.txt 
	gcovr --html-details output.html

clean:
	rm *.o *.gcov *.gcda *.gcno *.gz *.html *.css output.txt coverage.txt valgrind.txt -f ${files}
