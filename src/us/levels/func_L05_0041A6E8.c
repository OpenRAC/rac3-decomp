#include "common.h"

/* localdecomp:start func_L05_0041A6E8 */
typedef struct {
    u8 pad_0[0x20];
    void *f20;
    u8 pad_24[0xC];
    s32 f30;
} Tbl_41A6E8;

typedef struct {
    u8 pad_0[0x30];
    s32 f30;
    s32 f34;
} Sel_41A6E8;

typedef struct {
    u8 pad_0[0x3C];
    s32 f3C;
} Ent_41A6E8;

extern f32 D_L05_001D6B44;
__asm__(".extern D_L05_001D6B44, 4");
extern s32 D_L05_001D6AB0;
__asm__(".extern D_L05_001D6AB0, 4");
extern u8 D_L05_001D6AA5;
__asm__(".extern D_L05_001D6AA5, 1");
extern u8 D_L05_001D6AA4;
__asm__(".extern D_L05_001D6AA4, 1");
extern s32 D_L05_001D6B88;
__asm__(".extern D_L05_001D6B88, 4");
extern s32 D_L05_001D6B70;
__asm__(".extern D_L05_001D6B70, 4");
extern s32 D_L05_001D6BA0;
__asm__(".extern D_L05_001D6BA0, 4");
extern s32 D_L05_001D6BB8;
__asm__(".extern D_L05_001D6BB8, 4");
extern s32 D_L05_001D6B74;
extern s32 D_001D545C;
extern Tbl_41A6E8 D_L05_002E92E0;
extern Sel_41A6E8 D_L05_001E6AC0;
extern u8 D_L05_002E9330[];
extern Ent_41A6E8 D_L05_002E93A0;
extern u8 D_L05_002E9400[];
extern u8 D_L05_002E9460[];
extern void func_L01_004203A8(void *, void *, void *, s32, s32, s32, s32);
extern void func_L03_0040DA90(void *, void *, void *, s32);

void func_L05_0041A6E8(void) {
    void *obj = 0;
    void *src = 0;
    void *dst = 0;
    void *other = 0;
    s32 flag = 0;

    D_L05_001D6B44 = 1.0f;
    D_L05_002E92E0.f20 = &D_L05_001D6AB0;
    D_L05_002E92E0.f30 = 1;
    D_L05_001D6AA5 = 0;
    if (D_001D545C == 5) {
        switch (D_L05_001E6AC0.f30) {
        case 0:
            other = D_L05_002E9330;
            dst = &D_L05_001D6B88;
            if (D_L05_001E6AC0.f34 < D_L05_001D6B74) {
                dst = &D_L05_001D6B70;
            }
            break;
        case 1:
            D_L05_001D6B44 = -1.0f;
            if (D_L05_001E6AC0.f34 < D_L05_002E93A0.f3C) {
                obj = &D_L05_002E93A0;
            } else {
                obj = D_L05_002E9400;
            }
            break;
        case 2:
            D_L05_001D6AA4 = 1;
            other = D_L05_002E9460;
            if (D_L05_001E6AC0.f34 >= D_L05_001D6BB8) {
                flag = 1;
            } else {
                dst = &D_L05_001D6BA0;
            }
            src = &D_L05_001D6BB8;
            break;
        }
    }
    if (obj != 0) {
        func_L01_004203A8(obj, dst, src, flag, 0, 1, 0);
    } else if (other != 0) {
        func_L03_0040DA90(other, dst, src, flag);
    }
}
/* localdecomp:end func_L05_0041A6E8 */
