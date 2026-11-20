#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u128_t v0, v1, v2;
    u128_t matrix[3];
} Local_51FC18;

typedef struct __attribute__((packed)) { s32 values[2]; } Pair;

/* localdecomp:start func_L39_00520350 */
extern s32 func_L01_00457458(s32, s32);
extern void func_003C2880(char *);
extern s32 func_0038DC20(char *, f32);
extern void func_L39_005203E0(char *);
extern void func_L39_00520630(char *);

void func_L39_00520350(char *obj)
{
    char local[16];
    s32 r;

    if (*(s32 *)(obj + 0x68) == 0)
        return;
    r = func_L01_00457458(*(s16 *)(obj + 0xAA), *(s32 *)(*(s32 *)(obj + 0x68) + 0x28));
    if (r == 0) {
        func_003C2880(obj);
        return;
    }
    *(u128_t *)local = *(u128_t *)(obj + 0x10);
    *(f32 *)(local + 0xC) = 2.0f;
    r = func_0038DC20(local, 100.0f);
    if (r == -1)
        return;
    func_L39_005203E0(obj);
    func_L39_00520630(obj);
}
/* localdecomp:end func_L39_00520350 */
