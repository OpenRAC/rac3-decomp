/* functional: high. Same as the PAL assembly: the trailing threshold compare (0x5A/0x12C against |D_L40_00241... - w44|) has a dead result in retail (return is always 0) so it is dropped; its reads have no side effects. */
typedef struct { f32 f0; s16 h4; u8 pad6[0x1A]; } P_3F1AD0;
typedef struct {
    P_3F1AD0 *p0;
    u8 pad4[0x1C];
    u8 *w20;
    u8 pad24[0xC];
    f32 f30;
    u8 pad34[0x12C];
    u8 b160[7];
    u8 b167;
    u8 pad168[0x154];
    s32 w2BC;
    s32 w2C0;
} S_3F1AD0;
typedef struct {
    u8 pad0[0x20];
    u8 b20;
    u8 pad21[0x47];
    S_3F1AD0 *p68;
    u8 pad6C[0x3E];
    s16 hAA;
} O_3F1AD0;
typedef struct {
    u8 pad0[0x10];
    u8 b10;
    u8 pad11[0x37];
    u8 b48;
    u8 pad49[0xF];
    f32 f58;
    u8 pad5C[0x14];
    s16 h70;
    u8 pad72[5];
    u8 b77;
    u8 pad78[0x30];
    f32 fA8;
} B_3F1AD0;
typedef struct {
    u8 pad0[0x20];
    u8 *w20;
    u8 pad24[8];
    f32 f2C;
} T_3F1AD0;
typedef struct { u8 pad0[0x1C]; s32 (*fn1C)(void *, s32); } Cls_3F1AD0;
typedef struct { u8 pad0[0x14]; Cls_3F1AD0 *p14; } Res_3F1AD0;
typedef struct { u8 pad0[4]; Res_3F1AD0 *(*fn4)(void *); } Rtti_3F1AD0;

extern u8 *D_L40_0024845C;
__asm__(".extern D_L40_0024845C, 4");
extern void func_L01_0044ABD0(void *);
extern void func_L39_0066C470(void *);
extern T_3F1AD0 *func_L01_00447490(void *, s32, s32);
extern s32 func_0038CB00(void *);
extern Rtti_3F1AD0 *func_L39_005C1018(void *);
extern void func_003C4A40(void *, void *);
extern f32 func_L01_004474E8(void *, void *);
extern s32 func_L40_0053F018(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_00455E18(void *, void *, void *);

s32 func_L40_003F1AD0(O_3F1AD0 *a, B_3F1AD0 *b, void *c, s32 unused, s32 d) {
    S_3F1AD0 *s;
    P_3F1AD0 *p;
    u8 *w20;
    T_3F1AD0 *t;
    u8 *obj;
    f32 dist;
    f32 f2;
    Res_3F1AD0 *r;

    s = a->p68;
    p = s->p0;
    w20 = s->w20;
    func_L01_0044ABD0(a);
    if (s->f30 <= 0.0f) {
        s->w2BC = s->w2BC + 1;
    }
    if (s->w2BC >= 0xC9 && a->b20 != 0x1C) {
        func_L39_0066C470(c);
    }
    if (d != 0) {
        t = func_L01_00447490(a, 1, 0);
    } else {
        t = func_L01_00447490(a, 0x10000, 0);
    }
    if (func_0038CB00((u8 *)p + 6) == 0) {
        t = 0;
    }
    if (t != 0) {
        obj = t->w20;
        if (obj != 0 && *(s16 *)(obj + 0xAA) == 0x1849 && *(u8 **)(obj + 0x68) != 0) {
            if (*(s32 *)(*(u8 **)(obj + 0x68) + 0x2C) == s->w2C0) {
                t = 0;
            }
        }
    }
    if (t != 0) {
        obj = t->w20;
        if (obj != 0) {
            u8 *q = obj;
            while (*(u8 **)(q + 0xB8) != 0) {
                q = *(u8 **)(q + 0xB8);
            }
            r = func_L39_005C1018(q)->fn4(q);
            if (r != 0) {
                if (r->p14->fn1C(r, s->w2C0) != 0) {
                    t = 0;
                    *(u8 *)((u8 *)a + 0xA8) = 0xFF;
                }
            }
        }
        if (t != 0) {
            s->b167 = 0xC8;
            func_003C4A40(a, s->b160);
            f2 = t->f2C;
            if (b->fA8 != 0.0f) {
                if (t->w20 == 0 || a->hAA != *(s16 *)(t->w20 + 0xAA)) {
                    goto after;
                }
                t->f2C = f2 * b->fA8;
            }
        }
    }
after:
    dist = func_L01_004474E8(a, t);
    *(u8 *)((u8 *)a + 0xA8) = 0xFF;
    p->f0 = p->f0 - dist;
    if (s->f30 <= 0.0f) {
        if (func_L40_0053F018(a) != 0 && a->b20 != b->b10) {
            func_L01_004450F0(a, b->b10, b->b48);
            goto tail;
        }
    }
    if (t != 0) {
        if (s->f30 * 0.01f < dist && a->b20 != 0x16) {
            func_L01_004450F0(a, 0x16, -1);
        }
    }
tail:
    if (w20 != 0) {
        func_L01_00455E18(a, (void *)w20, p);
    }
    if (dist != 0.0f) {
        b->h70 = -1;
        if (t != 0 && t->w20 != 0) {
            b->h70 = (t->w20 - D_L40_0024845C) >> 8;
        }
    }
    return 0;
}
