#include "common.h"

/* NTSC-U counterpart of func_L39_00669538 (src/levels/shared/L39_0066BB58.c): the timer global is D_001A5F78, level data moved */
/* localdecomp:start func_L39_00669538 */
typedef struct O_00669538 {
    u8 p0[0x10];
    f32 f10;
    f32 f14;
    f32 f18;
    u8 p1C[0x4C];
    s32 w68;
    u8 p6C[0x24];
    s32 w90;
    u8 p94[0x16];
    s16 hAA;
} O_00669538;
typedef struct E_00669538 {
    s32 w0;
    u8 p4[0x18];
    O_00669538 *obj;
    u8 p20[8];
    void (*f28)(O_00669538 *);
    void (*f2C)(void);
    u8 b30;
    u8 b31;
    u8 p32[0x12];
} E_00669538;
extern E_00669538 D_L39_0033ACA0[50];
extern s32 D_L39_0024D070;
extern s32 D_L39_0024D038 __attribute__((section(".sdata")));
extern s32 D_001A5F78[];
extern s32 D_L39_002412AC;
extern void func_L39_00669B18_00669538(void);
extern void func_L39_006692B0(void);
extern void func_L39_00669B68(s32);
extern void func_003C1A90(void *);
extern void func_003C26C8(O_00669538 *);
extern void func_L39_00669478(s32);

void func_L39_00669538(void) {
    s32 i;
    O_00669538 *o;

    func_L39_00669B18_00669538();
    D_L39_0024D070 = 0;
    D_L39_0024D038 = D_001A5F78[0];
    func_L39_006692B0();
    if (D_L39_002412AC % 15 == 0) {
        func_L39_00669478(5);
    }
    for (i = 0; i < 50; i++) {
        if (D_L39_0033ACA0[i].b31 == 1 && (o = D_L39_0033ACA0[i].obj) != 0 && o->w90 != 0 && o->w68 != 0) {
            if (D_L39_0033ACA0[i].b30 != 0 && D_L39_0033ACA0[i].f2C != 0) {
                D_L39_0033ACA0[i].f2C();
            }
            if (D_L39_0033ACA0[i].f28 != 0) {
                D_L39_0033ACA0[i].f28(D_L39_0033ACA0[i].obj);
            }
            if ((o = D_L39_0033ACA0[i].obj) != 0 && o->hAA == 0x109D) {
                func_003C1A90(o);
                func_003C26C8(D_L39_0033ACA0[i].obj);
            }
            if (D_L39_0033ACA0[i].obj->f10 < 2.0f || D_L39_0033ACA0[i].obj->f10 > 1021.0f || D_L39_0033ACA0[i].obj->f14 < 2.0f ||
                D_L39_0033ACA0[i].obj->f14 > 1021.0f || D_L39_0033ACA0[i].obj->f18 < 2.0f || D_L39_0033ACA0[i].obj->f18 > 1021.0f) {
                func_L39_00669B68(D_L39_0033ACA0[i].w0);
            }
        }
    }
    func_L39_00669B18_00669538();
}
/* localdecomp:end func_L39_00669538 */
