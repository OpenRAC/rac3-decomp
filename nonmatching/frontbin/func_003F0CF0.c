/* US draft of func_003F0CF0 (rac3-uya-decomp func_003EB728, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override). */


/* localdecomp:start func_003F0CF0 */
typedef struct {
    u8 p00[0x10];
    s32 f10;
    s32 f14;
    s16 h18;
    s16 h1A;
    u8 p1C[0xC];
    f32 f28;
    f32 f2C;
    f32 f30;
    u32 f34;
    u32 f38;
    f32 f3C;
    f32 f40;
    f32 f44;
    u16 h48;
    u16 p4A;
    u16 h4C;
    u16 p4E;
    f32 f50;
    u16 h54;
    u16 h56;
    u8 b58;
    u8 b59;
    u8 b5A;
} P_3EB728;

typedef struct {
    u8 p00[0x20];
    void (*f20)(void *, s32, f32 *, s32);
} VT_3EB728;

typedef struct {
    u8 p00[8];
    VT_3EB728 *vt;
    u8 p0C[0x14];
    f32 f20;
    f32 f24;
    u32 f28;
    P_3EB728 *p;
    u8 b30;
    u8 p31[3];
    f32 f34;
} O_3EB728;

typedef struct {
    s16 y0, y1, x0, x1, tx, ty, w, h, f30, flags, f34, f36, f38, f3A;
} Desc_3EB728;

extern f32 D_001D9690;
extern f32 D_001D9694;
extern f32 D_001D9698;
extern f32 D_001D969C;
extern s32 D_001D55C4;
extern s32 D_003357E0[];
extern void func_0038E150(s32);
extern void func_003EDCF0(void *, f32 *);
extern void func_003F0BB8(void *, s32 *, s32 *);
extern s32 func_003EDAF8(void *, s32);
extern void func_00391210();
extern void func_003911F0();
extern void func_00390CC8(void);
extern void func_00390CA8(void);
extern void func_003E7160(void);
extern long func_00389598(s32);

static __inline__ void TextA_3EB728(Desc_3EB728 *d, f32 f44, f32 ty, f32 *pw, f32 *px, unsigned long b1, s32 dd, s32 g, f32 l, f32 tx, s32 c, f32 t, unsigned long hh, f32 r, f32 sc3C, f32 *ph, f32 sc40, f32 *py, f32 b, f32 fl, s32 flags) {
    s32 o1, o2;
    f32 tt;
    s32 it;
    s32 fr;
    o1 = 0;
    o2 = 0;
    d->x0 = l * D_001D9698;
    d->x1 = r * D_001D9698;
    d->y0 = t * D_001D969C;
    d->y1 = b * D_001D969C;
    d->tx = tx * D_001D9698;
    if (flags & 2) d->ty = (t + (b - t) * 0.5f) * D_001D969C;
    else d->ty = ty * D_001D969C;
    tt = sc40 * D_001D969C;
    it = tt;
    d->ty += it;
    d->h = 0;
    d->w = 0;
    d->flags = flags;
    fr = (tt - it) * 16.0f;
    if (sc3C != 0.0f || sc40 != 0.0f) d->flags = flags | 8;
    d->f36 = fr;
    d->f30 = f44 * D_001D969C;
    d->f34 = (s32)(sc3C * D_001D9698) << 4;
    ((void (*)(void *, unsigned long, s32, s32, long, void *, s32, unsigned long, f32, s32 *, s32 *))func_00391210)(d, b1, c, dd, func_00389598(1), D_003357E0, g, hh, fl, &o1, &o2);
    *pw = d->w;
    *ph = d->h;
    *px = (f32)o1 / D_001D9698 + D_001D9690;
    *py = (f32)o2 / D_001D969C + D_001D9694;
    func_003E7160();
}

static __inline__ void TextB_3EB728(Desc_3EB728 *d, f32 tx, f32 *pw, f32 l, s32 flags, f32 ox, f32 f44, s32 c, f32 t, f32 r, f32 *ph, unsigned long b1, f32 b, f32 sc3C, f32 oy, f32 ty, f32 sc40, unsigned long hh, f32 fl) {
    f32 tt;
    s32 it;
    s32 fr;
    d->x0 = l * D_001D9698;
    d->x1 = r * D_001D9698;
    d->y0 = t * D_001D969C;
    d->y1 = b * D_001D969C;
    d->tx = tx * D_001D9698;
    d->f38 = ox * D_001D9698;
    d->f3A = oy * D_001D9698;
    if (flags & 2) d->ty = (t + (b - t) * 0.5f) * D_001D969C;
    else d->ty = ty * D_001D969C;
    tt = sc40 * D_001D969C;
    it = tt;
    d->ty += it;
    d->h = 0;
    d->w = 0;
    d->flags = flags;
    fr = (tt - it) * 16.0f;
    if (sc3C != 0.0f || sc40 != 0.0f) d->flags = flags | 8;
    d->f36 = fr;
    d->f30 = f44 * D_001D969C;
    d->f34 = (s32)(sc3C * D_001D9698) << 4;
    ((void (*)(void *, unsigned long, s32, s32, s32, s32, unsigned long, f32))func_003911F0)(d, b1, c, -1, 0, D_001D55C4, hh, fl);
    *pw = d->w / D_001D9698;
    *ph = d->h / D_001D969C;
    func_003E7160();
}

void func_003F0CF0(O_3EB728 *o, s32 a1) {
    f32 r[4];
    Desc_3EB728 d;
    s32 b40;
    s32 b44;
    f32 w;
    f32 h;
    f32 x0;
    f32 y0;
    f32 ox;
    f32 oy;
    s32 flags;
    P_3EB728 *p;

    if (o->p->f10 == 0 && o->p->f14 == 0) return;
    switch (o->p->b58) {
    case 1:
        func_0038E150(1);
        break;
    case 2:
        func_0038E150(0);
        break;
    case 0:
    default:
        func_0038E150(0);
        break;
    }
    o->vt->f20(o, a1, r, 1);
    func_003EDCF0(o, r);
    {
        f32 dx;
        dx = r[2] - r[0];
        x0 = r[0];
        if (o->p->h48 & 1) x0 += dx * 0.5f;
    }
    y0 = r[1];
    w = 0.0f;
    h = 0.0f;
    func_003F0BB8(o, &b40, &b44);
    flags = b40 == 1;
    if (b44 == 1) flags |= 2;
    if (func_003EDAF8(o, 0x40)) flags |= 0x20;
    ox = o->f20;
    oy = o->f24;
    if (func_003EDAF8(o, 0x40)) {
        if (o->p->h18 == 0) goto check4;
        func_00390CC8();
        {
        P_3EB728 *q = o->p;
        TextA_3EB728(&d, q->f44, y0 + oy, &w, &q->f2C, o->f28, q->h18, q->h1A, r[0] + ox, x0 + ox, q->f14, r[1] + oy, o->f28, r[2] + ox, q->f3C, &h, q->f40, &q->f30, r[3] + oy, q->f28, flags);
        }
        func_00390CA8();
    }
    p = o->p;
    if (p->h18 == 0) {
check4:
        if (o->p->h48 & 4) {
            flags |= 4;
            TextB_3EB728(&d, x0, &w, r[0], flags, ox, o->p->f44, o->p->f10, r[1], r[2], &h, o->p->f34, r[3], o->p->f3C, oy, y0, o->p->f40, o->f28, o->p->f28);
            flags &= ~4;
            if (r[3] - r[1] < h) {
                switch (o->p->b59) {
                case 0:
                    if (o->p->b5A == 0 && (o->p->h48 & 0x40)) o->p->f40 = (r[3] - r[1]) + 0.005f;
                    if ((s16)--o->p->h56 > 0) break;
                    o->p->h56 = 0;
                    o->p->b59++;
                    if (o->p->b5A != 0) {
                        f32 v;
                        f32 z;
                        if (o->p->h48 & 0x40) v = (r[3] - r[1]) + 0.005f;
                        else v = o->p->f40;
                        z = 0.0f;
                        if (!(o->p->h48 & 0x10)) z = v;
                        o->p->f40 = z;
                    } else {
                        o->p->b5A = 1;
                    }
                    /* fallthrough */
                case 1:
                    if (h + r[1] + o->p->f40 < r[1]) {
                        o->p->f40 = o->p->f40 - o->p->f50;
                        o->p->h56 = o->p->h54;
                        o->p->b59++;
                    } else {
                        o->p->f40 = o->p->f40 - o->p->f50;
                    }
                    break;
                case 2:
                    if ((s16)--o->p->h56 > 0) break;
                    o->p->h56 = o->p->h4C;
                    o->p->b59 = 0;
                    {
                        f32 v;
                        P_3EB728 *q = o->p;
                        if (!(q->h48 & 0x10)) v = (r[3] - r[1]) + 0.005f;
                        else v = 0.0f;
                        q->f40 = v;
                    }
                    break;
                }
            }
        }
        TextB_3EB728(&d, x0, &w, r[0], flags, ox, o->p->f44, o->p->f10, r[1], r[2], &h, o->p->f34, r[3], o->p->f3C, oy, y0, o->p->f40, o->f28, o->p->f28);
        o->b30 = 1;
        o->f34 = h;

    } else {
        TextA_3EB728(&d, p->f44, y0, &w, &p->f2C, p->f34, p->h18, p->h1A, r[0], x0, p->f14, r[1], p->f38, r[2], p->f3C, &h, p->f40, &p->f30, r[3], p->f28, flags);
    }
}
/* localdecomp:end func_003F0CF0 */
