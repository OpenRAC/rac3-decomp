#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void func_003CF0F0(void);
extern void func_003CF050(void);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003CF0F0();
extern void func_003CF050();
/* --- end of declarations from other files --- */

extern f32 D_001DA670[];
extern s32 D_001DA680[];
extern f32 D_00225B30[];
extern f32 D_00334FB0[];
extern void func_0038CBA0();
INCLUDE_ASM("asm/nonmatchings/text", func_003CEDF8);

extern u32 *D_001DA050;
extern u32 *D_001DA68C;
extern s32 D_001DA694;
extern s32 D_001D4BB0;
extern void func_003CFDD0(void);
extern s32 func_003CFF38(s32);
extern void func_003A9618(void);
INCLUDE_ASM("asm/nonmatchings/text", func_003CEF40);

/* localdecomp:start func_003CF050 */
typedef struct {
    u32 word0;
    u8 pad4[0x1F];
    u8 index23;
    u8 pad24[0xC];
    u32 word30;
    u8 pad34[0x1C];
} Item_003C9AE0;

typedef struct {
    Item_003C9AE0 *items;
    s32 count;
} Group_003C9AE0;

typedef struct {
    s16 first;
    s16 second;
} Pair_003C9AE0;

extern Group_003C9AE0 D_002FD800[];
extern Pair_003C9AE0 D_002FD500[];

void func_003CF050(void) {
    Group_003C9AE0 *group = D_002FD800;

    if (group->items != 0) {
        do {
            Item_003C9AE0 *item = group->items;
            register s32 loaded_count __asm__("$2") = group->count;

            if (loaded_count > 0) {
                register s32 count __asm__("$7") = loaded_count;
                do {
                    Pair_003C9AE0 *pair = &D_002FD500[item->index23];
                    s16 value = pair->first;

                    if (value != 0) {
                        item->word0 = (item->word0 & 0xFFFFC000) | value;
                    }

                    value = pair->second;
                    count--;
                    if (value != 0) {
                        item->word30 = (item->word30 & 0xFFFFC000) | value;
                    }
                    item++;
                } while (count != 0);
            }
            group++;
        } while (group->items != 0);
    }
}
/* localdecomp:end func_003CF050 */

extern s32 D_001D4BB4;
extern u8 D_00222400[];
extern u8 D_002FDC00[];
extern void func_0038CE20(f32 *, void *, f32);
extern void func_0038D640();
extern void func_0038CD80();
extern void func_11F0A0(s32);
INCLUDE_ASM("asm/nonmatchings/text", func_003CF0F0);
TEXT_PADDING(2);

INCLUDE_ASM("asm/nonmatchings/text", func_003CF1C8);
