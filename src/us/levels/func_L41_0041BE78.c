#include "common.h"

/* NTSC-U counterpart of func_L41_0041C778 (src/levels/shared/L41_0041C568.c): 30/60 frame counts for 25/50, level data +0x180, D_001A5F78 */
/* localdecomp:start func_L41_0041BE78 */
typedef struct { u8 bytes[8]; } __attribute__((packed)) B8_0041BE78;
typedef struct { f32 v[8]; } __attribute__((aligned(16))) B32_0041BE78;

typedef struct {
    s32 index;
    s32 other;
    u8 p8[8];
    f32 health;
    f32 max;
    s32 delay;
    s32 ownArg;
    s32 otherArg;
} P_0041BE78;

typedef struct {
    u8 p[0x10];
    void *collision;
} C_0041BE78;

typedef struct {
    u8 p[0x10];
    f32 pos[4];
    u8 state;
    u8 p21[3];
    C_0041BE78 *cl;
    u8 p28[4];
    f32 scale;
    u8 byte30;
    u8 p31;
    u16 distance;
    u16 flags;
    u8 p36[0x32];
    P_0041BE78 *vars;
    u8 p6C[0x2C];
    void *collision;
    u8 p9C[0xC];
    u8 hit;
    u8 pA9[0x57];
} M_0041BE78;

typedef struct {
    u8 p[0x2C];
    f32 damage;
} H_0041BE78;

typedef struct {
    u8 p[0x20];
    f32 scale;
    s32 p24;
    s32 duration;
    s32 timer;
} F_0041BE78;

/* the moby table pointer at 0x2487DC in level 41, read here both through $gp (this alias:
   gp + 0x69C in level 41) and with %hi/%lo (D_L41_002487DC) */
extern M_0041BE78 *D_L41_002487DC_0041BE78;
__asm__(".extern D_L41_002487DC_0041BE78, 4");
extern M_0041BE78 *D_L41_002487DC;
extern u8 D_L41_00242AB0[] __attribute__((section(".sdata")));
extern B8_0041BE78 D_L41_00247968[];
extern B8_0041BE78 D_L41_00247970[];
extern B32_0041BE78 D_L41_00247980;
extern F_0041BE78 D_L41_0024A280;
extern s32 D_001A5F78[];
extern s32 D_L41_0024145C;
__asm__(".extern D_L41_0024145C, 16");

extern void func_L41_004894B0(M_0041BE78 *, s32);
extern void func_L40_00487860(M_0041BE78 *, s32);
extern H_0041BE78 *func_L41_0041B8E8(M_0041BE78 *);
extern s32 func_L03_003F8F68(void *, void *, s32);
extern void func_L41_0041BC68(M_0041BE78 *);
extern void func_L41_0041B230(void *, s32, u32, f32);
extern void func_L41_0041BA28(M_0041BE78 *, s32);
extern void func_L41_0041B870(M_0041BE78 *, s32);
extern s32 func_L41_0041B9E8(f32 *, f32);
extern void func_L41_0048F968(M_0041BE78 *, void *, void *, void *, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_004367E8(M_0041BE78 *, s32, f32 *);
extern void func_L41_0041B100(f32 *, s32, f32, f32, f32);
extern void func_L01_004367A0(M_0041BE78 *, s32 *, s32 *);
extern void func_L40_004C35D0(s32, s32, M_0041BE78 *, s32);
extern void func_003BD360(M_0041BE78 *);

void func_L41_0041BE78(M_0041BE78 *m) {
    B8_0041BE78 b1;
    B8_0041BE78 b2;
    B32_0041BE78 b3;
    f32 pos[4] __attribute__((aligned(16)));
    s32 n1;
    s32 n2;
    P_0041BE78 *p = m->vars;
    M_0041BE78 *other;
    H_0041BE78 *hit;
    s32 dead;
    s32 sound;
    f32 old;
    f32 low;
    f32 mid;

    if (m->state == 0) {
        p->delay = 0;
        p->index = -1;
        m->state = 1;
        m->byte30 = 255;
        m->distance = 255;
        if (p->other >= 0) {
            M_0041BE78 *initOther;

            initOther = &D_L41_002487DC_0041BE78[p->other];
            initOther->distance = 255;
            initOther->flags |= 0x4041;
            func_L41_004894B0(initOther, p->otherArg);
        }
        m->collision = 0;
        m->flags |= 0x41;
        func_L40_00487860(m, p->ownArg);
        p->max = p->health;
    }
    if (m->state == 1) {
        if (p->index == -1) {
            dead = 0;
            if (p->other >= 0) {
                other = &D_L41_002487DC[p->other];
                hit = func_L41_0041B8E8(other);
                if (p->delay > 0) {
                    p->delay--;
                }
                if (hit && p->delay == 0) {
                    p->delay = 30;
                    if (!func_L03_003F8F68(D_L41_00242AB0, hit, 16)) {
                        if (hit->damage >= 8.0f) {
                            func_L41_0041BC68(m);
                        }
                        func_L41_0041B230(hit, 20, 0x80555E6A, 1.0f);
                    }
                    old = p->health;
                    mid = p->max * 0.6f;
                    low = p->max * 0.3f;
                    p->health = old - hit->damage;
                    if (old > mid && p->health <= mid) {
                        func_L41_0041BA28(m, 500);
                    }
                    if (old > low && p->health <= low) {
                        func_L41_0041BA28(m, 500);
                    }
                    if (p->health <= 0.0f) {
                        p->health = 0.0f;
                        dead = 1;
                    }
                }
                other->hit = 255;
            }
            if (dead) {
                func_L41_0041B870(m, 250);
                func_L41_0041BA28(m, 500);
                func_L41_0041BA28(m, 1000);
            }
        }
        if (p->index >= 0 && p->index < D_001A5F78[0] && p->other >= 0) {
            other = &D_L41_002487DC_0041BE78[p->other];
            if (func_L41_0041B9E8(m->pos, 64.0f)) {
                b1 = D_L41_00247968[0];
                b2 = D_L41_00247970[0];
                b3 = D_L41_00247980;
                func_L41_0048F968(other, &b3, &b2, &b1, 65535, -1, -1, 1, 65535, 255, 0);
                func_L01_004367E8(other, 0, pos);
                func_L41_0041B100(pos, 5, 1.0f, 6.0f, 12.0f);
                func_L41_0041B230(pos, 20, 0x80555E6A, 1.5f);
                func_L01_004367A0(m, &n1, &n2);
                if (n2 >= 2) {
                    func_L01_004367E8(other, 1, pos);
                    func_L41_0041B230(pos, 25, 0x80555E6A, 2.0f);
                }
                if (n2 >= 5) {
                    func_L01_004367E8(other, 4, pos);
                    func_L41_0041B100(pos, 5, 1.0f, 8.0f, 12.0f);
                    func_L41_0041B230(pos, 20, 0x80555E6A, 1.5f);
                }
                if (n2 >= 8) {
                    func_L01_004367E8(other, 7, pos);
                    func_L41_0041B100(pos, 5, 1.0f, 6.0f, 12.0f);
                    func_L41_0041B230(pos, 20, 0x80555E6A, 1.5f);
                }
                D_L41_0024A280.scale = 0.15f;
                D_L41_0024A280.duration = 60;
                D_L41_0024A280.timer = 0;
            }
            sound = -1;
            switch (D_L41_0024145C) {
            case 41:
            case 51:
                sound = 19;
                break;
            case 42:
            case 52:
                sound = 18;
                break;
            case 45:
            case 55:
                sound = 17;
                break;
            }
            if (sound != -1) {
                func_L40_004C35D0(sound, 0, m, 0);
            }
            m->state = 2;
            func_L41_004894B0(m, p->ownArg);
            if (p->other >= 0) {
                func_L40_00487860(&D_L41_002487DC_0041BE78[p->other], p->otherArg);
            }
            m->collision = m->cl->collision;
            func_003BD360(other);
        }
    }
}
/* localdecomp:end func_L41_0041BE78 */
