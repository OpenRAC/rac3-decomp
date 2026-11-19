/* functional: medium. 271 words differ; same frame size as retail. Float constants taken bit-exact from the asm. */
extern u8 D_002428C0[];
extern u8 D_001A4BE0[];
extern u8 *D_001D52FC;
extern f32 D_L03_001DEED0;
extern f32 D_L03_001DEED4;
extern f32 D_L03_001DEED8;
__asm__(".extern D_L03_001DEED0, 16");
__asm__(".extern D_L03_001DEED4, 16");
__asm__(".extern D_L03_001DEED8, 16");
extern void func_L01_00450DE8(void *, f32, f32, f32, void *);
extern f32 func_L01_0040E570(void *, void *);
extern void func_L01_00452560(s32, s32, s32, s32, s32, s32, s32);
extern void func_003A0EC0(s32, s32, s32, s32, s32);
extern s32 func_L01_004561B8(void *);
extern s32 func_0038CAD0(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_00443B88(void *, f32, f32);
extern f32 func_0038CED8(void *);
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern u8 *func_L03_00458A70(void *, void *, f32, s32, s32, s32);
extern void func_L01_00451DB8(void *, void *, s32, s32, f32);
extern void func_L03_003C8F78(void *);

void func_L03_003C8AC0(u8 *m) {
    u8 *s = *(u8 **)(m + 0x68);
    vu0_v4 pos;
    vu0_v4 vel;
    vu0_v4 tmp;
    u8 *h;
    s32 n;
    s32 r;
    s32 g;
    s32 b;
    s32 col;
    s32 life;
    f32 len;
    f32 size;
    f32 rv;
    f32 r2;
    f32 r3;
    f32 r4;
    s32 st = m[0x20];

    if (st == 1) {
        func_L01_00450DE8(m, D_L03_001DEED0, D_L03_001DEED4, D_L03_001DEED8, &tmp);
        h = D_001A4BE0;
        if (h[0x25E4] == 0 && *(s16 *)(h + 0x288C) == 0
            && func_L01_0040E570(&tmp, h + 0x80) < 1.44000006f
            && *(s32 *)(h + 0x360) != 0
            && *(f32 *)(h + 0x98) > -3.14159274f && *(f32 *)(h + 0x98) < 0.0f) {
            func_L01_00452560(0, 1, 0x8BC, 1, 0, 0, 0);
            if (*(s32 *)(D_001D52FC + 0x1A4) & 0x10) {
                func_003A0EC0(5, 1, 2, 0, 0);
            }
        }
        if (*(s32 *)(D_002428C0 + 0x76C) != 0) {
            *(s32 *)(D_002428C0 + 0x76C) = 0;
            func_L01_004450F0(m, 2, -1);
        }
    } else if (st == 0) {
        func_L01_004450F0(m, 1, -1);
    } else if (st == 2) {
        if (func_L01_004561B8(m) != 0) {
            n = 0x1E;
            *(s32 *)s = 0x64;
        } else {
            n = 5;
            if (func_0038CAD0(s) != 0) {
                func_L01_004450F0(m, 1, -1);
            }
        }
        while (n != 0) {
            func_L01_00443B88(&vel, 0.0200000014f, 0.0400000028f);
            len = func_0038CED8(&vel);
            if (func_00382468(2) != 0) {
                rv = func_003824E0(-3.0f, 3.0f);
                r2 = func_003824E0(0.300000012f, 1.0f);
                pos.x = rv + r2 * vel.x / len + 2.4000001f;
                r2 = func_003824E0(0.300000012f, 1.0f);
                pos.y = r2 * vel.y / len + -1.39999998f;
            } else {
                r2 = func_003824E0(0.300000012f, 1.0f);
                pos.x = r2 * vel.x / len + 2.4000001f;
                rv = func_003824E0(-0.5f, 3.0f);
                r3 = func_003824E0(-0.5f, 4.0f);
                r4 = func_003824E0(0.300000012f, 1.0f);
                pos.y = rv + r3 + r4 * vel.y / len;
            }
            n--;
            pos.z = func_003824E0(0.5f, 3.0f);
            vec_add_ab(&pos, &pos, m + 0x10);
            r = func_00382468(0x7F);
            g = func_00382468(0x7F);
            b = func_00382468(0x7F);
            col = func_0038DBD8((r << 16) | (g << 8) | 0x7F000000 | b, 0x7FB0B0B0, 0.800000012f);
            size = func_003824E0(1.20000005f, 2.4000001f);
            life = (func_00382498(0x1E, 0x50) * 5 + 2) / 6;
            func_L03_00458A70(&pos, &vel, size, life, func_00382498(-4, 4), col);
        }
    }
    if (m[0x31] != 0) {
        func_L01_00451DB8(m, s + 4, 0x7FA0A0A0, 0x7F505050, 0.167551622f);
    }
    func_L03_003C8F78(m);
}
