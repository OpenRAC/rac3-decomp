#include "common.h"

/* localdecomp:start func_L39_00519A60 */
typedef struct S_00519A60 { char pad[0x14]; char f14[0x40]; s32 f54; } S_00519A60;
typedef struct T_00519A60 {
    char pad[0xC]; s32 fC; s32 f10; s32 f14; s32 f18; char f1C[0x10]; s32 f2C;
    char pad2[0x38]; s32 f68; s32 f6C;
} T_00519A60;
typedef struct A_00519A60 { u8 f0; u8 f1; u16 f2; char f4[0xC]; } A_00519A60;
extern S_00519A60 *func_L39_005190E8(s32);
extern T_00519A60 *func_L39_00519388(s32);
extern void func_L39_005193C0(void *, void *);
extern s32 func_L39_00519438(u16);
extern void func_L39_005190C8(void);
extern void func_1488A8(void *, s32, s32, s32);
extern s32 func_1487E8(void *, s32, void *);
extern s32 func_148860(void *, s32, s32, s32);
extern s32 func_L39_00519058(void);
extern s32 func_L39_005192A8(S_00519A60 *, s32);
extern s32 func_L39_00519468(s32);
s32 func_L39_00519A60(s32 fd, A_00519A60 *addr, s32 len) {
    S_00519A60 *p;
    T_00519A60 *q;
    s32 r;

    p = func_L39_005190E8(0);
    if (p == 0) return -1;
    q = func_L39_00519388(fd);
    if (q == 0) return func_L39_005192A8(p, 9);
    if (len != 0x10) return func_L39_005192A8(p, 0x16);
    if (addr->f1 != 2) return func_L39_005192A8(p, 0x6A);
    func_L39_005193C0(q->f1C, addr->f4);
    q->f2C = func_L39_00519438(addr->f2);
    if (q->f18 == 0) q->f18 = -1;
    if (q->fC != 0) {
        if (q->f14 == 1) return func_L39_005192A8(p, 0x70);
        if (q->f14 > 0) {
            if (q->f14 < 4) {
                func_L39_005190C8();
                func_1488A8(p->f14, p->f54, q->fC, q->f6C);
                q->fC = 0;
                if (func_L39_00519058() < 0) return func_L39_005192A8(p, -1);
            }
        }
    }
    func_L39_005190C8();
    r = func_1487E8(p->f14, p->f54, &q->f14);
    if (func_L39_00519058() < 0) return func_L39_005192A8(p, -1);
    if (r <= 0) return func_L39_005192A8(p, func_L39_00519468(r));
    if (q->f10 != 0) return func_L39_005192A8(p, 0x71);
    q->fC = r;
    func_L39_005190C8();
    r = func_148860(p->f14, p->f54, q->fC, q->f68);
    if (func_L39_00519058() < 0) return func_L39_005192A8(p, -1);
    if (r < 0) return func_L39_005192A8(p, func_L39_00519468(r));
    return func_L39_005192A8(p, 0);
}
/* localdecomp:end func_L39_00519A60 */
