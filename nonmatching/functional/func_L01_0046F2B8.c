/* functional: high. Per-frame update of a bouncing debris particle. When its life ends it splits: spawns one child (state 0x88, life 2) with a scattered position/velocity and keeps itself as the other half with a scaled-down size. Otherwise it flickers its model byte, moves by its velocity, and (while moving) ray-tests the step against the world: a hit freezes it in place and puts it into the "stuck" state (flag 8), where it shrinks/fades until size or alpha hits zero and it is freed. Also drives the spin/phase byte (q+0x10 wraps 0..1). The retail code also scales an uninitialised stack vector by 0.01 right before the flag test; that result is never used (overwritten or unread on every path), so it is omitted. */
typedef struct {
    vu0_v4 v;
    s32 w30;
    s32 w34;
    s32 w38;
    f32 f3C;
    s32 w40;
} Extra_46F2B8;

extern s32 func_003D3CB0(void *, void *, s32, s32, void *);
extern void func_0038CE20(void *dst, void *src, f32 s);

void func_L01_0046F2B8(u8 *o) {
    u8 *q = o + 0x20;
    vu0_v4 a;
    vu0_v4 b;
    Extra_46F2B8 ex;
    u8 *d;
    u8 *ch;
    f32 f20;
    f32 f3;
    f32 f1;
    f32 sign;
    s32 hit;
    s32 flags;

    if (*(s16 *)(o + 0xA) != 0 && func_0038CB00((s16 *)(o + 0xA)) != 0) {
        q[0x18] = q[0x18] | 0x88;
        f20 = *(f32 *)(o + 0xC) / 900000.0f;
        *(f32 *)(o + 0xC) = *(f32 *)(o + 0xC) * 0.8f;
        func_0038CE20(&a, q, func_003824E0(0.5f, 0.7f));
        b.x = *(f32 *)(o + 0x10) + func_003824E0(-f20, f20);
        b.y = *(f32 *)(o + 0x14) + func_003824E0(-f20, f20);
        b.z = *(f32 *)(o + 0x18) + func_003824E0(-f20, f20);
        a.x = a.x + func_003824E0(-*(f32 *)(q + 0) * 0.2f, *(f32 *)(q + 0) * 0.2f);
        a.y = a.y + func_003824E0(-*(f32 *)(q + 4) * 0.2f, *(f32 *)(q + 4) * 0.2f);
        a.z = a.z + func_003824E0(-*(f32 *)(q + 8) * 0.2f, 0.0f);
        ch = (u8 *)func_L01_0046F148((u128_t *)&b, (u128_t *)&a, 0x88, *(s32 *)(q + 0x1C));
        if (ch != 0) {
            *(s16 *)(ch + 0xA) = 2;
            *(f32 *)(ch + 0xC) = *(f32 *)(o + 0xC);
        }
        func_0038CE20(q, q, func_003824E0(0.5f, 0.7f));
        *(f32 *)(q + 0) = *(f32 *)(q + 0) + func_003824E0(-*(f32 *)(q + 0) * 0.2f, *(f32 *)(q + 0) * 0.2f);
        *(f32 *)(q + 4) = *(f32 *)(q + 4) + func_003824E0(-*(f32 *)(q + 4) * 0.2f, *(f32 *)(q + 4) * 0.2f);
        *(f32 *)(q + 8) = *(f32 *)(q + 8) + func_003824E0(-*(f32 *)(q + 8) * 0.2f, 0.0f);
        *(f32 *)(o + 0x10) = *(f32 *)(o + 0x10) + func_003824E0(-f20, f20);
        *(f32 *)(o + 0x14) = *(f32 *)(o + 0x14) + func_003824E0(-f20, f20);
        *(f32 *)(o + 0x18) = *(f32 *)(o + 0x18) + func_003824E0(-f20, f20);
    }

    d = D_L01_002211E0[0];
    o[2] = d[(*(s16 *)(o + 0xA) + *(s16 *)(q + 0x16) + (o[2] - d[0])) & 7];
    vec_add_ab(&a, o + 0x10, q);
    if (*(s16 *)(q + 0x14) < 3) {
        b = *(vu0_v4 *)(o + 0x10);
    } else {
        vec_sub_ab(&b, o + 0x10, q);
    }
    hit = 0;
    if (q[0x18] & 8) {
        if ((*(s32 *)(o + 4) & 0xFF000000) == 0) {
            func_003CD250((Obj *)o);
            return;
        }
        q[0x18] = q[0x18] | 8;
        if (func_00382468(3) == 0) {
            hit = func_003D3CB0(&b, &a, 0, *(s32 *)(q + 0x1C), 0) != 0;
        }
    } else {
        ex.v = *(vu0_v4 *)q;
        ex.w30 = *(s32 *)(q + 0x1C);
        ex.f3C = 1.0f;
        ex.w34 = 1;
        ex.w40 = 1;
        if (func_00382468(3) == 0) {
            hit = func_003D3CB0(&b, &a, 0, *(s32 *)(q + 0x1C), &ex) != 0;
        }
    }
    if (hit != 0) {
        q[0x18] = q[0x18] | 8;
    } else {
        *(vu0_v4 *)(o + 0x10) = a;
    }
    if (q[0x18] & 8) {
        *(u16 *)(q + 0x16) = *(u16 *)(q + 0x16) + 1;
        *(f32 *)(o + 0xC) = *(f32 *)(o + 0xC) - 26000.002f;
        if (*(f32 *)(o + 0xC) <= 0.0f) {
            func_003CD250((Obj *)o);
            return;
        }
    } else {
        *(f32 *)(o + 0xC) = *(f32 *)(o + 0xC) + 20800.002f;
    }
    f3 = (f32)*(s16 *)(q + 0x14) / 15.0f * 0.0064000003f + 0.08f;
    if (f3 < 0.0f) {
        f3 = 0.0f;
    }
    if (0.08f < f3) {
        f3 = 0.08f;
    }
    if (q[0x18] & 8) {
        f3 = f3 / ((f32)*(s16 *)(q + 0x16) / 7.0f + 1.0f);
    }
    *(s32 *)(o + 4) = (*(s32 *)(o + 4) & 0xFFFFFF) | ((s32)(f3 * 256.0f) << 24);
    *(f32 *)(q + 8) = *(f32 *)(q + 8) + 0.000288f;
    if (*(s16 *)(q + 0x14) >= 22 || (q[0x18] & 8)) {
        *(f32 *)(q + 0) = *(f32 *)(q + 0) * 0.95f;
        *(f32 *)(q + 4) = *(f32 *)(q + 4) * 0.95f;
    }
    flags = q[0x18];
    sign = -1.0f;
    if (flags & 1) {
        sign = 1.0f;
    }
    f1 = *(f32 *)(q + 0x10);
    if (flags & 8) {
        f1 = f1 + sign * -0.012f / (f32)*(s16 *)(q + 0x16);
        *(f32 *)(q + 8) = *(f32 *)(q + 8) + 0.000288f;
    } else {
        f1 = f1 + sign * -0.012f;
    }
    *(f32 *)(q + 0x10) = f1;
    if (1.0f < *(f32 *)(q + 0x10)) {
        *(f32 *)(q + 0x10) = *(f32 *)(q + 0x10) - 1.0f;
    }
    if (*(f32 *)(q + 0x10) < 0.0f) {
        *(f32 *)(q + 0x10) = *(f32 *)(q + 0x10) + 1.0f;
    }
    o[8] = (s32)(*(f32 *)(q + 0x10) * 256.0f);
}
