/* functional: medium. Aim-mode decision table (A/S/Z/Y flags) was hand-derived; worth a gate run */
extern u8 D_001A4BE0[];
extern u8 D_001425C0[];
extern u8 D_00142A60[];
extern u8 D_002C5600[];
extern u8 D_002BAE80[];
extern u8 *D_001D52FC;
extern s32 D_001D6694;
extern s32 D_001E2100;
extern s32 D_001E2104;
extern s32 D_001E2120;
extern u8 D_001DAFF0;
extern u8 D_001E29C0[];
extern u8 D_001E29E0[];
extern s32 D_L01_001DE360;
__asm__(".extern D_L01_001DE360, 4");
extern s32 D_L01_001DE340;
__asm__(".extern D_L01_001DE340, 4");
extern u8 D_L01_001DE300[];
extern u8 D_L01_001DE310[];

static void vadd_3A70A8(f32 *d, f32 *a, f32 *b) {
    f32 x = a[0] + b[0], y = a[1] + b[1], z = a[2] + b[2], w = a[3];
    d[0] = x; d[1] = y; d[2] = z; d[3] = w;
}
static void vsub_3A70A8(f32 *d, f32 *a, f32 *b) {
    f32 x = a[0] - b[0], y = a[1] - b[1], z = a[2] - b[2], w = a[3];
    d[0] = x; d[1] = y; d[2] = z; d[3] = w;
}

void func_L01_003A70A8(u8 *obj) {
    extern s32 func_L01_005003D0(s32, s32);
    extern void func_L01_00444F38(u8 *, s32, s32, s32, s32);
    extern void func_0038D000(void *, void *, void *);
    extern void func_0038CF68(u8 *, Vec4 *, f32);
    extern f32 func_0038CF00(void *, void *);
    extern f32 func_0038DAB8(f32, f32);
    extern u8 *func_L01_00450BB0(void *, void *, s32, f32, f32, f32, f32, f32);
    extern void func_L01_004CB128(void *, void *, s32);
    extern void func_L01_003F6F20(s32, void *, s32, void *, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32);
    extern s32 func_L01_004CB1F0(f32, f32);
    extern s32 func_0038CAD0(void *);
    extern s32 func_L01_005118D0(s32, s32);
    extern void func_L01_004EA7D8(s32);
    extern s32 func_L01_003F2058(void *, s32);
    extern f32 func_003824E0(f32, f32);
    extern void func_L01_0035BF48(u8 *, void *, void *, s32, s32, f32, f32);
    extern void func_L01_00404A10(void *, void *);
    extern void func_L01_003A78E8(u8 *);
    extern void func_L01_003A7B38(u8 *);
    extern void func_L01_004EAA80(void);
    extern s32 func_L01_005119E0(s32);
    extern void func_L01_003F2278(s32, s32);
    extern s32 func_L01_003F1FC0(s32, s32);
    u128_t a, b, c;
    f32 *pa = (f32 *)&a;
    f32 *pb = (f32 *)&b;
    f32 *pc = (f32 *)&c;
    u8 *v = *(u8 **)(obj + 0x68);
    u8 *H = D_001A4BE0;
    u8 *tbl;
    u8 *target;
    u8 *pad;
    s32 t;
    s32 h;
    s32 f;
    f32 d;
    f32 ang;
    f32 w;
    f32 f13;

    if (obj[0x20] == 0) {
        obj[0x30] = 0xFF;
        D_001E2104 = 0;
        *(s32 *)(v + 0x58) = -1;
        obj[0x20] = 1;
    }
    if (D_002C5600[D_001425C0[0x2F] * 0xF0 + 1] >= 2) D_00142A60[0x2F] |= 0x20;
    if (D_002C5600[D_001425C0[0x2F] * 0xF0 + 1] >= 3) D_00142A60[0x2F] |= 2;
    t = D_002C5600[D_001425C0[0x2F] * 0xF0 + 1];
    if (t == 2) {
        *(s16 *)(obj + 0x7C) = 3;
    } else if (t == 1) {
        *(s16 *)(obj + 0x7C) = 1;
    }
    if (*(s32 *)(H + 0x25C4) == 1) func_L01_005003D0(0x1D, 1);
    if (obj[0x42] == obj[0x43] && (obj[0x60] & 2)) {
        func_L01_00444F38(obj, 1, 0, 2, 0);
    }
    func_0038D000(&a, D_L01_001DE300, obj + 0xC0);
    vadd_3A70A8(pa, pa, (f32 *)(obj + 0x10));
    *(u128_t *)(v + 0x10) = a;
    func_0038D000(&b, D_L01_001DE310, obj + 0xC0);
    vadd_3A70A8(pb, pb, (f32 *)(obj + 0x10));
    *(u128_t *)(v + 0x20) = b;
    func_0038CF68(v + 0x40, (Vec4 *)(obj + 0xD0), -20.0f);
    func_0038CF68(v + 0x30, (Vec4 *)(*(u8 **)(H + 0x25C0) + 0xC0), 1.0f);
    if (D_001DAFF0 != 0) {
        target = func_L01_00450BB0(v + 0x10, v + 0x30, 0, 0.34906584f, 0.17453292f, 50.0f, 0.78539819f, 0.78539819f);
    } else {
        target = func_L01_00450BB0(v + 0x10, v + 0x30, 0, 0.052359879f, 0.10471976f, 35.0f, 0.78539819f, 0.78539819f);
    }
    if (*(s32 *)(H + 0x1430) != 0) {
        *(s32 *)(H + 0xBD8) = *(s32 *)(H + 0x1430);
        target = *(u8 **)(H + 0x1430);
    }
    if (target != 0) {
        func_L01_004CB128(&c, target, 0);
        vsub_3A70A8((f32 *)(v + 0x30), pc, (f32 *)(v + 0x10));
        func_0038CF68(v + 0x30, (Vec4 *)(v + 0x30), 20.0f);
        vadd_3A70A8((f32 *)v, (f32 *)(v + 0x30), pa);
        if (*(s32 *)(H + 0x25C4) != 0x1D && *(s32 *)(H + 0x16B0) == 0) {
            d = func_0038CF00(D_001E29C0, &c) / 150.0f;
            ang = func_0038DAB8(*(f32 *)(v + 0x5C), 0.034906585f);
            *(f32 *)(v + 0x5C) = ang;
            w = 0.9f - d * 0.65f;
            if (w < 0.0f) w = -w;
            func_L01_003F6F20(0, obj, 0xFF0FFF0F, &c, 0x26, -1, 4, w, -ang, 90.0f, 0.5f, 0.5f, 40.0f, 40.0f);
            *(u8 **)(H + 0xBD8) = target;
        }
    }
    {
        s32 A = *(s16 *)(H + 0x2874) != 0;
        s32 S = *(s32 *)(H + 0x25C4) == 0x1D;
        s32 Z = *(s32 *)(H + 0x16B0) == 0;
        s32 Y = *(s32 *)(H + 0x1430) == 0;
        if (S) goto aim_b;
        if (Z) {
            if (A) {
                func_0038CF68(v + 0x30, (Vec4 *)(obj + 0xD0), -20.0f);
                goto aim_g;
            }
            if (target != 0) goto after_aim;
            func_0038CF68(v + 0x30, (Vec4 *)(*(u8 **)(H + 0x25C0) + 0xC0), 20.0f);
            goto aim_g;
        }
        if (A || Y) goto aim_b;
        func_L01_004CB128(&c, target, 0);
        vsub_3A70A8((f32 *)(v + 0x30), pc, (f32 *)(v + 0x10));
        func_0038CF68(v + 0x30, (Vec4 *)(v + 0x30), 20.0f);
    }
aim_g:
    vadd_3A70A8((f32 *)v, (f32 *)(v + 0x30), pa);
    *(s32 *)(H + 0x16D8) = 0;
    *(s32 *)(H + 0x16D4) = 0;
    goto after_aim;
aim_b:
    func_0038CF68(v + 0x30, (Vec4 *)D_001E29E0, 20.0f);
    vadd_3A70A8((f32 *)v, (f32 *)(v + 0x30), pa);
    h = func_L01_004CB1F0(0.99f, 150.0f);
    func_L01_003F6F20(0, obj, h, 0, 0x56, -1, 4, 0.75f, 0.0f, 90.0f, 0.5f, 0.5f, 40.0f, 40.0f);
    *(u8 **)(H + 0xBD8) = target;
after_aim:
    pad = D_001D52FC;
    if ((H[0x25ED] == 0 && D_001D6694 == 0 && *(s32 *)(H + 0x1220) >= 0x13 &&
         (*(s32 *)(pad + 0x1A0) & *(s32 *)(H + 0x1210)) != 0) ||
        ((*(s32 *)(pad + 0x1A0) & 8) != 0 && *(s32 *)(H + 0x25C4) == 0x1D)) {
        D_001E2104 = D_001E2104 + 1;
        *(s32 *)(v + 0x54) = 0x11;
        if (func_0038CAD0(&D_001E2100) == 0) goto tail;
        if (func_L01_005118D0(-1, 1) != 0) {
            func_L01_004EA7D8(-1);
            D_001E2120 = 1;
            *(s32 *)(v + 0x58) = func_L01_003F2058(D_002BAE80, 0);
            w = func_003824E0(60.0f, 80.0f);
            func_0038CF68((u8 *)&c, (Vec4 *)(v + 0x30), w * 0.02f);
            ((void (*)(s32, s32, u8 *))func_003A52A0)(3, 0, obj);
            f13 = 0.75f;
            if (target != 0) f13 = 0.0f;
            tbl = D_002C5600 + D_001425C0[0x2F] * 0xF0;
            if (D_L01_001DE360 != 0) {
                func_L01_0035BF48(obj, v + 0x20, &c, 0x10000, D_L01_001DE340, *(f32 *)(tbl + 0x6C), f13);
                D_L01_001DE360 = 0;
            } else {
                func_L01_0035BF48(obj, v + 0x10, &c, 0x10000, D_L01_001DE340, *(f32 *)(tbl + 0x6C), f13);
                D_L01_001DE360 = 1;
            }
            D_001E2100 = 12;
            func_L01_00404A10(func_L01_003A7B38, obj);
            func_L01_003A78E8(obj);
            pad = D_001D52FC;
            goto fin;
        } else {
            pad = D_001D52FC;
            if ((*(s32 *)(pad + 0x1A4) & *(s32 *)(H + 0x1210)) != 0 || D_001E2120 == 1) {
                ((void (*)(s32, s32, u8 *))func_003A52A0)(4, 0, obj);
                D_001E2120 = 0;
                goto tail;
            }
            goto fin;
        }
    } else {
        func_L01_004EAA80();
        D_001E2100 = 0;
        if (*(s32 *)(v + 0x54) <= 0) D_001E2104 = 0;
    }
tail:
    pad = D_001D52FC;
fin:
    h = *(s32 *)(v + 0x58);
    if ((*(s32 *)(pad + 0x1A0) & *(s32 *)(H + 0x1210)) != 0 && func_L01_005119E0(-1) != 0 && H[0x25E9] != 0) {
        goto have;
    }
    if (h < 0) return;
    func_L01_003F2278(h, 0);
    *(s32 *)(v + 0x58) = -1;
    h = -1;
have:
    if (h > 0) {
        if (func_L01_003F1FC0(h - 1, 0) != 0) return;
        *(s32 *)(v + 0x58) = -1;
    }
}
