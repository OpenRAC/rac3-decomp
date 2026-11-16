#include "common.h"

/* localdecomp:start func_L01_00462978 */
typedef void (*Updater_462978)();
extern Updater_462978 D_L01_00220E40[];
extern void func_L01_00461B28();
extern void func_L01_00461C20();
extern void func_L01_00463038();
extern void func_L01_004632D0();
extern void func_L01_00463538();
extern void func_L01_004637C0_00462978();
extern void func_L01_004638C8();
extern void func_L01_004639C8();
extern void func_L01_00463A70();
extern void func_L01_00464178();
extern void func_L01_004642F0();
extern void func_L01_00464400();
extern void func_L01_00464558();
extern void func_L01_00464910();
extern void func_L01_00465168();
extern void func_L01_00465520();
extern void func_L01_00465650();
extern void func_L01_00465878();
extern void func_L01_00465CD0();
extern void func_L01_00465F88_00462978();
extern void func_L01_00465F90();
extern void func_L01_004661F0();
extern void func_L01_00466290();
extern void func_L01_00466678();
extern void func_L01_00466B78();
extern void func_L01_00466E40();
extern void func_L01_004670C8();
extern void func_L01_004674D8();
extern void func_L01_00467608();
extern void func_L01_00467910();
extern void func_L01_00467B20();
extern void func_L01_00467DC8();
extern void func_L01_004682B8();
extern void func_L01_00468468();
extern void func_L01_00468640();
extern void func_L01_00468828();
extern void func_L01_00468B70();
extern void func_L01_00468D98();
extern void func_L01_00468F08();
extern void func_L01_00469018();
extern void func_L01_00469130();
extern void func_L01_004693D8();
extern void func_L01_00469BD0();
extern void func_L01_00469D88();
extern void func_L01_0046A430();
extern void func_L01_0046A798();
extern void func_L01_0046AA88();
extern void func_L01_0046ACD0();
extern void func_L01_0046AE98();
extern void func_L01_0046AF38();
extern void func_L01_0046AFD8();
extern void func_L01_0046B0B8();
extern void func_L01_0046B198();
extern void func_L01_0046B3A8();
extern void func_L01_0046B5F0();
extern void func_L01_0046B898();
extern void func_L01_0046BAE0();
extern void func_L01_0046BC18();
extern void func_L01_0046BCB0();
extern void func_L01_0046BF78();
extern void func_L01_0046C418();
extern void func_L01_0046C5C8();
extern void func_L01_0046C790();
extern void func_L01_0046CB28();
extern void func_L01_0046CC20();
extern void func_L01_0046CDA8();
extern void func_L01_0046CFD8();
extern void func_L01_0046D3B0();
extern void func_L01_0046D5A8();
extern void func_L01_0046D850();
extern void func_L01_0046D980();
extern void func_L01_0046DBE8();
extern void func_L01_0046DC50();
extern void func_L01_0046DF90();
extern void func_L01_0046DFD0();
extern void func_L01_0046E1B8();
extern void func_L01_0046E380();
extern void func_L01_0046E4A0();
extern void func_L01_0046E4F0();
extern void func_L01_0046E720();
extern void func_L01_0046EA10();
extern void func_L01_0046EB58();
extern void func_L01_0046EEA0();
extern void func_L01_0046F2B8();
extern void func_L01_0046F938();
extern void func_L01_0046FA88();
extern void func_L01_0046FD18();
extern void func_L01_0046FE60();
extern void func_L01_00470000();
extern void func_L01_004702E0();
extern void func_L01_00470770();
extern void func_L01_00470A28();
extern void func_L01_00470E48();
extern void func_L01_004710F8();
extern void func_L01_004711C0();
extern void func_L01_004712E0();
extern void func_L01_00471530();
extern void func_L01_00471670();
extern void func_L01_00471748();
extern void func_L01_00471A30();
extern void func_L01_00471B20();
extern void func_L01_00471D88();
extern void func_L01_00471F78();
extern void func_L01_00471FB0();
extern void func_L01_00472158();
extern void func_L01_004723B0();
extern void func_L01_00472758();
extern void func_L01_00472C98();
extern void func_L01_004730F8();
extern void func_L01_004734A8();
extern void func_L01_004736F0();
extern void func_L01_00473860();
extern void func_L01_004739D0_00462978();
extern void func_L01_00473AC8();
extern void func_L01_004741B8();
extern void func_L01_00474328();
extern void func_L01_004744D0();
extern void func_L01_004747C0();
extern void func_L01_00474968();
extern void func_L01_00474B48();
extern void func_L01_00474DE0();
extern void func_L01_00474F38();
extern void func_L01_00475278();
extern void func_L01_004756D0();
extern void func_L01_00475910();
extern void func_L01_00475DC8();
extern void func_L01_004760C8();
extern void D_L01_00474070();

/* particle_types_init: fills particle_update_table, the update routine of each particle type. */
void func_L01_00462978(void) {
    D_L01_00220E40[0x0] = func_L01_00463038;
    D_L01_00220E40[0x1] = func_L01_004632D0;
    D_L01_00220E40[0x2] = func_L01_00463538;
    D_L01_00220E40[0x3] = func_L01_004637C0_00462978;
    D_L01_00220E40[0x4] = func_L01_004638C8;
    D_L01_00220E40[0x5] = func_L01_004639C8;
    D_L01_00220E40[0x6] = func_L01_00463A70;
    D_L01_00220E40[0x7] = func_L01_00464178;
    D_L01_00220E40[0x8] = func_L01_004642F0;
    D_L01_00220E40[0x9] = func_L01_00464400;
    D_L01_00220E40[0xA] = func_L01_00464558;
    D_L01_00220E40[0xB] = func_L01_00464910;
    D_L01_00220E40[0xC] = func_L01_00465168;
    D_L01_00220E40[0xD] = func_L01_00465520;
    D_L01_00220E40[0xE] = func_L01_00465650;
    D_L01_00220E40[0xF] = func_L01_00465878;
    D_L01_00220E40[0x10] = func_L01_00465CD0;
    D_L01_00220E40[0x11] = func_L01_00465F88_00462978;
    D_L01_00220E40[0x12] = func_L01_00465F90;
    D_L01_00220E40[0x13] = func_L01_004661F0;
    D_L01_00220E40[0x14] = func_L01_00466290;
    D_L01_00220E40[0x15] = func_L01_00466678;
    D_L01_00220E40[0x16] = func_L01_00461B28;
    D_L01_00220E40[0x17] = func_L01_00466B78;
    D_L01_00220E40[0x18] = func_L01_00466E40;
    D_L01_00220E40[0x19] = func_L01_004670C8;
    D_L01_00220E40[0x1A] = func_L01_004674D8;
    D_L01_00220E40[0x1B] = func_L01_00467608;
    D_L01_00220E40[0x1C] = func_L01_00467910;
    D_L01_00220E40[0x1D] = func_L01_00467B20;
    D_L01_00220E40[0x1E] = func_L01_00467DC8;
    D_L01_00220E40[0x1F] = func_L01_004682B8;
    D_L01_00220E40[0x20] = func_L01_00468468;
    D_L01_00220E40[0x21] = func_L01_00468640;
    D_L01_00220E40[0x22] = func_L01_00468828;
    D_L01_00220E40[0x23] = func_L01_00468B70;
    D_L01_00220E40[0x24] = func_L01_00468D98;
    D_L01_00220E40[0x25] = func_L01_00468F08;
    D_L01_00220E40[0x26] = func_L01_00469018;
    D_L01_00220E40[0x27] = func_L01_00469130;
    D_L01_00220E40[0x28] = func_L01_004693D8;
    D_L01_00220E40[0x29] = func_L01_00469BD0;
    D_L01_00220E40[0x2A] = func_L01_00469D88;
    D_L01_00220E40[0x2B] = func_L01_0046A430;
    D_L01_00220E40[0x2C] = func_L01_0046A798;
    D_L01_00220E40[0x2D] = func_L01_0046AA88;
    D_L01_00220E40[0x2E] = func_L01_0046ACD0;
    D_L01_00220E40[0x2F] = func_L01_0046AE98;
    D_L01_00220E40[0x30] = func_L01_0046AF38;
    D_L01_00220E40[0x31] = func_L01_0046AFD8;
    D_L01_00220E40[0x32] = func_L01_0046B0B8;
    D_L01_00220E40[0x33] = func_L01_0046B198;
    D_L01_00220E40[0x34] = func_L01_0046B3A8;
    D_L01_00220E40[0x35] = func_L01_0046B5F0;
    D_L01_00220E40[0x36] = func_L01_0046B898;
    D_L01_00220E40[0x37] = func_L01_0046BAE0;
    D_L01_00220E40[0x38] = func_L01_0046BC18;
    D_L01_00220E40[0x39] = func_L01_0046BCB0;
    D_L01_00220E40[0x3A] = func_L01_0046BF78;
    D_L01_00220E40[0x3B] = func_L01_0046C418;
    D_L01_00220E40[0x3C] = func_L01_0046C5C8;
    D_L01_00220E40[0x3D] = func_L01_0046C790;
    D_L01_00220E40[0x3E] = func_L01_0046CB28;
    D_L01_00220E40[0x3F] = func_L01_0046CC20;
    D_L01_00220E40[0x40] = func_L01_0046CDA8;
    D_L01_00220E40[0x41] = func_L01_0046CFD8;
    D_L01_00220E40[0x42] = func_L01_0046D3B0;
    D_L01_00220E40[0x43] = func_L01_0046D5A8;
    D_L01_00220E40[0x44] = func_L01_0046D850;
    D_L01_00220E40[0x45] = func_L01_0046D980;
    D_L01_00220E40[0x46] = func_L01_0046DBE8;
    D_L01_00220E40[0x47] = func_L01_0046DC50;
    D_L01_00220E40[0x48] = func_L01_0046DF90;
    D_L01_00220E40[0x49] = func_L01_0046DFD0;
    D_L01_00220E40[0x4A] = func_L01_0046E1B8;
    D_L01_00220E40[0x4B] = func_L01_0046E380;
    D_L01_00220E40[0x4C] = func_L01_0046E4A0;
    D_L01_00220E40[0x4D] = func_L01_0046E4F0;
    D_L01_00220E40[0x4E] = func_L01_0046E720;
    D_L01_00220E40[0x4F] = func_L01_0046EA10;
    D_L01_00220E40[0x50] = func_L01_0046EB58;
    D_L01_00220E40[0x51] = func_L01_0046EEA0;
    D_L01_00220E40[0x52] = func_L01_0046F2B8;
    D_L01_00220E40[0x53] = func_L01_0046F938;
    D_L01_00220E40[0x54] = func_L01_0046FA88;
    D_L01_00220E40[0x55] = func_L01_00461C20;
    D_L01_00220E40[0x56] = func_L01_0046FE60;
    D_L01_00220E40[0x57] = func_L01_00470000;
    D_L01_00220E40[0x58] = func_L01_0046FD18;
    D_L01_00220E40[0x59] = func_L01_004702E0;
    D_L01_00220E40[0x5A] = func_L01_00470770;
    D_L01_00220E40[0x5B] = func_L01_00470A28;
    D_L01_00220E40[0x5C] = func_L01_00470E48;
    D_L01_00220E40[0x5D] = func_L01_00461C20;
    D_L01_00220E40[0x5E] = func_L01_004710F8;
    D_L01_00220E40[0x5F] = func_L01_004711C0;
    D_L01_00220E40[0x60] = func_L01_004712E0;
    D_L01_00220E40[0x61] = func_L01_00471530;
    D_L01_00220E40[0x62] = func_L01_00471670;
    D_L01_00220E40[0x63] = func_L01_00471748;
    D_L01_00220E40[0x64] = func_L01_00471A30;
    D_L01_00220E40[0x65] = func_L01_00471B20;
    D_L01_00220E40[0x66] = func_L01_00471D88;
    D_L01_00220E40[0x67] = func_L01_00471F78;
    D_L01_00220E40[0x68] = func_L01_00471FB0;
    D_L01_00220E40[0x69] = func_L01_00472158;
    D_L01_00220E40[0x6A] = func_L01_004723B0;
    D_L01_00220E40[0x6B] = func_L01_00472758;
    D_L01_00220E40[0x6C] = func_L01_00472C98;
    D_L01_00220E40[0x6D] = func_L01_004730F8;
    D_L01_00220E40[0x6E] = func_L01_004734A8;
    D_L01_00220E40[0x6F] = func_L01_004736F0;
    D_L01_00220E40[0x70] = func_L01_00473860;
    D_L01_00220E40[0x71] = func_L01_004739D0_00462978;
    D_L01_00220E40[0x72] = func_L01_00473AC8;
    D_L01_00220E40[0x73] = D_L01_00474070;
    D_L01_00220E40[0x74] = func_L01_004741B8;
    D_L01_00220E40[0x75] = func_L01_00474328;
    D_L01_00220E40[0x76] = func_L01_004744D0;
    D_L01_00220E40[0x77] = func_L01_004747C0;
    D_L01_00220E40[0x78] = func_L01_00474968;
    D_L01_00220E40[0x79] = func_L01_00474B48;
    D_L01_00220E40[0x7A] = func_L01_00474DE0;
    D_L01_00220E40[0x7B] = func_L01_00474F38;
    D_L01_00220E40[0x7C] = func_L01_00475278;
    D_L01_00220E40[0x7D] = func_L01_004756D0;
    D_L01_00220E40[0x7E] = func_L01_00475910;
    D_L01_00220E40[0x7F] = func_L01_00475DC8;
    D_L01_00220E40[0x80] = func_L01_004760C8;
}
/* localdecomp:end func_L01_00462978 */

LINKER_REMNANT("asm/levels", func_L01_00463030);

INCLUDE_ASM("asm/levels", func_L01_00463038);

INCLUDE_ASM("asm/levels", func_L01_00463218);

/* localdecomp:start func_L01_004632D0 */
extern s32 func_0038CB00(u8 *);
extern void func_003CD250(u8 *);
extern u8 *D_L01_0022109C[];

void func_L01_004632D0(u8 *self) {
    s32 alpha = *(s16 *)(self + 0xA) * *(s32 *)(self + 0x20) / 22;
    *(u32 *)(self + 4) = (*(u32 *)(self + 4) & 0xFFFFFFu) | (alpha << 24);
    if (func_0038CB00(self + 0xA)) {
        func_003CD250(self);
    } else {
        self[2] = D_L01_0022109C[0][(22 - *(s16 *)(self + 0xA)) * 9 / 22];
    }
}
/* localdecomp:end func_L01_004632D0 */

INCLUDE_ASM("asm/levels", func_L01_00463378);

INCLUDE_ASM("asm/levels", func_L01_00463538);

/* localdecomp:start func_L01_004637C0 */
void func_L01_004637C0(void) {

}
/* localdecomp:end func_L01_004637C0 */

/* localdecomp:start func_L01_004637C8 */
typedef int Quad_4637C8 __attribute__((mode(TI)));
typedef struct {
    Quad_4637C8 velocity;          /* 0x20 */
    u32 rgba;                      /* 0x30: the colour it fades from */
    s32 spin_step;                 /* 0x34 */
    s16 size_start;                /* 0x38: x 1000 */
    s16 size_grow;                 /* 0x3A: x 1000, over its life */
    s32 life_start;                /* 0x3C */
} Puff_4637C8;
typedef struct {
    u8 type;                       /* 0x00 */
    s8 flags;                      /* 0x01 */
    u8 texture;                    /* 0x02 */
    u8 render;                     /* 0x03: 0x48 added, 0x44 blended */
    u32 rgba;                      /* 0x04 */
    u8 spin;                       /* 0x08 */
    u8 render2;                    /* 0x09 */
    s16 life;                      /* 0x0A */
    s32 size;                      /* 0x0C */
    Quad_4637C8 position;          /* 0x10 */
    Puff_4637C8 puff;              /* 0x20 */
} Particle_4637C8;

extern u8 *D_L01_002210A8[];
/* declared as the file's other blocks declare them */
extern u8 *func_L01_004618E0(s32);
extern u8 func_0013D3E0(void);

/* particle_spawn_smoke_puff: a type 4 particle, a smoke puff at position drifting at velocity,
 * growing from size_start to size_start + size_grow (x 1000) over its life and fading from
 * rgba to nothing; added if added is set, else blended. */
Particle_4637C8 *func_L01_004637C8(Quad_4637C8 *position, Quad_4637C8 *velocity, u32 rgba, s32 spin_step,
                                   s32 life, s32 size_grow, s32 size_start, s32 added) {
    Particle_4637C8 *p = (Particle_4637C8 *)func_L01_004618E0(4);

    if (p != 0) {
        Puff_4637C8 *puff;

        p->position = *position;
        p->render2 = 0xA4;
        p->rgba = rgba;
        p->render = added ? 0x48 : 0x44;
        p->flags = 0;
        p->texture = *D_L01_002210A8[0];
        p->spin = func_0013D3E0();
        puff = &p->puff;
        p->size = 0;
        p->position = *position;
        p->puff.velocity = *velocity;
        p->life = life;
        puff->life_start = life;
        puff->rgba = rgba;
        puff->spin_step = spin_step;
        puff->size_start = size_start;
        puff->size_grow = size_grow;
    }
    return p;
}
/* localdecomp:end func_L01_004637C8 */

INCLUDE_ASM("asm/levels", func_L01_004638C8);

LINKER_REMNANT("asm/levels", func_L01_004639C0);

INCLUDE_ASM("asm/levels", func_L01_004639C8);

LINKER_REMNANT("asm/levels", func_L01_00463A68);

INCLUDE_ASM("asm/levels", func_L01_00463A70);

INCLUDE_ASM("asm/levels", func_L01_00464178);

INCLUDE_ASM("asm/levels", func_L01_00464210);

INCLUDE_ASM("asm/levels", func_L01_004642F0);

LINKER_REMNANT("asm/levels", func_L01_004643F8);

INCLUDE_ASM("asm/levels", func_L01_00464400);

LINKER_REMNANT("asm/levels", func_L01_00464550);

INCLUDE_ASM("asm/levels", func_L01_00464558);

INCLUDE_ASM("asm/levels", func_L01_00464690);

INCLUDE_ASM("asm/levels", func_L01_00464910);

INCLUDE_ASM("asm/levels", func_L01_00464EC8);

INCLUDE_ASM("asm/levels", func_L01_00465168);

INCLUDE_ASM("asm/levels", func_L01_004653B8);

INCLUDE_ASM("asm/levels", func_L01_00465520);

LINKER_REMNANT("asm/levels", func_L01_00465648);

INCLUDE_ASM("asm/levels", func_L01_00465650);

INCLUDE_ASM("asm/levels", func_L01_00465738);

INCLUDE_ASM("asm/levels", func_L01_00465878);

/* localdecomp:start func_L01_00465B30 */
typedef int s128 __attribute__((mode(TI)));

typedef struct {
    s128 v;
    s32 w16;
    s32 w20;
    s16 h24;
    s16 h26;
    f32 f28;
} Sub_00462578;

extern f32 D_L01_001DFB4C;
extern u8 *D_L01_002210D8[];
extern s32 func_00382468(s32);
extern u8 *func_L01_004618E0(s32);
extern u8 func_0013D3E0(void);

u8 *func_L01_00465B30(s128 *a0, s128 *a1, s32 a2, s32 a3, s32 t0, s32 t1, f32 f12) {
    u8 *o;
    Sub_00462578 *e;
    u8 *p;

    if (t0 == 0) {
        return 0;
    }
    {
        if (0.9f < D_L01_001DFB4C) {
            if (func_00382468(3) == 0) {
                return 0;
            }
        }
        if (0.95f < D_L01_001DFB4C) {
            if (func_00382468(2) == 0) {
                return 0;
            }
        }
        if (1.0f < D_L01_001DFB4C) {
            if (func_00382468(1) == 0) {
                return 0;
            }
        }
    }
    o = func_L01_004618E0(16);
    if (o != 0) {
        *(s128 *)(o + 16) = *a0;
        *(s32 *)(o + 4) = a2;
        o[1] = 0;
        *(f32 *)(o + 12) = f12;
        o[9] = 68;
        o[3] = 68;
        o[8] = func_0013D3E0();
        p = D_L01_002210D8[0] + t1;
        if (t1 == 3) {
            p = D_L01_002210D8[0];
        }
        e = (Sub_00462578 *)(o + 32);
        o[2] = *p;
        *(s16 *)(o + 10) = t0;
        e->h24 = t0;
        e->f28 = f12;
        e->w16 = a2;
        e->w20 = a3;
        e->h26 = t1;
        e->v = *a1;
        ((f32 *)e)[3] = ((f32 *)a0)[2] - 0.5f;
    }
    return o;
}
/* localdecomp:end func_L01_00465B30 */

INCLUDE_ASM("asm/levels", func_L01_00465CD0);

/* localdecomp:start func_L01_00465F88 */
void func_L01_00465F88(void) {

}
/* localdecomp:end func_L01_00465F88 */

/* localdecomp:start func_L01_00465F90 */
extern s32 func_0038CB00(u8 *);
extern void func_003CD250(u8 *);

void func_L01_00465F90(u8 *o)
{
    f32 *p = (f32 *)(o + 32);
    f32 f;
    f32 y;

    f = p[1] + p[3] * 0.0156000007f;
    p[1] = f;
    if (f <= 0.0f || func_0038CB00(o + 10) != 0) {
        func_003CD250(o);
    } else {
        f = p[1];
        if (0.22f <= f) {
            y = p[3];
            y = -y;
            p[3] = y;
            p[1] = f + y * 0.0156000007f;
        }
        *(f32 *)(o + 12) = *(f32 *)(o + 12) + 9828.0f;
        *(u32 *)(o + 4) = (*(u32 *)(o + 4) & 0xFFFFFFu) | ((s32)(p[1] * 255.0f) << 24);
        p[2] = p[2] + 0.0144000009f;
        if (p[2] > 1.0f)
            p[2] = p[2] - 1.0f;
        *(u8 *)(o + 8) = (u8)(p[2] * 255.0f);
        *(f32 *)(o + 24) = *(f32 *)(o + 24) - 0.02f;
    }
}
/* localdecomp:end func_L01_00465F90 */

INCLUDE_ASM("asm/levels", func_L01_004660F8);

INCLUDE_ASM("asm/levels", func_L01_004661F0);

INCLUDE_ASM("asm/levels", func_L01_00466290);

/* localdecomp:start func_L01_00466588 */
extern u8 *func_L01_004618E0(s32);
typedef int s128_00462FD0 __attribute__((mode(TI)));
typedef struct {
    s128_00462FD0 v;
    s32 f10;
    s32 f14;
    s16 f18;
    s16 f1A;
    f32 f1C;
} Sub_00462FD0;
typedef struct {
    u8 f0;
    u8 f1;
    u8 f2;
    u8 f3;
    s32 f4;
    u8 f8;
    u8 f9;
    s16 fA;
    f32 fC;
    s128_00462FD0 f10;
    Sub_00462FD0 sub;
} Part_00462FD0;
extern u8 *D_L01_002210EC[];
extern u8 func_0013D3E0(void);
Part_00462FD0 *func_L01_00466588(s128_00462FD0 *pos, s128_00462FD0 *v2, s32 a2, s32 a3, s32 t0, s32 t1, f32 f) {
    Part_00462FD0 *p;
    Sub_00462FD0 *q;
    if (t0 == 0) {
        return 0;
    }
    p = ((Part_00462FD0 * (*)(s32))func_L01_004618E0)(21);
    if (p != 0) {
        p->f10 = *pos;
        p->f4 = a2;
        p->f1 = 0;
        p->fC = f;
        p->f9 = 164;
        p->f3 = 72;
        p->f8 = func_0013D3E0();
        p->f2 = *D_L01_002210EC[0];
        q = &p->sub;
        p->fA = t0;
        q->f18 = t0;
        q->f1C = f;
        q->f10 = a2;
        q->f14 = a3;
        q->f1A = t1;
        q->v = *v2;
    }
    return p;
}
/* localdecomp:end func_L01_00466588 */

INCLUDE_ASM("asm/levels", func_L01_00466678);

INCLUDE_ASM("asm/levels", func_L01_004668A0);

/* localdecomp:start func_L01_004669B0 */
typedef int Quad_4669B0 __attribute__((mode(TI)));
typedef struct {
    u32 rgba;                      /* 0x20: the colour it fades from */
    s32 pad_24;                    /* 0x24 */
    s16 spin_rate;                 /* 0x28: turn a frame, random sign */
    u8 pad_2A[2];
    f32 grow;                      /* 0x2C: size factor a frame */
    Quad_4669B0 drift;             /* 0x30: w is 25.0 */
} Cloud_4669B0;
typedef struct {
    u8 type;                       /* 0x00 */
    s8 flags;                      /* 0x01 */
    u8 texture;                    /* 0x02 */
    u8 render;                     /* 0x03 */
    u32 rgba;                      /* 0x04 */
    u8 spin;                       /* 0x08 */
    u8 render2;                    /* 0x09 */
    s16 life;                      /* 0x0A */
    f32 size;                      /* 0x0C */
    f32 x;                         /* 0x10: the position */
    f32 y;                         /* 0x14 */
    f32 z;                         /* 0x18 */
    f32 fade_start;                /* 0x1C */
    Cloud_4669B0 cloud;            /* 0x20 */
} Smoke_4669B0;

extern u8 *D_L01_002210F4[];
extern u8 *func_L01_004618E0(s32);
extern s32 func_00382468(s32);
extern f32 func_003824E0(f32, f32);
extern f32 func_L01_00443A18(f32, f32);

/* particle_spawn_smoke: a type 0x17 particle, the dark smoke: it appears at position jittered by up
 * to jitter, grows by a factor from grow_min to grow_max a frame and fades in before it fades out. */
Smoke_4669B0 *func_L01_004669B0(Quad_4669B0 *position, s32 spin_rate, Quad_4669B0 *drift, u32 rgba, s32 fade_start,
                                f32 jitter, f32 grow_min, f32 grow_max, f32 size) {
    Smoke_4669B0 *p = (Smoke_4669B0 *)func_L01_004618E0(0x17);
    Cloud_4669B0 *cloud;

    if (p != 0) {
        *(Quad_4669B0 *)&p->x = *position;
        p->flags = 0;
        p->render2 = 0x74;
        p->render = 0x48;
        p->rgba = rgba | 0x20000000;
        cloud = &p->cloud;
        p->size = size;
        p->spin = 0;
        p->texture = *D_L01_002210F4[0];
        p->x += func_L01_00443A18(0.0f, jitter);
        p->y += func_L01_00443A18(0.0f, jitter);
        p->z += func_L01_00443A18(0.0f, jitter);
        p->fade_start = fade_start;
        p->life = 8;
        cloud->pad_24 = 0;
        cloud->rgba = rgba;
        if (func_00382468(2) != 0) cloud->spin_rate = spin_rate * 1.2f;
        else cloud->spin_rate = -spin_rate * 1.2f;
        cloud->grow = func_003824E0(grow_min, grow_max);
        cloud->drift = *drift;
        ((f32 *)&cloud->drift)[3] = 25.0f;
    }
    return p;
}
/* localdecomp:end func_L01_004669B0 */

INCLUDE_ASM("asm/levels", func_L01_00466B78);

LINKER_REMNANT("asm/levels", func_L01_00466E38);

INCLUDE_ASM("asm/levels", func_L01_00466E40);

/* localdecomp:start func_L01_00466F50 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec_466F50;
typedef struct {
    Vec_466F50 velocity;           /* 0x20: w is the gravity (0: 22.7 u/s^2) */
    f32 red_fade;                  /* 0x30: 1 white to yellow to red, -1 to green */
    f32 green_fade;                /* 0x34 */
    f32 blue_fade;                 /* 0x38 */
    f32 alpha;                     /* 0x3C */
} Spark_466F50;
typedef struct {
    u8 type;                       /* 0x00 */
    s8 flags;                      /* 0x01 */
    u8 texture;                    /* 0x02 */
    u8 render;                     /* 0x03 */
    u32 rgba;                      /* 0x04 */
    u8 spin;                       /* 0x08 */
    u8 render2;                    /* 0x09 */
    s16 life;                      /* 0x0A */
    f32 size;                      /* 0x0C: world units x 210000 */
    Vec_466F50 position;           /* 0x10 */
    Spark_466F50 spark;            /* 0x20 */
} Particle_466F50;

extern u8 *D_L01_002210FC[];
extern u8 *func_L01_004618E0(s32);
extern u32 func_L01_00448CC0(f32 r, f32 g, f32 b, f32 a);
extern f32 func_003824E0(f32 low, f32 high);

/* particle_spawn_spark: a type 0x19 particle, a drop or spark at position moving at velocity
 * that falls by gravity, shrinks and stops where it meets the world: white at alpha 0.6 going
 * to red, or to green if green is set; a negative size is a random 5000-30000. */
void func_L01_00466F50(Vec_466F50 *position, Vec_466F50 *velocity, s32 green, f32 size, f32 gravity) {
    Particle_466F50 *p = (Particle_466F50 *)func_L01_004618E0(0x19);

    if (p != 0) {
        Spark_466F50 *spark;

        p->position = *position;
        spark = &p->spark;
        if (!green) {
            p->rgba = func_L01_00448CC0(1.0f, 1.0f, 1.0f, 0.6f);
            spark->red_fade = 1.0f;
            spark->green_fade = 1.0f;
            spark->blue_fade = 1.0f;
        } else {
            p->rgba = func_L01_00448CC0(1.0f, 1.0f, 1.0f, 0.6f);
            spark->red_fade = -1.0f;
            spark->green_fade = -1.0f;
            spark->blue_fade = -1.0f;
        }
        p->render2 = 0x44;
        p->render = 0x48;
        p->flags = 0;
        if (size < 0.0f) p->size = func_003824E0(5000.0f, 30000.0f);
        else p->size = size;
        p->spin = 0;
        p->texture = *D_L01_002210FC[0];
        spark->alpha = 0.6f;
        p->life = 0x43;
        spark->velocity = *velocity;
        spark->velocity.w = gravity;
    }
}
/* localdecomp:end func_L01_00466F50 */

INCLUDE_ASM("asm/levels", func_L01_004670C8);

LINKER_REMNANT("asm/levels", func_L01_004674D0);

INCLUDE_ASM("asm/levels", func_L01_004674D8);

INCLUDE_ASM("asm/levels", func_L01_00467608);

INCLUDE_ASM("asm/levels", func_L01_00467688);

INCLUDE_ASM("asm/levels", func_L01_00467910);

INCLUDE_ASM("asm/levels", func_L01_00467B20);

LINKER_REMNANT("asm/levels", func_L01_00467DC0);

INCLUDE_ASM("asm/levels", func_L01_00467DC8);

LINKER_REMNANT("asm/levels", func_L01_004682B0);

INCLUDE_ASM("asm/levels", func_L01_004682B8);

LINKER_REMNANT("asm/levels", func_L01_00468460);

INCLUDE_ASM("asm/levels", func_L01_00468468);

/* localdecomp:start func_L01_00468640 */
extern s32 func_0038CB00(u8 *);
extern void func_003CD250(u8 *);
void func_L01_00468640(u8 *a0) {
    if (func_0038CB00(a0 + 10)) {
        func_003CD250(a0);
    }
}
/* localdecomp:end func_L01_00468640 */

/* localdecomp:start func_L01_00468678 */
#include "structs/hero.h"
typedef int Quad_468678 __attribute__((mode(TI)));
typedef struct {
    u8 type;                       /* 0x00 */
    s8 flags;                      /* 0x01 */
    u8 texture;                    /* 0x02 */
    u8 render;                     /* 0x03 */
    u32 rgba;                      /* 0x04 */
    u8 spin;                       /* 0x08 */
    u8 render2;                    /* 0x09 */
    s16 life;                      /* 0x0A */
    f32 size;                      /* 0x0C */
    Quad_468678 position;          /* 0x10 */
} Bubble_468678;
typedef struct {
    f32 velocity[3];               /* 0x20 */
    f32 wobble_size;               /* 0x2C */
    f32 surface_z;                 /* 0x30: the water height it pops at */
    f32 wobble_phase;              /* 0x34 */
    f32 wobble_speed;              /* 0x38 */
    f32 wobble_amp;                /* 0x3C */
    f32 rise;                      /* 0x40 */
} Rise_468678;

extern u8 *D_L01_00221120[];
extern struct Hero D_001A4BE0;
extern u8 *func_L01_004618E0(s32);
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);

/* particle_spawn_bubble: a type 0x22 particle, a bubble rising from position at velocity; surface_z
 * is where it pops (-1 for the hero's water height, or his z + 0.4 in state 0x30). */
Bubble_468678 *func_L01_00468678(Quad_468678 *position, f32 *velocity, u32 rgba, f32 scale, f32 surface_z) {
    Bubble_468678 *p = (Bubble_468678 *)func_L01_004618E0(0x22);
    Rise_468678 *r;

    if (p != 0) {
        p->rgba = rgba;
        p->flags = 0;
        r = (Rise_468678 *)((u8 *)p + 0x20);
        p->render2 = 0x44;
        p->render = 0x44;
        r->wobble_size = func_003824E0(0.75f, 1.25f) * scale;
        p->size = 5250.0f;
        p->spin = func_00382498(-10, 10) - 0x80;
        p->texture = *D_L01_00221120[0];
        p->life = func_00382498(0x3A, 0x75);
        if (surface_z == -1.0f) {
            if (D_001A4BE0.state == 0x30) r->surface_z = D_001A4BE0.pos.z + 0.4f;
            else r->surface_z = D_001A4BE0.water_height;
        } else {
            r->surface_z = surface_z;
        }
        r->wobble_phase = func_00382538();
        r->wobble_speed = func_003824E0(0.03490659f /* 2 degrees */, 0.13962636f /* 8 degrees */);
        r->wobble_amp = func_003824E0(0.010000001f, 0.028f);
        r->velocity[0] = velocity[0];
        r->velocity[1] = velocity[1];
        r->velocity[2] = velocity[2];
        p->position = *position;
    }
    return p;
}
/* localdecomp:end func_L01_00468678 */

INCLUDE_ASM("asm/levels", func_L01_00468828);

INCLUDE_ASM("asm/levels", func_L01_00468A68);

INCLUDE_ASM("asm/levels", func_L01_00468B70);

INCLUDE_ASM("asm/levels", func_L01_00468D98);

LINKER_REMNANT("asm/levels", func_L01_00468F00);

INCLUDE_ASM("asm/levels", func_L01_00468F08);

LINKER_REMNANT("asm/levels", func_L01_00469010);

INCLUDE_ASM("asm/levels", func_L01_00469018);

LINKER_REMNANT("asm/levels", func_L01_00469128);

INCLUDE_ASM("asm/levels", func_L01_00469130);

INCLUDE_ASM("asm/levels", func_L01_00469210);

INCLUDE_ASM("asm/levels", func_L01_004693D8);

/* localdecomp:start func_L01_00469BD0 */
extern void func_003CD250(u8 *);
extern s32 func_0038CB00(u8 *);
typedef struct { u8 pad[0xA]; s16 h; } S_466558;

void func_L01_00469BD0(S_466558 *p) {
    if (p->h != -1 && ((s32 (*)(s16 *))func_0038CB00)(&p->h) != 0) {
        ((void (*)(S_466558 *))func_003CD250)(p);
    }
}
/* localdecomp:end func_L01_00469BD0 */

INCLUDE_ASM("asm/levels", func_L01_00469C18);

INCLUDE_ASM("asm/levels", func_L01_00469D88);

LINKER_REMNANT("asm/levels", func_L01_0046A428);

INCLUDE_ASM("asm/levels", func_L01_0046A430);

/* localdecomp:start func_L01_0046A610 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec_46A610;
typedef struct {
    f32 velocity[3];               /* 0x20 */
    f32 gravity;                   /* 0x2C */
    u8 spin_step;                  /* 0x30: a frame, x 1.2 for 50 Hz */
    u8 rgb[3];                     /* 0x31: the colour it starts from */
    f32 size_step;                 /* 0x34: a frame, x 1.2 */
    f32 drag;                      /* 0x38: velocity kept a frame, 1.0 for none */
    s16 life_start;                /* 0x3C */
    s16 alpha_start;               /* 0x3E */
} Ember_46A610;
typedef struct {
    u8 type;                       /* 0x00 */
    s8 flags;                      /* 0x01 */
    u8 texture;                    /* 0x02 */
    u8 render;                     /* 0x03 */
    u32 rgba;                      /* 0x04 */
    u8 spin;                       /* 0x08 */
    u8 render2;                    /* 0x09 */
    s16 life;                      /* 0x0A */
    f32 size;                      /* 0x0C: world units x 210000 */
    Vec_46A610 position;           /* 0x10 */
    Ember_46A610 ember;            /* 0x20 */
} Particle_46A610;

extern u8 *D_L01_00221148[];
extern u8 *func_L01_004618E0(s32);
extern s32 func_00382468(s32);

/* particle_spawn_ember: a type 0x2C particle, an ember or spark that fades to nothing over its
 * life, grows a set step a frame, keeps drag of its velocity and falls by gravity; the per-frame
 * rates are scaled by 1.2 for PAL's 50 Hz. */
Particle_46A610 *func_L01_0046A610(Vec_46A610 *position, f32 *velocity, s32 life, s32 alpha, s32 rgb, s32 spin_step,
                                   f32 size, f32 size_step, f32 drag, f32 gravity, f32 w) {
    Particle_46A610 *p = (Particle_46A610 *)func_L01_004618E0(0x2C);

    if (p != 0) {
        Ember_46A610 *ember;

        p->position = *position;
        p->size = size;
        p->position.w = w;
        p->flags = 0;
        p->rgba = (alpha << 24) | rgb;
        p->render2 = 0x44;
        p->render = 0x48;
        p->spin = func_00382468(0xFF);
        p->texture = *D_L01_00221148[0];
        p->life = life;
        ember = &p->ember;
        ember->velocity[0] = velocity[0];
        ember->velocity[1] = velocity[1];
        ember->velocity[2] = velocity[2];
        ember->spin_step = spin_step * 1.2f;
        ember->size_step = size_step * 1.2f;
        ember->drag = (drag - 1.0f) * 1.2f + 1.0f;
        ember->rgb[0] = rgb;
        ember->rgb[1] = rgb >> 8;
        ember->rgb[2] = rgb >> 16;
        ember->life_start = life;
        ember->alpha_start = alpha;
        ember->gravity = gravity;
    }
    return p;
}
/* localdecomp:end func_L01_0046A610 */

INCLUDE_ASM("asm/levels", func_L01_0046A798);
