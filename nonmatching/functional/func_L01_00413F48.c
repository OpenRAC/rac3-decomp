/* functional: high. Auto-aim/lock-on target selection: picks up to 16 candidates from the object list (D_L01_0021E860) scored by distance and facing, ray-checks from nearest-scored backwards, stores the pick at +0x8C/+0xB0 and its motion delta at +0xA0. VU0 vector ops written as xyz float ops keeping w of the first operand. */
typedef struct {
    f32 x, y, z, w;
} V4_00413F48;

extern u8 D_L01_001EAA00[];
extern u8 D_L01_001E2A40[];
extern u8 *D_L01_0021E860[];

extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_0038D000(void *, void *, void *);
extern f32 func_0038CEA8(void *);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038D098(f32);
extern u8 *func_00382348(void *);
extern s32 func_003C4B50(void *);

void func_L01_00413F48(u8 *a0) {
    V4_00413F48 v190, v1A0, v1B0, v1C0, v0;
    V4_00413F48 pos[16];
    u8 *list[16];
    f32 t[16];
    u8 *prev;
    u8 *hitobj;
    u8 *o;
    u8 **pp;
    u8 *r;
    s32 n;
    s32 i;
    f32 f22, f20, f21, f23, fd;
    s32 owner;

    if (*(void (**)(u8 *))(a0 + 0xE4) != 0) {
        (*(void (**)(u8 *))(a0 + 0xE4))(a0);
        return;
    }
    prev = *(u8 **)(a0 + 0x8C);
    *(s32 *)(a0 + 0x8C) = 0;
    *(s32 *)(a0 + 0xB0) = 0;
    func_0038CF68(&v0, a0, *(f32 *)(a0 + 0x120));
    v0.x = v0.x + *(f32 *)(a0 + 0x30);
    v0.y = v0.y + *(f32 *)(a0 + 0x34);
    v0.z = v0.z + *(f32 *)(a0 + 0x38);
    if (func_003D3CB0(a0 + 0x30, &v0, 0, *(void **)(a0 + 0xBC), 0)) {
        hitobj = *(u8 **)(D_L01_001EAA00 + 0x18);
        if (hitobj != 0 && *(u8 **)(hitobj + 0x24) != 0 && *(*(u8 **)(hitobj + 0x24) + 0x46) == 5) {
            s32 cls = *(s16 *)(hitobj + 0xAA);
            if (cls != 0x19C0 && cls != 0x1AE6) {
                *(u8 **)(a0 + 0x8C) = hitobj;
                *(f32 *)(a0 + 0xB0) = 1.0f;
            }
        }
        *(V4_00413F48 *)(a0 + 0x110) = *(V4_00413F48 *)(D_L01_001EAA00 + 0x20);
    } else {
        *(V4_00413F48 *)(a0 + 0x110) = v0;
    }
    if (*(u8 **)(a0 + 0x8C) == 0) {
        n = 0;
        fd = *(f32 *)(D_L01_001E2A40 + *(s32 *)(a0 + 0x12C) * 0x460 + 0x424) / 1.1100293f;
        f22 = func_0038D098(*(f32 *)(a0 + 0x7C) * fd);
        f23 = 37000000.0f;
        pp = D_L01_0021E860;
        o = *pp;
        while (o != 0) {
            if (*(u8 *)(o + 0x31) != 0 && *(u8 **)(o + 0x24) != 0 && *(*(u8 **)(o + 0x24) + 0x46) == 5
                && *(s32 *)(o + 0x98) != 0 && o != *(u8 **)(a0 + 0xBC)
                && *(s16 *)(o + 0xAA) != 0x19C0 && *(s16 *)(o + 0xAA) != 0x1AE6) {
                r = func_00382348(o);
                if (r != 0) {
                    v1A0.x = 0.0f;
                    v1A0.y = 0.0f;
                    v1A0.z = 0.0f;
                    v1A0.w = 0.0f;
                    v1A0.z = *(f32 *)(r + 0x10);
                    v190 = v1A0;
                    func_0038D000(&v190, &v190, o + 0xC0);
                    v1C0 = v190;
                    v1B0 = *(V4_00413F48 *)(a0 + 0x30);
                    v190.x = v1C0.x + *(f32 *)(o + 0x10);
                    v190.y = v1C0.y + *(f32 *)(o + 0x14);
                    v190.z = v1C0.z + *(f32 *)(o + 0x18);
                    v190.w = v1C0.w;
                    v1A0.x = v190.x - v1B0.x;
                    v1A0.y = v190.y - v1B0.y;
                    v1A0.z = v190.z - v1B0.z;
                    v1A0.w = v190.w;
                    f20 = func_0038CEA8(&v1A0);
                    if (!(*(f32 *)(a0 + 0x120) < f20)) {
                        f21 = 1.0f;
                        func_0038CE20(&v1A0, &v1A0, f21 / f20);
                        fd = func_0038CE68(&v1A0, a0);
                        if (!(fd < f22)) {
                            f21 = (fd - f22) / (f21 - f22);
                            f20 = f20 + f20 * f21;
                            if (func_003C4B50(o) != 0) {
                                f20 = f20 + 10.0f;
                            }
                            if (f20 < f23) {
                                f23 = f20;
                                i = n;
                                n = n + 1;
                                list[i] = o;
                                pos[i] = v190;
                                t[i] = f21;
                                if (n >= 16) {
                                    break;
                                }
                            }
                        }
                    }
                }
            }
            pp = pp + 1;
            o = *pp;
        }
        for (i = n - 1; i >= 0; i--) {
            if (func_003D3CB0(a0 + 0x30, &pos[i], 0, *(void **)(a0 + 0xBC), 0) == 0
                || *(u8 **)(D_L01_001EAA00 + 0x18) == list[i]) {
                *(f32 *)(a0 + 0xB0) = t[i];
                *(u8 **)(a0 + 0x8C) = list[i];
                break;
            }
        }
        if (*(u8 **)(a0 + 0x8C) == 0) {
            *(V4_00413F48 *)(a0 + 0xA0) = (V4_00413F48){0.0f, 0.0f, 0.0f, 0.0f};
            return;
        }
    }
    r = *(u8 **)(a0 + 0x8C);
    if (r == prev) {
        V4_00413F48 *tp = (V4_00413F48 *)(r + 0x10);
        V4_00413F48 *cu = (V4_00413F48 *)(a0 + 0x90);
        V4_00413F48 *dp = (V4_00413F48 *)(a0 + 0xA0);
        dp->x = tp->x - cu->x;
        dp->y = tp->y - cu->y;
        dp->z = tp->z - cu->z;
        dp->w = tp->w;
    }
    *(V4_00413F48 *)(a0 + 0x90) = *(V4_00413F48 *)(*(u8 **)(a0 + 0x8C) + 0x10);
}
