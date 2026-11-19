#include "common.h"

/* localdecomp:start func_L39_005F0790 */
typedef struct { u8 pad[0x10]; u8 *base; s16 h14; s16 h16; s16 h18; s16 h1A; s16 h1C; s16 h1E; } E_005F0790;
typedef struct { s16 n; u16 flags; u8 pad[0xC]; E_005F0790 items[1]; } S_005F0790;
typedef struct { u8 p0[8]; s32 w8; } Cfg_005F0790;
__asm__(".extern D_L39_0024CAD0, 16");
__asm__(".extern D_L39_0024CAD0_b, 4");
extern u32 *D_L39_0024CAD0;
extern u32 *D_L39_0024CAD0_b;
extern Cfg_005F0790 D_001FC450;
extern u8 D_001A4290[];
extern void func_003CED08(void *, s32, u8 *);
extern void func_003CE780(void);
extern s32 func_003CE828(u8 *, u8 *, s32);
extern void func_003CE920(s32, u8 *, u8 *, u8 *);
extern void func_003A9440(s32, unsigned long);

void func_L39_005F0790(S_005F0790 *s) {
    s32 i;
    E_005F0790 *e;
    E_005F0790 *p;
    u8 *flag;
    if (s->n != 0) {
        e = s->items;
        func_003CED08(e, s->n, (u8 *)0x70003F00); /* scratchpad */
        func_003CE780();
        D_L39_0024CAD0[0] = 0x30000007;
        D_L39_0024CAD0[1] = (u32)D_001A4290;
        D_L39_0024CAD0[2] = 0;
        D_L39_0024CAD0[3] = 0x50000007;
        D_L39_0024CAD0_b = D_L39_0024CAD0 + 4;
        flag = (u8 *)0x70003F00; /* scratchpad */
        p = e;
        for (i = 0; i < s->n; i++, p++, flag++) {
            if (*flag == 0) {
                u8 *a = p->base + p->h1C;
                u8 *c = p->base + p->h18;
                u8 *b = p->base + p->h1A;
                if (func_003CE828(c, (u8 *)0x70000000, p->h14) == 0) {
                    func_003CE920(s->items[i].h16, a, b, (u8 *)0x70000000);
                }
            }
        }
        func_003A9440(0x47, 0x3180B);
        func_003A9440(0x4E, ((long)(D_001FC450.w8 >> 13) | 0x1000000) | (1L << 32));
    }
}
/* localdecomp:end func_L39_005F0790 */
