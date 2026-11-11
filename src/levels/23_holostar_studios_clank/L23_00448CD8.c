#include "common.h"

/* localdecomp:start func_L23_00448CD8 */
#include "vu0.h"
typedef int u128_t __attribute__((mode(TI)));
extern char *func_L01_004618E0(int);
extern int func_13D3E0(void);
extern void func_003C2F58(s32, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern unsigned char *D_L23_0021EDC0[];
extern vu0_v4 D_L23_001E19C0;

void *func_L23_00448CD8(u8 *obj, int color, int a2, int a3, float f)
{
    char *e;
    char *p;
    vu0_v4 pos;
    vu0_v4 d;

    e = func_L01_004618E0(0x1A);
    if (e != 0) {
        p = e + 0x20;
        *(u8 **)(e + 0x20) = obj;
        *(int *)(p + 0xC) = color >> 24;
        *(s16 *)(p + 6) = a3;
        *(int *)(p + 8) = a2;
        *(s16 *)(p + 4) = a2;
        if ((s16)a3 == -1) {
            *(u128_t *)(e + 0x10) = *(u128_t *)(obj + 0x10);
        } else {
            func_003C2F58(*(s32 *)(e + 0x20), (s16)a3, &pos);
            vec_sub_ba(&d, &D_L23_001E19C0, &pos);
            func_0038CF68(&d, &d, 0.4f);
            vec_add_ab(e + 0x10, &pos, &d);
        }
        *(unsigned char *)(e + 8) = func_13D3E0();
        *(int *)(e + 4) = color;
        *(unsigned char *)(e + 9) = 0x74;
        *(unsigned char *)(e + 3) = 0x48;
        *(float *)(e + 0xC) = f;
        *(unsigned char *)(e + 1) = 0;
        *(unsigned char *)(e + 2) = **D_L23_0021EDC0;
    }
    return e;
}
/* localdecomp:end func_L23_00448CD8 */
