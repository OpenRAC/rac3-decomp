/* Matches PAL byte for byte with check.py (round 13, sonnet xhigh; needs `-mvu0-use-vf0-vf2` added to its file's text_parts line,
 * `src/levels/shared/L18_003514B8.c`), but the full level build rejects it at levels 18, 20, 26 and 29:
 * "func_L18_00351908, its word at +0x4CC: the instruction differs" (the word at +0x4CC of the function). Look at that word in the level
 * build's own output (build/levels/NN_*/build.log, tools/level_symbols.py) before spending more compiles.
 */
/* localdecomp:start func_L18_00351908 */
typedef int u128_00351908 __attribute__((mode(TI)));
typedef struct {
    f32 v[4];
} __attribute__((aligned(16))) V_00351908;
typedef struct {
    u8 pad0[0x19E0];
    void *x19E0;
    u8 pad19E4[0xBE0];
    s32 x25C4;
} G_00351908;
typedef struct {
    u8 *p;
    s32 pad[1];
} Ptr_00351908;
typedef struct {
    u8 *p;
    s32 pad[3];
} Ptr16_00351908;
typedef struct {
    void *p0;
    void (*f4)(void);
    void (*f8)(void);
} Ctl_00351908;

extern s32 func_L01_0043B568(s32, s32, s32);
extern void func_L18_00353110(u8 *);
extern s32 func_00382380(void *, s32, s32);
extern s32 func_L01_00456500(void *, s32);
extern f32 func_L01_0040E570(void *, void *);
extern void func_L01_004464C8(void *, void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CEA8(void *);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_003C3DA0(void *, void *, s32, void *, f32);
extern void func_0038D000(void *, void *, void *);
extern f32 func_L01_00446E38(void *, void *, f32, s32, void *);
extern f32 func_0038CE68(void *, void *);
extern s32 func_L01_003FB640(void *, s32, void *, f32);
extern s32 func_L01_003FDCA0(void *, s32, f32);
extern Ptr16_00351908 D_001A71A0;
extern G_00351908 D_001A4BE0_00351908;
__asm__(".extern D_L18_001E009C_00351908, 16");
extern Ptr_00351908 D_L18_001E009C_00351908;
__asm__(".extern D_L18_001E0180_00351908, 16");
extern Ptr_00351908 D_L18_001E0180_00351908;
__asm__(".extern D_L18_001DFD4C_00351908, 16");
extern Ptr_00351908 D_L18_001DFD4C_00351908;
__asm__(".extern D_L18_001DFD50_00351908, 16");
extern s32 D_L18_001DFD50_00351908;
extern V_00351908 D_L18_001EAAC0_00351908;
extern V_00351908 D_L18_001EAAB0_00351908;

s32 func_L18_00351908(u8 *o) {
    V_00351908 q0;
    V_00351908 t10;
    V_00351908 d;
    V_00351908 t30;
    V_00351908 t40;
    V_00351908 t50;
    V_00351908 t60;
    V_00351908 t70;
    V_00351908 t80;
    V_00351908 t90;
    s32 ret = 0;
    s32 f4 = 0;
    s32 f8 = 0;
    s32 fc = 0;
    Ctl_00351908 *ctl;
    vu0_q qc;
    s32 *list;
    u8 *v = *(u8 **)(o + 0x68);
    f32 r;
    f32 len;
    s32 ci;

    if (o[0x20] != 5) {
        u8 *a = D_001A71A0.p;
        if (*(s32 *)(a + 0x9C) != 0) {
            fc = 1;
            *(s32 *)(a + 0x9C) = -1;
        } else if (*(s32 *)(a + 0x98) != 0) {
            fc = 1;
            *(s32 *)(a + 0x9C) = -1;
        }
    }
    ctl = (Ctl_00351908 *)func_L01_0043B568(0x1E6F, 0, 12);
    if (ctl != 0) {
        ctl->f4();
    }
    list = (s32 *)(v + 0x308);
    func_L18_00353110(o);
    {
        u8 *tab = D_L18_001E009C_00351908.p;
        for (ci = 0; ci < 18; ci++) {
            s32 k = list[ci];
            if (k != -1) {
                u8 *e = tab + (k << 8);
                *(s32 *)(e + 0x98) = *(s32 *)(*(u8 **)(e + 0x24) + 0x10);
            }
        }
    }
    if (*(s32 *)(v + 0x3BC) != 0) {
        if (*(s32 *)(v + 0x3EC) != -1 && func_00382380((o + 0x10), *(s32 *)(v + 0x3EC), 0) == 0) {
            vec_sub_ba(&d, D_L18_001E0180_00351908.p + 0x30 + (*(s32 *)(v + 0x3EC) << 7), (o + 0x10));
            d.v[2] = 0.0f;
            func_0038CF68(&d, &d, 0.00030000001f);
            vec_add_ab(v + 0x3F0, v + 0x3F0, &d);
        } else if (*(s32 *)(v + 0x43C) != -1 && func_L01_00456500((o + 0x10), *(s32 *)(v + 0x43C)) == 0) {
            f32 m1 = 999999.0f;
            f32 m2 = 999999.0f;
            s32 i1 = -1;
            s32 i2 = -1;
            s32 n;
            u8 *rec = D_L18_001DFD4C_00351908.p + (*(s32 *)(v + 0x43C) * 0x30 + 0x20);
            for (n = 0; n < *(s16 *)(rec + 0x12); n++) {
                s32 ent = ((s32 *)*(u8 **)(rec + 0x20))[n];
                f32 dd = func_L01_0040E570(D_L18_001E0180_00351908.p + (ent << 7) + 0x30, (o + 0x10));
                if (dd < m2) {
                    i2 = i1;
                    m1 = m2;
                    m2 = dd;
                    i1 = n;
                } else if (dd < m1) {
                    m1 = dd;
                    i2 = n;
                }
            }
            func_L01_004464C8(&t90, D_L18_001E0180_00351908.p + (i1 << 7) + 0x30, D_L18_001E0180_00351908.p + (i2 << 7) + 0x30, (o + 0x10));
            vec_sub_ba(&d, &t90, (o + 0x10));
            d.v[2] = 0.0f;
            func_0038CF68(&d, &d, 0.00030000001f);
            vec_add_ab(v + 0x3F0, v + 0x3F0, &d);
        } else {
            *(f32 *)(v + 0x3F0) = *(f32 *)(v + 0x3F0) - *(f32 *)(v + 0x3F0) * 0.09f;
            if (fabs_asm(*(f32 *)(v + 0x3F0)) < 0.01f) *(f32 *)(v + 0x3F0) = 0.0f;
            *(f32 *)(v + 0x3F4) = *(f32 *)(v + 0x3F4) - *(f32 *)(v + 0x3F4) * 0.09f;
            if (fabs_asm(*(f32 *)(v + 0x3F4)) < 0.01f) *(f32 *)(v + 0x3F4) = 0.0f;
            *(f32 *)(v + 0x3F8) = *(f32 *)(v + 0x3F8) - *(f32 *)(v + 0x3F8) * 0.09f;
            if (fabs_asm(*(f32 *)(v + 0x3F8)) < 0.01f) *(f32 *)(v + 0x3F8) = 0.0f;
        }
        vec_add_ab(v + 0x290, v + 0x290, v + 0x3F0);
        if (*(f32 *)(o + 0x18) > *(f32 *)(v + 0x300)) {
            *(f32 *)(o + 0x18) = *(f32 *)(v + 0x300);
            if (0.0f < *(f32 *)(v + 0x298)) *(f32 *)(v + 0x298) = 0.0f;
        } else if (*(f32 *)(o + 0x18) < *(f32 *)(v + 0x304)) {
            if (D_001A4BE0_00351908.x25C4 == 0x31 && D_001A4BE0_00351908.x19E0 == o) {
                *(f32 *)(v + 0x298) = *(f32 *)(v + 0x298) + 0.024000001f;
            }
        }
    } else {
        vec_sub_ab(&d, (o + 0x10), (void *)&D_L18_001DFD50_00351908);
        len = func_0038CEA8(&d);
        func_0038CE20(&t70, &d, 1.0f / len);
        if (len < *(f32 *)(v + 0x304)) {
            func_0038CE20(&t60, &t70, *(f32 *)(v + 0x304));
            vec_add_ab((o + 0x10), (void *)&D_L18_001DFD50_00351908, &t60);
        } else if (*(f32 *)(v + 0x300) < len) {
            func_0038CE20(&t60, &t70, *(f32 *)(v + 0x300));
            vec_add_ab((o + 0x10), (void *)&D_L18_001DFD50_00351908, &t60);
        }
        func_003C3DA0(&t60, (o + 0x10), 0, o, 3.0f);
        func_0038CE20(&d, &t70, 1.9f);
        vec_add_ab(&t60, &t60, &d);
        *(u128_00351908 *)(v + 0x3C0) = *(u128_00351908 *)&t70;
        func_L18_003514B8(o);
        *(u128_00351908 *)(o + 0xC0) = *(u128_00351908 *)(v + 0x2D0);
        *(u128_00351908 *)(o + 0xD0) = *(u128_00351908 *)(v + 0x2E0);
        *(u128_00351908 *)(o + 0xE0) = *(u128_00351908 *)(v + 0x2F0);
    }
    if (*(s32 *)(v + 0x3BC) != 0) {
        *(u128_00351908 *)&d = *(u128_00351908 *)(v + 0x290);
    } else {
        func_0038D000(&d, v + 0x290, v + 0x2D0);
    }
    if (*(s32 *)(v + 0x3BC) != 0) {
        *(f32 *)(o + 0x18) = *(f32 *)(o + 0x18) + 0.5f;
    } else {
        func_0038CE20(&t80, &t70, 0.5f);
        vec_add_ab((o + 0x10), (o + 0x10), &t80);
    }
    {
        vec_add_ba(&q0, (o + 0x10), &d);
        __asm__("lqc2 %0, %1" : "=j"(qc) : "m"(*(vu0_v4 *)(o + 0x10)));
        {
            vu0_q qa, qr;
            __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(q0));
            __asm__("vsub.xyz %0, %1, %2" : "=j"(qr) : "j"(qa), "j"(qc));
            __asm__("sqc2 %1, %0" : "=m"(t40) : "j"(qr));
        }
    }
L349:
    r = func_L01_00446E38((o + 0x10), &q0, 2.5f, 0x84, o);
    if (!(0.0f <= r && r < 1.0f)) goto L473;
L369:
    func_0038CF68(&t30, &D_L18_001EAAC0_00351908, 1.0f);
    func_0038CE20(&t90, &t30, 0.008f);
    vec_add_ab((o + 0x10), (o + 0x10), &t90);
    if (r == 0.0f) {
        if (f8 == 0 || (f8 < 3 && 0.0f < func_0038CE68(&t50, &t30))) {
            f4 = 0;
            f8 = f8 + 1;
            *(u128_00351908 *)&t50 = *(u128_00351908 *)&t30;
            goto L349;
        }
    }
    {
        f32 dt = func_0038CE68(&t40, &t30);
        func_0038CE20(&d, &t30, dt * -1.01f);
    }
    vec_add_ba(v + 0x290, v + 0x290, &d);
    ret = 1;
    func_0038CE20(&t10, &t40, r);
    vec_add_ab((o + 0x10), (o + 0x10), &t10);
    if (*(f32 *)(v + 0x298) < 0.0f) *(f32 *)(v + 0x298) = 0.0f;
    if (f4 == 0) {
        func_0038CE20(&t40, v + 0x290, 1.0f - r);
        vec_add_ba(&t90, (o + 0x10), &t40);
        r = func_L01_00446E38((o + 0x10), &t90, 2.5f, 0x84, o);
        if (r < 1.0f) {
            if (0.0f <= r) {
                f4 = 1;
                goto L369;
            }
            goto L477;
        }
    L473:
        vec_add_ab((o + 0x10), (o + 0x10), &t40);
    }
L477:
    {
    s32 i;
    for (i = 0; i < 4; i++) {
        s32 hit = 0;
        if (func_L01_003FB640((o + 0x10), 4, o, 2.5f) != 0) {
            *(u128_00351908 *)(o + 0x10) = *(u128_00351908 *)&D_L18_001EAAB0_00351908;
            hit = 1;
        }
        if (func_L01_003FDCA0((o + 0x10), 0, 2.5f) != 0) {
            *(u128_00351908 *)(o + 0x10) = *(u128_00351908 *)&D_L18_001EAAB0_00351908;
            hit = 1;
        }
        if (hit == 0) break;
    }
    }
    if (*(s32 *)(v + 0x3BC) != 0) {
        *(f32 *)(o + 0x18) = *(f32 *)(o + 0x18) - 0.5f;
    } else {
        vec_sub_ab((o + 0x10), (o + 0x10), &t80);
    }
    if (*(f32 *)(o + 0x10) < 10.0f) *(f32 *)(o + 0x10) = 10.0f;
    if (1013.0f < *(f32 *)(o + 0x10)) *(f32 *)(o + 0x10) = 1013.0f;
    if (*(f32 *)(o + 0x14) < 10.0f) *(f32 *)(o + 0x14) = 10.0f;
    if (1013.0f < *(f32 *)(o + 0x14)) *(f32 *)(o + 0x14) = 1013.0f;
    if (*(f32 *)(o + 0x18) < 10.0f) *(f32 *)(o + 0x18) = 10.0f;
    if (1013.0f < *(f32 *)(o + 0x18)) *(f32 *)(o + 0x18) = 1013.0f;
    {
        u8 *tab = D_L18_001E009C_00351908.p;
        for (ci = 0; ci < 18; ci++) {
            s32 e = list[ci];
            if (e != -1) {
                *(s32 *)(tab + (e << 8) + 0x98) = 0;
            }
        }
    }
    if (fc != 0 && o[0x20] != 5) {
        *(s32 *)(D_001A71A0.p + 0x9C) = 0;
    }
    if (ctl != 0) {
        ctl->f8();
    }
    *(f32 *)(v + 0x368) = *(f32 *)(o + 0x18);
    *(u128_00351908 *)(v + 0x420) = *(u128_00351908 *)(o + 0x10);
    return ret;
}
/* localdecomp:end func_L18_00351908 */
