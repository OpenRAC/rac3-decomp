#include "common.h"

typedef struct {
    f32 f0;
    s32 f4;
} S_003CD938;

/* declared by functions of L07_003CC2B0.c, which this file was cut from */
void func_L07_003CD2E8(void *, s32);
extern void func_L07_003CD2E8(void *, s32);
extern s32 func_00382498(s32, s32);

/* localdecomp:start func_L07_003CDC48 */
extern int func_00382498(int, int);
extern void func_L07_003CD2E8(void *, int);
void func_L07_003CDC48(void *arg0) {
    func_L07_003CD2E8(arg0, func_00382498(0, 1) + 0x15);
}
/* localdecomp:end func_L07_003CDC48 */
