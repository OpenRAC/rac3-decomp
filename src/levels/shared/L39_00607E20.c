#include "common.h"

/* localdecomp:start func_L39_00607E20 */
/* from boot_elf's func_003B0188 */
typedef struct { u8 pad[0xB0]; s32 handle; } S_00607E20;
typedef struct {
    s32 f0;
    void (*f4)(void);
    s32 f8;
    s32 fC;
    void *f10;
    s32 f14;
    s32 f18;
    s32 f1C;
    s32 f20;
    s32 pad[3];
} Cfg_00607E20;
extern void func_003B1308(s32);
extern void func_001431D0(void);
extern void func_L39_0060A4C8(s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L39_006080C0(s32, s32, s32, s32);
extern void func_L39_0060A5D0(s32, s32, s32, void (*)(void), s32);
extern void func_003B2BF8(s32, s32, s32, s32);
extern void func_003B27C8(void);
extern s32 func_00126060(Cfg_00607E20 *);
extern void func_001271D0(s32, S_00607E20 *);
extern void func_003B1400(s32, s32, s32);
extern void func_0013A9D8(s32 *);
extern void func_L39_00608DB0(void);
extern s32 func_00125F70(s32, void (*)(void), s32);
extern void func_00126E38(s32);
extern void func_003B0FF0(void);
extern void func_003B1108(void);
extern void func_003B0F50(void);
extern s32 D_L39_0024CC04, D_L39_0024CBEC, D_L39_0024CBF0, D_L39_0024CC10, D_L39_0024CBF8;
extern S_00607E20 *D_L39_0024CC0C_00607E20;
extern s32 D_L39_0024CBF4, D_L39_0024CBE4, D_L39_0024CBE8, D_L39_0024CBE0, D_L39_0024CC00, D_L39_0024CC08;
extern u8 D_00247FC0[1];
extern s32 D_L39_0024CBFC;
extern s32 D_L39_0024CC20;
void func_L39_00607E20(s32 a, s32 b, s32 c) {
    Cfg_00607E20 cfg;
    s32 t;
    *(volatile u32 *)0x1000E000 |= 3;
    *(volatile u32 *)0x1000E010 = 4;
    func_003B1308(D_L39_0024CBF4);
    func_001431D0();
    func_L39_0060A4C8((s32)D_L39_0024CC0C_00607E20, D_L39_0024CBF0, 0xEC800, D_L39_0024CBFC, D_L39_0024CBEC, 0x100, D_L39_0024CC04, 0x200);
    func_L39_006080C0(D_L39_0024CC10, D_L39_0024CBF8, 0xC000, 3);
    func_L39_0060A5D0((s32)D_L39_0024CC0C_00607E20, 0, 0, func_003B0FF0, D_L39_0024CBF4);
    func_L39_0060A5D0((s32)D_L39_0024CC0C_00607E20, 3, c, func_003B1108, D_L39_0024CBF4);
    func_003B2BF8(D_L39_0024CBE0, (D_L39_0024CBE4 & 0xFFFFFFF) | 0x20000000, D_L39_0024CBE8, 2);
    cfg.f4 = func_003B27C8;
    cfg.fC = 0x4000;
    cfg.f14 = 1;
    cfg.f10 = D_00247FC0;
    cfg.f20 = 0;
    cfg.f8 = D_L39_0024CC00;
    t = func_00126060(&cfg);
    D_L39_0024CC20 = t;
    func_001271D0(t, D_L39_0024CC0C_00607E20);
    func_003B1400(D_L39_0024CC08, a, b);
    func_0013A9D8((s32 *)func_L39_00608DB0);
    D_L39_0024CC0C_00607E20->handle = func_00125F70(2, func_003B0F50, 0);
    func_00126E38(2);
}
/* localdecomp:end func_L39_00607E20 */

/* localdecomp:start func_L39_00607FF8 */
typedef struct { u8 pad[0xB0]; s32 handle; } S_00607FF8;
extern void func_L01_004BF948_00607FF8(s32);
extern void func_L01_004CE7E8_00607FF8(s32);
extern void func_001260B0(s32);
extern void func_00126070(s32);
extern s32 func_00126DD0(s32);
extern void func_00125F90(s32, s32);
extern void func_0013A9D8(s32 *);
extern void func_L39_0060A638(s32);
extern void func_L39_00608158(s32);
extern void func_L39_00609468(s32);
extern s32 D_L39_0024CBF4;
extern s32 D_L39_0024CBE0;
extern s32 D_L39_0024CC20;
extern S_00607FF8 *D_L39_0024CC0C;
extern s32 D_L39_0024CC10;
extern s32 D_L39_0024CC08;
extern s32 D_00194E50[];
void func_L39_00607FF8(void) {
    func_L01_004BF948_00607FF8(D_L39_0024CBF4);
    func_L01_004CE7E8_00607FF8(D_L39_0024CBE0);
    func_001260B0(D_L39_0024CC20);
    func_00126070(D_L39_0024CC20);
    func_00126DD0(2);
    func_00125F90(2, D_L39_0024CC0C->handle);
    func_0013A9D8(D_00194E50);
    func_L39_0060A638((s32)D_L39_0024CC0C);
    func_L39_00608158(D_L39_0024CC10);
    func_L39_00609468(D_L39_0024CC08);
    *(volatile u32 *)0x1000E000 &= ~2; /* D_CTRL */
}
/* localdecomp:end func_L39_00607FF8 */
