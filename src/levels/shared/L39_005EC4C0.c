#include "common.h"

/* localdecomp:start func_L39_005EC4C0 */
typedef struct { u32 w[4]; } Q_005EC4C0;
__asm__(".extern D_L39_0024CAD0_005EC4C0, 4");
__asm__(".extern D_L39_0024C8E0, 4");
__asm__(".extern D_001D8678_sda, 4");
extern u32 *D_L39_0024CAD0;
extern u8 D_001A4060[];
extern u8 D_L39_0049A620[];
typedef struct { u8 pad[0x150]; s16 w; s16 h; } S_005EC4C0;
extern S_005EC4C0 D_L39_00228580;
extern f32 D_L39_0024C8D4;
extern f32 D_L39_0024C8D0;
extern u8 D_L39_002412F7;
extern Q_005EC4C0 *D_L39_0024CAD0_005EC4C0;
extern s32 D_L39_0024C8E0;
extern s32 D_001D8678_sda;
extern s32 D_L39_00243D80[] __attribute__((section(".sdata")));
extern s32 D_L39_001FC450[];
extern void func_003D1030(void);
extern void func_003D0EC8(void *, f32);
extern void *func_003D0FD8(void *);
extern void func_003D1E28(f32 *, f32 *);
extern s32 func_003D20B0(s32, s32);
extern void func_003D1EC0(s32, s32);
extern void func_003D2520(s32, s32);
extern void func_003D2380(s32, s32);
extern void func_003D27C0(s32);
extern void func_003D11E0(s32);
extern void func_003A9440(s32, unsigned long);
typedef struct { s32 count; s32 f4; f32 f8; f32 fC; f32 f10; f32 f14; f32 f18; f32 f1C; u8 f20[0x10]; } E_005EC4C0;

void func_L39_005EC4C0(E_005EC4C0 *q) {
    E_005EC4C0 *p;
    s32 i;
    s32 r;
    s32 a, b;
    Q_005EC4C0 *base;
    f32 v[8];
    s32 n;
    func_003D1030();
    p = q;
    D_L39_0024CAD0[0] = 0x30000007;
    D_L39_0024CAD0[1] = (u32)D_001A4060;
    D_L39_0024CAD0[2] = 0x13000000;
    D_L39_0024CAD0[3] = 0x50000007;
    D_L39_0024CAD0 += 4;
    D_L39_0024CAD0[0] = 0x30000003;
    D_L39_0024CAD0[1] = (u32)D_L39_0049A620;
    D_L39_0024CAD0[2] = 0x13000000;
    D_L39_0024CAD0[3] = 0x50000003;
    D_L39_0024C8D0 = (f32)((D_L39_00228580.w >> 1) - 0x800);
    D_L39_0024C8D4 = (f32)((D_L39_00228580.h >> 1) - 0x800);
    base = (Q_005EC4C0 *)(D_L39_0024CAD0 + 4);
    D_L39_0024CAD0_005EC4C0 = (Q_005EC4C0 *)(D_L39_0024CAD0 + 8);
    if (D_L39_002412F7) { b = 1; a = 2; } else { b = 2; a = 1; }
    while (p->count != 0) {
        q++;
        func_003D0EC8(p->f20, 1000.0f);
        v[4] = v[0] = p->f10;
        v[5] = v[1] = p->f14;
        v[6] = v[2] = p->f18;
        v[3] = -p->f8 - p->fC;
        v[7] = -p->f8 + p->fC;
        for (i = 0; i < p->count; i++) {
            q = func_003D0FD8(q);
            func_003D1E28(v, v + 4);
            if (p->f4) r = func_003D20B0(0x70000000, D_L39_0024C8E0);
            else { func_003D1EC0(0x70000000, D_L39_0024C8E0); r = 0; }
            if (r) {
                func_003D2520(a, D_L39_00243D80[3]);
                func_003D2520(b, D_001D8678_sda);
                if (r & 0x20) func_003D27C0(D_001D8678_sda);
            } else {
                func_003D2380(a, D_L39_00243D80[3]);
                func_003D2380(b, D_001D8678_sda);
            }
        }
        p = q;
    }
    n = D_L39_0024CAD0_005EC4C0 - base - 1;
    if (n > 0) {
        base->w[0] = n | 0x10000000;
        base->w[1] = 0;
        base->w[2] = 0;
        base->w[3] = n | 0x50000000;
    } else {
        D_L39_0024CAD0 = (u32 *)(D_L39_0024CAD0_005EC4C0 - 1);
    }
    func_003A9440(0x4C, 0x80000 | (D_L39_001FC450[1] >> 13));
    func_003A9440(0x42, 0x2000000064UL);
    func_003D11E0(0);
    func_003A9440(0x47, 0x5360B);
    func_003A9440(0x42, 0x8000000044UL);
}
/* localdecomp:end func_L39_005EC4C0 */
