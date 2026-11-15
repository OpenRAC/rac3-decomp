#include "common.h"

/* localdecomp:start func_L39_004F5CB0 */
void func_L39_004F5E70(void *);
void func_L39_004F4EE8(void *);
void *func_L39_004F74E8(void *, s32, u32);

void func_L39_004F5CB0(u8 *p) {
    func_L39_004F5E70(p);
    func_L39_004F4EE8(p + 0x14);
    func_L39_004F74E8(p + 0x28, 0, 8);
}
/* localdecomp:end func_L39_004F5CB0 */

/* localdecomp:start func_L39_004F5CE8 */
typedef struct O_004F5CE8 { void (*fn)(struct O_004F5CE8 *); } O_004F5CE8;
typedef struct S_004F5CE8 { u8 pad[0x14]; u8 sub[0x14]; O_004F5CE8 *obj; } S_004F5CE8;

void func_L39_004F4EB8(void *);
void func_L39_004F7620(void *);
void func_L39_004F5FA0(void *);

void func_L39_004F5CE8(S_004F5CE8 *p) {
    func_L39_004F4EB8(p->sub);
    if (p->obj != 0) {
        p->obj->fn(p->obj);
        func_L39_004F7620(p->obj);
    }
    func_L39_004F5FA0(p);
}
/* localdecomp:end func_L39_004F5CE8 */

INCLUDE_ASM("asm/levels", func_L39_004F5D38);
