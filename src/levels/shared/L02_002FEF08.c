#include "common.h"

/* localdecomp:start func_L02_002FEF08 */
#include "vu0.h"
typedef struct { s32 id, unused, flags, state, repeat, event, area, count, timer, message; } P_002FEF08;
typedef struct {
 u8 pad0[0x10]; vu0_v4 pos; u8 state, pad21[15]; u8 distance, pad31[0x37];
 P_002FEF08 *p; u8 pad6c[0x44]; u8 area, padb1; s16 index; u8 padb4[8];
 u8 initialized, padbd[0x33]; vu0_v4 rot;
} M_002FEF08;
typedef struct { u8 pad0[0x38]; s32 a,b; } E_002FEF08;
typedef struct {
 s32 active; u8 pad4[12]; vu0_v4 pos,rot; s32 a,b,c;
 u8 d,e,f,g,h,i; u8 pad42[2]; f32 j,k,l,m; s32 mode; E_002FEF08 *ptr; s32 n;
 u8 pad60[0x404]; u8 bits[0x800]; s32 o,p;
} Save_002FEF08;
typedef struct { u8 pad0[0x25c0]; E_002FEF08 *ptr; u8 pad25c4[0x20]; u8 mode; u8 pad25e5[0x295]; s16 n; } Hero_002FEF08;
typedef struct { u8 pad0[0x40]; u8 a,b,c; u8 pad43[0x71]; s32 n; } Anim_002FEF08;
extern s32 D_L02_001DE4C0;
extern s32 D_001D545C_sda;
extern s32 D_001D545C;
extern u8 D_001BBC40[];
extern u8 D_001BBE90[];
extern u8 D_001A71C4[];
extern u32 D_001A71AC[];
extern s32 D_001A71A4[];
extern u8 D_001A4C60[];
extern Save_002FEF08 D_L02_00234840;
extern u8 D_L02_002348A0[];
extern u8 D_L02_00233C30[];
extern Save_002FEF08 D_L02_00233BD0;
extern Hero_002FEF08 D_001A4BE0;
extern Anim_002FEF08 D_001A30B0;
extern s16 D_001CCFD0[];
extern s32 D_L02_001F1580[];
extern u8 D_L02_001DE364,D_L02_001DE365,D_L02_001DE366;
extern f32 D_L02_001DE368,D_L02_001DE36C,D_L02_001DE370,D_L02_001DE374;
extern s32 D_001D4CF0;
extern M_002FEF08 *D_L02_001DC310;
__asm__(".extern D_L02_001DE4C0, 16");
__asm__(".extern D_001D545C, 16");
__asm__(".extern D_L02_001DE364, 16");
__asm__(".extern D_L02_001DE365, 16");
__asm__(".extern D_L02_001DE366, 16");
__asm__(".extern D_L02_001DE368, 16");
__asm__(".extern D_L02_001DE36C, 16");
__asm__(".extern D_L02_001DE370, 16");
__asm__(".extern D_L02_001DE374, 16");
__asm__(".extern D_001D4CF0, 16");
__asm__(".extern D_L02_001DC310, 4");
extern void func_L01_003EE650(s32);
extern s32 func_0038CAD0(s32 *);
extern s32 func_00382380(void *,s32,s32);
extern s32 func_L01_004BA800(void);
extern void func_L01_0043B510(s32);
extern f32 func_003C3D30(void *,s32,s32,f32);
extern void func_L01_004A3610(void *,void *);
extern void func_0038CC88(void *,void *,s32);
extern void func_0039EC28(s32,s32);
extern void func_L01_00451F60(s32,s32,s32);
void func_L02_002FEF08(M_002FEF08 *m) {
    P_002FEF08 *p = m->p;
    vu0_v4 pos;
    s32 i;
    s32 b;
    s32 level;
    s32 off;
    u8 *src;
    u8 *q;
    s32 entry;

    if (m->distance < 32) {
        m->distance = 32;
    }
    if (!D_L02_001DE4C0 && p->event != -1) {
        func_L01_003EE650(p->event);
    }
    if (p->flags & 8) {
        return;
    }
    if (!m->initialized) {
        m->initialized = 1;
        p->count = 0;
        p->timer = 0;
        return;
    }
    if (p->area != -1 && !(D_001BBC40[p->area + (D_001D545C_sda << 4)] & 0x80)) {
        return;
    }
    if ((p->flags & 2) && D_001A71C4[0] != 1) {
        return;
    }
    if ((p->flags & 4) && D_001A71C4[0] != 3 && D_001A71C4[0] != 0) {
        return;
    }
    if ((p->flags & 16) && D_001A71AC[0] >= 2 && D_001A71AC[0] != 9) {
        return;
    }
    if ((p->flags & 32) && D_001A71A4[0] == 49) {
        return;
    }
    if (p->state == 2 && func_0038CAD0(&p->timer)) {
        p->state = 0;
    }
    if (!func_00382380(D_001A4C60, p->id, 0) && !D_L02_00234840.bits[m->index]) {
        b = D_001BBE90[(m->index >> 1) + (D_001D545C_sda << 10)];
        if (m->index & 1) {
            if ((b >> 4) & 7) {
                goto check;
            }
            goto inactive;
        } else if (!(b & 7)) {
            goto inactive;
        }
    }
check:
    if (!func_L01_004BA800()) {
        if (!p->state || (p->repeat && !p->timer)) {
            p->state = 1;
            func_L01_0043B510(m->area);
            *(vu0_q *)&pos = *(vu0_q *)&m->pos;
            pos.z = func_003C3D30(&pos, 0, 0, 0.5f);
            if (fabs_asm(m->pos.z - pos.z) > 2.0f) {
                pos.z = m->pos.z;
            }
            if (D_001D545C != 24) {
                func_L01_004A3610(&pos, &m->rot);
            } else {
                if (D_001A4BE0.mode == 4) {
                    return;
                }
                func_0038CC88(D_L02_002348A0, D_L02_00233C30, 0x404);
                level = D_001D545C;
                off = (level << 4) - 2;
                src = &D_L02_00233C30[0x404];
                for (i = 0; i < 0x7ff; i++, src++) {
                    entry = *src;
                    if ((u8)entry != 0 && ((u8)entry == 1 || (D_001BBC40[(u8)entry + off] & 0x80))) {
                        (D_L02_002348A0 + 0x404)[i] = entry;
                        if (i & 1) {
                            u8 *n = &D_001BBE90[(i >> 1) + (level << 10)];
                            u8 v = *n;

                            if (((v >> 4) & 7) != 7) {
                                *n = v + 16;
                            }
                        } else {
                            u8 *n = &D_001BBE90[(i >> 1) + (level << 10)];
                            u8 v = *n;

                            if ((v & 7) != 7) {
                                *n = v + 1;
                            }
                        }
                    }
                }
                D_L02_00234840.active = 1;
                *(vu0_q *)&D_L02_00234840.pos = *(vu0_q *)&pos;
                *(vu0_q *)&D_L02_00234840.rot = *(vu0_q *)&m->rot;
                D_L02_00234840.a = D_001A4BE0.ptr->a;
                D_L02_00234840.b = D_001A4BE0.ptr->b;
                D_L02_00234840.mode = D_001A4BE0.mode;
                D_L02_00234840.ptr = D_001A4BE0.ptr;
                D_L02_00234840.n = D_001A4BE0.n;
                D_L02_00234840.c = D_001A30B0.n;
                D_L02_00234840.d = D_001A30B0.a;
                D_L02_00234840.e = D_001A30B0.b;
                D_L02_00234840.f = D_001A30B0.c;
                D_L02_00234840.o = D_001CCFD0[0x24];
                D_L02_00234840.p = D_L02_001F1580[0];
                D_L02_00234840.g = D_L02_001DE364;
                D_L02_00234840.h = D_L02_001DE365;
                D_L02_00234840.i = D_L02_001DE366;
                D_L02_00234840.j = D_L02_001DE368;
                D_L02_00234840.k = D_L02_001DE36C;
                D_L02_00234840.l = D_L02_001DE370;
                D_L02_00234840.m = D_L02_001DE374;
                func_0039EC28(0, D_001D4CF0);
            }
            D_L02_00233BD0.bits[m->index] = 0;
            D_L02_00234840.bits[m->index] = 0;
            q = &D_001BBE90[(m->index >> 1) + (D_001D545C << 10)];
            {
                s32 c = *q;
                s32 v = c & 0xf8;

                if (m->index & 1) {
                    v = c & 0x8f;
                }
                *q = v;
            }
            if (p->message && D_L02_001DC310 != m) {
                func_L01_00451F60(0x25a, 90, 0);
                D_L02_001DC310 = m;
            }
            p->timer = 750;
        }
    } else {
inactive:
        if (p->state) {
            p->state = 2;
        }
    }
    if (!m->state && (D_001BBC40[m->area + (D_001D545C << 4)] & 0x80)) {
        m->state = 1;
    }
}
/* localdecomp:end func_L02_002FEF08 */
