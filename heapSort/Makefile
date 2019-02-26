heapSort: heapSort.o
	g++ -E heapSort.cpp -o heapSort.i
	g++ -S heapSort.i -o heapSort.s
	g++ -c heapSort.s -o heapSort.o
	g++ heapSort.o -o heapSort


clean:
	rm -f heapSort.o heapSort.S heapSort.i
