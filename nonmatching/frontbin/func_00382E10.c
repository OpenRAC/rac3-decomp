/* US draft of func_00382E10 (rac3-uya-decomp func_0037EB68, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_00382E10 */
typedef int u128_37EB68 __attribute__((mode(TI)));
typedef struct { u8 p0[0x2B8]; f32 f2B8; u8 p2BC[0xC]; f32 f2C8; u8 p2CC[0x58]; s32 f324; u8 p328[0x138]; } E_37EB68;
extern E_37EB68 D_00222480_00382E10[];
extern u8 *D_001D9A84;
extern u8 D_002251D0[];
extern void func_00382A80(s32);
extern void func_00382DC8(u8 *);
void func_00382E10(u8 *o, s32 a1) {
    s32 idx = *(s32 *)(o + 0x94);
    s32 j = idx;
    u8 *e = (u8 *)D_00222480_00382E10 + idx * 0x460;
    u8 *q = *(u8 **)(e + 0x50);
    s32 k = *(s16 *)(q + 0x7E);
    u8 *t;
    s32 m;
    s32 off;
    f32 f;
    if (a1 != 0 || *(s32 *)(e + 0x458) > 0) k = 4;
    t = *(u8 **)((u8 *)((*(s16 *)(o + 0x84) << 5) + (s32)D_001D9A84) + 0x1C);
    m = 0;
    if (t != 0) m = t[0x1D];
    if (k == 4) {
        *(s16 *)(e + 0x2A0) = 0;
        *(s16 *)(o + 0x8E) = 1;
    } else if (k == 2 || m == 1 || m == 5) {
        if (m == 1) {
            f = *(f32 *)(o + 0x78);
            e[0x2A3] = 0;
            if (0.0f < f) {
                ((E_37EB68 *)((u8 *)D_00222480_00382E10 + j * 0x460))->f2C8 = f;
                ((E_37EB68 *)((u8 *)D_00222480_00382E10 + j * 0x460))->f2B8 = f;
            } else {
                ((E_37EB68 *)((u8 *)D_00222480_00382E10 + j * 0x460))->f2C8 = 0.018f;
                ((E_37EB68 *)((u8 *)D_00222480_00382E10 + j * 0x460))->f2B8 = 0.018f;
            }
        } else if (m == 5) {
            f = *(f32 *)(o + 0x78);
            e[0x2A3] = 2;
            if (0.0f < f) {
                ((E_37EB68 *)((u8 *)D_00222480_00382E10 + j * 0x460))->f324 = f;
            } else {
                ((E_37EB68 *)((u8 *)D_00222480_00382E10 + j * 0x460))->f324 = 0x28;
            }
        }
        if (*(s16 *)(e + 0x2A0) == 0) {
            *(s16 *)(e + 0x2A0) = 1;
        } else {
            *(s16 *)(e + 0x2A0) = 2;
        }
    } else if (*(s16 *)(q + 0x7E) == 3 || *(s16 *)(q + 0x7E) == 5 || m == 3 || m == 6) {
        *(u128_37EB68 *)(o + 0x30) = *(u128_37EB68 *)(q + 0x30);
        *(u128_37EB68 *)(o + 0x00) = *(u128_37EB68 *)(q + 0x00);
        *(u128_37EB68 *)(o + 0x10) = *(u128_37EB68 *)(q + 0x10);
        *(u128_37EB68 *)(o + 0x20) = *(u128_37EB68 *)(q + 0x20);
        o[0x7D] = 2;
        if (*(s16 *)(q + 0x7E) == 5 || m == 6) {
            f = *(f32 *)(o + 0x78);
            e[0x2A3] = 0;
            if (0.0f < f) {
                ((E_37EB68 *)((u8 *)D_00222480_00382E10 + j * 0x460))->f2C8 = f;
                ((E_37EB68 *)((u8 *)D_00222480_00382E10 + j * 0x460))->f2B8 = f;
            } else {
                ((E_37EB68 *)((u8 *)D_00222480_00382E10 + j * 0x460))->f2C8 = 0.018f;
                ((E_37EB68 *)((u8 *)D_00222480_00382E10 + j * 0x460))->f2B8 = 0.018f;
            }
        }
    } else {
        *(s16 *)(o + 0x8E) = 1;
    }
    off = j * 0x780;
    *(s16 *)(q + 0x7E) = 0;
    q[0x7D] = 0;
    *(s16 *)(q + 0x8E) = 0;
    *(u8 **)(e + 0x54) = q;
    func_0038CD28(D_002251D0 + off, D_002251D0 - 0x280 + off, 0x280);
    *(u8 **)(*(u8 **)(e + 0x54) + 0x70) = D_002251D0 + off;
    *(u8 **)(e + 0x50) = o;
    *(u8 **)(o + 0x70) = D_002251D0 - 0x280 + off;
    q = o;
    *(s32 *)(e + 0x454) = 0;
    func_00382DC8(q);
    func_00382A80(idx);
    *(u128_37EB68 *)e = *(u128_37EB68 *)(q + 0x30);
    {
        f32 *src = (f32 *)(q + 0x30);
        f32 *dst = (f32 *)(q + 0x64);
        dst[0] = src[0];
        dst[1] = src[1];
        dst[2] = src[2];
    }
}
/* localdecomp:end func_00382E10 */
