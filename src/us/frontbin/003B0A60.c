#include "common.h"

/* NTSC-U counterpart of func_003B6018 (src/frontbin/3B5D70.c): one more line, D_001D5520 yes/no, and the fifth line at base + 0x80 */
/* localdecomp:start func_U_003B0A60 */
typedef struct { s32 a, b, c, d; } E_003B0A60;
extern u8 D_U_0037B7D0[];
extern s32 D_00143950_003B0A60[];
extern char D_U_001D8A38[];
extern char D_U_001D8A40[];
extern s32 D_001D5520_003B0A60;
__asm__(".extern D_001D5520_003B0A60, 16");
extern E_003B0A60 D_U_0037B870[];
extern s32 func_U_0037DF98();
extern void func_0011B2E8();
extern s32 *func_U_003B46F0(s32);
extern s32 func_U_003B0FC8(void);
extern s32 func_U_003B4950(void *, s32, s32);
extern s32 func_U_003E2728(s32, s32);

void func_U_003B0A60(void) {
    s32 i = 0;
    u8 *base = D_U_0037B7D0;
    u8 *b = (u8 *)D_00143950_003B0A60;
    char *fmt = D_U_001D8A38;
    s32 yes = 0x175;
    s32 no;
    u8 *p1 = base + 0x20;
    u8 *p2 = base + 0x40;
    u8 *p3 = base + 0x60;
    E_003B0A60 *e;
    u8 *p;
    void *text;
    func_0011B2E8(base, fmt, func_U_0037DF98(b[0xAD] == 0 ? 0x176 : yes));
    no = 0x176;
    ((s32 (*)())func_0011B2E8)(p1, fmt, func_U_0037DF98(D_001D5520_003B0A60 ? yes : no));
    func_0011B2E8(p2, fmt, func_U_0037DF98(b[6] ? yes : no));
    func_0011B2E8(p3, fmt, func_U_0037DF98(*(s32 *)(b + 8) ? 0x237 : 0x236));
    ((s32 (*)())func_0011B2E8)(D_U_0037B7D0 + 0x80, fmt, func_U_0037DF98(func_U_003B0FC8()));
    e = D_U_0037B870;
    if (e->a) {
      p = base;
      do {
        text = (void *)func_U_003B4950(func_U_003B46F0(0), 0, i);
        func_0011B2E8(text, D_U_001D8A40, func_U_0037DF98(e->a));
        e++;
        text = (void *)func_U_003B4950(func_U_003B46F0(0), 1, i);
        i++;
        ((s32 (*)())func_0011B2E8)(text, D_U_001D8A38, p);
        p += 0x20;
      } while (e->a);
    }
    func_U_003E2728(0x1C0004, func_U_0037DF98(0x1EBD));
}
/* localdecomp:end func_U_003B0A60 */
