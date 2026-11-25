#include "common.h"

/* localdecomp:start func_L39_0059F5F8 */
extern s32 *D_00240290;
__asm__(".extern D_00240290, 16");
extern s32 D_L39_0024BD20[5];
__asm__(".extern D_L39_0024BD20, 32");
extern s32 *D_L39_0024BCF8;
__asm__(".extern D_L39_0024BCF8, 16");
extern s32 D_L39_0024BCFC;
__asm__(".extern D_L39_0024BCFC, 16");
extern s32 D_L39_0024BD00;
__asm__(".extern D_L39_0024BD00, 16");
extern s32 D_L39_0024BD04;
__asm__(".extern D_L39_0024BD04, 16");
extern s32 D_L39_0024BD08;
__asm__(".extern D_L39_0024BD08, 16");
extern char D_00242D60[];
extern char D_00242D70[];
extern s32 D_L39_0025F680[];
extern s32 *func_003932C0(s32, s32, char *, s32);
extern void func_0038CD28(s32 *, s32, s32);
extern void func_003990F0(s32, s32);
extern s32 func_L39_005F4188(s32, s32, s32, char *);
extern void func_L39_0059C088(s32, s32, s32);
extern void func_001264E0(s32);
extern void func_00392FD0(s32, s32);
extern void func_00393138(void);

void func_L39_0059F5F8(void)
{
    s32 *hdr = D_00240290;
    s32 *g;
    s32 i;
    s32 size;
    s32 *r;
    s32 addr;
    s32 n;

    i = 0;
    do {
        s32 j = i + 1;
        D_L39_0024BD20[i] = (hdr[9 + i * 2] + 0x3F) & 0xFFFFFFC0u;
        i = j;
    } while (i < 5);
    size = (hdr[7] + 0x3F) & 0xFFFFFFC0u;
    g = D_L39_0025F680;
    r = func_003932C0(size, 0, D_00242D60, 0x39E);
    func_0038CD28(r, hdr[6] + (s32)hdr, size);
    D_L39_0024BCF8 = r;
    D_L39_0024BCFC = (s32)r + r[1];
    addr = g[4] + 0x30000;
    D_L39_0024BD00 = (s32)r + r[2];
    D_L39_0024BD08 = (s32)r + r[3];
    D_L39_0024BD04 = (s32)r + r[4];
    if (r[0x54 / 4] != 0) {
        n = ((hdr[9] + 0x3F) & 0xFFFFFFC0u) >> 4;
        func_003990F0(0, addr);
        D_L39_0024BCF8[0x94 / 4] = func_L39_005F4188(hdr[8] + (s32)hdr, n, n, D_00242D70);
        func_L39_0059C088(0, addr, 1);
    }
    if (D_L39_0024BCF8[0x58 / 4] != 0) {
        s32 m = (s32)func_003932C0(D_L39_0024BCF8[0x58 / 4], 0, D_00242D60, 0x3CE);
        func_003990F0(1, m);
        func_001264E0(0);
        func_00392FD0(1, m);
    }
    func_00393138();
}
/* localdecomp:end func_L39_0059F5F8 */
