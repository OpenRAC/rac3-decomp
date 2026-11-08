#include "common.h"

/* localdecomp:start func_L39_00662510 */
extern u8 D_L39_0047AA10[];
void *func_L39_00662510(u8 *p) {
    *(void **)(p + 20) = D_L39_0047AA10;
    return p;
}
/* localdecomp:end func_L39_00662510 */

/* localdecomp:start func_L39_00662528 */
typedef struct S_65FC50 S_65FC50;

struct S_65FC50 {
    u8 pad[88];
    S_65FC50 *next;
};

extern S_65FC50 D_L39_0030C400[];
extern S_65FC50 *D_L39_002461F0;
extern void func_L39_00662A48(S_65FC50 *);

void func_L39_00662528(void) {
    s32 i;

    for (i = 0; i < 192; i++) {
        func_L39_00662A48(&D_L39_0030C400[i]);
    }
    for (i = 190; i >= 0; i--) {
        D_L39_0030C400[i].next = &D_L39_0030C400[i + 1];
    }
    D_L39_002461F0 = D_L39_0030C400;
}
/* localdecomp:end func_L39_00662528 */

/* localdecomp:start func_L39_006625A8 */
typedef struct { unsigned a:4; unsigned b:6; unsigned c:3; unsigned rest:19; int pad; int f8; char pad2[68]; int f50; char f54; char f55; } Type1;
extern Type1 *func_L39_006629F8(void);
extern void func_L39_00662B68(Type1 *, int, int);
extern int D_001A5CD8[];

/* from rac4-decomp's func_0053C920 */
Type1 *func_L39_006625A8(int *arg0, int arg1, int arg2, int arg3) {
 Type1 *p = func_L39_006629F8();
 p->a = arg1;
 p->f8 = *arg0;
 p->b = 0;
 p->c = D_001A5CD8[0];
 p->f54 = 0;
 p->f50 = -1;
 p->f55 = 1;
 func_L39_00662B68(p, arg2, arg3);
 return p;
}
/* localdecomp:end func_L39_006625A8 */
