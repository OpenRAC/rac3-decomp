#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L21_003B1960 */
s32 func_0038CB00(void *);
void func_003C2880(void *);
void func_L01_00404808(void *, void *);
void func_L21_003B1B58(void *, void *);
extern u8 D_L21_003B1F10[];

void func_L21_003B1960(void *arg0) {
    void *temp_s0;

    temp_s0 = *(void **)((u8 *)arg0 + 0x68);
    *(u16 *)((u8 *)temp_s0 + 0x7A) = (u16) ((*(u16 *)((u8 *)temp_s0 + 0x7A)) + 1);
    if (((*(s16 *)((u8 *)temp_s0 + 0x78)) != 0) && (func_0038CB00(temp_s0 + 0x78) != 0)) {
        func_003C2880(arg0);
        return;
    }
    if (((s16) (*(u16 *)((u8 *)temp_s0 + 0x7A)) >= 0x79) && ((*(s16 *)((u8 *)temp_s0 + 0x78)) == 0)) {
        *(s16 *)((u8 *)temp_s0 + 0x78) = 0xC;
    } else {
        func_L21_003B1B58(arg0, temp_s0);
    }
    func_L01_00404808(D_L21_003B1F10, arg0);
}
/* localdecomp:end func_L21_003B1960 */
