#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003D13B0();
/* --- end of declarations from other files --- */

/* declarations of 3CB890.c's earlier functions (tools/port_from_us.py) */
extern void func_003D0A08(s32, s32, s32);
extern s32 func_003DE9F8(s32, s32, s32);
extern s32 func_003E1238(s32, s32, s32);
extern u8 D_002FF700[];
typedef int u128_3CB958 __attribute__((mode(TI)));
extern u8 D_001DA6B0[8];
extern f32 D_001DA6C0;
extern f32 D_001DA6C4;
extern volatile f32 D_001DA6C8;
extern u8 D_001DA6D0[];
extern void func_0038CDE8(void *, void *);
extern void func_0038CE20(f32 *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CF68(s32, s32, f32);
void func_003D1A20(s16 *);
void func_003D1B68(s16 *);

/* localdecomp:start func_003D1030 */
typedef struct { u8 pad0[0x150]; s16 x; s16 y; } S_3CBAC0;
extern S_3CBAC0 D_001CFEC0;
extern u32 *D_001DA050_003D1030;
extern void func_003A9440(s32, unsigned long);
void func_003D1030(void) {
    S_3CBAC0 *s = &D_001CFEC0;
    s32 x = s->x;
    s32 y = s->y;
    s32 n = x / 32;
    s32 i;
    unsigned long *q;
    s32 k;
    func_003A9440(0x42, 0x64);
    D_001DA050_003D1030[0] = (n + 5) | 0x10000000;
    D_001DA050_003D1030[1] = 0;
    D_001DA050_003D1030[2] = 0;
    D_001DA050_003D1030[3] = (n + 5) | 0x50000000;
    D_001DA050_003D1030 += 4;
    q = (unsigned long *)D_001DA050_003D1030;
    q[0] = 0x1000000000000001UL;
    q[1] = 0xE;
    q[2] = 0x35001;
    q[3] = 0x47;
    q[4] = 0x2400000000008001UL;
    q[5] = 0x10;
    q[6] = 0x146;
    q[7] = 0x80808080;
    q[8] = (n | 0x8000) | 0x2400000000000000UL;
    q[9] = 0x44;
    i = 0;
    if (i < n) {
        k = 10;
        do {
            q[k++] = (0x8000 - x * 8 + i * 0x200) | ((unsigned long)(0x8000 - y * 8) << 16);
            q[k++] = (0x8200 - x * 8 + i * 0x200) | ((unsigned long)(y * 8 + 0x7FF0) << 16);
            i++;
        } while (i < n);
    }
    D_001DA050_003D1030 += n * 4 + 20;
}
/* localdecomp:end func_003D1030 */

/* localdecomp:start func_003D11E0 */
typedef struct { u8 pad0[0x150]; s16 x; s16 y; } S_3CBC70;
extern S_3CBC70 D_001CFEC0_003D11E0;
extern u32 *D_001DA050_003D11E0;
void func_003D11E0(s32 rgba) {
    S_3CBC70 *s = &D_001CFEC0_003D11E0;
    s32 x = s->x;
    s32 y = s->y;
    s32 n = x / 32;
    s32 i;
    unsigned long *q;
    s32 k;
    D_001DA050_003D11E0[0] = (n + 5) | 0x10000000;
    D_001DA050_003D11E0[1] = 0;
    D_001DA050_003D11E0[2] = 0;
    D_001DA050_003D11E0[3] = (n + 5) | 0x50000000;
    D_001DA050_003D11E0 += 4;
    q = (unsigned long *)D_001DA050_003D11E0;
    q[0] = 0x1000000000000001UL;
    q[1] = 0xE;
    q[2] = 0x35801;
    q[3] = 0x47;
    q[4] = 0x2400000000000001UL;
    q[5] = 0x10;
    q[6] = 0x146;
    q[7] = rgba;
    q[8] = (n | 0x8000) | 0x2400000000000000UL;
    q[9] = 0x44;
    i = 0;
    if (i < n) {
        k = 10;
        do {
            q[k++] = (0x8000 - x * 8 + i * 0x200) | ((unsigned long)(0x8000 - y * 8) << 16);
            q[k++] = (0x8200 - x * 8 + i * 0x200) | ((unsigned long)(y * 8 + 0x7FF0) << 16);
            i++;
        } while (i < n);
    }
    D_001DA050_003D11E0 += n * 4 + 20;
    D_001DA050_003D11E0[0] = 0x10000000;
    D_001DA050_003D11E0[1] = 0;
    D_001DA050_003D11E0[2] = 0x13000000;
    D_001DA050_003D11E0[3] = 0;
    D_001DA050_003D11E0 += 4;
}
/* localdecomp:end func_003D11E0 */

typedef struct { s32 x0; void *x4; s32 x8; s32 xC; } Q_003CBE40;
typedef struct {
    s32 x0;
    s32 x4;
    f32 x8;
    f32 xC;
    f32 x10;
    f32 x14;
    f32 x18;
    u8 pad1C[4];
    u8 x20[0x10];
} R_003CBE40;
typedef struct { u8 pad[0x150]; s16 x150; s16 x152; } V_003CBE40;
extern Q_003CBE40 *D_001DA050[1];
extern s32 D_001DA6F0;
extern s32 D_001D9340;
extern volatile s32 D_001D9344;
extern f32 D_001DA6E0;
extern f32 D_001DA6E4;
extern u8 D_001D5477;
extern u8 D_1420B0[];
extern u8 D_003801F0[];
extern V_003CBE40 D_1CFEC0;
extern s32 D_1A1ED0[];
extern void func_003D0EC8(void *, f32);
extern void func_003D1E28(f32 *, f32 *);
extern void func_003D2380(s32, s32);
extern void func_003A9440(s32, unsigned long);
/* localdecomp:start func_003D13B0 */
/* Small-data size metadata for the file's single-pass assembler. */
__asm__(".extern D_001D9340, 4");
extern s16 *func_003D0FD8(s16 *);
extern s32 func_003D20B0(s32, s32);
extern void func_003D1EC0(s32, s32);
extern void func_003D2520(s32, s32);
extern void func_003D27C0(s32);

void func_003D13B0(R_003CBE40 *q) {
    R_003CBE40 *r;
    Q_003CBE40 *start;
    s32 a, b, k, res, n;
    f32 v0[4];
    f32 v1[4];

    func_003D1030();
    r = q;
    D_001DA050[0]->x0 = 0x30000007;
    D_001DA050[0]->x4 = D_1420B0;
    D_001DA050[0]->x8 = 0x13000000;
    D_001DA050[0]->xC = 0x50000007;
    (++D_001DA050[0])->x0 = 0x30000003;
    D_001DA050[0]->x4 = D_003801F0;
    D_001DA050[0]->x8 = 0x13000000;
    D_001DA050[0]->xC = 0x50000003;
    start = D_001DA050[0] + 1;
    D_001DA6E0 = (D_1CFEC0.x150 >> 1) - 0x800;
    D_001DA6E4 = (D_1CFEC0.x152 >> 1) - 0x800;
    D_001DA050[0] = D_001DA050[0] + 2;
    if (D_001D5477) {
        b = 1;
        a = 2;
    } else {
        b = 2;
        a = 1;
    }
    while (r->x0 != 0) {
        q++;
        func_003D0EC8(r->x20, 1000.0f);
        v1[0] = v0[0] = r->x10;
        v1[1] = v0[1] = r->x14;
        v1[2] = v0[2] = r->x18;
        v0[3] = -r->x8 - r->xC;
        v1[3] = -r->x8 + r->xC;
        for (k = 0; k < r->x0; k++) {
            q = (R_003CBE40 *)func_003D0FD8((s16 *)q);
            func_003D1E28(v0, v1);
            if (r->x4 != 0) {
                res = func_003D20B0(0x70000000, D_001DA6F0);
            } else {
                func_003D1EC0(0x70000000, D_001DA6F0);
                res = 0;
            }
            if (res != 0) {
                func_003D2520(a, D_001D9344);
                func_003D2520(b, D_001D9340);
                if (res & 0x20) {
                    func_003D27C0(D_001D9340);
                }
            } else {
                func_003D2380(a, D_001D9344);
                func_003D2380(b, D_001D9340);
            }
        }
        r = q;
    }
    n = D_001DA050[0] - start - 1;
    if (n > 0) {
        start->x0 = n | 0x10000000;
        start->x4 = 0;
        start->x8 = 0;
        start->xC = n | 0x50000000;
    } else {
        D_001DA050[0]--;
    }
    func_003A9440(0x4C, 0x80000 | (D_1A1ED0[1] >> 13));
    func_003A9440(0x42, (0x8000L << 22) | 0x64);
    func_003D11E0(0);
    func_003A9440(0x47, 0x5360B);
    func_003A9440(0x42, (0x8000L << 24) | 0x44);
}
/* localdecomp:end func_003D13B0 */
