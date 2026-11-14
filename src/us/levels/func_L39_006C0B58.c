#include "common.h"

/* NTSC-U counterpart of func_L39_006C3670 (src/levels/39_multiplayer_menu/L39_006C20B0.c) */
typedef struct {
    char pad0[0xE0];
    s16 hE0[8];
    s16 hF0[1];
} S_241640_006C2C40;
extern S_241640_006C2C40 *D_001D5F30_sda_006C0B58;
extern u8 D_001A5E50_006C0B58[0x16C] __attribute__((section(".data")));

/* localdecomp:start func_L39_006C0B58 */
/* Retail has two padding nops before the division. */
typedef struct {
    u8 name[8][16];
    u8 pad[0x60];
    s16 slot[8];
    u8 pad2[0x20];
    f32 a[8];
    f32 b[8];
} S_006C3670;
extern u8 D_001A6444[];
extern s32 func_L39_006C9748(s32, s32);
extern s32 func_L39_006DCA38(f32, f32);
extern void func_L39_006C97B8(s32, void *, s32);

void func_L39_006C0B58(void) {
    u8 *d = (u8 *)&D_001A5E50_006C0B58;
    s32 sum;
    s32 cnt;
    s32 i;
    s32 big;
    s32 v;
    if (d[0x168] == 0 || D_001D5F30_sda_006C0B58 == 0) {
        return;
    }
    sum = 0;
    cnt = 0;
    big = func_L39_006C9748(3, *(s32 *)(d + 0x5F4)) >= 8;
    for (i = 0; i < 8; i++) {
        S_006C3670 *t = (S_006C3670 *)D_001D5F30_sda_006C0B58;
        if (t->slot[i] != -1) {
            cnt++;
            sum += func_L39_006DCA38(t->a[i], t->b[i]);
        }
    }
    if (cnt > 0) {
        v = (f32)sum / (f32)cnt;
        func_L39_006C97B8(3, D_001A6444, big ? v + 8 : v);
    }
}
/* localdecomp:end func_L39_006C0B58 */
