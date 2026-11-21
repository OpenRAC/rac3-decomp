#include "common.h"

/* NTSC-U counterpart of func_L39_00688108 (src/levels/39_multiplayer_menu/L39_006879E0.c) */
typedef struct S_006879E0_slot {
    u8 pad0[0xA4];
    u8 *fA4;
    u8 padA8[0x284 - 0xA8];
    s32 f284;
} S_006879E0_slot;
extern s32 *D_L39_0024D860;
extern u8 *D_001E1FD0_sda;
extern S_006879E0_slot *D_001DC1E4_sda;

/* localdecomp:start func_L39_006855C8 */
typedef struct S_00688108_in {
    s32 w[14];
} S_00688108_in;

typedef struct S_00688108_buf {
    S_00688108_in in;
    s32 w38;
    s32 w3C;
} S_00688108_buf;

typedef struct S_00688108_obj {
    u8 pad0[0x110];
    s32 ids[44];
    s32 kinds[44];
    s32 f270;
    u8 pad274[0x27C - 0x274];
    s32 f27C;
} S_00688108_obj;

typedef struct S_00688108_slot {
    u8 pad0[0x64];
    u8 *f64;
    u8 pad68[0x27C - 0x68];
    s32 f27C;
    u8 f280;
    u8 pad281[3];
    s32 f284;
} S_00688108_slot;

__asm__(".extern D_001DC1E4_sda, 4");
__asm__(".extern D_L39_0024D860, 16");
extern s32 func_L39_006D1928(s32);
extern s32 func_L01_003A2FD8(s32);
extern void func_L39_006D9F70(s32, s32);
extern void func_L39_006D62D8(void *);
extern void func_001986B8(void);
extern void *func_001375B0(void *, void *, s32);
extern s32 func_L39_0067C078(void);
extern void func_00195500(void);
extern void func_L39_00686F20(s32, void *);
extern int func_L39_0067C0B0(void);
extern void func_00199190(void);
extern void func_001986A0(void);

void func_L39_006855C8(S_00688108_obj *arg0, S_00688108_in *arg1, void *arg2) {
    S_00688108_buf buf;
    S_00688108_buf *b = &buf;
    s32 saved;
    S_00688108_slot *slot;
    s32 *g;
    u8 *p;
    s32 idx;
    s32 v;
    s32 k;

    slot = (S_00688108_slot *)D_001DC1E4_sda;
    b->in = *arg1;
    v = slot->f280;
    g = D_L39_0024D860;
    slot->f280 = 1;
    p = slot->f64;
    saved = v;
    v = func_L39_006D1928(D_L39_0024D860[0x3C / 4]);
    if (p[0x2B9] != 0) {
        func_L01_003A2FD8(g[0x30 / 4]);
    }
    if (p[0x2B8] != 0) {
        func_L39_006D9F70(g[0x50 / 4], 0);
    }
    func_L39_006D62D8(D_001E1FD0_sda);
    func_001986B8();
    func_001375B0(b, arg2, 0x40);
    if (b->in.w[0x30 / 4] != 5) {
        func_L39_0067C078();
    }
    do {
        func_00195500();
        func_001375B0(b, arg2, 0x40);
        idx = arg0->f270;
        func_L39_00686F20(arg0->ids[idx], arg2);
        if (func_L39_0067C0B0() > 30000) {
            break;
        }
    } while (b->in.w[0x30 / 4] != 5);
    D_001DC1E4_sda->f284 = 0x18;
    arg0->f27C = 0;
    func_00199190();
    func_001986A0();
    ((S_00688108_slot *)D_001DC1E4_sda)->f280 = saved;
}
/* localdecomp:end func_L39_006855C8 */
