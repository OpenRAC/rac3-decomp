#include "common.h"

typedef struct {
    f32 f0;
    s32 f4;
} S_003CD938;

INCLUDE_ASM("asm/levels", func_L07_003CC2B0);

INCLUDE_ASM("asm/levels", func_L07_003CCAF0);

/* localdecomp:start func_L07_003CCD40 */
typedef int Q_003CCD40 __attribute__((mode(TI)));
void func_L07_003CCD40(u8 *m,s32 which) {
    extern void func_L07_003BB1A8(u8 *);
    extern void func_L07_003CD2E8(void *,s32);
    u8 *d=*(u8 **)(m+0x68);
    u8 *object;
    if(*(u8 *)((s32)d+which+0x2a0)) {
        func_L07_003BB1A8(m);
        object=*(u8 **)(m+0x24);
        *(f32 *)(m+0x2c)=*(f32 *)(object+0x24);
        *(Q_003CCD40 *)(m+0x10)=*(Q_003CCD40 *)(d+0x280);
        *(Q_003CCD40 *)(m+0xf0)=*(Q_003CCD40 *)(d+0x290);
        *(u16 *)(m+0x34)&=0xfffd;
        if(*(s32 *)(d+0x428)!=-1) {
            func_L07_003CD2E8(m,3);
        } else {
            *(u16 *)(m+0x34)&=0xffbe;
            *(u16 *)(m+0x34)|=*(u16 *)(object+0x44)&0x1000;
            *(s32 *)(m+0x98)=*(s32 *)(object+0x10);
            func_L07_003CD2E8(m,5);
        }
    }
}
/* localdecomp:end func_L07_003CCD40 */

/* localdecomp:start func_L07_003CCDF8 */
void func_L07_003BB1F0();
void func_L07_003CD2E8(void *, s32);

void func_L07_003CCDF8(void *arg0) {
    void *temp_s1;

    temp_s1 = *(void **)((u8 *)arg0 + 0x68);
    func_L07_003BB1F0();
    *(s32 *)((u8 *)temp_s1 + 0x414) = 0;
    *(s8 *)((u8 *)temp_s1 + 0x406) = 0;
    *(s8 *)((u8 *)temp_s1 + 0x404) = 0;
    *(s8 *)((u8 *)temp_s1 + 0x405) = 0;
    *(s8 *)((u8 *)temp_s1 + 0x407) = 0;
    *(s32 *)((u8 *)temp_s1 + 0x410) = 0;
    *(s32 *)((u8 *)temp_s1 + 0x418) = -1;
    func_L07_003CD2E8(arg0, 0x19);
}
/* localdecomp:end func_L07_003CCDF8 */

/* localdecomp:start func_L07_003CCE58 */
s32 func_L07_003CCE58(void *arg0) {
    return (*(u8 *)((u8 *)arg0 + 0x20)) == 0x19;
}
/* localdecomp:end func_L07_003CCE58 */

INCLUDE_ASM("asm/levels", func_L07_003CCE68);
