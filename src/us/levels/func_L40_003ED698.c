#include "common.h"

/* localdecomp:start func_L40_003ED698 */
extern s32 D_001A5F78[];
extern u8 *func_L39_006699B0(void);
extern s32 func_L39_00669978(s32, void *, s32, void *, u8 *);

/* Writes a network message: gets a buffer from func_L39_006699B0, fills it with
 * func_L39_00669978(4, ...), appends the word at +0x26C of the entity's data, and stores the total
 * length at the buffer start. */
void func_L40_003ED698(void *object, void *context, u8 *entity) {
    u8 *state = *(u8 **)(entity + 0x68);
    u8 *buffer = func_L39_006699B0();
    u8 *cursor;
    s32 offset;
    if (buffer != 0) {
        offset = func_L39_00669978(4, object, D_001A5F78[0] + 0x1F4, context, buffer);
        cursor = buffer + offset;
        *(s32 *)cursor = *(s32 *)(state + 0x26C);
        cursor += 4;
        *(s32 *)buffer = (s32)cursor - (s32)buffer;
    }
}
/* localdecomp:end func_L40_003ED698 */
