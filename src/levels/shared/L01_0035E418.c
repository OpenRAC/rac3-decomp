#include "common.h"

typedef int s128 __attribute__((mode(TI)));
typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} __attribute__((aligned(16))) S_38C110v;

typedef struct {
    s32 a[12];
} S_0035E418;

extern void func_L01_004C8668(int);
extern void func_003C2880(void *);


/* localdecomp:start func_L01_0035E418 */
extern S_0035E418 D_L01_001E1A70;

s32 func_L01_0035E418(void)
{
    s32 i;

    for (i = 0; i < 12; i++) {
        if (D_L01_001E1A70.a[i] == 0) {
            return 0;
        }
    }
    return 1;
}
/* localdecomp:end func_L01_0035E418 */
