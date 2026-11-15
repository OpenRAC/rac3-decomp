#include "common.h"

/* localdecomp:start func_L39_0050DE78 */
extern s32 func_L39_0050DDC8(void *, u16 *);

s32 func_L39_0050DE78(void *input, u16 *expected)
{
    u16 value;
    u16 want;
    s32 diff;
    s32 status = func_L39_0050DDC8(input, &value);
    if (status != 0) return status;
    want = *expected;
    diff = value ^ want;
    if (diff != 0) return 0x801;
    return 0;
}
/* localdecomp:end func_L39_0050DE78 */

/* localdecomp:start func_L39_0050DEC0 */
typedef struct {
    u8 *data;
    u32 remaining;
} Cursor;
typedef struct {
    u8 prefix[12];
    Cursor cursor;
} Input;
extern s32 func_L39_0050DF38(const Input *input, Cursor *output);
extern void func_L39_004F74E8(u8 *, s32, u32);
extern void func_L39_004F7510(u8 *, u8 *, u32);

s32 func_L39_0050DEC0(const Input *input, Cursor *out)
{
    Cursor local;
    u32 skip;
    s32 status;
    status = func_L39_0050DF38(input, &local);
    if (status != 0) return status;
    if (local.remaining > out->remaining)
        return 0x801;
    skip = out->remaining - local.remaining;
    func_L39_004F74E8(out->data, 0, skip);
    func_L39_004F7510(out->data + skip, local.data, local.remaining);
    return 0;
}
/* localdecomp:end func_L39_0050DEC0 */
