#include "common.h"

/* NTSC-U counterpart of func_L39_005732E0 (src/levels/shared/L39_00573208.c): 25 -> 30 */
/* localdecomp:start func_L39_005725B8 */
typedef int Q_005732E0 __attribute__((mode(TI)));

typedef struct {
    u8 pad0[0x84];
    s16 h84;
    u8 pad86[0x94 - 0x86];
    s32 w94;
} Obj_005732E0;

typedef struct {
    u8 pad0[0x1C];
    u8 *p1C;
    u8 pad20[0x20 - 0x20];
} Slot_005732E0;

typedef struct {
    u8 pad0[0x20];
    s32 arr[9];
    u8 pad44[0x44 - 0x44];
    s16 h44;
    s16 h46;
    s16 h48;
} Sub_005732E0;

extern Slot_005732E0 *D_L39_0024B950;
extern u8 *D_L39_0024C100;
extern s32 func_L39_005B24C8(s32 a, s32 b);
extern void func_0038CC88_005725B8(void *, void *, s32);

void func_L39_005725B8(Obj_005732E0 *self) {
    Sub_005732E0 *o;
    s32 *arr;
    u8 *q;
    u8 *src;
    s32 cnt;
    s32 i;
    if (self->w94 > 0) return;
    o = (Sub_005732E0 *)D_L39_0024B950[self->h84].p1C;
    arr = o->arr;
    cnt = 0;
    q = (u8 *)self + 0x74;
    for (i = 0; i < 9; i++) {
        if (arr[i] != -1) cnt++;
    }
    if (cnt == 1) {
        i = 0;
    } else {
        i = func_L39_005B24C8(0, cnt - 1);
    }
    if (*(s32 *)((u8 *)arr + (i << 2)) == -1) i = 0;
    if (*(s32 *)((u8 *)arr + (i << 2)) != -1) {
        src = D_L39_0024C100 + (*(s32 *)((u8 *)arr + (i << 2)) << 7);
        *(Q_005732E0 *)((u8 *)self + 0x30) = *(Q_005732E0 *)(src + 0x30);
        *(Q_005732E0 *)((u8 *)self + 0x40) = *(Q_005732E0 *)(src + 0x70);
        func_0038CC88_005725B8(self, src, 0x30);
    }
    *(s16 *)(q + 0xA) = 0;
    o->h44 = 0x1E;
    o->h48 = 0;
    o->h46 = 0;
}
/* localdecomp:end func_L39_005725B8 */
