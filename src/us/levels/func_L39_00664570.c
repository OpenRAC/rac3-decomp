#include "common.h"

/* NTSC-U counterpart of func_L39_00666E48 (src/levels/shared/L39_00665C18.c) */
/* localdecomp:start func_L39_00664570 */
typedef struct Ply_00666E48 {
    u8 pad0[0x1A14];
    u8 b1A14;
    u8 pad1A15[0x2524 - 0x1A15];
    void *p2524;
    u8 pad2528[0x2558 - 0x2528];
    void *p2558;
} Ply_00666E48;
typedef struct Slf_00666E48 {
    s32 w0;
    u8 pad4[0x1B0 - 4];
    u8 a1B0[1];
} Slf_00666E48;
typedef struct Glb_00666E48 {
    u8 pad0[0x7D5];
    u8 b7D5[8];
} Glb_00666E48;

extern Ply_00666E48 *D_L39_0024CF20[8] __attribute__((section(".sdata")));
extern Glb_00666E48 D_001A5E50;
extern s32 func_00197638(void);
extern void func_L39_0066DA60(void *);
extern void func_L39_0063DE28(void *);
extern void func_L39_00619AE0(void *);
extern void func_003BD360(void *);
extern void func_L39_00665B20(void *, s32);
extern void func_L39_00669CA8(void);
extern void func_L39_0066AAA0(s32, s32);

void func_L39_00664570(Slf_00666E48 *self) {
    s32 i;
    Ply_00666E48 *p;
    Ply_00666E48 *q;

    for (i = 0; i < 8; i++) {
        p = D_L39_0024CF20[i];
        if (p != 0 && p->p2558 != 0 && p->p2558 == self && (p->b1A14 == 0 || func_00197638() == 0)) {
            q = D_L39_0024CF20[i];
            if (D_001A5E50.b7D5[i] != 2) {
                D_001A5E50.b7D5[i] = 2;
                func_L39_0066DA60(self->a1B0);
            }
            func_L39_0063DE28(q);
            func_L39_00619AE0(q->p2524);
            func_003BD360(q->p2524);
            q->p2524 = 0;
            q->p2558 = 0;
            D_L39_0024CF20[i] = 0;
            func_L39_00665B20(q, self->w0);
            func_L39_00669CA8();
            func_L39_0066AAA0(i, self->w0);
            return;
        }
    }
}
/* localdecomp:end func_L39_00664570 */
