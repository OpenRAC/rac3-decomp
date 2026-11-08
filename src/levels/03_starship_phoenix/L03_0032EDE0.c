#include "common.h"

/* localdecomp:start func_L03_0032EDE0 */
extern void func_L03_0032EE30(char *, int);

void func_L03_0032EDE0(char *a)
{
    int i;
    for (i = 0; i < 3; i++)
        func_L03_0032EE30(a, i);
}
/* localdecomp:end func_L03_0032EDE0 */

INCLUDE_ASM("asm/levels", func_L03_0032EE30);

/* localdecomp:start func_L03_0032EF78 */
extern u16 *D_L03_0021C620[];
extern u8 *D_L03_001DF99C;
__asm__(".extern D_L03_001DF99C, 16");
extern s32 D_L03_001DF9D8;
extern void func_L02_003A0200(u8 *);
void func_L03_0032EF78(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    u16 *p = D_L03_0021C620[*(s32 *)(s + 0xC0)];
    s32 k;
    u8 *e;
    while (1) {
        k = *(s32 *)(s + 0xC0);
        if ((k & 0xFF) == 0xFF) break;
        if (D_L03_001DF9D8 < k) break;
        if (p == 0) break;
        if (!((s16)p[-1] >= 0 || p == D_L03_0021C620[k])) break;
        e = D_L03_001DF99C + ((*p & 0x7FFF) << 8);
        if (e == 0) break;
        p++;
        func_L02_003A0200(e);
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
