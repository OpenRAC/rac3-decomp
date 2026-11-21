#include "common.h"

/* NTSC-U counterpart of func_L02_002FEF08 (src/levels/shared/L02_002FEF08.c): timer 900 (30 s at 30 fps) for 750 */
/* localdecomp:start func_L02_002FED60 */
#include "vu0.h"
typedef struct { s32 id, unused, flags, state, repeat, event, area, count, timer, message; } P_002FED60;
typedef struct {
 u8 pad0[0x10]; vu0_v4 pos; u8 state, pad21[15]; u8 distance, pad31[0x37];
 P_002FED60 *p; u8 pad6c[0x44]; u8 area, padb1; s16 index; u8 padb4[8];
 u8 initialized, padbd[0x33]; vu0_v4 rot;
} M_002FED60;
typedef struct { u8 pad0[0x38]; s32 a,b; } E_002FED60;
typedef struct {
 s32 active; u8 pad4[12]; vu0_v4 pos,rot; s32 a,b,c;
 u8 d,e,f,g,h,i; u8 pad42[2]; f32 j,k,l,m; s32 mode; E_002FED60 *ptr; s32 n;
 u8 pad60[0x404]; u8 bits[0x800]; s32 o,p;
} Save_002FED60;
typedef struct { u8 pad0[0x25c0]; E_002FED60 *ptr; u8 pad25c4[0x20]; u8 mode; u8 pad25e5[0x295]; s16 n; } Hero_002FED60;
typedef struct { u8 pad0[0x40]; u8 a,b,c; u8 pad43[0x71]; s32 n; } Anim_002FED60;
extern s32 D_L02_001DE540;
extern s32 D_001D545C_sda;
extern s32 D_001D545C;
extern u8 D_001BBC40[];
extern u8 D_001BBE90[];
extern u8 D_001A71C4[];
extern u32 D_001A71AC[];
extern s32 D_001A71A4[];
extern u8 D_001A4C60[];
extern Save_002FED60 D_L02_002348C0;
extern u8 D_L02_00234920[];
extern u8 D_L02_00233CB0[];
extern Save_002FED60 D_L02_00233C50;
extern Hero_002FED60 D_001A4BE0;
extern Anim_002FED60 D_001A30B0;
extern s16 D_001CCFD0[];
extern s32 D_L02_001F1600[];
extern u8 D_L02_001DE3E4,D_L02_001DE3E5,D_L02_001DE3E6;
extern f32 D_L02_001DE3E8,D_L02_001DE3EC,D_L02_001DE3F0,D_L02_001DE3F4;
extern s32 D_001D4CF0;
extern M_002FED60 *D_L02_001DC350;
__asm__(".extern D_L02_001DE540, 16");
__asm__(".extern D_001D545C, 16");
__asm__(".extern D_L02_001DE3E4, 16");
__asm__(".extern D_L02_001DE3E5, 16");
__asm__(".extern D_L02_001DE3E6, 16");
__asm__(".extern D_L02_001DE3E8, 16");
__asm__(".extern D_L02_001DE3EC, 16");
__asm__(".extern D_L02_001DE3F0, 16");
__asm__(".extern D_L02_001DE3F4, 16");
__asm__(".extern D_001D4CF0, 16");
__asm__(".extern D_L02_001DC350, 4");
extern void func_L01_003EC710(s32);
extern s32 func_00388398(s32 *);
extern s32 func_0037E0F0(void *,s32,s32);
extern s32 func_L01_004B6C68(void);
extern void func_L01_00438430(s32);
extern f32 func_003BE7F0(void *,s32,s32,f32);
extern void func_L01_0049FDB0(void *,void *);
extern void func_00388550(void *,void *,s32);
extern void func_00399C90(s32,s32);
extern void func_L01_0044ECE0(s32,s32,s32);
void func_L02_002FED60(M_002FED60 *m) {
    P_002FED60 *p = m->p;
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
    if (!D_L02_001DE540 && p->event != -1) {
        func_L01_003EC710(p->event);
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
    if (p->state == 2 && func_00388398(&p->timer)) {
        p->state = 0;
    }
    if (!func_0037E0F0(D_001A4C60, p->id, 0) && !D_L02_002348C0.bits[m->index]) {
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
    if (!func_L01_004B6C68()) {
        if (!p->state || (p->repeat && !p->timer)) {
            p->state = 1;
            func_L01_00438430(m->area);
            *(vu0_q *)&pos = *(vu0_q *)&m->pos;
            pos.z = func_003BE7F0(&pos, 0, 0, 0.5f);
            if (fabs_asm(m->pos.z - pos.z) > 2.0f) {
                pos.z = m->pos.z;
            }
            if (D_001D545C != 24) {
                func_L01_0049FDB0(&pos, &m->rot);
            } else {
                if (D_001A4BE0.mode == 4) {
                    return;
                }
                func_00388550(D_L02_00234920, D_L02_00233CB0, 0x404);
                level = D_001D545C;
                off = (level << 4) - 2;
                src = &D_L02_00233CB0[0x404];
                for (i = 0; i < 0x7ff; i++, src++) {
                    entry = *src;
                    if ((u8)entry != 0 && ((u8)entry == 1 || (D_001BBC40[(u8)entry + off] & 0x80))) {
                        (D_L02_00234920 + 0x404)[i] = entry;
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
                D_L02_002348C0.active = 1;
                *(vu0_q *)&D_L02_002348C0.pos = *(vu0_q *)&pos;
                *(vu0_q *)&D_L02_002348C0.rot = *(vu0_q *)&m->rot;
                D_L02_002348C0.a = D_001A4BE0.ptr->a;
                D_L02_002348C0.b = D_001A4BE0.ptr->b;
                D_L02_002348C0.mode = D_001A4BE0.mode;
                D_L02_002348C0.ptr = D_001A4BE0.ptr;
                D_L02_002348C0.n = D_001A4BE0.n;
                D_L02_002348C0.c = D_001A30B0.n;
                D_L02_002348C0.d = D_001A30B0.a;
                D_L02_002348C0.e = D_001A30B0.b;
                D_L02_002348C0.f = D_001A30B0.c;
                D_L02_002348C0.o = D_001CCFD0[0x24];
                D_L02_002348C0.p = D_L02_001F1600[0];
                D_L02_002348C0.g = D_L02_001DE3E4;
                D_L02_002348C0.h = D_L02_001DE3E5;
                D_L02_002348C0.i = D_L02_001DE3E6;
                D_L02_002348C0.j = D_L02_001DE3E8;
                D_L02_002348C0.k = D_L02_001DE3EC;
                D_L02_002348C0.l = D_L02_001DE3F0;
                D_L02_002348C0.m = D_L02_001DE3F4;
                func_00399C90(0, D_001D4CF0);
            }
            D_L02_00233C50.bits[m->index] = 0;
            D_L02_002348C0.bits[m->index] = 0;
            q = &D_001BBE90[(m->index >> 1) + (D_001D545C << 10)];
            {
                s32 c = *q;
                s32 v = c & 0xf8;

                if (m->index & 1) {
                    v = c & 0x8f;
                }
                *q = v;
            }
            if (p->message && D_L02_001DC350 != m) {
                func_L01_0044ECE0(0x25a, 90, 0);
                D_L02_001DC350 = m;
            }
            p->timer = 900;
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
/* localdecomp:end func_L02_002FED60 */
