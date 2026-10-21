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

INCLUDE_ASM("asm/levels", func_L12_003E6840);

INCLUDE_ASM("asm/levels", func_L12_003E6870);

/* localdecomp:start func_L12_003E6938 */
extern void func_L12_003E6160_003E6938(u8 *m, s32 b);
extern void func_L12_003E6938(void *p);
extern void func_L12_003E6938(void *);

 
void func_L12_003E6938(void *p) {
    ((void (*)(void *, s32))func_L12_003E6160_003E6938)(p, 0);
}
/* localdecomp:end func_L12_003E6938 */
