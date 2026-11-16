#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations of 12A948.c's earlier functions (tools/port_from_us.py) */
extern s32 func_0012B098(s32);
extern s32 func_00124920(void);
extern s32 func_00124970(void);
extern s32 D_15A140;
extern void *D_15A144;
extern volatile int D_0013F914;
extern volatile int D_0013F920;
extern volatile int D_0013F928;
extern volatile int D_0013F934;
extern volatile int D_0013F960;
extern volatile int D_0013F964;
extern int D_15A140;
extern void func_0011EE50(s32);

/* localdecomp:start func_0012AB88 */
typedef struct Cb_0012AB88 {
    s32 n1;
    s32 n2;
    u8 *dst1;
    u8 *dst2;
    u8 src1[0x40];
    u8 src2[0x40];
} Cb_0012AB88;

void func_0012AB88(void *arg)
{
    extern void func_0012AAE0(s32 *);
    Cb_0012AB88 *p;
    u8 *d;
    u8 *uc;
    s32 i;

    p = (Cb_0012AB88 *)((u32)arg | 0x20000000);
    if (p->n1 > 0) {
        uc = (u8 *)((u32)p->dst1 | 0x20000000);
        d = p->dst1;
        for (i = 0; i < p->n1; i++) {
            d[i] = uc[i] = p->src1[i];
        }
    }
    if (p->n2 > 0) {
        uc = (u8 *)((u32)p->dst2 | 0x20000000);
        d = p->dst2;
        for (i = 0; i < p->n2; i++) {
            d[i] = uc[i] = p->src2[i];
        }
    }
    func_0012AAE0((s32 *)&D_0013F960);
}
/* localdecomp:end func_0012AB88 */
