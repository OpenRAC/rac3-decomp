/* Unlinked regional matching draft. PAL: 423 words; timer pointer, callback loads, ring setup and division padding remain. */
/* PAL frontbin near miss (Nov 24): 423 raw positional words differ with the
 * owning 3A3B70.c flags. Ported from the read-only boot_elf mixer draft by
 * pairing each retail reference at the same instruction offset. The stack
 * frame is 0x370 as in retail. Initializing the Doppler multiplier to 300
 * before the optional 500 override improves the translated baseline (430).
 * Still differs in ring setup, ramp division padding and channel iteration:
 * the first pass lacks a reduced timer pointer, and the second reuses its
 * channel pointer instead of rebuilding callback arguments from byte offsets.
 * The aliases here are for stand-alone checking, not yet linked into frontbin.
 */
#include "common.h"
#include "vu0.h"

typedef int u128_3A4288 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3A4288;
typedef struct {
    u8 p0[0x18]; u8 b18; u8 b19; s16 h1A; s32 i1C;
} Def_3A4288;
typedef struct {
    u8 p0[0x10]; V4_3A4288 pos; u8 b20; u8 p21[0xC0 - 0x21]; u8 mtx[0x40];
} Obj_3A4288;
typedef struct {
    u32 handle;            /* 0x00 */
    Def_3A4288 *def;       /* 0x04 */
    u8 p8[4];
    s16 vol;               /* 0x0C */
    u8 pE[2];
    u8 state;              /* 0x10 */
    u8 p11[2];
    u8 b13;                /* 0x13 */
    s32 i14;               /* 0x14 */
    s32 pitch;             /* 0x18 */
    Obj_3A4288 *obj;       /* 0x1C */
    V4_3A4288 pos;         /* 0x20 */
    V4_3A4288 offset;      /* 0x30 */
    s32 i40;               /* 0x40 */
    u8 p44[8];
    s32 i4C;               /* 0x4C */
    u8 p50[4];
    u8 timer[4];           /* 0x54 */
    s32 flags;             /* 0x58 */
    u8 p5C[0x80 - 0x5C];
} Ch_3A4288;
typedef struct {
    s32 i0, i4, i8, iC, i10, i14;  /* 0x00: bus volumes */
    u8 p18[0x40 - 0x18];
    u8 b40, b41, b42, b43;         /* 0x40 */
    s32 i44;                       /* 0x44 */
    s32 i48;                       /* 0x48: ring index */
    u8 p4C[4];
    V4_3A4288 ring[4];             /* 0x50 */
    s32 snd[7];                    /* 0x90 */
    s16 hAC;                       /* 0xAC */
    s16 hAE;                       /* 0xAE */
    u8 pB0[4];
    s32 iB4;                       /* 0xB4 */
    u8 pB8[8];
    Ch_3A4288 ch[52];              /* 0xC0 */
    u8 p1AC0[0x1B20 - 0x1AC0];
    s32 i1B20;                     /* 0x1B20 */
} Mgr_3A4288;

extern Mgr_3A4288 D_1A30B0_003A4288;
extern Ch_3A4288 D_1A3170[];
extern s32 D_002228D0[];
extern f32 D_1A4F30[];
extern u8 D_001D5BDC;
extern s32 D_001D5B70;
extern s32 D_001D5B94;
extern s16 D_16C5A0;
extern V4_3A4288 D_1A4D30;
extern V4_3A4288 D_00222400_003A4288;
extern void func_13B620(void);
extern void func_003A3FE0(void);
extern void func_003A3C30(void *, void *);
extern void func_13CF80(s32, s32, s32, s32, s32);
extern void func_13CFF8(s32, s32, s32, s32);
extern s32 func_13BF30(s32, s32);
extern void func_13C118(s32);
extern void func_13C200(s32, void *, void *);
extern void func_13C2C0(s32, s32, s32, s32, s32, s32, void *, void *);
extern void func_13C0B8(s32, s32, s32, s32, s32, s32, void *, void *);
extern s32 func_13D1E8(s32);
extern void func_13CA28(void);
extern void func_13CA20(void);
extern void func_003A1F30(void);
extern void func_003A5550();
extern void func_003A5508();
extern s32 func_0038CAD0(void *);
extern void func_0038CB78(void *, s32, s32);
extern void func_0038D000(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038CEA8(void *);
extern void func_0038CE20(void *, void *, f32);
/* The frontbin callee returns the channel attenuation. */
extern s32 func_003A3DC8_003A4288(void *, void *, void *, void *);
extern s32 func_003A3E28_003A4288(void *, void *);

s32 func_003A4288(void) {
    V4_3A4288 lis;
    V4_3A4288 acc;
    V4_3A4288 vel;
    s32 act[52];
    s32 vol[52];
    f32 dop[52];
    V4_3A4288 tmp;
    s32 has_x;
    vu0_q qa, qb, qc, qd;
    Ch_3A4288 *ch;
    Obj_3A4288 *obj;
    s32 a, b, n, cnt, i, r, v, flags, pan, pitch, h, i14, dead;
    s32 s, m, st, k, fl;
    f32 cut, speed, f, div;

    has_x = D_002228D0[0];
    cut = 0.0f;
    if (has_x != 0) {
        cut = D_1A4F30[0];
    }
    func_13B620();
    func_003A3FE0();
    {
    Ch_3A4288 *c0 = D_1A30B0_003A4288.ch;
    Mgr_3A4288 *mg = (Mgr_3A4288 *)((u8 *)c0 - 0xC0);
    m = mg->b43;
    if (m & 8) {
        func_13CF80(2, 0, 0, 0, 0);
    } else if (m & 0x13) {
        func_13CF80(2, mg->b40, mg->iB4, mg->b41, mg->b42);
    } else if (m & 4) {
        func_13CFF8(2, mg->iB4, 0xC, 3);
    }
    }
    D_1A30B0_003A4288.b43 = 0;
    if ((D_001D5B94 == 0 || D_001D5B94 == 2) && D_001D5BDC == 0) {
        func_003A3C30(&lis, 0);
    }

    n = (D_1A30B0_003A4288.i48 + 1) % 4;
    qzero(&acc);
    D_1A30B0_003A4288.i48 = n;
    *(u128_3A4288 *)&D_1A30B0_003A4288.ring[n] = *(u128_3A4288 *)&D_00222400_003A4288;
    speed = func_0038CEA8(&D_1A4D30);
    a = D_1A30B0_003A4288.i48;
    b = (a + 3) % 4;
    cnt = 0;
    if (b != a) {
        do {
            vec_sub_ab(&vel, &D_1A30B0_003A4288.ring[a], &D_1A30B0_003A4288.ring[b]);
            if (!(func_0038CEA8(&vel) < speed + 1.2f)) {
                break;
            }
            a = b;
            vec_add_ab(&acc, &acc, &vel);
            b = (b + 3) % 4;
            cnt++;
        } while (b != D_1A30B0_003A4288.i48);
    }
    if (cnt >= 2) {
        func_0038CE20((f32 *)&acc, &acc, 1.0f / (f32)cnt);
    }

    if (D_001D5B70 != 0 || D_1A30B0_003A4288.hAC > 0) {
        div = 1.0f;
        f = (f32)D_1A30B0_003A4288.i0;
        if (D_001D5B70 == 0) {
            if (D_1A30B0_003A4288.hAC == 2) {
                D_1A30B0_003A4288.hAC = 3;
                D_1A30B0_003A4288.hAE = 25;
            }
        } else if (D_1A30B0_003A4288.hAC == 0) {
            if (D_001D5B70 == 2) {
                D_1A30B0_003A4288.hAC = 2;
            } else {
                D_1A30B0_003A4288.hAC = 1;
                D_1A30B0_003A4288.hAE = 25;
            }
        }
        s = (u16)D_1A30B0_003A4288.hAE - 1;
        D_1A30B0_003A4288.hAE = s;
        switch (D_1A30B0_003A4288.hAC) {
        case 3:
            div = (f32)(s16)s / 25.0f * 3.0f + 1.0f;
            if ((s16)s <= 0) {
                D_1A30B0_003A4288.hAC = 0;
            }
            break;
        case 1:
            div = (1.0f - (f32)(s16)s / 25.0f) * 3.0f + 1.0f;
            if ((s16)s <= 0) {
                D_1A30B0_003A4288.hAC = 2;
            }
            break;
        case 2:
            div = 4.0f;
            break;
        }
        f /= div;
        v = (s32)f;
        func_13BF30(0, v);
        func_13BF30(3, v);
    } else if (D_001D5B94 == 2 || (D_001D5B94 == 6 && (D_16C5A0 == 3 || D_16C5A0 == 0))) {
        D_1A30B0_003A4288.i4 = 0;
        func_13BF30(1, 0);
        D_1A30B0_003A4288.i0 >>= 1;
        func_13BF30(0, D_1A30B0_003A4288.i0);
        D_1A30B0_003A4288.iC >>= 1;
        func_13BF30(3, D_1A30B0_003A4288.iC);
    } else {
        if (D_1A30B0_003A4288.i1B20 & 2) {
            s32 w = D_1A30B0_003A4288.i4;
            if (has_x != 0) {
                w = w * 3 / 5;
            }
            D_1A30B0_003A4288.i4 = w;
            func_13BF30(1, w);
        }
        if (D_1A30B0_003A4288.i1B20 & 1) {
            func_13BF30(0, D_1A30B0_003A4288.i0);
        }
        if (D_1A30B0_003A4288.i1B20 & 8) {
            func_13BF30(3, D_1A30B0_003A4288.iC);
        }
    }
    if (D_1A30B0_003A4288.i1B20 & 0x10) {
        func_13BF30(4, D_1A30B0_003A4288.i10);
    }
    if (D_1A30B0_003A4288.i1B20 & 4) {
        func_13BF30(2, D_1A30B0_003A4288.i8);
        func_13BF30(6, D_1A30B0_003A4288.i8);
    }
    if (D_1A30B0_003A4288.i1B20 & 0x20) {
        func_13BF30(5, D_1A30B0_003A4288.i14);
    }

    func_0038CB78(act, 0, 0xD0);
    func_0038CB78(vol, 0, 0xD0);
    func_0038CB78(dop, 0, 0xD0);

    ch = D_1A3170;
    for (i = 0; i < 52; i++, ch++) {
        if (ch->state != 7) {
            if (ch->handle == 0) {
                continue;
            }
            if (ch->handle == -1) {
                continue;
            }
        }
        obj = ch->obj;
        dead = 0;
        if (obj != 0) {
            if (obj->b20 == 0xFE || ch->obj->b20 == 0xFD) {
                dead = 1;
            }
        }
        if (dead) {
            ch->obj = 0;
        }
        if (!func_0038CAD0(ch->timer)) {
            continue;
        }
        st = ch->state;
        if (st == 4) {
            act[i] = 0x20;
            continue;
        }
        if (st != 6 && dead && ch->def->b18 != 0) {
            act[i] = 0x20;
            continue;
        }
        if (D_001D5B94 != 0 && D_001D5B94 != 2 && D_001D5B94 != 6 && ch->state != 7) {
            act[i] = 0x10;
            continue;
        }
        if (ch->flags & 0x100) {
            *(u128_3A4288 *)&ch->pos = *(u128_3A4288 *)&D_00222400_003A4288;
        }
        if (ch->obj != 0 && !(ch->flags & 8)) {
            if (ch->flags & 0x40) {
                func_0038D000(&tmp, &ch->offset, obj->mtx);
                vec_add_ba(&tmp, &tmp, &obj->pos);
                vec_sub_ba(&vel, &tmp, &ch->pos);
                *(u128_3A4288 *)&ch->pos = *(u128_3A4288 *)&tmp;
            } else {
                ch->pos.z -= 1.0f;
                vec_sub_ab(&vel, &ch->obj->pos, &ch->pos);
                *(u128_3A4288 *)&ch->pos = *(u128_3A4288 *)&ch->obj->pos;
                ch->pos.z += 1.0f;
            }
        } else {
            qzero(&vel);
        }
        /* Paired VU0 subtractions; the compiler schedules their quadword temporaries. */
        __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(vel));
        __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(acc));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(qa) : "j"(qa), "j"(qb));
        __asm__("lqc2 %0, %1" : "=j"(qc) : "m"(D_00222400_003A4288));
        __asm__("lqc2 %0, %1" : "=j"(qd) : "m"(ch->pos));
        __asm__("sqc2 %1, %0" : "=m"(vel) : "j"(qa));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(qc) : "j"(qc), "j"(qd));
        __asm__("sqc2 %1, %0" : "=m"(tmp) : "j"(qc));
        func_0038CF68(&tmp, &tmp, 1.0f);
        dop[i] = func_0038CE68(&tmp, &vel);
        fl = ch->flags;
        if (!(fl & 0x10)) {
            r = func_003A3DC8_003A4288(ch, &D_1A3170[i].pos, 0, 0);
            vol[i] = r * ch->vol / 1024;
            if (!(ch->def->b19 & 2)) {
                act[i] |= 8;
            }
        } else {
            r = 0x400;
            vol[i] = ch->vol;
            if (fl & 0x200) {
                act[i] |= 8;
            }
        }
        if (has_x != 0 && !(ch->def->b19 & 4) && cut < ch->pos.z) {
            vol[i] /= 2;
        }
        act[i] |= 1;
        if (r < 0x20 && vol[i] < 0x20 && (ch->flags & 4)) {
            act[i] = 0x20;
            continue;
        }
        if (*(u8 *)&ch->flags & 1) {
            continue;
        }
        {
            s32 t = act[i];
            act[i] = t | 2;
            if (ch->flags & 0x20) {
                continue;
            }
            if (ch->def->b19 & 0x10) {
                continue;
            }
            act[i] = t | 6;
        }
    }

    for (i = 0; i < 52; i++) {
        ch = &D_1A3170[i];
        k = act[i];
        if (k == 0) {
            continue;
        }
        h = ch->handle;
        ch->handle = -1;
        if (k & 0x20) {
            if (ch->state == 7) {
                ch->obj = 0;
                ch->i40 = 0;
                ch->state = 0;
                continue;
            }
            func_13C118(h);
            ch->state = 6;
            func_13C200(h, func_003A5550, &D_1A3170[i]);
            D_1A30B0_003A4288.ch[i].i4C = D_1A30B0_003A4288.ch[i].b13;
            continue;
        }
        if (k & 0x10) {
            func_13C200(h, func_003A5550, &D_1A3170[i]);
            D_1A30B0_003A4288.ch[i].i4C = D_1A30B0_003A4288.ch[i].b13;
            continue;
        }
        pan = 0;
        pitch = 0;
        i14 = ch->i14;
        flags = 1;
        if ((k & 2) && !(ch->flags & 0x100)) {
            pan = func_003A3E28_003A4288(ch, &ch->pos);
            flags = 7;
        }
        if (act[i] & 4) {
            f32 scale = 300.0f;
            f32 rate = dop[i];
            flags |= 8;
            if (ch->flags & 2) {
                scale = 500.0f;
            }
            rate *= scale;
            pitch = func_13D1E8((s32)rate);
        }
        if (i14 != 0) {
            flags |= 0x10;
        }
        if (ch->pitch != 0) {
            pitch += ch->pitch;
            flags |= 8;
        }
        if (has_x != 0 && !(ch->def->b19 & 8)) {
            flags |= 8;
            pitch -= 0x5F4;
        }
        if (ch->state != 7) {
            v = vol[i];
            if (v > 0x400) {
                v = 0x400;
            }
            func_13C2C0(h, flags, v, pan, pitch, i14, func_003A5550, &D_1A3170[i]);
            D_1A30B0_003A4288.ch[i].i4C = D_1A30B0_003A4288.ch[i].b13;
            continue;
        }
        if (ch->def == 0 || D_1A30B0_003A4288.snd[ch->def->i1C] == -1 || D_1A30B0_003A4288.snd[ch->def->i1C] == 0) {
            ch->obj = 0;
            ch->i40 = 0;
            ch->state = 0;
            continue;
        }
        ch->state = 1;
        v = vol[i];
        if (v > 0x400) {
            v = 0x400;
        }
        func_13C0B8(D_1A30B0_003A4288.snd[ch->def->i1C], ch->def->h1A, v, pan, pitch, i14, func_003A5508, &D_1A3170[i]);
    }
    func_003A1F30();
    func_13CA28();
    func_13B620();
    func_13CA20();
    D_1A30B0_003A4288.i1B20 = 0;
    D_1A30B0_003A4288.i44 = 0;
    return 0;
}
