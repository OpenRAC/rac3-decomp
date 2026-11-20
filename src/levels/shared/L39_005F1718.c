#include "common.h"

/* declared by functions of L39_005F1470.c, which this file was cut from */
extern u8 D_001FE020[];
extern void func_00193BB0(s32, s32);
extern void func_L39_005F1470(void);

/* localdecomp:start func_L39_005F1718 */
#include "vu0.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_005F1718;
typedef struct { u8 pad0[0x18]; u8 b18; u8 b19; s16 s1A; s32 s1C; } Info_005F1718;
typedef struct { u8 pad0[0x10]; V4_005F1718 pos; u8 b20; u8 pad21[0xC0 - 0x21]; u8 mtx[0x40]; } Moby_005F1718;
typedef struct {
    u32 handle;                 /* 0x00 */
    Info_005F1718 *info;        /* 0x04 */
    s32 pad08;                  /* 0x08 */
    s16 vol;                    /* 0x0C */
    u16 cnt;                    /* 0x0E */
    u8 state;                   /* 0x10 */
    u8 pad11[2];
    u8 b13;                     /* 0x13 */
    s32 s14;                    /* 0x14 */
    s32 s18;                    /* 0x18 */
    Moby_005F1718 *moby;        /* 0x1C */
    V4_005F1718 pos;            /* 0x20 */
    V4_005F1718 offs;           /* 0x30 */
    s32 s40;                    /* 0x40 */
    u8 pad44[8];
    s32 s4C;                    /* 0x4C */
    u8 pad50[4];
    u8 b54[4];                  /* 0x54 */
    s32 flags;                  /* 0x58 */
    u8 b5C[36];                 /* 0x5C */
} Slot_005F1718;
typedef struct {
    s32 vol[8];                 /* 0x00 */
    s32 prev[8];                /* 0x20 */
    u8 b40, b41, b42, b43;      /* 0x40 */
    s32 s44;                    /* 0x44 */
    s32 ring_i;                 /* 0x48 */
    s32 pad4C;
    V4_005F1718 ring[4];        /* 0x50 */
    s32 tbl90[6];               /* 0x90 */
    s32 sA8;                    /* 0xA8 */
    s16 sAC;                    /* 0xAC */
    s16 sAE;                    /* 0xAE */
    s32 padB0;
    s32 sB4;                    /* 0xB4 */
    u8 padB8[8];
    Slot_005F1718 slots[52];    /* 0xC0 */
    V4_005F1718 vecs[6];        /* 0x1AC0 */
    s32 f1B20;                  /* 0x1B20 */
} G_005F1718;

extern s32 D_L39_0024E2D0[];
extern V4_005F1718 D_L39_0024DE00;
extern s32 D_L39_00241128;
extern s32 D_L39_0024112C;
extern u8 D_L39_002429AC;
extern s32 D_L39_002428F0;
extern s16 D_001FC360 __attribute__((section(".data")));

extern s32 func_00193590(void);
extern void func_00193BB0(s32, s32);
extern void func_00193D38(s32, s32, s32, s32, s32, s32, void *, void *);
extern void func_00193D98(s32);
extern void func_00193E80(s32, void *, void *);
extern void func_00193F08(s32, s32, s32, s32, s32, s32, void *, void *);
extern void func_00194668(void);
extern void func_00194670(void);
extern void func_00194BC8(s32, s32, s32, s32, s32);
extern void func_00194C40(s32, s32, s32, s32);
extern s32 func_00194E30(s32);
extern s32 func_L39_00577818(void);
extern s32 func_0038CAD0(void *);
extern void func_0038CB78(void *, s32, s32);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038D000(void *, void *, void *);
extern s32 func_L39_00590A38(u8 *, s32);
extern void func_L39_005C2148(void);
extern void func_L39_005F0FA0(void *, void *);
extern u8 func_L39_005F1058(void *, void *, s32);
extern s32 func_003A3DC8(void *, void *, void *, void *);
extern s32 func_003A3E28(void *, void *);
extern void func_003A5508(s32, long);
extern void func_003A5550(s32, long);
extern u8 *func_L39_0061BF38(s32);
extern void func_L39_005F1470(void);

static __inline__ void copy_005F1718(V4_005F1718 *d, V4_005F1718 *s) {
    *d = *s;
}

s32 func_L39_005F1718(void) {
    V4_005F1718 pos;
    V4_005F1718 acc;
    V4_005F1718 d;
    V4_005F1718 t;
    s32 i;
    s32 snd = D_L39_0024E2D0[0];
    f32 zero;
    s32 *flags;
    s32 *vols;
    f32 *dists;
    Slot_005F1718 *sl = ((G_005F1718 *)D_001FE020)->slots;

    func_00193590();
    zero = 0.0f;
    func_L39_005F1470();
    {
        u8 fl = ((G_005F1718 *)D_001FE020)->b43;
        if (fl & 8) {
            func_00194BC8(2, 0, 0, 0, 0);
        } else if (fl & 0x13) {
            func_00194BC8(2, ((G_005F1718 *)D_001FE020)->b40, ((G_005F1718 *)D_001FE020)->sB4,
                          ((G_005F1718 *)D_001FE020)->b41, ((G_005F1718 *)D_001FE020)->b42);
        } else if (fl & 4) {
            func_00194C40(2, ((G_005F1718 *)D_001FE020)->sB4, 0xC, 3);
        }
    }
    ((G_005F1718 *)D_001FE020)->b43 = 0;
    if (func_L39_00577818() == 0 && (D_L39_00241128 == 0 || D_L39_00241128 == 2) && D_L39_002429AC == 0) {
        func_L39_005F0FA0(&pos, 0);
    }
    {
        s32 j, k, n, h;
        f32 base;
        u8 *p;
        n = 0;
        qzero(&acc);
        h = ((G_005F1718 *)D_001FE020)->ring_i + 1;
        h %= 4;
        ((G_005F1718 *)D_001FE020)->ring_i = h;
        copy_005F1718(&((G_005F1718 *)D_001FE020)->ring[h], &D_L39_0024DE00);
        base = 0.0f;
        p = func_L39_0061BF38(0);
        if (p != 0) {
            base = func_0038CEA8(p + 0x180);
        }
        j = ((G_005F1718 *)D_001FE020)->ring_i;
        k = (j + 3) % 4;
        if (k != j) {
            do {
                vec_sub_ab(&d, &((G_005F1718 *)D_001FE020)->ring[j], &((G_005F1718 *)D_001FE020)->ring[k]);
                if (!(func_0038CEA8(&d) < base + 1.2f)) {
                    break;
                }
                j = k;
                vec_add_ab(&acc, &acc, &d);
                k = (j + 3) % 4;
                n++;
            } while (k != ((G_005F1718 *)D_001FE020)->ring_i);
        }
        if (n >= 2) {
            func_0038CE20(&acc, &acc, 1.0f / n);
        }
    }
    if (D_L39_002428F0 != 0 || ((G_005F1718 *)D_001FE020)->sAC > 0) {
        f32 div = 1.0f;
        f32 v = ((G_005F1718 *)D_001FE020)->vol[0];
        s32 r;
        if (D_L39_002428F0 == 0) {
            if (((G_005F1718 *)D_001FE020)->sAC == 2) {
                ((G_005F1718 *)D_001FE020)->sAC = 3;
                ((G_005F1718 *)D_001FE020)->sAE = 25;
            }
        } else if (((G_005F1718 *)D_001FE020)->sAC == 0) {
            if (D_L39_002428F0 == 2) {
                ((G_005F1718 *)D_001FE020)->sAC = 2;
            } else {
                ((G_005F1718 *)D_001FE020)->sAC = 1;
                ((G_005F1718 *)D_001FE020)->sAE = 25;
            }
        }
        ((G_005F1718 *)D_001FE020)->sAE--;
        switch (((G_005F1718 *)D_001FE020)->sAC) {
        case 3:
            div = ((G_005F1718 *)D_001FE020)->sAE / 25.0f * 3.0f + 1.0f;
            if (((G_005F1718 *)D_001FE020)->sAE <= 0) {
                ((G_005F1718 *)D_001FE020)->sAC = 0;
            }
            break;
        case 1:
            div = (1.0f - ((G_005F1718 *)D_001FE020)->sAE / 25.0f) * 3.0f + 1.0f;
            if (((G_005F1718 *)D_001FE020)->sAE <= 0) {
                ((G_005F1718 *)D_001FE020)->sAC = 2;
            }
            break;
        case 2:
            div = 4.0f;
            break;
        }
        v /= div;
        r = v;
        func_00193BB0(0, r);
        func_00193BB0(3, r);
    } else if (D_L39_00241128 == 2 || (D_L39_00241128 == 6 && (D_001FC360 == 3 || D_001FC360 == 0))) {
        ((G_005F1718 *)D_001FE020)->vol[1] = 0;
        func_00193BB0(1, 0);
        ((G_005F1718 *)D_001FE020)->vol[0] >>= 1;
        func_00193BB0(0, ((G_005F1718 *)D_001FE020)->vol[0]);
        ((G_005F1718 *)D_001FE020)->vol[3] >>= 1;
        func_00193BB0(3, ((G_005F1718 *)D_001FE020)->vol[3]);
    } else {
        if (((G_005F1718 *)D_001FE020)->f1B20 & 2) {
            s32 v = ((G_005F1718 *)D_001FE020)->vol[1];
            if (snd != 0) {
                v = v * 3 / 5;
            }
            ((G_005F1718 *)D_001FE020)->vol[1] = v;
            func_00193BB0(1, v);
        }
        if (((G_005F1718 *)D_001FE020)->f1B20 & 1) {
            func_00193BB0(0, ((G_005F1718 *)D_001FE020)->vol[0]);
        }
        if (((G_005F1718 *)D_001FE020)->f1B20 & 8) {
            func_00193BB0(3, ((G_005F1718 *)D_001FE020)->vol[3]);
        }
    }
    if (((G_005F1718 *)D_001FE020)->f1B20 & 0x10) {
        func_00193BB0(4, ((G_005F1718 *)D_001FE020)->vol[4]);
    }
    if (((G_005F1718 *)D_001FE020)->f1B20 & 4) {
        func_00193BB0(2, ((G_005F1718 *)D_001FE020)->vol[2]);
        func_00193BB0(6, ((G_005F1718 *)D_001FE020)->vol[2]);
    }
    if (((G_005F1718 *)D_001FE020)->f1B20 & 0x20) {
        func_00193BB0(5, ((G_005F1718 *)D_001FE020)->vol[5]);
    }

    flags = (s32 *)0x70000000;
    func_0038CB78(flags, 0, 0xD0);
    vols = flags + 52;
    func_0038CB78(vols, 0, 0xD0);
    dists = (f32 *)(vols + 52);
    func_0038CB78(dists, 0, 0xD0);

    for (i = 0; i < 52; i++) {
        Moby_005F1718 *m;
        s32 dead;
        if (sl[i].state != 7 && (sl[i].handle == 0 || sl[i].handle == 0xFFFFFFFF)) {
            continue;
        }
        m = sl[i].moby;
        dead = 0;
        if (m != 0 && (m->b20 == 0xFE || sl[i].moby->b20 == 0xFD)) {
            dead = 1;
        }
        if (dead) {
            sl[i].moby = 0;
        }
        if (func_0038CAD0(sl[i].b54) == 0) {
            continue;
        }
        if (sl[i].state == 4 || (sl[i].state != 6 && dead && sl[i].info->b18 != 0)) {
            flags[i] = 0x20;
            continue;
        }
        if (D_L39_00241128 == 0 || D_L39_00241128 == 2 || D_L39_00241128 == 6 || sl[i].state == 7) {
            s32 r;
            if (sl[i].flags & 0x100) {
                copy_005F1718(&sl[i].pos, &D_L39_0024DE00);
            }
            if (sl[i].moby != 0 && !(sl[i].flags & 8)) {
                if (sl[i].flags & 0x40) {
                    func_0038D000(&t, &sl[i].offs, m->mtx);
                    vec_add_ba(&t, &t, &m->pos);
                    vec_sub_ba(&d, &t, &sl[i].pos);
                    copy_005F1718(&sl[i].pos, &t);
                } else {
                    sl[i].pos.z -= 1.0f;
                    vec_sub_ab(&d, &sl[i].moby->pos, &sl[i].pos);
                    copy_005F1718(&sl[i].pos, &sl[i].moby->pos);
                    sl[i].pos.z += 1.0f;
                }
            } else {
                qzero(&d);
            }
            vec_sub_ab(&d, &d, &acc);
            vec_sub_ab(&t, &D_L39_0024DE00, &sl[i].pos);
            func_0038CF68(&t, &t, 1.0f);
            dists[i] = func_0038CE68(&t, &d);
            if (!(sl[i].flags & 0x10)) {
                r = func_003A3DC8(&sl[i], &sl[i].pos, 0, 0);
                vols[i] = r * sl[i].vol / 1024;
                if (!(sl[i].info->b19 & 2)) {
                    flags[i] |= 8;
                }
            } else {
                vols[i] = sl[i].vol;
                r = 0x400;
                if (sl[i].flags & 0x200) {
                    flags[i] |= 8;
                }
            }
            if (snd != 0 && !(sl[i].info->b19 & 4) && zero < sl[i].pos.z) {
                vols[i] /= 2;
            }
            flags[i] |= 1;
            if (r < 0x20 && vols[i] < 0x20 && (sl[i].flags & 4)) {
                flags[i] = 0x20;
                continue;
            }
            if (((u8)sl[i].flags ^ 1) & 1) {
                flags[i] |= 2;
                if (!(sl[i].flags & 0x20) && !(sl[i].info->b19 & 0x10)) {
                    flags[i] |= 4;
                }
            }
        } else {
            flags[i] = 0x10;
        }
    }

    for (i = 0; i < 52; i++) {
        s32 n;
        if (!(flags[i] & 8) || func_L39_00577818() != 0) {
            continue;
        }
        if (sl[i].state == 7) {
            s32 j, k, m;
            if ((D_L39_00241128 != 0 && D_L39_00241128 != 2) || D_L39_002429AC != 0) {
                continue;
            }
            n = 0;
            if (D_L39_0024112C != ((G_005F1718 *)D_001FE020)->sA8) {
                for (j = 0; j < 6; j++) {
                    func_L39_005F0FA0(&((G_005F1718 *)D_001FE020)->vecs[j], 0);
                }
                ((G_005F1718 *)D_001FE020)->sA8 = D_L39_0024112C;
            }
            for (k = 0, j = 0; k < 36; j++, k += 6) {
                sl[i].b5C[k] = func_L39_005F1058(&sl[i], &((G_005F1718 *)D_001FE020)->vecs[j], 0);
                for (m = 1; m < 6; m++) {
                    sl[i].b5C[k + m] = sl[i].b5C[k];
                }
                if (sl[i].b5C[k] != 0) {
                    n += 6;
                }
            }
            if (n >= 36) {
                vols[i] = 0;
            } else if (n >= 19) {
                vols[i] = (36 - n) * vols[i] / 18;
            }
        } else {
            s32 c;
            if ((D_L39_00241128 == 0 || D_L39_00241128 == 2) && D_L39_002429AC == 0) {
                s32 t2;
                sl[i].cnt = (sl[i].cnt + 1) % 36;
                t2 = (i ^ D_L39_0024112C) & 1;
                if (!(sl[i].flags & 4)) {
                    t2 = (i & 3) == (D_L39_0024112C & 3);
                }
                if (t2) {
                    sl[i].b5C[sl[i].cnt] = func_L39_005F1058(&sl[i], &pos, 0);
                } else {
                    sl[i].b5C[sl[i].cnt] = sl[i].b5C[(sl[i].cnt + 35) % 36];
                }
            }
            c = func_L39_00590A38(sl[i].b5C, 36);
            if (c >= 36) {
                vols[i] = 0;
            } else if (c >= 19) {
                vols[i] = (36 - c) * vols[i] / 18;
            }
        }
    }

    for (i = 0; i < 52; i++) {
        s32 h;
        if (flags[i] == 0) {
            continue;
        }
        h = sl[i].handle;
        sl[i].handle = 0xFFFFFFFF;
        if (flags[i] & 0x20) {
            if (sl[i].state == 7) {
                sl[i].moby = 0;
                sl[i].s40 = 0;
                sl[i].state = 0;
                continue;
            }
            func_00193D98(h);
            sl[i].state = 6;
            func_00193E80(h, func_003A5550, &((G_005F1718 *)D_001FE020)->slots[i]);
            ((G_005F1718 *)D_001FE020)->slots[i].s4C = ((G_005F1718 *)D_001FE020)->slots[i].b13;
        } else if (flags[i] & 0x10) {
            func_00193E80(h, func_003A5550, &((G_005F1718 *)D_001FE020)->slots[i]);
            ((G_005F1718 *)D_001FE020)->slots[i].s4C = ((G_005F1718 *)D_001FE020)->slots[i].b13;
        } else {
            s32 a7 = 0;
            s32 a8 = 0;
            s32 a9 = sl[i].s14;
            s32 mode = 1;
            if ((flags[i] & 2) && !(sl[i].flags & 0x100)) {
                a7 = func_003A3E28(&sl[i], &sl[i].pos);
                mode = 7;
            }
            if (flags[i] & 4) {
                mode |= 8;
                {
                    f32 dd = dists[i];
                    if (sl[i].flags & 2) {
                        dd *= 500.0f;
                    } else {
                        dd *= 300.0f;
                    }
                    a8 = func_00194E30(dd);
                }
            }
            if (a9 != 0) {
                mode |= 0x10;
            }
            if (sl[i].s18 != 0) {
                a8 += sl[i].s18;
                mode |= 8;
            }
            if (snd != 0 && !(sl[i].info->b19 & 8)) {
                mode |= 8;
                a8 -= 0x5F4;
            }
            if (sl[i].state != 7) {
                func_00193F08(h, mode, vols[i] > 0x400 ? 0x400 : vols[i], a7, a8, a9, func_003A5550, &((G_005F1718 *)D_001FE020)->slots[i]);
                ((G_005F1718 *)D_001FE020)->slots[i].s4C = ((G_005F1718 *)D_001FE020)->slots[i].b13;
            } else {
                Info_005F1718 *inf = sl[i].info;
                s32 c;
                if (inf == 0 || (c = ((G_005F1718 *)D_001FE020)->tbl90[inf->s1C]) == -1 || c == 0) {
                    sl[i].moby = 0;
                    sl[i].s40 = 0;
                    sl[i].state = 0;
                } else {
                    sl[i].state = 1;
                    func_00193D38(((G_005F1718 *)D_001FE020)->tbl90[inf->s1C], inf->s1A,
                                  vols[i] > 0x400 ? 0x400 : vols[i], a7, a8, a9, func_003A5508, &((G_005F1718 *)D_001FE020)->slots[i]);
                }
            }
        }
    }

    func_L39_005C2148();
    func_00194670();
    func_00193590();
    func_00194668();
    ((G_005F1718 *)D_001FE020)->s44 = 0;
    ((G_005F1718 *)D_001FE020)->f1B20 = 0;
    return 0;
}
/* localdecomp:end func_L39_005F1718 */

INCLUDE_ASM("asm/levels", func_L39_005F26E8);
