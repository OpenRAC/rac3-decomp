/* NTSC-U draft (2026-11-14, Claude worker): C of func_L01_0033CCA8, the NTSC-U twin of func_L01_0033D398, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (src/levels/shared/L01_0033AC58.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division -mno-split-addresses").
 */
#include "common.h"

/* NTSC-U counterpart of func_L01_0033D398 (src/levels/shared/...) */
typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L01_0033CCA8 */
#include "vu0.h"

typedef struct {
    u8 pad0[0x20];
    u8 b20;
    u8 pad21[0xAA - 0x21];
    u16 xAA;
} O_0033CCA8;

typedef struct {
    u8 pad0[0x360];
    s32 w360;
    u8 pad364[0xAC0 - 0x364];
    u8 *pAC0;
    u8 padAC4[0xC00 - 0xAC4];
    f32 fC00;
    u8 padC04[0x1210 - 0xC04];
    s32 w1210;
    u8 pad1214[0x25C4 - 0x1214];
    s32 w25C4;
    u8 pad25C8[0x25ED - 0x25C8];
    u8 b25ED;
} Hero_0033CCA8;

typedef struct {
    u128_t x0;
    void *x10;
    s32 x14;
    u8 x18;
    u8 x19;
    u16 x1A;
    f32 x1C;
    s32 x20;
    u8 pad24[0xC];
} S_0033CCA8;

typedef struct {
    u8 pad0[0x8C];
    s32 w8C;
    u8 pad90[0x10];
} E_0033CCA8;

typedef struct {
    u8 pad0[0x6C];
    f32 f6C;
    u8 pad70[0xF0 - 0x70];
} Row_0033CCA8;

extern E_0033CCA8 D_L01_00278C40[];
extern u8 D_L01_001E1920[];
extern u8 D_L01_001E1930[];
extern vu0_v4 D_L01_001E2A40;
extern Hero_0033CCA8 D_001A4BE0;
extern u8 D_001D52FC_W[];
extern u8 **D_001D52FC;
extern s32 D_001DD01C_sda;
__asm__(".extern D_001DD01C_sda, 4");
extern u8 D_001425D2[];
extern Row_0033CCA8 D_L01_002C5640[];
extern void func_003BDA38(void *, s32, void *);
extern void func_L01_004FC518(s32, s32);
extern f32 func_003887C8(void *, void *);
extern void func_L01_003F4D78(s32, void *, u32, void *, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32);
extern void func_L01_004E6A08(s32);
extern s32 func_00388398(void *);
extern void func_00388880(void *, void *, f32);
extern void func_L01_00443840(void *, void *);
extern void func_L01_0033D248(void *, void *, s32);
extern void func_L01_0033D4F0(void *);
extern void func_L01_004026A0(void *, void *);
extern void func_L01_0033D090(void);

void func_L01_0033CCA8(O_0033CCA8 *o) {
    vu0_v4 v0;
    vu0_v4 v10;
    vu0_v4 v20;
    S_0033CCA8 s;
    s32 i;
    f32 d;

    *(u128_t *)&v0 = 0;
    if (o->b20 == 0) {
        for (i = 2; i >= 0; i--) {
            D_L01_00278C40[i].w8C = 0;
        }
        o->b20 = 1;
    }
    func_003BDA38(o, 1, D_L01_001E1920);
    func_003BDA38(o, 0, D_L01_001E1930);
    if (D_001A4BE0.w25C4 == 1) {
        func_L01_004FC518(0x1D, 1);
    }
    func_003BDA38(o, 0, &v10);
    switch (o->b20) {
    case 0:
        o->b20 = 1;
        /* fall through */
    case 1:
        if (D_001A4BE0.b25ED == 0) {
            if (D_001A4BE0.pAC0 != 0) {
                d = func_003887C8(&D_L01_001E2A40, D_001A4BE0.pAC0 + 0x10) / 50.0f;
                *(u128_t *)&v20 = *(u128_t *)(D_001A4BE0.pAC0 + 0x10);
                func_L01_003F4D78(0, o, 0xFF0FFF0F, &v20, 0x26, -1, 4, fabs_asm(0.9f - d * 0.65f), 0.0f, 90.0f, 0.5f,
                                  0.5f, 40.0f, 40.0f);
                vec_sub_ab(&v0, D_001A4BE0.pAC0 + 0x10, &v10);
            }
            if ((*(s32 *)(*D_001D52FC + 0x1A4) & D_001A4BE0.w1210) != 0 && D_001A4BE0.pAC0 != 0) {
                D_001DD01C_sda = D_001A4BE0.w360 != 0 ? 0xC : 4;
                o->b20 = 2;
                func_L01_004E6A08(-1);
            }
        }
        break;
    case 2:
        if (func_00388398(&D_001DD01C_sda) != 0) {
            *(u128_t *)&s = *(u128_t *)&v0;
            s.x20 = 1;
            s.x1C = D_L01_002C5640[D_001425D2[0]].f6C;
            s.x14 = 0x10000;
            s.x10 = o;
            D_001A4BE0.fC00 = 0.0f;
            func_00388880(&s, &s, 1.0f);
            ((f32 *)&s)[2] = 1.0f;
            ((f32 *)&s)[3] = 5627.9248f;
            s.x19 = 2;
            s.x1A = o->xAA;
            s.x18 = 3;
            func_L01_00443840(D_001A4BE0.pAC0, &s);
            o->b20 = 3;
            if (D_001A4BE0.w360 != 0) {
                D_001DD01C_sda = 0xF;
                func_L01_0033D248(o, D_001A4BE0.pAC0, 7);
                func_L01_0033D248(o, D_001A4BE0.pAC0, 7);
                func_L01_0033D248(o, D_001A4BE0.pAC0, 7);
            } else {
                D_001DD01C_sda = 3;
                func_L01_0033D248(o, D_001A4BE0.pAC0, 3);
                func_L01_0033D248(o, D_001A4BE0.pAC0, 3);
                func_L01_0033D248(o, D_001A4BE0.pAC0, 3);
            }
            D_001A4BE0.pAC0 = 0;
        }
        break;
    case 3:
        if (func_00388398(&D_001DD01C_sda) != 0) {
            D_001A4BE0.fC00 = 1.0f;
            D_001DD01C_sda = 7;
            o->b20 = 4;
        }
        break;
    case 4:
        if (func_00388398(&D_001DD01C_sda) != 0) {
            o->b20 = 1;
        }
        break;
    }
    func_L01_0033D4F0(o);
    func_L01_004026A0(func_L01_0033D090, o);
}
/* localdecomp:end func_L01_0033CCA8 */
