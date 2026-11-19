/* functional: high. Compiles; written from the PAL asm using the NTSC-U draft as a guide (PAL differs: owner/other respawn callees 00667700/006673E8, hold time 0x97, world base D_001A5CD0, list D_0024CE20). Retail quirk kept: when only 'other' exists the health-zero block writes owner+0x320. VU0 vsub.xyz replaced by float subtraction (w kept). */
#include "common.h"
#include "vu0.h"

typedef struct W_0066AFA0 {
    u8 pad0[0x128];
    s32 context;
    u8 pad12C[0x3C];
    u8 running;
    u8 pad169[3];
    s32 event;
} W_0066AFA0;

typedef union Dec_0066AFA0 {
    u8 b[8];
    u32 w[2];
} Dec_0066AFA0;

typedef struct P_0066AFA0 {
    u8 pad0[0x1F0];
    vu0_v4 previousPos;
    vu0_v4 previousRot;
    u8 pad210[0x80];
    vu0_v4 spawnPos;
    vu0_v4 spawnRot;
    u8 pad2B0[0x20];
    u8 *model;
    s32 unknown2D4;
    u8 *owner;
    u8 *other;
    u8 pad2E0[0xC];
    s32 stuck;
    s32 respawn;
    s32 delay;
    s32 flags;
    s16 type;
    u8 pad2FE[0xA];
    f32 health;
    u8 pad30C[8];
    f32 radius;
    s32 unknown318;
    s32 timer1;
    s32 timer2;
    s32 active;
    s32 unknown328;
    s32 target;
    s32 age;
    u8 pad334[0xC];
} P_0066AFA0;

typedef struct K_0066AFA0 {
    void (*spawn)(u8 *);
    u8 pad4[0xC];
    void (*update)(u8 *);
    u8 pad14[8];
} K_0066AFA0;

extern W_0066AFA0 D_001A5CD0;
extern s32 D_001DB0E8_sda __attribute__((section(".sdata")));
__asm__(".extern D_001DB0E8_sda, 4");
extern K_0066AFA0 D_L39_0033AB08[];
extern u8 D_L39_004997E0[];
extern u8 *D_L39_002637C0[];
extern u8 *D_L39_0024CE20[];
extern s32 func_0038CAD0(s32 *);
extern f32 func_0038CE68(void *, void *);
extern s32 func_003D4D00(void *, s32, void *, s32, f32);
extern void func_L01_0043B9E8(void *, s32, s32, s32);
extern void func_L39_0066ACA8(P_0066AFA0 *, s32);
extern void func_L39_00667208(P_0066AFA0 *, u32, s32, s32);
extern void func_L39_0061ECE0(void *, void *, s32);
extern void func_L39_00668D60(P_0066AFA0 *);
extern void func_L39_0066A690(P_0066AFA0 *, s32);
extern void func_L39_006692A0(P_0066AFA0 *, u8 *);
extern void func_L39_00667700(P_0066AFA0 *, u8 *, s32);
extern void func_L39_006673E8(P_0066AFA0 *, u8 *, s32);
extern void func_L39_00628038(u8 *, s32);
extern void func_L39_0066A028(u8 *, s32);

/* the keyed byte-table decode of a protected word at q, as the matched L39 code writes it */
static u32 dec_0066AFA0(u8 *q) {
    Dec_0066AFA0 buf;
    u32 a;
    u32 b;
    s32 n;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    if (*q == 0) {
        return 0;
    }
    n = *q;
    k = ((u32)q - n) & 7;
    m = n + 1;
    d = buf.b;
    for (i = 0; i < 40; i += 5) {
        *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
    }
    a = buf.w[0] ^ (u32)q;
    b = buf.w[1] ^ a;
    return b;
}

void func_L39_0066AFA0(void) {
    vu0_v4 a;
    u8 changed = 0;
    s32 i;
    s32 context;
    P_0066AFA0 *p;
    u8 *owner;
    s32 n;
    s32 j;
    u8 **list;

    context = D_001A5CD0.context;
    for (i = 0; i < D_001DB0E8_sda; i++) {
        p = (P_0066AFA0 *)D_L39_00337700 + i;
        if (p->model == 0) {
            continue;
        }
        p->age++;
        if (p->age > 100) {
            p->age = 100;
        }
        if (p->age > 60 && p->health <= 0.0f && p->active) {
            u8 st = p->model[0xBC];
            if (st != 9 && st != 10 && st != 11 && st != 7 && st != 8) {
                if (p->owner) {
                    *(s16 *)(p->owner + 0x320) = 2;
                }
                if (p->other) {
                    *(s16 *)(p->owner + 0x320) = 2;
                }
            }
        }
        if (D_001A5CD0.running) {
            func_0038CAD0(&p->timer1);
            func_0038CAD0(&p->timer2);
        }
        p->target = -1;
        if (p->owner) {
            if ((dec_0066AFA0(p->owner + 0x19E4) ^ 0x31) != 0 && *(s16 *)(p->model + 0xAA) != 0x10C2) {
                u8 *actor = p->owner;
                ((void (*)(void *, s32, s32, s32, s32))(*(void ***)(actor + 0x14))[13])(actor, 0x31, 1, 0, 1);
                if (!(p->flags & 0x4000000)) {
                    p->owner[0x1A0A] = 1;
                }
            }
        }
        if (p->other) {
            if ((dec_0066AFA0(p->other + 0x19E4) ^ 0x31) != 0) {
                u8 *actor = p->other;
                ((void (*)(void *, s32, s32, s32, s32))(*(void ***)(actor + 0x14))[13])(actor, 0x31, 1, 0, 1);
                if (!(p->flags & 0x4000000)) {
                    p->other[0x1A0A] = 1;
                }
            }
        }
        if (p->owner || p->other) {
            if (p->owner) {
                n = *(s32 *)(p->owner + 0x2548);
            } else {
                n = *(s32 *)(p->other + 0x2548);
            }
            func_L39_0066ACA8(p, n);
            p->target = n;
            p->stuck = 0;
        } else {
            if (p->flags & 0x400) {
                if (p->flags & 0x100) {
                    func_L39_0066ACA8(p, 0);
                    p->target = 0;
                } else if (p->flags & 0x200) {
                    func_L39_0066ACA8(p, 1);
                    p->target = 1;
                }
            } else {
                if (p->type == 0) {
                    *(s32 *)(p->model + 0x78) = 0x787878;
                } else {
                    func_L01_0043B9E8(p->model, 128, 128, 128);
                }
            }
            if (p->model[0xBC] == 0) {
                a = p->spawnPos;
                a.x = a.x - ((vu0_v4 *)(p->model + 0x10))->x;
                a.y = a.y - ((vu0_v4 *)(p->model + 0x10))->y;
                a.z = a.z - ((vu0_v4 *)(p->model + 0x10))->z;
                if (func_0038CE68(&a, &a) > 10.0f) {
                    if (++p->stuck > 7200) {
                        p->health = 0.0f;
                        func_L39_00667208(p, 0xFFFFFFFF, 6, D_001A5CD0.event);
                    }
                }
            }
        }
        if (p->model[0xBC] == 7) {
            *(s32 *)(p->model + 0x98) = 0;
            *(u16 *)(p->model + 0x34) |= 0x41;
            func_0038CAD0(&p->respawn);
            if (p->respawn <= 0) {
                s32 count = func_003D4D00(&p->spawnPos, 1, 0, 0, p->radius * 1.75f);
                if (count == 0 || (count == 1 && *(s16 *)(D_L39_002637C0[0] + 0xAA) == 0x1981)) {
                    *(vu0_v4 *)(p->model + 0x10) = p->spawnPos;
                    *(vu0_v4 *)(p->model + 0xF0) = p->spawnRot;
                    p->previousPos = p->spawnPos;
                    p->previousRot = p->spawnRot;
                    if (D_L39_0033AB08[p->type].spawn) {
                        D_L39_0033AB08[p->type].spawn(p->model);
                    }
                    func_L39_0061ECE0((u8 *)p + 0x20, p->model + 0x10, D_001A5CD0.context);
                    p->active = 0;
                    p->model[0xA8] = 255;
                    p->flags |= 8;
                    if (p->flags & 0x300) {
                        p->flags |= 0x400;
                    }
                    *(s32 *)(p->model + 0x98) = *(s32 *)(*(u8 **)(p->model + 0x24) + 0x10);
                    *(u16 *)(p->model + 0x34) &= 0xFFBE;
                    p->model[0xBC] = 0;
                }
            }
        } else if (p->model[0xBC] == 8) {
            *(s32 *)(p->model + 0x98) = 0;
            *(u16 *)(p->model + 0x34) |= 0x41;
        } else if (p->model[0xBC] != 10) {
            func_L39_00668D60(p);
            func_L39_0066A690(p, context);
            func_L39_006692A0(p, &changed);
            if (D_L39_0033AB08[p->type].update) {
                D_L39_0033AB08[p->type].update(p->model);
            }
        } else if (*(u16 *)(p->model + 0x96) >= 0x97) {
            p->model[0xBC] = 7;
            p->respawn = p->delay;
            *(u16 *)(p->model + 0x96) = 0;
            if (p->owner) {
                owner = p->owner;
                if (!(p->flags & 0x4000000)) {
                    ((void (*)(void *, s32, s32, s32, s32))(*(void ***)(owner + 0x14))[13])(owner, 0x76, 0, 0, 0);
                    owner[0x1A0A] = 1;
                }
                func_L39_00667700(p, owner, 0);
                if (!(p->flags & 0x4000000)) {
                    func_L39_00628038(owner, 0);
                    owner[0x1A0A] = 1;
                }
            }
            if (p->other) {
                owner = p->other;
                if (!(p->flags & 0x4000000)) {
                    ((void (*)(void *, s32, s32, s32, s32))(*(void ***)(owner + 0x14))[13])(owner, 0x76, 0, 0, 0);
                    owner[0x1A0A] = 1;
                }
                func_L39_006673E8(p, owner, 0);
                if (!(p->flags & 0x4000000)) {
                    func_L39_00628038(owner, 0);
                    owner[0x1A0A] = 1;
                }
            }
        }
        (*(u16 *)(p->model + 0x96))++;
    }
    list = D_L39_0024CE20;
    j = 7;
    do {
        owner = *list++;
        j--;
        if (owner) {
            func_L39_0066A028(owner, changed);
        }
    } while (j >= 0);
}
