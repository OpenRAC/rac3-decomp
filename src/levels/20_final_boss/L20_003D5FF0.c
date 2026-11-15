#include "common.h"

/* localdecomp:start func_L20_003D5FF0 */
typedef int q_003D5FF0 __attribute__((mode(TI)));
extern void func_003C2EC0(void *, s32, void *);
extern void func_003C6FE0(void *);
extern void func_003C7C38(void *);
extern void func_L01_00448E10(void *);
extern void func_003C7DD8(void *);
extern void func_0038D890(void *, void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);

void func_L20_003D5FF0(u8 *obj)
{
    u8 *v = *(u8 **)(obj + 0x68);
    q_003D5FF0 m[4];

    func_003C2EC0(obj, 0, m);
    *(q_003D5FF0 *)(*(u8 **)(v + 0x2F8) + 0x10) = m[3];
    func_003C6FE0(*(u8 **)(v + 0x2F8));
    if ((*(u16 *)(*(u8 **)(v + 0x2F8) + 0x34) & 4) == 0) {
        func_003C7C38(*(u8 **)(v + 0x2F8));
    }
    *(q_003D5FF0 *)(*(u8 **)(v + 0x2F8) + 0xC0) = m[1];
    *(q_003D5FF0 *)(*(u8 **)(v + 0x2F8) + 0xD0) = m[2];
    *(q_003D5FF0 *)(*(u8 **)(v + 0x2F8) + 0xE0) = m[0];
    func_L01_00448E10(*(u8 **)(v + 0x2F8) + 0xC0);
    func_003C7DD8(*(u8 **)(v + 0x2F8));
    *(u16 *)(*(u8 **)(v + 0x2F8) + 0x34) |= 6;

    func_003C2EC0(obj, 1, m);
    *(q_003D5FF0 *)(*(u8 **)(v + 0x2FC) + 0x10) = m[3];
    func_003C6FE0(*(u8 **)(v + 0x2FC));
    if ((*(u16 *)(*(u8 **)(v + 0x2FC) + 0x34) & 4) == 0) {
        func_003C7C38(*(u8 **)(v + 0x2F8));
    }
    *(q_003D5FF0 *)(*(u8 **)(v + 0x2FC) + 0xC0) = m[1];
    *(q_003D5FF0 *)(*(u8 **)(v + 0x2FC) + 0xD0) = m[2];
    *(q_003D5FF0 *)(*(u8 **)(v + 0x2FC) + 0xE0) = m[0];
    func_0038D890(*(u8 **)(v + 0x2FC) + 0xC0, *(u8 **)(v + 0x2FC) + 0xC0, *(u8 **)(v + 0x2FC) + 0xD0, 0.17453292f);
    func_0038D890(*(u8 **)(v + 0x2FC) + 0xE0, *(u8 **)(v + 0x2FC) + 0xE0, *(u8 **)(v + 0x2FC) + 0xD0, 0.17453292f);
    func_0038CF68(*(u8 **)(v + 0x2FC) + 0xC0, *(u8 **)(v + 0x2FC) + 0xC0, -1.0f);
    func_0038CF68(*(u8 **)(v + 0x2FC) + 0xD0, *(u8 **)(v + 0x2FC) + 0xD0, -1.0f);
    func_0038CF68(*(u8 **)(v + 0x2FC) + 0xE0, *(u8 **)(v + 0x2FC) + 0xE0, -1.0f);
    func_L01_00448E10(*(u8 **)(v + 0x2FC) + 0xC0);
    func_003C7DD8(*(u8 **)(v + 0x2FC));
    *(u16 *)(*(u8 **)(v + 0x2FC) + 0x34) |= 6;
}
/* localdecomp:end func_L20_003D5FF0 */
