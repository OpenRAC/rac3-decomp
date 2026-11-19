#include "common.h"

/* localdecomp:start func_L39_005EB698 */
extern s32 func_L01_00517688(void);
extern s32 func_L01_00516558(s32, f32 *, f32 *);
extern s32 func_L01_00517448_005EB698(s32, s32 *, s32 *);
extern s32 func_003E7AC8(s32, s32);
extern s32 func_L01_00516470(s32, f32, f32);
extern void func_L01_00517538(s32, f32, f32);
extern s32 func_L01_00516C78_005EB698(s32, s32, s32);
extern void func_0038E150(s32);
extern s32 func_0038E548(f32, s32, s32);
typedef struct { s32 f0; s32 f4; s32 f8; } S_005EB698;
extern S_005EB698 D_L39_0049A498[];
extern s32 D_L39_002B6988[][3];
extern f32 D_L39_00245C38;
extern s32 D_001D85F8_sda[] __attribute__((section(".sdata")));
__asm__(".extern D_001D85F8_sda, 4");

void func_L39_005EB698(s32 p) {
    f32 w = 0.0f;
    f32 x = 0.0f;
    f32 y = 0.0f;
    f32 h = 0.0f;
    s32 al0, al1;
    s32 id = D_001D85F8_sda[p];
    s32 idx = func_L01_00517688();
    f32 a, b, c, d, e, m;
    f32 t;
    f32 u;
    f32 bw;
    a = 0.008f;
    b = 0.002404f;
    e = 0.001953f;
    m = 0.01f;
    c = 0.015624f;
    d = 0.038464f;
    if ((u32)(p - 2) < 2) {
        f32 r[4];
        r[0] = 0.0f; r[1] = 0.0f; r[2] = 0.0f; r[3] = 0.0f;
        func_L01_00516558(0x540012, &r[0], &r[1]);
        func_L01_00516558(0x540016, &r[2], &r[3]);
        al0 = 3;
        al1 = 3;
        func_0038E150(1);
        u = (f32)func_0038E548(1.0f, D_L39_002B6988[2][D_L39_0049A498[idx].f0], -1) / D_L39_00245C38;
        t = (f32)func_0038E548(1.0f, D_L39_002B6988[3][D_L39_0049A498[idx].f0], -1) / D_L39_00245C38;
        w = (t < u) ? u : t;
        id = 0x540012;
        d = 0.086544f;
        x = (r[0] + r[2]) * 0.5f;
        y = (r[1] + r[3]) * 0.5f - b;
        func_003E7AC8(0x540016, 0);
    } else {
        func_L01_00516558(id, &x, &y);
        func_L01_00517448_005EB698(id, &al0, &al1);
        func_0038E150(1);
        w = (f32)func_0038E548(1.0f, D_L39_002B6988[p][D_L39_0049A498[idx].f0], -1) / D_L39_00245C38;
    }
    h = d + m;
    y = y - b;
    bw = (c + a) + w;
    switch (al0) {
    case 1:
        x += (bw - a - c) * 0.5f;
        break;
    case 2:
        x -= (bw - a - c) * 0.5f;
        break;
    }
    switch (al1) {
    case 1:
        y += h * 0.5f;
        break;
    case 2:
        y -= h * 0.5f;
        break;
    }
    func_003E7AC8(id, 0);
    func_L01_00516470(id + 1, x, y);
    func_L01_00517538(id + 1, bw, h);
    func_L01_00516470(id + 2, x, y);
    func_L01_00517538(id + 2, bw - 0.008f, h - 0.01f);
    func_L01_00516470(id + 3, x + e * 4.0f, y + b * 4.0f);
    func_L01_00517538(id + 3, bw, h);
    func_L01_00516C78_005EB698(id + 1, 3, 3);
    func_L01_00516C78_005EB698(id + 2, 3, 3);
    func_L01_00516C78_005EB698(id + 3, 3, 3);
}
/* localdecomp:end func_L39_005EB698 */

/* localdecomp:start func_L39_005EBAF0 */
extern s32 func_L01_00517688(void);
extern s32 *func_003B9BD0(s32);
extern s32 func_003B9C58(s32 *);
extern void func_L39_005F3548(s32, s32, s32);
/* an alias: func_L39_005EBDA0 below declares func_L39_0061BF38 with its own return type */
extern u8 *func_L39_0061BF38_005EBAF0(s32 i);
typedef struct { u8 pad[0x74]; s32 t[4][4]; } S_005EBAF0_A;
typedef struct { s32 t[4][8]; } S_005EBAF0_B;
extern s32 D_L39_0024C890[] __attribute__((section(".sdata")));
extern S_005EBAF0_A D_001A5810;
extern S_005EBAF0_B D_001A5990;

void func_L39_005EBAF0(s32 buttons) {
    s32 i = 0;
    s32 idx = 0;
    switch (func_L01_00517688()) {
    case 0: i = 0; break;
    case 1: i = 1; break;
    case 2: i = 2; break;
    case 3: i = 3; break;
    default: break;
    }
    idx = func_L01_00517688();
    if (func_003B9C58(func_003B9BD0(i)) == 3) {
        if (buttons & 0x8000) {
            s32 v = D_001A5810.t[D_L39_0024C890[idx]][idx] - 2;
            if (v < 0) v = 0;
            D_001A5810.t[D_L39_0024C890[idx]][idx] = v;
            func_L39_005F3548(3, 0, 0);
        } else if (buttons & 0x2000) {
            s32 v = D_001A5810.t[D_L39_0024C890[idx]][idx] + 2;
            D_001A5810.t[D_L39_0024C890[idx]][idx] = (v > 100) ? 100 : v;
            func_L39_005F3548(3, 0, 0);
        }
        D_001A5990.t[D_L39_0024C890[idx]][*(s32 *)(func_L39_0061BF38_005EBAF0(idx) + 0x2544)] = D_001A5810.t[D_L39_0024C890[idx]][idx];
    }
}
/* localdecomp:end func_L39_005EBAF0 */

/* localdecomp:start func_L39_005EBCB8 */
extern s32 D_L39_0024C890[] __attribute__((section(".sdata")));
__asm__(".extern D_L39_00243CA4, 4");
__asm__(".extern D_L39_00243CA8, 4");
__asm__(".extern D_L39_00243CAC, 4");
extern f32 D_L39_00243CA4;
extern f32 D_L39_00243CA8;
extern f32 D_L39_00243CAC;
extern s32 func_L01_00517688(void);
extern s32 func_L01_00516558(s32, f32 *, f32 *);
extern s32 func_L01_00516470(s32, f32, f32);

void func_L39_005EBCB8(void) {
    f32 v[2];
    s32 i;
    f32 q;
    f32 s;
    f32 k1;
    f32 k2;
    f32 z;
    i = func_L01_00517688();
    k1 = 0.012f;
    k2 = 0.007f;
    z = 0.0f;
    v[0] = z;
    v[1] = z;
    q = (f32)D_001A5810.t[D_L39_0024C890[i]][i] / 100.0f;
    func_L01_00516558(0x54003D, &v[0], &v[1]);
    s = D_L39_00243CA4 + D_L39_00243CAC;
    v[0] = s + k2 + (D_L39_00243CA8 - s - k1) * q;
    func_L01_00516470(0x54003D, v[0], v[1]);
}
/* localdecomp:end func_L39_005EBCB8 */
