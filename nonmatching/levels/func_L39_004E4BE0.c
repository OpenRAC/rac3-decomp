/* Near miss, ported from rac4-decomp's func_L00_005209E0 (cross-game near pair). NEAR: 16-byte save slots (frame 0x60, s0-s3/ra at 0x10..0x50) vs our 0x30 packed frame; logic/regs otherwise same (s1=&record hoisted) */
typedef struct Record Record;
typedef struct Container Container;
extern s32 func_L39_004E4AE8(Container *container, u32 category, u32 key,
                             s32 *cursor, Record **output, u32 flags);

s32 func_L39_004E4BE0(Container *container, u32 category, const u32 *keys)
{
    s32 cursor = 0;
    Record *record;
    s32 status;
    while (*keys != 0) {
        status = func_L39_004E4AE8(container, category, *keys,
                                   &cursor, &record, 4);
        if (status != 0)
            return status;
        ++keys;
    }
    return 0;
}
