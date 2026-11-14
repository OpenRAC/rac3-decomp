#include "common.h"

/* localdecomp:start func_L39_00597FF8 */
typedef struct {
    u8 pad0[0x160];
    s16 w;
    s16 h;
    s16 psm;
    s16 fbp;
    u8 pad168[4];
    s16 zpsm;
    s16 zbp;
} Cfg_00597FF8;

typedef struct {
    unsigned long FBP : 9;
    unsigned long pad09 : 7;
    unsigned long FBW : 6;
    unsigned long pad22 : 2;
    unsigned long PSM : 6;
    unsigned long pad30 : 2;
    unsigned long FBMSK : 32;
} GsFrame_00597FF8;

__asm__(".extern D_L39_0024CAD0, 16");
extern u32 *D_L39_0024CAD0;
extern u32 *D_L39_0024CAD0_b;
__asm__(".extern D_L39_0024CAD0_b, 4");
extern unsigned long D_001D4C70_sda;
extern Cfg_00597FF8 D_00228580;
extern void func_0038CBA0(void *, s32);
extern void func_00139B38(void *, s32, s32, s32, s32, s32);

void func_L39_00597FF8(s32 a, s32 b, s32 c, s32 flag) {
    s32 x;
    unsigned long *d;
    unsigned long *r;
    unsigned long z;

    x = a - 6;
    if (x <= 0) {
        x = 1;
    }
    D_00228580.fbp = c >> 13;
    D_00228580.w = 1 << a;
    D_00228580.h = 1 << b;
    D_001D4C70_sda = (unsigned long)(c >> 8) | ((unsigned long)(1 << x) << 14) | ((unsigned long)a << 26) | ((unsigned long)b << 30) | ((unsigned long)1 << 34);
    func_0038CBA0(D_L39_0024CAD0, 0xF0);
    D_L39_0024CAD0[0] = 0x1000000E;
    D_L39_0024CAD0[1] = 0;
    D_L39_0024CAD0[2] = 0;
    D_L39_0024CAD0[3] = 0x5000000E;
    D_L39_0024CAD0 += 4;
    r = (unsigned long *)D_L39_0024CAD0;
    r[0] = 0x1000000000000008L;
    r[1] = 0xE;
    D_L39_0024CAD0_b = D_L39_0024CAD0 + 4;
    d = (unsigned long *)D_L39_0024CAD0_b;
    func_00139B38(d, D_00228580.psm, D_00228580.w, D_00228580.h, 3, 0);
    ((GsFrame_00597FF8 *)d)->FBP = D_00228580.fbp;
    if (flag == 0) {
        d[2] = (unsigned long)D_00228580.zbp | ((unsigned long)(D_00228580.zpsm & 0xF) << 24);
    } else {
        s32 t = a + b;
        if (t > 16) {
            t = 16;
        }
        d[2] = (unsigned long)((c - (4 << t)) >> 13) | ((unsigned long)(D_00228580.zpsm & 0xF) << 24);
    }
    D_L39_0024CAD0 += 0x20;
    r = (unsigned long *)D_L39_0024CAD0;
    r[0] = 0x1000000000000001L;
    r[1] = 0xE;
    r[2] = 0x30003;
    r[3] = 0x47;
    r[4] = 0x4400000000008001L;
    r[5] = 0x4410;
    r[6] = 0x106;
    r[7] = 0;
    r[8] = (unsigned long)(0x8000 - D_00228580.w * 8) | ((unsigned long)(0x8000 - D_00228580.h * 8) << 16);
    r[9] = (unsigned long)(D_00228580.w * 8 + 0x8000) | ((unsigned long)(D_00228580.h * 8 + 0x7FF0) << 16);
    D_L39_0024CAD0 += 0x14;
}
/* localdecomp:end func_L39_00597FF8 */
