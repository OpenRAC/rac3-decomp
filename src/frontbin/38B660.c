#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void func_0038DAB8(f32, f32);
typedef int u128_t __attribute__((mode(TI)));
extern u128_t D_00222400[];
extern long func_00389598(s32);
extern void func_0038BCD8(f32, f32, f32, f32, f32, s32, s32, long, s32, s32, s32, s32, f32, f32);
extern void func_0038C500(s32, s32, s32, s32, s32 *, s32 *, s32, s32, f32, f32);
extern void func_0038D640();
extern void func_0038C9B0(void);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_0038AF30(s32, s32, s32, s32, unsigned long);
/* --- end of declarations from other files --- */

LINKER_REMNANT("asm/remnants", func_0038B660);

extern s32 D_001D4BD0_0038B670, D_001D4BD4_0038B670;
extern s32 D_001DA050;
/* localdecomp:start func_0038B670 */
extern s32 D_001D4BD0_0038B670, D_001D4BD4_0038B670;
extern s32 D_001DA050;

s32 func_0038B670(s32 u, s32 v, s32 w, s32 h,
                  long t0, long t1, s32 flag,
                  f32 x, f32 y, f32 fw, f32 fh) {
    s32 u1 = u + w;
    s32 v1 = v + h;
    s32 x0 = (s32)(x * 16.0f) + D_001D4BD0_0038B670 - 8;
    s32 x1 = (s32)((x + fw) * 16.0f) + D_001D4BD0_0038B670 - 9;
    s32 y0 = (s32)(y * 16.0f) + D_001D4BD4_0038B670 - 8;
    s32 y1 = (s32)((y + fh) * 16.0f) + D_001D4BD4_0038B670 - 9;
    s32 u4 = u << 4;
    s32 uw4 = u1 << 4;
    long *p;

    if (x0 > 0x9000 || x1 < 0x7000 || y0 > 0x9000 || y1 < 0x7000)
        return 0;

    if (flag) {
        x0 = (x0 & 0xFFF0) + 8;
        x1 = (x1 & 0xFFF0) + 8;
        y0 = (y0 & 0xFFF0) + 8;
        y1 = (y1 & 0xFFF0) + 8;
    }

    p = (long *)D_001DA050;
    p[0] = t1;
    p[1] = 0x154;
    p[2] = 0xA | (long)u << 4 | (long)(u1 - 1) << 14
               | (long)v << 24 | (long)(v1 - 1) << 34;
    p[3] = t0;
    p[4] = (v << 20) + u4;
    p[5] = (long)x0 | (long)y0 << 16;
    p[6] = (v << 20) + uw4;
    p[7] = (long)x1 | (long)y0 << 16;
    p[8] = (v1 << 20) + u4;
    p[9] = (long)x0 | (long)y1 << 16;
    p[10] = (v1 << 20) + uw4;
    p[11] = (long)x1 | (long)y1 << 16;
    D_001DA050 += 0x60;
    return 1;
}
/* localdecomp:end func_0038B670 */

extern s32 D_001D4BD0_0038B850, D_001D4BD4_0038B850;
extern s32 D_001DA050;
/* localdecomp:start func_0038B850 */
extern s32 D_001D4BD0_0038B850, D_001D4BD4_0038B850;
extern s32 D_001DA050;

s32 func_0038B850(s32 u, s32 v, s32 w, s32 h,
                  long *c, long t1, s32 flag,
                  f32 x, f32 y, f32 fw, f32 fh) {
    s32 u1 = u + w;
    s32 v1 = v + h;
    s32 x0 = (s32)(x * 16.0f) + D_001D4BD0_0038B850 - 8;
    s32 x1 = (s32)((x + fw) * 16.0f) + D_001D4BD0_0038B850 - 9;
    s32 y0 = (s32)(y * 16.0f) + D_001D4BD4_0038B850 - 8;
    s32 y1 = (s32)((y + fh) * 16.0f) + D_001D4BD4_0038B850 - 9;
    s32 u4 = u << 4;
    s32 uw4 = u1 << 4;
    long *p;

    if (x0 > 0x9000 || x1 < 0x7000 || y0 > 0x9000 || y1 < 0x7000)
        return 0;

    if (flag) {
        x0 = (x0 & 0xFFF0) + 8;
        x1 = (x1 & 0xFFF0) + 8;
        y0 = (y0 & 0xFFF0) + 8;
        y1 = (y1 & 0xFFF0) + 8;
    }

    p = (long *)D_001DA050;
    p[0] = t1;
    p[1] = 0x154;
    p[2] = 0xA | (long)u << 4 | (long)(u1 - 1) << 14
               | (long)v << 24 | (long)(v1 - 1) << 34;
    p[3] = c[0];
    p[4] = (v << 20) + u4;
    p[5] = (long)x0 | (long)y0 << 16;
    p[6] = c[1];
    p[7] = (v << 20) + uw4;
    p[8] = (long)x1 | (long)y0 << 16;
    p[9] = c[2];
    p[10] = (v1 << 20) + u4;
    p[11] = (long)x0 | (long)y1 << 16;
    p[12] = c[3];
    p[13] = (v1 << 20) + uw4;
    p[14] = (long)x1 | (long)y1 << 16;
    p[15] = 0;
    D_001DA050 += 0x80;
    return 1;
}
/* localdecomp:end func_0038B850 */

extern s32 D_001D4BD0_0038BA30;
extern s32 D_001D4BD4_0038BA30;
/* localdecomp:start func_0038BA30 */
extern s32 D_001D4BD0_0038BA30;
extern s32 D_001D4BD4_0038BA30;
extern s32 D_001DA050;
s32 func_0038BA30(s32 x, s32 y, s32 w, s32 h, long t0, long t1, long t2, s32 snap,
                  f32 sx, f32 sy, f32 sw, f32 sh, f32 dx, f32 dy) {
    s32 x2, y2;
    s32 U0, U1, V0, V1, U0d, U1d, V0d, V1d;
    long clamp;
    long *p;
    s32 ox, oy, ddx, ddy;
    s32 tx0, tx1;
    f32 ex, ey;
    ex = sx + sw;
    dy = dy * 16.0f;
    dx = dx * 16.0f;
    ox = D_001D4BD0_0038BA30;
    U0 = (s32)(sx * 16.0f) + ox - 8;
    ddx = (s32)dx;
    tx0 = x << 4;
    U0d = U0 + ddx;
    U1 = (s32)(ex * 16.0f) + ox - 8;
    oy = D_001D4BD4_0038BA30;
    U1d = U1 + ddx;
    ddy = (s32)dy;
    x2 = x + w;
    ey = sy + sh;
    V0 = (s32)(sy * 16.0f) + oy - 8;
    y2 = y + h;
    V1 = (s32)(ey * 16.0f) + oy - 8;
    V0d = V0 + ddy;
    V1d = V1 + ddy;
    tx1 = x2 << 4;
    if (U0 > 0x9000 || U1 < 0x7000 || V0 > 0x9000 || V1 < 0x7000) return 0;
    if (snap) {
        U0 = (U0 & 0xFFF0) + 8;
        U1 = (U1 & 0xFFF0) + 8;
        V0 = (V0 & 0xFFF0) + 8;
        V1 = (V1 & 0xFFF0) + 8;
        U0d = (U0d & 0xFFF0) + 8;
        U1d = (U1d & 0xFFF0) + 8;
        V0d = (V0d & 0xFFF0) + 8;
        V1d = (V1d & 0xFFF0) + 8;
    }
    clamp = 0xA | ((long)x << 4) | ((long)(x2 - 1) << 14) | ((long)y << 24) | ((long)(y2 - 1) << 34);
    p = (long *)D_001DA050;
    p[0] = t2;
    p[1] = 0x154;
    p[2] = clamp;
    p[3] = t1;
    p[4] = (y << 20) + tx0;
    p[5] = (long)U0d | ((long)V0d << 16);
    p[6] = (y << 20) + tx1;
    p[7] = (long)U1d | ((long)V0d << 16);
    p[8] = (y2 << 20) + tx0;
    p[9] = (long)U0d | ((long)V1d << 16);
    p[10] = (y2 << 20) + tx1;
    p[11] = (long)U1d | ((long)V1d << 16);
    p[12] = t2;
    p[13] = 0x154;
    p[14] = clamp;
    p[15] = t0;
    p[16] = (y << 20) + tx0;
    p[17] = (long)U0 | ((long)V0 << 16);
    p[18] = (y << 20) + tx1;
    p[19] = (long)U1 | ((long)V0 << 16);
    p[20] = (y2 << 20) + tx0;
    p[21] = (long)U0 | ((long)V1 << 16);
    p[22] = (y2 << 20) + tx1;
    p[23] = (long)U1 | ((long)V1 << 16);
    D_001DA050 += 0xC0;
    return 1;
}
/* localdecomp:end func_0038BA30 */

typedef int Q_3875A0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3875A0;
extern s32 D_001D4BD0_0038BCD8;
extern s32 D_001D4BD4_0038BCD8;
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_0038CE20(f32 *, void *, f32);
/* localdecomp:start func_0038BCD8 */
/* from boot_elf's twin func_0038C0B8 (src/boot_elf/text/38BA50.c), renamed through config/frontend_pairs.tsv */
typedef int Q_0038BCD8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_0038BCD8;
extern s32 D_001D4BD0_0038BCD8;
extern s32 D_001D4BD4_0038BCD8;
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_0038CE20(f32 *, void *, f32);
extern s32 D_001DA050_0038BCD8;
void func_0038BCD8(f32 px, f32 py, f32 sx, f32 sy, f32 ang, s32 w, s32 h, long tex, s32 z, s32 rgba,
                   s32 fx, s32 fy, f32 ax, f32 ay) {
    V4_0038BCD8 a, b, c, t, p0, p1, p2, p3;
    s32 u0, u1, v0, v1;
    f32 bx, by, sn;
    long zz;
    u8 bfx = fx;
    u8 bfy = fy;
    if (bfx) {
        u0 = w << 4;
        u1 = 0x10;
    } else {
        u1 = w << 4;
        u0 = 0x10;
    }
    if (bfy) {
        v0 = h << 20;
        v1 = 0x100000;
    } else {
        v1 = h << 20;
        v0 = 0x100000;
    }
    c.x = px;
    c.y = py;
    sn = func_0038D0B0(ang);
    bx = 1.0f;
    by = bx - ay;
    bx = bx - ax;
    a.x = sy * sn;
    a.y = sy * func_0038D098(ang);
    b.x = sx * func_0038D098(ang);
    b.y = -sx * func_0038D0B0(ang);
    func_0038CE20(&t.x, &a, by);
    { Q_0038BCD8 r1, r2;
      __asm__("lqc2 %0, %1" : "=j"(r2) : "m"(t));
      __asm__("lqc2 %0, %1" : "=j"(r1) : "m"(c));
      __asm__("vadd.xyz %0, %1, %2" : "=j"(r1) : "j"(r1), "j"(r2));
      __asm__("sqc2 %1, %0" : "=m"(p0) : "j"(r1)); }
    func_0038CE20(&t.x, &b, bx);
    { Q_0038BCD8 r1, r2;
      __asm__("lqc2 %0, %1" : "=j"(r2) : "m"(t));
      __asm__("lqc2 %0, %1" : "=j"(r1) : "m"(p0));
      __asm__("vsub.xyz %0, %1, %2" : "=j"(r1) : "j"(r1), "j"(r2));
      __asm__("sqc2 %1, %0" : "=m"(p0) : "j"(r1)); }
    func_0038CE20(&t.x, &a, by);
    { Q_0038BCD8 r1, r2;
      __asm__("lqc2 %0, %1" : "=j"(r2) : "m"(t));
      __asm__("lqc2 %0, %1" : "=j"(r1) : "m"(c));
      __asm__("vadd.xyz %0, %1, %2" : "=j"(r1) : "j"(r1), "j"(r2));
      __asm__("sqc2 %1, %0" : "=m"(p1) : "j"(r1)); }
    func_0038CE20(&t.x, &b, ax);
    { Q_0038BCD8 r1, r2;
      __asm__("lqc2 %0, %1" : "=j"(r2) : "m"(t));
      __asm__("lqc2 %0, %1" : "=j"(r1) : "m"(p1));
      __asm__("vadd.xyz %0, %1, %2" : "=j"(r1) : "j"(r1), "j"(r2));
      __asm__("sqc2 %1, %0" : "=m"(p1) : "j"(r1)); }
    func_0038CE20(&t.x, &a, ay);
    { Q_0038BCD8 r1, r2;
      __asm__("lqc2 %0, %1" : "=j"(r2) : "m"(t));
      __asm__("lqc2 %0, %1" : "=j"(r1) : "m"(c));
      __asm__("vsub.xyz %0, %1, %2" : "=j"(r1) : "j"(r1), "j"(r2));
      __asm__("sqc2 %1, %0" : "=m"(p2) : "j"(r1)); }
    func_0038CE20(&t.x, &b, bx);
    { Q_0038BCD8 r1, r2;
      __asm__("lqc2 %0, %1" : "=j"(r2) : "m"(t));
      __asm__("lqc2 %0, %1" : "=j"(r1) : "m"(p2));
      __asm__("vsub.xyz %0, %1, %2" : "=j"(r1) : "j"(r1), "j"(r2));
      __asm__("sqc2 %1, %0" : "=m"(p2) : "j"(r1)); }
    func_0038CE20(&t.x, &a, ay);
    { Q_0038BCD8 r1, r2;
      __asm__("lqc2 %0, %1" : "=j"(r2) : "m"(t));
      __asm__("lqc2 %0, %1" : "=j"(r1) : "m"(c));
      __asm__("vsub.xyz %0, %1, %2" : "=j"(r1) : "j"(r1), "j"(r2));
      __asm__("sqc2 %1, %0" : "=m"(p3) : "j"(r1)); }
    func_0038CE20(&t.x, &b, ax);
    { Q_0038BCD8 r1, r2;
      __asm__("lqc2 %0, %1" : "=j"(r2) : "m"(p3));
      __asm__("lqc2 %0, %1" : "=j"(r1) : "m"(t));
      __asm__("vadd.xyz %0, %1, %2" : "=j"(r2) : "j"(r2), "j"(r1));
      __asm__("sqc2 %1, %0" : "=m"(p3) : "j"(r2)); }
    *(u32 *)(D_001DA050_0038BCD8 + 0) = 0x10000007;
    *(u32 *)(D_001DA050_0038BCD8 + 4) = 0;
    *(u32 *)(D_001DA050_0038BCD8 + 8) = 0;
    *(u32 *)(D_001DA050_0038BCD8 + 0xC) = 0x50000007;
    zz = (long)z << 32;
    {
        long *t2 = (long *)(D_001DA050_0038BCD8 + 0x10);
        D_001DA050_0038BCD8 = (s32)t2;
        t2[0] = 0xB400000000008001UL;
        t2[2] = tex;
        t2[1] = (0xA6A6A6A6UL << 11) | 0x106;
        t2[4] = rgba;
        t2[3] = 0x154;
        t2[5] = u0 | v0;
        t2[6] = ((s32)(p0.x * 16.0f) + D_001D4BD0_0038BCD8 - 8) | ((long)((s32)(p0.y * 16.0f) + D_001D4BD4_0038BCD8 - 8) << 16) | zz;
        t2[7] = u1 | v0;
        t2[8] = ((s32)(p1.x * 16.0f) + D_001D4BD0_0038BCD8 - 8) | ((long)((s32)(p1.y * 16.0f) + D_001D4BD4_0038BCD8 - 8) << 16) | zz;
        t2[9] = u0 | v1;
        t2[10] = ((s32)(p2.x * 16.0f) + D_001D4BD0_0038BCD8 - 8) | ((long)((s32)(p2.y * 16.0f) + D_001D4BD4_0038BCD8 - 8) << 16) | zz;
        t2[11] = u1 | v1;
        t2[12] = ((s32)(p3.x * 16.0f) + D_001D4BD0_0038BCD8 - 8) | ((long)((s32)(p3.y * 16.0f) + D_001D4BD4_0038BCD8 - 8) << 16) | zz;
        t2[13] = 0;
    }
    D_001DA050_0038BCD8 += 0x70;
}
/* localdecomp:end func_0038BCD8 */

typedef int u128_387A00 __attribute__((mode(TI)));
extern s32 D_001DA050;
extern u8 D_001D7770[];
/* localdecomp:start func_0038C138 */
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void (*D_001D9A40[2])(s32);
extern s32 D_001DA050;
extern s32 D_001DA050;
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void (*D_001D9C18[])(int);
extern s32 D_001DA050;
extern s32 D_001DA050;
extern s32 D_001DA050;
extern s32 D_001DA050;
extern u8 D_001D7770[];
extern s32 D_001DA050;

void func_0038C138(long *a, s32 *b, s32 *c, long d, s32 e) {
    u8 *r;
    u8 *p;
    u8 *q;
    *(s32 *)(D_001DA050 + 0) = 0x10000009;
    *(s32 *)(D_001DA050 + 4) = 0;
    *(s32 *)(D_001DA050 + 8) = 0;
    *(s32 *)(D_001DA050 + 0xC) = 0x50000009;
    r = (u8 *)D_001DA050;
    D_001DA050 = (s32)r + 0x10;
    *(u128_387A00 *)(r + 0x10) = *(u128_387A00 *)D_001D7770;
    p = (u8 *)D_001DA050;
    q = p + 0x10;
    D_001DA050 = (s32)q;
    if (e) {
        *(long *)(p + 0x10) = 5;
    } else {
        *(long *)(p + 0x10) = 0;
    }
    *(long *)(q + 8) = d;
    *(long *)(q + 0x10) = 0x154;
    *(long *)(q + 0x18) = c[0];
    *(long *)(q + 0x20) = b[0];
    *(long *)(q + 0x28) = a[0];
    *(long *)(q + 0x30) = c[1];
    *(long *)(q + 0x38) = b[1];
    *(long *)(q + 0x40) = a[1];
    *(long *)(q + 0x48) = c[2];
    *(long *)(q + 0x50) = b[2];
    *(long *)(q + 0x58) = a[2];
    *(long *)(q + 0x60) = c[3];
    *(long *)(q + 0x68) = b[3];
    *(long *)(q + 0x70) = a[3];
    *(long *)(q + 0x78) = 0;
    D_001DA050 = D_001DA050 + 0x80;
}
/* localdecomp:end func_0038C138 */

typedef int u128_387B10 __attribute__((mode(TI)));
extern s32 D_001DA050;
extern u8 D_001D7740[];
/* localdecomp:start func_0038C248 */
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void (*D_001D9A40[2])(s32);
extern s32 D_001DA050;
extern s32 D_001DA050;
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void (*D_001D9C18[])(int);
extern s32 D_001DA050;
extern s32 D_001DA050;
extern s32 D_001DA050;
extern s32 D_001DA050;
extern s32 D_001DA050;
extern u8 D_001D7740[];

void func_0038C248(long *a, s32 *b) {
    u8 *p;
    u8 *q;
    u8 *r;
    *(s32 *)(D_001DA050 + 0) = 0x10000005;
    *(s32 *)(D_001DA050 + 4) = 0;
    *(s32 *)(D_001DA050 + 8) = 0;
    *(s32 *)(D_001DA050 + 0xC) = 0x50000005;
    r = (u8 *)D_001DA050;
    D_001DA050 = (s32)r + 0x10;
    *(u128_387B10 *)(r + 0x10) = *(u128_387B10 *)D_001D7740;
    p = (u8 *)D_001DA050;
    q = p + 0x10;
    D_001DA050 = (s32)q;
    *(long *)(p + 0x10) = 0x4C;
    *(long *)(q + 8) = b[0];
    *(long *)(q + 0x10) = a[0];
    *(long *)(q + 0x18) = a[2];
    *(long *)(q + 0x20) = b[1];
    *(long *)(q + 0x28) = a[1];
    *(long *)(q + 0x30) = a[3];
    *(long *)(q + 0x38) = 0;
    D_001DA050 = D_001DA050 + 0x40;
}
/* localdecomp:end func_0038C248 */

extern s32 D_001D4BD0[];
extern s32 D_001D4BD4[];
/* localdecomp:start func_0038C310 */
extern s32 D_001D4BD0_0038C310;
extern s32 D_001D4BD4_0038C310;
void func_0038C310(int i0, int i1, int i2, int i3, int tag, s32 *x)
{
    unsigned long v[4];
    v[0] = (((i0 << 4) + D_001D4BD0_0038C310) - 8)
         | ((long)(((i1 << 4) + D_001D4BD4_0038C310) - 8) << 16)
         | ((long)tag << 32);
    v[1] = (((i2 << 4) + D_001D4BD0_0038C310) - 8)
         | ((long)(((i1 << 4) + D_001D4BD4_0038C310) - 8) << 16)
         | ((long)tag << 32);
    v[2] = (((i0 << 4) + D_001D4BD0_0038C310) - 8)
         | ((long)(((i3 << 4) + D_001D4BD4_0038C310) - 8) << 16)
         | ((long)tag << 32);
    v[3] = (((i2 << 4) + D_001D4BD0_0038C310) - 8)
         | ((long)(((i3 << 4) + D_001D4BD4_0038C310) - 8) << 16)
         | ((long)tag << 32);
    func_0038C248((long *)v, x);
}
/* localdecomp:end func_0038C310 */

/* localdecomp:start func_0038C3B0 */
void func_0038C3B0(s32 x, s32 y, s32 w, s32 z, s32 a, s32 b) {
    s32 c = (a << 24) | b;
    func_0038AF30(x, y, w, z, c);
    func_0038AF30(x + 1, y - 1, w - 2, w, c);
    func_0038AF30(x + 2, y - 2, w - 3, w - 2, c);
    func_0038AF30(x + 4, y - 4, w - 4, w - 3, c);
    func_0038AF30(x + 1, y - 1, z, z + 2, c);
    func_0038AF30(x + 2, y - 2, z + 2, z + 3, c);
    func_0038AF30(x + 4, y - 4, z + 3, z + 4, c);
}
/* localdecomp:end func_0038C3B0 */

LINKER_REMNANT("asm/remnants", func_0038C4F0);

typedef struct { f32 x, y, z, w; } V_387DC8;
extern void func_0038C138(long *, s32 *, s32 *, long, s32);
/* localdecomp:start func_0038C500 */
/* func_0038C500 log: US draft (rac3-uya-decomp func_00387DC8) taken as is; 1 compile: the only difference from retail is
   the 2 nops retail has before its one div.s (PAL and US alike). DIVS: divscheck.sh is levels-only. */


void func_0038C500(s32 x, s32 y, s32 rx, s32 ry, s32 *a4, s32 *a5, s32 col, s32 n, f32 a0, f32 a1) {
    long base = 0xFFFFF000000000;
    long pts[4];
    V_387DC8 v0, v1;
    long c;
    f32 step, ang, ang2;
    s32 i;
    c = func_00389598(col);
    step = (a1 - a0) / (f32)n;
    ang = ((f32 (*)(f32, f32))func_0038DAB8)(a0, 1.5707964f);
    ang2 = ((f32 (*)(f32, f32))func_0038DAB8)(ang, step);
    for (i = 15; i >= 0; i--) {
        v0.x = func_0038D098(ang);
        v0.y = func_0038D0B0(ang);
        v0.z = 0.0f;
        v1.x = func_0038D098(ang2);
        v1.y = func_0038D0B0(ang2);
        v1.z = 0.0f;
        ang = ang2;
        pts[0] = ((long)(s32)(v0.x * (f32)rx) + x) + (((long)(s32)(v0.y * (f32)rx) + y) << 16) + base;
        pts[1] = ((long)(s32)(v0.x * (f32)ry) + x) + (((long)(s32)(v0.y * (f32)ry) + y) << 16) + base;
        pts[2] = ((long)(s32)(v1.x * (f32)rx) + x) + (((long)(s32)(v1.y * (f32)rx) + y) << 16) + base;
        pts[3] = ((long)(s32)(v1.x * (f32)ry) + x) + (((long)(s32)(v1.y * (f32)ry) + y) << 16) + base;
        func_0038C138(pts, a5, a4, c, 1);
        ang2 = ((f32 (*)(f32, f32))func_0038DAB8)(ang, step);
    }
}
/* localdecomp:end func_0038C500 */
TEXT_PADDING(2);

typedef struct { u8 p0[0x190]; u128_t q190; u128_t q1A0; u8 p1B0[0x70]; f32 f220; u8 p224[0x14]; f32 f238; f32 f23C; s32 f240; s32 f244; s32 f248; s32 f24C; } S_388018;
extern f32 D_001D5880;
extern s32 D_001D9D1C;
extern S_388018 D_00225900_0038C750;
extern long D_001D5330[];
extern u8 D_0010F500[];
extern void func_0038D2D0_0038C750(f32 *, f32);
extern u16 D_0010F4F0[];
extern void func_003A9338(s32, u32);
extern void func_003A9740(void);
/* localdecomp:start func_0038C750 */
typedef struct { u8 p0[0x190]; u128_t q190; u128_t q1A0; u8 p1B0[0x70]; f32 f220; u8 p224[0x14]; f32 f238; f32 f23C; s32 f240; s32 f244; s32 f248; s32 f24C; } S_388018_0038C750;
__asm__(".extern D_001D5880_0038C750, 4");
extern f32 D_001D5880_0038C750;
extern s32 D_001D9D1C_0038C750;
extern S_388018_0038C750 D_00225900_0038C750_0038C750;
extern long D_001D5330_0038C750[];
extern u8 D_0010F500_0038C750[];
extern void func_0038D2D0_0038C750_0038C750(f32 *, f32);
extern u16 D_0010F4F0_0038C750[];
extern void func_003A9338_0038C750(s32, u32);
extern void func_003A9740_0038C750(void);
void func_0038C750(void) {
    f32 m[12];
    f32 v[4];
    u8 *p;
    u8 *q;
    u8 *d;
    S_388018_0038C750 *s;
    func_0038D2D0_0038C750_0038C750(m, 1024.0f);
    func_0038CE20(v, D_00222400, -1024.0f);
    v[3] = 1.0f;
    if (D_001D9D1C_0038C750 != 8) {
        func_003A9338_0038C750((s32)D_0010F500_0038C750, D_0010F4F0_0038C750[0]);
        D_001D9D1C_0038C750 = 8;
    }
    *(s32 *)(D_001DA050 + 0) = 0x10000000;
    *(s32 *)(D_001DA050 + 4) = 0;
    *(s32 *)(D_001DA050 + 8) = 0x11000000;
    *(s32 *)(D_001DA050 + 0xC) = 0x1000404;
    p = (u8 *)D_001DA050;
    *(s32 *)(p + 0x10) = 0;
    *(s32 *)(p + 0x14) = 0;
    *(s32 *)(p + 0x18) = 0;
    *(s32 *)(p + 0x1C) = 0x6C0C43A4;
    q = p + 0x20;
    func_0038D640(q, (u8 *)D_00222400 - 0x100, m);
    *(f32 *)(q + 0x38) += D_001D5880_0038C750;
    q = p + 0x60;
    func_0038D640(q, (u8 *)D_00222400 - 0x80, m);
    *(f32 *)(q + 0x38) += D_001D5880_0038C750;
    s = &D_00225900_0038C750_0038C750;
    *(s32 *)(p + 0xA0) = 0x8000;
    *(s32 *)(p + 0xA4) = 0x303EC000;
    *(s32 *)(p + 0xA8) = 0x412;
    *(f32 *)(p + 0xAC) = s->f220;
    *(u128_t *)(p + 0xB0) = s->q190;
    *(u128_t *)(p + 0xC0) = s->q1A0;
    *(f32 *)(p + 0xD0) = s->f23C;
    *(f32 *)(p + 0xD4) = s->f238;
    *(s32 *)(p + 0xE0) = 0x3000000;
    *(s32 *)(p + 0xE4) = 0x20001D2;
    *(s32 *)(p + 0xE8) = 0x15000000;
    *(s32 *)(p + 0xD8) = 0;
    *(s32 *)(p + 0xDC) = 0;
    *(s32 *)(p + 0xEC) = 0;
    q = p + 0xF0;
    d = (u8 *)D_001DA050;
    *(s32 *)d |= ((q - d) >> 4) - 1;
    D_001DA050 = (s32)q;
    D_001D5330_0038C750[2] = (long)s->f240 | ((long)s->f244 << 16) | ((long)s->f248 << 32) | ((long)s->f24C << 48);
    D_001D5330_0038C750[4] = (long)s->f240 | ((long)s->f244 << 16) | ((long)s->f248 << 32) | ((long)s->f24C << 48);
    func_003A9740_0038C750();
}
/* localdecomp:end func_0038C750 */

LINKER_REMNANT("asm/remnants", func_0038C990);

/* localdecomp:start func_0038C9B0 */
extern void func_003CE250(void);
extern void func_003CE1B0(void);
extern void func_003CE2C0(void);
extern void func_003A9440(s32, unsigned long);
extern s32 D_001A1ED8[];
void func_0038C9B0(void) {
    func_003CE250();
    func_003CE1B0();
    func_003CE2C0();
    func_003A9440(0x47, 0x5360B);
    func_003A9440(0x4E, (D_001A1ED8[0] >> 13) | 0x1000000);
}
/* localdecomp:end func_0038C9B0 */
