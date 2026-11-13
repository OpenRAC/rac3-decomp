#include "common.h"

/* NTSC-U counterpart of func_L39_006625A8 (src/levels/shared/L39_00662510.c) */
/* localdecomp:start func_L39_0065FCD0 */
typedef struct { unsigned a:4; unsigned b:6; unsigned c:3; unsigned rest:19; int pad; int f8; char pad2[68]; int f50; char f54; char f55; } Type1;
extern Type1 *func_L39_00660120(void);
extern void func_L39_00660290(Type1 *, int, int);
extern int D_001A5E58[];

/* from rac4-decomp's func_0053C920 */
Type1 *func_L39_0065FCD0(int *arg0, int arg1, int arg2, int arg3) {
 Type1 *p = func_L39_00660120();
 p->a = arg1;
 p->f8 = *arg0;
 p->b = 0;
 p->c = D_001A5E58[0];
 p->f54 = 0;
 p->f50 = -1;
 p->f55 = 1;
 func_L39_00660290(p, arg2, arg3);
 return p;
}
/* localdecomp:end func_L39_0065FCD0 */
