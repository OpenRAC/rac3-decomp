#include "common.h"

/* NTSC-U counterpart of func_L07_003C1528 (src/levels/07_annihilation_nation/L07_003C1528.c): pulse step
 * 0.06f -> 0.05f (60 Hz), $gp slots 0x40 higher (D_001DE590_sda, D_L07_001DE594/5) */
/* localdecomp:start func_L07_003BFBD8 */
typedef struct {
    u8 b0;
    u8 pad1;
    s16 h2;
    u8 pad4[0x20];
} E_003BFBD8;
extern u8 *D_001DE590_sda;
__asm__(".extern D_001DE590_sda, 4");
extern u8 D_L07_001DE594;
__asm__(".extern D_L07_001DE594, 1");
extern u8 D_L07_001DE595;
__asm__(".extern D_L07_001DE595, 1");
extern E_003BFBD8 D_L07_002BC920[];
extern u8 *D_001D52FC;
extern u8 D_00142CA0[];
extern s32 func_L01_0044F2E8(s32, s32, s32, s32, s32, s32, s32);
extern void func_0039FF28(s32, s32, s32);
extern void func_003A2F98(void *);
extern void func_L07_003BFE70(void *);
extern void func_L07_003BF3B0(s32);
extern s32 func_L07_00334330(s32);
extern void func_L07_003BF5F0(u8 *);
extern void func_L01_00512568(s32, f32 *, f32 *);
extern s32 func_L01_00512480(s32, f32, f32);
extern s32 func_003894A0(s32, s32, f32);
extern s32 func_L01_005130C8(s32, s32);

s32 func_L07_003BFBD8(void) {
    u8 *self;
    u8 *st;
    s32 r;
    u32 buttons;
    s32 id;
    f32 t;
    f32 u;
    f32 w;
    f32 buf[2];

    self = D_001DE590_sda;
    st = *(u8 **)(self + 0x68);
    r = 0;
    func_L01_0044F2E8(0, 5, 0, 1, 0, 0, 0);
    buttons = *(u32 *)(D_001D52FC + 0x1C4);
    if (buttons & 0x1000) {
        if (D_L07_001DE594 != 0) {
            func_0039FF28(3, 0, 0);
            D_L07_001DE594 = D_L07_001DE594 - 1;
            if (D_L07_001DE594 < D_L07_001DE595) {
                D_L07_001DE595 = D_L07_001DE595 - 1;
            }
            func_L07_003BFE70(self);
        }
        func_003A2F98(D_001D52FC);
    } else if (buttons & 0x4000) {
        if (D_L07_001DE594 < st[0x39] + st[0x3A] - 1) {
            func_0039FF28(3, 0, 0);
            D_L07_001DE594 = D_L07_001DE594 + 1;
            if (D_L07_001DE594 - D_L07_001DE595 >= 5) {
                D_L07_001DE595 = D_L07_001DE595 + 1;
            }
            func_L07_003BFE70(self);
        }
        func_003A2F98(D_001D52FC);
    } else if (buttons & 0x10) {
        r = 1;
        func_L07_003BF3B0((s32)self);
        func_003A2F98(D_001D52FC);
    } else if (buttons & 0x40) {
        E_003BFBD8 *e = &D_L07_002BC920[st[0x38]];
        if (e->b0 == 0) {
            s32 idx = func_L07_00334330(e->h2);
            if (idx != -1 && D_00142CA0[idx] == 0) {
                func_0039FF28(5, 0, 0);
                return 2;
            }
        }
        func_0039FF28(4, 0, 0);
        func_L07_003BF5F0(self);
        func_003A2F98(D_001D52FC);
        r = 3;
    }
    w = *(f32 *)(st + 0x28) + 0.05f;
    *(f32 *)(st + 0x28) = w;
    if (2.0f < w) {
        *(f32 *)(st + 0x28) = w - 2.0f;
    }
    id = 0x470024 + (D_L07_001DE594 - D_L07_001DE595);
    func_L01_00512568(id, &buf[0], &buf[1]);
    func_L01_00512480(0x470023, buf[0], buf[1]);
    t = *(f32 *)(st + 0x28);
    u = (t <= 1.0f) ? t : 2.0f - t;
    func_L01_005130C8(id, func_003894A0(0x66D6EEFA, 0x80FFFFFF, u));
    return r;
}
/* localdecomp:end func_L07_003BFBD8 */
