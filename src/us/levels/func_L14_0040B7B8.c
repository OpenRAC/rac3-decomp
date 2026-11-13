#include "common.h"

/* localdecomp:start func_L14_0040B7B8 */
typedef struct {
    u8 pad0[0x20];
    void *f20;
    u8 pad24[0xC];
    s32 f30;
} Base_L14_0040B7B8;
typedef struct {
    u8 pad0[0x30];
    s32 f30;
    s32 f34;
} State_L14_0040B7B8;
typedef struct {
    u8 pad0[0x38];
    s32 lo;
    s32 hi;
} Rec_L14_0040B7B8;

extern Base_L14_0040B7B8 D_L14_002E85A0;
extern State_L14_0040B7B8 D_L14_001E6480_0040B7B8;
extern Rec_L14_0040B7B8 D_L14_002E8710;
extern Rec_L14_0040B7B8 D_L14_002E8650;
extern Rec_L14_0040B7B8 D_L14_002E85F0;
extern Rec_L14_0040B7B8 D_L14_002E86B0;
extern s32 D_001D545C;
extern u8 D_L14_001D6AB0;
extern f32 D_L14_001D6B44;
extern u8 D_L14_001D6AA5;
extern u8 D_L14_001D6B70;
__asm__(".extern D_L14_001D6AB0, 4");
__asm__(".extern D_L14_001D6B44, 4");
__asm__(".extern D_L14_001D6AA5, 1");
__asm__(".extern D_L14_001D6B70, 4");
extern void func_L01_004203A8(void *, void *, s32, s32, s32, s32, s32);

void func_L14_0040B7B8(void) {
    Rec_L14_0040B7B8 *rec = 0;
    void *extra = 0;

    D_L14_001D6B44 = 1.0f;
    D_L14_002E85A0.f20 = &D_L14_001D6AB0;
    D_L14_002E85A0.f30 = 1;
    D_L14_001D6AA5 = 0;
    if (D_001D545C == 0xE && D_L14_001E6480_0040B7B8.f30 == 1) {
        if (D_L14_001E6480_0040B7B8.f34 >= D_L14_002E8710.lo && D_L14_001E6480_0040B7B8.f34 <= D_L14_002E8710.hi) {
            extra = &D_L14_001D6B70;
            rec = &D_L14_002E8710;
        } else if (D_L14_001E6480_0040B7B8.f34 < D_L14_002E8650.lo) {
            rec = &D_L14_002E85F0;
        } else if (D_L14_001E6480_0040B7B8.f34 < D_L14_002E86B0.lo) {
            rec = &D_L14_002E8650;
        } else {
            rec = &D_L14_002E86B0;
        }
    }
    if (rec != 0) {
        func_L01_004203A8(rec, extra, 0, 0, 0, 1, 0);
    }
}
/* localdecomp:end func_L14_0040B7B8 */
