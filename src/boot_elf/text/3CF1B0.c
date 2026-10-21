#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void func_0038D680();
extern void func_003CF4A8(void);
extern void func_003CF408(void);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003CF4A8();
extern void func_003CF408();
/* --- end of declarations from other files --- */

extern f32 D_001DA670[];
extern s32 D_001DA680[];
extern f32 D_00225B30[];
extern f32 D_00334FB0[];
extern void func_0038CF80();
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003CF1B0);

/* localdecomp:start func_003CF2F8 */
extern u32 *D_001DA050;
extern u32 *D_001DA68C;
extern s32 D_001DA694;
extern s32 D_001D4BB0;
extern void func_003D0188(void);
extern s32 func_003D02F0(s32);
extern void func_003A99D0(void);
void func_003CF2F8(void) {
    u32 *save = D_001DA050;
    s32 r;
    D_001DA050 += 4;
    D_001DA68C[0] = 0x20000000;
    D_001DA68C[1] = (u32)D_001DA050;
    D_001DA68C[2] = 0;
    D_001DA68C[3] = 0;
    func_003D0188();
    r = func_003D02F0(D_001D4BB0);
    func_003A99D0();
    if (D_001DA694 < r) { D_001DA694 = r; }
    D_001DA050[0] = 0x20000000;
    D_001DA050[1] = (u32)(D_001DA68C + 4);
    D_001DA050[2] = 0;
    D_001DA050[3] = 0;
    D_001DA050 += 4;
    save[0] = 0x20000000;
    save[1] = (u32)D_001DA050;
    save[2] = 0;
    save[3] = 0;
}
/* localdecomp:end func_003CF2F8 */

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
/* localdecomp:start func_003CF408 */
void func_003CF408(void) {
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
/* localdecomp:end func_003CF408 */

/* US draft of func_003CF4A8 (rac3-uya-decomp func_003CF340, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: unmapped symbols: func_003CF418. */


/* localdecomp:start func_003CF4A8 */
extern s32 D_001D4BB4;
extern u8 D_00222400[];
extern u8 D_002FDC00[];
extern void func_0038D200(f32 *, void *, f32);
extern void func_0038DA20();
extern void func_0038D160();
extern void func_11F0A0(s32);
extern void func_003CF580();
void func_003CF4A8(void) {
    u8 v[0x40];
    u32 *o = D_001DA050;
    s32 t = D_001D4BB4;
    D_001DA68C = o;
    o += 4;
    D_001D4BB0 = t;
    D_001DA050 = o;
    func_0038D680(v);
    func_0038D200((f32 *)(v + 0x30), D_00222400, -1024.0f);
    *(f32 *)(v + 0x3C) = 1.0f;
    func_0038DA20(v, D_00222400 - 0x100, v);
    func_003A9748(5, (s32)v, 4);
    func_003A9748(0x14D, (s32)v, 4);
    func_11F0A0(0);
    func_003CF580();
    func_003CF2F8();
    func_0038D160(D_002FDC00, 0x3000, 0x40);
}
/* localdecomp:end func_003CF4A8 */
TEXT_PADDING(2);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003CF580);
