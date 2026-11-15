#include "common.h"

/* declared by functions of L39_004D7740.c, which this file was cut from */
extern void func_L39_004DAE48(s32 arg0, s32 arg1, s32 arg2, s32 *arg3);

/* localdecomp:start func_L39_004DAF40 */
typedef struct S_004DAF40 { char pad[0x24]; struct S_004DAF40 *next; struct S_004DAF40 *prev; } S_004DAF40;

S_004DAF40 *func_L39_004DAF40(S_004DAF40 *self, S_004DAF40 *child) {
    S_004DAF40 *tail;
    if (self == 0) return child;
    tail = self;
    while (tail->next != 0) tail = tail->next;
    tail->next = child;
    if (child != 0) child->prev = tail;
    func_L39_004DAE48((s32)self, 6, 0, 0);
    return self;
}
/* localdecomp:end func_L39_004DAF40 */

/* localdecomp:start func_L39_004DAFC0 */
void *func_L39_004DAFC0(void *arg0) {
    S_004DAF40 *self = arg0;
    S_004DAF40 *next;

    if (self == 0) return 0;
    next = self->next;
    if (self->prev != 0) self->prev->next = next;
    if (self->next != 0) self->next->prev = self->prev;
    self->next = 0;
    self->prev = 0;
    func_L39_004DAE48((s32)self, 7, 0, 0);
    return next;
}
/* localdecomp:end func_L39_004DAFC0 */
