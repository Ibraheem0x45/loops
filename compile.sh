clang c/optimized_version.c -o c/optimized_version.o -O3 -lm
clang c/optimized_version.c -o c/optimized_version_avx.o -O3 -mavx2 -lm
clang c/original_version.c -o c/original_version.o -O3 -mavx2
clang c/caseys_version.c -o c/caseys_version.o -O3 -lm
clang c/caseys_version.c -o c/caseys_version_avx.o -O3 -mavx2 -lm
javac -g:none jvm/original_version.java
javac -g:none jvm/optimized_version.java
