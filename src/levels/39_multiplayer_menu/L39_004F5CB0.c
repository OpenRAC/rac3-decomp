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

/* localdecomp:start func_L39_004F5D38 */
s32 func_L39_004F5D38(void *arg0, s32 arg1)
{
    u32 value;
    s32 result;

    value = *(u32 *)((u8 *)arg0 + 0x28);
    result = 0x203;
    if (value != 0) {
        value = *(u32 *)value;
        result = 0x205;
        value ^= (u32)arg1;
        result = (value == 0) ? 0 : 0x205;
    }
    return result;
}
/* localdecomp:end func_L39_004F5D38 */
