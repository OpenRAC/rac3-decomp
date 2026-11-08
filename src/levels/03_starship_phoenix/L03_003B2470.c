#include "common.h"

/* localdecomp:start func_L03_003B2470 */
void func_L01_00445130(s32, s32, s32);
void func_L03_003B2470(s32 arg0) {
    func_L01_00445130(arg0, 3, -1);
}
/* localdecomp:end func_L03_003B2470 */

/* localdecomp:start func_L03_003B2490 */
void func_L01_00445130(s32, s32, s32);
void func_L03_003B2490(s32 arg0) {
    func_L01_00445130(arg0, 4, -1);
}
/* localdecomp:end func_L03_003B2490 */

/* localdecomp:start func_L03_003B24B0 */
void func_L01_00445130(s32, s32, s32);
void func_L03_003B24B0(s32 arg0) {
    func_L01_00445130(arg0, 2, -1);
}
/* localdecomp:end func_L03_003B24B0 */

/* localdecomp:start func_L03_003B24D0 */
void func_L01_00445130(s32, s32, s32);
void func_L03_003B24D0(s32 arg0) {
    func_L01_00445130(arg0, 5, -1);
}
/* localdecomp:end func_L03_003B24D0 */

/* localdecomp:start func_L03_003B24F0 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    char pad0[0x100];
    u128_t vec;
    char pad1[0x18];
    int flag;
} S_003B24F0;
typedef struct {
    char pad0[0x68];
    S_003B24F0 *p;
} T_003B24F0;
typedef struct {
    char pad0[0x10];
    u128_t vec;
} V_003B24F0;
void func_L03_003B24F0(T_003B24F0 *a, V_003B24F0 *src) {
    S_003B24F0 *s = a->p;
    if (src == 0) {
        s->flag = 0;
    } else {
        s->flag = 1;
        s->vec = src->vec;
    }
}
/* localdecomp:end func_L03_003B24F0 */
