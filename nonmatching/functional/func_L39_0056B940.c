/* functional: medium. Helper prototypes (func_0038D590, func_0038D000) inferred from register use; w lanes follow the destination register; 242 byte diffs are codegen/stack layout. */
#include "common.h"
extern s32 D_0024B858[];
extern f32 D_0024DE80[];
extern f32 D_0025F760[];
void func_0038D590(void *, void *);
void func_0038D000(void *, void *, void *);
void func_0038CE20(void *, void *, f32);
void func_0038CF68(void *, void *, f32);
void func_0038CE90(void *, void *, void *);
f32 func_0038CEA8(void *);
s32 func_003D3CB0(void *, void *, s32, s32, s32);

static void bf148_vop2(f32 *d, f32 *a, f32 *b, s32 sub, f32 w) {
    if (sub) {
        d[0] = a[0] - b[0]; d[1] = a[1] - b[1]; d[2] = a[2] - b[2];
    } else {
        d[0] = a[0] + b[0]; d[1] = a[1] + b[1]; d[2] = a[2] + b[2];
    }
    d[3] = w;
}
static void bf148_q2(void *d, void *s) {
    s32 *dd = d, *ss = s;
    s32 a = ss[0], b = ss[1], c = ss[2], e = ss[3];
    dd[0] = a; dd[1] = b; dd[2] = c; dd[3] = e;
}

void func_L39_0056B940(s32 idx, s32 flag) {
    u8 *G = (u8 *)(D_0024DE80 + idx * 0x118);
    u8 *H = G + 0x150;
    u8 *P = *(u8 **)(G + 0x50);
    u8 *st = *(u8 **)(P + 0x70);
    u8 *e = st + 0x180;
    u8 *sb = st + 0x60;
    f32 v00[4], v10[4], v20[4], v30[4], v40[4], v50[4], v60[4], v90[4], vA0[4], vB0[4], vC0[4], vF0[4];
    f32 len, len2;

    if (flag != 0) {
        v50[0] = -*(f32 *)(e + 0x2C);
        v50[1] = 0.0f;
        v50[2] = *(f32 *)(e + 0x30);
        v50[3] = 0.0f;
        func_0038D590(v60, H);
        func_0038D000(v40, v50, *(u8 **)(sb + 0xE0) + 0xC0);
        bf148_vop2((f32 *)(P + 0x30), (f32 *)(st + 0x60), v40, 0, *(f32 *)(st + 0x6C));
        func_0038CE20(v10, *(u8 **)(sb + 0xE0) + 0xE0, *(f32 *)(sb + 0xD0));
        bf148_vop2(v30, (f32 *)(st + 0x60), v10, 0, *(f32 *)(st + 0x6C));
        if (func_003D3CB0(v30, P + 0x30, D_0024B858[idx], *(s32 *)(H + 0xF0), 0) != 0) {
            bf148_vop2(v90, D_0025F760, v30, 1, D_0025F760[3]);
            len = func_0038CEA8(v90);
            if (len <= 2.5f) {
                vB0[0] = *(f32 *)(e + 0x2C);
                vB0[1] = 0.0f;
                vB0[2] = *(f32 *)(e + 0x30);
                vB0[3] = 0.0f;
                func_0038D590(vC0, H);
                func_0038D000(vA0, vB0, *(u8 **)(sb + 0xE0) + 0xC0);
                bf148_vop2((f32 *)(P + 0x30), (f32 *)(st + 0x60), vA0, 0, *(f32 *)(st + 0x6C));
                func_0038CE20(v10, *(u8 **)(sb + 0xE0) + 0xE0, *(f32 *)(sb + 0xD0));
                bf148_vop2(v30, (f32 *)(st + 0x60), v10, 0, *(f32 *)(st + 0x6C));
                if (func_003D3CB0(v30, P + 0x30, D_0024B858[idx], *(s32 *)(H + 0xF0), 0) != 0) {
                    bf148_vop2(vF0, D_0025F760, v30, 1, D_0025F760[3]);
                    len2 = func_0038CEA8(vF0);
                    if (len2 == 0.0f) {
                        bf148_q2(P + 0x30, v30);
                    } else {
                        func_0038CE20(vF0, vF0, (len2 - 0.5f) / len2);
                        bf148_vop2((f32 *)(P + 0x30), v30, vF0, 0, v30[3]);
                    }
                }
            } else {
                func_0038CE20(v90, v90, (len - 0.5f) / len);
                bf148_vop2((f32 *)(P + 0x30), v30, v90, 0, v30[3]);
            }
        }
    }
    *(f32 *)(P + 0x64) = *(f32 *)(P + 0x30);
    *(f32 *)(P + 0x68) = *(f32 *)(P + 0x34);
    *(f32 *)(P + 0x6C) = *(f32 *)(P + 0x38);
    bf148_q2(v00, G + 0x90);
    func_0038CF68(v10, v00, *(f32 *)(sb + 0xD0));
    bf148_vop2(v30, v10, (f32 *)(st + 0x60), 0, v10[3]);
    bf148_vop2(v20, v30, (f32 *)(P + 0x30), 1, v30[3]);
    func_0038CF68(P, v20, 1.0f);
    bf148_q2(P + 0x20, v00);
    func_0038CE90(P + 0x10, P, P + 0x20);
    func_0038CF68(P + 0x10, P + 0x10, 1.0f);
    func_0038CE90(P + 0x20, P + 0x10, P);
    bf148_q2(P + 0x40, P);
}
