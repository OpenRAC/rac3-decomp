/* functional: medium-high. Written from the PAL asm (no draft). Same calls/args/order, same frame size (0xD0); 638 words differ from retail in scheduling/regalloc only. Notes: a1 (axis) unused as in retail; func_L20_003EFFE0 gets f12=s[0x6C] passed through (retail leaves it in f12); the three scatter loops are separate copies as in retail (differences: rand range 0.6-1 / 0.75-1.5 / 0.6-1, colour slot s[0x48..0x54], t3 1/5/3, loop1 has a second spawn, loop3 size scale*2100.0f). Rolling random-table index D_L20_001DF338 mod 44. Needs the file context (vu0.h, D_L20_001E2E80 as C_003EEB40[], D_L20_002C51D0, D_L20_00220258, D_L20_001DF338, func_L01_00443A18, func_003824E0, func_0038DAB8, func_00382498, func_0038D160). */
extern u8 *func_L01_0046FB40(void *, void *, s32, u32, s32, s32, s32, s32, f32, f32, f32);
extern u8 *D_L20_002203C8[];
extern f32 D_L20_002C5180[];
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_L01_00459590(void *, s32, f32);
extern void func_L01_003006C0(void *, void *, s32, s32);
extern void func_L20_003EFFE0(u8 *, f32);

void func_L20_003EF550(u8 *obj, void *axis, void *zero, f32 final) {
    u8 *s = *(u8 **)(obj + 0x68);
    u8 *pos = obj + 0x10;
    vu0_v4 v;
    vu0_v4 vel;
    f32 scale = *(f32 *)(s + 0xC);
    f32 big = scale * 4.5f * 210000.0f;
    f32 small = scale * 3.0f * 210000.0f;
    f32 ang, jit, sz, w;
    s32 n, k, r, life;
    u8 *p;

    p = func_L01_0046FB40(pos, zero, 25, *(u32 *)(s + 0x40), 0, 100, 0, 0, small, big, 0.0f);
    if (p) p[2] = D_L20_002203C8[0][0];
    p = func_L01_0046FB40(pos, zero, 25, *(u32 *)(s + 0x44), 0, 100, 0, 0, small, big, 0.0f);
    if (p) {
        p[3] = 0x44;
        p[2] = D_L20_002203C8[0][0];
    }
    for (n = 1; n >= 0; n--) {
        p = func_L01_0046FB40(pos, zero, 25, *(u32 *)(s + 0x40), 0, 127, 0, 0, small, big, 0.0f);
        if (p) p[2] = (*(u8 **)(D_L20_00220258 + 0x170))[5];
    }
    for (n = 1; n >= 0; n--) {
        p = func_L01_0046FB40(pos, zero, 25, *(u32 *)(s + 0x40), 0, 127, 0, 0, small, big, 0.0f);
        if (p) p[2] = (*(u8 **)(D_L20_00220258 + 0x170))[6];
    }
    ang = func_0038D160(D_L20_001E2E80[D_001D52F0].pos.x - ((f32 *)pos)[0],
                        D_L20_001E2E80[D_001D52F0].pos.y - ((f32 *)pos)[1]);

    for (n = 0; n < *(s32 *)(s + 0x20); n++) {
        r = (s32)func_L01_00443A18(2.0f, 5.0f);
        k = (D_L20_001DF338 + 1) % 44;
        v.x = ((f32 *)pos)[0] + D_L20_002C51D0[k] * 0.1f * scale;
        D_L20_001DF338 = k;
        k = (D_L20_001DF338 + 1) % 44;
        v.y = ((f32 *)pos)[1] + D_L20_002C51D0[k] * 0.1f * scale;
        D_L20_001DF338 = k;
        k = (D_L20_001DF338 + 1) % 44;
        v.z = ((f32 *)pos)[2] + D_L20_002C51D0[k] * 0.1f * scale;
        D_L20_001DF338 = k;
        w = func_003824E0(0.6f, 1.0f) * scale;
        sz = func_003824E0(9.0f, 12.0f) * scale;
        jit = func_L01_00443A18(0.0f, 1.3962634f);
        ang = func_0038DAB8(ang, jit);
        sz = sz * 0.020000001f;
        vel.x = func_0038D098(ang) * sz;
        vel.y = func_0038D0B0(ang) * sz;
        vel.z = 0.0f;
        sz = func_003824E0(0.0f, 12.0f) * scale;
        vel.z = sz * 0.020000001f;
        vec_add_ab(&vel, &vel, zero);
        life = (func_00382498(30, 50) * 5 + 2) / 6;
        p = func_L01_0046FB40(&v, &vel, life, *(u32 *)(s + 0x48), r, 127, 127, 1,
                              w * 210000.0f, scale * 0.01f * 210000.0f, 0.00584000023f);
        if (p) {
            p[3] = 0x44;
            p[2] = (*(u8 **)(D_L20_00220258 + 0xD4))[0];
        }
        r = -(r * 2);
        life = (func_00382498(30, 50) * 5 + 2) / 6;
        p = func_L01_0046FB40(&v, &vel, life, *(u32 *)(s + 0x4C), r, 48, 48, 0,
                              w * 6.0f * 210000.0f, scale * 0.02f * 210000.0f, 0.00584000023f);
        if (p) {
            p[3] = 0x44;
            p[2] = (*(u8 **)(D_L20_00220258 + 0xD4))[0];
        }
    }
    for (n = 0; n < *(s32 *)(s + 0x24); n++) {
        r = (s32)func_L01_00443A18(2.0f, 5.0f);
        k = (D_L20_001DF338 + 1) % 44;
        v.x = ((f32 *)pos)[0] + D_L20_002C51D0[k] * 0.1f * scale;
        D_L20_001DF338 = k;
        k = (D_L20_001DF338 + 1) % 44;
        v.y = ((f32 *)pos)[1] + D_L20_002C51D0[k] * 0.1f * scale;
        D_L20_001DF338 = k;
        k = (D_L20_001DF338 + 1) % 44;
        v.z = ((f32 *)pos)[2] + D_L20_002C51D0[k] * 0.1f * scale;
        D_L20_001DF338 = k;
        w = func_003824E0(0.75f, 1.5f) * scale;
        sz = func_003824E0(9.0f, 12.0f) * scale;
        jit = func_L01_00443A18(0.0f, 1.3962634f);
        ang = func_0038DAB8(ang, jit);
        sz = sz * 0.020000001f;
        vel.x = func_0038D098(ang) * sz;
        vel.y = func_0038D0B0(ang) * sz;
        vel.z = 0.0f;
        sz = func_003824E0(0.0f, 12.0f) * scale;
        vel.z = sz * 0.020000001f;
        vec_add_ab(&vel, &vel, zero);
        life = (func_00382498(30, 50) * 5 + 2) / 6;
        func_L01_0046FB40(&v, &vel, life, *(u32 *)(s + 0x50), r, 127, 127, 5,
                          w * 210000.0f, scale * 0.01f * 210000.0f, 0.00584000023f);
    }
    for (n = 0; n < *(s32 *)(s + 0x28); n++) {
        r = (s32)func_L01_00443A18(2.0f, 5.0f);
        k = (D_L20_001DF338 + 1) % 44;
        v.x = ((f32 *)pos)[0] + D_L20_002C51D0[k] * 0.1f * scale;
        D_L20_001DF338 = k;
        k = (D_L20_001DF338 + 1) % 44;
        v.y = ((f32 *)pos)[1] + D_L20_002C51D0[k] * 0.1f * scale;
        D_L20_001DF338 = k;
        k = (D_L20_001DF338 + 1) % 44;
        v.z = ((f32 *)pos)[2] + D_L20_002C51D0[k] * 0.1f * scale;
        D_L20_001DF338 = k;
        w = func_003824E0(0.6f, 1.0f) * scale;
        sz = func_003824E0(9.0f, 12.0f) * scale;
        jit = func_L01_00443A18(0.0f, 1.3962634f);
        ang = func_0038DAB8(ang, jit);
        sz = sz * 0.020000001f;
        vel.x = func_0038D098(ang) * sz;
        vel.y = func_0038D0B0(ang) * sz;
        vel.z = 0.0f;
        sz = func_003824E0(0.0f, 12.0f) * scale;
        vel.z = sz * 0.020000001f;
        vec_add_ab(&vel, &vel, zero);
        life = (func_00382498(30, 50) * 5 + 2) / 6;
        func_L01_0046FB40(&v, &vel, life, *(u32 *)(s + 0x54), r, 127, 127, 3,
                          w * 210000.0f, scale * 2100.0f, 0.00584000023f);
    }
    if (final > 0.0f) {
        *(vu0_q *)&v = *(vu0_q *)pos;
        v.w = scale * 3.0f;
        if (func_L01_00459590(&v, 0, 96.0f) > 0) {
            D_L20_002C5180[8] = final;
            D_L20_002C5180[9] = final;
            D_L20_002C5180[10] = final;
            func_L01_003006C0(D_L20_002C5180, pos, 0, 0);
        }
    }
    if (*(f32 *)(s + 0x6C) > 0.0f) func_L20_003EFFE0(obj, *(f32 *)(s + 0x6C));
}
