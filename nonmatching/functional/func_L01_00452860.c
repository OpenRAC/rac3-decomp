/* functional: high. Ported from the (byte-exact) NTSC-U draft shape and re-read against PAL's assembly: PAL differs in the 251 (0xFB) frame threshold and in the (rand*5+2)/6 spark lifetime argument. Plain C, no inline vector asm. */
typedef union { u8 b[0x1B0]; u8 *ptr[0x6C]; } T_00452860;
extern T_00452860 D_L01_00221098;
extern u8 D_L01_001D66B0[];
extern u8 D_70000000[];
extern u8 *func_L01_00449020(void *);
extern s32 func_0038CAD0(void *);
extern f32 func_003824E0(f32, f32);
extern void func_L01_00446748(void *, void *, s32, f32);
extern void func_L01_00446978(void *, void *);
extern s32 func_003C2B88(void *, s32);
extern s32 func_00382468(s32);
extern void func_00382580(void *, f32, f32);
extern s32 func_00382498(s32, s32);
extern u8 *func_L01_004637C8(void *, void *, u32, u32, s32, s32, s32, s32);
extern s32 func_L01_00447938(void *, s32, void *, s32, f32);
extern void func_L01_004C7D98(void *, void *);
extern void func_0038CDF8(void *, void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);

typedef struct { f32 x, y, z, w; } V4_00452860;

s32 func_L01_00452860(u8 *self, u8 *e, u8 *o) {
    V4_00452860 a;
    V4_00452860 b;
    V4_00452860 c;
    V4_00452860 arr[10];
    u8 *p;
    u8 *sc;
    u8 *r;
    s32 n;
    s32 i;
    s32 k;
    f32 f;

    if (e == 0) {
        return 0;
    }
    if (self == 0) {
        return 0;
    }
    p = func_L01_00449020(self);
    if (p == 0 && o == 0) {
        return 0;
    }
    if (o != 0) {
        p = o;
    }
    if (e[0x2F] == 0) {
        return 1;
    }
    *(u16 *)(p + 0x1E) = *(u16 *)(p + 0x1E) + 1;
    if (func_0038CAD0(e + 0x38) != 0) {
        *(u16 *)(p + 0x1E) = 0;
        e[0x35] = 1;
        e[0x2F] = 0;
    }
    if (*(u8 **)(p + 0x10) != 0 && *(s16 *)(*(u8 **)(p + 0x10) + 0xAA) != 0 && *(s16 *)(p + 0x16) == 0) {
        *(s16 *)(p + 0x16) = 1;
    }
    if (*(s16 *)(p + 0x16) > 0 || (*(u8 **)(p + 0x10) != 0 && *(s16 *)(*(u8 **)(p + 0x10) + 0xAA) == 0)) {
        *(u16 *)(p + 0x16) = *(u16 *)(p + 0x16) + 1;
    }
    if (0.0f < *(f32 *)e) {
        if (*(u8 **)(p + 0x10) != 0 && *(s16 *)(*(u8 **)(p + 0x10) + 0xAA) == 0) {
            f = (f32)*(s16 *)(p + 0x16);
            if ((func_003824E0(90.0f, 150.0f) * 5.0f + 2.0f) / 6.0f < f) {
                func_L01_00446748(&a, self, 0x10000, 1500.0f);
                func_L01_00446978(self, &a);
            }
        }
        if (*(f32 *)e <= 1.0f) {
            func_L01_00446748(&a, self, 0x10000, 1500.0f);
            func_L01_00446978(self, &a);
        }
        if (*(s16 *)(p + 0x1E) >= 0xFB) {
            *(f32 *)e = *(f32 *)e - (f32)*(s16 *)(e + 4) * 0.002f;
        }
    } else {
        func_L01_00446748(&a, self, 0x10000, 1500.0f);
        func_L01_00446978(self, &a);
    }
    n = func_003C2B88(self, 0);
    if (n != 0) {
        sc = D_70000000;
        for (i = 0; i < n; i++, sc += 0x20) {
            if (func_00382468(2) == 0) {
                continue;
            }
            if (*(f32 *)(sc + 0x1C) == 0.0f) {
                a = *(V4_00452860 *)sc;
                a.w = 1.0f;
                func_00382580(&b, 0.0f, *(f32 *)(sc + 0xC));
                a.x = a.x + b.x;
                a.y = a.y + b.y;
                a.z = a.z + b.z;
                r = func_L01_004637C8(&a, D_L01_001D66B0, 0x3005A182, 0x5A182, (func_00382498(10, 0x12) * 5 + 2) / 6, 0x4B, 0x78, 1);
            } else {
                a = *(V4_00452860 *)sc;
                b = *(V4_00452860 *)(sc + 0x10);
                a.w = 1.0f;
                b.w = 1.0f;
                func_0038CDF8(&c, &a, &b, func_003824E0(0.0f, 1.0f));
                c.x = c.x + func_003824E0(-*(f32 *)(sc + 0xC) * 0.4f, *(f32 *)(sc + 0xC) * 0.4f);
                c.y = c.y + func_003824E0(-*(f32 *)(sc + 0xC) * 0.4f, *(f32 *)(sc + 0xC) * 0.4f);
                c.z = c.z + func_003824E0(-*(f32 *)(sc + 0xC) * 0.4f, *(f32 *)(sc + 0xC) * 0.4f);
                r = func_L01_004637C8(&c, D_L01_001D66B0, 0x3005A182, 0x5A182, (func_00382498(10, 0x12) * 5 + 2) / 6, 0x4B, 0x78, 1);
            }
            if (r != 0) {
                r[3] = 0x44;
                k = func_00382468(4);
                if (k == 0) {
                    r[2] = *D_L01_00221098.ptr[0x5C / 4];
                } else if (k == 1) {
                    r[2] = *D_L01_00221098.ptr[0x1A4 / 4];
                } else {
                    r[2] = *D_L01_00221098.ptr[0x88 / 4];
                }
            }
        }
        return 1;
    }
    n = func_L01_00447938(self, 10, arr, 0xFFFF, 7.0f);
    if (n > 0) {
        for (i = 0; i < n; i++) {
            func_L01_004C7D98(self + 0x10, &a);
            func_0038CE20(&a, &a, func_003824E0(-0.05f, 0.05f));
            r = func_L01_004637C8(&arr[i], &a, 0x3005A182, 0x5A182, (func_00382498(10, 0x19) * 5 + 2) / 6, 0x2D, 0x5A, 1);
            if (r != 0) {
                r[3] = 0x44;
                k = func_00382468(4);
                if (k == 0) {
                    r[2] = *D_L01_00221098.ptr[0x5C / 4];
                } else if (k == 1) {
                    r[2] = *D_L01_00221098.ptr[0x1A4 / 4];
                } else {
                    r[2] = *D_L01_00221098.ptr[0x88 / 4];
                }
            }
        }
    }
    return 1;
}
