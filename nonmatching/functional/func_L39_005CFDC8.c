/* functional: high. Per-tick update of an effect object that is pulled toward a target object (q[0x18]): ramps its size (+0xC) and alpha byte (top byte of +4) with the remaining life (s16 +0xA vs q's s16 at +8, last 5 ticks fade in/out by life/(dur-6) or rem/5), adds the velocity at q+0xC to the position, copies the position onto itself (func_L39_005FFB48, a quad copy) and, when the target is within 2 units in x and y, nudges the position by a rescaled difference and re-aims the velocity; frees itself when func_0038CB00 says so. VU0 vadd/vsub in plain C, same call order. */
/* localdecomp:start func_L39_005CFDC8 */
typedef struct { f32 x, y, z, w; } L39V4_5CFDC8;

extern void func_L39_005FFB48(void *, void *);
extern void func_L39_005BC330(void *, void *, s32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CEA8(void *);
extern f32 D_001D7E74_sda;

void func_L39_005CFDC8(u8 *p) {
    L39V4_5CFDC8 s0 __attribute__((aligned(16)));
    L39V4_5CFDC8 d __attribute__((aligned(16)));
    L39V4_5CFDC8 s20 __attribute__((aligned(16)));
    L39V4_5CFDC8 s30 __attribute__((aligned(16)));
    u8 *q = p + 0x20;
    s32 life, rem, col;
    f32 t, a, b;
    u8 *tgt;

    p[8] = p[8] + q[0xA];
    life = *(s16 *)(p + 0xA);
    rem = *(s16 *)(q + 8) - life;
    if (rem < 6) {
        a = *(f32 *)(q + 4);
        t = (f32)rem / 5.0f;
        *(f32 *)(p + 0xC) = a + ((*(f32 *)(p + 0x20) + a) * 0.5f - a) * t;
        {
            s32 r = q[0xB];
            f32 fr = (f32)r;
            f32 delta = (f32)((r >> 1) - r);
            col = (s32)(fr + delta * t);
        }
    } else {
        a = *(f32 *)(p + 0x20);
        b = *(f32 *)(q + 4);
        t = (f32)life / (f32)(*(s16 *)(q + 8) - 6);
        *(f32 *)(p + 0xC) = a + ((a + b) * 0.5f - a) * t;
        col = (s32)((f32)(q[0xB] >> 1) * t + 0.0f);
    }
    *(s32 *)(p + 4) = (col << 24) | (*(s32 *)(p + 4) & 0xFFFFFF);
    s0.x = *(f32 *)(q + 0xC);
    s0.y = *(f32 *)(q + 0x10);
    s0.w = 0.0f;
    s0.z = *(f32 *)(q + 0x14);
    *(f32 *)(p + 0x10) = *(f32 *)(p + 0x10) + s0.x;
    *(f32 *)(p + 0x14) = *(f32 *)(p + 0x14) + s0.y;
    *(f32 *)(p + 0x18) = *(f32 *)(p + 0x18) + s0.z;
    func_L39_005FFB48(p + 0x10, p + 0x10);
    tgt = *(u8 **)(q + 0x18);
    if (tgt != 0) {
        d.x = *(f32 *)(tgt + 0x10) - *(f32 *)(p + 0x10);
        d.y = *(f32 *)(tgt + 0x14) - *(f32 *)(p + 0x14);
        d.z = *(f32 *)(tgt + 0x18) - *(f32 *)(p + 0x18);
        d.w = *(f32 *)(tgt + 0x1C);
        if ((d.x < 0.0f ? -d.x : d.x) <= 2.0f && (d.y < 0.0f ? -d.y : d.y) <= 2.0f) {
            func_L39_005BC330(&s30, &s30, 0);
            func_0038CE90(&s20, &d, &s30);
            func_0038CF68(&s20, &s20, D_001D7E74_sda);
            *(f32 *)(p + 0x10) = *(f32 *)(p + 0x10) + s20.x;
            *(f32 *)(p + 0x14) = *(f32 *)(p + 0x14) + s20.y;
            *(f32 *)(p + 0x18) = *(f32 *)(p + 0x18) + s20.z;
            if (d.x <= 0.5f && d.y <= 0.5f) {
                func_0038CF68(&s0, &d, 0.03f);
            } else {
                func_0038CF68(&s0, &d, func_0038CEA8(&s0));
            }
            *(f32 *)(q + 0xC) = s0.x;
            *(f32 *)(q + 0x10) = s0.y;
            s0.z = s0.z + 0.02f;
            *(f32 *)(q + 0x14) = s0.z;
        }
    }
    if (func_0038CB00(p + 0xA) != 0) {
        func_003CD250(p);
    }
}
/* localdecomp:end func_L39_005CFDC8 */
