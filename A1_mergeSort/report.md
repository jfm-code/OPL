# Ada
3 files are needed to a program to run:
- mergesort.ads => like a header file
- mergesort.adb => the main logic is here
- mergesort_test.adb => use to build the program, execute this with gnatmake mergesort_test.adb.
when build successfully, print out the output by typing ./mergesort_test

when build successfully, the following files will appear:
- mergesort_test
- mergesort_test.ali
- mergesort_test.o
- mergesort.ali
- mergesort.o

difficulty i ran into:
- when i tried to build, i got this error: mergesort.adb:14:30: there is no applicable operator "<=" for private type "Element_Type" defined at mergesort.ads:2
-> this is because i didnt define a generic operator in mergesort.ads to use in mergesort.adb
-> i then define by adding this line
```with function "<="(Left, Right : Element_Type) return Boolean is <>;```
-> i can also fix this bug by simply use < and not using <= but that would make my logical script tedious