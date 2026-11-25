#include "common.h"
#include "vu0.h"

typedef int s128 __attribute__((mode(TI)));
typedef struct {
    u8 pad0[124];
    s32 f124;
    u8 pad128[8];
    s32 f136;
    u8 pad140[20];
} Sub_0034CC80;
typedef struct {
    u8 pad0[48];
    Sub_0034CC80 sub;
} Entry_0034CC80;

/* localdecomp:start func_L01_0034D078 */
typedef struct {
    s128 q0;
    s128 q10;
    u8 pad20[0x20];
    s128 pos;
    s128 dir;
    f32 rot[3];
    f32 rotSpeed[3];
    f32 scale[3];
    f32 rot2[3];
    f32 rotSpeed2[3];
    f32 scale2[3];
    s32 xA8;
    s32 xAC;
    s32 xB0;
    s32 xB4;
    s32 xB8;
    s32 xBC;
    s32 xC0;
    s32 xC4;
    f32 xC8;
    s32 xCC;
} Slot_0034D078;

extern Entry_0034CC80 D_L01_0027FB20[];
extern f32 func_003824E0(f32, f32);
extern f32 func_L01_00443A18(f32, f32);

void func_L01_0034D078(s32 a0, s32 a1, s32 a2, s128 *pos, s128 *dir, s32 t1, s32 t2, s32 t3, f32 f, s32 s0)
{
    s32 i;
    Slot_0034D078 *e;
    Slot_0034D078 *base = (Slot_0034D078 *)D_L01_0027FB20;

    for (i = 0; i < 48; i++) {
        e = &base[i];
        if (e->xAC == 0) {
            e->xAC = a0;
            e->pos = *pos;
            e->dir = *dir;
            e->rot[0] = func_003824E0(-3.14159274f, 3.14159274f);
            e->rot[1] = func_003824E0(-3.14159274f, 3.14159274f);
            e->rot[2] = func_003824E0(-3.14159274f, 3.14159274f);
            e->rot2[0] = func_003824E0(-3.14159274f, 3.14159274f);
            e->rot2[1] = func_003824E0(-3.14159274f, 3.14159274f);
            e->rot2[2] = func_003824E0(-3.14159274f, 3.14159274f);
            e->rotSpeed[0] = func_L01_00443A18(0.001f, 0.005f);
            e->rotSpeed[1] = func_L01_00443A18(0.001f, 0.005f);
            e->rotSpeed[2] = func_L01_00443A18(0.001f, 0.005f);
            e->rotSpeed2[0] = func_L01_00443A18(0.001f, 0.005f);
            e->rotSpeed2[1] = func_L01_00443A18(0.001f, 0.005f);
            e->rotSpeed2[2] = func_L01_00443A18(0.001f, 0.005f);
            e->scale[0] = func_003824E0(3.25f, 4.75f);
            e->scale[1] = func_003824E0(3.25f, 4.75f);
            e->scale[2] = func_003824E0(3.25f, 4.75f);
            e->scale2[0] = func_003824E0(3.25f, 4.75f);
            e->scale2[1] = func_003824E0(3.25f, 4.75f);
            e->scale2[2] = func_003824E0(3.25f, 4.75f);
            e->xBC = t2;
            e->xB0 = a2;
            e->xB4 = a1;
            e->xC4 = t1;
            e->xC0 = 0;
            e->xC8 = f;
            qzero(&e->q0);
            e->xB8 = t2;
            e->xA8 = t3;
            qzero(&e->q10);
            e->xCC = s0;
            return;
        }
    }
}
/* localdecomp:end func_L01_0034D078 */
