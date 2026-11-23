#include "common.h"

typedef struct {
    f32 f0;
    s32 f4;
} S_003CD938;

/* declared by functions of L07_003CC2B0.c, which this file was cut from */
void func_L07_003CD2E8(void *, s32);
extern void func_L07_003CD2E8(void *, s32);
extern void func_L07_003CD2E8(void *, int);

/* localdecomp:start func_L07_003CDDC0 */
void func_L07_003CDC48(void *);
void func_L07_003CD2E8(void *, s32);

void func_L07_003CDDC0(void *arg0) {
    void *temp_s0;

    temp_s0 = *(void **)((u8 *)arg0 + 0x68);
    if (*(u8 *)((u8 *)arg0 + 0x60) & 0x2) {
        if (*(u8 *)((u8 *)temp_s0 + 0x406) != 0) {
            func_L07_003CDC48(arg0);
            *(u8 *)((u8 *)temp_s0 + 0x406) = 0;
        } else {
            func_L07_003CD2E8(arg0, 0x6);
        }
    }
}
/* localdecomp:end func_L07_003CDDC0 */

/* localdecomp:start func_L07_003CDE10 */
extern void func_L07_003CD2E8(void *, int);
void func_L07_003CDE10(char *a0)
{
    char *s = *(char **)(a0 + 0x68);
    if (a0[0x60] & 2) {
        s[0x407] = 0;
        func_L07_003CD2E8(a0, 6);
    }
}
/* localdecomp:end func_L07_003CDE10 */
