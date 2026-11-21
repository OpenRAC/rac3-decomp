/* functional: medium. Same calls and stores as retail; vector subtract done in scalar float instead of VU0; unconfirmed global names. */
typedef struct {
    s16 h0;
    s16 h2;
    f32 f4;
    f32 f8;
    f32 fC;
    f32 f10;
    f32 f14;
    f32 f18;
    s32 n;
} L23_Cfg;

extern u8 D_L23_001E5D80[];
extern u8 *D_L23_00238930[];
extern s32 D_001D545C;
extern L23_Cfg D_001D7090;
extern u8 D_001D70B0[];
extern u8 D_001D6AB4[];
extern u8 D_001D6AB8[];
extern u8 D_001D7190[];
extern u8 D_001D7198[];
extern u8 D_001D71D8[];
extern f32 D_L23_001DEF70[4];
extern f32 D_L23_001DEF80[4];

extern void func_L01_00423AB8(void);
extern void func_003A58C0(void *, s32);
extern void func_003A7AF8(void *);
extern void func_L01_00404808(void *, void *);
extern void func_L01_004048D0(void *, void *);
extern void func_L01_00424168(void *);
extern void func_L01_00451DB8(void *, void *, s32, s32, f32);
extern void func_003C2F58(void *, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_003C4C18(void *, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern s32 func_00382468(s32);
extern void func_L01_0046C470(void *, void *, s32, f32, s32, s32, s32, s32, s32);
extern void func_L23_00406AC0(void *);
extern void func_L23_00406C48(void *);
extern void func_L23_00406D00(void);
extern void func_L03_00411F50(void *, s32);
extern void func_L10_004079E0(void *);

void func_L23_00407638(void) {
    u8 *gs;
    u8 *o;
    u8 **pp;
    s32 i;
    s32 j;
    s32 s;
    s32 t;
    s32 type;
    L23_Cfg cfg;
    f32 v[4];
    f32 r;
    s32 ri;

    func_L01_00423AB8();
    gs = D_L23_001E5D80;
    for (i = 0; i < *(s16 *)(gs + 0x44); i++) {
        o = *(u8 **)(gs + 0x1A0 + i * 4);
        if (o != 0 && *(s16 *)(o + 0xAA) == 0xE29) {
            *(u16 *)(o + 0x34) |= 0x800;
        }
        if (*(s16 *)(o + 0xAA) == 0xD54) {
            o[0x63] = 0;
            for (pp = D_L23_00238930; *pp != 0; pp++) {
                if ((*pp)[0x63] != 0) {
                    (*pp)[0x63] = 1;
                }
            }
            func_003A58C0(o, 0);
            func_L01_004048D0((void *)func_003A7AF8, o);
        }
        if (o != 0) {
            type = *(s16 *)(o + 0xAA);
            if (type == 0xFA0) {
                if (*(u8 **)(o + 0x68) != 0) {
                    func_L01_00451DB8(o, *(u8 **)(o + 0x68) + 0xC, 0x80AAAAD2, 0x80396464, 0.0733038336f);
                }
            } else if (type == 0x1DEE || type == 0x19BC) {
                func_L01_00451DB8(o, D_001D70B0, 0x80505080, 0x80404038, 0.0383972451f);
            } else if (type == 0x1977) {
                func_L01_00451DB8(o, D_001D6AB4, 0x8080AAAA, 0x80464646, 0.0453785658f);
            } else if (type == 0x1766) {
                func_L01_00451DB8(o, D_001D6AB8, 0x80AAAAFF, 0x80646496, 0.132645041f);
            } else if (type == 0x195B || type == 0x1B58 || type == 0x195C || type == 0x175A) {
                func_L01_00404808((void *)func_L01_00424168, o);
            }
        }
    }

    if (D_001D545C != 0x17) {
        return;
    }
    gs = D_L23_001E5D80;
    s = *(s32 *)(gs + 0x30);
    if (s != 0) {
        if (s == 1) {
            *(u8 **)D_001D7190 = D_001D7198;
            func_L10_004079E0(D_001D71D8);
        }
        return;
    }
    o = *(u8 **)(gs + 0x1AC);
    if (o != 0) {
        func_L23_00406AC0(o);
        func_L01_00404808((void *)func_L23_00406C48, o);
    }
    t = *(s32 *)(gs + 0x34);
    if ((u32)(t - 0x683) < 0x17) {
        u8 *a;
        u8 *b;

        a = *(u8 **)(gs + 0x1A0);
        cfg = D_001D7090;
        cfg.h0 = 0x14;
        cfg.h2 = 0xF;
        cfg.f4 = 0.4f;
        cfg.f8 = 0.2f;
        cfg.f10 = 0.2f;
        cfg.n = 8;
        b = *(u8 **)(gs + 0x1A4);
        func_003C2F58(a, 2, D_L23_001DEF70);
        func_003C2F58(b, 0, D_L23_001DEF80);
        j = 0;
        if (s < cfg.n) {
            do {
                if ((j & 1) == 0) {
                    v[0] = D_L23_001DEF80[0] - D_L23_001DEF70[0];
                    v[1] = D_L23_001DEF80[1] - D_L23_001DEF70[1];
                    v[2] = D_L23_001DEF80[2] - D_L23_001DEF70[2];
                    v[3] = D_L23_001DEF80[3];
                    func_0038CF68(v, v, 0.0032f);
                    func_003C4C18(v, 0.0048f);
                    r = func_003824E0(cfg.f8, cfg.f4);
                    ri = func_00382498(cfg.h2, cfg.h0);
                    func_L01_0046C470(D_L23_001DEF70, v, 0x80403080, r, ri, func_00382468(0xFF) & 0xFF, 0, 0x40, 0);
                }
                v[0] = D_L23_001DEF70[0] - D_L23_001DEF80[0];
                v[1] = D_L23_001DEF70[1] - D_L23_001DEF80[1];
                v[2] = D_L23_001DEF70[2] - D_L23_001DEF80[2];
                v[3] = D_L23_001DEF70[3];
                func_0038CF68(v, v, 0.008f);
                j++;
                func_003C4C18(v, 0.0120f);
                r = func_003824E0(cfg.f8, cfg.f4);
                ri = func_00382498(cfg.h2, cfg.h0);
                func_L01_0046C470(D_L23_001DEF80, v, 0x80403080, r, ri, func_00382468(0xFF) & 0xFF, 0, 0x40, 0);
            } while (j < cfg.n);
        }
        func_L01_00404808((void *)func_L23_00406D00, a);
    }
    if (*(s32 *)(gs + 0x34) >= 0x6CE) {
        o = *(u8 **)(gs + 0x1B4);
        if (o != 0) {
            func_L03_00411F50(o, 0);
            func_L03_00411F50(o, 1);
        }
    }
}
