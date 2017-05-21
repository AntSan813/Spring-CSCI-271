sorts: main.o insertionSort.o mergeSort.o selectionSort.o quickSort.o
	c++ -o p4 main.o
	c++ -o is insertionSort.o
	c++ -o ms mergeSort.o
	c++ -o ss selectionSort.o
	c++ -o qs quickSort.o
main.o: main.cpp
	c++ -c main.cpp
insertionSort.o: insertionSort.cpp
	c++ -c insertionSort.cpp
mergeSort.o: mergeSort.cpp
	c++ -c mergeSort.cpp
selectionSort.o: selectionSort.cpp
	c++ -c selectionSort.cpp
quickSort.o: quickSort.cpp
	c++ -c quickSort.cpp
clean: 
	rm main.o insertionSort.o mergeSort.o selectionSort.o quickSort.o sorted.dat p4 is ms ss qs
