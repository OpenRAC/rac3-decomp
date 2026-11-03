#include "common.h"


/* localdecomp:start func_U_0037D1A8 */
typedef struct {
    u8 pad[0x84];
    void *buffer;
} FrontendState_0037D1A8;

extern FrontendState_0037D1A8 D_U_00227600;

extern void *func_0011A264(void *dest, s32 value, u32 size);
extern void *func_U_003ECDC0(u32 size, void *buffer);
extern void *func_U_003A9B10(void *object, u32 size);

void func_U_0037D1A8(void)
{
    void *object;

    func_0011A264(D_U_00227600.buffer, 0xCD, 0x40000);
    object = func_U_003ECDC0(0x24F10, D_U_00227600.buffer);
    *(void **)0x001D5C78 = func_U_003A9B10(object, 0x40000);
}
/* localdecomp:end func_U_0037D1A8 */
