/* functional: medium. No draft; written from asm and read block by block. 517 diff words (regalloc/stack layout, 8 saved regs). Table/struct names inferred (D_001DFD68[] = per-player table header whose first word points to 0x1C-byte entries); 8-byte accessors (004CC758) treated as returning u32 pointers */
typedef struct {
    u8 *tbl;
} Hdr_004D0E90;

extern Hdr_004D0E90 *D_L01_001DFD68[];
extern u8 D_001439F4[];
extern s32 D_L01_001D67C8[];
extern u8 D_L01_002C5600[];
extern u8 D_001425C0[];
extern s32 D_00142DE0[];
extern s32 D_001427F0[];
extern f32 D_001DB718_sda;

extern s32 func_L01_004526F8(void);
extern void func_003AAF00(u8 *, s32);
extern void func_003AB988(u8 *, s32, s32);
extern s32 func_L01_004D25D0(s32, s32, s32);
extern void func_L01_004CD880(s32, s32 *, s32 *, s32 *);
extern void func_003AB530(u8 *, s32, s32);
extern void func_003ABBE0(u8 *, s32);
extern void func_003ABBE8(u8 *, s32);
extern s32 func_L01_00418DE0(s32, s32);
extern s32 func_00396690(void);
extern void func_L01_004CF498(u8 *, s32);
extern void func_003AD590(u8 *, s32);
extern void func_L01_004CF3A0(u8 *);
extern u32 *func_L01_004CC758(u8 *);
extern f32 *func_003AB390(u8 *);

void func_L01_004D0E90(u8 *obj, s32 idx) {
    s32 sp0 = 0, sp4 = 0, sp8 = 0;
    s32 spC = 0, sp10 = 0, sp14 = 0;
    s32 i;
    s32 fp;
    s32 base_off;
    u8 *r16, *r17, *r18, *r19, *r22, *r23;
    u32 alpha, alpha2, m;
    s32 sel_b0;
    u32 a16, a17, a18, a0v;
    f32 f20;

    *(s32 *)(obj + 0xB4C) = func_L01_004526F8();
    base_off = 0x1FCA8;

    if (D_L01_001DFD68[0] != 0) {
        u8 *name_r22 = obj + 0x664;
        if (D_001439F4[0] == 0) {
            func_003AAF00(obj + 0x5C8, 1);
            func_003AAF00(obj + 0x5F8, 0);
        } else {
            func_003AAF00(obj + 0x5C8, 0);
            func_003AAF00(obj + 0x5F8, 1);
        }
        for (i = 0; i < 8; i++) {
            u8 *e = D_L01_001DFD68[0]->tbl + i * 0x1C;
            s32 p;
            u8 *q;
            s32 idx2;
            s32 sel;
            if (*(s32 *)e == 0) {
                func_003AAF00(name_r22, 0);
            } else {
                func_003AAF00(name_r22, 1);
                func_003AB988(name_r22, *(s32 *)e, 0);
            }
            p = func_L01_004D25D0(D_L01_001D67C8[0] + base_off, 0, 0);
            q = (u8 *)p + i * 0x3C;
            func_003AAF00(q, 0);
            sp0 = 0;
            sp4 = 0;
            sp8 = 0;
            func_L01_004CD880(*(s32 *)(e + 0x18), &sp0, &sp4, &sp8);
            p = func_L01_004D25D0(D_L01_001D67C8[0] + base_off, 0, 0);
            r19 = (u8 *)p + i * 0x3C;
            func_003AAF00(r19, 1);
            func_003AB530(r19, sp0, sp4);
            func_003ABBE0(r19, 100);
            func_003ABBE8(r19, 100);
            idx2 = *(s32 *)(e + 0x18);
            sel = D_001425C0[idx2];
            if (D_L01_002C5600[sel * 0xF0] != 0) {
                u32 b1 = D_L01_002C5600[sel * 0xF0 + 1];
                s32 w68 = *(s32 *)(D_L01_002C5600 + sel * 0xF0 + 0x68);
                if (w68 != 0 || b1 != 0) {
                    s32 saved = 0;
                    if (b1 != 0) {
                        func_L01_00418DE0(idx2, b1 - 1);
                        saved = *(s32 *)(D_L01_002C5600 + D_001425C0[idx2] * 0xF0 + 0x68);
                        func_L01_00418DE0(idx2, b1);
                    }
                    func_003ABBE0(r19, *(s32 *)(D_L01_002C5600 + D_001425C0[idx2] * 0xF0 + 0x68) - saved);
                    if (*(s32 *)(D_L01_002C5600 + D_001425C0[idx2] * 0xF0 + 0x68) > 0) {
                        func_003ABBE8(r19, (D_00142DE0[idx2] >> 5) - saved);
                    }
                }
            }
            name_r22 += 0x30;
        }
    }

    if (obj[0xB40] != 0) {
        fp = *(s32 *)(obj + 0xB44);
    } else {
        fp = func_00396690();
    }
    r16 = obj + 0x110;
    r17 = obj + 0x7E8;
    sel_b0 = D_L01_002C5600[D_001425C0[fp] * 0xF0];
    spC = 0;
    sp10 = 0;
    sp14 = 0;
    r18 = obj + 0x870;
    r19 = obj + 0x8F8;
    r22 = obj + 0x5C8;
    r23 = obj + 0x5F8;
    func_L01_004CD880(fp, &spC, &sp10, &sp14);
    *func_L01_004CC758(r16) = sp14;
    func_L01_004CF498(r17, 1);
    func_L01_004CF498(r18, 1);
    func_L01_004CF498(r19, 1);
    func_L01_004CF498(obj + 0x980, 1);
    func_L01_004CF498(obj + 0xA08, 1);
    alpha = (*func_L01_004CC758(obj + 0x664) >> 24) << 24;
    for (i = 6; i >= 0; i--) {
        u32 *p = func_L01_004CC758(obj + 0x694 + (6 - i) * 0x30);
        *p = (*p & 0xFFFFFF) | alpha;
    }
    {
        u32 *p = func_L01_004CC758(r22);
        *p = (*p & 0xFFFFFF) | alpha;
        p = func_L01_004CC758(r23);
        *p = (*p & 0xFFFFFF) | alpha;
    }
    func_L01_004CF498(obj + 0xA90, 1);
    m = *func_L01_004CC758(obj + 0x2BC) >> 24;
    alpha2 = m << 24;
    for (i = 0; i < 8; i++) {
        s32 prev = i - 1;
        Hdr_004D0E90 *h;
        u32 *p;
        if (prev < 0) {
            prev = 7;
        }
        h = D_L01_001DFD68[idx];
        if (h != 0) {
            u8 *e = h->tbl + i * 0x1C;
            if (*(s32 *)e != 0) {
                s32 idx2 = *(s32 *)(e + 0x18);
                u8 *ent = D_L01_002C5600 + D_001425C0[idx2] * 0xF0;
                if (ent[0] == 0) {
                    *func_L01_004CC758(obj + prev * 0x3C + 0x2BC) = 0x331465B7;
                } else if (D_001427F0[idx2] != 0) {
                    *func_L01_004CC758(obj + prev * 0x3C + 0x2BC) = 0x331465B7;
                } else if (*(u16 *)(ent + 0x84) == 0) {
                    *func_L01_004CC758(obj + prev * 0x3C + 0x2BC) = 0x331465B7;
                } else {
                    *func_L01_004CC758(obj + prev * 0x3C + 0x2BC) = 0x70202080;
                }
            }
        }
        p = func_L01_004CC758(obj + prev * 0x3C + 0x2BC);
        *p = (*p & 0xFFFFFF) | alpha2;
    }
    {
        u32 *p = func_L01_004CC758(obj + 0x244);
        *p = (*p & 0xFFFFFF) | (m << 24);
        a16 = *func_L01_004CC758(obj + 0x280) & 0xFF000000;
        p = func_L01_004CC758(obj + 0x628);
        *p = (*p & 0xFFFFFF) | a16;
        a17 = *func_L01_004CC758(obj + 0xD0) & 0xFF000000;
        a18 = *func_L01_004CC758(obj + 0x110) & 0xFF000000;
        a0v = *func_L01_004CC758(obj) & 0xFF000000;
        if (a0v < a17) {
            a17 = a0v;
        }
        p = func_L01_004CC758(obj + 0xD0);
        if (a0v < a18) {
            a18 = a0v;
        }
        *p = (*p & 0xFFFFFF) | a17;
        p = func_L01_004CC758(obj + 0x110);
        *p = (*p & 0xFFFFFF) | a18;
    }
    if (*(s32 *)(obj + 0xB38) != 0) {
        *(s32 *)(obj + 0xB38) -= 1;
        if (*(s32 *)(obj + 0xB38) == 0) {
            if (*(s32 *)(obj + 0xB3C) != 1) {
                *(s32 *)(obj + 0xB3C) = 1;
                func_003AAF00(obj + 0x628, 0);
                func_003AD590(obj + 0x7E8, -1);
                func_003AD590(obj + 0x870, -1);
                func_003AD590(obj + 0x8F8, -1);
                func_003AD590(obj + 0x980, -1);
                func_003AD590(obj + 0xA08, -1);
                func_003AD590(obj + 0xA90, -1);
                func_L01_004CF3A0(obj + 0x7E8);
                func_L01_004CF3A0(obj + 0x870);
                func_L01_004CF3A0(obj + 0x8F8);
                func_L01_004CF3A0(obj + 0x980);
                func_L01_004CF3A0(obj + 0xA08);
                func_L01_004CF3A0(obj + 0xA90);
            }
        }
    }
    if (fp != 0 && sel_b0 != 0) {
        s32 w = *(s32 *)(D_L01_002C5600 + D_001425C0[fp] * 0xF0 + 0x68);
        if (w > 0) {
            f32 ratio = (f32)(D_00142DE0[fp] >> 5) / (f32)w;
            f32 g = D_001DB718_sda * (0.5f - ratio * 0.5f);
            if (g < 1.0f) {
                g = 1.0f;
            }
            f20 = ratio * 30.0f * g;
            if (30.0f < f20) {
                f20 = 30.0f;
            }
        } else {
            f20 = 30.0f;
        }
        *func_003AB390(obj + 0x78) = f20;
    }
}
