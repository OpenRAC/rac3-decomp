#include "common.h"

/* localdecomp:start func_L01_00403168 */
typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
    f32 f10;
    f32 f14;
    f32 f18;
    f32 f1C;
    s32 w20;
    f32 f24;
} S_00403168;

typedef struct {
    u8 pad0[0xB0];
    f32 fB0;
    u8 padB4[0x1A0 - 0xB4];
    f32 f1A0;
    f32 f1A4;
    u8 pad1A8[0x210 - 0x1A8];
    f32 f210;
    f32 f214;
    f32 f218;
    f32 f21C;
    u8 pad220[0x240 - 0x220];
    s32 w240;
    s32 w244;
    s32 w248;
    s32 w24C;
    u8 pad250[0x268 - 0x250];
    s32 w268;
} C_00403168;

extern s16 D_L01_001CFEC0[];
extern S_00403168 D_L01_002C5070[];
extern C_00403168 D_L01_001E7580;
typedef struct {
    s32 w;
    s32 h;
    s32 cx;
    s32 cy;
    s32 x0;
    s32 y0;
    s32 x1;
    s32 y1;
} V_00403168;
extern V_00403168 D_L01_001D4BC0 __attribute__((section(".sdata")));
extern s32 D_L01_001D52F0;
__asm__(".extern D_L01_001D52F0, 16");
extern s32 D_L01_001D7B88[] __attribute__((section(".sdata")));
extern s32 D_L01_001D7B80;

extern void func_L01_005195E0_00403168(f32, f32);
extern void func_003A9500(s32, s32, s32, s32);
extern void func_003873C0(void);
extern void func_L01_004B14C8(s32);

void func_L01_00403168(s32 idx) {
    S_00403168 *p = &D_L01_002C5070[idx];
    s32 w, h;
    s32 l, r, t, b;
    s16 sw, sh;
    f32 fw, fh;

    w = (s32)((f32)D_L01_001CFEC0[0xA8] * p->f10);
    h = (s32)((f32)D_L01_001CFEC0[0xA9] * p->f14);
    D_L01_001D4BC0.w = w;
    D_L01_001D4BC0.h = h;
    func_L01_005195E0_00403168((f32)w, (f32)h);

    sw = D_L01_001CFEC0[0xA8];
    sh = D_L01_001CFEC0[0xA9];
    D_L01_001D4BC0.cx = (s32)(sw * (p->f18 + 0.5f));
    D_L01_001D4BC0.cy = (s32)(sh * (p->f1C + 0.5f));
    D_L01_001D4BC0.x0 = (D_L01_001D4BC0.cx + (0x800 - (sw >> 1)) - (D_L01_001D4BC0.w >> 1)) * 16;
    D_L01_001D4BC0.y0 = (D_L01_001D4BC0.cy + (0x800 - (sh >> 1)) - (D_L01_001D4BC0.h >> 1)) * 16;
    D_L01_001D4BC0.x1 = D_L01_001D4BC0.x0 + D_L01_001D4BC0.w * 16;
    D_L01_001D4BC0.y1 = D_L01_001D4BC0.y0 + D_L01_001D4BC0.h * 16;
    l = (s32)(sw * p->f0);
    r = (s32)(sw * p->f4) - 1;
    t = (s32)(sh * p->f8);
    b = (s32)(sh * p->fC) - 1;
    D_L01_001E7580.w240 = l;
    D_L01_001E7580.w244 = r;
    D_L01_001E7580.w248 = t;
    D_L01_001E7580.w24C = b;
    func_003A9500(l, r, t, b);

    D_L01_001E7580.w268 = p->w20;
    D_L01_001E7580.fB0 = D_L01_001E7580.fB0 * p->f24;
    fw = D_L01_001CFEC0[0xA8];
    fh = D_L01_001CFEC0[0xA9];
    D_L01_001E7580.f210 = fw * (p->f10 * 0.5f);
    D_L01_001E7580.f214 = fh * (p->f14 * 0.5f);
    D_L01_001E7580.f218 = D_L01_001E7580.f210 * 4.0f;
    D_L01_001E7580.f21C = D_L01_001E7580.f214 * 4.0f;
    D_L01_001E7580.f1A0 = fw * p->f18 + 2048.0f;
    D_L01_001E7580.f1A4 = fh * p->f1C + 2048.0f;
    func_003873C0();
    D_L01_001D7B80 = D_L01_001D7B88[D_L01_001D52F0];
    func_L01_004B14C8(0);
}
/* localdecomp:end func_L01_00403168 */
