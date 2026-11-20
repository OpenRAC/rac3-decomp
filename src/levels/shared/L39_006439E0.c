#include "common.h"

/* declared by functions of L39_0063EE68.c, which this file was cut from */
extern void func_L39_006439E0(u8 *);

/* localdecomp:start func_L39_006439E0 */
/* same code as func_L01_004ED188 (src/levels/shared/L01_004E7338.c), the single-player levels' copy */
typedef struct { u8 p0[0xC]; u8 bC; } T_006439E0;
typedef struct { u8 p0[0x20]; u8 b20; u8 p21[3]; T_006439E0 *w24; u8 p28[0x1B]; u8 b43; u8 p44[0x1C]; u8 b60; u8 p61[3]; void (*w64)(void *); } O_006439E0;
typedef struct { u8 p0[0x3C]; void (*f3C)(void *, s32); } V_006439E0;
typedef struct { u8 p0[0x450]; O_006439E0 *obj; u8 p454[0x17]; u8 b46B; u8 p46C[4]; s32 w470; s32 w474; s32 w478; } L_006439E0;
typedef struct { u8 p0[0x14]; V_006439E0 *vt; u8 p18[0x12F8]; s32 w1310; u8 p1314[0x700]; u8 b1A14; } S_006439E0;
extern s32 D_L39_0024B9C8;
extern void func_L39_00640738(void *, s32);
extern void func_L39_00644448(u8 *, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);

void func_L39_006439E0(u8 *a) {
    S_006439E0 *s = (S_006439E0 *)a;
    s32 i;
    for (i = 0; i < 6; i++) {
        L_006439E0 *l = (L_006439E0 *)((u8 *)s + i * 0x50);
        O_006439E0 *o = l->obj;
        if (o != 0) {
            switch (l->w474) {
            case 2:
                l->w470++;
                func_L39_00640738(s, i);
                if ((o->b60 & 2) && o->b43 == 0 && o->w24->bC >= 2)
                    func_003C3A10(o, 1, 0, 2);
                break;
            case 3:
                l->b46B++;
                if ((o->b60 & 2) || i == 1 || i == 0)
                    func_L39_00644448((u8 *)s, i, D_L39_0024B9C8 + 2);
                break;
            }
            s->vt->f3C(s, i);
            if (s->w1310 == 2 && s->b1A14 != 0 && i == 0 && ((L_006439E0 *)s)->w478 != 10)
                continue;
            if (o != 0 && o->b20 != 0xFE && o->b20 != 0xFD && i != 5 && o->w64 != 0)
                o->w64(o);
        } else {
            func_L39_00640738(s, i);
        }
    }
}
/* localdecomp:end func_L39_006439E0 */

/* localdecomp:start func_L39_00643B98 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_00643B98;
typedef union { u8 b[8]; u32 w[2]; } Buf_00643B98;
typedef struct {
    u8 pad0[0x34];
    u8 f34;
    u8 pad35[0x78 - 0x35];
    s32 f78;
} Obj_00643B98;
typedef struct {
    u8 pad0[0x450];
    Obj_00643B98 *obj;
    u8 pad454[0x470 - 0x454];
    s32 f470;
    u8 pad474[4];
    s32 f478;
    f32 f47C;
    u8 pad480[0x19E4 - 0x480];
    u8 b19E4;
    u8 pad19E5[0x1A07 - 0x19E5];
    u8 b1A07;
} G_00643B98;

extern u8 D_L39_004997E0[];
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D0B0(f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_L01_00470150(void *, s32, s32, s32, s32, s32, f32, f32, s32, s32, f32, s32, s32);

static __inline__ s32 Dec_00643B98(u8 *q) {
    Buf_00643B98 buf;
    
    u8 *d;
    long t;
    s32 x = 0;
    s32 n;
    s32 m;
    s32 k;
    s32 i;

    t = *q;
    if (t != 0) {
        n = *q;
        m = n + 1;
        k = ((s32)q - n) & 7;
        d = buf.b;
        for (i = 0; i < 40; i += 5) {
            *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
        }
        buf.w[0] ^= (u32)q;
        buf.w[1] ^= buf.w[0];
        x = buf.w[1];
    }
    return x;
}

static __inline__ s32 DecEq_00643B98(u8 *q, s32 v) {
    return Dec_00643B98(q) == v;
}

void func_L39_00643B98(u8 *a0) {
    G_00643B98 *a = (G_00643B98 *)a0;
    Obj_00643B98 *obj;
    s32 color;

    if (a->obj != 0 && !DecEq_00643B98(&a->b19E4, 0x63)) {
        obj = a->obj;
        if ((obj->f34 ^ 1) & 1) {
            if (a->f470 >= 0x13) {
                V4_00643B98 vec;
                V4_00643B98 unused;
                color = a->f470 - 12;
                if (color > 0x40) color = 0x40;
                if (color < 0) color = 0;
                color = (color << 24) | 0xFFFFFF;
                switch (a->f478) {
                case 5:
                    a->f47C = func_0038DAB8(a->f47C, 0.06283186f);
                    obj->f78 = func_0038DBD8(0xFF00FFFF, 0xFF104080, func_0038D0B0(a->f47C) * 0.5f + 0.5f);
                    *(u128_t *)&vec = 0;
                    vec.x = 0.333f;
                    vec.y = -0.05f;
                    func_L01_00470150(&vec, (s32)obj, obj->f78 & 0x35FFFFFF, -1, 1, 2, 73500.0f, 0.15f, 0, -1, 1.0f, 0, 0);
                    break;
                case 1:
                    *(u128_t *)&vec = 0;
                    vec.x = 0.195f;
                    vec.y = -0.317f;
                    if (a->b1A07 != 0) {
                        s32 r, m;
                        a->f47C = func_0038DAB8(a->f47C, 0.13962635f);
                        r = func_0038DBD8(obj->f78, func_0038DBD8(0xFF0040FF, 0xFF10BEBE, func_0038D0B0(a->f47C) * 0.5f + 0.5f), 0.264f);
                        obj->f78 = r;
                        m = 0x32FFFFFF;
                        if (color < m) m = color;
                        func_L01_00470150(&vec, (s32)obj, r & m, -1, 1, 2, 50400.0f, 0.15f, 0, -1, 1.0f, 0, 0);
                    } else {
                        s32 r, m;
                        a->f47C = func_0038DAB8(a->f47C, 0.048869222f);
                        r = func_0038DBD8(obj->f78, func_0038DBD8(0xFF0028C8, 0xFF10B4B4, func_0038D0B0(a->f47C) * 0.5f + 0.5f), 0.18f);
                        obj->f78 = r;
                        m = 0x38FFFFFF;
                        if (color < m) m = color;
                        func_L01_00470150(&vec, (s32)obj, r & m, -1, 1, 2, 50400.0f, 0.15f, 0, -1, 1.0f, 0, 0);
                    }
                    break;
                case 2:
                    a->f47C = func_0038DAB8(a->f47C, 0.06981318f);
                    obj->f78 = func_0038DBD8(0xFFDFDFDF, 0xFF20205F, func_0038D0B0(a->f47C) * 0.5f + 0.5f);
                    break;
                case 4:
                    break;
                }
            }
        }
    }
}
/* localdecomp:end func_L39_00643B98 */

/* localdecomp:start func_L39_00643F50 */
#include "vu0.h"

typedef int Q_00643F50 __attribute__((mode(TI)));
typedef struct {
    Q_00643F50 pos;
    vu0_v4 rot;
    u8 *obj[2];
    u8 pad28[0x3A - 0x28];
    u8 active;
    u8 pad3B[0x44 - 0x3B];
    s32 mode;
    s32 id;
    u8 pad4C[0x50 - 0x4C];
} Slot_00643F50;
typedef struct {
    vu0_v4 r[4];
} M_00643F50;
typedef struct {
    u8 pad0[0x430];
    Slot_00643F50 slots[6];
    u8 pad610[0x640 - 0x610];
    M_00643F50 mats[7];
} G_00643F50;
typedef struct {
    u8 pad0[0xA];
    s8 b0A;
    s8 b0B;
    u8 pad1[0x21 - 0xC];
    s8 b21;
    u8 pad2[0x80 - 0x22];
} Ent_00643F50;

extern Ent_00643F50 D_L39_0049C890[];
extern s32 D_L39_0047ABA8[];
extern s32 D_L39_00246100[];
extern s32 D_L39_00246118[];
extern void func_003C48A8(void *, void *);
extern void func_003C6FE0(void *);
extern void func_003C7C38(void *);
extern s32 func_L39_00648AE0(u8 *, s32);
extern s32 func_L39_006319D8(char *, s32);
extern void func_0038D590(void *, void *);
extern void func_L39_006445F8(s32, s32 *, void *, u8 *, s32);
typedef void (*Fn6445F8_00643F50)(s32, s32 *, void *, u8 *, s32, u8 *);
extern void func_L39_00644878(u8 *, u8 *, u8 *, s32);
extern void func_003C2EC0(void *, s32, void *);
extern void func_0038D308(void *, void *);
extern s32 func_L39_006212E8(void *);
extern void func_0038D570(void *, void *);

static __inline__ s32 Sub_00643F50(u8 *s) {
    if (*(s32 *)(s + 0x474) == 2) {
        return *(s32 *)(s + 0x478);
    }
    return -1;
}

void func_L39_00643F50(u8 *g, u8 *target)
{
    vu0_v4 mat[4];
    u8 *slot;
    u8 *obj;
    u8 *p;
    Ent_00643F50 *e;
    s32 i;
    s32 k;
    s32 n;
    s32 m;
    s32 x;
    s32 t;
    s32 flag;
    s32 c;
    s32 r;
    s32 res;
    s32 *anim0 = D_L39_00246100;
    s32 *anim1 = D_L39_00246118;

    if (target == 0) {
        target = *(u8 **)(g + 0x2524);
    }
    for (i = 0; i < 6; i++) {
        for (k = 0; k < 2 && (k < 1 || i == 1 || i == 3 || i == 4); k = n) {
            slot = g + i * 0x50;
            obj = *(u8 **)(slot + 0x450);
            if (k == 1) {
                obj = *(u8 **)(slot + 0x454);
            }
            n = k + 1;
            if (obj == 0) {
                goto next;
            }
            *(long *)(obj + 0x38) = *(long *)(*(u8 **)(g + 0x2524) + 0x38);
            m = 0;
            if (i != 0) {
                m = n;
            }
            if (slot[0x46A] != 0) {
                *(Q_00643F50 *)(slot + 0x430) = *(Q_00643F50 *)&((G_00643F50 *)g)->mats[m].r[3];
                func_003C48A8(&((G_00643F50 *)g)->mats[m], &((G_00643F50 *)g)->slots[i].rot);
                func_003C6FE0(obj);
                func_003C7C38(obj);
                *(u16 *)(obj + 0x34) &= 0xFEFB;
                goto tail;
            }
            *(Q_00643F50 *)(obj + 0x10) = *(Q_00643F50 *)&((G_00643F50 *)g)->mats[m].r[3];
            if (*(s32 *)(g + 0x24AC) != 0) {
                x = *(s32 *)(slot + 0x478);
                if (func_L39_00648AE0(g, x)) {
                    Ent_00643F50 *tab = D_L39_0049C890;
                    e = &tab[tab[x].b21];
                } else {
                    e = &D_L39_0049C890[x];
                }
                if (e->b0B != 0) {
                    goto special;
                }
            }
            flag = 0;
            if (i == 0) {
                t = Sub_00643F50(g);
                if (t == 6 || t == 12) {
                    c = 1;
                } else {
                    c = 0;
                }
                if (c != 0) {
                    flag = 1;
                }
            }
            r = func_L39_006319D8((char *)g, i);
            *(u16 *)(obj + 0x34) |= 0x106;
            if (flag == 0 && r == 0) {
                func_003C6FE0(obj);
            }
            func_0038D590(obj + 0xC0, &((G_00643F50 *)g)->mats[m]);
            func_003C7C38(obj);
            if ((u32)((*(u8 **)(g + 0x2524))[0x42] - 0x40) < 2) {
                *(f32 *)(obj + 0xC) += 1800.0f;
            }
            if (flag != 0) {
                ((Fn6445F8_00643F50)func_L39_006445F8)((s32)g, D_L39_0047ABA8, g + 0x3D00, *(u8 **)(obj + 0x24), 0, target);
                *(u8 **)(obj + 0x58) = g + 0x3D00;
                *(u8 **)(obj + 0x5C) = g + 0x3D00;
                *(s32 *)(obj + 0x44) = 0;
                *(s32 *)(obj + 0x40) = 0;
            } else if (r != 0) {
                if (k == 0) {
                    ((Fn6445F8_00643F50)func_L39_006445F8)((s32)g, anim0, g + 0x4100, *(u8 **)(obj + 0x24), 0, target);
                    *(u8 **)(obj + 0x58) = g + 0x4100;
                    *(u8 **)(obj + 0x5C) = g + 0x4100;
                } else {
                    ((Fn6445F8_00643F50)func_L39_006445F8)((s32)g, anim1, g + 0x4200, *(u8 **)(obj + 0x24), 0, target);
                    *(u8 **)(obj + 0x58) = g + 0x4200;
                    *(u8 **)(obj + 0x5C) = g + 0x4200;
                }
                *(s32 *)(obj + 0x44) = 0;
                *(s32 *)(obj + 0x40) = 0;
            }
            goto cam;
        special:
            func_003C6FE0(obj);
            if (*(s32 *)(g + 0x24AC) == 0 || i != 0) {
                func_003C48A8(&((G_00643F50 *)g)->mats[m], obj + 0xF0);
            } else {
                func_L39_00644878(g, obj, &((G_00643F50 *)g)->mats[m], 1);
            }
            func_003C7C38(obj);
            *(u16 *)(obj + 0x34) |= 6;
        cam:
            p = *(u8 **)(g + 0x251C);
            if (p != 0) {
                if (*(s32 *)(g + 0x2528) == 0) {
                    u8 *q = g + i * 0x50;
                    if (Sub_00643F50(q) == 10) {
                        *(Q_00643F50 *)(p + 0x10) = *(Q_00643F50 *)&((G_00643F50 *)g)->mats[m].r[3];
                        func_0038D590(*(u8 **)(g + 0x251C) + 0xC0, &((G_00643F50 *)g)->mats[m]);
                        *(u16 *)(obj + 0x34) |= 1;
                    } else if (Sub_00643F50(q) == 11) {
                        x = 10;
                        if (func_L39_00648AE0(g, x)) {
                            e = &D_L39_0049C890[D_L39_0049C890[x].b21];
                        } else {
                            e = &D_L39_0049C890[x];
                        }
                        func_003C2EC0(*(u8 **)(g + 0x2524), e->b0A, mat);
                        *(Q_00643F50 *)(*(u8 **)(g + 0x251C) + 0x10) = *(Q_00643F50 *)&mat[3];
                        func_0038D590(*(u8 **)(g + 0x251C) + 0xC0, mat);
                    }
                } else {
                    qzero(&mat[0]);
                    mat[0].y += -1.5707964f;
                    func_0038D308(p + 0xC0, mat);
                    *(Q_00643F50 *)(*(u8 **)(g + 0x251C) + 0x10) = *(Q_00643F50 *)(g + 0xA0);
                }
                res = func_L39_006212E8(g);
                if ((u32)(res - 10) >= 2 && res != -1) {
                    c = 1;
                    g[0x1A0E] = c;
                }
            }
        tail:
            if (i == 0) {
                func_0038D570(g + 0x1380, obj + 0xC0);
                *(Q_00643F50 *)(g + 0x13B0) = *(Q_00643F50 *)(obj + 0x10);
            }
        next:;
        }
    }
}
/* localdecomp:end func_L39_00643F50 */
