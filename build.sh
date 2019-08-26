mkdir ./build
cd ./build
cmake ..
make -j4
#doxygen ../doc/Doxyfile
cat names.txt | ./nickname 
#ltrace -e malloc -e free ./nickname 
#valgrind --tool=memcheck ./nickname
#valgrind --leak-check=full -v  ./nickname

