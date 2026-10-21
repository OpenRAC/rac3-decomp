#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_008007C8(int);
/* --- end of declarations from other files --- */

/* declarations of 800488.c's earlier functions (tools/port_from_us.py) */
typedef struct {
    u32 *dst;
    u32 size;
    u32 pad8;
    u32 entry;
} Hdr_800488;
extern u8 D_8C6200[];
extern u8 D_00806080[];
extern void func_00800160(void *, void *);
extern void func_008026F0(void);
extern u32 func_00800488(void);

/* localdecomp:start func_00800790 */
/* Sony 2.9-ee library code: byte copy. */
int func_00800790(unsigned char *d, unsigned char *s, unsigned int n) {
    unsigned int i;
    for (i = 0; i < n; i++)
        *d++ = *s++;
    return 0;
}
/* localdecomp:end func_00800790 */

/* localdecomp:start func_008007C0 */
/* Sony 2.9-ee library code (sibling call). func_008010F8 is in 8010A8.c. */
extern void func_008010F8(void);
void func_008007C0(void) {
    func_008010F8();
}
/* localdecomp:end func_008007C0 */

/* localdecomp:start func_008007C8 */
/* Sony 2.9-ee library code: run func_008007C0, then the Exit syscall stub func_00800840
   (a sibling call). */
extern void func_00800840(int);
void func_008007C8(int code) {
    func_008007C0();
    func_00800840(code);
}
/* localdecomp:end func_008007C8 */

LINKER_REMNANT("asm/i5bootn/remnants", func_008007F0);
