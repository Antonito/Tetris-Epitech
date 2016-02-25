==16424== Memcheck, a memory error detector
==16424== Copyright (C) 2002-2015, and GNU GPL'd, by Julian Seward et al.
==16424== Using Valgrind-3.11.0 and LibVEX; rerun with -h for copyright info
==16424== Command: ./tetris
==16424== Parent PID: 2632
==16424== 
==16424== Invalid read of size 8
==16424==    at 0x400B7D: display_tetriminos (board.c:32)
==16424==    by 0x400C3F: display_board (board.c:42)
==16424==    by 0x400FD0: display (display.c:23)
==16424==    by 0x40093E: main (main.c:21)
==16424==  Address 0x0 is not stack'd, malloc'd or (recently) free'd
==16424== 
==16424== 
==16424== Process terminating with default action of signal 11 (SIGSEGV)
==16424==  Access not within mapped region at address 0x0
==16424==    at 0x400B7D: display_tetriminos (board.c:32)
==16424==    by 0x400C3F: display_board (board.c:42)
==16424==    by 0x400FD0: display (display.c:23)
==16424==    by 0x40093E: main (main.c:21)
==16424==  If you believe this happened as a result of a stack
==16424==  overflow in your program's main thread (unlikely but
==16424==  possible), you can try to increase the size of the
==16424==  main thread stack using the --main-stacksize= flag.
==16424==  The main thread stack size used in this run was 8388608.
==16424== 
==16424== HEAP SUMMARY:
==16424==     in use at exit: 486,568 bytes in 190 blocks
==16424==   total heap usage: 198 allocs, 8 frees, 495,243 bytes allocated
==16424== 
==16424== LEAK SUMMARY:
==16424==    definitely lost: 192 bytes in 2 blocks
==16424==    indirectly lost: 226 bytes in 22 blocks
==16424==      possibly lost: 0 bytes in 0 blocks
==16424==    still reachable: 486,150 bytes in 166 blocks
==16424==         suppressed: 0 bytes in 0 blocks
==16424== Rerun with --leak-check=full to see details of leaked memory
==16424== 
==16424== For counts of detected and suppressed errors, rerun with: -v
==16424== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
