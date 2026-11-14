#include "common.h"

typedef struct N_65FDA0 { u32 w0; s32 w4; s32 w8; u8 p0[0x49]; u8 b55; u8 p1x; struct N_65FDA0 *next; } N_65FDA0;
typedef struct N_65FE10 { u8 pad[0x58]; struct N_65FE10 *next; } N_65FE10;
typedef void (*Fn_6600D8)(void *, void *);
typedef struct {
    u32 pad0 : 4;
    u32 cap : 6;
    u32 pad1 : 22;
} S_6601C8;

/* localdecomp:start func_L39_00663900 */
extern void func_L39_005C34A8(u8 *a, u8 *b, int c);

void func_L39_00663900(u8 *a0)
{
    *(int *)(*(u8 **)(a0 + 9524) + 428) = *(int *)(*(u8 **)(a0 + 9524) + 840);
    *(int *)(*(u8 **)(a0 + 9524) + 416) = 0;
    *(int *)(*(u8 **)(a0 + 9524) + 444) = *(int *)(*(u8 **)(a0 + 9524) + 432);
    *(int *)(*(u8 **)(a0 + 9524) + 432) = 0;
    func_L39_005C34A8(*(u8 **)(a0 + 9524), *(u8 **)(a0 + 9560) + 3148, 20);
}
/* localdecomp:end func_L39_00663900 */
