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
