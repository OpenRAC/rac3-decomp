#include "common.h"

typedef int Q_003CAE68 __attribute__((mode(TI)));
typedef struct {
    u8 pad0[0xD0];
    u8 bD0;
    u8 padD1[0xB];
    void *pDC;
} Slot_003CAE68;
typedef struct {
    u8 pad0[0xC0];
    f32 v270[4];
    u8 padD0[0x58];
    s16 h128;
} Obj_003CAE68;
typedef struct {
    u8 pad0[0x6B0];
    f32 f6B0[4];
    u8 pad6C0[0x10];
    Obj_003CAE68 *p6D0;
    u8 pad6D4[0x78];
    f32 f74C;
    u8 pad750[0x28];
    s32 h778;
    s32 h77C;
    s32 h780;
    s32 h784;
    s32 state788;
    s16 h78C;
    u8 pad78E[2];
    f32 f790[4];
    s16 h7A0;
    s16 h7A2;
} Sub_003CAE68;
typedef struct {
    u8 pad0[0x68];
    Sub_003CAE68 *sub;
    u8 pad6C[0x50];
    u8 bBC;
    u8 padBD[0x3B];
    f32 fF8;
} Self_003CAE68;

/* declared by functions of L09_003CAC70.c, which this file was cut from */
extern s32 D_001D545C;
extern f32 func_L01_0040E548(void *, void *);
extern void func_L09_003C7B78(u8 *);
extern void func_L09_003CAC70(u8 *);
extern void func_L01_004450F0(u8 *, s32, s32);
extern void func_0038CF68(void *, void *, f32);

INCLUDE_ASM("asm/levels", func_L09_003CB6C0);

INCLUDE_ASM("asm/levels", func_L09_003CB7B0);
