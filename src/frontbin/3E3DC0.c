#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_003E3DF0(void);
extern void func_003E3E08(void);
extern void func_003E3DC0(void);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003E3DC0 */
typedef struct { u8 pad[0x40]; s32 f40; u8 pad2[0x14]; s32 f58; } S_302D80;
extern S_302D80 D_00306D00;
 
void func_003E3DC0(void) {
    S_302D80 *s = &D_00306D00;
    if (s->f40 == 7 && s->f58 == 1) {
        s->f58 = 2;
    }
}
/* localdecomp:end func_003E3DC0 */

/* localdecomp:start func_003E3DF0 */
extern s32 D_00306D40[];
s32 func_003E3DF0(void) {
    return D_00306D40[0] == 7;
}
/* localdecomp:end func_003E3DF0 */

/* localdecomp:start func_003E3E08 */
extern s32 D_001D94B0;
void func_003E3E08(void) {
    D_001D94B0 = 3;
}
/* localdecomp:end func_003E3E08 */

LINKER_REMNANT("asm/remnants", func_003E3E18);

/* localdecomp:start func_003E3E20 */
extern s16 D_00306D84[];
 
void func_003E3E20(void) {
    D_00306D84[0] = 0;
}
/* localdecomp:end func_003E3E20 */

/* localdecomp:start func_003E3E30 */
void *func_003E3E30(void *p) {
    return (u8 *)p + 0xED1C;
}
/* localdecomp:end func_003E3E30 */
