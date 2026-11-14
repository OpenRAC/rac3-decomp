#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L09_003C5F38 */
typedef int Q_003C5F38 __attribute__((mode(TI)));
extern u8 *D_L09_001E011C;
extern u8 D_001DE8D0_sda[8];
__asm__(".extern D_001DE8D0_sda, 8");
extern u8 D_001A4BE0[];
extern u8 *func_L01_00444358(void *, s32, s32);
extern void func_003DF7C0(s32);
extern void func_003883C8(void *);
extern void func_L09_003C4F18(void *);
extern void func_L09_003C5D58(void *, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L09_003C5B78(void *, s32, void *);
extern void func_L09_003C52C0(void *);
extern void func_L01_003EFFE0(s32, s32);
extern void func_L09_003C5DF8(void *);

void func_L09_003C5F38(u8 *obj) {
    u8 *vars = *(u8 **)(obj + 0x68);
    u8 *hit = func_L01_00444358(obj, 1, 0);
    Q_003C5F38 v;
    func_003DF7C0(30);
    func_003883C8(vars + 0x36);
    if (hit != 0) {
        if (*(s16 *)(vars + 0x36) <= 0) {
            if (obj[0xBC] != 9 && obj[0xBC] != 11 && obj[0xBC] != 10) {
                *(f32 *)(vars + 0x30) -= *(f32 *)(hit + 0x2C);
                func_L09_003C4F18(obj);
                *(s16 *)(vars + 0x36) = 60;
                if (*(f32 *)(vars + 0x30) < 0.0f) *(f32 *)(vars + 0x30) = 0.0f;
                if (*(f32 *)(vars + 0x30) <= 0.0f) {
                    obj[0xBC] = 9;
                    *(s16 *)(obj + 0x96) = 0;
                }
            }
        }
        obj[0xA8] = 255;
    }
    if (obj[0xBC] == 10) {
        if (*(u16 *)(obj + 0x96) >= 201) {
            s32 idx;
            u8 *q;
            if (*(s32 *)(vars + 0x7D4)) func_L09_003C5D58(obj, 1);
            *(s32 *)(obj + 0x98) = *(s32 *)(*(u8 **)(obj + 0x24) + 0x10);
            *(u16 *)(obj + 0x34) &= 0xFFBE;
            obj[0xBC] = 0;
            func_L01_00441FB8(obj, 1, -1);
            *(Q_003C5F38 *)(obj + 0x10) = *(Q_003C5F38 *)(*(u8 **)(vars + 0x6D0) + 0xE0);
            *(Q_003C5F38 *)(obj + 0xF0) = *(Q_003C5F38 *)(*(u8 **)(vars + 0x6D0) + 0xF0);
            *(f32 *)(vars + 0x30) = (f32)*(s16 *)(vars + 0x34);
            idx = *(s32 *)(vars + 0x758);
            if (idx != -1) {
                q = D_L09_001E011C + (idx << 8);
                *(u16 *)(q + 0x34) &= 0xFFBE;
                *(u16 *)(q + 0x34) |= *(u16 *)(*(u8 **)(q + 0x24) + 0x44) & 0x1000;
                *(s32 *)(q + 0x98) = *(s32 *)(*(u8 **)(q + 0x24) + 0x10);
            }
        }
    } else if (obj[0xBC] == 9) {
        func_L09_003C5B78(obj, 6, D_001DE8D0_sda);
        if (*(u16 *)(obj + 0x96) >= 91) {
            u8 *hero;
            obj[0xBC] = 10;
            func_L01_00441FB8(obj, 4, -1);
            *(s32 *)(obj + 0x98) = 0;
            *(u16 *)(obj + 0x34) |= 0x41;
            hero = D_001A4BE0;
            if (*(u8 **)(hero + 0x19E0) == obj) {
                qzero(&v);
                func_L09_003C52C0(obj);
                *(s32 *)(hero + 0x2850) = 0;
                *(s32 *)(vars + 0x7D4) = 1;
                func_L01_003EFFE0(0x1C, 0);
            } else {
                *(s32 *)(vars + 0x7D4) = 0;
            }
            func_L09_003C5DF8(obj);
        }
    }
}
/* localdecomp:end func_L09_003C5F38 */
