#include "common.h"

/* localdecomp:start func_L03_0032EDE0 */
void func_L03_0032EE30(void *a, int b);
void func_L03_0032EDE0(void *a) {
    int i;
    for (i = 0; i < 3; i++) {
        func_L03_0032EE30(a, i);
    }
}
/* localdecomp:end func_L03_0032EDE0 */

INCLUDE_ASM("asm/levels", func_L03_0032EE30);

/* localdecomp:start func_L03_0032EF78 */
typedef struct { char pad[0xC0]; int idx; } S_0032EF78;
extern short *D_L03_0021C620[];
extern char *D_L03_001DF99C;
__asm__(".extern D_L03_001DF99C, 16");
extern int D_001DF9D8_sda;
__asm__(".extern D_001DF9D8_sda, 4");
void func_L02_003A0200(void *a);
void func_L03_0032EF78(void *a) {
    S_0032EF78 *s = *(S_0032EF78 **)((char *)a + 0x68);
    short *p = D_L03_0021C620[s->idx];
    while (1) {
        int k = s->idx;
        char *q;
        if ((k & 0xFF) == 0xFF) break;
        if (D_001DF9D8_sda < k) break;
        if (p == 0) break;
        if (p[-1] < 0 && p != D_L03_0021C620[k]) break;
        q = D_L03_001DF99C + ((*(unsigned short *)p & 0x7FFF) << 8);
        if (q == 0) break;
        p += 1;
        func_L02_003A0200(q);
    }
}
/* localdecomp:end func_L03_0032EF78 */

INCLUDE_ASM("asm/levels", func_L03_0032F038);

/* localdecomp:start func_L03_0032F520 */
typedef struct { char pad[0x84]; unsigned short v; char pad2[0xF0-0x86]; } S_0032F520;
extern unsigned char D_001426E0[];
extern unsigned char D_00142CA0[];
extern unsigned char D_00142D40[];
extern unsigned char D_001425C0[];
extern int D_001427F0[];
extern S_0032F520 D_L03_002C49C0[1];
void func_0039EF28(void);
void func_L03_0040F9E8(int a);
void func_L03_004F54E0(int a);
void func_L03_0035AD98(void);
void func_L01_0044CD60(int a);
void func_L01_00419248(int a);
void func_L03_0032F520(void) {
    int i = D_001426E0[0xD6];
    if (i != 0) {
        D_00142CA0[i] = 0;
        D_00142D40[i] = 0;
        func_0039EF28();
        func_L03_0040F9E8(i);
        func_L03_004F54E0(i);
        if (((S_0032F520 *)D_L03_002C49C0)[D_001425C0[i]].v != 0) {
            D_001427F0[i] = 0;
        } else if (i == 0x87) {
            func_L03_0035AD98();
        }
        func_L01_0044CD60(9);
        func_L01_00419248(i);
    }
    D_001426E0[0xD6] = 0;
}
/* localdecomp:end func_L03_0032F520 */
