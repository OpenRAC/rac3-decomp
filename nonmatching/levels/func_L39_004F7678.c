/* NTSC-U draft (Claude wave B): C of func_L39_004F7478, the NTSC-U twin of func_L39_004F7678, with NTSC-U names and addresses.
 * near miss: 15 words differ on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division" (the file's line: "@ee296 @eeas -O2 -G0") (NTSC-U twin "func_L39_004F7478").
 * Worker's note: 15 diff (func_L39_004F7478.near.c): the row is TWO functions: a 24-byte tail-call wrapper (addiu sp,-0x10; sd ra; ld ra; j func_L39_004F74F8; addiu sp; nop) that neither gcc 2.95.3 nor @ee29 compile to (both emit jal+jr) and the 44-byte string copy at ...
 */
#include "common.h"

/* The catalogue row is two functions: func_L39_004F7478 (24 B incl. the alignment nop) and the
 * 44-byte string copy at 0x4F7490. */
/* localdecomp:start func_L39_004F7478 */
extern char *func_L39_004F74F8(char *, const char *);

char *func_L39_004F7478(char *dst, const char *src) {
    return func_L39_004F74F8(dst, src);
}

char *func_L39_004F7490(char *dst, const unsigned char *src) {
    char *ret = dst;

    while ((*dst++ = *src++) != 0) {
    }
    return ret;
}
/* localdecomp:end func_L39_004F7478 */
