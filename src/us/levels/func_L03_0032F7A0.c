#include "common.h"

/* NTSC-U counterpart of func_L03_0032FE70 (src/levels/03_starship_phoenix/L03_0032FBA8.c).
 * In the buttons & 0x40 arm 'r = 1' is written AFTER the last call: with r = 1 right after func_0039FF28(4, 0, 0)
 * sched2 orders the argument moves a0, a1, a2 instead of retail's a2, a0, a1 (3 differing words). */

/* localdecomp:start func_L03_0032F7A0 */
extern u8 *D_001D52FC;
extern u8 *D_001DD144_sda;
__asm__(".extern D_001DD144_sda, 4");
extern u8 D_001DD148_sda;
__asm__(".extern D_001DD148_sda, 1");
extern u8 D_001DD149_sda;
__asm__(".extern D_001DD149_sda, 1");
extern s32 D_L03_001DF594;
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003A2F98(void *);
extern s32 func_0039FF28(s32, s32, s32);
extern void func_L03_0032FA70(void *);
extern void func_L03_0032C940(void *, s32);
extern void func_L01_00512568(s32, f32 *, f32 *);
extern s32 func_L01_00512480(s32, f32, f32);
extern s32 func_003894A0(s32, s32, f32);
extern s32 func_L01_005130C8(s32, s32);

s32 func_L03_0032F7A0(void) {
    s32 r;
    u8 *self;
    u8 *st;
    s32 buttons;
    s32 id;
    f32 t;
    f32 u;
    f32 w;
    f32 buf[2];

    r = 0;
    self = D_001DD144_sda;
    st = *(u8 **)(self + 0x68);
    if (*(s32 *)(D_001D52FC + 0x1C4) & 0x10) {
        D_L03_001DF594 = 2;
        func_L01_00441FB8(self, 12, -1);
        r = 1;
        func_003A2F98(D_001D52FC);
    }
    buttons = *(s32 *)(D_001D52FC + 0x1C4);
    if (buttons & 0x1000) {
        if (D_001DD149_sda != 0) {
            func_0039FF28(3, 0, 0);
            D_001DD149_sda = D_001DD149_sda - 1;
            if (D_001DD149_sda < D_001DD148_sda) {
                D_001DD148_sda = D_001DD148_sda - 1;
            }
            func_L03_0032FA70(self);
            func_003A2F98(D_001D52FC);
        }
    } else if (buttons & 0x4000) {
        if (D_001DD149_sda < st[0x112] - 1) {
            func_0039FF28(3, 0, 0);
            D_001DD149_sda = D_001DD149_sda + 1;
            if (D_001DD149_sda - D_001DD148_sda >= 5) {
                D_001DD148_sda = D_001DD148_sda + 1;
            }
            func_L03_0032FA70(self);
            func_003A2F98(D_001D52FC);
        }
    } else if (buttons & 0x40) {
        D_L03_001DF594 = 2;
        func_0039FF28(4, 0, 0);
        func_L03_0032C940(self, st[0xFF]);
        func_003A2F98(D_001D52FC);
        r = 1;
    }
    w = *(f32 *)(st + 0x100) + 0.05f;
    *(f32 *)(st + 0x100) = w;
    if (2.0f < w) {
        *(f32 *)(st + 0x100) = w - 2.0f;
    }
    id = 0x470024 + (D_001DD149_sda - D_001DD148_sda);
    func_L01_00512568(id, &buf[0], &buf[1]);
    func_L01_00512480(0x470023, buf[0], buf[1]);
    t = *(f32 *)(st + 0x100);
    u = (t <= 1.0f) ? t : 2.0f - t;
    func_L01_005130C8(id, func_003894A0(0x66D6EEFA, 0x80FFFFFF, u));
    return r;
}
/* localdecomp:end func_L03_0032F7A0 */
