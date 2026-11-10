#include "common.h"

/* localdecomp:start func_L07_003DA1A8 */
void func_L01_00402498(void *, void *);
s32 func_L01_00452EC8(void *);
void func_L07_003DA448(void *);
void func_L07_003DAA68(void *);
extern s32 D_L07_001DE948;
extern s32 D_L07_001DE968;
extern u8 D_L07_003DACC0[];

void func_L07_003DA1A8(void *arg0) {
    u16 temp_v1_2;
    u8 temp_v1;
    void *temp_s1;

    temp_v1 = *(u8 *)((u8 *)arg0 + 0x20);
    temp_s1 = *(void **)((u8 *)arg0 + 0x68);
    switch (temp_v1) {                              /* irregular */
    case 0:
        if (func_L01_00452EC8(arg0) != 0) {
            *(void **)((u8 *)temp_s1 + 0x114) = &D_L07_001DE948;
        }
        if ((u16) (*(u16 *)((u8 *)arg0 + 0x96)) >= 0x15U) {
            *(void **)((u8 *)temp_s1 + 0x110) = &D_L07_001DE948;
        }
        break;
    case 1:
        if (func_L01_00452EC8(arg0) != 0) {
            *(void **)((u8 *)temp_s1 + 0x114) = &D_L07_001DE968;
        }
        if ((u16) (*(u16 *)((u8 *)arg0 + 0x96)) >= 0x15U) {
            *(void **)((u8 *)temp_s1 + 0x110) = &D_L07_001DE968;
        }
        func_L07_003DAA68(arg0);
        break;
    }
    func_L07_003DA448(arg0);
    func_L01_00402498(D_L07_003DACC0, arg0);
    temp_v1_2 = *(u16 *)((u8 *)arg0 + 0x96);
    if (temp_v1_2 <= 0xFFFEU) {
        *(u16 *)((u8 *)arg0 + 0x96) = (u16) (temp_v1_2 + 1);
    }
}
/* localdecomp:end func_L07_003DA1A8 */
