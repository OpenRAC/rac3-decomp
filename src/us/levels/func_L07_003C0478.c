#include "common.h"

/* localdecomp:start func_L07_003C0478 */
extern void func_L07_00474888(s32);
extern void func_L07_00476A68(void);
extern void func_L07_00476FD8(void);
extern void func_L07_003EAAD0(s32, void *, void *, s32, s32, s32);
extern void func_L07_003EA9E8(s32, void *);
extern void func_L07_003EAA58(s32, void *);
extern void func_L07_00442528(s32, s32, s32);
extern u8 D_L07_001E1EC0[];
extern s32 D_001DE5A0;
extern s32 D_001DE5B0;

void func_L07_003C0478(s32 object) {
    func_L07_00474888(object);
    func_L07_00476A68();
    func_L07_00476FD8();
    func_L07_003EAAD0(0, D_L07_001E1EC0, D_L07_001E1EC0 + 0x10, 2, 0xC8, 0);
    func_L07_003EA9E8(0, &D_001DE5A0);
    func_L07_003EAA58(0, &D_001DE5B0);
    func_L07_00442528(object, 3, -1);
}
/* localdecomp:end func_L07_003C0478 */
