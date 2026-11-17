#include "common.h"

typedef struct { u8 pad0[0x68]; struct { u8 pad[4]; s32 idx; } *p68; } O_B;

/* declared by functions of L07_003C0710.c, which this file was cut from */
extern u8 *D_001DE550_sda;
extern void func_L07_003C17C0(void *);
extern void func_L07_003C0F40(u8 *);
typedef struct {
    u8 b0;
    u8 pad1;
    s16 h2;
    u8 pad4[0x20];
} E_003C0F40;
extern E_003C0F40 D_L07_002BC920_003C0F40[];
extern u8 D_L07_001DE554;
extern u8 D_L07_001DE555;

/* localdecomp:start func_L07_003C1528 */
/* from rac3-decomp's func_L03_0032FE70 */
extern u8 *D_001D52FC;
extern u8 D_00142CA0[];
__asm__(".extern D_001DE550_sda, 4");
__asm__(".extern D_L07_001DE554, 1");
__asm__(".extern D_L07_001DE555, 1");
extern s32 func_L01_00452560(s32, s32, s32, s32, s32, s32, s32);
extern void func_003A5348(s32, s32, s32);
extern void func_003A2CD8(void *);
extern void func_L01_00516558(s32, f32 *, f32 *);
extern s32 func_L01_00516470(s32, f32, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern s32 func_L01_005170B8(s32, s32);

s32 func_L07_003C1528(void) {
    u8 *self;
    u8 *st;
    s32 r;
    u32 buttons;
    s32 id;
    f32 t;
    f32 u;
    f32 w;
    f32 buf[2];

    self = D_001DE550_sda;
    st = *(u8 **)(self + 0x68);
    r = 0;
    func_L01_00452560(0, 5, 0, 1, 0, 0, 0);
    buttons = *(u32 *)(D_001D52FC + 0x1C4);
    if (buttons & 0x1000) {
        if (D_L07_001DE554 != 0) {
            func_003A5348(3, 0, 0);
            D_L07_001DE554 = D_L07_001DE554 - 1;
            if (D_L07_001DE554 < D_L07_001DE555) {
                D_L07_001DE555 = D_L07_001DE555 - 1;
            }
            func_L07_003C17C0(self);
        }
        func_003A2CD8(D_001D52FC);
    } else if (buttons & 0x4000) {
        if (D_L07_001DE554 < st[0x39] + st[0x3A] - 1) {
            func_003A5348(3, 0, 0);
            D_L07_001DE554 = D_L07_001DE554 + 1;
            if (D_L07_001DE554 - D_L07_001DE555 >= 5) {
                D_L07_001DE555 = D_L07_001DE555 + 1;
            }
            func_L07_003C17C0(self);
        }
        func_003A2CD8(D_001D52FC);
    } else if (buttons & 0x10) {
        r = 1;
        func_L07_003C0D00((s32)self);
        func_003A2CD8(D_001D52FC);
    } else if (buttons & 0x40) {
        E_003C0F40 *e = &D_L07_002BC920_003C0F40[st[0x38]];
        if (e->b0 == 0) {
            s32 idx = func_L07_00334A70(e->h2);
            if (idx != -1 && D_00142CA0[idx] == 0) {
                func_003A5348(5, 0, 0);
                return 2;
            }
        }
        func_003A5348(4, 0, 0);
        func_L07_003C0F40(self);
        func_003A2CD8(D_001D52FC);
        r = 3;
    }
    w = *(f32 *)(st + 0x28) + 0.060000002f;
    *(f32 *)(st + 0x28) = w;
    if (2.0f < w) {
        *(f32 *)(st + 0x28) = w - 2.0f;
    }
    id = 0x470024 + (D_L07_001DE554 - D_L07_001DE555);
    func_L01_00516558(id, &buf[0], &buf[1]);
    func_L01_00516470(0x470023, buf[0], buf[1]);
    t = *(f32 *)(st + 0x28);
    u = (t <= 1.0f) ? t : 2.0f - t;
    func_L01_005170B8(id, func_0038DBD8(0x66D6EEFA, 0x80FFFFFF, u));
    return r;
}
/* localdecomp:end func_L07_003C1528 */

INCLUDE_ASM("asm/levels", func_L07_003C17C0);
