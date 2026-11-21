#include "common.h"

/* localdecomp:start func_L39_004CB698 */
typedef struct S_004CB698 {
    char _p0[0x98];
    s32 references;
    char _p9C[4];
    unsigned long timeout;
    s32 time;
    char _pAC[0x10];
    char ex_data[8];
    void *prev;
    void *next;
} S_004CB698;

extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);
extern void *func_L39_004BEED8(s32);
extern void *func_0011D534(void *, s32, s32);
extern s32 func_L39_004E5108(void);
extern void func_L39_004DEF48(s32, void *, void *);
extern s32 D_L39_00465704 __attribute__((section(".data")));

void *func_L39_004CB698(void) {
    S_004CB698 *ss = func_L39_004BEED8(0xD0);
    if (ss == 0) {
        func_L39_004BC6C8(0x14, 0xBD, 0x21, 0, 0);
        return 0;
    }
    func_0011D534(ss, 0, 0xD0);
    ss->references = 1;
    ss->timeout = 60 * 5 + 4;
    ss->time = func_L39_004E5108();
    ss->prev = 0;
    ss->next = 0;
    func_L39_004DEF48(D_L39_00465704, ss, ss->ex_data);
    return ss;
}
/* localdecomp:end func_L39_004CB698 */
