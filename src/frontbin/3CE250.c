#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations carried from the file this was cut from */
extern void func_003CE250(void);


typedef struct Config_003C8CE0 {
    unsigned char padding[0xC];
    short count;
    unsigned char padding2[2];
    unsigned char *buffer;
} Config_003C8CE0;
extern int D_001DA050;
extern Config_003C8CE0 *D_001DA5F0_003CE250;
extern int D_001DA600;
extern int D_001D4BB4;
extern int D_001D4BB0;
extern int D_001D9BFC;
/* localdecomp:start func_003CE250 */
void func_003CE250(void) {
    s32 i;
    s32 v = D_001DA050;
    Config_003C8CE0 *c = D_001DA5F0_003CE250;
    D_001DA600 = v;
    v += 0x10;
    D_001DA050 = v;
    D_001D4BB0 = D_001D4BB4;
    D_001D9BFC = 0;
    for (i = 0; i < c->count; i++) {
        *(unsigned long *)(c->buffer + i * 16) = 0;
    }
}
/* localdecomp:end func_003CE250 */
