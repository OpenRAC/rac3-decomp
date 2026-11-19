/* functional: high. Per-tick update of a smoke/ember emitter object (q = obj+0x20): fades alpha (top byte of +4) and size (+0xC) by life*scale, moves by q (and, when q has upward speed below a cap, clamps z to the limit), then with probability from q[0x1E] spawns a child effect through func_L01_00475128 (either a plain 0x21 puff with a small z velocity, or a rotated randomised one built from func_0038D160/func_0038DAB8/func_00382760), and finally, when q[0x1D] is set and alpha >= 0xF, calls func_003D4D00 and burns n loop iterations (retail's empty delay loop, four nops each). Plain C for the VU0 vadd/zero quad; same call order as retail; PAL values (not the NTSC-U twin's). */
/* localdecomp:start func_L39_005D50A0 */
typedef struct { f32 x, y, z, w; } L39V4_5D50A0;

extern u8 D_001D7EC0_sda;
extern s32 D_001D7EBC_sda;
extern f32 D_001D7EAC_sda;
extern f32 D_001D7EB0_sda;
extern s32 D_001D7EB4_sda;
extern s32 D_001D7EB8_sda;
extern f32 D_001D7EA8_sda;

extern s32 func_L39_005B4398(s32);
extern s32 func_L39_005B43C8(s32, s32);
extern f32 func_L39_005B4410(f32, f32);
extern u8 *func_L01_00475128(s32, void *, void *, u32, f32, f32, f32, s32, s32, s32, s32);
extern void func_003C4C18(void *, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038CED8(void *);
extern void func_00382760(void *, f32, f32, f32);
extern s32 func_003D4D00(void *, s32, void *, s32, f32);

void func_L39_005D50A0(u8 *self) {
    u8 *q;
    f32 sv, t, g, inc, limit, nz;
    f32 a20, b20, a21, a22, a23;
    u8 alpha;
    s32 n;
    u8 *r;
    L39V4_5D50A0 v __attribute__((aligned(16)));
    L39V4_5D50A0 v2 __attribute__((aligned(16)));

    if (func_0038CB00(self + 0xA) != 0) {
        func_003CD250(self);
        return;
    }
    q = self + 0x20;
    self[8] = self[8] + D_001D7EC0_sda;
    sv = *(f32 *)(self + 0x1C);
    t = (f32)*(s16 *)(self + 0xA) * sv;
    alpha = (u8)(s32)((f32)q[0x1C] * t);
    *(u32 *)(self + 4) = (*(u32 *)(self + 4) & 0xFFFFFF) | ((u32)alpha << 24);
    g = *(f32 *)(q + 0x18);
    *(f32 *)(self + 0xC) = g + (*(f32 *)(q + 0x14) - g) * t;
    inc = *(f32 *)(self + 0xC) / 500000.0f;
    if (0.0f < *(f32 *)(q + 0xC) && *(f32 *)(q + 8) < 0.0f) {
        limit = *(f32 *)(q + 0xC) + inc;
        nz = *(f32 *)(q + 8);
        if (nz * 5.0f < limit - *(f32 *)(self + 0x18)) {
            *(f32 *)(q + 8) = (limit - *(f32 *)(self + 0x18)) / 5.0f;
        }
        *(f32 *)(self + 0x10) = *(f32 *)(self + 0x10) + *(f32 *)(self + 0x20);
        *(f32 *)(self + 0x14) = *(f32 *)(self + 0x14) + *(f32 *)(self + 0x24);
        *(f32 *)(self + 0x18) = *(f32 *)(self + 0x18) + *(f32 *)(self + 0x28);
        if (*(f32 *)(self + 0x18) < limit) {
            *(f32 *)(self + 0x18) = limit;
        }
    } else {
        *(f32 *)(self + 0x10) = *(f32 *)(self + 0x10) + *(f32 *)(q + 0);
        *(f32 *)(self + 0x14) = *(f32 *)(self + 0x14) + *(f32 *)(q + 4);
        *(f32 *)(self + 0x18) = *(f32 *)(self + 0x18) + *(f32 *)(q + 8);
    }
    if (q[0x1E] != 0 && func_L39_005B4398(q[0x1E]) == 0) {
        if (func_L39_005B4398(D_001D7EBC_sda) == 0) {
            v.x = 0.0f;
            v.y = 0.0f;
            v.z = 0.0f;
            v.w = 0.0f;
            v.z = inc * 0.2f;
            r = func_L01_00475128(*(s32 *)(q + 0x10), self + 0x10, &v, ((s32)(t * 64.0f) << 24) | 0x202020, 0.0f,
                                  *(f32 *)(self + 0xC), *(f32 *)(self + 0xC) * 0.8f, 0x21, 0, 0, 1);
            if (r != 0) {
                r[3] = 0x44;
            }
        } else {
            v = *(L39V4_5D50A0 *)(self + 0x10);
            func_003C4C18(&v, inc);
            a21 = D_001D7EAC_sda * 1.2f * inc;
            a20 = func_0038D160(*(f32 *)q, *(f32 *)(q + 4));
            a23 = D_001D7EB0_sda * 0.017453292f;
            a22 = func_0038DAB8(a20, func_L39_005B4410(-a23, a23));
            b20 = func_0038D160(func_0038CED8(q), *(f32 *)(q + 8));
            func_00382760(&v2, a21, a22, func_0038DAB8(b20, func_L39_005B4410(0.0f, D_001D7EB0_sda * 0.017453292f)));
            n = func_L39_005B43C8((D_001D7EB4_sda * 5 + 2) / 6, (D_001D7EB8_sda * 5 + 2) / 6);
            r = func_L01_00475128(*(s32 *)(q + 0x10), &v, &v2, *(u32 *)(self + 4), 0.0f, *(f32 *)(self + 0xC),
                                  *(f32 *)(self + 0xC) * D_001D7EA8_sda, n, 0, 0, 0);
            if (r != 0) {
                r[2] = self[2];
            }
        }
    }
    if (q[0x1D] == 0 || alpha < 0xF) {
        *(f32 *)(self + 0x1C) = sv;
        return;
    }
    n = func_003D4D00(self + 0x10, 1, *(void **)(q + 0x10), 0, inc);
    if (n > 0) {
        do {
        } while (--n);
    }
    *(f32 *)(self + 0x1C) = sv;
}
/* localdecomp:end func_L39_005D50A0 */
