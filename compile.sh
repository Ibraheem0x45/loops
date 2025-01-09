clang optimized_version.c -o optimized_version.o -O3 -lm
clang optimized_version.c -o optimized_version_avx.o -O3 -mavx2 -lm
clang original_version.c -o original_version.o -O3
clang caseys_version.c -o caseys_version.o -O3 -lm
clang caseys_version.c -o caseys_version_avx.o -O3 -mavx2 -lm
