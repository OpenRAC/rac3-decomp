#include "common.h"

/* localdecomp:start func_L06_00347370 */
#include "vu0.h"

typedef struct {
    vu0_v4 p0;
    vu0_v4 p1;
    s32 st;
    s32 t;
    u8 pad28[8];
} Seg_00347370;

typedef struct {
    s32 st;
    s32 t;
    u8 *moby;
    s32 time;
} Slot_00347370;

typedef struct {
    s32 w0;
    u8 *moby;
    u8 *target;
    u8 pad0C[0x1C - 0x0C];
    s32 w1C;
    u8 pad20[4];
    s32 w24;
    s32 w28;
    u8 pad2C[4];
    u8 *p30;
    s32 w34;
    u8 pad38[0x50 - 0x38];
    Seg_00347370 seg[4];
    Slot_00347370 slot[4];
} S_00347370;

typedef struct {
    u8 pad[0x18];
    u8 *moby;
    u8 pad1C[4];
    vu0_v4 pos;
} Hit_00347370;

typedef struct {
    vu0_v4 dir;
    s32 owner;
    s32 mode;
    u8 first;
    u8 second;
    u16 cls;
    f32 dist;
    s32 enabled;
} Q_00347370;

__asm__(".extern D_L06_001E07C8, 0");
__asm__(".extern D_L06_001DD258, 4");
__asm__(".extern D_L06_001DD210, 0");
extern u8 *D_L06_001E07C8[] __attribute__((section(".sdata")));
extern s32 D_L06_001DD258;
extern s32 D_L06_001DD210[][4] __attribute__((section(".sdata")));
extern Hit_00347370 D_L06_001E8440;
extern u8 *D_L06_001DED9C;
extern u8 *D_L06_001DEE80;
extern s32 D_L06_001DE940;
extern s32 D_001D545C;
typedef struct {
    u8 pad0[0x1DC];
    s16 h1DC;
    u8 pad1DE[0x25C0 - 0x1DE];
    u8 *moby;
} Hero_00347370;
extern Hero_00347370 D_001A4BE0;
extern u8 *D_001A71A0 __attribute__((section(".data")));
extern u8 D_001BBC40[][16];
extern u8 D_001BBB18[][8];

extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern f32 func_L01_00443A18(f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_00446760(void *, void *, s32, f32, void *);
extern s32 func_L04_0035A660(u8 **, s32 *, u8 *);
extern void func_L04_0035A6A0(u8 **, s32 *);
extern s32 func_L01_00366FC8(void);
extern void func_L01_003F3740(s32);
extern void func_L01_003F3768(s32);
extern void func_L04_0035A528(s32 *, s32 *);
extern s32 func_L01_00367080(void *, void *, void *, void *);
extern void func_L01_00367260(void *, s32, s32, void *, void *, s32);
extern void func_L04_0037A5B8(void *, s32, s32);
extern void func_L01_00456230(void *, s32);
extern void func_L04_00379CC0(u8 *, void *);
extern s32 func_L04_0035A5B8(void *, void *, void *);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L04_003796C8(u8 *);
extern f32 func_L01_004C93D8(void);
extern s32 func_003C4B50(void *);
extern u8 *func_00382348(void *);
extern s32 func_L01_004AAC98(s32, s32, void *, s32);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern f32 func_0038CE68(void *, void *);
extern s32 func_L04_0035B838(void *, u8 *, s32);
extern void func_L01_00367430(s32, f32);

static __inline__ void vcopy_00347370(void *d, void *s) {
    *(vu0_q *)d = *(vu0_q *)s;
}

void func_L06_00347370(u8 *mob, S_00347370 *s, s32 idx, s32 flag) {
    vu0_v4 save;
    vu0_v4 dir;
    vu0_v4 up;
    vu0_v4 side;
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 hp;
    vu0_v4 hn;
    vu0_v4 tp;
    Q_00347370 q;
    Seg_00347370 *seg = &s->seg[idx];
    Slot_00347370 *slot = &s->slot[idx];
    s32 mask = 0x110001;
    s32 i;
    s32 hit;
    s32 r;
    s32 stop;
    u8 *m;

    *(vu0_q *)&save = *(vu0_q *)&seg->p1;
    vec_sub_ba(&dir, &seg->p1, &seg->p0);
    func_0038CF68(&dir, &dir, 1.0f);
    if (idx == 2 || idx == 3) {
        mask = (mask & ~0x100000) | 0x200000;
    }
    qzero(&up);
    up.z = 1.0f;
    func_0038CE90(&side, &dir, &up);
    func_0038CE20(&side, &side, func_L01_00443A18(0.5f, 1.0f));
    if (D_001D545C == 16) {
        func_L01_00446760(&q, mob, mask, 50.0f, &side);
    } else {
        func_L01_00446760(&q, mob, mask, 1.0f, &side);
    }
    q.first = 9;
    q.cls = *(u16 *)(mob + 0xAA);
    m = s->moby;
    if (m != 0) {
        if (idx == 2 || idx == 3) {
            func_L04_0035A660(D_L06_001E07C8, &D_L06_001DD258, m);
        } else {
            *(u16 *)(m + 0x34) &= 0xBFFF;
        }
    }
    if (func_L01_00366FC8()) {
        func_L04_0035A660(D_L06_001E07C8, &D_L06_001DD258, D_001A71A0);
    }
    hit = 0;
    func_L01_003F3740(0);
    r = 0;
    slot->st = 0;
    func_L04_0035A528((s32 *)seg, (s32 *)slot);
    if (flag == 0) {
        switch (idx) {
        case 1:
        case 3:
            r = func_L01_00367080(seg, &seg->p1, &hp, &hn);
            if (r == 0) {
                break;
            }
            if (r == 2) {
                s->w0 = 1;
                func_L01_00367260(mob, idx, D_L06_001DD210[idx][r], seg, &hp, -1);
            } else {
                hit = 1;
            }
            break;
        case 0:
        case 2:
            r = func_L01_00367080(seg, &seg->p1, &hp, &hn);
            if (r == 0) {
                break;
            }
            if (r == 2) {
                s->w0 = 1;
                func_L01_00367260(mob, idx, D_L06_001DD210[idx][r], seg, &hp, -1);
                if (idx == 0) {
                    idx = 1;
                } else {
                    idx = 3;
                }
                vcopy_00347370(&s->seg[idx].p0, &seg->p0);
                *(vu0_q *)&seg->p0 = *(vu0_q *)&hn;
                *(vu0_q *)&seg->p1 = *(vu0_q *)&hn;
                vcopy_00347370(&s->seg[idx].p1, &save);
                func_L06_00347370(mob, s, idx, 1);
                func_L04_0035A6A0(D_L06_001E07C8, &D_L06_001DD258);
                if (s->moby != 0 && idx != 2 && idx != 3) {
                    *(u16 *)(s->moby + 0x34) |= 0x4000;
                }
                func_L01_003F3768(0);
                return;
            }
            hit = 1;
            func_0038CE20(&seg->p1, &dir, 0.01f);
            vec_add_ab(&seg->p1, &seg->p1, &hp);
            if (idx == 0) {
                slot->st = 5;
            } else {
                slot->st = 6;
            }
            if (r & 2) {
                flag = 1;
            }
            break;
        }
    }
    *(vu0_q *)&a = *(vu0_q *)&seg->p0;
    *(vu0_q *)&b = *(vu0_q *)&seg->p1;
    stop = 0;
    for (i = 0; i < 5 && func_003D3CB0(&a, &b, 0, 0, &q); i++) {
        Hit_00347370 *p = &D_L06_001E8440;
        u8 *o = p->moby;

        if (o == 0 || *(s16 *)(o + 0xAA) == 0x1B92) {
            *(vu0_q *)&seg->p1 = *(vu0_q *)&p->pos;
            slot->st = 1;
            if (s->moby == 0) {
                break;
            }
            if (idx == 2 || idx == 3) {
                if (s->w1C != 0) {
                    if (mob[0xB0] != 0xFF && (D_001BBC40[D_001D545C][mob[0xB0]] & 0x80)) {
                        break;
                    }
                    if (s->w34 != -1 && D_001BBB18[D_001D545C][s->w34]) {
                        break;
                    }
                }
                func_L04_003796C8(s->moby);
            }
            break;
        }
        if (*(s16 *)(o + 0xAA) == 0x192F || *(s16 *)(o + 0xAA) == 0x1930 || *(s16 *)(o + 0xAA) == 0x1A77) {
            *(vu0_q *)&a = *(vu0_q *)&p->pos;
            if (!func_L04_0035A660(D_L06_001E07C8, &D_L06_001DD258, o)) {
                break;
            }
            continue;
        }
        if (*(s16 *)(o + 0xAA) == 0x1BA8) {
            u8 *tgt = 0;
            s32 w;

            func_L01_00456230(o, 1);
            w = **(s32 **)(p->moby + 0x68);
            if (w != -1) {
                p->moby = D_L06_001DED9C + (w << 8);
            }
            if ((s->w24 != -1 && p->moby == D_L06_001DED9C + (s->w24 << 8)) ||
                (s->w28 != -1 && p->moby == D_L06_001DED9C + (s->w28 << 8))) {
                tgt = D_L06_001E8440.moby;
            }
            if (tgt == 0) {
                *(vu0_q *)&a = *(vu0_q *)&D_L06_001E8440.pos;
                if (!func_L04_0035A660(D_L06_001E07C8, &D_L06_001DD258, D_L06_001E8440.moby)) {
                    break;
                }
                continue;
            }
            func_L04_00379CC0(tgt, &tp);
            if (func_L04_0035A5B8(seg, &tp, &tp)) {
                *(vu0_q *)&seg->p1 = *(vu0_q *)&tp;
                s->target = tgt;
                func_L04_0037A5B8(tgt, (s32)mob, 1);
                slot->st = 3;
                break;
            }
            if (!func_L04_0035A660(D_L06_001E07C8, &D_L06_001DD258, tgt)) {
                break;
            }
            continue;
        }
        if (*(s16 *)(o + 0xAA) == 0x1860 || *(s16 *)(o + 0xAA) == 0x1751) {
            u8 *tgt = 0;

            if (*(s16 *)(o + 0xAA) == 0x1860) {
                u8 *t = *(u8 **)(mob + 0xB8);
                s32 k;

                if (t != 0 && (k = *(s32 *)(*(u8 **)(t + 0x68) + 0x13C)) != -1 &&
                    1.3f * 1.3f < func_L01_0040E548(t + 0x10, D_L06_001DEE80 + (k << 7) + 0x30)) {
                    *(vu0_q *)&a = *(vu0_q *)&p->pos;
                    if (!func_L04_0035A660(D_L06_001E07C8, &D_L06_001DD258, p->moby)) {
                        break;
                    }
                    continue;
                }
                if (s->p30 != 0) {
                    tgt = s->p30;
                } else if ((s->w24 != -1 && D_L06_001E8440.moby == D_L06_001DED9C + (s->w24 << 8)) ||
                           (s->w28 != -1 && D_L06_001E8440.moby == D_L06_001DED9C + (s->w28 << 8))) {
                    tgt = D_L06_001E8440.moby;
                }
            } else {
                u8 *v = *(u8 **)(o + 0x68);
                s32 k = *(s32 *)(v + 0x13C);

                if (k != -1 && 1.3f * 1.3f < func_L01_0040E548(o + 0x10, D_L06_001DEE80 + (k << 7) + 0x30)) {
                    *(vu0_q *)&a = *(vu0_q *)&p->pos;
                    if (!func_L04_0035A660(D_L06_001E07C8, &D_L06_001DD258, p->moby)) {
                        break;
                    }
                    continue;
                }
                tgt = 0;
                if ((s->w24 != -1 && *(u8 **)(v + 0x12C) == D_L06_001DED9C + (s->w24 << 8)) ||
                    (s->w28 != -1 && *(u8 **)(v + 0x12C) == D_L06_001DED9C + (s->w28 << 8))) {
                    tgt = *(u8 **)(v + 0x12C);
                }
            }
            if (tgt == 0) {
                *(vu0_q *)&a = *(vu0_q *)&D_L06_001E8440.pos;
                if (!func_L04_0035A660(D_L06_001E07C8, &D_L06_001DD258, D_L06_001E8440.moby)) {
                    break;
                }
                continue;
            }
            func_L04_00379CC0(tgt, &tp);
            if (func_L04_0035A5B8(seg, &tp, &tp)) {
                *(vu0_q *)&seg->p1 = *(vu0_q *)&tp;
                s->target = tgt;
                func_L04_0037A5B8(tgt, (s32)mob, 1);
                slot->st = 3;
                break;
            }
            if (!func_L04_0035A660(D_L06_001E07C8, &D_L06_001DD258, tgt)) {
                break;
            }
            continue;
        }
        if (*(s16 *)(o + 0xAA) == 0x185F) {
            if (o != s->moby) {
                if (!func_L04_0035A660(D_L06_001E07C8, &D_L06_001DD258, o)) {
                    break;
                }
                if (idx == 0 || idx == 2) {
                    stop = 1;
                    *(vu0_q *)&seg->p1 = *(vu0_q *)&p->pos;
                    break;
                }
            }
            if (s->moby != 0 && (idx == 0 || idx == 1)) {
                slot->st = 4;
                *(vu0_q *)&seg->p1 = *(vu0_q *)(s->moby + 0x10);
                break;
            }
            *(vu0_q *)&a = *(vu0_q *)&D_L06_001E8440.pos;
            if (!func_L04_0035A660(D_L06_001E07C8, &D_L06_001DD258, D_L06_001E8440.moby)) {
                break;
            }
            continue;
        }
        if (!(*(u16 *)(o + 0x34) & 0x4000)) {
            *(vu0_q *)&seg->p1 = *(vu0_q *)&p->pos;
            slot->st = 1;
            if (s->moby == 0) {
                break;
            }
            if (idx == 2 || idx == 3) {
                if (s->w1C != 0) {
                    if (mob[0xB0] != 0xFF && (D_001BBC40[D_001D545C][mob[0xB0]] & 0x80)) {
                        break;
                    }
                    if (s->w34 != -1 && D_001BBB18[D_001D545C][s->w34]) {
                        break;
                    }
                }
                func_L04_003796C8(s->moby);
            }
            break;
        }
        if (o == D_001A4BE0.moby) {
            if (func_L01_00366FC8() == 0) {
                if (p->moby == D_001A4BE0.moby && func_L01_004C93D8() != 0.0f) {
                    if (idx == 0 || idx == 2) {
                        stop = 1;
                        *(vu0_q *)&seg->p1 = *(vu0_q *)&p->pos;
                        break;
                    }
                    *(vu0_q *)&a = *(vu0_q *)&p->pos;
                    if (!func_L04_0035A660(D_L06_001E07C8, &D_L06_001DD258, p->moby)) {
                        break;
                    }
                    continue;
                }
            } else {
                *(vu0_q *)&a = *(vu0_q *)&p->pos;
                if (!func_L04_0035A660(D_L06_001E07C8, &D_L06_001DD258, p->moby)) {
                    break;
                }
                continue;
            }
        }
        if (idx == 0 || idx == 2) {
            stop = 1;
            *(vu0_q *)&seg->p1 = *(vu0_q *)&D_L06_001E8440.pos;
            break;
        }
        *(vu0_q *)&a = *(vu0_q *)&D_L06_001E8440.pos;
        if (!func_L04_0035A660(D_L06_001E07C8, &D_L06_001DD258, D_L06_001E8440.moby)) {
            break;
        }
        if (D_L06_001E8440.moby == D_001A4BE0.moby) {
            if (D_001A4BE0.h1DC >= 2) {
                continue;
            }
        } else if (func_003C4B50(D_L06_001E8440.moby) ||
                   (*(u8 **)(D_L06_001E8440.moby + 0x24) != 0 && (*(u8 **)(D_L06_001E8440.moby + 0x24))[0x46] == 0x16)) {
            if (D_L06_001E8440.moby == slot->moby && D_L06_001DE940 - slot->time < 50) {
                continue;
            }
        } else {
            u8 *y = func_00382348(D_L06_001E8440.moby);

            if (y == 0) {
                if (D_L06_001E8440.moby == slot->moby && D_L06_001DE940 - slot->time < 50) {
                    continue;
                }
            } else if (*(u8 **)(y + 0x18) == mob && *(s16 *)(y + 0x1C) < 49) {
                continue;
            }
        }
        slot->moby = D_L06_001E8440.moby;
        slot->time = D_L06_001DE940;
        func_L01_004AAC98(2, 0, D_L06_001E8440.moby, 0x1937);
        continue;
    }
    if (hit) {
        switch (idx) {
        case 1:
        case 3:
            if (func_0038CE68(&dir, &seg->p1) < func_0038CE68(&dir, &hp) + 0.01f) {
                hit = 0;
            }
            break;
        case 0:
        case 2:
            if (slot->st != 5 && slot->st != 6) {
                hit = 0;
            }
            break;
        }
        if (hit && idx == 0 && func_L04_0035B838(mob, (u8 *)s, 1)) {
            if (D_001D545C == 16) {
                func_L01_00367430((s32)mob, 50.0f);
            } else {
                func_L01_00367430((s32)mob, 2.0f);
            }
        }
    }
    if (slot->st == 5 || slot->st == 6 || stop) {
        if ((r & 2) || stop) {
            s32 again = 1;

            if (idx == 0) {
                idx = 1;
            } else {
                idx = 3;
            }
            func_0038CE20(&s->seg[idx].p0, &dir, -0.01f);
            if (stop != 0 || func_003D3CB0(&seg->p1, &hn, 0, D_001A71A0, 0) != 0) {
                u8 *h = D_L06_001E8440.moby;

                if (h == 0 || (!(*(u16 *)(h + 0x34) & 0x4000) && *(s16 *)(h + 0xAA) != 0x1BA8 &&
                               *(s16 *)(h + 0xAA) != 0x1860 && *(s16 *)(h + 0xAA) != 0x185F)) {
                    again = 0;
                } else {
                    vec_add_ba(&s->seg[idx].p0, &s->seg[idx].p0, &seg->p1);
                }
            } else {
                vec_add_ba(&s->seg[idx].p0, &s->seg[idx].p0, &hn);
            }
            if (again) {
                *(vu0_q *)&s->seg[idx].p1 = *(vu0_q *)&save;
                func_L06_00347370(mob, s, idx, flag);
            } else {
                vcopy_00347370(&s->seg[idx].p1, &s->seg[idx].p0);
            }
        }
    }
    func_L04_0035A6A0(D_L06_001E07C8, &D_L06_001DD258);
    if (s->moby != 0 && idx != 2 && idx != 3) {
        *(u16 *)(s->moby + 0x34) |= 0x4000;
    }
    func_L01_003F3768(0);
}
/* localdecomp:end func_L06_00347370 */
