#include "common.h"

/* NTSC-U counterpart of func_L39_00533250 (src/levels/shared/L39_00533250.c) */
/* localdecomp:start func_L39_00532BD8 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct Vt_00532BD8 { u8 pad0[0x34]; void (*f34)(void *, s32, s32, s32, s32); } Vt_00532BD8;
typedef struct Ply_00532BD8 { u8 pad0[0x14]; Vt_00532BD8 *vt; } Ply_00532BD8;
typedef struct Obj_00532BD8 { u8 pad0[0xBC]; u8 bBC; } Obj_00532BD8;
typedef struct Tgt_00532BD8 { u8 pad0[0x46]; u8 b46; } Tgt_00532BD8;
typedef struct Ent_00532BD8 { u8 b0; u8 b1; u8 pad2[0x3E]; } Ent_00532BD8;
typedef struct St_00532BD8 {
    u32 w0;
    u8 pad4[0xB0 - 4];
    u8 a0B0[0x208 - 0xB0];
    f32 f208;
    u8 pad20C[0x230 - 0x20C];
    u128_t q230;
    u128_t q240;
    u128_t q250;
    u128_t q260;
    u8 pad270[0x288 - 0x270];
    u8 a288[0x2D0 - 0x288];
    Obj_00532BD8 *o2D0;
    u8 pad2D4[4];
    Ply_00532BD8 *p2D8;
} St_00532BD8;
typedef struct Sub_00532BD8 {
    u8 *w0;
    u8 pad4[0x30 - 4];
    f32 f30;
    u16 h34;
    u8 pad36[0x3E - 0x36];
    u8 b3E;
    u8 pad3F;
    f32 f40;
    u8 pad44[0x62 - 0x44];
    u8 b62;
    u8 pad63[0x70 - 0x63];
    Ent_00532BD8 e70[2];
    u8 padF0[0x160 - 0xF0];
    St_00532BD8 *p160;
    u8 pad164[0x16C - 0x164];
    s32 w16C;
} Sub_00532BD8;
typedef struct Slf_00532BD8 {
    u8 pad0[0x10];
    u128_t q10;
    u8 b20;
    u8 pad21[3];
    Tgt_00532BD8 *p24;
    u8 pad28[0x34 - 0x28];
    u16 h34;
    u8 pad36[0x68 - 0x36];
    Sub_00532BD8 *p68;
    u8 pad6C[0x90 - 0x6C];
    St_00532BD8 *p90;
    u8 pad94[0xBC - 0x94];
    u8 bBC;
    u8 padBD;
    u8 bBE;
    u8 padBF[0xF0 - 0xBF];
    u128_t qF0;
} Slf_00532BD8;

extern f32 D_001DF508_sda;
__asm__(".extern D_001DF508_sda, 4");
extern u8 D_001A5FB8[];
extern void func_003BD360(void *);
extern void func_L39_00619A68(void *, s32);
extern void func_L01_0044E128(void *, void *, void *);
extern s32 func_00197588(s32);
extern void func_L39_006663B8(s32, void *, s32, s32, s32, s32, s32, s32);
extern St_00532BD8 *func_L39_006646E0(s32, void *, u32, s32, s32, f32);
extern void func_L01_00437350(void *, s32, void *);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_L39_006197F0(void *);
extern void func_L06_00428768(void *, void *, f32);
extern void func_L01_004455F0(void *, f32, void *, f32, f32, f32, s32);
extern void func_L39_00532968(void *);
extern void func_L39_00532580(void *);
extern void func_L39_00667FF0(void *, void *);
extern void func_L01_004026A0(void *, void *);
extern void func_L39_00531E88(void *);
extern void func_L39_00532B98(void *);

void func_L39_00532BD8(Slf_00532BD8 *a0) {
    St_00532BD8 *s3;
    Sub_00532BD8 *p;
    Ply_00532BD8 *pl;
    u32 id;
    s32 i;

    s3 = a0->p68->p160;
    if (a0->p68->b62 == 1) {
        func_003BD360(a0);
        return;
    }
    switch (a0->b20) {
    case 0:
        p = a0->p68;
        p->w0 = (u8 *)p + 0x30;
        a0->h34 |= 0x5020;
        p->b3E = 1;
        p->f30 = 40.0f;
        p->f40 = D_001DF508_sda;
        p->h34 = 0x28;
        a0->p24->b46 = 5;
        a0->bBE &= 0xE7;
        func_L39_00619A68(a0, -1);
        func_L01_0044E128(&a0->q10, a0, &a0->q10);
        id = 0xFFFFFFFF;
        if (D_001A5FB8[0] != 0) {
            id = func_00197588(3);
        }
        func_L39_006663B8(3, func_L39_00531E88, 0, 0, 0, 0, 0, 0);
        s3 = func_L39_006646E0(3, a0, id, 0xE10, 0, 2.0f);
        p->p160 = s3;
        a0->p90 = s3;
        for (i = 0; i < 2; i++) {
            if (p->e70[i].b1 == 0) {
                func_L01_00437350(a0, i, &p->e70[i]);
            }
        }
        func_L01_00441FB8(a0, 1, -1);
        if (p->w16C == 0) {
            a0->bBC = 8;
        }
        break;
    case 1:
        if (D_001A5FB8[0] != 0 && s3->w0 == 0xFFFFFFFF) {
            s3->w0 = func_00197588(3);
        }
        if (s3->w0 != 0xFFFFFFFF) {
            func_L01_00441FB8(a0, 2, -1);
        }
        break;
    case 2:
    case 5:
        if (a0->b20 == 2) {
            if (func_L39_006197F0(s3->p2D8) >= 0) {
                func_L01_00441FB8(a0, 4, -1);
            } else {
                pl = s3->p2D8;
                if (pl != 0) {
                    s3->q250 = a0->q10;
                    s3->q260 = a0->qF0;
                    pl->vt->f34(pl, 0, 1, 0, 1);
                    func_L01_00441FB8(a0, 3, -1);
                }
            }
        }
        break;
    case 3:
        func_L06_00428768(&a0->q10, s3->a0B0, 0.033333335f);
        func_L01_004455F0((u8 *)a0 + 0xF8, s3->f208, s3->a288, 0.025f, 0.15f, 0.0523598827f, 0);
        if (s3->p2D8 == 0) {
            func_L01_00441FB8(a0, 2, -1);
        }
        s3->q250 = a0->q10;
        s3->q260 = a0->qF0;
        break;
    case 4:
        if (s3->o2D0->bBC != 10) {
            if (s3->p2D8 == 0) {
                func_L01_00441FB8(a0, 2, -1);
            } else {
                func_L39_00532968(a0);
                func_L39_00532580(a0);
                s3->q230 = a0->q10;
                s3->q240 = a0->qF0;
            }
        }
        break;
    case 6:
    case 7:
        break;
    }
    func_L39_00667FF0(s3, a0);
    func_L01_004026A0(func_L39_00532B98, a0);
}
/* localdecomp:end func_L39_00532BD8 */
