/* PAL near miss (Codex wave 10): near miss: 105 words differ with the file's flags.
 * Worker's note: Best bitwise draft .03.log: 116 positional word diffs; return normalization loses retail s0=1/s2 live range and global address hoists; complete call sequence retained
 */
#include "common.h"
/* localdecomp:start func_003B3208 */
typedef struct { s32 x[2]; } S_003B3208;
extern S_003B3208 D_001DA938 __attribute__((section(".data")));
extern u8 D_0022E820[];
extern u8 D_0022E420[];
s32 func_003B3208(void)
{
    extern void func_003AA060(s32);
    extern void func_003E9828(void);
    extern void func_003E7670(s32);
    extern s32 *func_003E6FC0(void);
    extern s32 *func_003B3180(s32);
    extern void func_003E5E58(s32 *, s32);
    extern void func_003E7090(s32 *, s32, s32 *);
    extern void *func_003B4678(void);
    extern void *func_003B46B0(s32);
    extern void *func_003B4738(void);
    extern void *func_003B4768(s32);
    extern void func_003E6D68(s32 *, s32, void *);
    extern s32 func_003E70C8(s32 *, s32, s32, void *, s32);
    extern void func_003E71C8(s32 *, s32);
    s32 result;
    s32 *stream;
    s32 i;
    result = 1;
    func_003AA060(result);
    func_003E9828();
    func_003E7670(1);
    func_003E6FC0();
    stream = (s32 *)&D_001DA938;
    if (!stream[1]) stream = func_003E6FC0();
    for (i=0; i<=0; i++) {
        func_003E5E58(func_003B3180(i), i);
        func_003E7090(stream, i, func_003B3180(i));
    }
    func_003E6D68(stream, 0, func_003B4678());
    func_003E6D68(stream, 1, func_003B46B0(0));
    func_003E6D68(stream, 2, func_003B46B0(1));
    func_003E6D68(stream, 3, func_003B46B0(2));
    func_003E6D68(stream, 4, func_003B46B0(3));
    func_003E6D68(stream, 5, func_003B4738());
    func_003E6D68(stream, 6, func_003B4768(0));
    func_003E6D68(stream, 7, func_003B4768(1));
    func_003E6D68(stream, 8, func_003B4768(2));
    func_003E6D68(stream, 9, func_003B4768(3));
    result = (result != 0) & (func_003E70C8(stream,0,0x400,D_0022E820,0x10) != 0);
    result = (result != 0) & (func_003E70C8(stream,1,0x12000,D_0022E420,0xC0) != 0);
    func_003E71C8(stream,0);
    return result;
}
/* localdecomp:end func_003B3208 */
