#include "common.h"

/* localdecomp:start func_L21_003AFDA8 */
extern s32 func_L21_003E4720(void *);
extern void func_L21_0040F5A0(void *);
extern void func_L21_003DB978(void *, void *);
extern void func_L21_003AFFA0(void *, void *);
extern u8 D_L21_003B0358[];

/* Per-frame update of a moby with a tick counter at +0x7A: when the +0x78 timer is running and
 * finishes it calls func_L21_0040F5A0, after 121 ticks it starts the timer at 0xF, else it calls
 * func_L21_003AFFA0; then registers a draw callback. */
void func_L21_003AFDA8(void *object) {
    u8 *state = *(u8 **)((u8 *)object + 0x68);
    *(u16 *)(state + 0x7A) = *(u16 *)(state + 0x7A) + 1;
    if (*(s16 *)(state + 0x78) != 0 && func_L21_003E4720(state + 0x78) != 0) {
        func_L21_0040F5A0(object);
        return;
    }
    if ((s16)*(u16 *)(state + 0x7A) >= 0x79 && *(s16 *)(state + 0x78) == 0) {
        *(s16 *)(state + 0x78) = 0xF;
    } else {
        func_L21_003AFFA0(object, state);
    }
    func_L21_003DB978(D_L21_003B0358, object);
}
/* localdecomp:end func_L21_003AFDA8 */
