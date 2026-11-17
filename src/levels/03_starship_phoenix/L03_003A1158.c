#include "common.h"
#include "vu0.h"
void func_L03_003A1158(void *, s32);

typedef struct S_003A1158 { u8 pad0[0x34]; u16 h34; u8 pad36[0xD]; u8 b43; u8 pad44[0x24]; s32 *p68; u8 pad6c[0x50]; u8 bBC; } S_003A1158;
typedef struct Q_003A1158 { u8 pad[0x20]; f32 f20; f32 f24; f32 f28; u8 pad2c[0xC]; s32 w38; } Q_003A1158;
typedef struct P_003A1158 { u8 pad[0x150]; f32 pad150[8]; f32 f170; f32 f174; f32 f178; s32 w188; } P_003A1158;

/* localdecomp:start func_L03_003A1158 */
void func_003C3A10();
void func_L03_0032DA08(void *);
void func_L03_0032D6B8(void *);
s32 func_00382468();
void func_L01_004450F0();

void func_L03_003A1158(void *arg0, s32 arg1) {
    S_003A1158 *s = arg0;
    u8 *p;
    p = (u8 *)s->p68;
    switch (arg1) {
    case 1:
    case 2:
        if (s->b43 != 0) {
            func_003C3A10(s, 0, 0, 0);
        }
        break;
    case 3:
        s->h34 |= 0x5000;
        break;
    case 4:
        break;
    case 5:
        func_L03_0032DA08(s);
        *(s32 *)(p + 0x188) &= ~0x10;
        if (s->b43 != 0) {
            func_003C3A10(s, 0, 0, 2);
        }
        break;
    case 6:
        { f32 *q = (f32 *)(p + 0x150);
        q[8] = 0.020000001f;
        q[10] = 0.20000002f;
        q[9] = 0.020000001f;
        }
        if (s->b43 != 2) {
            func_003C3A10(s, 2, 0, 2);
        }
        break;
    case 7:
        func_L03_0032D6B8(s);
        if (s->b43 != 3) {
            func_003C3A10(s, 3, 0, 2);
        }
        break;
    case 8:
        if (s->b43 != 4) {
            func_003C3A10(s, 4, 0, 2);
        }
        break;
    case 9:
        { f32 *q = (f32 *)(p + 0x150);
        q[8] = 0.0012000001f;
        ((s32 *)q)[14] |= 0x10;
        q[10] = 0.060000002f;
        q[9] = 0.0012000001f;
        }
        func_L03_0032D6B8(s);
        if (s->b43 != 1) {
            func_003C3A10(s, 1, 0, 7);
        }
        break;
    case 10:
        s->bBC = 0xFF;
        *(s16 *)(p + 0x310) = func_00382468(0x32) + 0x32;
        *(s32 *)(p + 0x304) = 0;
        break;
    case 11:
        if (s->b43 != 5) {
            func_003C3A10(s, 5, 0, 2);
        }
        break;
    case 12:
        if (s->b43 != 0) {
            func_003C3A10(s, 0, 0, 2);
        }
        break;
    case 13:
        if (s->b43 != 6) {
            func_003C3A10(s, 6, 5, 2);
        }
        break;
    case 14:
        { f32 *q = (f32 *)(p + 0x150);
        q[8] = 0.00080000004f;
        ((s32 *)q)[14] |= 0x10;
        q[10] = 0.040000003f;
        q[9] = 0.00080000004f;
        }
        if (s->b43 != 1) {
            func_003C3A10(s, 1, 0, 2);
        }
        break;
    }
    func_L01_004450F0(s, arg1, -1);
}
/* localdecomp:end func_L03_003A1158 */
