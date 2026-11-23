/* functional: high. Camera collision push-in: orbits a ring of 15 sample segments around the target at a shrinking radius (up to 4 rings) until none is blocked by func_003D3CB0; VU0 add/sub as xyz float ops. */
typedef struct {
    f32 x, y, z, w;
} V4_00418618;

extern u8 D_001D5474[];
extern u8 D_L01_001D66B0[];
extern u8 D_L01_001EA760[];
extern V4_00418618 D_L01_001E29C0;
extern V4_00418618 D_001A4C60;

extern s32 func_003E3DF0(void);
extern void func_L01_004C7D98(void *, void *);
extern s32 func_L01_00513EF0(void);
extern void func_L01_00510AD0(void);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038CEA8(void *);
extern f32 func_0038DB48(f32);
extern void func_0038D890(void *, void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);

void func_L01_00418618(void) {
    V4_00418618 v00, v10, v20, v30;
    u8 *s;
    u8 *cam;
    f32 f20, f12;
    s32 i, k;

    if (func_003E3DF0() == 0) {
        return;
    }
    if (D_001D5474[0] == 0) {
        return;
    }
    s = D_L01_001EA760;
    *(f32 *)(s + 0x44) = -*(f32 *)(s + 0x44);
    *(s32 *)(s + 0x48) = 0;
    *(V4_00418618 *)s = *(V4_00418618 *)D_L01_001D66B0;
    if (*(f32 *)(s + 0x44) == *(f32 *)(s + 0x48)) {
        *(f32 *)(s + 0x44) = 1.0f;
    }
    *(s32 *)(s + 0x50) = 0;
    func_L01_004C7D98(&D_001A4C60, s + 0x30);
    if (func_L01_00513EF0() == 2) {
        cam = *(u8 **)((u8 *)&D_001A4C60 + 0x2540);
        func_0038CF68(&v00, cam + 0xC0, -4.0f);
        D_L01_001E29C0.x = D_L01_001E29C0.x + v00.x;
        D_L01_001E29C0.y = D_L01_001E29C0.y + v00.y;
        D_L01_001E29C0.z = D_L01_001E29C0.z + v00.z;
        func_L01_00510AD0();
    }
    v00.x = D_001A4C60.x - D_L01_001E29C0.x;
    v00.y = D_001A4C60.y - D_L01_001E29C0.y;
    v00.z = D_001A4C60.z - D_L01_001E29C0.z;
    v00.w = D_001A4C60.w;
    f12 = func_0038CE68((u8 *)&D_L01_001E29C0 + 0x20, &v00);
    func_0038CF68(s, (u8 *)&D_L01_001E29C0 + 0x20, f12);
    f20 = func_0038CEA8(s);
    {
        V4_00418618 *sv = (V4_00418618 *)s;
        sv->x = sv->x + D_L01_001E29C0.x;
        sv->y = sv->y + D_L01_001E29C0.y;
        sv->z = sv->z + D_L01_001E29C0.z;
    }
    *(V4_00418618 *)(s + 0x10) = *(V4_00418618 *)s;
    *(f32 *)(s + 0x40) = f20;
    i = 0;
    do {
        V4_00418618 *p10 = (V4_00418618 *)(s + 0x10);
        f12 = f20 * (1.0f - (f32)i / 7.0f);
        *(f32 *)(s + 0x54) = f12;
        v30.x = D_L01_001E29C0.x - p10->x;
        v30.y = D_L01_001E29C0.y - p10->y;
        v30.z = D_L01_001E29C0.z - p10->z;
        v30.w = D_L01_001E29C0.w;
        func_0038CF68(&v30, &v30, f12);
        *(s32 *)(s + 0x50) = 0;
        k = 0;
        do {
            f12 = func_0038DB48((f32)k * 6.2831855f / 15.0f);
            k = k + 1;
            func_0038D890(&v10, &v30, s + 0x30, f12);
            v10.x = v10.x + p10->x;
            v10.y = v10.y + p10->y;
            v10.z = v10.z + p10->z;
            f12 = func_0038DB48((f32)k * 6.2831855f / 15.0f);
            func_0038D890(&v20, &v30, s + 0x30, f12);
            v20.x = v20.x + p10->x;
            v20.y = v20.y + p10->y;
            v20.z = v20.z + p10->z;
            if (func_003D3CB0(&v10, &v20, 0x80, 0, 0)) {
                *(s32 *)(s + 0x50) = 1;
                break;
            }
        } while (k < 15);
        i = i + 1;
        if (*(s32 *)(s + 0x50) == 0) {
            break;
        }
    } while (i < 4);
}
