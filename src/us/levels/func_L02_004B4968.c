#include "common.h"

typedef struct {
    u8 pad0[0x740];
    f32 first;
    f32 second;
    u8 pad748[0x25C0 - 0x748];
    u8 *object;
    s32 mode;
} Global_L02_004B4968;

/* localdecomp:start func_L02_004B4968 */
extern Global_L02_004B4968 D_001A4BE0;
extern void func_L02_00422FA0(u8 *, f32 *, f32 *, f32, f32, f32);

/* When the hero global's mode is 0x81 or 0x50, turns the target object toward its two stored angles
 * via func_L02_00422FA0 with fixed rate limits. */
void func_L02_004B4968(void) {
    Global_L02_004B4968 *global = &D_001A4BE0;
    if (global->mode != 0x81 && global->mode != 0x50) {
        return;
    }
    func_L02_00422FA0(global->object, &global->first, &global->second,
                       0.1745329252f, 0.0261799414f, 0.0349065885f);
}
/* localdecomp:end func_L02_004B4968 */
