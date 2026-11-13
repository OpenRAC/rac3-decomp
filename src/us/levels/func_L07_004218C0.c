#include "common.h"

/* localdecomp:start func_L07_004218C0 */
typedef struct {
    u8 pad0[0x20];
    void *f20;
    u8 pad24[0xC];
    s32 f30;
} Base_L07_004218C0;
typedef struct {
    u8 pad0[0x30];
    u32 f30;
    s32 f34;
} State_L07_004218C0;
typedef struct {
    u8 pad0[0x40];
    s32 f40;
} RecE_L07_004218C0;
typedef struct {
    u8 pad0[0xAA];
    s16 fAA;
} Obj_L07_004218C0;

extern Base_L07_004218C0 D_L07_002E8560;
extern State_L07_004218C0 D_L07_001E6200;
extern RecE_L07_004218C0 D_L07_002E85B0;
extern RecE_L07_004218C0 D_L07_002E8620;
extern RecE_L07_004218C0 D_L07_002E8680;
extern RecE_L07_004218C0 D_L07_002E86E0;
extern RecE_L07_004218C0 D_L07_002E88A0;
extern s32 D_001D545C;
extern u8 D_L07_001D6AB0;
extern f32 D_L07_001D6B44;
extern u8 D_L07_001D6AA5;
extern u8 D_L07_001D6B88;
extern u8 D_L07_001D6B70;
extern s32 D_L07_001D6BA0;
extern s32 D_L07_001D6B74;
extern Obj_L07_004218C0 *D_L07_001DF41C_004218C0;
extern Obj_L07_004218C0 *D_L07_001DF420;
__asm__(".extern D_L07_001D6AB0, 4");
__asm__(".extern D_L07_001D6B44, 4");
__asm__(".extern D_L07_001D6AA5, 1");
__asm__(".extern D_L07_001D6B88, 4");
__asm__(".extern D_L07_001D6B70, 4");
__asm__(".extern D_L07_001D6BA0, 4");
extern void func_L01_004203A8(void *, void *, s32, s32, s32, s32, s32);
extern void func_L03_0040DA90(void *, void *, s32, s32);

void func_L07_004218C0(void) {
    RecE_L07_004218C0 *rec = 0;
    void *extra = 0;
    void *rec2 = 0;
    Obj_L07_004218C0 *o;
    s32 n;

    D_L07_001D6B44 = 1.0f;
    D_L07_002E8560.f20 = &D_L07_001D6AB0;
    D_L07_002E8560.f30 = 1;
    D_L07_001D6AA5 = 0;
    if (D_001D545C == 7) {
        switch (D_L07_001E6200.f30) {
        case 0:
            rec2 = &D_L07_002E85B0;
            extra = (D_L07_001E6200.f34 <= D_L07_001D6B74) ? &D_L07_001D6B70 : &D_L07_001D6B88;
            break;
        case 1:
            rec = &D_L07_002E8620;
            break;
        case 2:
            rec = &D_L07_002E8680;
            break;
        case 3:
            if (D_L07_001E6200.f34 >= D_L07_001D6BA0) {
                extra = &D_L07_001D6BA0;
                rec2 = &D_L07_002E85B0;
            }
            break;
        case 4:
            o = D_L07_001DF41C_004218C0;
            D_L07_002E8560.f20 = &D_L07_002E86E0;
            rec = &D_L07_002E88A0;
            n = 0;
            for (; o < D_L07_001DF420; o = (Obj_L07_004218C0 *)((u8 *)o + 0x100)) {
                if (o != 0 && o->fAA == rec->f40) {
                    func_L01_004203A8(rec, 0, 0, 0, (s32)o, 7, n);
                    n++;
                }
            }
            rec = 0;
            break;
        }
    }
    if (rec != 0) {
        func_L01_004203A8(rec, extra, 0, 0, 0, 1, 0);
    } else if (rec2 != 0) {
        func_L03_0040DA90(rec2, extra, 0, 0);
    }
}
/* localdecomp:end func_L07_004218C0 */
