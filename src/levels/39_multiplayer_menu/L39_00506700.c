#include "common.h"

/* localdecomp:start func_L39_00506700 */
extern u8 D_L39_0046EDD0[];
extern void *func_L39_004F7590(s32);
extern void func_L39_004F74E8(void *, s32, s32);
void func_L39_00507378(void *, s32, s32, s32);
void func_L39_00507128(void *, s32, s32, s32);
void func_L39_005076E0(void *, s32);

typedef struct S_00506700 {
    u8 pad0[0xC];
    void *fC;
    u8 f10[0x2C];
    u8 f3C[0x28];
    s32 f64;
    s32 f68;
    u8 pad6C[0xC];
} S_00506700;

S_00506700 *func_L39_00506700(S_00506700 *p, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    if (p == 0) {
        p = func_L39_004F7590(sizeof(S_00506700));
        if (p == 0) {
            return p;
        }
    }
    func_L39_004F74E8(p, 0, sizeof(S_00506700));
    func_L39_005076E0(p, arg1);
    p->fC = D_L39_0046EDD0;
    p->f64 = arg6;
    p->f68 = arg7;
    func_L39_00507378(p->f10, arg1, arg4, arg5);
    func_L39_00507128(p->f3C, arg1, arg2, arg3);
    return p;
}
/* localdecomp:end func_L39_00506700 */

/* localdecomp:start func_L39_005067F0 */
typedef struct { char _p0[0x10]; u8 f10[0x2C]; u8 f3C[0x34]; void *f70; s32 f74; } S_005067F0;
extern void func_L39_00507408(void *);
extern void func_L39_005071B0(void *);
extern void func_L39_004F74E8(void *, s32, s32);
extern void func_L39_004F7620(void *);
void func_L39_005067F0(S_005067F0 *a0) {
    func_L39_00507408(a0->f10);
    func_L39_005071B0(a0->f3C);
    if (a0->f70 != 0) {
        func_L39_004F74E8(a0->f70, 0, a0->f74 * 2);
        func_L39_004F7620(a0->f70);
    }
}
/* localdecomp:end func_L39_005067F0 */
