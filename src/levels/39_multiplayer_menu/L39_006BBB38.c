#include "common.h"

/* declared by functions of L39_006BA5C0.c, which this file was cut from */
void func_L39_006CC158(void *, s32);

/* localdecomp:start func_L39_006BBB38 */
__asm__(".extern D_L39_0024D760, 16");
__asm__(".extern D_L39_0024D764, 16");
extern u8 D_L39_0024D764;
extern u8 *D_L39_0024D760;
void func_L39_006CC120(void *);
void func_L39_006CC930(void *);
void func_L39_0068A2D0(void *, s32, s32, s32, f32, f32);
void func_L39_0068B2F8(void *, s32, s32);
void func_L39_0067F168(void);
void func_L39_0068ADC8(void *);
void func_L39_006CC158(void *, s32);

void func_L39_006BBB38(u8 *arg0) {
    u8 buf[0x1E0];

    D_L39_0024D764 = 0;
    *(s32 *)(arg0 + 0x318) = 0;
    func_L39_006CC120(buf);
    func_L39_006CC930(buf);
    *(u8 *)(*(u8 **)(D_L39_0024D760 + 0x4C) + 0x168) = 0;
    *(u8 *)(*(u8 **)(D_L39_0024D760 + 0x70) + 0x10) = 0;
    func_L39_0068A2D0(arg0, 0, 3, 3, 0.0f, 0.0f);
    func_L39_0068B2F8(arg0, 4, 0);
    func_L39_0067F168();
    func_L39_0068ADC8(arg0);
    func_L39_006CC158(buf, 2);
}
/* localdecomp:end func_L39_006BBB38 */

/* localdecomp:start func_L39_006BBBE0 */
long func_L39_006BBBE0(void *arg0) {
    long r = 0;

    if (*(s32 *)((u8 *)arg0 + 0x2A8) != -1) {
        s32 t = *(s32 *)((u8 *)arg0 + 0x2F0) != 0;
        r = t;
    }
    return r;
}
/* localdecomp:end func_L39_006BBBE0 */
