#include "common.h"

typedef struct {
    u8 pad0[0x10];
    s32 handle;
} Global_L39_0067C220;

/* localdecomp:start func_L39_0067C220 */
extern Global_L39_0067C220 D_001A5E50;
extern s32 func_001918A8(s32);
extern void func_00191730(void);
extern s32 func_00126150(void);
extern void func_001260F0(s32, s32);

void func_L39_0067C220(void) {
    s32 value;
    func_001918A8(D_001A5E50.handle);
    D_001A5E50.handle = -1;
    func_00191730();
    value = func_00126150();
    func_001260F0(value, *(s32 *)0x0024D270);
}
/* localdecomp:end func_L39_0067C220 */
