#include "common.h"

/* NTSC-U counterpart of func_L39_006B7EB0 (src/levels/39_multiplayer_menu/L39_006B7EB0.c) */
extern s32 D_L39_0024D35C;
extern s32 D_001DDBAC_sda;
extern s32 D_001DDBB0_sda_006B54A8;
extern s32 D_001DDBB4_sda;
extern s32 D_001DDBB8_sda;

/* localdecomp:start func_L39_006B54A8 */
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


__asm__(".extern D_L39_0024145C, 16");
__asm__(".extern D_L39_00242A90, 16");
__asm__(".extern D_L39_0024D358, 16");
__asm__(".extern D_001DDA60_sda, 4");
__asm__(".extern D_001DDA50_sda_006B54A8, 4");
__asm__(".extern D_001DDB80_sda, 4");
__asm__(".extern D_001DDB90_sda, 4");
__asm__(".extern D_001DDB68_sda, 4");
__asm__(".extern D_001DDB58_sda, 4");
__asm__(".extern D_001DDBA8_sda, 4");
__asm__(".extern D_001DDA10_sda, 4");
__asm__(".extern D_001DDA14_sda, 1");
__asm__(".extern D_001E1AC8_sda, 4");
__asm__(".extern D_001E0404_sda, 4");
__asm__(".extern D_001DDBAC_sda, 4");
__asm__(".extern D_001DDBB0_sda_006B54A8, 4");
__asm__(".extern D_001DDBB4_sda, 4");
__asm__(".extern D_001DDBB8_sda, 4");
extern s32 D_L39_0024145C;
extern s32 D_L39_00242A90;
extern M_006B7EB0 *D_L39_0037C8F0[];
extern s32 D_L39_004B13A0[];
extern M_006B7EB0 *D_L39_0024D358;
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
extern Cam_006B7EB0 D_L39_0024DF80[];
extern View_006B7EB0 D_L39_0024DF00;
extern s32 D_001DDBA8_sda;
extern s32 D_001DDA10_sda;
extern u8 D_001DDA14_sda;
extern M_006B7EB0 *D_001E1AC8_sda;
extern V4_006B7EB0 D_001DDA60_sda __attribute__((section(".sdata")));
extern V4_006B7EB0 D_001DDA50_sda_006B54A8 __attribute__((section(".sdata")));
extern V4_006B7EB0 D_001DDB80_sda __attribute__((section(".sdata")));
extern V4_006B7EB0 D_001DDB90_sda __attribute__((section(".sdata")));
extern f32 D_001DDB68_sda[] __attribute__((section(".sdata")));
extern s32 D_001DDB58_sda[] __attribute__((section(".sdata")));
extern s32 D_001E0404_sda;
extern f32 D_L39_0025D7C0[];

extern void func_L39_0061E448(void);
extern M_006B7EB0 *func_003BCFB0(s32, s32);
extern void func_003BD0D8(void *, s32);
extern void func_003C1A40(void *, s32, s32, s32, s32);
extern s32 func_L39_005B2498(s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_003C26C8(void *);
extern void func_00388BD0(void *, void *);
extern void func_00382F40(void);
extern void func_00388550(void *, void *, s32);
extern void func_00381F18(void);
extern void func_L39_00586568(void);
extern s32 func_0012CD60(void);
extern void func_003BE1A0(void);
extern void func_003BE118(void);
extern void func_003BE140(void);
extern void func_003BD8A0(void);
extern void func_L39_00586D40(void);
extern void func_003BD9A0(void *, s32, void *);
extern void func_003C1A90(void *);
extern void func_003A3FB0(s32, s32, s32, s32);
extern void func_L39_005AA108(void *, s32);
extern void func_003BE170(void);
extern void func_003BE2E0(void);
extern void func_003A4720(s32);
extern void func_0012CDB0(void);
extern void func_003A3DA0(s32);
extern void func_003BDC90(void);

void func_L39_006B54A8(void) {
    Mtx_006B7EB0 m;
    M_006B7EB0 *list[4];
    s32 n = 0;
    s32 i;
    f32 save;

    if (D_L39_0024145C != 0x27) {
        return;
    }
    if (--D_001DDBA8_sda <= 0) {
        D_001DDBA8_sda = 0;
    } else {
        D_001DDA10_sda = -1;
    }
    if (D_001DDA10_sda == -1) {
        return;
    }
    func_L39_0061E448();
    if (D_L39_00242A90 == 0) {
        return;
    }
    if (D_L39_0037C8F0[D_001DDA10_sda] == 0) {
        D_L39_0037C8F0[D_001DDA10_sda] = func_003BCFB0(D_L39_004B13A0[D_001DDA10_sda], 0);
        func_003BD0D8(D_L39_0037C8F0[D_001DDA10_sda], D_L39_004B13A0[D_001DDA10_sda]);
        D_L39_0037C8F0[D_001DDA10_sda]->h32 = 0xC0;
        func_003C1A40(D_L39_0037C8F0[D_001DDA10_sda], 0x808080, 0, 0, 0);
        *(u128_006B7EB0 *)&D_L39_0037C8F0[D_001DDA10_sda]->mF0 = *(u128_006B7EB0 *)&D_001DDA60_sda;
        D_L39_0037C8F0[D_001DDA10_sda]->b7E |= 0x80;
        D_L39_0037C8F0[D_001DDA10_sda]->b7E &= 0x8F;
        i = func_L39_005B2498(4);
        D_L39_0037C8F0[D_001DDA10_sda]->f48 = D_001DDB68_sda[i];
        func_003BE4F0(D_L39_0037C8F0[D_001DDA10_sda], D_001DDB58_sda[i], 0, 10);
        func_003C26C8(D_L39_0037C8F0[D_001DDA10_sda]);
    }
    if (D_L39_0024D358 == 0) {
        D_L39_0024D358 = func_003BCFB0(0x1094, 0);
        func_003C1A40(D_L39_0024D358, 0x808080, 0, 0, 0);
        func_003BD0D8(D_L39_0024D358, 0x1094);
        D_L39_0024D358->h32 = 0xC0;
        D_L39_0024D358->mF0.z = 3.1415927f;
        func_003BE4F0(D_L39_0024D358, 1, 0, 10);
    }
    func_00388BD0(D_L39_0024DF00.unk20, &D_001DDA50_sda_006B54A8);
    D_001E0404_sda = 0;
    func_00382F40();
    D_L39_0024DF80[0].pos = D_L39_0024DF00.pos;
    D_L39_0024DF80[0].unk10 = D_L39_0024DF00.unk10;
    func_00388550(D_L39_0024DF80[0].c, D_L39_0024DF00.unk20, 0x30);
    func_00381F18();
    save = D_L39_0025D7C0[44];
    D_L39_0025D7C0[44] = 0.62f;
    func_L39_00586568();
    func_0012CD60();
    func_003BE1A0();
    func_003BE118();
    func_003BE140();
    D_L39_0024DF00.pos = *(u128_006B7EB0 *)&D_001DDB80_sda;
    func_00381F18();
    func_003BD8A0();
    func_L39_00586D40();
    D_L39_0037C8F0[D_001DDA10_sda]->b7E &= 0x8F;
    D_L39_0037C8F0[D_001DDA10_sda]->b7E |= (D_001DDA14_sda << 4) & 0x70;
    *(u128_006B7EB0 *)&D_L39_0037C8F0[D_001DDA10_sda]->q10 = *(u128_006B7EB0 *)&D_001DDB90_sda;
    if ((D_L39_0037C8F0[D_001DDA10_sda]->b60 & 2) && func_L39_005B2498(2) == 0) {
        i = func_L39_005B2498(4);
        func_003BE4F0(D_L39_0037C8F0[D_001DDA10_sda], D_001DDB58_sda[i], 0, 10);
        D_L39_0037C8F0[D_001DDA10_sda]->f48 = D_001DDB68_sda[i];
    }
    func_003BD9A0(D_L39_0037C8F0[D_001DDA10_sda], 0, &m);
    *(u128_006B7EB0 *)&D_L39_0024D358->q10 = *(u128_006B7EB0 *)&m.r[3];
    *(u128_006B7EB0 *)&D_L39_0024D358->mC0 = *(u128_006B7EB0 *)&m.r[0];
    *(u128_006B7EB0 *)&D_L39_0024D358->mD0 = *(u128_006B7EB0 *)&m.r[1];
    *(u128_006B7EB0 *)&D_L39_0024D358->mE0 = *(u128_006B7EB0 *)&m.r[2];
    *(u128_006B7EB0 *)&D_L39_0024D358->mF0 = *(u128_006B7EB0 *)&m.r[3];
    D_L39_0024D358->h34 |= 0x100;
    func_003C1A90(D_L39_0037C8F0[D_001DDA10_sda]);
    func_003C1A90(D_001E1AC8_sda);
    func_003C26C8(D_L39_0037C8F0[D_001DDA10_sda]);
    func_003C26C8(D_001E1AC8_sda);
    if (D_L39_0024D35C == 1) {
        func_003A3FB0(D_001DDBAC_sda, D_001DDBB0_sda_006B54A8, D_001DDBB4_sda, D_001DDBB8_sda);
        D_L39_0024D35C = 0;
    }
    func_L39_005AA108(D_L39_0037C8F0[D_001DDA10_sda], 1);
    func_L39_005AA108(D_L39_0024D358, 1);
    list[n++] = D_L39_0037C8F0[D_001DDA10_sda];
    func_003BE170();
    func_003BE2E0();
    func_003A4720(0x2080000);
    func_003A3FB0(0, 0x1FF, 0, 0x19F);
    func_0012CDB0();
    func_003A3DA0(0x10);
    func_003BDC90();
    D_L39_0025D7C0[44] = save;
    func_L39_00586568();
    D_001DDA10_sda = -1;
}
/* localdecomp:end func_L39_006B54A8 */
