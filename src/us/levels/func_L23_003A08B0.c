#include "common.h"
#include "structs/hero.h"

/* NTSC-U counterpart of func_L23_003A2068 (src/levels/23_holostar_studios_clank/L23_003A2068.c): 60 Hz timers (600, 360) and other float args (20.0f, 15.0f) */
/* localdecomp:start func_L23_003A08B0 */
typedef struct { u8 pad[0x24]; s32 i24; u8 pad28[0x6C - 0x28]; s32 i6C; u8 pad70[6]; s16 h76; u8 pad78[0x94 - 0x78]; s32 i94; s16 h98; u8 pad9A[4]; s16 h9E; } G_003A31D8;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { u8 pad0[0x30]; V4 pos; u8 pad40[0x40]; } Node_3A2068;
typedef struct { u8 pad0[0x34]; u16 h34; u8 pad36[0x98 - 0x36]; s32 i98; } M10_3A2068;
typedef struct {
    u8 pad0[8]; s32 i8; s32 iC; M10_3A2068 *p10; s32 i14; s32 i18; u8 pad1C[4]; f32 f20; f32 f24;
    u8 pad28[0x30 - 0x28]; s32 i30; u8 pad34[0x3C - 0x34]; s32 i3C; u8 pad40[0x64 - 0x40]; s32 i64;
    u8 pad68[0x80 - 0x68]; s32 i80; s32 i84; s32 i88; s32 i8C; s32 i90; u8 pad94[0xB4 - 0x94];
    s32 iB4; s32 iB8; u8 padBC[4]; s32 iC0; s32 iC4; s32 iC8; s32 iCC; u8 padD0[0x160 - 0xD0];
    s32 i160; s32 i164; s32 i168; u8 pad16C[0x17C - 0x16C]; s32 i17C;
} Vars_003A2068;
extern s32 D_L23_001D6694;
__asm__(".extern D_L23_001D6694, 16");
extern s32 D_L23_001D6690;
__asm__(".extern D_L23_001D6690, 16");
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern u8 D_001BBC40[][16];
extern s32 D_00142C60[];
__asm__(".extern D_00142C60, 16");
extern u8 D_001426E0[];
extern struct Hero D_001A4BE0;
extern u8 D_L23_001E85C0[];
extern f32 D_L23_001D6720;
__asm__(".extern D_L23_001D6720, 16");
extern f32 D_L23_001DEAD0;
__asm__(".extern D_L23_001DEAD0, 16");
extern s32 D_L23_001DED14;
__asm__(".extern D_L23_001DED14, 16");
extern s32 D_L23_001DDFDC;
__asm__(".extern D_L23_001DDFDC, 4");
extern s32 D_L23_001DDFE0;
__asm__(".extern D_L23_001DDFE0, 4");
extern Node_3A2068 *D_L23_001DF2C0;
__asm__(".extern D_L23_001DF2C0, 16");

extern s32 func_L01_00452EF0(void *);
extern s32 func_L01_00452EC8(void *);
extern s32 func_L01_00452F60(void *);
extern s32 func_L01_00453210(void *, s32);
extern void func_L23_003A1250(u8 *);
extern void func_L23_003A2850(u8 *);
extern void func_L23_0039A1F8(u8 *, V4);
extern void func_L01_003EF800(void *);
extern void func_L23_003B2BE0(void *);
extern void func_L23_003B5430(s32);
extern void func_L01_003F32F0(s32, f32);
extern void func_L23_003D6580(s32, s32, f32);
extern s32 func_0038E2E8(void *, s32);
extern s32 func_0038E440(void *);
extern void func_0038E5B8(s32, s32);
extern void func_00399C90(s32, s32);
extern s32 func_00399F90(void);
extern void func_L01_00438430(s32);
extern u8 *func_0037E0B8(void *);
extern void func_L03_0042FC00(s32, s32);
extern f32 func_003BEBF8(f32 *, f32, f32);
extern void func_L01_0045BE58(s32, s32);
extern s32 func_L01_00477BD0(void);
extern void func_L01_0049FDB0(u8 *, u8 *);
extern void func_L01_004A6DF8(void *, s32);
extern s32 func_L01_004B6C68(void);
extern void func_L01_004EA040(void);
extern void func_L01_00441FB8(void *, s32, s32);
void func_L23_003A20A8(void *);
void func_L23_003A16C0(u8 *);
void func_L23_003A1738(u8 *);
void func_L23_003A17B0(void *, s32);
void func_L23_003A1800(void *);
void func_L23_003A1868(u8 *, u8 *);
void func_L23_003A1A20(u8 *);
void func_L23_003A2810(u8 *, s32);
extern u8 *D_L23_001DF1DC;
__asm__(".extern D_L23_001DF1DC, 16");
extern u8 D_001A4C60[];
extern G_003A31D8 D_001CCFD0;
extern s32 func_0037E0F0(void *, s32, s32);
extern s32 func_0037E208(s32, s32);

void func_L23_003A08B0(u8 *o)
{
    Vars_003A2068 *v = *(Vars_003A2068 **)(o + 0x68);
    s32 r;
    u8 *p;
    f32 f;
    unsigned long t;
    V4 pos;

    if (D_L23_001D6694 == 1 || D_L23_001D6694 == 2 || D_L23_001D6690 == 1 || D_L23_001D6690 == 2)
        return;
    if (o[0x95] == 0 && func_L01_00452EF0(o)) {
        func_L23_003A1250(o);
        func_L23_003A2810(o, 0);
    }
    if (o[0x20] == 0) {
        if (D_001BBC40[D_001D545C][v->i14] & 0x80)
            func_L01_00441FB8(o, 5, 2);
        else
            func_L01_00441FB8(o, 1, 1);
    }
    switch (o[0x95]) {
    case 2:
        if (func_L01_00452EF0(o)) {
            func_L23_003A1738(o);
            func_L23_003A2810(o, 1);
        }
        func_L23_003A2850(o);
        break;
    case 1:
        if (func_L01_00452EF0(o)) {
            func_L23_003A16C0(o);
            func_L23_003A2810(o, 0);
        }
        break;
    }
    switch (o[0x20]) {
    case 1:
        t = D_00142C60[0];
        if (!((t >> 2) & 1) && func_0038E2E8(D_L23_001E85C0, 0xC2)) {
            func_0038E440(D_L23_001E85C0);
            D_L23_001D6720 = 2.0f;
            v->i30 = 1;
            break;
        }
        func_L23_003A17B0(o, 600);
        func_L01_00441FB8(o, 2, -1);
        break;
    case 2:
        if (func_L01_00452EC8(o)) {
            r = D_L23_001DDFDC++;
            switch (r) {
            case 0: if (0x12 != v->i168 && 0x12 != v->i164) v->i160 = 0x12; break;
            case 2: if (0x1F != v->i168 && 0x1F != v->i164) v->i160 = 0x1F; break;
            case 4: if (0x20 != v->i168 && 0x20 != v->i164) v->i160 = 0x20; break;
            case 6: if (0x21 != v->i168 && 0x21 != v->i164) v->i160 = 0x21; break;
            case 11: if (0x1E != v->i168 && 0x1E != v->i164) v->i160 = 0x1E; break;
            default: if (0x1D != v->i168 && 0x1D != v->i164) v->i160 = 0x1D; break;
            }
        }
        if (func_0037E0F0(D_001A4C60, v->iB8, 0))
            *(f32 *)(D_001A4C60 + 0x19DC) = 0.61086524f;
        else
            *(f32 *)(D_001A4C60 + 0x19DC) = 0.0f;
        *(s32 *)(*(u8 **)(D_L23_001DF1DC + v->i80 * 0x100 + 0x68) + 0xC) =
            func_L01_00452F60(D_L23_001DF1DC + v->i84 * 0x100);
        if (v->i164 == 0 || v->i164 == 1 || (v->i64 >= 2 && v->i64 < 10)) {
            func_L23_003A1800(o);
            func_L23_003B5430(v->i90);
            v->i164 = -1;
            v->i168 = -1;
        }
        if (__builtin_fabsf(D_001A4BE0.pos.z - D_L23_001DF2C0[v->iC8].pos.z) < 1.0f &&
            __builtin_fabsf(*(f32 *)(D_L23_001DF1DC + v->i8 * 0x100 + 0x18) - D_L23_001DF2C0[v->iC4].pos.z) < 1.0f) {
            if (func_0037E0F0(&D_001A4BE0.pos, v->iC0, 0)) {
                p = D_L23_001DF1DC + (v->i8 << 8);
                pos = D_L23_001DF2C0[v->iC4].pos;
                func_L23_0039A1F8(p, pos);
            } else {
                p = D_L23_001DF1DC + (v->i8 << 8);
                pos = D_L23_001DF2C0[v->iCC].pos;
                func_L23_0039A1F8(p, pos);
            }
        }
        if (v->i8C >= 0 && func_0037E0F0(D_001A4C60, v->i8C, 0)) {
            func_L03_0042FC00(v->i88, 1);
            v->i8C = -1;
        }
        if (v->i164 == 0x17)
            func_L01_00441FB8(o, 4, -1);
        if (func_L01_00453210(D_001A4C60, v->iB4))
            func_L01_00441FB8(o, 3, -1);
        break;
    case 3:
        func_L23_003A17B0(o, 2);
        if (D_L23_001DEAD0 < 1.0f) {
            func_003BEBF8(&D_L23_001DEAD0, 1.0f, 0.05f);
        } else {
            *(s16 *)((u8 *)&D_001A4BE0 + 0x22A) = 0;
            if (func_L01_00452EC8(o)) {
                s32 k;

                if (D_001CCFD0.h76 != 6 && D_001CCFD0.h76 != 7) D_001CCFD0.h76 = 5;
                if (D_001CCFD0.h9E != 6 && D_001CCFD0.h9E != 7) D_001CCFD0.h9E = 5;
                k = func_0037E208(8, 0xC);
                if (k != v->i168 && k != v->i164) v->i160 = k;
            }
            if (v->i160 == -1 && v->i168 == -1)
                func_L01_004EA040();
        }
        break;
    case 4:
        if (func_L01_00452EC8(o))
            func_L23_003D6580(0, 1, 20.0f);
        if (1.0f <= D_L23_001DEAD0) {
            func_L01_00438430(v->i14);
            func_L01_00441FB8(o, 5, 2);
            D_001426E0[0xC2] = 1;
            func_L01_0049FDB0(D_001A4C60, D_001A4C60 + 0x10);
            func_00399C90(0, -1);
        }
        break;
    case 5:
        if (func_L01_00452EC8(o)) {
            func_L01_003F32F0(0, 15.0f);
            func_L01_0045BE58(v->i17C, -1);
            v->p10->h34 |= 0x41;
            v->p10->h34 &= ~0x1000;
            v->p10->i98 = 0;
            func_L01_004A6DF8(v->p10, 1);
            func_L23_003A17B0(o, 600);
        }
        func_L01_00441FB8(o, 6, -1);
        break;
    case 6:
        p = func_0037E0B8(D_L23_001DF1DC + (v->iC << 8));
        if (p != 0 && *(s16 *)(p + 4) != 0) {
            f = *(f32 *)p / (f32)*(s16 *)(p + 4);
            if (f < 0.0f) f = 0.0f;
        } else {
            f = 1.0f;
        }
        v->f24 = f;
        f = (f32)*(s32 *)((u8 *)&D_001A4BE0 + 0x1A84) / 1500.0f;
        if (f < 0.0f) f = 0.0f;
        v->f20 = f;
        if (func_L01_00452EC8(o)) {
            r = D_L23_001DDFE0++;
            switch (r) {
            case 0: if (0x10 != v->i168 && 0x10 != v->i164) v->i160 = 0x10; break;
            case 2: if (0x1F != v->i168 && 0x1F != v->i164) v->i160 = 0x1F; break;
            case 4: if (0x20 != v->i168 && 0x20 != v->i164) v->i160 = 0x20; break;
            case 6: if (0x21 != v->i168 && 0x21 != v->i164) v->i160 = 0x21; break;
            case 11: if (0x1E != v->i168 && 0x1E != v->i164) v->i160 = 0x1E; break;
            default: if (0x1D != v->i168 && 0x1D != v->i164) v->i160 = 0x1D; break;
            }
        }
        if (v->i164 == 0 || v->i164 == 1 || (v->i64 >= 2 && v->i64 < 10)) {
            func_L23_003A1800(o);
            func_L23_003B2BE0(D_L23_001DF1DC + (v->iC << 8));
            v->i164 = -1;
            v->i168 = -1;
        }
        if (v->f20 < 0.0f)
            func_L01_00441FB8(o, 7, -1);
        if (v->i164 == 0x1B)
            func_L01_00441FB8(o, 8, -1);
        func_L23_003A1868(o, D_L23_001DF1DC + (v->iC << 8));
        break;
    case 7:
        func_L23_003A17B0(o, 2);
        if (D_L23_001DEAD0 < 1.0f) {
            func_003BEBF8(&D_L23_001DEAD0, 1.0f, 0.05f);
        } else {
            *(s16 *)((u8 *)&D_001A4BE0 + 0x22A) = 0;
            if (func_L01_00452EC8(o)) {
                s32 k;

                if (D_001CCFD0.h76 != 6 && D_001CCFD0.h76 != 7) D_001CCFD0.h76 = 5;
                if (D_001CCFD0.h9E != 6 && D_001CCFD0.h9E != 7) D_001CCFD0.h9E = 5;
                k = func_0037E208(8, 0xC);
                if (k != v->i168 && k != v->i164) v->i160 = k;
            }
            if (v->i160 == -1 && v->i168 == -1)
                func_L01_004EA040();
        }
        break;
    case 8:
        if (func_L01_00452EC8(o))
            func_L01_003EF800(o);
        if (*(u16 *)(o + 0x96) > 360) {
            if (!(D_00142C60[0] & 1) && func_0038E2E8(D_L23_001E85C0, 0xC0)) {
                func_0038E2E8(D_L23_001E85C0, 0xC1);
                func_0038E440(D_L23_001E85C0);
                D_L23_001DED14 = 0;
                v->i3C = 1;
            } else if (!func_L01_004B6C68()) {
                D_L23_001DED14 = 2;
                D_001426E0[0x32] = 1;
                func_00399F90();
                func_L01_00438430(v->i18);
                func_L01_00477BD0();
                func_0038E5B8(0xD, 1);
                func_L01_00441FB8(o, 9, -1);
            }
        }
        break;
    }
    func_L23_003A1A20(o);
    func_L23_003A20A8(o);
}
/* localdecomp:end func_L23_003A08B0 */
