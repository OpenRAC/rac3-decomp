#include "common.h"

/* localdecomp:start func_L39_004E1200 */
extern s32 func_L39_004BECF0(void *, s32, s32, char *, s32);
extern void func_L39_004E1268(void *);
extern void func_L39_004BEF28(void *);
extern char D_L39_00477278[];

void func_L39_004E1200(void *arg0) {
    if (arg0 == 0) {
        return;
    }
    if (func_L39_004BECF0((u8 *)arg0 + 8, -1, 0xA, D_L39_00477278, 0xF2) > 0) {
        return;
    }
    func_L39_004E1268(arg0);
    func_L39_004BEF28(arg0);
}
/* localdecomp:end func_L39_004E1200 */

/* localdecomp:start func_L39_004E1268 */
extern void func_L39_004EA410(s32);
extern void func_L39_004DDA88(s32);
extern void func_L39_004DD250(s32);

typedef struct S_004E1268 {
    s32 type;
    s32 f4;
    s32 f8;
    s32 fC;
} S_004E1268;

void func_L39_004E1268(void *p) {
    S_004E1268 *a = p;
    switch (a->type) {
    case 6:
    case 0x13:
        func_L39_004EA410(a->fC);
        break;
    case 0x42:
    case 0x46:
    case 0x71:
    case 0x74:
        func_L39_004DDA88(a->fC);
        break;
    case 0x1C:
        func_L39_004DD250(a->fC);
        break;
    }
}
/* localdecomp:end func_L39_004E1268 */
