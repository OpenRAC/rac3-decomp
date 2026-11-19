#include "common.h"

/* declared by functions of L39_0050CC00.c, which this file was cut from */
extern s32 func_L39_0050CC90(void *, void *, void *, s32, void *);

/* localdecomp:start func_L39_0050CC90 */
typedef struct R_0050CC90 { s32 a; void *b; void *type; void *flag; } R_0050CC90;
typedef struct O_0050CC90 { s32 p0; u32 count; u32 cap; R_0050CC90 **arr; } O_0050CC90;
extern void *func_L39_004F7590(s32);
extern void func_L39_004F74E8(void *, s32, s32);
extern void func_L39_004F7510(void *, void *, s32);
extern void func_L39_004F7620(void *);

s32 func_L39_0050CC90(void *a0, void *type, void *flag, s32 a, void *b) {
    O_0050CC90 *obj = a0;
    u32 newcap;
    u32 bytes;
    R_0050CC90 **p;
    R_0050CC90 *q;

    if ((s32)type == 0x1F && flag == 0) {
        return 0x804;
    }
    if (obj->count >= obj->cap) {
        newcap = obj->cap + 10;
        bytes = newcap * 4;
        if (bytes < obj->cap * 4) {
            return 0x803;
        }
        p = func_L39_004F7590(bytes);
        if (p == 0) {
            return 0x803;
        }
        func_L39_004F74E8(p, 0, bytes);
        func_L39_004F7510(p, obj->arr, obj->cap * 4);
        func_L39_004F7620(obj->arr);
        obj->arr = p;
        while (obj->cap < newcap) {
            q = func_L39_004F7590(0x10);
            obj->arr[obj->cap] = q;
            if (q == 0) {
                return 0x803;
            }
            obj->cap++;
        }
    }
    obj->arr[obj->count]->a = a;
    obj->arr[obj->count]->b = b;
    obj->arr[obj->count]->type = type;
    obj->arr[obj->count]->flag = flag;
    obj->count++;
    return 0;
}
/* localdecomp:end func_L39_0050CC90 */
