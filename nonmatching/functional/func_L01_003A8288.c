/* functional: medium. File's extern of func_003A52A0 should become s32 for cleanliness; 3 dead v3 writes in the no-motion branch are faithful to retail */
extern u8 *D_L01_001E001C;
extern u8 D_001A30B0[];
static __inline__ void stop_003A8288(s32 id, u8 *moby) {
    extern void func_003A4F28(int);
    if (id != -1) {
        u8 *entry = D_001A30B0 + (id << 7);
        if (*(u8 **)(entry + 0xDC) == moby && entry[0xD0]) func_003A4F28(id);
    }
}
void func_L01_003A8288(u8 *object, u8 *state) {
    extern s32 func_L01_003A8048(O_3A68C0 *o, S_3A68C0 *p);
    extern void func_0038CE20(void *, void *, f32);
    extern f32 func_0038CEA8(void *);
    extern void func_003C4360(f32 *, f32, f32, f32, f32);
    extern void func_0038CF68(u8 *, Vec4 *, f32);
    extern f32 func_0038CF00(void *, void *);
    extern f32 func_0038DAB8(f32, f32);
    extern void func_0038D308(void *, void *);
    extern f32 func_L01_0040E548(void *, void *);
    extern void func_003A52A0(s32, s32, void *);
    extern void func_003C7C38(void *);
    extern s32 func_L01_004AA710(void *, s32);
    Vec4 vectors[5];
    u8 *moby;
    Vec4 *origin, *position;
    s32 rotate, changed;
    vectors[0].q = *(u128_t *)(object + 0x10);
    vectors[1].q = *(u128_t *)(object + 0xF0);
    func_L01_003A8048((O_3A68C0 *)object, (S_3A68C0 *)state);
    moby = D_L01_001E001C + (*(s32 *)(state + 8) << 8);
    if (*(f32 *)(state + 0x10) != 0.0f || *(f32 *)(state + 0x14) != 0.0f || *(f32 *)(state + 0x18) != 0.0f) {
        rotate = 1;
        if (*(f32 *)(state + 0x28) == 0.0f && *(f32 *)(state + 0x2C) == 0.0f) {
            rotate = 0;
            if (*(f32 *)(state + 0x30) != 0.0f) rotate = 1;
        }
        origin = (Vec4 *)(state + 0x70);
        vectors[2].q = origin->q;
        if (*(s32 *)(state + 0x68)) {
            func_0038CE20(&vectors[4], state + 0x90, *(f32 *)(state + 0x10));
            __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                : "=m"(vectors[2]) : "m"(vectors[2]), "m"(vectors[4]) : "vf1", "vf2");
            func_0038CE20(&vectors[4], state + 0xA0, *(f32 *)(state + 0x14));
            __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                : "=m"(vectors[2]) : "m"(vectors[2]), "m"(vectors[4]) : "vf1", "vf2");
            func_0038CE20(&vectors[4], state + 0xB0, *(f32 *)(state + 0x18));
            __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                : "=m"(vectors[2]) : "m"(vectors[2]), "m"(vectors[4]) : "vf1", "vf2");
        }
        position = (Vec4 *)(object + 0x10);
        __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                : "=m"(vectors[4]) : "m"(vectors[2]), "m"(*position) : "vf1", "vf2");
        func_003C4360((f32 *)(state + 0x60), func_0038CEA8(&vectors[4]), *(f32 *)(state + 0x20) * 0.0004000000189989805f, *(f32 *)(state + 0x24) * 0.0004000000189989805f, *(f32 *)(state + 0x1C) * 0.020000001415610313f);
        func_0038CF68((u8 *)&vectors[4], &vectors[4], *(f32 *)(state + 0x60));
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                : "=m"(*position) : "m"(*position), "m"(vectors[4]) : "vf1", "vf2");
        if (rotate) {
            f32 length, fraction;
            vectors[4].f[0] = *(f32 *)(state + 0x10);
            vectors[4].f[1] = *(f32 *)(state + 0x14);
            vectors[4].f[2] = *(f32 *)(state + 0x18);
            length = func_0038CEA8(&vectors[4]);
            fraction = func_0038CF00(position, origin) / length;
            *(f32 *)(object + 0xF0) = func_0038DAB8(*(f32 *)(state + 0x80), *(f32 *)(state + 0x28) * fraction * 0.01745329238474369f);
            *(f32 *)(object + 0xF4) = func_0038DAB8(*(f32 *)(state + 0x84), *(f32 *)(state + 0x2C) * fraction * 0.01745329238474369f);
            *(f32 *)(object + 0xF8) = func_0038DAB8(*(f32 *)(state + 0x88), *(f32 *)(state + 0x30) * fraction * 0.01745329238474369f);
            func_0038D308(object + 0xC0, object + 0xF0);
        }
    } else {
        rotate = 1;
        vectors[3].q = *(u128_t *)(state + 0x80);
        if (*(s32 *)(state + 0x68)) {
            vectors[3].f[0] += *(f32 *)(state + 0x28);
            vectors[3].f[1] += *(f32 *)(state + 0x2C);
            vectors[3].f[2] += *(f32 *)(state + 0x30);
        }
    }
    changed = 0;
    if (rotate && func_L01_0040E548(&vectors[1], object + 0xF0) > 3.0461741573617473e-08f) changed = 1;
    else if (func_L01_0040E548(&vectors[0], object + 0x10) > 1.0000001111620804e-06f) changed = 1;
    if (changed) {
        if (*(s16 *)(moby + 0xAA) == 0x1C28 && !*(s32 *)(state + 0x58)) {
            s32 id = *(s32 *)(state + 0xD0);
            u8 *entry = D_001A30B0 + (id << 7);
            if (id == -1 || *(u8 **)(entry + 0xDC) != moby || !entry[0xD0]) {
                *(s32 *)(state + 0xD0) = ((s32 (*)(s32, s32, void *))func_003A52A0)(0, 4, moby);
            }
        }
        *(u128_t *)(moby + 0x10) = *(u128_t *)(object + 0x10);
        if (rotate) {
            *(u128_t *)(moby + 0xF0) = *(u128_t *)(object + 0xF0);
            func_0038D308(moby + 0xC0, moby + 0xF0);
        }
        func_003C7C38(moby);
        if (*(unsigned long *)(state + 0x48) == 0) return;
        if (*(s32 *)(state + 0x68)) {
            if (*(s32 *)(state + 0x40) >= 0 && *(s32 *)(state + 0x48) && !func_L01_004AA710(moby, *(s32 *)(state + 0x50))) {
                *(s32 *)(state + 0x50) = ((s32 (*)(s32, s32, void *))func_003A52A0)(*(s32 *)(state + 0x40), 4, moby);
            }
            stop_003A8288(*(s32 *)(state + 0x54), moby);
            *(s32 *)(state + 0x54) = -1;
        } else {
            if (*(s32 *)(state + 0x44) >= 0 && *(s32 *)(state + 0x4C) && !func_L01_004AA710(moby, *(s32 *)(state + 0x54))) {
                *(s32 *)(state + 0x54) = ((s32 (*)(s32, s32, void *))func_003A52A0)(*(s32 *)(state + 0x44), 4, moby);
            }
            stop_003A8288(*(s32 *)(state + 0x50), moby);
            *(s32 *)(state + 0x50) = -1;
        }
    } else {
        stop_003A8288(*(s32 *)(state + 0x54), moby);
        *(s32 *)(state + 0x54) = -1;
        stop_003A8288(*(s32 *)(state + 0x50), moby);
        *(s32 *)(state + 0x50) = -1;
        stop_003A8288(*(s32 *)(state + 0xD0), moby);
        *(s32 *)(state + 0xD0) = -1;
    }
}
