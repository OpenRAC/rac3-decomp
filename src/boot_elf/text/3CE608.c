#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003CE608(void);
/* --- end of declarations from other files --- */

/* declarations of 3CE2E8.c's earlier functions (tools/port_from_us.py) */
typedef struct { u8 pad[0x20]; s16 *arr[1]; } S_3C8B28;
extern S_3C8B28 *D_001DA5F0_003CE450;
extern s32 D_001DA610[2];
extern void func_0038D728(void *, void *);
extern s32 func_003CE450(s32, s32);
s32 func_003CE798_003CE568(s32);
extern s32 D_001D9D00;
extern void *D_001DA5F0_003CE568;
extern s32 D_001DA650;

/* localdecomp:start func_003CE608 */
typedef struct Config_003C8CE0 {
    unsigned char padding[0xC];
    short count;
    unsigned char padding2[2];
    unsigned char *buffer;
} Config_003C8CE0;

extern int D_001DA050;
extern Config_003C8CE0 *D_001DA5F0_003CE608;
extern int D_001DA600;
extern int D_001D4BB4;
extern int D_001D4BB0;
extern int D_001D9BFC;
__asm__(".extern D_001D9BFC, 4");

void func_003CE608(void) {
    register int old __asm__("$2");
    register int index __asm__("$5");
    register Config_003C8CE0 *config __asm__("$6");
    register int saved __asm__("$3");
    register int count __asm__("$4");

    old = D_001DA050;
    index = 0;
    config = D_001DA5F0_003CE608;
    D_001DA600 = old;
    saved = D_001D4BB4;
    old += 0x10;
    count = config->count;
    D_001DA050 = old;
    D_001D4BB0 = saved;
    D_001D9BFC = 0;
    if (count > 0) {
        do {
            old = (int)config->buffer;
            saved = index * 0x10;
            index++;
            saved += old;
            __asm__ volatile("" : "+r"(saved));
            *(unsigned long *)saved = 0;
            old = config->count;
        } while (index < old);
    }
}
/* localdecomp:end func_003CE608 */
