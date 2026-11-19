/* functional: high. Per-frame update of a scripted mover (obj+0x70 data block): blends/clamps its pose by mode (1/4 copy keyframe, 2 timed blend, 3 timed blend with angle wrap against the per-player D_001E2B90 table, else clamp to limits), then rebuilds the matrix; calls, branches and stores mirror retail */
typedef struct { u8 pad[0x20]; u8 b20; } Base_003EBA68;
typedef struct { u8 pad[28]; Base_003EBA68 *p1C; } Row_003EBA68;
extern Row_003EBA68 *D_L01_001DF804;
extern u8 D_L01_001E2A40[];
extern s32 func_0038CAD0(void *);
extern void func_L01_00445438(void *, void *, void *, f32);
extern void func_L01_00445510(void *, void *, void *, f32);
extern s32 func_L01_003F5FC0(void *, void *, void *);
extern f32 func_0038DB00(f32, f32);
extern f32 func_003C3BE8(f32, f32, f32);
extern f32 func_L01_004453B8(f32, f32, f32);
extern f32 func_L01_004451D0(f32, f32, f32, f32, f32);
extern void func_L01_003F5F10(f32 *, f32 *, void *);
extern f32 func_00382BC8(f32 *, f32, f32, f32, f32, f32);
extern f32 func_00382C58(f32 *, f32, f32, f32, f32, f32);
extern void func_L01_00404AD8(void *, void *);
extern void func_L01_003EB750(void);
void func_L01_003EBA68(u8 *a0) {
    f32 mtx[16];
    u8 *data = *(u8 **)(a0 + 0x70);
    u8 *dd = data + 0xE0;
    u8 *q30 = a0 + 0x30;
    u8 *q40 = a0 + 0x40;
    u8 *q80 = data + 0x80;
    u8 *q30d = data + 0x30;
    Base_003EBA68 *base = D_L01_001DF804[*(s16 *)(a0 + 0x84)].p1C;
    u8 mode = a0[0x88];
    s32 t0, t1;
    f32 t, d0, d1, ang, f, s;
    u8 *ref;

    if (mode == 1 || mode == 4) goto do_copy;
    if (mode == 2) {
        func_0038CAD0(dd);
        t0 = *(s32 *)(dd + 4);
        t1 = *(s32 *)(data + 0xE0);
        t = (f32)(t1 > 0x7fffffff ? 0 : (t0 - t1)) / (f32)t0;
        func_L01_00445438(q30, q30, q80, t);
        func_L01_00445510(q40, q40, data + 0x90, t);
        goto finish;
    }
    if (mode == 3) {
        if (func_0038CAD0(dd) != 0) goto do_copy;
        t0 = *(s32 *)(dd + 4);
        t1 = *(s32 *)(data + 0xE0);
        t = (f32)(t0 - t1) / (f32)t0;
        ref = D_L01_001E2A40 + *(s32 *)(a0 + 0x94) * 0x460;
        func_L01_003F5FC0(data + 0xE8, q80, ref + 0x190);
        d0 = func_0038DB00(*(f32 *)(dd + 8), *(f32 *)(dd + 0x1C));
        d1 = func_0038DB00(*(f32 *)(q80 + 0x18), *(f32 *)(ref + 0x18));
        if ((d0 > 0.34906584f && d1 < -0.34906584f) ||
            (d0 < -0.34906584f && 0.34906584f < d1)) {
            f = *(f32 *)(dd + 8) - *(f32 *)(dd + 0x1C);
            if ((f < 0.0f && 0.0f < d1) || (f > 0.0f && d1 < 0.0f)) f = -f;
            *(f32 *)(dd + 0x1C) = *(f32 *)(dd + 0x1C) + func_003C3BE8(0.0f, f, t);
        } else {
            *(f32 *)(dd + 0x1C) = func_L01_004453B8(*(f32 *)(dd + 0x1C), *(f32 *)(dd + 8), t);
        }
        s = func_L01_004451D0(*(f32 *)(dd + 0x44), 0.0f, 1.0f, *(f32 *)(dd + 0x48), t);
        *(f32 *)(dd + 0x24) = *(f32 *)(dd + 0x24) + (*(f32 *)(dd + 0x10) - *(f32 *)(dd + 0x24)) * s;
        *(f32 *)(dd + 0x20) = func_L01_004453B8(*(f32 *)(dd + 0x20), *(f32 *)(dd + 0xC), t);
        ref = D_L01_001E2A40 + *(s32 *)(a0 + 0x94) * 0x460;
        func_L01_00445438(dd + 0x30, dd + 0x30, ref + 0x190, t);
        func_L01_003F5F10((f32 *)q30, (f32 *)(dd + 0x1C), dd + 0x30);
        func_L01_00445510(q40, q40, data + 0x90, t);
        goto finish;
    }
    if (*(s16 *)(data + 0x1C) == 1) {
        *(f32 *)(a0 + 0x30) = func_00382BC8((f32 *)data, *(f32 *)(a0 + 0x30), *(f32 *)(q80 + 0), *(f32 *)(data + 0x10), *(f32 *)(data + 0x14), *(f32 *)(data + 0x18));
        *(f32 *)(a0 + 0x34) = func_00382BC8((f32 *)(data + 4), *(f32 *)(a0 + 0x34), *(f32 *)(q80 + 4), *(f32 *)(data + 0x10), *(f32 *)(data + 0x14), *(f32 *)(data + 0x18));
        *(f32 *)(a0 + 0x38) = func_00382BC8((f32 *)(data + 8), *(f32 *)(a0 + 0x38), *(f32 *)(q80 + 8), *(f32 *)(data + 0x10), *(f32 *)(data + 0x14), *(f32 *)(data + 0x18));
    }
    if (*(s16 *)(q30d + 0x2C) == 1) {
        *(f32 *)(a0 + 0x40) = func_00382C58((f32 *)q30d, *(f32 *)(a0 + 0x40), *(f32 *)(q80 + 0x10), *(f32 *)(q30d + 0x20), *(f32 *)(q30d + 0x24), *(f32 *)(q30d + 0x28));
        *(f32 *)(a0 + 0x44) = func_00382C58((f32 *)(data + 0x34), *(f32 *)(a0 + 0x44), *(f32 *)(q80 + 0x14), *(f32 *)(q30d + 0x20), *(f32 *)(q30d + 0x24), *(f32 *)(q30d + 0x28));
        *(f32 *)(a0 + 0x48) = func_00382C58((f32 *)(data + 0x38), *(f32 *)(a0 + 0x48), *(f32 *)(q80 + 0x18), *(f32 *)(q30d + 0x20), *(f32 *)(q30d + 0x24), *(f32 *)(q30d + 0x28));
    }
    goto finish;
do_copy:
    *(u128_t *)q30 = *(u128_t *)q80;
    *(u128_t *)q40 = *(u128_t *)(data + 0x90);
finish:
    func_0038D328(mtx, (f32 *)q40);
    func_0038D590(a0, mtx);
    if (base->b20 != 0) func_L01_00404AD8(func_L01_003EB750, 0);
}
