#include "common.h"

/* NTSC-U counterpart of func_003B63D0 (src/boot_elf/text/3B3B08.c): one more row (D_001D5520), the rows and the table 0x20 further on */
/* localdecomp:start func_U_003B6220 */
typedef struct { s32 a, b, c, d; } E_U_003B6220;
extern E_U_003B6220 D_U_0037F8B0[];
extern s32 func_U_003B6788(void);
extern s32 func_U_003BA110(void *, s32, s32);
extern s32 func_U_003E7EE8(s32, s32);
extern s32 *func_U_003B9EB0(s32);
extern s32 func_U_003823F0();
extern void func_0011B2E8();
extern u8 D_U_0037F810[];
extern char D_U_001D8A40[];
extern char D_U_001D8A38[];
extern s32 D_00143950[];
__asm__(".extern D_001D5520, 16");
extern s32 D_001D5520;

void func_U_003B6220(void) {
    s32 i = 0;
    u8 *base = D_U_0037F810;
    u8 *b = (u8 *)D_00143950;
    char *fmt = D_U_001D8A38;
    s32 yes = 0x175;
    s32 no;
    u8 *p1 = base + 0x20;
    u8 *p2 = base + 0x40;
    u8 *p3 = base + 0x60;
    E_U_003B6220 *e;
    u8 *p;
    void *text;
    func_0011B2E8(base, fmt, func_U_003823F0(b[0xAD] == 0 ? 0x176 : yes));
    no = 0x176;
    ((s32 (*)())func_0011B2E8)(p1, fmt, func_U_003823F0(D_001D5520 ? yes : no));
    func_0011B2E8(p2, fmt, func_U_003823F0(b[6] ? yes : no));
    func_0011B2E8(p3, fmt, func_U_003823F0(*(s32 *)(b + 8) ? 0x237 : 0x236));
    ((s32 (*)())func_0011B2E8)(base + 0x80, fmt, func_U_003823F0(func_U_003B6788()));
    e = D_U_0037F8B0;
    if (e->a) {
      p = base;
      do {
        text = (void *)func_U_003BA110(func_U_003B9EB0(0), 0, i);
        func_0011B2E8(text, D_U_001D8A40, func_U_003823F0(e->a));
        e++;
        text = (void *)func_U_003BA110(func_U_003B9EB0(0), 1, i);
        i++;
        ((s32 (*)())func_0011B2E8)(text, D_U_001D8A38, p);
        p += 0x20;
      } while (e->a);
    }
    func_U_003E7EE8(0x1C0004, func_U_003823F0(0x1EBD));
}
/* localdecomp:end func_U_003B6220 */
