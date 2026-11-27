#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_00393548 */
typedef struct { u8 p0[0x14]; s32 a[8]; s32 b[16]; s32 c[1]; } S_38E930;
typedef struct { u32 w0; u16 h4; u8 b6; u8 b7; } E_38E930;
extern S_38E930 * volatile D_001D9EA0_00393548;
extern E_38E930 *D_001D9EAC_00393548;
extern volatile s32 D_001A1F08_00393548[];
extern void func_003933B0_00393548();
extern void func_00397D60(s32, s32, s32, s32, s32, s32);
/* the copy of func_00393168 */
struct HudTexCounts_00393548 {
    u8 pad0[0x14];
    s32 mid_ends[8];
    s32 ends[16];
    s32 loaded[16];
};
struct HudTexPage_00393548 {
    u32 source_address;
    u16 gs_block_offset;
    u8 width_log2;
    u8 height_log2;
};
struct HudState_00393548 {
    s32 serial;
    s32 unk4;
    s32 unk8;
    s32 z;
    s32 heap_cur;
    s32 heap_end;
    struct HudTexCounts_00393548 *counts;
    void *anim_defs;
    void *frame_refs;
    struct HudTexPage_00393548 *image_pages;
    struct HudTexPage_00393548 *palette_pages;
};
extern struct HudState_00393548 D_001D9E88_00393548 __attribute__((section(".sdata")));
extern s32 D_001A1F08_00393548_a00393548[] __asm__("D_001A1F08_00393548");
extern u32 D_001D5D50;
extern void func_003933B0(s32, s32);
extern void func_00397D60(s32, s32, s32, s32, s32, s32);

void func_00393548(s32 bank, s32 base, s32 immediate)
{
    struct HudTexCounts_00393548 *counts;
    s32 address;
    s32 bank_offset;
    s32 first;
    s32 end;
    s32 i;
    s32 page;
    s32 width_log2;
    s32 height_log2;
    s32 size;
    if (D_001D9E88_00393548.counts->loaded[bank] == 0) {
        func_003933B0(0, base);
        address = D_001A1F08_00393548_a00393548[0];
    } else {
        address = D_001A1F08_00393548_a00393548[0];
    }
    counts = D_001D9E88_00393548.counts;
    bank_offset = bank << 2;
    first = bank == 0 ? 0 : counts->ends[bank - 1];
    i = first;
    end = *(s32 *)((u8 *)D_001D9E88_00393548.counts + bank_offset + 0x34);
    do {
        for (; i < end; i++) {
            page = address >> 8;
            width_log2 = D_001D9E88_00393548.image_pages[i].width_log2;
            height_log2 = D_001D9E88_00393548.image_pages[i].height_log2;
            size = 1 << (width_log2 + height_log2);
            func_00397D60(D_001D9E88_00393548.image_pages[i].source_address, page, 0x1B, width_log2,
                          height_log2, immediate);
            address += size * 4;
            D_001D9E88_00393548.image_pages[i].gs_block_offset = page;
            D_001D5D50 = address;
        }
    } while (0);
}
/* localdecomp:end func_00393548 */
