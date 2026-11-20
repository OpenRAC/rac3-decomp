/* functional: high. Auto-aim/lock-on target selection: picks up to 16 candidates from the object list (D_L01_0021E860) scored by distance and facing, ray-checks from nearest-scored backwards, stores the pick at +0x8C/+0xB0 and its motion delta at +0xA0. VU0 vector ops kept as VU0 ops (asm blocks, fixed vf1/vf2), since the FPU rounds differently; candidate position w is the object's (retail's vadd.xyz keeps vf1 = o+0x10's w, the earlier draft kept the transformed offset's). Data refs it forms that retail does not (D_L01_001E2A40+0x424 folded) are the same table entry reached another way. */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_00413F48;

/* d.xyz = a.xyz + b.xyz, d.w = a.w (lqc2, lqc2, vadd.xyz, sqc2): VU0 rounds differently from the FPU,
 * so the vector ops stay VU0 ops; one asm block with fixed vf1/vf2 (the level file has no "j" class) */
static void vadd_00413F48(void *d, void *a, void *b) {
    __asm__ __volatile__("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
                         : : "r"(d), "r"(a), "r"(b) : "memory");
}
/* d.xyz = a.xyz - b.xyz, d.w = a.w */
static void vsub_00413F48(void *d, void *a, void *b) {
    __asm__ __volatile__("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
                         : : "r"(d), "r"(a), "r"(b) : "memory");
}

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
    vadd_00413F48(&v0, &v0, a0 + 0x30);
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
                    /* retail: vadd.xyz vf1, vf2(v1C0), vf1(o+0x10): w is the object's position w */
                    vadd_00413F48(&v190, o + 0x10, &v1C0);
                    vsub_00413F48(&v1A0, &v190, &v1B0);
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
        vsub_00413F48(a0 + 0xA0, r + 0x10, a0 + 0x90);
    }
    *(V4_00413F48 *)(a0 + 0x90) = *(V4_00413F48 *)(*(u8 **)(a0 + 0x8C) + 0x10);
}
