#include "common.h"

/* declared by functions of L39_006B7E90.c, which this file was cut from */
extern s32 D_L39_0024D25C;
extern s32 D_001DDBDC_sda;
extern s32 D_001DDBE0_sda;
extern s32 D_001DDBE4_sda;
extern s32 D_001DDBE8_sda;

/* localdecomp:start func_L39_006B7EB0 */
typedef int u128_006B7EB0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_006B7EB0;

typedef struct {
    u8 pad0[0x10];
    V4_006B7EB0 q10;
    u8 pad20[0x12];
    s16 h32;
    u16 h34;
    u8 pad36[0x12];
    f32 f48;
    u8 pad4C[0x14];
    u8 b60;
    u8 pad61[0x1D];
    u8 b7E;
    u8 pad7F[0x41];
    V4_006B7EB0 mC0;
    V4_006B7EB0 mD0;
    V4_006B7EB0 mE0;
    V4_006B7EB0 mF0;
} M_006B7EB0;

typedef struct {
    V4_006B7EB0 r[4];
} Mtx_006B7EB0;


__asm__(".extern D_L39_002412DC, 16");
__asm__(".extern D_L39_00242910, 16");
__asm__(".extern D_L39_0024D258, 16");
__asm__(".extern D_001DDA90_sda, 4");
__asm__(".extern D_001DDA80_sda, 4");
__asm__(".extern D_001DDBB0_sda, 4");
__asm__(".extern D_001DDBC0_sda, 4");
__asm__(".extern D_001DDB98_sda, 4");
__asm__(".extern D_001DDB88_sda, 4");
__asm__(".extern D_001DDBD8_sda, 4");
__asm__(".extern D_001DDA50_sda, 4");
__asm__(".extern D_001DDA54_sda, 1");
__asm__(".extern D_001E1B48_sda, 4");
__asm__(".extern D_001E0484_sda, 4");
__asm__(".extern D_001DDBDC_sda, 4");
__asm__(".extern D_001DDBE0_sda, 4");
__asm__(".extern D_001DDBE4_sda, 4");
__asm__(".extern D_001DDBE8_sda, 4");
extern s32 D_L39_002412DC;
extern s32 D_L39_00242910;
extern M_006B7EB0 *D_L39_0037C7F0[];
extern s32 D_L39_004B1520[];
extern M_006B7EB0 *D_L39_0024D258;
typedef struct {
    u128_006B7EB0 pos;
    u128_006B7EB0 unk10;
    u8 pad20[0x380 - 0x20];
    f32 c[12];
    u8 pad3B0[0x460 - 0x3B0];
} Cam_006B7EB0;
typedef struct {
    u128_006B7EB0 pos;
    u128_006B7EB0 unk10;
    u8 unk20[48];
} View_006B7EB0;
extern Cam_006B7EB0 D_L39_0024DE80[];
extern View_006B7EB0 D_L39_0024DE00;
extern s32 D_001DDBD8_sda;
extern s32 D_001DDA50_sda;
extern u8 D_001DDA54_sda;
extern M_006B7EB0 *D_001E1B48_sda;
extern V4_006B7EB0 D_001DDA90_sda __attribute__((section(".sdata")));
extern V4_006B7EB0 D_001DDA80_sda __attribute__((section(".sdata")));
extern V4_006B7EB0 D_001DDBB0_sda __attribute__((section(".sdata")));
extern V4_006B7EB0 D_001DDBC0_sda __attribute__((section(".sdata")));
extern f32 D_001DDB98_sda[] __attribute__((section(".sdata")));
extern s32 D_001DDB88_sda[] __attribute__((section(".sdata")));
extern s32 D_001E0484_sda;
extern f32 D_L39_0025D6C0[];

extern void func_L39_00620BE8(void);
extern M_006B7EB0 *func_003C24B0(s32, s32);
extern void func_003C25D8(void *, s32);
extern void func_003C6F90(void *, s32, s32, s32, s32);
extern s32 func_L39_005B4398(s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_003C7C38(void *);
extern void func_0038D308(void *, void *);
extern void func_00387218(void);
extern void func_0038CC88(void *, void *, s32);
extern void func_003861F0(void);
extern void func_L39_005872D8(void);
extern s32 func_12CD60(void);
extern void func_003C36C0(void);
extern void func_003C3638(void);
extern void func_003C3660(void);
extern void func_003C2DC0(void);
extern void func_L39_00587E80(void);
extern void func_003C2EC0(void *, s32, void *);
extern void func_003C6FE0(void *);
extern void func_003A9500(s32, s32, s32, s32);
extern void func_L39_005ABFE8(void *, s32);
extern void func_003C3690(void);
extern void func_003C3800(void);
extern void func_003A9C70(s32);
extern void func_12CDB0(void);
extern void func_003A92F0(s32);
extern void func_003C31B0(void);

void func_L39_006B7EB0(void) {
    Mtx_006B7EB0 m;
    M_006B7EB0 *list[4];
    s32 n = 0;
    s32 i;
    f32 save;

    if (D_L39_002412DC != 0x27) {
        return;
    }
    if (--D_001DDBD8_sda <= 0) {
        D_001DDBD8_sda = 0;
    } else {
        D_001DDA50_sda = -1;
    }
    if (D_001DDA50_sda == -1) {
        return;
    }
    func_L39_00620BE8();
    if (D_L39_00242910 == 0) {
        return;
    }
    if (D_L39_0037C7F0[D_001DDA50_sda] == 0) {
        D_L39_0037C7F0[D_001DDA50_sda] = func_003C24B0(D_L39_004B1520[D_001DDA50_sda], 0);
        func_003C25D8(D_L39_0037C7F0[D_001DDA50_sda], D_L39_004B1520[D_001DDA50_sda]);
        D_L39_0037C7F0[D_001DDA50_sda]->h32 = 0xC0;
        func_003C6F90(D_L39_0037C7F0[D_001DDA50_sda], 0x808080, 0, 0, 0);
        *(u128_006B7EB0 *)&D_L39_0037C7F0[D_001DDA50_sda]->mF0 = *(u128_006B7EB0 *)&D_001DDA90_sda;
        D_L39_0037C7F0[D_001DDA50_sda]->b7E |= 0x80;
        D_L39_0037C7F0[D_001DDA50_sda]->b7E &= 0x8F;
        i = func_L39_005B4398(4);
        D_L39_0037C7F0[D_001DDA50_sda]->f48 = D_001DDB98_sda[i];
        func_003C3A10(D_L39_0037C7F0[D_001DDA50_sda], D_001DDB88_sda[i], 0, 8);
        func_003C7C38(D_L39_0037C7F0[D_001DDA50_sda]);
    }
    if (D_L39_0024D258 == 0) {
        D_L39_0024D258 = func_003C24B0(0x1094, 0);
        func_003C6F90(D_L39_0024D258, 0x808080, 0, 0, 0);
        func_003C25D8(D_L39_0024D258, 0x1094);
        D_L39_0024D258->h32 = 0xC0;
        D_L39_0024D258->mF0.z = 3.1415927f;
        func_003C3A10(D_L39_0024D258, 1, 0, 8);
    }
    func_0038D308(D_L39_0024DE00.unk20, &D_001DDA80_sda);
    D_001E0484_sda = 0;
    func_00387218();
    D_L39_0024DE80[0].pos = D_L39_0024DE00.pos;
    D_L39_0024DE80[0].unk10 = D_L39_0024DE00.unk10;
    func_0038CC88(D_L39_0024DE80[0].c, D_L39_0024DE00.unk20, 0x30);
    func_003861F0();
    save = D_L39_0025D6C0[44];
    D_L39_0025D6C0[44] = 0.62f;
    func_L39_005872D8();
    func_12CD60();
    func_003C36C0();
    func_003C3638();
    func_003C3660();
    D_L39_0024DE00.pos = *(u128_006B7EB0 *)&D_001DDBB0_sda;
    func_003861F0();
    func_003C2DC0();
    func_L39_00587E80();
    D_L39_0037C7F0[D_001DDA50_sda]->b7E &= 0x8F;
    D_L39_0037C7F0[D_001DDA50_sda]->b7E |= (D_001DDA54_sda << 4) & 0x70;
    *(u128_006B7EB0 *)&D_L39_0037C7F0[D_001DDA50_sda]->q10 = *(u128_006B7EB0 *)&D_001DDBC0_sda;
    if ((D_L39_0037C7F0[D_001DDA50_sda]->b60 & 2) && func_L39_005B4398(2) == 0) {
        i = func_L39_005B4398(4);
        func_003C3A10(D_L39_0037C7F0[D_001DDA50_sda], D_001DDB88_sda[i], 0, 8);
        D_L39_0037C7F0[D_001DDA50_sda]->f48 = D_001DDB98_sda[i];
    }
    func_003C2EC0(D_L39_0037C7F0[D_001DDA50_sda], 0, &m);
    *(u128_006B7EB0 *)&D_L39_0024D258->q10 = *(u128_006B7EB0 *)&m.r[3];
    *(u128_006B7EB0 *)&D_L39_0024D258->mC0 = *(u128_006B7EB0 *)&m.r[0];
    *(u128_006B7EB0 *)&D_L39_0024D258->mD0 = *(u128_006B7EB0 *)&m.r[1];
    *(u128_006B7EB0 *)&D_L39_0024D258->mE0 = *(u128_006B7EB0 *)&m.r[2];
    *(u128_006B7EB0 *)&D_L39_0024D258->mF0 = *(u128_006B7EB0 *)&m.r[3];
    D_L39_0024D258->h34 |= 0x100;
    func_003C6FE0(D_L39_0037C7F0[D_001DDA50_sda]);
    func_003C6FE0(D_001E1B48_sda);
    func_003C7C38(D_L39_0037C7F0[D_001DDA50_sda]);
    func_003C7C38(D_001E1B48_sda);
    if (D_L39_0024D25C == 1) {
        func_003A9500(D_001DDBDC_sda, D_001DDBE0_sda, D_001DDBE4_sda, D_001DDBE8_sda);
        D_L39_0024D25C = 0;
    }
    func_L39_005ABFE8(D_L39_0037C7F0[D_001DDA50_sda], 1);
    func_L39_005ABFE8(D_L39_0024D258, 1);
    list[n++] = D_L39_0037C7F0[D_001DDA50_sda];
    func_003C3690();
    func_003C3800();
    func_003A9C70(0x2080000);
    func_003A9500(0, 0x1FF, 0, 0x19F);
    func_12CDB0();
    func_003A92F0(0x10);
    func_003C31B0();
    D_L39_0025D6C0[44] = save;
    func_L39_005872D8();
    D_001DDA50_sda = -1;
}
/* localdecomp:end func_L39_006B7EB0 */
