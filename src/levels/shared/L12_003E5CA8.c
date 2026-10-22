#include "common.h"

typedef struct {
    void (*f0)(void *);
    void (*f4)(void *);
} S_3E40A0;

INCLUDE_ASM("asm/levels", func_L12_003E5CA8);

INCLUDE_ASM("asm/levels", func_L12_003E5F28);

/* localdecomp:start func_L12_003E6160 */

extern S_3E40A0 *func_L01_0043B548(s32, s32);
extern void func_003C2880(void *);

void func_L12_003E6160(u8 *m, s32 b) {
    if (*(s32 *)(*(u8 **)(m + 0x68) + 0x30) != 0) {
        S_3E40A0 *v = func_L01_0043B548(6625, 108);
        v->f0(m);
        if (b) {
            v->f4(m);
        }
    } else {
        func_003C2880(m);
    }
}
/* localdecomp:end func_L12_003E6160 */

INCLUDE_ASM("asm/levels", func_L12_003E61E0);

INCLUDE_ASM("asm/levels", func_L12_003E6790);

INCLUDE_ASM("asm/levels", func_L12_003E67F0);

/* localdecomp:start func_L12_003E6840 */
extern void *D_L12_001DF2F4;

void func_L12_003E6840(void) {
    void *temp_a0;
    void *var_v1;

    var_v1 = D_L12_001DF2F4;
    if (var_v1 != 0) {
        do {
            temp_a0 = *(void **)((u8 *)var_v1 + 0x68);
            if ((*(u8 *)((u8 *)temp_a0 + 0x60)) != 0) {
                *(s32 *)((u8 *)var_v1 + 0x98) = 0;
            }
            var_v1 = *(void **)((u8 *)temp_a0 + 0x64);
        } while (var_v1 != 0);
    }
}
/* localdecomp:end func_L12_003E6840 */

/* localdecomp:start func_L12_003E6870 */
void func_L12_003E6870(void *arg0, void *arg1) {
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    s32 temp_v0;
    void *temp_a0;
    void *temp_v1;

    temp_v1 = *(void **)((u8 *)arg1 + 0x68);
    temp_f1 = *(f32 *)((u8 *)temp_v1 + 4);
    temp_a0 = *(void **)((u8 *)arg0 + 0x68);
    if (temp_f1 != -1.0f) {
        *(f32 *)((u8 *)temp_a0 + 0x40) = temp_f1;
    } else {
        *(f32 *)((u8 *)temp_a0 + 0x40) = 1.0f;
    }
    temp_f1_2 = *(f32 *)((u8 *)temp_v1 + 0xC);
    if (temp_f1_2 != -1.0f) {
        *(f32 *)((u8 *)temp_a0 + 0x44) = temp_f1_2;
    } else {
        *(f32 *)((u8 *)temp_a0 + 0x44) = 1.0f;
    }
    temp_f1_3 = *(f32 *)((u8 *)temp_v1 + 0x60);
    if (temp_f1_3 != -1.0f) {
        *(f32 *)((u8 *)temp_a0 + 0x48) = temp_f1_3;
    } else {
        *(f32 *)((u8 *)temp_a0 + 0x48) = 1.0f;
    }
    temp_v0 = *(s32 *)((u8 *)temp_v1 + 0x1C);
    if (temp_v0 != 0) {
        *(s32 *)((u8 *)temp_a0 + 0x50) = temp_v0;
    }
    *(s32 *)((u8 *)temp_a0 + 0x54) = (s32) (*(s32 *)((u8 *)temp_v1 + 0x28));
    *(s32 *)((u8 *)temp_a0 + 0x58) = (s32) (*(s32 *)((u8 *)temp_v1 + 0x70));
}
/* localdecomp:end func_L12_003E6870 */

/* localdecomp:start func_L12_003E6938 */
extern void func_L12_003E6160_003E6938(u8 *m, s32 b);
extern void func_L12_003E6938(void *p);
extern void func_L12_003E6938(void *);

 
void func_L12_003E6938(void *p) {
    ((void (*)(void *, s32))func_L12_003E6160_003E6938)(p, 0);
}
/* localdecomp:end func_L12_003E6938 */
