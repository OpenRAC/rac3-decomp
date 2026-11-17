#include "common.h"
#include "vu0.h"

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

/* localdecomp:start func_L01_00463218 */
typedef int Q_463218 __attribute__((mode(TI)));
extern u8 *D_L01_0022109C[];
extern u8 *func_L01_004618E0(s32);

void func_L01_00463218(void *a0, s32 a1, s32 a2) {
    u8 *p = func_L01_004618E0(1);
    if (p != 0) {
        ((f32 *)a0)[2] += 0.2f;
        *(Q_463218 *)(p + 0x10) = *(Q_463218 *)a0;
        *(u32 *)(p + 4) = (a1 << 24) | 0x907070;
        p[9] = 0x42;
        p[3] = 0x44;
        p[1] = 0;
        p[2] = *D_L01_0022109C[0];
        *(f32 *)(p + 0xC) = 63000.004f;
        p[8] = 0xA0;
        *(s16 *)(p + 0xA) = 0x16;
        *(s32 *)(p + 0x20) = a1;
    }
}
/* localdecomp:end func_L01_00463218 */

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

/* localdecomp:start func_L01_00463538 */
#include "vu0.h"
typedef struct {
    u32 velocity0, velocity1;
    u32 color0, color1;
    s16 duration0, duration1, duration2, size0, size1;
} S_00463538;
extern u32 D_L01_001DFB40;
__asm__(".extern D_L01_001DFB40, 16");
/* EE Timer 0 count register, reset in the first phase. */
extern volatile u32 D_L01_10000000[];
void func_L01_00463538(u8 *self) {
    extern void func_L01_0044E130(void *, void *);
    extern u32 func_0038DBD8(u32, u32, f32);
    extern void func_0038CDF8(void *, void *, void *, f32);
    extern s32 func_0038CB00(u8 *);
    extern void func_003CD250(u8 *);
    S_00463538 *s = (S_00463538 *)(self + 0x20);
    vu0_v4 delta, first, second;
    f32 factor;
    if (D_L01_001DFB40 & 1) self[8]++;
    if (s->duration0 != 0) {
        D_L01_10000000[0] = 0;
        func_L01_0044E130(&delta, s);
        vec_add_ab(self + 0x10, self + 0x10, &delta);
        *(u32 *)(self + 4) = func_0038DBD8(s->color0 & 0xFFFFFF, s->color0, 1.0f - (f32)*(s16 *)(self + 0xA) / (f32)s->duration0);
        *(f32 *)(self + 0xC) = s->size0 * 1000;
        if (func_0038CB00(self + 0xA)) {
            s->duration0 = 0;
            *(s16 *)(self + 0xA) = s->duration1;
        }
    } else if (s->duration1 != 0) {
        func_L01_0044E130(&first, s);
        func_L01_0044E130(&second, &s->velocity1);
        factor = (f32)*(s16 *)(self + 0xA) / (f32)s->duration1;
        func_0038CDF8(&delta, &second, &first, factor);
        vec_add_ab(self + 0x10, self + 0x10, &delta);
        *(f32 *)(self + 0xC) = ((s->size0 - s->size1) * factor + s->size1) * 1000.0f;
        *(u32 *)(self + 4) = func_0038DBD8(s->color1, s->color0, factor);
        if (func_0038CB00(self + 0xA)) {
            s->duration1 = 0;
            *(s16 *)(self + 0xA) = s->duration2;
        }
    } else {
        func_L01_0044E130(&delta, &s->velocity1);
        vec_add_ab(self + 0x10, self + 0x10, &delta);
        *(u32 *)(self + 4) = func_0038DBD8(s->color1 & 0xFFFFFF, s->color1, (f32)*(s16 *)(self + 0xA) / (f32)s->duration2);
        *(f32 *)(self + 0xC) = s->size1 * 1000;
        if (func_0038CB00(self + 0xA)) func_003CD250(self);
    }
}
/* localdecomp:end func_L01_00463538 */

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

/* localdecomp:start func_L01_004638C8 */
#include "vu0.h"
extern vu0_v4 D_L01_001D7EA0_004638C8 __attribute__((section(".sdata")));
__asm__(".extern D_L01_001D7EA0_004638C8, 0");
void func_L01_004638C8(u8 *self) {
    extern void func_0038CE20(void *, void *, f32);
    extern s32 func_L01_00447470_004638C8(s32, s32, f32);
    extern s32 func_0038CB00(u8 *);
    extern void func_003CD250(u8 *);
    u8 *vars = self + 0x20;
    vu0_v4 position;
    *(f32 *)(self + 0xC) = (*(s16 *)(vars + 0x18) * (*(s32 *)(vars + 0x1C) - *(s16 *)(self + 0xA)) / *(s32 *)(vars + 0x1C) + *(s16 *)(vars + 0x1A)) * 1000.0f;
    func_0038CE20(vars, vars, 0.976f);
    vec_add_ba(self + 0x10, self + 0x10, vars);
    {
        vu0_q a, b;
        __asm__("lqc2 %1, %4\n\tlqc2 %0, %5\n\tvadd.xyz %1, %1, %0\n\tsqc2 %1, %2\n\tsqc2 %1, %3"
                : "=&j"(a), "=&j"(b), "=m"(*(vu0_v4 *)(self + 0x10)), "=m"(position)
                : "m"(*(vu0_v4 *)(self + 0x10)), "m"(D_L01_001D7EA0_004638C8));
    }
    self[8]++;
    *(s32 *)(self + 4) = func_L01_00447470_004638C8(*(s32 *)(vars + 0x14), *(s32 *)(vars + 0x10), (f32)*(s16 *)(self + 0xA) / (f32)*(s32 *)(vars + 0x1C));
    if (func_0038CB00(self + 0xA)) func_003CD250(self);
}
/* localdecomp:end func_L01_004638C8 */

LINKER_REMNANT("asm/levels", func_L01_004639C0);

/* localdecomp:start func_L01_004639C8 */
extern s32 func_0038CAD0(void *);
extern void func_L01_004CAB30(void *, void *);
void func_L01_004639C8(u8 *a0) {
    u8 *s1 = a0 + 0x20;
    s32 n;

    if (func_0038CAD0(s1) != 0) {
        func_003CD250(a0);
        return;
    }
    func_L01_004CAB30(a0 + 0x10, a0 + 0x10);
    *(f32 *)(a0 + 0xC) = *(f32 *)(a0 + 0xC) + *(f32 *)(s1 + 4);
    n = *(s32 *)(a0 + 0x20);
    if (n < 5) {
        *(u32 *)(a0 + 4) = (*(u32 *)(a0 + 4) & 0xFFFFFF) | (u32)((n * 127) / 5) << 24;
    }
}
/* localdecomp:end func_L01_004639C8 */

LINKER_REMNANT("asm/levels", func_L01_00463A68);

INCLUDE_ASM("asm/levels", func_L01_00463A70);

/* localdecomp:start func_L01_00464178 */
extern s32 func_0038CAD0(void *);

void func_L01_00464178(u8 *a0) {
    u8 *p = a0 + 0x20;

    if (func_0038CAD0(p) != 0) {
        func_003CD250(a0);
        return;
    }
    *(f32 *)(a0 + 0xC) += *(f32 *)(p + 4);
    if (*(s32 *)(a0 + 0x20) < 5) {
        *(u32 *)(a0 + 4) = (*(u32 *)(a0 + 4) & 0xFFFFFF) | ((*(s32 *)(a0 + 0x20) * 127 / 5) << 24);
    }
}
/* localdecomp:end func_L01_00464178 */

/* localdecomp:start func_L01_00464210 */
typedef int Quad_00464210 __attribute__((mode(TI)));
typedef struct {
    Quad_00464210 velocity;
    s32 colour, value, life;
    f32 fade;
} Vars_00464210;
extern u8 *D_L01_002210B8[];
void func_L01_00464210(Quad_00464210 *position, Quad_00464210 *velocity, s32 colour, s32 value, s32 life, f32 fade)
{
    extern u8 *func_L01_004618E0(s32);
    u8 *p;
    Vars_00464210 *vars;
    if (life == 0) return;
    p = func_L01_004618E0(8);
    if (p != 0) {
        *(Quad_00464210 *)(p + 0x10) = *position;
        *(s32 *)(p + 4) = colour;
        p[1] = 0;
        *(s32 *)(p + 0xC) = 0;
        p[9] = 0xA4;
        p[3] = 0x48;
        p[8] = 0;
        p[2] = *D_L01_002210B8[0];
        vars = (Vars_00464210 *)(p + 0x20);
        vars->velocity = *velocity;
        *(s16 *)(p + 0xA) = life;
        vars->life = life;
        vars->fade = fade / life;
        vars->colour = colour;
        vars->value = value;
    }
}
/* localdecomp:end func_L01_00464210 */

/* localdecomp:start func_L01_004642F0 */
#include "vu0.h"
extern u8 *D_L01_002210B8[];
void func_L01_004642F0(u8 *p) {
    extern s32 func_0038CB00(u8 *);
    extern void func_003CD250(u8 *);
    extern u32 func_0038DBD8(u32, u32, f32);
    u8 *v = p + 0x20;
    u32 color;
    s32 life;
    vec_add_ab(p + 0x10, p + 0x10, v);
    if (func_0038CB00(p + 0xA)) {
        func_003CD250(p);
    } else {
        *(f32 *)(p + 0xC) += *(f32 *)(v + 0x1C);
        color = func_0038DBD8(*(u32 *)(v + 0x14), *(u32 *)(v + 0x10),
                             (f32)*(s16 *)(p + 0xA) / (f32)*(s32 *)(v + 0x18));
        *(u32 *)(p + 4) = color;
        life = *(s16 *)(p + 0xA);
        if (life < 5) {
            *(u32 *)(p + 4) = (color & 0xFFFFFF) | ((life * (s32)(color >> 24) / 5) << 24);
        }
        p[2] = D_L01_002210B8[0][(*(s32 *)(v + 0x18) - *(s16 *)(p + 0xA)) * 10 / *(s32 *)(v + 0x18)];
    }
}
/* localdecomp:end func_L01_004642F0 */

LINKER_REMNANT("asm/levels", func_L01_004643F8);

/* localdecomp:start func_L01_00464400 */
__asm__(".extern D_L01_001D7EB4, 4");
extern s32 D_L01_001D7EB4 __attribute__((section(".sdata")));
void func_L01_00464400(u8 *self) {
    extern s32 func_0038CAD0(void *);
    extern void func_003CD250(u8 *);
    extern f32 func_0038DAB8(f32, f32);
    u8 *vars = self + 0x20;
    s32 ticks, life, alpha;
    f32 angle;
    if (func_0038CAD0(vars)) {
        func_003CD250(self);
        return;
    }
    angle = func_0038DAB8(*(f32 *)(vars + 0xC), *(f32 *)(vars + 8));
    *(f32 *)(vars + 0xC) = angle;
    self[8] = (s32)(angle * 128.0f / 3.1415927f) - 128;
    ticks = D_L01_001D7EB4 * 5 + 2;
    life = ticks / 6;
    if (*(s32 *)(self + 0x20) > life * 3 / 4) {
        alpha = *(s32 *)(vars + 0x10) * (life - *(s32 *)(self + 0x20)) / (ticks / 24);
    } else if (*(s32 *)(self + 0x20) < ticks / 24) {
        alpha = *(s32 *)(vars + 0x10) * *(s32 *)(self + 0x20) / (ticks / 24);
    } else {
        alpha = *(s32 *)(vars + 0x10);
    }
    *(u32 *)(self + 4) = (alpha << 24) + (self[3] == 0x48 ? 0x4F4F4F : 0x7F7F7F);
}
/* localdecomp:end func_L01_00464400 */

LINKER_REMNANT("asm/levels", func_L01_00464550);

/* localdecomp:start func_L01_00464558 */
#include "vu0.h"
void func_L01_00464558(u8 *p)
{
    extern s32 func_0038CB00(u8 *);
    extern void func_003CD250(u8 *);
    extern void func_0038CE20(void *, void *, f32);
    u8 *s=p+0x20;
    *(f32 *)(s+0x1C) += -0.04800000041723251f;
    if (*(f32 *)(s+0x1C)<=0.0f || func_0038CB00(p+0xA)) {
        func_003CD250(p);
    } else {
        *(f32 *)(p+0xC) += 14400.0009765625f;
        if (*(f32 *)(s+0x18)<0.225f) {
            *(f32 *)(s+0x18) += 0.058080002665519714f;
        }
        *(u32 *)(p+4) = (*(u32 *)(p+4) & 0xFFFF) |
            (((s32)(*(f32 *)(s+0x18)*255.0f) & 255)<<16) |
            ((s32)(*(f32 *)(s+0x1C)*255.0f)<<24);
        vec_add_ab(p+0x10,p+0x10,p+0x20);
        func_0038CE20(s,s,0.88f);
        p[8]--;
    }
}
/* localdecomp:end func_L01_00464558 */

INCLUDE_ASM("asm/levels", func_L01_00464690);

/* localdecomp:start func_L01_00464910 */
typedef struct {
    vu0_v4 velocity;
    u32 color0, color1;
    u8 spin, flags, generation, duration;
    f32 endsize;
} Vars_00464910;
typedef struct {
    u8 type, flags, texture, render;
    u32 color;
    u8 spin, render2;
    s16 life;
    f32 size;
    vu0_v4 position;
    Vars_00464910 vars;
} Particle_00464910;
extern vu0_v4 D_L01_001E29C0;
__asm__(".extern D_L01_001DFB4C, 16");
extern f32 D_L01_001DFB4C;
void func_L01_00464910(u8 *self) {
    extern void func_0038CE20(void *, void *, f32);
    extern f32 func_003824E0(f32, f32);
    extern s32 func_00382498(s32, s32);
    extern void func_L01_00464690(void *, void *, u32, u32, s32, s32, s32, f32, s32, f32);
    extern f32 func_0038CF00(void *, void *);
    extern u32 func_0038DBD8(u32, u32, f32);
    extern void func_L01_0040E020(void *);
    extern void func_0038CF68(void *, void *, f32);
    Particle_00464910 *p = (Particle_00464910 *)self;
    Vars_00464910 *s = &p->vars;
    s32 i, second, first;
    u8 *life_pointer;
    u8 *spin_pointer;
    f32 a, b, c, age, root1, root0, discriminant, distance;
    p->spin++;
    if (((s->flags ^ 1) & 1)) {
        __asm__("lqc2 $vf1, %0\n\tlqc2 $vf2, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "+m"(p->position) : "m"(s->velocity) : "vf1", "vf2");
        if (s->flags & 4) s->velocity.z += 0.00392000004649f;
        func_0038CE20(s, s, (s->flags & 2) ? 0.6f : 0.8f);
        spin_pointer = &s->spin;
        life_pointer = (u8 *)&p->life;
        if (p->life == (s32)(s->duration * 0.85f) && s->generation < 2 && !(s->flags & 4)) {
            vu0_v4 *position = &p->position;
            for (i = 4; i >= 0; i--) {
                s32 life, spin;
                f32 scale, size;
                u8 flags;
                life = (s32)(s->duration * func_003824E0(0.9f, 1.1f));
                spin = s->spin;
                scale = func_003824E0(0.85f, 1.0f);
                size = s->endsize;
                flags = s->flags;
                func_L01_00464690(position, s, s->color0, s->color1, life, spin,
                    s->generation + 1, size, flags, s->velocity.w * scale);
            }
        }
        if (!(s->flags & 4)) {
            f32 size = s->endsize;
            f32 duration = s->duration;
            b = (duration * 8.0f - duration * 3.0f * size) / ((size * 8.0f) * size + size * 8.0f);
            a = (duration * 3.0f + b * 8.0f * size) / (size * -8.0f);
            age = duration - p->life;
            discriminant = sqrt_asm(b * b - a * 4.0f * age);
            root1 = -b + discriminant;
            root0 = -b - discriminant;
            root0 /= a + a;
            root1 /= a + a;
            if (root0 < root1) p->size = root1;
            else p->size = root0;
            distance = func_0038CF00(&p->position, &D_L01_001E29C0);
            if (distance < 10.0f) p->size *= distance * 0.075f + 0.25f;
        }
        if (s->flags & 2) {
            p->color = func_0038DBD8(s->color0, 0x0FFFFFFF, (f32)p->life / (f32)s->duration);
        } else {
            p->color = func_0038DBD8(s->color1, s->color0, (f32)p->life / (f32)s->duration);
        }
        func_L01_0040E020(spin_pointer);
        if (func_0038CB00(life_pointer)) {
            if (s->flags & 2) {
                s32 duration = s->duration * 3;
                p->life = duration;
                s->duration = duration;
                s->flags = (s->flags & ~2) | 4;
                func_0038CF68(s, s, s->velocity.w * func_003824E0(1.6f, 2.0f));
            } else {
                s32 life;
                s->color0 = s->color1;
                s->color1 = p->render == 0x48 ? 0 : 0x0F2F3F3F;
                s->flags |= 1;
                life = func_00382498(s->duration * 2, s->duration * 3);
                if (s->flags & 8) life *= 5;
                s->duration = life;
                p->life = (u8)life;
            }
        }
    } else {
        second = (s32)(s->duration * 0.75f) + 1;
        first = (s32)(s->duration * 0.25f) + 1;
        s->velocity.z += 0.0012f;
        vec_add_ab(&p->position, &p->position, &s->velocity);
        func_0038CE20(s, s, 0.9800000190734863f);
        if (second < p->life) {
            p->color = func_0038DBD8(s->color1, s->color0, (f32)(p->life - second) / (f32)first);
        } else if (p->render == 0x48) {
            p->life = 0;
        } else {
            p->color = (p->color & 0xFFFFFF) | ((p->life * 15 / second) << 24);
        }
        life_pointer = (u8 *)&p->life;
        if (D_L01_001DFB4C > 1.0f) func_0038CB00(life_pointer);
        if (func_0038CB00(life_pointer)) func_003CD250(self);
    }
}
/* localdecomp:end func_L01_00464910 */

/* localdecomp:start func_L01_00464EC8 */
typedef int Q_00464EC8 __attribute__((mode(TI)));
extern f32 D_L01_001D7EE8;
__asm__(".extern D_L01_001D7EE8, 4");
extern s32 D_L01_001D7EF0;
__asm__(".extern D_L01_001D7EF0, 4");
extern s32 D_L01_001D7EF4;
__asm__(".extern D_L01_001D7EF4, 4");
extern u32 D_L01_001D7ED8;
__asm__(".extern D_L01_001D7ED8, 4");
extern u32 D_L01_001D7EDC;
__asm__(".extern D_L01_001D7EDC, 4");
extern u32 D_L01_001D7EE0;
__asm__(".extern D_L01_001D7EE0, 4");
extern u32 D_L01_001D7EE4;
__asm__(".extern D_L01_001D7EE4, 4");
extern f32 D_L01_001D7EC8;
__asm__(".extern D_L01_001D7EC8, 4");
extern s32 D_L01_001D7ED0;
__asm__(".extern D_L01_001D7ED0, 4");
extern s32 D_L01_001D7ED4;
__asm__(".extern D_L01_001D7ED4, 4");
extern u32 D_L01_001D7EB8;
__asm__(".extern D_L01_001D7EB8, 4");
extern u32 D_L01_001D7EBC;
__asm__(".extern D_L01_001D7EBC, 4");
extern u32 D_L01_001D7EC0;
__asm__(".extern D_L01_001D7EC0, 4");
extern u32 D_L01_001D7EC4;
__asm__(".extern D_L01_001D7EC4, 4");
extern u8 *D_L01_002210F8[];
extern u8 *D_L01_002210C8[];
u8 *func_L01_00464EC8(Q_00464EC8 *pos, Q_00464EC8 *vel, u8 flags, f32 size) {
    extern u8 *func_L01_004618E8(s32, s32);
    extern f32 func_003824E0(f32, f32);
    extern u32 func_0038DBD8(u32, u32, f32);
    extern s32 func_00382468(s32);
    extern f32 func_L01_00443A18(f32, f32);
    u8 *p = func_L01_004618E8(12, 0);
    u8 *vars;
    if (p) {
        *(Q_00464EC8 *)(p + 0x10) = *pos;
        vars = p + 0x20;
        *(Q_00464EC8 *)(p + 0x20) = *vel;
        if (flags & 1) {
            f32 one = 1.0f, zero = 0.0f;
            f32 initialSize = D_L01_001D7EE8;
            f32 low = (f32)D_L01_001D7EF0;
            f32 high = (f32)D_L01_001D7EF4;
            *(u32 *)(p + 4) = D_L01_001D7ED8;
            *(f32 *)(p + 0xC) = initialSize * 210000.0f;
            *(s16 *)(p + 0xA) = (func_003824E0(low, high) * 5.0f + 2.0f) / 6.0f;
            *(u32 *)(vars + 0x14) = func_0038DBD8(D_L01_001D7ED8, D_L01_001D7EDC, func_003824E0(zero, one));
            *(u32 *)(vars + 0x18) = func_0038DBD8(D_L01_001D7EE0, D_L01_001D7EE4, func_003824E0(zero, one));
            {
                u8 texture = D_L01_002210F8[0][0];
                p[3] = 0x48;
                p[2] = texture;
            }
        } else {
            f32 zero = 0.0f, one = 1.0f;
            f32 initialSize = D_L01_001D7EC8;
            f32 low = (f32)D_L01_001D7ED0;
            f32 high = (f32)D_L01_001D7ED4;
            *(u32 *)(p + 4) = D_L01_001D7EB8;
            *(f32 *)(p + 0xC) = initialSize * 210000.0f;
            *(s16 *)(p + 0xA) = (func_003824E0(low, high) * 5.0f + 2.0f) / 6.0f;
            *(u32 *)(vars + 0x14) = func_0038DBD8(D_L01_001D7EB8, D_L01_001D7EBC, func_003824E0(zero, one));
            *(u32 *)(vars + 0x18) = func_0038DBD8(D_L01_001D7EC0, D_L01_001D7EC4, func_003824E0(zero, one));
            {
                u8 texture = D_L01_002210C8[0][func_00382468(8)];
                p[3] = 0x44;
                p[2] = texture;
            }
        }
        p[1] = 0;
        p[9] = 0x44;
        p[8] = func_00382468(255);
        vars[0x1E] = func_L01_00443A18(1.0f, 4.0f);
        *(f32 *)(vars + 0x10) = size;
        vars[0x1F] = flags;
        if (flags & 4) *(s16 *)(p + 0xA) /= 2;
        vars[0x1D] = p[0xA];
    }
    return p;
}
/* localdecomp:end func_L01_00464EC8 */

/* localdecomp:start func_L01_00465168 */
#include "vu0.h"
extern f32 D_L01_001D7EF8 __attribute__((section(".sdata")));
__asm__(".extern D_L01_001D7EF8, 4");
extern f32 D_L01_001D7EFC __attribute__((section(".sdata")));
__asm__(".extern D_L01_001D7EFC, 4");
extern f32 D_L01_001D7EEC __attribute__((section(".sdata")));
__asm__(".extern D_L01_001D7EEC, 4");
extern f32 D_L01_001D7EE8 __attribute__((section(".sdata")));
__asm__(".extern D_L01_001D7EE8, 4");
extern f32 D_L01_001D7ECC __attribute__((section(".sdata")));
__asm__(".extern D_L01_001D7ECC, 4");
extern f32 D_L01_001D7EC8 __attribute__((section(".sdata")));
__asm__(".extern D_L01_001D7EC8, 4");
void func_L01_00465168(u8 *self) {
    extern f32 func_0038CEA8(void *);
    extern void func_003C41A0(void *, f32 *, f32, f32, f32, f32);
    extern void func_0038CF68(f32 *, f32 *, f32);
    extern u32 func_0038DBD8(u32, u32, f32);
    extern s32 func_0038CB00(u8 *);
    extern void func_003CD250(u8 *);
    u8 *vars = self + 0x20;
    f32 drag;
    register f32 ratio;
    self[8] += vars[0x1E];
    vec_add_ab(self + 0x10, self + 0x10, vars);
    drag = -func_0038CEA8(vars);
    func_003C41A0(self + 0x30, &drag, 0.0f, 0.0f, D_L01_001D7EF8 * 0.0004000000189989805f, drag);
    func_0038CF68((f32 *)vars, (f32 *)vars, -drag);
    *(f32 *)(self + 0x18) += D_L01_001D7EFC * 0.020000001415610313f;
    ratio = (f32)*(s16 *)(self + 0xA) / (f32)vars[0x1D];
    if (vars[0x1F] & 1) {
        f32 start = D_L01_001D7EEC;
        f32 end = D_L01_001D7EE8;
        *(f32 *)(self + 0xC) = ((end - start) * ratio + start) * 210000.0f;
    } else {
        f32 start = D_L01_001D7ECC;
        f32 end = D_L01_001D7EC8;
        *(f32 *)(self + 0xC) = ((end - start) * ratio + start) * 210000.0f;
    }
    *(u32 *)(self + 4) = func_0038DBD8(*(u32 *)(vars + 0x18), *(u32 *)(vars + 0x14), ratio);
    if (*(s16 *)(self + 0xA) < 12) {
        *(u32 *)(self + 4) = func_0038DBD8(*(u32 *)(self + 4) & 0xFFFFFF, *(u32 *)(self + 4), *(s16 *)(self + 0xA) * 0.125f);
    }
    if (*(f32 *)(self + 0x10) < 2.0f || *(f32 *)(self + 0x10) > 1021.0f ||
        *(f32 *)(self + 0x14) < 2.0f || *(f32 *)(self + 0x14) > 1021.0f ||
        *(f32 *)(self + 0x18) < 2.0f || *(f32 *)(self + 0x18) > 1021.0f || func_0038CB00(self + 0xA)) {
        func_003CD250(self);
    } else if (*(f32 *)(vars + 0x10) < 0.009999999776482582f) {
        (*(s16 *)(self + 0xA))--;
    }
}
/* localdecomp:end func_L01_00465168 */

/* localdecomp:start func_L01_004653B8 */
typedef int Q_004653B8 __attribute__((mode(TI)));
extern u8 *D_L01_002210CC[];
u8 *func_L01_004653B8(Q_004653B8 *pos, s32 spin, s32 color, f32 jitter, f32 low, f32 high, f32 rate, f32 size) {
    extern u8 *func_L01_004618E0(s32);
    extern f32 func_L01_00443A18(f32, f32);
    extern s32 func_00382468(s32);
    extern f32 func_003824E0(f32, f32);
    u8 *p = func_L01_004618E0(13);
    if (p != 0) {
        u8 *vars;
        *(Q_004653B8 *)(p + 0x10) = *pos;
        p[9] = 0x44;
        p[3] = 0x48;
        *(f32 *)(p + 0xC) = size;
        *(s32 *)(p + 4) = color;
        p[1] = 0;
        p[8] = 0;
        p[2] = *D_L01_002210CC[0];
        vars = p + 0x20;
        *(f32 *)(p + 0x10) += func_L01_00443A18(0.0f, jitter);
        *(f32 *)(p + 0x14) += func_L01_00443A18(0.0f, jitter);
        *(f32 *)(p + 0x18) += func_L01_00443A18(0.0f, jitter);
        *(s16 *)(p + 0xA) = 8;
        *(s32 *)(vars + 4) = 0;
        if (func_00382468(2)) *(s32 *)(vars + 8) = spin;
        else *(s32 *)(vars + 8) = -spin;
        *(s32 *)(vars + 0x14) = color & 0xFFFFFF;
        *(f32 *)(vars + 0xC) = func_003824E0(low, high);
        *(f32 *)(vars + 0x10) = rate;
    }
    return p;
}
/* localdecomp:end func_L01_004653B8 */

/* localdecomp:start func_L01_00465520 */
void func_L01_00465520(u8 *p) {
    extern s32 func_0038CB00(u8 *);
    extern void func_003CD250(u8 *);
    u8 *v = p + 0x20;
    p[8] += v[8];
    *(f32 *)(p + 0x18) += *(f32 *)(v + 0x10);
    *(f32 *)(p + 0xC) *= *(f32 *)(v + 0xC);
    if (*(s32 *)(v + 4) == 0) {
        if (func_0038CB00(p + 0xA)) {
            *(s32 *)(v + 4) = 1;
            *(s16 *)(p + 0xA) = 25;
            *(u32 *)(p + 4) = *(u32 *)(v + 0x14) | 0x7F000000;
        } else {
            *(u32 *)(p + 4) = (((s32)((8 - *(s16 *)(p + 0xA)) * 12.0f) + 32) << 24) | *(u32 *)(v + 0x14);
        }
    } else {
        if (func_0038CB00(p + 0xA)) {
            func_003CD250(p);
            return;
        }
        *(u32 *)(p + 4) = ((s32)(*(s16 *)(p + 0xA) * 5.08f) << 24) | *(u32 *)(v + 0x14);
    }
}
/* localdecomp:end func_L01_00465520 */

LINKER_REMNANT("asm/levels", func_L01_00465648);

/* localdecomp:start func_L01_00465650 */
#include "vu0.h"
extern vu0_v4 D_L01_001E29C0;
void func_L01_00465650(u8 *self) {
    extern s32 func_0038CB00(u8 *);
    extern void func_003CD250(u8 *);
    extern void func_0038CF68(void *, void *, f32);
    u8 *state = self + 0x20;
    vu0_v4 delta;
    self[8] += state[0];
    if (*(s32 *)(state + 4) == 0) {
        *(vu0_q *)(self + 0x10) = *(vu0_q *)(*(u8 **)(state + 8) + 0x10);
        vec_sub_ba(&delta, &D_L01_001E29C0, self + 0x10);
        func_0038CF68(&delta, &delta, 0.01f);
        vec_add_ab(self + 0x10, self + 0x10, &delta);
    } else if (func_0038CB00(self + 0xA)) {
        func_003CD250(self);
    } else {
        *(s32 *)(self + 4) = ((s32)(*(s16 *)(self + 0xA) * 25.4f) << 24) | 0xFFFFFF;
    }
}
/* localdecomp:end func_L01_00465650 */

INCLUDE_ASM("asm/levels", func_L01_00465738);

/* localdecomp:start func_L01_00465878 */
extern s32 D_L01_001D673C;
extern u32 D_L01_001DFB40;
typedef struct {
    vu0_v4 velocity;
    s32 color_start, color_end;
    s16 duration, emit;
    f32 gravity;
} Vars_00465878;
void func_L01_00465878(u8 *self) {
    extern s32 func_0038CB00(u8 *);
    extern void func_003CD250(u8 *);
    extern s32 func_L01_00447470_00465878(s32, s32, f32);
    extern void func_003C5180(void *, void *, s32);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_L01_004CAB30(void *, void *);
    extern f32 func_003824E0(f32, f32);
    extern f32 func_0038CEA8(void *);
    extern void func_0038CF68(void *, void *, f32);
    extern s32 func_00382498(s32,s32);
    extern void func_L01_00465738(void *,void *,s32,s32,s32,s32,s32,s32,s32,f32);
    Vars_00465878 *s = (Vars_00465878 *)(self+0x20);
    vu0_v4 *pos;
    struct { vu0_v4 copy,gravity,jitter,random; } v;
    f32 length;
    if (func_0038CB00(self+0xA)) {
        func_003CD250(self);
        return;
    }
    pos=(vu0_v4 *)(self+0x10);
    *(f32 *)(self+0xC)=(f32)*(s16 *)(self+0xA)*s->gravity/(f32)s->duration;
    *(s32 *)(self+4)=func_L01_00447470_00465878(s->color_end,s->color_start,(f32)*(s16 *)(self+0xA)/(f32)s->duration);
    vec_add_ab(pos,pos,&s->velocity);
    if (D_L01_001D673C) {
        func_003C5180(pos,&v.gravity,0);
        func_0038CE20(&v.gravity,&v.gravity,s->velocity.w);
        vec_add_ab(&s->velocity,&s->velocity,&v.gravity);
    } else {
        s->velocity.z -= s->velocity.w;
    }
    v.copy=*(vu0_v4 *)(self+0x10);
    if (*(f32 *)(self+0x1C) != 0.0f) {
        if (*(f32 *)(self+0x1C) == 2.0f) func_L01_004CAB30(pos,pos);
        *(f32 *)(self+0x1C)=2.0f;
    }
    if (s->emit && (D_L01_001DFB40 & 1)) {
        *(vu0_q *)&v.random=0;
        v.random.x=func_003824E0(-1.0f,1.0f);
        v.random.y=func_003824E0(-1.0f,1.0f);
        v.random.z=func_003824E0(-1.0f,1.0f);
        v.jitter=v.random;
        length=func_0038CEA8(s);
        func_0038CF68(&v.jitter,&v.jitter,length*func_003824E0(0.15f,0.25f));
        vec_add_ab(&v.jitter,&v.jitter,&s->velocity);
        func_0038CE20(&v.jitter,&v.jitter,func_003824E0(0.75f,0.95f));
        func_L01_00465738(pos,&v.jitter,*(s32 *)(self+4),s->color_end,(func_00382498(15,30)*5+2)/6,0,self[2],self[3],(s32)*(f32 *)(self+0x1C),*(f32 *)(self+0xC));
    } else {
        func_0038CE20(s,s,0.96f);
    }
}
/* localdecomp:end func_L01_00465878 */

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

/* localdecomp:start func_L01_004660F8 */
#include "vu0.h"
extern u8 *D_L01_002210E4[];
u8 *func_L01_004660F8(vu0_q *pos, vu0_q *end) {
    extern u8 *func_L01_004618E0(s32);
    extern s32 func_00382468(s32);
    u8 *p = func_L01_004618E0(19);
    if (p != 0) {
        u32 color = ((func_00382468(6) * 6) + 64) | 0x78404000;
        p[9] = 0x22;
        p[3] = 0x48;
        p[1] = 3;
        *(u32 *)(p + 4) = color;
        *(u32 *)(p + 12) = color;
        p[2] = *D_L01_002210E4[0];
        *(vu0_q *)(p + 16) = *pos;
        *(vu0_q *)(p + 48) = *end;
        vec_sub_ba(p + 32, pos, p + 48);
        vec_sub_ab(p + 32, p + 32, p + 48);
        *(f32 *)(p + 60) = 6.0f;
        *(f32 *)(p + 28) = 0.09f;
        *(f32 *)(p + 44) = 0.5f;
    }
    return p;
}
/* localdecomp:end func_L01_004660F8 */

/* localdecomp:start func_L01_004661F0 */
extern void func_L01_004CAB30(void *, void *);
extern void func_003CD250(u8 *);

void func_L01_004661F0(u8 *self) {
    u8 *pos = self + 0x10;
    u8 *rot = self + 0x20;
    u8 *vel = self + 0x30;
    s32 v;

    vec_add_ba(pos, pos, vel);
    vec_add_ba(rot, rot, vel);
    func_L01_004CAB30(pos, pos);
    func_L01_004CAB30(rot, rot);
    v = *(s32 *)(self + 4) - ((s32)*(f32 *)(vel + 0xC) << 24);
    *(s32 *)(self + 4) = v;
    *(s32 *)(self + 0xC) = v;
    if (v < 0) {
        func_003CD250(self);
    }
}
/* localdecomp:end func_L01_004661F0 */

/* localdecomp:start func_L01_00466290 */
#include "vu0.h"
void func_L01_00466290(u8 *self)
{
    extern f32 func_0038D0B0(f32);
    extern f32 func_0038D098(f32);
    extern void func_0038D028(void *, void *, void *);
    extern void func_003C2F58(void *, s32, void *);
    extern void func_0038CF68(void *, void *, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_L01_00448EC0(void *, void *, void *, s32);
    extern s32 func_0038CB00(u8 *);
    extern void func_003CD250(u8 *);
    vu0_v4 target, local, delta;
    vu0_q matrix[4];
    u8 *state = self + 0x20;
    f32 f;
    if (*(f32 *)(state + 0x10) != 0.0f) {
        u8 *source = *(u8 **)state;
        u8 *position = self + 0x10;
        matrix[0] = *(vu0_q *)source;
        matrix[1] = *(vu0_q *)(source + 0x10);
        matrix[2] = *(vu0_q *)(source + 0x20);
        local.y = func_0038D0B0(*(f32 *)(state + 0x14)) * *(f32 *)(state + 0x10);
        local.z = func_0038D098(*(f32 *)(state + 0x14)) * *(f32 *)(state + 0x10);
        local.x = 0.0f;
        local.w = 0.0f;
        func_0038D028(&delta, &local, matrix);
        vec_sub_ba(position, position, &delta);
        *(f32 *)(state + 0x1C) += 0.07201200723648071f;
        func_003C2F58(*(void **)(state + 0x18), 0, &target);
        vec_sub_ab(&local, &target, position);
        func_0038CF68(&local, &local, *(f32 *)(state + 0x1C));
        vec_add_ba(position, position, &local);
        *(f32 *)(state + 0x14) = func_0038DAB8(*(f32 *)(state + 0x14), 0.6283185482025146f);
        *(f32 *)(state + 0x10) *= 0.88f;
        local.y = func_0038D0B0(*(f32 *)(state + 0x14)) * *(f32 *)(state + 0x10);
        local.z = func_0038D098(*(f32 *)(state + 0x14)) * *(f32 *)(state + 0x10);
        local.x = 0.0f;
        local.w = 0.0f;
        func_0038D028(&delta, &local, matrix);
        vec_add_ab(position, position, &delta);
        if (func_L01_00448EC0(&target, *(u8 **)(state + 0x18) + 0xC0, position, 1) > 0.0f) {
            func_003CD250(self);
            return;
        }
    }
    *(f32 *)(state + 4) += *(f32 *)(state + 0xC) * 0.013200000859797f;
    if (*(f32 *)(state + 4) <= 0.0f || func_0038CB00(self + 0xA)) {
        func_003CD250(self);
    } else {
        f = *(f32 *)(state + 4);
        if (f >= 1.0f) {
            f32 step = -*(f32 *)(state + 0xC);
            *(f32 *)(state + 0xC) = step;
            *(f32 *)(state + 4) = f + step * 0.013200000859797f;
        }
        *(f32 *)(self + 0xC) += -3528.000244140625f;
        *(u32 *)(self + 4) = (*(u32 *)(self + 4) & 0xFFFFFF) | ((s32)(*(f32 *)(state + 4) * 255.0f) << 24);
        *(f32 *)(state + 8) += 0.007200000341981649f;
        if (*(f32 *)(state + 8) > 1.0f) *(f32 *)(state + 8) -= 1.0f;
        self[8] = (s32)(*(f32 *)(state + 8) * 255.0f);
    }
}
/* localdecomp:end func_L01_00466290 */

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

/* localdecomp:start func_L01_00466678 */
#include "vu0.h"
extern u32 D_L01_001DFB40;
void func_L01_00466678(u8 *p) {
    extern s32 func_0038CB00(u8 *);
    extern void func_003CD250(u8 *);
    extern s32 func_L01_00447470_00466678(s32, s32, f32);
    extern f32 func_003824E0(f32 low, f32 high);
    extern f32 func_0038CEA8(void *);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038CE20(void *, void *, f32);
    extern s32 func_00382498(s32, s32);
    extern Part_00462FD0 *func_L01_00466588(s128_00462FD0 *, s128_00462FD0 *, s32, s32, s32, s32, f32);
    vu0_v4 old;
    vu0_v4 velocity;
    vu0_v4 random;
    u8 *v = p + 0x20;
    f32 ratio;
    if (func_0038CB00(p + 0xA)) {
        func_003CD250(p);
        return;
    }
    ratio = 1.0f / *(s16 *)(v + 0x18);
    *(f32 *)(p + 0xC) = *(s16 *)(p + 0xA) * *(f32 *)(v + 0x1C) * ratio;
    *(s32 *)(p + 4) = func_L01_00447470_00466678(*(s32 *)(v + 0x14), *(s32 *)(v + 0x10), *(s16 *)(p + 0xA) * ratio);
    vec_add_ab(p + 0x10, p + 0x10, v);
    *(f32 *)(v + 8) -= 0.001440000138245523f;
    old = *(vu0_v4 *)(p + 0x10);
    if (*(s16 *)(v + 0x1A) && (D_L01_001DFB40 & 1)) {
        f32 speed;
        *(vu0_q *)&random = 0;
        random.x = func_003824E0(-1.0f, 1.0f);
        random.y = func_003824E0(-1.0f, 1.0f);
        random.z = func_003824E0(-1.0f, 1.0f);
        velocity = random;
        speed = func_0038CEA8(v);
        func_0038CF68(&velocity, &velocity, speed * func_003824E0(0.21f, 0.25f));
        vec_add_ab(&velocity, &velocity, v);
        func_0038CE20(&velocity, &velocity, func_003824E0(0.75f, 0.95f));
        func_L01_00466588((s128_00462FD0 *)(p + 0x10), (s128_00462FD0 *)&velocity, *(s32 *)(p + 4), *(s32 *)(v + 0x14), (func_00382498(15,20) * 5 + 2) / 6, 0, *(f32 *)(p + 0xC));
    } else {
        func_0038CE20(v, v, 0.96f);
    }
}
/* localdecomp:end func_L01_00466678 */

/* localdecomp:start func_L01_004668A0 */
typedef int Q_004668A0 __attribute__((mode(TI)));
typedef struct { Q_004668A0 vel; s32 color, value; s16 life, pad; f32 delta; } Vars_004668A0;
extern u8 *D_L01_002210F0[];
void func_L01_004668A0(Q_004668A0 *pos, Q_004668A0 *vel, s32 color, s32 value, s32 life, f32 size) {
    extern u8 *func_L01_004618E0(s32);
    extern u8 func_0013D3E0(void);
    u8 *p = func_L01_004618E0(0x16);
    Vars_004668A0 *v;
    if (p != 0) {
        *(s32 *)(p + 4) = color;
        p[1] = 0;
        p[9] = 0x74;
        p[3] = 0x44;
        *(f32 *)(p + 0xC) = size * 0.2f;
        p[8] = func_0013D3E0();
        p[2] = *D_L01_002210F0[0];
        v = (Vars_004668A0 *)(p + 0x20);
        *(s16 *)(p + 0xA) = life;
        v->life = life;
        v->delta = (size - *(f32 *)(p + 0xC)) / life;
        v->color = color;
        v->value = value;
        *(Q_004668A0 *)(p + 0x20) = *vel;
        *(Q_004668A0 *)(p + 0x10) = *pos;
        ((f32 *)&v->vel)[3] = 0.0004960000514984131f;
    }
}
/* localdecomp:end func_L01_004668A0 */

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

/* localdecomp:start func_L01_00466B78 */
#include "vu0.h"
void func_L01_00466B78(u8 *self) {
 extern void func_L01_004CAB30(void *,void *);
 extern s32 func_0038CB00(u8 *);
 extern void func_003CD250(u8 *);
 u8 *s=self+0x20;
 f32 blend;
 s32 elapsed;
 self[8]+=s[8];
 vec_add_ab(self+0x10,self+0x10,self+0x30);
 if(*(f32 *)(self+0x1c)!=0.0f) {
  if(*(f32 *)(self+0x1c)==2.0f) func_L01_004CAB30(self+0x10,self+0x10);
  *(f32 *)(self+0x1c)=2.0f;
 }
 *(f32 *)(self+0xc)*=(*(f32 *)(s+0xc)-1.0f)*1.2f+1.0f;
 if(*(s32 *)(s+4)==0) {
  if(func_0038CB00(self+0xa)) {
   *(s32 *)(s+4)=1;
   *(s16 *)(self+0xa)=17;
   *(s32 *)(self+4)=*(s32 *)s|0x7f000000;
  } else {
   *(s32 *)(self+4)=(((s32)((8-*(s16 *)(self+0xa))*12.0f)+32)<<24)|*(s32 *)s;
  }
 } else if(*(s32 *)(s+4)==2) {
  if(func_0038CB00(self+0xa)) {
   func_003CD250(self);
  } else {
   *(s32 *)(self+4)=((s32)(s[10]*((f32)*(s16 *)(self+0xa)/s[11])+0.0f)<<24)|(*(s32 *)s&0xffffff);
  }
 } else if(*(s32 *)(s+4)==3) {
  func_0038CB00(self+0xa);
  elapsed=s[11]-*(s16 *)(self+0xa);
  blend=(f32)elapsed / *(f32 *)(s+0x1c);
  if(blend>1.0f) blend=1.0f;
  *(s32 *)(self+4)=((s32)(s[10]*blend+0.0f)<<24)|(*(s32 *)s&0xffffff);
  if(s[11]-*(s16 *)(self+0xa)>=(s32)*(f32 *)(s+0x1c)) {
   s[11]-=(s32)*(f32 *)(s+0x1c);
   *(s32 *)(s+4)=2;
  }
 } else {
  if(func_0038CB00(self+0xa)) {
   func_003CD250(self);
  } else {
   *(s32 *)(self+4)=((s32)(*(s16 *)(self+0xa)*7.470588207244873f)<<24)|*(s32 *)s;
  }
 }
}
/* localdecomp:end func_L01_00466B78 */

LINKER_REMNANT("asm/levels", func_L01_00466E38);

/* localdecomp:start func_L01_00466E40 */
typedef int Q_00466E40 __attribute__((mode(TI)));
void func_L01_00466E40(u8 *self) {
    extern void func_003CD250(u8 *);
    u8 *source;
    f32 *p;
    if (self != 0) {
        source = *(u8 **)(self + 0x20);
        p = (f32 *)(self + 0x20);
        if (source == 0 || (source[1] & 0x80)) {
            func_003CD250(self);
        } else {
            *(Q_00466E40 *)(self + 0x10) = *(Q_00466E40 *)(source + 0x10);
            self[8] = source[8];
            *(f32 *)(self + 0xC) = *(f32 *)(source + 0xC) * p[1] + p[2];
            p[3] += p[5];
            if (p[3] < 0.0f) {
                p[3] = 0.0f;
            } else {
                if (p[3] > 1.0f) p[3] = 1.0f;
                *(u32 *)(self + 4) = (*(u32 *)(self + 4) & 0xFFFFFF) |
                    ((s32)(((*(u8 **)(self + 0x20))[7] * (p[4] * 0.00390625f) + p[3]) * 256.0f) << 24);
            }
        }
    }
}
/* localdecomp:end func_L01_00466E40 */

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

/* localdecomp:start func_L01_004674D8 */
#include "vu0.h"
extern vu0_v4 D_L01_001E29C0;
void func_L01_004674D8(u8 *p) {
    extern s32 func_0038CB00(u8 *);
    extern void func_003CD250(u8 *);
    extern s32 func_00382498(s32, s32);
    extern void func_003C2F58(void *, s32, void *);
    extern void func_0038CF68(void *, void *, f32);
    u8 *v;
    vu0_v4 pos, delta;
    if (p) {
        v = p+0x20;
        if (func_0038CB00(p+0x24) || !*(u8 **)(p+0x20) || *(s8 *)(*(u8 **)(p+0x20)+0x20)<0) {
            func_003CD250(p);
            return;
        }
        if (*(s16 *)(v+4) < *(s32 *)(v+8)/5) {
            *(u32 *)(p+4) = (*(u32 *)(p+4)&0xFFFFFF) + ((*(s32 *)(v+12) * *(s16 *)(v+4) / (*(s32 *)(v+8)/3)) << 24);
        }
        p[8] = func_00382498(0,255);
        if (*(s16 *)(v+6) == -1) {
            *(vu0_q *)(p+0x10) = *(vu0_q *)(*(u8 **)(p+0x20)+0x10);
        } else {
            func_003C2F58(*(u8 **)(p+0x20),*(s16 *)(v+6),&pos);
            vec_sub_ba(&delta,&D_L01_001E29C0,&pos);
            func_0038CF68(&delta,&delta,0.4f);
            vec_add_ab(p+0x10,&pos,&delta);
        }
    }
}
/* localdecomp:end func_L01_004674D8 */

/* localdecomp:start func_L01_00467608 */
extern s32 func_0038CAD0(void *);
extern void func_003CD250(u8 *);

void func_L01_00467608(u8 *a0) {
    u8 *q = a0 + 0x20;
    s32 n;
    vec_add_ab(a0 + 0x10, a0 + 0x10, q);
    n = *(s32 *)(q + 0x18) * *(s32 *)(q + 0x10) / *(s32 *)(q + 0x14);
    *(u32 *)(a0 + 4) = (*(u32 *)(a0 + 4) & 0xFFFFFF) + (n << 24);
    if (func_0038CAD0(a0 + 0x30) != 0) {
        func_003CD250(a0);
    }
}
/* localdecomp:end func_L01_00467608 */

/* localdecomp:start func_L01_00467688 */
#include "vu0.h"
extern u8 *D_L01_00221108[];
void func_L01_00467688(void *position, void *orientation, f32 spread) {
    extern u8 *func_L01_004618E0(s32);
    extern f32 func_003824E0(f32, f32);
    extern u8 func_0013D3E0(void);
    extern void func_0038D570(void *, void *);
    extern void func_0038D028(void *, void *, void *);
    extern void func_0038D000(void *, void *, void *);
    vu0_v4 transformed, delta, velocity;
    vu0_v4 matrix[4];
    u8 *particle = func_L01_004618E0(0x1C);
    u8 *state;
    s32 r, g, b;
    if (particle) {
        f32 low = -0.03f;
        state = particle + 0x20;
        delta.x = func_003824E0(low, 0.03f);
        delta.y = func_003824E0(low, 0.03f);
        delta.z = 0;
        if (orientation) {
            func_0038D570(matrix, orientation);
            func_0038D028(&transformed, &delta, matrix);
            vec_add_ba(particle + 0x10, &transformed, position);
        } else {
            vec_add_ba(particle + 0x10, &delta, position);
        }
        *(f32 *)(particle + 0x18) -= 0.05f;
        /* The divisor sign does not change the remainder. */
        r = (s32)func_0013D3E0() % -96;
        if (!r) r = 1;
        g = ((s32)func_0013D3E0() % r) % 64;
        if (!g) g = 1;
        b = ((s32)func_0013D3E0() % g) % 48;
        *(s32 *)(particle + 4) = (r + 143) | ((g + 143) << 8) | ((b + 111) << 16);
        particle[9] = 0x44;
        particle[3] = 0x48;
        particle[1] = 0;
        particle[8] = 0;
        particle[2] = *D_L01_00221108[0];
        *(f32 *)(state + 4) = func_003824E0(0.0f, 0.0223456006f) + 0.00001f;
        *(f32 *)(particle + 0xC) = func_003824E0(10080.0f, 19950.0f);
        *(f32 *)(state + 8) = 0;
        *(s16 *)(particle + 0xA) = 210;
        *(f32 *)(state + 0xC) = 1.0f;
        qzero(&velocity);
        if (orientation) {
            velocity.x = spread;
            velocity.z = -0.0025f;
            func_0038D000(state + 0x10, &velocity, orientation);
        } else {
            *(f32 *)(state + 0x10) = func_003824E0(-spread, spread);
            *(f32 *)(state + 0x14) = func_003824E0(-spread, spread);
            *(f32 *)(state + 0x18) = -0.0025f;
        }
    }
}
/* localdecomp:end func_L01_00467688 */

/* localdecomp:start func_L01_00467910 */
#include "vu0.h"
void func_L01_00467910(u8 *self) {
    extern s32 func_0038CB00(u8 *);
    extern void func_003CD250(u8 *);
    f32 *p = (f32 *)(self + 0x20);
    if (p[3] > 0.0f) {
        p[1] += p[3] * 0.008400000631809235f;
    } else if (p[1] > 0.03f) {
        p[1] += p[3] * 0.008400000631809235f;
    } else {
        p[1] += p[3] * 0.008400000631809235f * 0.2f;
        *(f32 *)(self + 0xC) += 6552.00048828125f;
    }
    if (p[1] <= 0.024399999529123306f || func_0038CB00(self + 0xA)) {
        func_003CD250(self);
    } else {
        if (p[1] >= 0.12f) {
            p[3] = -p[3];
            p[1] += p[3] * 0.008400000631809235f;
        }
        *(f32 *)(self + 0xC) += 6552.00048828125f;
        *(u32 *)(self + 4) = (*(u32 *)(self + 4) & 0xFFFFFFu) | ((s32)(p[1] * 255.0f) << 24);
        p[2] += 0.002400000113993883f;
        if (p[2] > 1.0f) p[2] -= 1.0f;
        self[8] = (s32)(p[2] * 255.0f);
        vec_add_ba(self + 0x10, self + 0x10, p + 4);
    }
}
/* localdecomp:end func_L01_00467910 */

INCLUDE_ASM("asm/levels", func_L01_00467B20);

LINKER_REMNANT("asm/levels", func_L01_00467DC0);

/* localdecomp:start func_L01_00467DC8 */
#include "vu0.h"
typedef struct {
    vu0_v4 velocity;
    u8 *anchor, *next;
    s16 a18, a1A, collision, flags;
} Chain_00467DC8;
extern vu0_v4 D_L01_001E29C0;
extern vu0_v4 D_L01_001EAA30, D_L01_001EAA40;
void func_L01_00467DC8(u8 *self) {
    extern void func_0038CF68(void *,void *,f32);
    extern void func_0038CE20(void *,void *,f32);
    extern f32 func_0038CEA8(void *);
    extern s32 func_L01_003FB640(void *,s32,s32,f32);
    extern void func_L01_0040E790(void *,void *,void *);
    extern void func_003CD250(u8 *);
    extern void func_0038D028(void *,void *,void *);
    extern f32 func_0038D160(f32,f32);
    vu0_v4 position, delta, sum;
    Chain_00467DC8 *state = (Chain_00467DC8 *)(self + 0x20);
    Chain_00467DC8 *prior;
    u8 *p;
    f32 distance, damping, gain, angle;
    s32 alpha;
    if (state->flags != 255) {
        if (((*(u8 *)&state->flags ^ 1) & 1)) {
            prior = 0;
            p = state->next;
            qzero(&sum);
            distance = 2.0f;
            damping = 0.15f;
            if (p) prior = (Chain_00467DC8 *)(p + 0x20);
            if (!state->collision) {
                while (p && !(*(unsigned long *)((u8 *)prior + 0x18) & 0x1FFFF00000000UL)) {
                    vec_sub_ab(&position,p + 0x10,self + 0x10);
                    func_0038CF68(&position,&position,0.2f / (distance * distance));
                    distance += 1.0f;
                    damping *= 0.9990000128746033f;
                    vec_add_ab(&sum,&sum,&position);
                    p = prior->next;
                    if (p) prior = (Chain_00467DC8 *)(p + 0x20);
                }
            }
            damping = (0.15f - damping) + 1.0700000524520874f;
            if (!prior || !prior->collision) vec_add_ab(state,state,&sum);
            else func_0038CE20(state,state,0.5f);
            if (state->next) func_0038CE20(state,state,damping);
            else func_0038CE20(state,state,0.9700000286102295f);
            state->velocity.z -= 0.028800001367926598f;
            vec_add_ab(&position,self + 0x10,state);
        } else {
            *(vu0_q *)&position = *(vu0_q *)(self + 0x10);
        }
        if (state->anchor) {
            vec_sub_ba(&sum,&position,state->anchor + 0x10);
            if (fabs_asm(func_0038CEA8(&sum) - 0.15f) > 0.1f) {
                func_0038CF68(&sum,&sum,0.15f);
                vec_add_ab(&position,&sum,state->anchor + 0x10);
            }
            if (func_L01_003FB640(&position,0,0,0.15f)) {
                if (!state->collision) *(vu0_q *)&position = *(vu0_q *)&D_L01_001EAA30;
                else *(vu0_q *)&position = *(vu0_q *)(self + 0x10);
                state->collision = 1;
            } else state->collision = 0;
            if (state->collision) {
                func_L01_0040E790(state,state,&D_L01_001EAA40);
                func_0038CE20(state,state,0.95f);
            } else {
                vec_sub_ba(&delta,&position,self + 0x10);
                vec_add_ab(state,state,&delta);
                func_0038CE20(state,state,0.5f);
            }
            vec_sub_ba(&delta,&position,self + 0x10);
            vec_add_ab(state,state,&delta);
            func_0038CE20(state,state,0.5f);
        }
        *(vu0_q *)(self + 0x10) = *(vu0_q *)&position;
        if (state->flags & 2) {
            alpha = (*(u32 *)(self + 4) >> 24) - 2;
            if (alpha > 0) *(u32 *)(self + 4) = (*(u32 *)(self + 4) & 0xFFFFFF) | (alpha << 24);
            else if (!state->next) {
                if (state->anchor) *(s32 *)(state->anchor + 0x34) = 0;
                func_003CD250(self);
                return;
            }
        }
    }
    if (state->anchor) {
        vec_sub_ab(&position,state->anchor + 0x10,&D_L01_001E29C0);
        func_0038D028(&position,&position,(u8 *)&D_L01_001E29C0 - 0x80);
        func_0038CE20(&position,&position,1.0f / position.w);
        vec_sub_ba(&delta,self + 0x10,&D_L01_001E29C0);
        func_0038D028(&delta,&delta,(u8 *)&D_L01_001E29C0 - 0x80);
        func_0038CE20(&delta,&delta,1.0f / delta.w);
        vec_sub_ab(&position,&position,&delta);
        angle = func_0038D160(position.x,position.y);
        self[8] = (s32)(angle * 128.0f / 3.1415927410125732f) - 32;
    }
}
/* localdecomp:end func_L01_00467DC8 */

LINKER_REMNANT("asm/levels", func_L01_004682B0);

/* localdecomp:start func_L01_004682B8 */
#include "vu0.h"
__asm__(".extern D_L01_001D7F14, 4");
__asm__(".extern D_L01_001D7F18, 4");
extern f32 D_L01_001D7F14 __attribute__((section(".sdata")));
extern f32 D_L01_001D7F18 __attribute__((section(".sdata")));
void func_L01_004682B8(u8 *self) {
    extern s32 func_0038CB00(u8 *);
    extern void func_003CD250(u8 *);
    extern void func_0038CE20(void *, void *, f32);
    extern f32 func_0038CF00(void *, void *);
    vu0_v4 v[2], temp;
    u8 *pos, *old;
    if (!*(u8 **)(self+0x30) || (*(u8 **)(self+0x30))[0x20] == 254 || (*(u8 **)(self+0x30))[0x20] == 253 || func_0038CB00(self+0xA)) {
        func_003CD250(self);
        return;
    }
    vec_sub_ba(&temp, *(u8 **)(self+0x30)+0x10, self+0x10);
    pos=self+0x10;
    old=self+0x20;
    v[0]=v[1]=temp;
    func_0038CE20(v,v,(D_L01_001D7F14-1.0f)*1.2f+1.0f);
    vec_add_ab(&temp,v,*(u8 **)(self+0x30)+0x10);
    *(vu0_v4 *)(self+0x10)=v[1]=temp;
    vec_sub_ba(&temp,*(u8 **)(self+0x30)+0x10,self+0x20);
    v[0]=v[1]=temp;
    func_0038CE20(v,v,(D_L01_001D7F18-1.0f)*1.2f+1.0f);
    vec_add_ab(&temp,v,*(u8 **)(self+0x30)+0x10);
    *(vu0_v4 *)(self+0x20)=v[1]=temp;
    if (func_0038CF00(pos,old)<0.1f || func_0038CF00(pos,*(u8 **)(self+0x30)+0x10)<1.0f) func_003CD250(self);
}
/* localdecomp:end func_L01_004682B8 */

LINKER_REMNANT("asm/levels", func_L01_00468460);

/* localdecomp:start func_L01_00468468 */
typedef int Q_00468468 __attribute__((mode(TI)));

void func_L01_00468468(void *arg0) {
    extern void func_003CD250(u8 *);
    extern u32 func_L01_00448CC0(f32 r, f32 g, f32 b, f32 a);
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f0_5;
    f32 temp_f1;
    f32 temp_f3;
    void *temp_16;
    void *temp_4;

    if (arg0 != 0) {
        temp_4 = (*(void **)((u8 *)(arg0) + (0x20)));
        temp_16 = arg0 + 0x20;
        if ((temp_4 == 0) || (((*(u8 *)((u8 *)(temp_4) + (0x20))) & 0xF0) == 0xF0) || ((*(Q_00468468 *)((u8 *)(arg0) + (0x10))) = (Q_00468468) (*(Q_00468468 *)((u8 *)(temp_4) + (0x10))), temp_f3 = (*(f32 *)((u8 *)(temp_16) + (8))), temp_f1 = (*(f32 *)((u8 *)(temp_16) + (4))) + temp_f3, (*(f32 *)((u8 *)(temp_16) + (4))) = temp_f1, (temp_f1 < 0.0f))) {
            func_003CD250(arg0);
            return;
        }
        if (temp_f1 > 0.6f) {
            temp_f0 = -temp_f3;
            (*(f32 *)((u8 *)(temp_16) + (8))) = temp_f0;
            (*(f32 *)((u8 *)(temp_16) + (4))) = (f32) (temp_f1 + temp_f0);
        }
        temp_f0_2 = (*(f32 *)((u8 *)(temp_16) + (0x10))) + -0.02088f;
        (*(f32 *)((u8 *)(temp_16) + (0x10))) = temp_f0_2;
        if (temp_f0_2 < 0.0f) {
            (*(f32 *)((u8 *)(temp_16) + (0x10))) = 0.0f;
        }
        temp_f0_3 = (*(f32 *)((u8 *)(temp_16) + (0x14))) + -0.017352002f;
        (*(f32 *)((u8 *)(temp_16) + (0x14))) = temp_f0_3;
        if (temp_f0_3 < 0.0f) {
            (*(f32 *)((u8 *)(temp_16) + (0x14))) = 0.0f;
        }
        temp_f0_4 = (*(f32 *)((u8 *)(temp_16) + (0x18))) + -0.0018000001f;
        (*(f32 *)((u8 *)(temp_16) + (0x18))) = temp_f0_4;
        if (temp_f0_4 < 0.0f) {
            (*(f32 *)((u8 *)(temp_16) + (0x18))) = 0.0f;
        }
        (*(s32 *)((u8 *)(arg0) + (4))) = func_L01_00448CC0((*(f32 *)((u8 *)(temp_16) + (0x10))), (*(f32 *)((u8 *)(temp_16) + (0x14))), (*(f32 *)((u8 *)(temp_16) + (0x18))), (*(f32 *)((u8 *)(temp_16) + (4))));
        temp_f0_5 = (*(f32 *)((u8 *)(temp_16) + (0xC))) + 0.00132f;
        (*(f32 *)((u8 *)(temp_16) + (0xC))) = temp_f0_5;
        if (temp_f0_5 > 1.0f) {
            (*(f32 *)((u8 *)(temp_16) + (0xC))) = (f32) (temp_f0_5 - 1.0f);
        }
        (*(s8 *)((u8 *)(arg0) + (8))) = (s8) (s32) ((*(f32 *)((u8 *)(temp_16) + (0xC))) * 255.0f);
        (*(f32 *)((u8 *)(arg0) + (0xC))) = (f32) (((*(f32 *)((u8 *)((*(void **)((u8 *)(arg0) + (0x20)))) + (0x2C))) * 100000.0f * 30.0f) + 50000.0f);
    }
}
/* localdecomp:end func_L01_00468468 */

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

/* localdecomp:start func_L01_00468828 */
#include "vu0.h"
extern f32 D_L01_001E29D8[];
void func_L01_00468828(u8 *self) {
    extern s32 func_0038CB00(u8 *);
    extern void func_003CD250(u8 *);
    extern s32 func_00382468(s32);
    extern f32 func_0038CED8(void *);
    extern void func_0038CFB8(void *, void *, f32);
    extern void func_003C4138(f32 *, f32, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_0038D0B0(f32);
    extern f32 func_0038D098(f32);
    u8 *vars = self + 0x20;
    f32 velocity[4] __attribute__((aligned(16)));
    f32 angle, radius;
    s32 alpha;
    if (func_0038CB00(self + 0xA)) { func_003CD250(self); return; }
    if (*(f32 *)(self + 0x18) > *(f32 *)(vars + 0x10)) {
        *(s32 *)(vars + 8) = 0;
        if (*(s16 *)(self + 0xA) > 10) *(s16 *)(self + 0xA) = 10;
    }
    if (*(f32 *)(self + 0x18) + 1.0399999618530273f > *(f32 *)(vars + 0x10)) {
        if (func_00382468(20) == 0 && *(s16 *)(self + 0xA) > 10) *(s16 *)(self + 0xA) = 10;
    }
    if (*(s16 *)(self + 0xA) < 12) {
        alpha = *(u32 *)(self + 4) >> 24;
        *(u32 *)(self + 4) = ((alpha * *(s16 *)(self + 0xA) / 12) << 24) | (*(u32 *)(self + 4) & 0xFFFFFF);
    }
    *(f32 *)(self + 0xC) += 1008.0001220703125f;
    if (*(f32 *)(self + 0xC) > *(f32 *)(vars + 0xC)) *(f32 *)(self + 0xC) = *(f32 *)(vars + 0xC);
    velocity[0] = *(f32 *)(vars + 0);
    velocity[1] = *(f32 *)(vars + 4);
    velocity[2] = *(f32 *)(vars + 8);
    func_0038CFB8(velocity, velocity, func_0038CED8(velocity) * 0.9640000462532043f);
    vec_add_ba(self + 0x10, self + 0x10, velocity);
    func_003C4138(&velocity[2], 0.026000000536441803f, 0.0020000000949949026f);
    *(f32 *)(vars + 4) = velocity[1];
    *(f32 *)(vars + 0) = velocity[0];
    *(f32 *)(vars + 8) = velocity[2];
    *(f32 *)(vars + 0x14) = func_0038DAB8(*(f32 *)(vars + 0x14), *(f32 *)(vars + 0x18));
    angle = func_0038DAB8(D_L01_001E29D8[0], 1.5707963705062866f);
    radius = func_0038D0B0(*(f32 *)(vars + 0x14)) * *(f32 *)(vars + 0x1C);
    velocity[0] = func_0038D098(angle) * radius;
    velocity[1] = func_0038D0B0(angle) * radius;
    velocity[2] = 0.0f;
    vec_add_ab(self + 0x10, self + 0x10, velocity);
}
/* localdecomp:end func_L01_00468828 */

/* localdecomp:start func_L01_00468A68 */
typedef int Q_00468A68 __attribute__((mode(TI)));
extern u8 *D_L01_00221124[];

u8 *func_L01_00468A68(Q_00468A68 *pos, Q_00468A68 *dir, s32 type, s32 arg3) {
    extern u8 *func_L01_004618E0(s32);
    extern f32 func_003824E0(f32 low, f32 high);
    u8 *p = func_L01_004618E0(0x23);
    u8 *vars;

    if (p != 0) {
        vars = p + 0x20;
        *(Q_00468A68 *)(p + 0x10) = *pos;
        p[1] = 0;
        *(u32 *)(p + 4) = 0x80808080;
        p[9] = 0x12;
        p[3] = 0x44;
        *(f32 *)(p + 0xC) = func_003824E0(10500.0f, 16800.0f);
        p[2] = *D_L01_00221124[0];
        *(Q_00468A68 *)(p + 0x20) = *dir;
        *(s32 *)(vars + 0x14) = arg3;
        *(s32 *)(vars + 0x10) = type;
        *(f32 *)(vars + 0x18) = *(f32 *)(p + 0x18);
        if (type == 2) {
            *(s32 *)(vars + 0x18) = 0;
        }
        *(f32 *)(vars + 0x1C) = func_003824E0(0.0042000003f, 0.0072000003f);
    }
    return p;
}
/* localdecomp:end func_L01_00468A68 */

/* localdecomp:start func_L01_00468B70 */
extern f32 D_001A4F30[];
extern s32 D_L01_001D7BE4;
extern u8 D_L01_001EAA20[];
typedef struct { u8 pad[0x20]; vu0_v4 pos; } Hit_00468B70;
extern Hit_00468B70 D_L01_001EAA00[];
void func_L01_00468B70(u8 *self) {
    extern s32 func_003D3CB0(void *, void *, s32, s32, s32);
    extern s32 func_003D5630(void);
    extern void func_L01_0046A938(void *, f32, s32, f32, s32);
    extern void func_L01_0046D250(void *, s32, f32, f32);
    vu0_q next;
    u8 *vars=self+0x20;
    s32 type=*(s32 *)(vars+0x10);
    if (type==0) {
        vec_add_ab(self+0x10,self+0x10,self+0x20);
        goto update;
    } else if (type==1) {
        vec_add_ab(&next,self+0x10,self+0x20);
        if (func_003D3CB0(self+0x10,&next,2,0,0)) {
            if (!func_003D5630()) func_L01_0046A938(D_L01_001EAA20,0.2f,D_L01_001D7BE4,5250.0f,-1);
            goto destroy;
        }
        goto moved;
    } else if (type==3) {
        vec_add_ab(self+0x10,self+0x10,self+0x20);
        if (*(f32 *)(self+0x18)<D_001A4F30[0]) {
            s32 effect=D_L01_001D7BE4;
            *(f32 *)(self+0x18)=D_001A4F30[0];
            func_L01_0046A938(self+0x10,0.2f,effect,5250.0f,-1);
            goto destroy;
        }
        goto update;
    } else {
        vec_add_ab(&next,self+0x10,self+0x20);
        if (func_003D3CB0(self+0x10,&next,2,0,0)) {
            if (func_003D5630()) {
                Hit_00468B70 *hit=D_L01_001EAA00;
                hit->pos.z+=0.05f;
                func_L01_0046D250(&hit->pos,-1,0.25f,3150.0f);
            }
            goto destroy;
        }
        goto moved;
    }
    goto update;
destroy:
    func_003CD250(self);
    return;
moved:
    *(vu0_q *)(self+0x10)=next;
update:
    *(f32 *)(vars+8)-=*(f32 *)(vars+0x1C);
    self[8]+=2;
    if (--*(s32 *)(vars+0x14)<=0 || *(f32 *)(self+0x18)<*(f32 *)(vars+0x18)) {
        s32 color=*(s32 *)(self+4)+0xF0000000;
        *(s32 *)(self+4)=color;
        if (color<0) {
            func_003CD250(self);
        }
    }
}
/* localdecomp:end func_L01_00468B70 */

INCLUDE_ASM("asm/levels", func_L01_00468D98);

LINKER_REMNANT("asm/levels", func_L01_00468F00);

/* localdecomp:start func_L01_00468F08 */
#include "vu0.h"
extern vu0_v4 D_L01_001E29C0;
void func_L01_00468F08(u8 *self) {
    extern s32 func_0038CB00(u8 *);
    extern void func_003CD250(u8 *);
    extern f32 func_0038CEA8(void *);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038CE20(void *, void *, f32);
    extern s32 func_L01_00447470_00468F08(s32, s32, f32);
    extern s32 abs(s32);
    vu0_v4 delta;
    u8 *vars = self + 0x20;
    s32 total;
    if (func_0038CB00(self + 0xA)) {
        func_003CD250(self);
        return;
    }
    vec_sub_ba(&delta, &D_L01_001E29C0, vars);
    if (func_0038CEA8(&delta) > 5.0f) {
        func_0038CF68(&delta, &delta, 1.25f);
    } else {
        func_0038CE20(&delta, &delta, 0.25f);
    }
    vec_add_ab(self + 0x10, vars, &delta);
    total = *(s32 *)(vars + 0x14);
    *(s32 *)(self + 4) = func_L01_00447470_00468F08(0, *(s32 *)(vars + 0x10), (f32)(total - abs(*(s16 *)(self + 0xA) - total)) / (f32)total);
}
/* localdecomp:end func_L01_00468F08 */

LINKER_REMNANT("asm/levels", func_L01_00469010);

/* localdecomp:start func_L01_00469018 */
#include "vu0.h"
void func_L01_00469018(u8 *self) {
    extern s32 func_0038CB00(u8 *);
    extern void func_003CD250(u8 *);
    extern void func_0038CE20(void *, void *, f32);
    u8 *vars = self + 0x20;
    if (func_0038CB00(self + 0xA)) goto destroy;
    *(f32 *)(self + 0xC) += *(f32 *)(vars + 0x10);
    self[8]++;
    *(f32 *)(vars + 0x14) -= 0.012f;
    *(f32 *)(vars + 0x14) = *(f32 *)(vars + 0x14) < 0.0f ? 0.0f : *(f32 *)(vars + 0x14);
    *(u32 *)(self + 4) &= 0xFFFFFF;
    *(u32 *)(self + 4) |= (s32)(*(f32 *)(vars + 0x14) * 255.0f) << 24;
    if (*(f32 *)(vars + 0x14) <= 0.0f) {
destroy:
        func_003CD250(self);
    } else {
        vec_add_ab(self + 0x10, self + 0x10, self + 0x20);
        func_0038CE20(vars, vars, 0.976f);
    }
}
/* localdecomp:end func_L01_00469018 */

LINKER_REMNANT("asm/levels", func_L01_00469128);

/* localdecomp:start func_L01_00469130 */
#include "vu0.h"
__asm__(".extern D_L01_001D7F24, 4");
__asm__(".extern D_L01_001D7F20, 4");
__asm__(".extern D_L01_001D7F2C, 1");
__asm__(".extern D_L01_001D7F28, 4");
extern s32 D_L01_001D7F24 __attribute__((section(".sdata")));
extern f32 D_L01_001D7F20 __attribute__((section(".sdata")));
extern u8 D_L01_001D7F2C __attribute__((section(".sdata")));
extern f32 D_L01_001D7F28 __attribute__((section(".sdata")));
extern vu0_v4 D_L01_001E29C0;
extern u8 *D_L01_00221134[];
typedef struct {
    u8 type, flags, texture, render;
    s32 rgba;
    u8 spin, render2;
    s16 life;
    f32 size;
    vu0_v4 position;
} Particle_00469130;
void func_L01_00469130(u8 *self) {
    extern void func_0038CF68(void *, void *, f32);
    vu0_v4 delta;
    Particle_00469130 *p = (Particle_00469130 *)self;
    u8 *vars = self + 0x20;
    p->rgba = D_L01_001D7F24;
    p->size = D_L01_001D7F20;
    p->spin += D_L01_001D7F2C;
    vec_sub_ba(&delta, *(u8 **)(vars + 4) + 0x10, &D_L01_001E29C0);
    func_0038CF68(&delta, &delta, D_L01_001D7F28);
    vec_add_ba(self + 0x10, *(u8 **)(vars + 4) + 0x10, &delta);
    p->texture = D_L01_00221134[0][*(s32 *)(vars + 8) / 2];
    if (++*(s32 *)(vars + 8) >= 31) *(s32 *)(vars + 8) = 0;
    if (p->life == 0) func_003CD250(self);
}
/* localdecomp:end func_L01_00469130 */

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

/* localdecomp:start func_L01_00469C18 */
typedef int Q_00469C18 __attribute__((mode(TI)));
typedef struct {
    Q_00469C18 velocity;
    f32 phase;
    s16 h14, h16;
    u8 type;
    u8 pad[3];
    s32 value;
} Vars_00469C18;
extern u8 *D_L01_002210C8[];

static __inline__ s32 remainder_00469C18(s32 value, s32 divisor) {
    return value % divisor;
}
u8 *func_L01_00469C18(Q_00469C18 *pos, Q_00469C18 *vel, u8 type, s32 value) {
    extern u8 *func_L01_004618E0(s32);
    extern u32 func_L01_00448CC0(f32, f32, f32, f32);
    extern f32 func_003824E0(f32, f32);
    extern u8 func_0013D3E0(void);
    u8 *p = func_L01_004618E0(42);
    Vars_00469C18 *v;
    if (p != 0) {
        *(Q_00469C18 *)(p + 0x10) = *pos;
        v = (Vars_00469C18 *)(p + 0x20);
        *(Q_00469C18 *)(p + 0x20) = *vel;
        *(u32 *)(p + 4) = func_L01_00448CC0(0.7f, 0.7f, 0.7f, 0.08f);
        p[1] = 0;
        p[9] = 0x44;
        p[3] = 0x44;
        v->phase = func_003824E0(0.0f, 1.0f);
        p[8] = (s32)(v->phase * 256.0f);
        p[2] = D_L01_002210C8[0][func_0013D3E0() & 7];
        v->type = type;
        v->h14 = 0;
        v->h16 = 0;
        if (type < 5) {
            *(f32 *)(p + 0xC) = func_003824E0(7000.0f, 10000.0f);
            *(s16 *)(p + 0xA) = 15 - remainder_00469C18(func_0013D3E0(), 12);
        } else {
            *(s16 *)(p + 0xA) = 15;
            *(f32 *)(p + 0xC) = 10000.0f;
        }
        v->value = value;
    }
    return p;
}
/* localdecomp:end func_L01_00469C18 */

INCLUDE_ASM("asm/levels", func_L01_00469D88);

LINKER_REMNANT("asm/levels", func_L01_0046A428);

/* localdecomp:start func_L01_0046A430 */
#include "vu0.h"
void func_L01_0046A430(u8 *self)
{
    extern void func_003CD250(u8 *);
    u8 *vars = self + 0x20;
    s32 time, life;
    f32 factor, r, g, b, total;
    u8 blue, green, red, alpha;
    ++*(s16 *)(self + 0xA);
    time = *(s16 *)(self + 0xA);
    life = *(s16 *)(vars + 0x18);
    if (time > life) {
        func_003CD250(self);
        return;
    }
    total = life;
    factor = (f32)time / total;
    factor = 1.0f - factor;
    g = vars[0x14] + -0.001f * factor;
    b = vars[0x15] + -0.0011f * factor;
    r = vars[0x16] + -0.00111f * factor;
    red = r;
    green = g;
    blue = b;
    if (time < 25) {
        factor = (f32)time / 25.0f;
        alpha = vars[0x17] * factor;
    } else {
        factor = (f32)(time - 25) / (f32)(life - 25);
        factor = 1.0f - factor;
        alpha = vars[0x17] * factor;
    }
    *(u32 *)(self + 4) = (alpha << 24) | (red << 16) | (blue << 8) | green;
    self[8]++;
    vec_add_ab(self + 0x10, self + 0x10, vars);
    *(f32 *)(vars + 8) += 0.0007200000691227615f;
}
/* localdecomp:end func_L01_0046A430 */

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

/* localdecomp:start func_L01_0046A798 */
#include "vu0.h"
extern f32 D_001A4EC0[];
void func_L01_0046A798(u8 *p) {
    extern s32 func_0038CB00(u8 *);
    extern void func_003CD250(u8 *);
    extern void func_L01_004CAB30(void *, void *);
    extern void func_0038CE20(void *, void *, f32);
    u8 *e;
    f32 ratio;
    f32 v[4] __attribute__((aligned(16)));
    f32 g[4] __attribute__((aligned(16)));
    if (func_0038CB00(p + 10)) {
        func_003CD250(p);
        return;
    }
    e = p + 0x20;
    ratio = (f32)*(s16 *)(p + 10) / (f32)*(s16 *)(e + 0x1C);
    *(u32 *)(p + 4) = ((s32)((f32)*(s16 *)(e + 0x1E) * ratio) << 24) | (e[0x13] << 16) | (e[0x12] << 8) | e[0x11];
    v[0] = *(f32 *)(p + 0x20);
    v[3] = 0.0f;
    v[1] = *(f32 *)(e + 4);
    v[2] = *(f32 *)(e + 8);
    vec_add_ab(p + 0x10, p + 0x10, v);
    if (*(f32 *)(p + 0x1C) != 0.0f) {
        if (*(f32 *)(p + 0x1C) == 2.0f) func_L01_004CAB30(p + 0x10, p + 0x10);
        *(f32 *)(p + 0x1C) = 2.0f;
    }
    func_0038CE20(g, D_001A4EC0, *(f32 *)(e + 0xC));
    vec_add_ab(v, v, g);
    func_0038CE20(v, v, *(f32 *)(e + 0x18));
    *(f32 *)(e + 0) = v[0];
    *(f32 *)(e + 4) = v[1];
    *(f32 *)(e + 8) = v[2];
    p[8] += e[0x10];
    *(f32 *)(p + 0xC) += *(f32 *)(e + 0x14);
}
/* localdecomp:end func_L01_0046A798 */
