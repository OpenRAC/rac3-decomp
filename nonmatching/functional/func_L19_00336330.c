/* functional: medium. Per-frame rebuild of the 4 ribbon point strips of the Thran beam/trail object: advances the texture scroll and wave phases, then per strip either copies points from a template table (D_0021D500) and bends them toward the player when within range, or generates a straight strip along a fixed direction; finally builds the second table (D_00277340) with width, sine-wave and noise offsets for the interior points. VU0 xyz-masked vector adds/subs are static helpers (w from first operand). Sine/cos assignment of func_0038D0B0/D098 and the wrap function func_0038DAB8 taken from the catalogue callers; float constants decoded from retail hex. */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_00336330;
/* d = a (op) b on x,y,z; w comes from a, as the VU0 xyz-masked ops leave it */
static void v3add_00336330(void *d, void *a, void *b) {
    V4_00336330 r = *(V4_00336330 *)a;
    r.x = r.x + ((V4_00336330 *)b)->x;
    r.y = r.y + ((V4_00336330 *)b)->y;
    r.z = r.z + ((V4_00336330 *)b)->z;
    *(V4_00336330 *)d = r;
}
static void v3sub_00336330(void *d, void *a, void *b) {
    V4_00336330 r = *(V4_00336330 *)a;
    r.x = r.x - ((V4_00336330 *)b)->x;
    r.y = r.y - ((V4_00336330 *)b)->y;
    r.z = r.z - ((V4_00336330 *)b)->z;
    *(V4_00336330 *)d = r;
}
extern u8 *D_0021D500[];
extern u8 D_L19_00276F40[];
extern u8 D_L19_00276E40[];
extern u8 D_L19_00277340[];
extern u8 D_1A4C60[];
extern f32 func_0038DAB8(f32, f32);
extern f32 func_L01_0044AE78(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D160(f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CEA8(void *);

void func_L19_00336330(u8 *obj) {
    u8 *pv = *(u8 **)(obj + 0x68);
    V4_00336330 v0, v10, v20, v30, v40, v50;
    f32 f, len24, wt, dist, d1, len, t, t20, t22, t23, ang, c;
    s32 k, j, m, n, row;
    u8 *src;

    *(f32 *)(pv + 0x94) = func_0038DAB8(*(f32 *)(pv + 0x94), *(f32 *)(pv + 0x98));
    *(f32 *)(pv + 0xA8) = func_0038DAB8(*(f32 *)(pv + 0xA8), *(f32 *)(pv + 0x98));
    f = *(f32 *)(pv + 0x84) + *(f32 *)(pv + 0x88);
    *(f32 *)(pv + 0x84) = f;
    if (1.0f < f) {
        *(f32 *)(pv + 0x84) = f - 1.0f;
    }
    for (k = 0; k < 4; k++) {
        if ((*(s32 *)(pv + 0x3C) & 1) && *(s32 *)(pv + 0x28 + k * 4) >= 0) {
            src = D_0021D500[*(s32 *)(pv + 0x28 + k * 4)];
            for (j = 0; j < *(s32 *)(pv + 0x38); j++) {
                *(V4_00336330 *)(D_L19_00276F40 + (((*(s32 *)(pv + 0xDC) + k) << 8) + j * 16)) = *(V4_00336330 *)(src + 0x10 + j * 16);
            }
            if (*(s32 *)(pv + 0x3C) & 8) {
                v3sub_00336330(&v0, D_1A4C60, pv + 0xE0);
                dist = func_0038CEA8(&v0);
                func_0038CF68(&v0, &v0, 1.1f);
                d1 = *(f32 *)(pv + 0xD4);
                if (d1 + 1.1f < dist) {
                    continue;
                }
                wt = 1.0f - (dist - 1.1f) / d1;
                for (j = 0; j < *(s32 *)(pv + 0x38); j++) {
                    u8 *p = D_L19_00276F40 + (((*(s32 *)(pv + 0xDC) + k) << 8) + j * 16);
                    v10 = *(V4_00336330 *)p;
                    v3sub_00336330(&v10, &v10, pv + 0xE0);
                    len = func_0038CEA8(&v10);
                    if (1.1f < len) {
                        len = 1.1f;
                    }
                    t = wt * (1.0f - len / 1.1f);
                    func_0038CE20(&v20, &v0, t);
                    func_0038CE20(&v10, &v10, 1.0f - t);
                    v3add_00336330(&v20, &v20, &v10);
                    v3add_00336330(p, &v20, pv + 0xE0);
                }
            }
            continue;
        }
        v30.x = 0.0f;
        v30.y = 0.0f;
        v30.z = 0.0f;
        v30.w = 1.0f;
        if (k == 1) {
            v30.z = v30.z - 0.6395349f;
            v30.y = v30.y - 0.6395349f;
            v30.x = v30.x - 0.6395349f;
        } else if (k == 0) {
            v30.z = v30.z + 1.1f;
        } else if (k == 2) {
            v30.z = v30.z - 0.6395349f;
            v30.y = v30.y - 0.6395349f;
            v30.x = v30.x + 0.6395349f;
        } else {
            v30.z = v30.z - 0.6395349f;
            v30.y = v30.y + 0.7857143f;
        }
        for (j = 0; j < *(s32 *)(pv + 0x38); j++) {
            u8 *p = D_L19_00276F40 + (((*(s32 *)(pv + 0xDC) + k) << 8) + j * 16);
            func_0038CF68(&v40, &v30, (f32)j / ((f32)*(s32 *)(pv + 0x38) - 0.5f));
            *(V4_00336330 *)p = v40;
            v3add_00336330(p, p, pv + 0xE0);
        }
    }
    row = *(s32 *)(pv + 0xDC) << 8;
    v3sub_00336330(&v30, D_L19_00276F40 + row + 0x10, D_L19_00276F40 + row);
    len24 = func_0038CEA8(&v30);
    for (j = 0; j < *(s32 *)(pv + 0x38); j++) {
        t23 = 0.0f;
        t22 = 0.0f;
        if (!(*(s32 *)(pv + 0x3C) & 0x40)) {
            func_0038CE20(&v50, D_L19_00276E40 + j * 16, *(f32 *)(pv + 0x90) * len24);
        }
        if (!(*(s32 *)(pv + 0x3C) & 0x80)) {
            f32 fj = (f32)j;
            c = func_0038D0B0(func_L01_0044AE78(*(f32 *)(pv + 0x94) + fj * -1.7802358f));
            t20 = *(f32 *)(pv + 0xA0) * c;
            t22 = func_L01_0044AE78(*(f32 *)(pv + 0xA8) + fj * -1.5184364f);
            t20 = t20 * func_0038D0B0(t22);
            t23 = len24 * t20;
        }
        if (!(*(s32 *)(pv + 0x3C) & 0x100)) {
            ang = func_0038DAB8(func_0038D160(v30.x, v30.y), 1.5707964f);
            t20 = len24 * *(f32 *)(pv + 0xA4) * func_0038D098(t22);
            v40.x = func_0038D098(ang) * t20;
            v40.y = func_0038D0B0(ang) * t20;
            v40.z = 0.0f;
        }
        for (m = 0; m < 4; m++) {
            row = ((*(s32 *)(pv + 0xDC) + m) << 8) + j * 16;
            *(V4_00336330 *)(D_L19_00277340 + row) = *(V4_00336330 *)(D_L19_00276F40 + row);
            if (j == 0) {
                continue;
            }
            if (j == *(s32 *)(pv + 0x38) - 1) {
                continue;
            }
            if (!(*(s32 *)(pv + 0x3C) & 0x40)) {
                v3add_00336330(D_L19_00277340 + row, D_L19_00277340 + row, &v50);
                v3add_00336330(D_L19_00276F40 + row, D_L19_00276F40 + row, &v50);
            }
            if (!(*(s32 *)(pv + 0x3C) & 0x80)) {
                *(f32 *)(D_L19_00277340 + row + 8) = *(f32 *)(D_L19_00277340 + row + 8) + t23;
            }
            if (!(*(s32 *)(pv + 0x3C) & 0x100)) {
                v3add_00336330(D_L19_00277340 + row, D_L19_00277340 + row, &v40);
            }
        }
    }
}
