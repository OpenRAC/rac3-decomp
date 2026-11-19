#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations carried from the file this was cut from */
extern s32 func_0011A264(s32, s32, s32);
extern s32 func_00392B20();
extern s32 func_00392C78();
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);



/* localdecomp:start func_00392F68 */
typedef struct LookupEntry_38E730 {
    u16 key;
    u8 reserved[6];
} LookupEntry_38E730;
extern LookupEntry_38E730 *D_001D9EA4_00392F68[];
s32 func_00392F68(s32 key) {
    LookupEntry_38E730 *entry = *D_001D9EA4_00392F68;
    s32 index = 0;
    if (entry->key != 0xFFFF && entry->key != key) {
        LookupEntry_38E730 *cursor = entry;
        s32 current;
        for (;;) {
            cursor++;
            current = cursor->key;
            index++;
            if (current == 0xFFFF || current == key) break;
        }
    }
    return index <= 0x3FF ? index : -1;
}
/* localdecomp:end func_00392F68 */

LINKER_REMNANT("asm/remnants", func_00392FC0);

/* localdecomp:start func_00392FD0 */
typedef struct { u8 p0[0x14]; s32 a[8]; s32 b[16]; s32 c[1]; } S_0038E798;
typedef struct { u32 w; u32 x; } E_0038E798;
extern S_0038E798 *D_001D9EA0_00392FD0[];
extern E_0038E798 *D_001D9EAC_00392FD0[];
extern E_0038E798 *D_001D9EB0_00392FD0[];
void func_00392FD0(s32 n, s32 size) {
    s32 i;
    s32 j;
    s32 end;
    if (D_001D9EA0_00392FD0[0]->c[n] == 0) {
        size = (size + 0xF) & 0xFFFFFFF0;
        D_001D9EA0_00392FD0[0]->c[n] = size;
        i = (n != 0) ? D_001D9EA0_00392FD0[0]->a[n - 1] : 0;
        end = D_001D9EA0_00392FD0[0]->a[n];
        for (j = i; j < end; j++) {
            D_001D9EB0_00392FD0[0][j].w &= 0x7FFFFFFF;
            D_001D9EB0_00392FD0[0][j].w += size;
        }
        i = (n != 0) ? D_001D9EA0_00392FD0[0]->b[n - 1] : 0;
        end = D_001D9EA0_00392FD0[0]->b[n];
        for (j = i; j < end; j++) {
            D_001D9EAC_00392FD0[0][j].w &= 0x7FFFFFFF;
            D_001D9EAC_00392FD0[0][j].w += size;
        }
    }
}
/* localdecomp:end func_00392FD0 */

LINKER_REMNANT("asm/remnants", func_00393130);

/* localdecomp:start func_00393138 */
extern u32 D_001D5D50;
u32 func_00393138(void) {
    u32 v = D_001D5D50;
    u32 r = 0;
    if (v <= 0x1CFFFF) r = (0x1D0000 - v) >> 2;
    return r;
}
/* localdecomp:end func_00393138 */

typedef struct { u8 p0[0x14]; s32 a[8]; s32 b[16]; s32 c[1]; } S_38E930;
typedef struct { u32 w0; u16 h4; u8 b6; u8 b7; } E_38E930;
extern S_38E930 * volatile D_001D9EA0_00393168;
extern E_38E930 *D_001D9EAC_00393168;
extern volatile s32 D_001A1F08_00393168[];
extern void func_00392FD0_00393168();
extern void func_00397980(s32, s32, s32, s32, s32, s32);
INCLUDE_ASM("asm/nonmatchings/text", func_00393168);
