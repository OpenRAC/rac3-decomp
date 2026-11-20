/* functional: medium. Frame laid out as retail's (0xC0: pos sp+0, dir +0x10, scratch +0x20, hit query +0x30): func_L01_00446760 leaves the query's bytes 0x18/0x19 and 0x24.. unset and func_003D3CB0 reads that stack garbage; PAL random-range constants 0x3E4CCCCE/0x3E851EB9 (one ulp off 0.2f/0.26f) kept; branch-likely delay slots and the movn flag select hand-decoded */
typedef u8 *(*Fx_003A9978)(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);
typedef struct { u8 pad[0x1A]; u16 h1A; u8 tail[0x14]; } Hit_003A9978;
extern u8 D_001A4BE0[];
extern u8 D_L01_001EAA00[];
extern u8 *D_L01_001EAA18[];
extern u8 D_L01_00221098[];
extern u8 D_L01_001D66B0[];
extern s32 D_001D545C;

void func_L01_003A9978(u8 *obj) {
    extern void func_L01_004450F0(void *, s32, s32);
    extern s32 func_L01_00367080(void *, void *, void *, void *);
    extern void func_L01_00367260(void *, s32, s32, void *, void *, s32);
    extern void func_L01_00367430(void *, f32);
    extern u8 *func_00382348(void *);
    extern void func_L01_00446760(void *, void *, s32, void *, f32);
    extern s32 func_L01_00366FC8(void);
    extern void func_L01_004CB320(void);
    extern void func_L01_004CB358(void);
    extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
    extern f32 func_0038CED8(void *);
    extern f32 func_0038D160(f32, f32);
    extern f32 func_003C4138(f32 *, f32, f32);
    extern void func_00382580(void *, f32, f32);
    extern f32 func_L01_00443A18(f32, f32);
    extern f32 func_003824E0(f32, f32);
    extern void func_L01_004713C8(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);
    extern void func_L01_00404A10(void *, void *);
    extern void func_L01_003AA120(u8 *);
    /* arrays, so they are laid out as declared, as retail's frame: pos sp+0, dir +0x10, scratch +0x20, hit +0x30
       (func_L01_00446760 leaves hit's bytes 0x18/0x19 and 0x24.. unset: func_003D3CB0 reads the stack garbage there) */
    u128_t pos[1];
    u128_t dir[1];
    u128_t scratch[1];
    Hit_003A9978 hit;
    u8 *p;
    u8 *o;
    u8 *par;
    u8 *hero;
    s32 limit;
    s32 state;
    s32 flags;
    s32 got;
    s32 i;
    s32 r;
    s32 c1, c2;
    f32 w;
    f32 alpha;
    f32 len;
    f32 ang;
    u8 *eff;
    u8 *fxbase;
    u8 *herobase;
    u8 *e;

    *(u16 *)(obj + 0x96) = *(u16 *)(obj + 0x96) + 1;
    p = *(u8 **)(obj + 0x68);
    limit = 30;
    if (*(f32 *)(p + 0x30) < 2.0f) limit = 20;
    if (limit < (s32)*(u16 *)(obj + 0x96)) {
        w = *(f32 *)(p + 0x1C) - 0.015f;
        *(f32 *)(p + 0x1C) = w;
        if (w <= 0.0f) func_L01_004450F0(obj, 1, -1);
    } else {
        w = *(f32 *)(p + 0x1C) + 0.015f;
        *(f32 *)(p + 0x1C) = w;
        if (0.4f < w) *(f32 *)(p + 0x1C) = 0.4f;
    }
    state = obj[0x20];
    herobase = D_001A4BE0;
    alpha = *(f32 *)(p + 0x1C);
    if (state == 1) {
        func_L01_00367260(obj, 0, 0, D_L01_001D66B0, D_L01_001D66B0, 0x2F2020FF);
        func_003C2880((Obj_003A5118 *)obj);
        return;
    }
    if (state == 0) {
        /* pos = vars[0x10] + vars[0x00] (xyz), w from vars[0x10] */
        pos[0] = *(u128_t *)(p + 0x10);
        ((f32 *)pos)[0] = *(f32 *)(p + 0x10) + *(f32 *)(p + 0x00);
        ((f32 *)pos)[1] = *(f32 *)(p + 0x14) + *(f32 *)(p + 0x04);
        ((f32 *)pos)[2] = *(f32 *)(p + 0x18) + *(f32 *)(p + 0x08);
        r = func_L01_00367080(p + 0x20, pos, dir, scratch);
        if (r != 0) {
            pos[0] = dir[0];
            func_L01_00367260(obj, 0, 1, p + 0x20, dir, 0x2F2020FF);
            o = func_00382348(*(void **)(obj + 0xB8));
            func_L01_00367430(obj, (f32)o[0x16]);
        } else {
            func_L01_00367260(obj, 0, 0, D_L01_001D66B0, D_L01_001D66B0, 0x2F2020FF);
        }
        flags = 1;
        o = func_00382348(*(void **)(obj + 0xB8));
        if (o != 0 && o[0x2F] != 0) flags = 0x10000;
        func_L01_00446760(&hit, obj, flags, p, *(f32 *)(p + 0x30));
        hit.h1A = *(u16 *)(obj + 0xAA);
        if (func_L01_00366FC8() != 0) {
            *(s32 *)(*(u8 **)(herobase + 0x25C0) + 0x98) = 0;
        }
        par = *(u8 **)(obj + 0xB8);
        func_L01_004CB320();
        got = func_003D3CB0(p + 0x20, p + 0x10, 0x10, par, &hit);
        if (got != 0) {
            o = D_L01_001EAA18[0];
            if (o != 0 && *(s16 *)(o + 0xAA) == 0x186D && o[0x20] != 2 && o[0x20] != 5) o[0x20] = 4;
        }
        func_L01_004CB358();
        hero = *(u8 **)(herobase + 0x25C0);
        *(s32 *)(hero + 0x98) = *(s32 *)(*(u8 **)(hero + 0x24) + 0x10);
        if (got != 0) {
            if (D_L01_001EAA18[0] != 0) {
                par = *(u8 **)(obj + 0xB8);
                func_L01_004CB320();
                got = func_003D3CB0(p + 0x20, p + 0x10, 0x12, par, 0);
                if (got != 0) {
                    o = D_L01_001EAA18[0];
                    if (o != 0 && *(s16 *)(o + 0xAA) == 0x186D && o[0x20] != 2 && o[0x20] != 5) o[0x20] = 4;
                }
                func_L01_004CB358();
            }
        }
        par = *(u8 **)(obj + 0xB8);
        if (par != 0) {
            o = func_00382348(par);
            if (o != 0 && o[0x2F] == 0) {
                func_L01_00446760(&hit, obj, 0x10000, p, *(f32 *)(p + 0x30) * 0.25f);
                hit.h1A = *(u16 *)(obj + 0xAA);
                par = *(u8 **)(obj + 0xB8);
                func_L01_004CB320();
                r = func_003D3CB0(p + 0x20, p + 0x10, 0x10, par, &hit);
                if (r != 0) {
                    o = D_L01_001EAA18[0];
                    if (o != 0 && *(s16 *)(o + 0xAA) == 0x186D && o[0x20] != 2 && o[0x20] != 5) o[0x20] = 4;
                }
                func_L01_004CB358();
            }
        }
        if (got != 0) {
            e = D_L01_001EAA00;
            len = func_0038CED8(e + 0x40);
            ang = func_0038D160(*(f32 *)(e + 0x48), len);
            if (ang < 0.436332315f) {
                func_003C4138((f32 *)pos + 2, *(f32 *)(e + 0x28), 0.5f);
            } else {
                pos[0] = *(u128_t *)(e + 0x20);
            }
        }
        *(u128_t *)(p + 0x10) = pos[0];
        *(f32 *)(p + 0x1C) = alpha;
    }
    fxbase = D_L01_00221098;
    pos[0] = *(u128_t *)(p + 0x10);
    ((f32 *)pos)[2] = ((f32 *)pos)[2] - *(f32 *)(p + 0x1C) * 0.5f;
    for (i = 1; i >= 0; i--) {
        c1 = 0x202080;
        c2 = 0x2040DD;
        if (*(f32 *)(p + 0xC) != 0.0f && D_001D545C == 1) {
            c1 = 0x208020;
            c2 = 0x20DD40;
        }
        func_00382580(dir, 0.200000018f, 0.26000002f);
        if (((f32 *)dir)[2] < 0.0f) ((f32 *)dir)[2] = -((f32 *)dir)[2];
        r = (s32)func_L01_00443A18(2.0f, 5.0f);
        w = func_003824E0(0.6f, 1.0f);
        eff = ((Fx_003A9978)func_L01_004713C8)(pos, dir, 8, c1, r, 0x7F, 0x7F, w * 210000.0f, 2100.0f, 0.00584f, 6);
        if (eff != 0) eff[2] = **(u8 **)(fxbase + 0xD4);
        r = (s32)func_L01_00443A18(2.0f, 5.0f);
        w = func_003824E0(0.6f, 1.0f);
        eff = ((Fx_003A9978)func_L01_004713C8)(pos, dir, 8, c2, r, 0x30, 0x30, w * 210000.0f * 3.0f, 4200.0f, 0.00584f, 0);
        if (eff != 0) eff[2] = **(u8 **)(fxbase + 0xD4);
    }
    func_L01_00404A10(func_L01_003AA120, obj);
}
