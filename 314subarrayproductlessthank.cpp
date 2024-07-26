Line 13: Char 55:
=================================================================
==22==ERROR: AddressSanitizer: heap-buffer-overflow on address 0x502000000140 at pc 0x55abd381ee76 bp 0x7ffecbc362d0 sp 0x7ffecbc362c8
READ of size 4 at 0x502000000140 thread T0
    #0 0x55abd381ee75 in Solution::numSubarrayProductLessThanK(std::vector<int, std::allocator<int>>&, int) solution.cpp:13:55
    #1 0x55abd381e71d in __helper__ solution.cpp:13:28
    #2 0x55abd381e71d in main solution.cpp:13:40
    #3 0x7ff97e314d8f  (/lib/x86_64-linux-gnu/libc.so.6+0x29d8f) (BuildId: 490fef8403240c91833978d494d39e537409b92e)
    #4 0x7ff97e314e3f in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x29e3f) (BuildId: 490fef8403240c91833978d494d39e537409b92e)
    #5 0x55abd374d814 in _start (solution+0xb1814)
0x502000000140 is located 0 bytes after 16-byte region [0x502000000130,0x502000000140)
allocated by thread T0 here:
    #0 0x55abd381c0ad in operator new(unsigned long) /root/llvm-project/compiler-rt/lib/asan/asan_new_delete.cpp:95:3
    #1 0x55abd383caee in void std::vector<int, std::allocator<int>>::_M_realloc_insert<int>(__gnu_cxx::__normal_iterator<int*, std::vector<int, std::allocator<int>>>, int&&) (solution+0x1a0aee)
    #2 0x55abd383c995 in int& std::vector<int, std::allocator<int>>::emplace_back<int>(int&&) (solution+0x1a0995)
    #3 0x55abd383bd6a in std::vector<int, std::allocator<int>> _Deserializer_::deserialize<int>(rapidjson::GenericValue<rapidjson::UTF8<char>, rapidjson::MemoryPoolAllocator<rapidjson::CrtAllocator>>&, std::vector<int, std::allocator<int>>*) (solution+0x19fd6a)
    #4 0x55abd383b9a2 in std::vector<int, std::allocator<int>> _Deserializer_::deserialize<std::vector<int, std::allocator<int>>>(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>> const&) (solution+0x19f9a2)
    #5 0x55abd381e6e3 in main solution.cpp:13:37
    #6 0x7ff97e314d8f  (/lib/x86_64-linux-gnu/libc.so.6+0x29d8f) (BuildId: 490fef8403240c91833978d494d39e537409b92e)
SUMMARY: AddressSanitizer: heap-buffer-overflow solution.cpp:13:55 in Solution::numSubarrayProductLessThanK(std::vector<int, std::allocator<int>>&, int)
Shadow bytes around the buggy address:
  0x501ffffffe80: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x501fffffff00: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x501fffffff80: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x502000000000: fa fa fd fa fa fa fd fa fa fa fd fa fa fa fd fa
  0x502000000080: fa fa fd fd fa fa fd fa fa fa fd fa fa fa fd fa
=>0x502000000100: fa fa fd fa fa fa 00 00[fa]fa fa fa fa fa fa fa
  0x502000000180: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x502000000200: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x502000000280: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x502000000300: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x502000000380: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
Shadow byte legend (one shadow byte represents 8 application bytes):
  Addressable:           00
  Partially addressable: 01 02 03 04 05 06 07
  Heap left redzone:       fa
  Freed heap region:       fd
  Stack left redzone:      f1
  Stack mid redzone:       f2
  Stack right redzone:     f3
  Stack after return:      f5
  Stack use after scope:   f8
  Global redzone:          f9
  Global init order:       f6
  Poisoned by user:        f7
  Container overflow:      fc
  Array cookie:            ac
  Intra object redzone:    bb
  ASan internal:           fe
  Left alloca redzone:     ca
  Right alloca redzone:    cb
==22==ABORTING